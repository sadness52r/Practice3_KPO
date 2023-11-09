#pragma once
class DynArray {
private:
	int length;
	int capacity;
	double* arr;

public:
	DynArray(int n);
	int size();
	void append(double el);
	double get(int index);
	~DynArray();
};
