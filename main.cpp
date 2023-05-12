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
	ifstream* file = new ifstream ("Graf2.txt");

	Graph* graph = new Graph ();

	graph->loadGraph (file);

	cout << endl;
	cout << endl;
	
	DFSIterator* depthIterator = new DFSIterator (graph);

	for (depthIterator->Reset (); !depthIterator->IsEnd (); depthIterator->Next ()) {
		cout << depthIterator->CurrentKey () << endl;
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