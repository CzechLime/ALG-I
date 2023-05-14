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
	Graph* graph = new Graph ("Graf3.txt");

	cout << endl;
	cout << endl;
	
	cout << "Depth First Iterator: " << endl;

	DFSIterator* depthIterator = new DFSIterator (graph);

	for (depthIterator->Reset (); !depthIterator->IsEnd (); depthIterator->Next ()) {
		cout << depthIterator->CurrentKey () << endl;
	}

	cout << endl;
	cout << "Bread First Iterator: " << endl;

	BFSIterator* breadIterator = new BFSIterator (graph);

	for (breadIterator->Reset (); !breadIterator->IsEnd (); breadIterator->Next ()) {
		cout << breadIterator->CurrentKey () << endl;
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