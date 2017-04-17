/*
 * Calculadora.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: Capellán
 */

#include "Calculadora.h"

namespace NotacionPI
{

	Calculadora::Calculadora() : _pl(new Pila()), _valor(new Nodo(0))
	{

	}

	int Calculadora::cast( string cadena )
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

	void Calculadora::operar(char operador)
	{
		int val1 = 0, val2 = 0;
		_valor = _pl -> pop();
		val1 = _valor -> getValor();
		delete(_valor);
		_valor = _pl -> pop();
		val2 = _valor-> getValor();
		delete(_valor);

		switch(operador)
		{
			case '+':
				_valor = new Nodo(val1 + val2 );
				break;
			case '-':
				_valor = new Nodo(val1 - val2 );
				break;
			case '*':
				_valor = new Nodo(val1 * val2 );
				break;
			case '/':
				_valor = new Nodo(val1 / val2 );
				break;
		}
		cout << val2 << " " << operador << " " << val1 <<  " = " << _valor -> getValor() << endl;
		_pl -> push(_valor);
	}

	int Calculadora::calcular(string expresion)
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
					_valor = new Nodo(cast(sub));
					_pl -> push(_valor);
				}
				operar(expresion[i]);
				sub = "";
				continue;
			}

			if(caracter == " ")
			{
				_valor = new Nodo(cast(sub));
				_pl -> push(_valor);
				sub = "";
				continue;
			}

			sub += expresion[i];

		}
		return _pl -> getTope() -> getValor();
	}

	void Calculadora::interaccion()
	{
		string expresion;
		getline(cin,expresion);
		int resulatdo = calcular(expresion);
		cout << "El resultado de esta operacion es: \n" << resulatdo << endl;
		~Calculadora();
	}

	Calculadora::~Calculadora()
	{
		delete(_valor,_pl);
	}

} /* namespace Listado */
