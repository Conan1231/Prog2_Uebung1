#include "IVektor.h"
#include <iostream>
#include <time.h>

IVektor::IVektor(int n)
{
	this->daten = new int[n];             // this-> Selbstreferenzierung z.b. nutzen um Namenskonflikten zu entgehen (this->groesse = groesse)
	if (this->daten != nullptr) {
		for (int i = 0; i < n; i++) {
			this->daten[i] = 0;
		}
	}
	else {
		cout << "Keine Daten vorhanden";
	}

	this->size = n;
}

IVektor::IVektor(const IVektor& ivv) {
	this->size = ivv.size;
	this->daten = new int[this->size];
	if (this->daten != nullptr) {
		for (int i = 0; i < this->size; i++) {
			this->setAt(i, ivv.getAt(i));
		}
	}
}



IVektor::~IVektor() {
	if (this->daten != nullptr) {
		delete[]this->daten;
	}
}

int IVektor::getAt(int n)
{
	if (n < 0) {
		n = 0;
	}
	if (n >= this->size) {
		n = size - 1;
	}
	return this->daten[n];
}

int IVektor::getAt(int n)const
{
	if (n < 0) {
		n = 0;
	}
	if (n >= this->size) {
		n = size - 1;
	}
	return this->daten[n];
}

void IVektor::setAt(int n, int value) const
{
	if (n < 0) {
		n = 0;
	}
	if (n >= this->size) {
		n = size - 1;
	}
	this->daten[n]=value;
}



void IVektor::print()
{
	if (this->daten != nullptr) {
		for (int i = 0; i < this->size; i++) {
			cout << "d[" << i << "]:" << this->getAt(i) << " ";
		}
		cout << endl;
	}
	else {
		cout << "Keine Daten vorhanden";
	}
	
}

int IVektor::getSize()
{
	return this->size;
}

IVektor IVektor::getSubVektor(int begin, int end) const {
	if (begin <= 0 || begin >= this->size) {
		begin = 0;
	}
	if (end >= this->size || end < 0) {
		end = this->size - 1;
	}
	int sub_size = end - begin + 1;
	/*int neuIndex = 0;
	IVektor subVektor = IVektor(sub_size);
	for (int i = begin; i <= end; +1) {
		subVektor.setAt(neuIndex, this->getAt(i));
		neuIndex++;
	}
	*/
	IVektor const subVektor(end - begin + 1);  // Danke Alekseei !! <3
	for (int i = 0; begin <= end; begin++) {
		subVektor.daten[i] = this->daten[begin]; 
		i++;
	}
	return subVektor;

}


void IVektor::setSubVektor(IVektor v) {
	if (this->daten != nullptr && v.daten != nullptr) {
		int src_len = v.getSize();
		int destination_len = this->getSize();
		int src_ind = 0;
		int destination_index = 0;

		while ((src_ind < src_len) && (destination_index < destination_len)) {
			this->setAt(destination_index, v.getAt(src_ind));
			src_ind++;
			destination_index++;
		}
	}
}