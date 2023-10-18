#include <iostream>
#define TASK1_DynArray

#ifdef TASK1_DynArray
class DynArray {
private:
	int length;
	int capacity;
	double* arr;

public:
	DynArray(int n){
		length = 0;
		capacity = n;
		arr = new double[capacity];
	}

	int size() {
		return length;
	}

	void append(double el) {
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

	double get(int index) {
		if (index < 0 || index >= length)
			return INFINITY;
		return arr[index];
	}

	~DynArray(){
		delete[] arr;
	}
};

int main() {
	DynArray arr(10);
	arr.append(1.0);
	for (size_t i = 0; i < 15; i++)
		arr.append(i + 0.0);
	for (size_t j = 0; j < arr.size(); j++)
		std::cout << arr.get(j) << ' ';
	std::cout << std::endl;
	return 0;
}
#endif // TASK1_DynArray

#ifdef TASK2_Stack
class MyStack{
private:
	int* stackArr;
	int maxSize;
	int top;

	bool isFull() {
		return top == maxSize - 1;
	}

public:
	MyStack() {
		maxSize = 64;
		top = -1;
		stackArr = new int[maxSize];
	}

	MyStack(int n) {
		maxSize = n;
		top = -1;
		stackArr = new int[n];
	}

	void push(int el) {
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

	void pop() {
		if (!isEmpty())
			top--;
	}

	int size() {
		return top + 1;
	}

	int peek() {
		if (isEmpty())
			return INT_MAX;
		return stackArr[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	~MyStack() {
		delete[] stackArr;
	}
};

int main() {
	MyStack st;
	MyStack st2(2);
	for (int i = 0; i < 10; i++) {
		st2.push(i + 1);
		st.push(i - 1);
	}
	std::cout << st.peek() << std::endl;
	st2.pop();
	while (!st2.isEmpty())
	{
		std::cout << st2.peek() << ' ';
		st2.pop();
	}
	std::cout << std::endl;
	while (!st.isEmpty())
	{
		std::cout << st.peek() << ' ';
		st.pop();
	}
	return 0;
}
#endif // TASK2_Stack
