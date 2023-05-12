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
	ifstream* file = new ifstream ("Graf1.txt");

	Graph* graph = new Graph ();

	graph->loadGraph (file);

	/*GraphIterator Iter (G); // vytvo�en� iter�toru pro graf G
	
	for (Iter.Reset (); !Iter.IsEnd (); Iter.Next ()) {
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
	)
	{
	cout << Iter.CurrentKey (); // zpracov�n� vrcholu
	}
*/