//============================================================================
// Name        : NPI.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Calculadora.h"
#include <string.h>

using namespace std;
using namespace NotacionPI;

int main()
{
	cout << "Ingrese la exprecion en Notacio Polaca Inversa que desea calcular: " << endl <<
						"Ejemplo: 1 2+3 4 5+** tendria como resultado 81" << endl;
	Calculadora* npi = new Calculadora();
	npi -> interaccion();
	system("pause>n");
	return 0;
}
