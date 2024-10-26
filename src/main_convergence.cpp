#include <iostream>
#include <fstream>
#include <algorithm>
#include "../include/complex.h"
#include <sstream>
#include <cmath>

using namespace std;

struct parameters_struct
{
    int iter_n = 0;
    MyComplex ll_boundary, ur_boundary;
    int Nxmax = 0, Nymax = 0;
    int pow = 0;
    int Nmax = 0;
    int Rc = 0;
    string filename;
    MyComplex c0;
    MyComplex c;
    MyComplex z;
    MyComplex z_discr;
};

void read_parameters(const string str, const int idx, parameters_struct *param_s);
void read_input_file(parameters_struct *param_s, const string filename);

int main()
{
    parameters_struct param_s;
    read_input_file(&param_s, "start1A.dat");

    /*-----------------Programmablauf------------------------------------
    |   Bestimmen der Iterationsvorschrift und Startwerte               |
    |   Iteration bis Nmax oder Konvergenzbedingung                     |
    |       //Berechnen der Iteration                                   |
    |       //(Diskretisieren der Werte)                                |
    |       //In Ergebnisdatei schreiben                                |
    -------------------------------------------------------------------*/

    // Bestimmen der Iterationsvorschrift und Startwerte

    // Ausgabedatei öffnen
    fstream file_out;
    file_out.open(param_s.filename, std::ios_base::out);
    if (!file_out.is_open())
    {
        cout << "failed to open " << param_s.filename << '\n';
        return 0;
    }

    cout << "x_max boundary::" << param_s.ur_boundary.real() << ", x_min boundary:" << param_s.ll_boundary.real() << endl;
    cout << "y_max right boundary:" << param_s.ur_boundary.imag() << ", y_min boundary:" << param_s.ll_boundary.imag() << endl;
    float x_min = 0.1; // param_s.ll_boundary.real();
    float x_max = 0.2; // param_s.ur_boundary.real();
    float y_min = 0.1; // param_s.ll_boundary.imag();
    float y_max = 0.2; // param_s.ur_boundary.imag();

    // Berechnen der Iterationschschritte
    float x = x_min;
    float y = y_min;
    float dx = (x_max - x_min) / param_s.Nxmax;
    float dy = (y_max - y_min) / param_s.Nymax;

    int iter_step = 0;
    while (x < x_max)
    {

        while (y < y_max)
        {
            switch (param_s.iter_n)
            {
            case 1:
                param_s.c = param_s.c0;
                param_s.z.set_values(x, y);
                break;
            case 2:
                param_s.c.set_values(x, y);
                param_s.z = param_s.c0;
                break;
            case 3:
                param_s.c.set_values(x, y);
                param_s.z = param_s.c0;
                break;
            default:
                cout << "unbekannte Iterationsvorschrift" << endl;
                break;
            }
            iter_step = 0;
            while (iter_step <= param_s.Nmax && param_s.z.norm() < param_s.Rc)
            {
                // cout << "norm:" << x << ", RC:" << y << endl;
                //  Berechnen der i-ten Iteration
                param_s.z = param_s.z.pow_n(param_s.pow) + param_s.c;
                // In Ergebnisdatei schreiben
                iter_step++;
            }

            file_out << x << " " << y << " " << iter_step << endl;
            y += dy;
        }
        x += dx;
        y = y_min;
    }
    // Ausgabedatei schließen
    file_out.close();
}

/*-----------------Programmablauf------------------------------------
|   read_input_file:Datei einlesen                                  |
|   read_parameters: Werte aus Datei in struct schreiben            |
-------------------------------------------------------------------*/

void read_input_file(parameters_struct *param_s, const string filename)
{
    ifstream fp(filename);
    string str;
    int idx = 0;
    string token;
    stringstream iss;

    if (fp)
    {
        while (getline(fp, str))
        {
            iss << str;
            while (getline(iss, token, ' '))
            {
                read_parameters(token, idx, param_s);
                idx++;
            }
            iss.clear();
        }
    }
}

void read_parameters(const string str, const int idx, parameters_struct *param_s)
{
    static string temp_str;
    MyComplex temp_cpx;
    switch (idx)
    {
    case 0:
        param_s->iter_n = stoi(str);
        break;
    case 1:
        temp_str = str;
        break;
    case 2:;
        temp_cpx.set_values(stof(temp_str), stof(str));
        param_s->ll_boundary = temp_cpx;
        break;
    case 3:
        temp_str = str;
        break;
    case 4:
        temp_cpx.set_values(stof(temp_str), stof(str));
        param_s->ur_boundary = temp_cpx;
        break;
    case 5:
        param_s->Nxmax = stoi(str);
        break;
    case 6:
        param_s->Nymax = stoi(str);
        break;
    case 7:
        param_s->pow = stoi(str);
        break;
    case 8:
        param_s->Nmax = stoi(str);
        break;
    case 9:
        param_s->Rc = stoi(str);
        break;
    case 10:
        param_s->filename = str;
        break;
    case 11:
        temp_str = str;
        break;
    case 12:
        temp_cpx.set_values(stof(temp_str), stof(str));
        param_s->c0 = temp_cpx;
        break;
    default:
        cout << "too many values" << endl;
        break;
    }
}