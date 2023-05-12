#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class Graph {
public:
	class Vertex { // bez grafu nevytvo��m vrchol
	public:
		int id;
		int color = 0; // 0 - b�l�, 1 - �ed�, 2 - �ern�
		vector <Vertex*> neighbors; // sousedi

		Vertex (int id) { // konstruktor
			this->id = id;
		}
	};

	class Edge { // hrany

	};

	vector <Vertex*> vertices; // vrcholy, vektor - vylep�en� pole

	void insertVertex (int id); // vlo�en� nenav�zan�ho vrcholu
	void insertVertex (int id, vector <int> neighborIds); // vlo�en� nav�zan�ho vrcholu
	Vertex* findVertex (int id); // hled�n� vrcholu podle ID
	bool traversal (int id); // pr�chod grafem

	void loadGraph (ifstream* file);
	void createEdge (int from, int to);
};
