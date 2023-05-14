#pragma once
#include <queue>
#include "Graph.h"

class BFSIterator { // iterátor prùchodem do šíøky (Bread First Search)
private:
	Graph* graph;
	queue <Graph::Vertex*> queue; // fronta
	Graph::Vertex* current;
	bool isEnd;
	vector <Graph::Vertex*> discovered; // 1
	vector <Graph::Vertex*> finished; // 2
public:
	BFSIterator (Graph* graph); // konstruktor

	void Reset (); // uloží do fronty vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	void Next (); // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje frontu, jestli je prázdná
	bool IsEnd (); // iterace je ukonèena, pokud je fronta prázdná a všechny vrcholy byly oznaèeny jako zpracované
	int CurrentKey (); // vrací hodnotu v aktuálním vrcholu, èili ve vrcholu, který je v hlavì fronty

	bool isDiscoverd (Graph::Vertex* vertex);
	bool isFinished (Graph::Vertex* vertex);
};

