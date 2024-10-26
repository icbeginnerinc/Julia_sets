# WPI Abgabe für Bonus
Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
IAM-ZM
Hinweis zur Abgabe:
Erstellen Sie ein Dokument mit den Ergebnissen der Aufgaben. Abgabe als pdf Dokument.
1. Gruppe auf ILIAS erstellen: maximal 4 Studierende
2. Kopfzeile der Seiten des Dokuments: Ihre Gruppennummer (ILIAS)
3. Erstellen Sie auf der ersten Seite des Dokuments eine Tabelle mit den Namen,
Immatrikulationsnummern und Studiengang der Gruppenmitglieder.
Vorlage
Name
Vorname
Matrikelnummer
Studiengang
A) Abgabe: Laden Sie das pdf Dokument mit der Lösung und ein zip oder tar.gz/tgz
Archiv (keine anderen Formate!!) mit dem vollständigen Quellcode (umfasst auch
Makefile/Startdateien) und Ergebnisdateien auf ILIAS hoch. KEINE BINARIES!!!
ð 2 Dateien !
B) Spätester Zeitpunkt der Abgabe: 09. Jan 2023, 18:00 Uhr
Die beiden Aufgaben bauen aufeinander auf. Lösen Sie diese in der angegebenen
Reihenfolge. Generell gilt, dass Sie Teile aus den Übungen übernehmen können.
Aufgabe 1: Rechnen mit komplexen Zahlen
Erstellen Sie ein Klasse mit dem Namen MyComplex zum Rechnen mit komplexen Zahlen.
Implementieren Sie hierzu die notwendigen Methoden und Operatoren. Spalten Sie die
Klasse in Kopf- und Quelldatei auf. Verwenden Sie zum Übersetzen ein Makefile. Sie können
ein Makefile aus der Übung übernehmen und anpassen.
Folgende Rechenoperationen sind in Aufgabe 2 ggf. notwendig und müssen daher
implementiert sein. Aufgabe 1 ist der Testfall für Ihre Klasse für:
•
•
•
•
•
•
•
•
Addition(en), Subtraktion
Multiplikation(en): operator*
Zuweisungsoperator: operator=
operator-
Berechnung des Betrags einer komplexen Zahl: Methodenname .norm()
Rückgabe von Realteil: Methodenname .real()
Rückgabe des Imaginärteils: Methodenname .imag()
operator<< Format: Ausgabe von real und imag Teil wie folgt => (x , y )
wobei z=x+iy ist.
Beachten Sie bei der Implementierung die Konstantkorrektheit!
Fügen Sie den Quellcode in Ihre Abgabedatei (pdf-Datei) als Text ein; Sie können diesen aus
eclipse (oder Ihrem Texteditor) herauskopieren oder unter LaTeX als Quellcode einbinden.
1Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
IAM-ZM
Verwenden Sie das Testprogramm main_complex_beispiel.cpp zur Berechnung der
folgenden Zahlenbeispiele: 𝑧 ! sei eine komplexe Zahl 𝑧 = 𝑥 + 𝑖𝑦 ( 𝑥 ist der Realteil und 𝑦 ist
der Imaginärteil).
Gegeben sind 𝑧 " = 2. +7. 𝑖 und 𝑧 # = 42. − 9. 𝑖 und 𝑧 $ = −11. +19. 𝑖.
Berechnen Sie:
a) 𝑧 % = 𝑧 " ∗ 𝑧 #
b) 𝑧 & = (𝑧 " + 𝑧 # )
c) 𝑧 ' = (𝑧 " + 𝑧 # ) ∗ 2.
d) 𝑧 ( = (𝑧 # + 𝑧 $ ) ∗ 𝑧 "
e) 𝑧 ) = 𝑧 " + 5.
f) 𝑧 * = −𝑧 " + 𝑧 #
Ergebnisdarstellung:
A) Listen Sie die Ausgabe / Ergebnisse der oben genannten Beispielaufgaben a) bis f) in
der gegebenen Reihenfolge in ihrer pdf-Datei auf. (hier keine Anpassung des
Quellcodes notwendig/erlaubt !!)
B) Schreiben Sie die Fälle a)-f) in der Operatorschreibweise im C++ Quellcode und fügen
Sie diese Codezeilen in Ihre pdf-Datei ein!
2Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
IAM-ZM
Aufgabe 2: Untersuchung der Konvergenz komplexer Zahlenfolgen
(Mandelbrot und Julia Mengen)
Das Konvergenzverhalten komplexer Zahlenfolgen soll untersucht werden. Erstellen Sie
hierzu ein eigenes Programm, das die unten beschriebenen Eingabeparameter einliest, die
unten gegebenen Iterationsvorschriften berechnet und jeweils eine Ausgabedatei im
beschriebenen Format zurückgibt. Die Iterationsvorschrift ist vorgegeben (Beispiel 𝑧 +," =
(𝑧 + ) ! + 𝑐, wobei 𝑧 + und c komplexe Zahlen sind, 𝑛 ein ganzzahliger Exponent) und 𝑖 der
Iterationsindex ist. Die Folge wird als konvergiert betrachtet, wenn der Betrag der Zahlen
|𝑧 + | < 𝑅 - endlich (kleiner als ein vorgegebener Wert 𝑅 - ) bleibt, wobei eine maximale Anzahl
von Iterationsschritten 𝑖 ∈ [1, 𝑁 ./0 ] vorgeben wird.
Die Konvergenz der Folge soll im einem zweidimensionalen Wertebereich in der komplexen
Koordinatenebene untersucht werden. Der Wertebereich ist durch Angabe der linken
unteren Ecke (ll) und rechte obere Ecke (ur) festgelegt.
=𝑧 11 = 𝑧 1234561478 > , … , ( 𝑧 95 = 𝑧 9::4565+;<8 )
Unterteilen Sie hierzu die Achse für den Realanteil und Imaginäranteil regelmäßig
(Schrittweite 𝛿𝑥 und 𝛿𝑦)
Darstellung des Ergebnisses mit Gnuplot:
Plotten Sie mit Hilfe der Befehle aus Übung 3 (Game of Life) ein „Bild“ mit dem Dateiformat.
nx: x-Richtung Nummer des diskretisierten Wertebereichs
ny: y-Richtung Nummer des diskretisierten Wertebereichs
n_iter: sei die Anzahl der Iterationschritte bei Erreichen des Abbruchkriteriums.
Die Spalten der Ergebnisdatei sind
nx ny
n_iter
Erstellen Sie mit Hilfe der gnuplot Kommandos aus Übung 3 die Ergebnisbilder.
gnuplot> set pm3d map
gnuplot> spl 'ergebnis2A.dat' u 1:2:3 with image
Fügen Sie diese in Ihr Dokument ein und dokumentieren Sie die verwendeten
Anfangsbedingungen.
Programmeingaben:
1) Wertebereich festlegen: (𝑥 = , 𝑦 = ) bis (𝑥 > , 𝑦 > ): 4 Fließkommazahlen (Datentyp
double)
𝑧 11 = 𝑥 = + 𝑖𝑦 = und 𝑧 95 = 𝑥 > + 𝑖𝑦 >
2) Unterteilung festlegen: 𝑁 0./0 , 𝑁 ?./0 : Anzahl der Intervalle in real bzw. entlang imag
Achse
3) Exponent (Ganzzahl): 𝑛
4) Maximale Anzahl der Iterationen festlegen: 𝑁 ./0
5) Konvergenzradius festlegen: 𝑅 -
6) Name der Ergebnisdatei
7) Komplexe Zahl c0:
3Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
IAM-ZM
Iterationsvorschriften + Wertebereiche
Folgende drei Iterationsvorschriften sollen umgesetzt werden:
[1]
𝑧 +," = 𝑧 +# + 𝑐
a. Wert 𝑐 wird festgelegt (Eingabedatei: komplexe Konstante c0)
b. Startwert für 𝑧 = = 𝑛 0 𝛿𝑥 + 𝑖 𝑛 ? 𝛿𝑦 ist Wert aus dem oben angegebenen
Wertebereich
c. Ergebnisdatei: Format pro Zeile für Ausgabe als Bild unter gnuplot
𝑛 0 𝑛 ? 𝑛 +845
Beispiel 1A: (Datei: start1A.dat)
Nummer der Iterationsvorschrift
Wertebereich
Unterteilung (Nxmax,Nymax)
Exponent
Nmax
Rc
Dateiname
Komplexe Konstante c0
1
(-1.5 , -1.)
(1.5 , 1)
750
500
2
2000
100
ergebnis1A.dat
(-0.75,0.1)
Beispiel 1B: (Datei: start1B.dat)
Nummer der Iterationsvorschrift
Wertebereich
Unterteilung (Nxmax,Nymax)
Exponent
Nmax
Rc
Dateiname
Komplexe Konstante c0
4
1
(-1.5 , -1.)
(1.5 , 1)
750
500
2
2000
100
ergebnis1B.dat
(-0.75,0.55)Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
[2]
IAM-ZM
𝑧 +," = 𝑧 +# + 𝑐
a. Wert 𝑐 = 𝑛 0 𝛿𝑥 + 𝑖 𝑛 ? 𝛿𝑦 ist aus dem oben angegebenen Wertebereich
b. Startwert für 𝑧 = ist (0.,0.) (die können sie im Programm fest einbauen oder
über den Übergabeparameter c0 umsetzen)
c. Ergebnisdatei:
𝑛 0 𝑛 ? 𝑛 +845
Beispiel 2A: (Datei: start2A.dat)
Nummer der Iterationsvorschrift
Wertebereich
Unterteilung (Nxmax,Nymax)
Exponent
Nmax
Rc
Dateiname
Komplexe Konstante c0
2
(-2 , -1.)
(1 , 1)
750
500
2
200
2
ergebnis2A.dat
(0.,0.)
Beispiel 2B: (Datei start2B.dat)
Nummer der Iterationsvorschrift
Wertebereich
Unterteilung (Nxmax,Nymax)
Exponent
Nmax
Rc
Dateiname
Komplexe Konstante c0
5
2
(-1.5 , 1.)
(0.,0.)
750
500
2
200
2
ergebnis2B.dat
(0.,0.)Wissenschaftliches Programmieren für Ingenieure (Abgabe bis 9.1.2023)
Übungsaufgabe mit Abgabe
IAM-ZM
𝑧 +," = 𝑧 +% + 𝑐
a. Wert 𝑐 = 𝑛 0 𝛿𝑥 + 𝑖 𝑛 ? 𝛿𝑦 ist aus dem oben angegebenen Wertebereich
b. Startwert für 𝑧 = ist (0,0)
c. Ergebnisdatei:
𝑛 0 𝑛 ? 𝑛 +845
[3]
Beispiel 2B: (Datei start3A.dat)
Nummer der Iterationsvorschrift
Wertebereich
Unterteilung (Nxmax,Nymax)
Exponent
Nmax
Rc
Dateiname
Komplexe Konstante c0
3
(-1.5 , -1.)
(1.5 , 1)
750
500
4
2000
200
Ergebnis3A.dat
(0.,0.)
Tipps: nutzen Sie Funktionen und Funktionszeiger, um Codewiederholungen zu reduzieren.
Viel Erfolg!
6
