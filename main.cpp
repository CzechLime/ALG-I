#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Graph.h"
#include "DFSIterator.h" // iterátor prùchodem do hloubky
#include "BFSIterator.h" // iterátor prùchodem do šíøky

using namespace std;

int main () {
	ifstream* file = new ifstream ("Graf2.txt");

	Graph* graph = new Graph ();

	graph->loadGraph (file);

	cout << endl;
	cout << endl;
	
	DFSIterator* depthIterator = new DFSIterator (graph);

	for (depthIterator->Reset (); !depthIterator->IsEnd (); depthIterator->Next ()) {
		cout << depthIterator->CurrentKey () << endl;
	}

	/*GraphIterator Iter (G); // vytvoøení iterátoru pro graf G
	
	for (Iter.Reset (); !Iter.IsEnd (); Iter.Next ()) { // int i = 0; i < m; i++
		cout << Iter.CurrentKey (); // zpracování vrcholu
	}*/

	return 0;
}

/*
Graph G (”MyGraph.txt”); // vytvoøení grafu
GraphIterator Iter (G); // vytvoøení iterátoru pro graf G
for (
	Iter.Reset (); // inicializace, reset iterátoru
	!Iter.IsEnd (); // dotaz na konec prùchodu
	Iter.Next () // posun na další vrchol
	) {
		cout << Iter.CurrentKey (); // zpracování vrcholu
	}
*/