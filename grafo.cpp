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
			dummy.nodo = j - 1;
			LSucesores[i - 1].push_back(dummy);
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

void GRAFO::actualizar(char nombrefichero[85]) {
	LPredecesores.clear();
	LSucesores.clear();
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
			dummy.nodo = j - 1;
			LSucesores[i - 1].push_back(dummy);
		}
		textfile.close();
		if (Es_dirigido() == 1) {
			ListaPredecesores();
		};
		cout << "¡Grafo actualizado correctamente!" << endl;
	} else {
		cout << "¡Error en la apertura del fichero!" << endl;
	}
}

void GRAFO::Info_Grafo() {
	cout << "Información del grafo:" << endl;
	cout << "Número de nodos: " << numero_nodos << endl;
	cout << "Númerod de arcos:" << numero_arcos << endl;
	if (Es_dirigido() == 1)
		cout << "Grafo dirigido" << endl;
	else
		cout << "Grafo no dirigido" << endl;
}

unsigned GRAFO::Es_dirigido() {
	return dirigido;
}

void GRAFO::Mostrar_Lista_Sucesores() {
	unsigned i, j;
	for (i = 0; i < LSucesores.size(); i++) {
		cout << "[" << i + 1 << "] :";
		if (LSucesores[i].empty())
			cout << " | Null" << endl;
		else {
			for (j = 0; j < LSucesores[i].size(); j++) {
				cout << " | " << LSucesores[i][j].nodo + 1;
			}
			cout << endl;
		}
	}
}

void GRAFO::Mostrar_Lista_Predecesores() {
	unsigned i, j;
	for (i = 0; i < LPredecesores.size(); i++) {
		cout << "[" << i + 1 << "] :";
		if (LPredecesores[i].empty())
			cout << " | Null" << endl;
		else {
			for (j = 0; j < LPredecesores[i].size(); j++) {
				cout << " | " << LPredecesores[i][j].nodo + 1;
			}
			cout << endl;
		}
	}
}
void GRAFO::Mostrar_Listas(int l) {
	if (l == 0) {
		Mostrar_Lista_Sucesores();
	} else {
		Mostrar_Lista_Sucesores();
		Mostrar_Lista_Predecesores();
	}
}

void GRAFO::ListaPredecesores() {
	unsigned j, k;
	ElementoLista dummy;
	LPredecesores.resize(numero_nodos);
	for (j = 0; j < LPredecesores.size(); j++) {
		for (k = 0; k < LSucesores[j].size(); k++) {
			dummy.nodo = j;
			LPredecesores[LSucesores[j][k].nodo].push_back(dummy);
		}
	}
}

