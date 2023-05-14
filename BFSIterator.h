#pragma once
#include <queue>
#include "Graph.h"

class BFSIterator { // iter�tor pr�chodem do ���ky (Bread First Search)
private:
	Graph* graph;
	queue <Graph::Vertex*> queue; // fronta
	Graph::Vertex* current;
	bool isEnd;
	vector <Graph::Vertex*> discovered; // 1
	vector <Graph::Vertex*> finished; // 2
public:
	BFSIterator (Graph* graph); // konstruktor

	void Reset (); // ulo�� do fronty vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	void Next (); // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje frontu, jestli je pr�zdn�
	bool IsEnd (); // iterace je ukon�ena, pokud je fronta pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	int CurrentKey (); // vrac� hodnotu v aktu�ln�m vrcholu, �ili ve vrcholu, kter� je v hlav� fronty

	bool isDiscoverd (Graph::Vertex* vertex);
	bool isFinished (Graph::Vertex* vertex);
};

