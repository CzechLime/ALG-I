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
	ifstream* file = new ifstream ("Graf1.txt");

	Graph* graph = new Graph ();

	graph->loadGraph (file);

	/*GraphIterator Iter (G); // vytvoøení iterátoru pro graf G
	
	for (Iter.Reset (); !Iter.IsEnd (); Iter.Next ()) {
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
	)
	{
	cout << Iter.CurrentKey (); // zpracování vrcholu
	}
*/