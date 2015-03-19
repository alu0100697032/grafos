/*
 * pg1.cpp
 *
 *  Created on: 19/03/2015
 *      Author: Victor
 */

#include "grafo.h"

int main() {
	//FASE DESARROLLO
	char nombrefichero[40] = "grafo1.gr";
	GRAFO grafo(nombrefichero);
	grafo.Mostrar_Lista_Sucesores();
	grafo.Mostrar_Lista_Predecesores();
	char nombrefichero2[40] = "grafo2.gr";
	grafo.actualizar(nombrefichero2);
	grafo.Mostrar_Lista_Sucesores();
	grafo.Mostrar_Lista_Predecesores();
	return 0;
}

