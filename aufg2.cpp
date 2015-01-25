#include <iostream>
#include <fstream>
#include "helfer.h"

using namespace std;

int main()
{
	const int N = 10;
	ifstream eingabe("datei.txt", ios::in);
	VecDoub a(N), b(N), c(N);
	int i = 0;

	// eingabe.good() gibt true zurück, falls keins der "error state flags" des Streams gesetzt ist (eofbit = end of file /// failbit = die operation ist fehlgeschlagen, andere Operationen können aber noch möglich sein mit dem Stream /// badbit = der Stream ist unbrauchbar). eingabe.eof() gibt zurück, ob das ende der datei erreicht wurde (end of file).
	while ( eingabe.good() && !eingabe.eof() )
		eingabe >> a[i++] >> b[i] >> c[i];
	// Der obige Ausdruck wird vom (GNU-)Compiler von rechts nach links ausgeführt, sodass zunächst c[i] seinen Wert erhält, dann b[i] und zu letzt a[i]. Deswegen muss der Inkrement-Operator im a[i++] stehen: An den beiden anderen Stellen würde i bereits verändert werden, bevor die komplette Zeile der Datei ausgelesen ist. Damit die Erhöhung von i nach der Zuweisung von a[i] durchgeführt wird, muss das Post-Inkrement verwendet werden. Sonst bekommt a[0] garkeine Daten-Zuweisung aus datei.txt und die restlichen a[i] sind um eine Zeile verschoben. Damit ist die obige Zeile äquivalent zu folgendem etwas expandierten Code:
	// eingabe >> a[i] >> b[i] >> c[i];
	// i++;

	// Test der Werte
	for (int k=0; k<N; k++)
		cout << a[k] << ' ' << b[k] << ' ' << c[k] << endl;

	eingabe.close();
}
