/*
 * Calculadora.h
 *
 *  Created on: Apr 16, 2017
 *      Author: Capellán
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Pila.h"

namespace NotacionPI
{

	class Calculadora
	{
		private:
			Pila* _pl;
			Nodo* _valor;
		public:
			Calculadora();
			int cast(string cadena);
			void operar(char operador);
			int calcular(string expresion);
			void interaccion();
			virtual ~Calculadora();
	};

} /* namespace Listado */

#endif /* CALCULADORA_H_ */
