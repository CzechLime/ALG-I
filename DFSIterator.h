#pragma once
#include <stack>
#include "Graph.h"

using namespace std;

class DFSIterator { // iter�tor pr�chodem do hloubky (Depth First Search)
private:
	Graph* graph;
	stack <Graph::Vertex*> stack; // z�sobn�k
	Graph::Vertex* current;
	bool isEnd;
public:
	DFSIterator (Graph* graph); // konstruktor
	void Reset (); // ulo�� do z�sobn�ku vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	void Next (); // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje z�sobn�k, jestli je pr�zdn�
	bool IsEnd (); // iterace je ukon�ena, pokud je z�sobn�k pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	int CurrentKey (); // vrac� data z vrcholu grafu, kter� je na vrcholu z�sobn�ku
};

