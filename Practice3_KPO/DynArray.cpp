#include <iostream>
#include "DynArray.hpp"

DynArray::DynArray(int n) {
	length = 0;
	capacity = n;
	arr = new double[capacity];
}

int DynArray::size() {
	return length;
}

void DynArray::append(double el) {
	if (size() == capacity)
	{
		capacity *= 2;
		double* newArr = new double[capacity];
		for (int i = 0; i < length; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}

	arr[length] = el;
	length++;
}

double DynArray::get(int index) {
	if (index < 0 || index >= length)
		return INFINITY;
	return arr[index];
}

DynArray::~DynArray() {
	delete[] arr;
}