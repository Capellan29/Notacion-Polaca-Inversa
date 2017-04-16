/*
 * Pila.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: Capellán
 */

#include "Pila.h"

namespace NotacionPI
{

	Pila::Pila() : _tope(NULL)
	{

	}

	Nodo* Pila::pop()
	{
		if(_tope == NULL)
		{
			return NULL;
		}
		else
		{
			Nodo* respuesta = _tope;
			_tope = _tope -> getSiguiente();
			return respuesta;
		}
	}

	void Pila::push(Nodo* elemento)
	{

		if(_tope == NULL)
		{
			_tope = elemento;
		}
		else
		{
			elemento -> setSiguiente(_tope);
			_tope = elemento;
		}
	}

	Pila::~Pila()
	{
		// TODO Auto-generated destructor stub
	}

} /* namespace NotacionPI */
