/*
 *  GRAFO.CPP - ImplementaciÃ³n de la clase GRAFOS
 *
 *
 *  Autor : 
 *  Fecha : 
 */

#include "grafo.h"

//CONSTRUCTOR
GRAFO::GRAFO(char nombrefichero[85]) {
	ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()) {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) numero_nodos >> (unsigned &) numero_arcos
				>> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LSucesores.resize(numero_nodos);
		// leemos los m arcos y cramos las listas de sucesores LS
		for (k = 0; k < numero_arcos; k++) {
			textfile >> i;
			textfile >> j;
			dummy.nodo = j-1;
			LSucesores[i-1].push_back(dummy);
		}
		textfile.close();
		if (Es_dirigido() == 1) {
			ListaPredecesores();
		};
		cout << "¡Fichero cargado correctamente!" << endl;
	} else {
		cout << "¡Error en la apertura del fichero!" << endl;
	}

}
//DESTRUCTOR
GRAFO::~GRAFO() {
	LPredecesores.clear();
	LSucesores.clear();
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {

}

void GRAFO::Info_Grafo() {

}

unsigned GRAFO::Es_dirigido() {
	return dirigido;
}

void Mostrar_Lista(vector<LA_nodo> L) {

}
;

void GRAFO::Mostrar_Listas(int l) {

}
;

void GRAFO::ListaPredecesores() {
	/*unsigned i, j , k;
	LPredecesores.resize(numero_nodos);
	for (int i = 0; i < numero_nodos; i++){
		for (int j = 0; i < numero_nodos; j++){
			for (int k = 0; i < numero_nodos; k++){

				}
			}
	}*/
}

