#include "Graph.h"
#include "queue"

using namespace std;

void Graph::insertVertex (int id) { // d� vrchol na konec vektoru
	vertices.push_back (new Vertex (id));
}

Graph::Vertex* Graph::findVertex (int id) { // najde vrchol podle ID
	for (auto vertex : vertices) { // for each - range based for
		if (vertex->id == id) return vertex;
	}

	return nullptr;
}

void Graph::insertVertex (int id, vector <int> neighborIds) { // vkl�d� vrchol do grafu
	Vertex* newVertex = new Vertex (id);
	vertices.push_back (newVertex); // p�id� vrchol za ostatn�

	for (auto neighborId : neighborIds) { // projde v�echny sousedy vrcholu (podle ID)
		Vertex* neighbor = findVertex (neighborId); // zkus�, jestli takov� soused existuje

		if (neighbor != nullptr) { // pokud soused existuje
			newVertex->neighbors.push_back (neighbor); // p�id� souseda za ostatn�
			if (newVertex->id != neighbor->id) neighbor->neighbors.push_back (newVertex); // pokud nesoused� s�m se sebou, p�id� se jako soused tomuto sousedovi
		}
	}
}

bool Graph::traversal (int id) { // pr�chod grafem
	Vertex* current = vertices.back (); // pointer na prvn� prvek vektoru
	queue <Vertex*> queue; // vytvo�� frontu vrchol�

	queue.push (current); // p�id� prvek na konec �ady, zv�t�� jej� velikost o 1
	current->color = 1; // �ed� - p�ijat ke zpracov�n� (discovered)

	while (!queue.empty ()) { // dokud neprojdu celou frontu
		current = queue.front (); // 1. prvek fronty (ten nejstar��)
		queue.pop (); // odstran� 1. prvek z fronty, zmen�� ji i o 1

		current->color = 2; // �ern� - zpracov�n (finished)

		//if (current->id == id) return true; // pokud byl prvek nalezen, vrac� true
		cout << current->id << endl;
		for (auto neighbor : current->neighbors) { // projde sousedy odstran�n�ho prvku
			if (neighbor->color == 0) { // b�l� - zat�m nenalezen (undiscovered)
				queue.push (neighbor); // pokud soused je�t� nebyl nalezen, d� ho na konec frotny
				neighbor->color = 1; // ozna��m ho jako nalezen�
			}
		}
	}

	return false; // prvek s dan�m ID nenalezen
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
	Vertex* neighbor = findVertex (to); // zkus�, jestli takov� soused existuje
	Vertex* newVertex= findVertex (from);

	if (neighbor != nullptr) { // pokud soused existuje
		newVertex->neighbors.push_back (neighbor); // p�id� souseda za ostatn�
		if (newVertex->id != neighbor->id) neighbor->neighbors.push_back (newVertex); // pokud nesoused� s�m se sebou, p�id� se jako soused tomuto sousedovi
	}
}