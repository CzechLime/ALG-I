#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;
}

/**
 * This function resets the iterator and sets all vertices to undiscovered;
 */
void DFSIterator::Reset () { // uloí do zásobníku vrchol grafu s nejniším èíslem (iterace zaèíná tímto vrcholem)
	this->current = this->graph->vertices.front ();
	
	for (auto vertex : this->graph->vertices) {
		if (vertex->id < current->id) current = vertex;
	}

	// nastaví všechny vrcholy na undiscovered
	this->discovered.clear ();
	this->finished.clear ();

	while (!this->stack.empty ()) this->stack.pop (); // vyprázdní zásobník

	this->stack.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

/**
 * This function moves the iterator to the next vertex;
 */
void DFSIterator::Next () { // funkce posune aktuální vrchol iterátoru na následující vrchol, metoda otestuje zásobník, jestli je prázdnı
	this->isEnd = this->stack.empty ();

	if (this->isEnd) {
		for (auto vertex : this->graph->vertices) {
			if (!isDiscoverd (vertex) && !isFinished (vertex)) { // pokud je undiscovered
				stack.push (vertex);
				this->isEnd = false;
				break;
			}
		}
	}
	if (this->isEnd) return;

	this->current = stack.top (); // 1. prvek fronty (ten nejstarší)
	stack.pop (); // odstraní 1. prvek z fronty, zmenší ji i o 1

	this->finished.push_back (current); // èerná - zpracován (finished)

	for (auto neighbor : current->neighbors) { // projde sousedy odstranìného prvku
		if (!isDiscoverd (neighbor) && !isFinished (neighbor)) { // bílá - zatím nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused ještì nebyl nalezen, dá ho do zásobníku
			discovered.push_back (neighbor); // oznaèím ho jako nalezenı
		}
	}
}

/**
 * This function checks whether the stack is empty and iterating is finished;
 * @return True if iterating is finished, false if it's not;
 */
bool DFSIterator::IsEnd () { // iterace je ukonèena, pokud je zásobník prázdnı a všechny vrcholy byly oznaèeny jako zpracované
	return this->isEnd;
}

/**
 * This function returns a vertex on the top of the stack;
 * @return Vertex from top of the stack;
 */
int DFSIterator::CurrentKey () { // vrací data z vrcholu grafu, kterı je na vrcholu zásobníku
	return this->current->id;
}

/**
 * This function checks whether the vertex was discovered, e.g. is in the vector of discovered vertices;
 * @param vertex The vertex to check;
 * @return True if the vertex was discovered, otherwise false;
 */
bool DFSIterator::isDiscoverd (Graph::Vertex* vertex) {
	for (auto element : this->discovered) {
		if (element->id == vertex->id) {
			return true;
		}
	}
	return false;
}

/**
 * This function checks whether the vertex was processed, e.g. is in the vector of finished vertices;
 * @param vertex The vertex to check;
 * @return True if the vertex was processed, otherwise false;
 */
bool DFSIterator::isFinished (Graph::Vertex* vertex) {
	for (auto element : this->finished) {
		if (element->id == vertex->id) {
			return true;
		}
	}
	return false;
}

