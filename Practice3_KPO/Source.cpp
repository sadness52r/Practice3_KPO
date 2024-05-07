#include <iostream>
#include <cassert>
#define TASK2_Stack

#ifdef TASK1_DynArray
#include "DynArray.hpp"
void TestSize() {
	DynArray arr(5);
	assert(arr.size() == 0);

	arr.append(1); arr.append(2); arr.append(3);
	assert(arr.size() == 3);

	arr.append(4); arr.append(5);
	assert(arr.size() == 5);

	arr.append(6);
	assert(arr.size() == 6);

	std::cout << "Test Size OK" << "\n";
}

void TestGet() {
	DynArray arr(5);
	assert(arr.get(-5) == INFINITY);
	assert(arr.get(0) == INFINITY);
	assert(arr.get(1) == INFINITY);

	arr.append(1); arr.append(2); arr.append(3);
	assert(arr.get(0) == 1);
	assert(arr.get(1) == 2);
	assert(arr.get(4) == INFINITY);
	assert(arr.get(100) == INFINITY);

	std::cout << "Test Get OK" << "\n";
}

int main() {
	DynArray arr(10);
	arr.append(1.0);
	for (size_t i = 0; i < 15; i++)
		arr.append(i + 0.0);
	for (size_t j = 0; j < arr.size(); j++)
		std::cout << arr.get(j) << ' ';
	std::cout << std::endl;

	TestSize();
	TestGet();
	return 0;
}
#endif // TASK1_DynArray

#ifdef TASK2_Stack
#include "MyStack.hpp"

void TestSize() {
	MyStack st1;
	MyStack st2(5);
	assert(st1.size() == 0);
	assert(st2.size() == 0);

	st1.push(1); st1.push(2); st1.push(3);
	st2.push(4); st2.push(5); st2.push(6);
	assert(st1.size() == 3);
	assert(st2.size() == 3);

	st1.pop(); st2.pop();
	assert(st1.size() == 2);
	assert(st2.size() == 2);

	st1.pop(); st1.pop();
	st2.pop(); st2.pop();
	assert(st1.size() == 0);
	assert(st2.size() == 0);

	st1.pop(); st2.pop();
	assert(st1.size() == 0);
	assert(st2.size() == 0);

	std::cout << "Test Size OK" << "\n";
}
void TestPeek() {
	MyStack st1;
	MyStack st2(5);
	assert(st1.peek() == INT_MAX);
	assert(st2.peek() == INT_MAX);

	st1.push(1); st1.push(2); st1.push(3);
	st2.push(4); st2.push(5); st2.push(6);
	assert(st1.peek() == 3);
	assert(st2.peek() == 6);

	st1.pop(); st2.pop();
	assert(st1.peek() == 2);
	assert(st2.peek() == 5);

	st1.pop(); st1.pop();
	st2.pop(); st2.pop();
	assert(st1.peek() == INT_MAX);
	assert(st2.peek() == INT_MAX);

	st1.pop(); st2.pop();
	assert(st1.peek() == INT_MAX);
	assert(st2.peek() == INT_MAX);

	std::cout << "Test Peek OK" << "\n";
}
void TestIsEmpty() {
	MyStack st1;
	MyStack st2(5);
	assert(st1.isEmpty() == true);
	assert(st2.isEmpty() == true);

	st1.push(1); st1.push(2); st1.push(3);
	st2.push(4); st2.push(5); st2.push(6);
	assert(st1.isEmpty() == false);
	assert(st2.isEmpty() == false);

	st1.pop(); st2.pop();
	assert(st1.isEmpty() == false);
	assert(st2.isEmpty() == false);

	st1.pop(); st1.pop();
	st2.pop(); st2.pop();
	assert(st1.isEmpty() == true);
	assert(st2.isEmpty() == true);

	st1.pop(); st2.pop();
	assert(st1.isEmpty() == true);
	assert(st2.isEmpty() == true);

	std::cout << "Test isEmpty OK" << "\n";
}

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
	std::cout << std::endl;

	TestSize();
	TestPeek();
	TestIsEmpty();
	return 0;
}
#endif // TASK2_Stack
