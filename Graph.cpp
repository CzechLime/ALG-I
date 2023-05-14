#include "Graph.h"
#include "queue"

using namespace std;

void Graph::insertVertex (int id) { // dá vrchol na konec vektoru
	vertices.push_back (new Vertex (id));
}

Graph::Vertex* Graph::findVertex (int id) { // najde vrchol podle ID
	for (auto vertex : vertices) { // for each - range based for
		if (vertex->id == id) return vertex;
	}

	return nullptr;
}

Graph::Graph (string graphFile) {
	ifstream* file = new ifstream (graphFile);

	this->loadGraph (file);
}

void Graph::insertVertex (int id, vector <int> neighborIds) { // vkládá vrchol do grafu
	Vertex* newVertex = new Vertex (id);
	vertices.push_back (newVertex); // pøidá vrchol za ostatní

	for (auto neighborId : neighborIds) { // projde všechny sousedy vrcholu (podle ID)
		Vertex* neighbor = findVertex (neighborId); // zkusí, jestli takový soused existuje

		if (neighbor != nullptr) { // pokud soused existuje
			newVertex->neighbors.push_back (neighbor); // pøidá souseda za ostatní
			if (newVertex->id != neighbor->id) neighbor->neighbors.push_back (newVertex); // pokud nesousedí sám se sebou, pøidá se jako soused tomuto sousedovi
		}
	}
}

/**
 * This function loads a graph from a text file;
 * @param file Textfile with the graph;
 */
void Graph::loadGraph (ifstream* file) {
	int num1;
	int num2;
	string tmpNum1;
	string tmpNum2;

	while (getline (*file, tmpNum1, ' ') && getline (*file, tmpNum2)) { // ètení øádkù souboru
		num1 = stoi (tmpNum1); // string to integer
		num2 = stoi (tmpNum2);

		printf ("num1: %d, num2: %d\n", num1, num2);

		if (findVertex (num1) == nullptr) insertVertex (num1); // pokud takový vrchol v grafu ještì není, pøidá ho
		if (findVertex (num2) == nullptr) insertVertex (num2);
		this->createEdge (num1, num2); // vytvoøí hranu mezi dvìma vrcholy výše
	}
	cout << endl;

}

/**
 * This function creates an edge between two neighboring vertices;
 * @param from The vertex which will be the edge's origin;
 * @param to The vertex the edge leads to;
 */
void Graph::createEdge (int from, int to) {
	Vertex* neighbor = findVertex (to); // zkusí, jestli takový soused existuje
	Vertex* newVertex= findVertex (from);

	if (neighbor != nullptr) { // pokud soused existuje
		newVertex->neighbors.push_back (neighbor); // pøidá souseda za ostatní
		if (newVertex->id != neighbor->id) neighbor->neighbors.push_back (newVertex); // pokud nesousedí sám se sebou, pøidá se jako soused tomuto sousedovi
	}
}