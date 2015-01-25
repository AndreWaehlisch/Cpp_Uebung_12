#include <iostream>
#include <fstream>
#include "helfer.h"

using namespace std;

int main()
{
	const int N = 10;
	ifstream eingabe("datei.txt");
	VecDoub a(N), b(N), c(N);
	int i = 0;

	while ( eingabe.good() && !eingabe.eof() )
		eingabe >> a[i++] >> b[i] >> c[i];

	for (int k=0; k<N; k++)
		cout << a[k] << ' ' << b[k] << ' ' << c[k] << endl;

	eingabe.close();
}
