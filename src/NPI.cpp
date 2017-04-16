//============================================================================
// Name        : NPI.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "Pila.h"

using namespace std;
using namespace NotacionPI;

Pila* pl = new Pila();
Nodo* valor;

int cast( string cadena )
{
	int size = cadena.size();
	int numero = 0;
	for(int i = 0; i < size; i++ )
	{
		numero = numero * 10;
		numero += (int)cadena[i] - '0';;
	};
	return numero;
};

void operar(char operador)
{
	int val1 = 0, val2 = 0;
	valor = pl -> pop();
	val1 = valor-> getValor();
	delete(valor);
	valor = pl -> pop();
	val2 = valor-> getValor();
	delete(valor);

	switch(operador)
	{
		case '+':
			valor = new Nodo(val1 + val2 );
			break;
		case '-':
			valor = new Nodo(val1 - val2 );
			break;
		case '*':
			valor = new Nodo(val1 * val2 );
			break;
		case '/':
			valor = new Nodo(val1 / val2 );
			break;
	}
	cout << val2 << " " << operador << " " << val1 <<  " = " << valor -> getValor() << endl;
	pl -> push(valor);
}

int calcular(string expresion)
{
	string caracter = "", sub= "";
	int size = expresion.size();
	for(int i = 0; i < size; i++)
	{
		caracter = expresion[i];
		if(caracter == "+" || caracter == "-" || caracter == "*" || caracter == "/")
		{
			if(sub != "")
			{
				valor = new Nodo(cast(sub));
				pl -> push(valor);
			}
			operar(expresion[i]);
			sub = "";
			continue;
		}

		if(caracter == " ")
		{
			valor = new Nodo(cast(sub));
			pl -> push(valor);
			sub = "";
			continue;
		}

		sub += expresion[i];

	}
	return pl -> getTope() -> getValor();
}

int main()
{
	cout << "Ingrese la exprecion en Notacio Polaca Inversa que desea calcular: " << endl <<
			"Ejemplo: 1 2+3 4 5+** tendria como resultado 81" << endl;
	string expresion;
	getline(cin,expresion);
	int resulatdo = calcular(expresion);
	cout << "El resultado de esta operacion es: \n" << resulatdo;
	return 0;
}
