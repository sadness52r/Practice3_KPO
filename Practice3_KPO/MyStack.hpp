#pragma once
class MyStack {
private:
	int* stackArr;
	int maxSize;
	int top;

	bool isFull();

public:
	MyStack();
	MyStack(int n);
	void push(int el);
	void pop();
	int size();
	int peek();
	bool isEmpty();
	~MyStack();
};