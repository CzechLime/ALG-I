#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;
}

/**
 * This function resets the iterator and sets all vertices to undiscovered;
 */
void DFSIterator::Reset () { // ulo�� do z�sobn�ku vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	this->current = this->graph->vertices.front ();
	
	for (auto vertex : this->graph->vertices) {
		if (vertex->id < current->id) current = vertex;
	}

	// nastav� v�echny vrcholy na undiscovered
	this->discovered.clear ();
	this->finished.clear ();

	while (!this->stack.empty ()) this->stack.pop (); // vypr�zdn� z�sobn�k

	this->stack.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

/**
 * This function moves the iterator to the next vertex;
 */
void DFSIterator::Next () { // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje z�sobn�k, jestli je pr�zdn�
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

	this->current = stack.top (); // 1. prvek fronty (ten nejstar��)
	stack.pop (); // odstran� 1. prvek z fronty, zmen�� ji i o 1

	this->finished.push_back (current); // �ern� - zpracov�n (finished)

	for (auto neighbor : current->neighbors) { // projde sousedy odstran�n�ho prvku
		if (!isDiscoverd (neighbor) && !isFinished (neighbor)) { // b�l� - zat�m nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused je�t� nebyl nalezen, d� ho do z�sobn�ku
			discovered.push_back (neighbor); // ozna��m ho jako nalezen�
		}
	}
}

/**
 * This function checks whether the stack is empty and iterating is finished;
 * @return True if iterating is finished, false if it's not;
 */
bool DFSIterator::IsEnd () { // iterace je ukon�ena, pokud je z�sobn�k pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	return this->isEnd;
}

/**
 * This function returns a vertex on the top of the stack;
 * @return Vertex from top of the stack;
 */
int DFSIterator::CurrentKey () { // vrac� data z vrcholu grafu, kter� je na vrcholu z�sobn�ku
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

