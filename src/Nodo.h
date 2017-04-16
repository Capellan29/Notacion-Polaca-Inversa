/*
 * Nodo.h
 *
 *  Created on: Apr 15, 2017
 *      Author: Capellán
 */

#ifndef NODO_H_
#define NODO_H_

#include <stdlib.h>
using namespace std;

namespace NotacionPI
{

	class Nodo
	{
	private:
			int _valor;
			Nodo* _siguiente;

		public:
			Nodo(int valor);
			virtual ~Nodo();

			Nodo* getSiguiente()
			{
				return _siguiente;
			}

			void setSiguiente(Nodo* siguiente)
			{
				_siguiente = siguiente;
			}

			int getValor()
			{
				return _valor;
			}
	};

} /* namespace NotacionPI */

#endif /* NODO_H_ */
