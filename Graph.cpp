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

bool Graph::traversal (int id) { // prùchod grafem
	Vertex* current = vertices.back (); // pointer na první prvek vektoru
	queue <Vertex*> queue; // vytvoøí frontu vrcholù

	queue.push (current); // pøidá prvek na konec øady, zvìtší její velikost o 1
	current->color = 1; // šedá - pøijat ke zpracování (discovered)

	while (!queue.empty ()) { // dokud neprojdu celou frontu
		current = queue.front (); // 1. prvek fronty (ten nejstarší)
		queue.pop (); // odstraní 1. prvek z fronty, zmenší ji i o 1

		current->color = 2; // èerná - zpracován (finished)

		//if (current->id == id) return true; // pokud byl prvek nalezen, vrací true
		cout << current->id << endl;
		for (auto neighbor : current->neighbors) { // projde sousedy odstranìného prvku
			if (neighbor->color == 0) { // bílá - zatím nenalezen (undiscovered)
				queue.push (neighbor); // pokud soused ještì nebyl nalezen, dá ho na konec frotny
				neighbor->color = 1; // oznaèím ho jako nalezený
			}
		}
	}

	return false; // prvek s daným ID nenalezen
}

void Graph::loadGraph (ifstream* file) {
	int num1;
	int num2;
	string tmpNum1;
	string tmpNum2;

	while (getline (*file, tmpNum1, ' ') && getline (*file, tmpNum2)) {
		num1 = stoi (tmpNum1); // string to integer
		num2 = stoi (tmpNum2);

		printf ("num1: %d, num2: %d\n", num1, num2);

		if (findVertex (num1) ==nullptr) insertVertex (num1);
		if (findVertex (num2)==nullptr) insertVertex (num2);
		this->createEdge (num1, num2);
	}
	cout << endl;
	this->traversal (0);
}

void Graph::createEdge (int from, int to) {
	Vertex* neighbor = findVertex (to); // zkusí, jestli takový soused existuje
	Vertex* newVertex= findVertex (from);

	if (neighbor != nullptr) { // pokud soused existuje
		newVertex->neighbors.push_back (neighbor); // pøidá souseda za ostatní
		if (newVertex->id != neighbor->id) neighbor->neighbors.push_back (newVertex); // pokud nesousedí sám se sebou, pøidá se jako soused tomuto sousedovi
	}
}