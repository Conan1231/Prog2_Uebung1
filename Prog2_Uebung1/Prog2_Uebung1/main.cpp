#include <iostream>
#include <time.h>
#include "IVektor.h"


int zufallNummer() {
	return rand() % 100 + 1; // zwischen 1 und 100
}

void test1(int chunksize) {
	IVektor v(chunksize);
	cout << v.getSize() << endl;
}

void test2() {
	IVektor v1(10);
	IVektor v2(10);
	srand(time(NULL));  // randomize seed
	for (int i = 0; i < v1.getSize(); i++) {
		v1.setAt(i, zufallNummer());
	}
	for (int i = 0; i < v2.getSize(); i++) {
		v2.setAt(i, zufallNummer());
	}

	v1.print();
	v2.print();
	v2.setSubVektor(v1);
	v1.print();
	v2.print();
}

void test3() {
	IVektor v1(10);
	IVektor v2 = v1;
	srand(time(NULL));  // randomize seed
	
	for (int i = 0; i < v1.getSize(); i++) {      // Werte von v1 setzen
		v1.setAt(i, zufallNummer());
	}
	v1.print();
	v2.print();
	for (int i = 0; i < v1.getSize(); i++) {      // Werte von v2 setzen
		v2.setAt(i, zufallNummer());
	}
	v1.print();
	v2.print();
	v2.getAt(5);
	cout << endl;
}

void createSubVektorOnHeap(const IVektor& source, IVektor** pSubVec, int begin, int end) {
	*pSubVec = new IVektor{ source.getSubVektor(begin, end) };
}

int main(int argc, char* argv[])
{
	cout << "Aufgabe 1.1" << endl;
	int lenght = 10;
	IVektor myTestVektor(lenght);
	for (int i = 0; i < lenght; i++) {
		myTestVektor.setAt(i, zufallNummer());
	}
	myTestVektor.print();
	cout << "Groesse des Vektors:" << myTestVektor.getSize() << endl;
	
	cout << "Aufgabe 1.2" << endl;
	test1(10000);

	cout << "Aufgabe 1.3" << endl;
	test2();
	cout << "Aufgabe 1.4" << endl;
	test3();
	cout << "Aufgabe 1.5" << endl;
	
	IVektor vector(10);
	for (int i = 0; i <= vector.getSize(); i++) {
		vector.setAt(i, zufallNummer());
	}
	vector.print();
	IVektor* hmm{ nullptr };
	createSubVektorOnHeap(vector, &hmm, 4, 7);
	hmm->print();
	delete hmm;

	return 0;
}



