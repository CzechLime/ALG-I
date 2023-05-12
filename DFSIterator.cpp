#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
}

void DFSIterator::Reset () { // uloží do zásobníku vrchol grafu s nejnižším èíslem (iterace zaèíná tímto vrcholem)
	while (!this->stack.empty ()) this->stack.pop (); // vyprázdní zásobník

	this->stack.push (graph->vertices.front ());
}

void DFSIterator::Next () { // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdný
	this->current = stack.top (); // 1. prvek fronty (ten nejstarší)
	stack.pop (); // odstraní 1. prvek z fronty, zmenší ji i o 1

	current->color = 2; // èerná - zpracován (finished)

	//if (current->id == id) return true; // pokud byl prvek nalezen, vrací true
	cout << current->id << endl;
	for (auto neighbor : current->neighbors) { // projde sousedy odstranìného prvku
		if (neighbor->color == 0) { // bílá - zatím nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused ještì nebyl nalezen, dá ho na konec frotny
			neighbor->color = 1; // oznaèím ho jako nalezený
		}
	}
}

bool DFSIterator::IsEnd () { // iterace je ukonèena, pokud je zásobník prázdný a všechny vrcholy byly oznaèeny jako zpracované
	return false;
}

int DFSIterator::CurrentKey () { // vrací data z vrcholu grafu, který je na vrcholu zásobníku
	return this->current->id;
}