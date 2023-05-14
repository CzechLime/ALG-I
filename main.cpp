#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Graph.h"
#include "DFSIterator.h" // iter�tor pr�chodem do hloubky
#include "BFSIterator.h" // iter�tor pr�chodem do ���ky

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

	/*GraphIterator Iter (G); // vytvo�en� iter�toru pro graf G
	
	for (Iter.Reset (); !Iter.IsEnd (); Iter.Next ()) { // int i = 0; i < m; i++
		cout << Iter.CurrentKey (); // zpracov�n� vrcholu
	}*/

	return 0;
}

/*
Graph G (�MyGraph.txt�); // vytvo�en� grafu
GraphIterator Iter (G); // vytvo�en� iter�toru pro graf G
for (
	Iter.Reset (); // inicializace, reset iter�toru
	!Iter.IsEnd (); // dotaz na konec pr�chodu
	Iter.Next () // posun na dal�� vrchol
	) {
		cout << Iter.CurrentKey (); // zpracov�n� vrcholu
	}
*/