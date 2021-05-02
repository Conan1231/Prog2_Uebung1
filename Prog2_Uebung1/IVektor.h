#pragma once

using namespace std;

class IVektor {
private:
	int size = 0;
	int* daten = nullptr;

public:
	IVektor(int n);
	IVektor(const IVektor& ivv);
	~IVektor();

	int getSize();
	int getAt(int n);
	int getAt(int n)const;
	void setAt(int ind, int value)const;
	IVektor getSubVektor(int begin, int end)const;
	void setSubVektor(IVektor v);

	void print();
};