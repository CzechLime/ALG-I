#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;
}

void DFSIterator::Reset () { // uloí do zásobníku vrchol grafu s nejniším èíslem (iterace zaèíná tímto vrcholem)
	this->current = graph->vertices.front ();

	for (auto vertex : this->graph->vertices) {
		if (vertex->id < current->id) current = vertex;
		vertex->color = 0; // odbarví vrcholy
	}

	while (!this->stack.empty ()) this->stack.pop (); // vyprázdní zásobník

	this->stack.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

void DFSIterator::Next () { // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdnı
	this->isEnd = this->stack.empty ();
	if (this->isEnd) return;
	this->current = stack.top (); // 1. prvek fronty (ten nejstarší)
	stack.pop (); // odstraní 1. prvek z fronty, zmenší ji i o 1

	current->color = 2; // èerná - zpracován (finished)

	for (auto neighbor : current->neighbors) { // projde sousedy odstranìného prvku
		if (neighbor->color == 0) { // bílá - zatím nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused ještì nebyl nalezen, dá ho do zásobníku
			neighbor->color = 1; // oznaèím ho jako nalezenı
		}
	}
}

bool DFSIterator::IsEnd () { // iterace je ukonèena, pokud je zásobník prázdnı a všechny vrcholy byly oznaèeny jako zpracované
	return this->isEnd;
}

int DFSIterator::CurrentKey () { // vrací data z vrcholu grafu, kterı je na vrcholu zásobníku
	return this->current->id;
}