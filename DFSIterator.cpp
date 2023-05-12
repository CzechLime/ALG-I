#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;

	for (auto vertex : this->graph->vertices) {
		DyedVertex* dyedVertex = new DyedVertex (vertex);
	}
}

void DFSIterator::Reset () { // uloží do zásobníku vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	this->current = this->dyedVerticies.front();

	for (auto dyedVertex : this->dyedVerticies) {
		if (dyedVertex->vertex->id < current->vertex->id) current = dyedVertex;
		dyedVertex->color = 0; // odbarví vrcholy
	}

	while (!this->stack.empty ()) this->stack.pop (); // vyprázdní zásobník

	this->stack.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

void DFSIterator::Next () { // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdný
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

	this->current = stack.top (); // 1. prvek fronty (ten nejstarší)
	stack.pop (); // odstraní 1. prvek z fronty, zmenší ji i o 1

	current->color = 2; // èerná - zpracován (finished)

	for (auto neighbor : current->vertex->neighbors) { // projde sousedy odstranìného prvku
		if (neighbor->color == 0) { // bílá - zatím nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused ještì nebyl nalezen, dá ho do zásobníku
			neighbor->color = 1; // oznaèím ho jako nalezený
		}
	}
}

bool DFSIterator::IsEnd () { // iterace je ukonèena, pokud je zásobník prázdný a všechny vrcholy byly oznaèeny jako zpracované
	return this->isEnd;
}

int DFSIterator::CurrentKey () { // vrací data z vrcholu grafu, který je na vrcholu zásobníku
	return this->current->id;
}

DFSIterator::DyedVertex::DyedVertex (Graph::Vertex* vertex) {
	this->vertex = vertex;
	this->color = 0; // bílá
}
