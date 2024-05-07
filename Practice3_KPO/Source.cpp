#include <iostream>
#define TASK2_Stack

#ifdef TASK1_DynArray
#include "DynArray.hpp"


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
#include "MyStack.hpp"

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

	return 0;
}
#endif // TASK2_Stack
