/*
 * Pila.h
 *
 *  Created on: Apr 15, 2017
 *      Author: Capellán
 */

#ifndef PILA_H_
#define PILA_H_

#include "Nodo.h"

namespace NotacionPI
{
	class Pila
	{
		private:
			Nodo* _tope;

		public:
			Pila();
			Nodo* pop();
			void push(Nodo* elemento);
			virtual ~Pila();
			Nodo* getTope()
			{
				return _tope;
			}
	};

} /* namespace NotacionPI */

#endif /* PILA_H_ */
