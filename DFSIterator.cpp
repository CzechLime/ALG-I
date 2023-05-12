#include "DFSIterator.h"

DFSIterator::DFSIterator (Graph* graph) { // konstruktor
	this->graph = graph;
	this->current = nullptr;
}

void DFSIterator::Reset () { // ulo�� do z�sobn�ku vrchol grafu s nejni���m ��slem (iterace za��n� t�mto vrcholem)
	while (!this->stack.empty ()) this->stack.pop (); // vypr�zdn� z�sobn�k

	this->stack.push (graph->vertices.front ());
}

void DFSIterator::Next () { // funkce posune aktu�ln� vrchol iter�toru na n�sleduj�c� vrchol, metoda otestuje z�sobn�k, jestli je pr�zdn�
	this->current = stack.top (); // 1. prvek fronty (ten nejstar��)
	stack.pop (); // odstran� 1. prvek z fronty, zmen�� ji i o 1

	current->color = 2; // �ern� - zpracov�n (finished)

	//if (current->id == id) return true; // pokud byl prvek nalezen, vrac� true
	cout << current->id << endl;
	for (auto neighbor : current->neighbors) { // projde sousedy odstran�n�ho prvku
		if (neighbor->color == 0) { // b�l� - zat�m nenalezen (undiscovered)
			stack.push (neighbor); // pokud soused je�t� nebyl nalezen, d� ho na konec frotny
			neighbor->color = 1; // ozna��m ho jako nalezen�
		}
	}
}

bool DFSIterator::IsEnd () { // iterace je ukon�ena, pokud je z�sobn�k pr�zdn� a v�echny vrcholy byly ozna�eny jako zpracovan�
	return false;
}

int DFSIterator::CurrentKey () { // vrac� data z vrcholu grafu, kter� je na vrcholu z�sobn�ku
	return this->current->id;
}