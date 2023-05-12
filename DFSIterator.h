#pragma once
#include <stack>
#include "Graph.h"

using namespace std;

class DFSIterator { // iterátor prùchodem do hloubky (Depth First Search)
public:	class DyedVertex;

private:
	Graph* graph;
	stack <DyedVertex*> stack; // zásobník
	DyedVertex* current;
	vector <DFSIterator::DyedVertex*> dyedVerticies;
	bool isEnd;

public:
	class DyedVertex { // pro uchovávání barvy vrcholu iterátorem
	public:
		Graph::Vertex* vertex;
		int color;

		DyedVertex (Graph::Vertex* vertex);
	};

	DFSIterator (Graph* graph); // konstruktor
	void Reset (); // uloží do zásobníku vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	void Next (); // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdný
	bool IsEnd (); // iterace je ukonèena, pokud je zásobník prázdný a všechny vrcholy byly oznaèeny jako zpracované
	int CurrentKey (); // vrací data z vrcholu grafu, který je na vrcholu zásobníku
};

