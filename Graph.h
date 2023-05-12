#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class Graph {
public:
	class Vertex { // bez grafu nevytvoøím vrchol
	public:
		int id;
		int color = 0; // 0 - bílá, 1 - šedá, 2 - èerná
		vector <Vertex*> neighbors; // sousedi

		Vertex (int id) { // konstruktor
			this->id = id;
		}
	};

	class Edge { // hrany

	};

	vector <Vertex*> vertices; // vrcholy, vektor - vylepšené pole

	void insertVertex (int id); // vložení nenavázaného vrcholu
	void insertVertex (int id, vector <int> neighborIds); // vložení navázaného vrcholu
	Vertex* findVertex (int id); // hledání vrcholu podle ID
	bool traversal (int id); // prùchod grafem

	void loadGraph (ifstream* file);
	void createEdge (int from, int to);
};
