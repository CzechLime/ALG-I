#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;

	for (auto vertex : this->graph->vertices) {
		DyedVertex* dyedVertex = new DyedVertex (vertex);
	}
}

void DFSIterator::Reset () { // ulo�� do z�sobn�ku vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	this->current = this->dyedVerticies.front();

	for (auto dyedVertex : this->dyedVerticies) {
		if (dyedVertex->vertex->id < current->vertex->id) current = dyedVertex;
		dyedVertex->color = 0; // odbarv� vrcholy
	}

	while (!this->stack.empty ()) this->stack.pop (); // vypr�zdn� z�sobn�k

	this->stack.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

void DFSIterator::Next () { // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje z�sobn�k, jestli je pr�zdn�
	this->isEnd = this->stack.empty ();

	if (this->isEnd) {
		for (auto dyedVertex : this->dyedVerticies) {
			if (dyedVertex->color == 0) {
			stack.push (dyedVertex);
			this->isEnd = false;
			break;
			}
		}
	}
	if (this->isEnd) return;

	this->current = stack.top (); // 1. prvek fronty (ten nejstar��)
	stack.pop (); // odstran� 1. prvek z fronty, zmen�� ji i o 1

	current->color = 2; // �ern� - zpracov�n (finished)

	for (auto neighbor : current->vertex->neighbors) { // projde sousedy odstran�n�ho prvku
		if (neighbor->color == 0) { // b�l� - zat�m nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused je�t� nebyl nalezen, d� ho do z�sobn�ku
			neighbor->color = 1; // ozna��m ho jako nalezen�
		}
	}
}

bool DFSIterator::IsEnd () { // iterace je ukon�ena, pokud je z�sobn�k pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	return this->isEnd;
}

int DFSIterator::CurrentKey () { // vrac� data z vrcholu grafu, kter� je na vrcholu z�sobn�ku
	return this->current->id;
}

DFSIterator::DyedVertex::DyedVertex (Graph::Vertex* vertex) {
	this->vertex = vertex;
	this->color = 0; // b�l�
}
