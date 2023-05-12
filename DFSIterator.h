#pragma once
#include <stack>
#include "Graph.h"

using namespace std;

class DFSIterator { // iterátor prùchodem do hloubky (Depth First Search)
private:
	Graph* graph;
	stack <Graph::Vertex*> stack; // zásobník
	Graph::Vertex* current;
	bool isEnd;
public:
	DFSIterator (Graph* graph); // konstruktor
	void Reset (); // uloží do zásobníku vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	void Next (); // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdný
	bool IsEnd (); // iterace je ukonèena, pokud je zásobník prázdný a všechny vrcholy byly oznaèeny jako zpracované
	int CurrentKey (); // vrací data z vrcholu grafu, který je na vrcholu zásobníku
};

