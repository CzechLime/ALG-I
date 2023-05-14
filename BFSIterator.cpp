#include "BFSIterator.h"

BFSIterator::BFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
	this->isEnd = true;
}

/**
 * This function resets the iterator and sets all vertices to undiscovered;
 */
void BFSIterator::Reset () { // ulo�� do z�sobn�ku vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	this->current = this->graph->vertices.front ();

	for (auto vertex : this->graph->vertices) {
		if (vertex->id < current->id) current = vertex;
	}

	// nastav� v�echny vrcholy na undiscovered
	this->discovered.clear ();
	this->finished.clear ();

	while (!this->queue.empty ()) this->queue.pop (); // vypr�zdn� z�sobn�k

	this->queue.push (current); // front () - 1. prvek vektoru
	this->isEnd = false;
	Next ();
}

/**
 * This function moves the iterator to the next vertex;
 */
void BFSIterator::Next () { // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje z�sobn�k, jestli je pr�zdn�
	this->isEnd = this->queue.empty ();

	if (this->isEnd) {
		for (auto vertex : this->graph->vertices) {
			if (!isDiscoverd (vertex) && !isFinished (vertex)) { // pokud je undiscovered
				queue.push (vertex);
				this->isEnd = false;
				break;
			}
		}
	}
	if (this->isEnd) return;

	this->current = queue.front (); // 1. prvek fronty (ten nejstar��)
	queue.pop (); // odstran� 1. prvek z fronty, zmen�� ji i o 1

	this->finished.push_back (current); // �ern� - zpracov�n (finished)

	for (auto neighbor : current->neighbors) { // projde sousedy odstran�n�ho prvku
		if (!isDiscoverd (neighbor) && !isFinished (neighbor)) { // b�l� - zat�m nenalezen (undiscovered)
			queue.push (neighbor); // pokud soused je�t� nebyl nalezen, d� ho do z�sobn�ku
			discovered.push_back (neighbor); // ozna��m ho jako nalezen�
		}
	}
}

/**
 * This function checks whether the queue is empty and iterating is finished;
 * @return True if iterating is finished, false if it's not;
 */
bool BFSIterator::IsEnd () { // iterace je ukon�ena, pokud je fronta pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	return this->isEnd;
}

/**
 * This function returns a vertex in the front of the queue;
 * @return Vertex from the front of the queue;
 */
int BFSIterator::CurrentKey () { // vrac� data z vrcholu grafu, kter� je na vrcholu fronty
	return this->current->id;
}

/**
 * This function checks whether the vertex was discovered, e.g. is in the vector of discovered vertices;
 * @param vertex The vertex to check;
 * @return True if the vertex was discovered, otherwise false;
 */
bool BFSIterator::isDiscoverd (Graph::Vertex* vertex) {
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
bool BFSIterator::isFinished (Graph::Vertex* vertex) {
	for (auto element : this->finished) {
		if (element->id == vertex->id) {
			return true;
		}
	}
	return false;
}