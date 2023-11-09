#include <iostream>
#include "MyStack.hpp"

bool MyStack::isFull() {
	return top == maxSize - 1;
}

MyStack::MyStack() {
	maxSize = 64;
	top = -1;
	stackArr = new int[maxSize];
}

MyStack::MyStack(int n) {
	maxSize = n;
	top = -1;
	stackArr = new int[n];
}

void MyStack::push(int el) {
	if (isFull())
	{
		maxSize *= 2;
		int* newArr = new int[maxSize];
		for (int i = 0; i < top + 1; i++)
			newArr[i] = stackArr[i];
		delete[] stackArr;
		stackArr = newArr;
	}
	stackArr[++top] = el;
}

void MyStack::pop() {
	if (!isEmpty())
		top--;
}

int MyStack::size() {
	return top + 1;
}

int MyStack::peek() {
	if (isEmpty())
		return INT_MAX;
	return stackArr[top];
}

bool MyStack::isEmpty() {
	return top == -1;
}

MyStack::~MyStack() {
	delete[] stackArr;
}