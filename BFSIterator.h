#pragma once
#include <queue>
#include "Graph.h"

class BFSIterator { // iterátor prùchodem do šíøky (Breadth First Search)
private:
	Graph* graph;
	queue <Graph::Vertex> queue; // fronta
	Graph::Vertex* current;
public:
	BFSIterator (); // konstruktor
	void Reset (); // uloží do fronty vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	void Next (); // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje frontu, jestli je prázdná
	bool IsEnd (); // iterace je ukonèena, pokud je fronta prázdná a všechny vrcholy byly oznaèeny jako zpracované
	void CurrentKey (); // vrací hodnotu v aktuálním vrcholu, èili ve vrcholu, který je v hlavì fronty
};

