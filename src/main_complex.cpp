#include <iostream>
#include <string>
// header file for own complex number class
#include "../include/complex.h"

using namespace std;

void output_my_cplx(const MyComplex &c, const std::string txt)
{
    cout << txt << ":(" << c.real() << "," << c.imag() << ")" << endl;
}

int main()
{
    MyComplex z1{2., 7.};
    MyComplex z2{42., -9};
    MyComplex z3{-11., 19.};
    MyComplex z4, z5, z6, z7, z8, z9, z10, z11;

    output_my_cplx(z1, "z1 ");
    output_my_cplx(z2, "z2 ");
    output_my_cplx(z3, "z3 ");

    // Eigener Ausgabeoperator
    cout << "z1:" << z1 << endl;
    cout << "z2:" << z2 << endl;
    cout << "z3:" << z3 << endl;

    z4 = z1 * z2;
    output_my_cplx(z4, "z4=z1*z2 =");
    z5 = (z1 + z2);
    output_my_cplx(z5, "z5=(z1+z2) =");
    z6 = (z1 + z2) * 2.;
    output_my_cplx(z6, "z6=(z1+z2)*2. = ");
    z7 = (z2 + z3) * z1;
    output_my_cplx(z7, "z7=(z2+z3)*z1 = ");
    z8 = z1 + 5.;
    output_my_cplx(z8, "z8=z1+5. = ");
    z9 = -z1 + z2;
    output_my_cplx(z9, "z9=-z1+z2 = ");

    cout << "Operator-Schreibweise:" << endl;
    operator<<(operator<<(cout, "z4=z1*z2="), z1.operator*(z2)) << endl;
    operator<<(operator<<(cout, "z5=z1+z2="), z1.operator+(z2)) << endl;
    operator<<(operator<<(cout, "z6=(z1+z2)*2="), z1.operator+(z2).operator*(2.0)) << endl;
    operator<<(operator<<(cout, "z7=(z2+z3)*z1="), z2.operator+(z3).operator*(z1)) << endl;
    operator<<(operator<<(cout, "z8=z1+5="), z1.operator+(5)) << endl;
    operator<<(operator<<(cout, "z9=-z1+z2="), z1.operator-().operator+(z2)) << endl;
    return 0;
}
