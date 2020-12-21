// ListBasedStackAndQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	Queue<int> q;
	q.Empty() ? std::cout << "Queue is empty\n" : std::cout << "Queue is not empty\n";

	q.Push(1);
	std::cout << q.Front() << '\n';
	std::cout << q.Back() << '\n';

	q.Push(2);
	std::cout << q.Front() << '\n';
	std::cout << q.Back() << '\n';
	
	q.Emplace(2, 3);

	std::cout << "q.Front - " << q.Front() << '\n';
	q.Pop();
	std::cout << "q.Front - " << q.Front() << '\n';
	q.Pop();
	std::cout << "q.Front - " << q.Front() << '\n';
	q.Pop();

	Stack<int> stack;
	stack.Push(10);
	std::cout << "stack.Front - " << stack.Front() << '\n';
	std::cout << "stack.Back - " << stack.Back() << '\n';

	stack.Push(20);
	std::cout << "stack.Front - " << stack.Front() << '\n';
	std::cout << "stack.Back - " << stack.Back() << '\n';

	stack.Emplace(2, 30);
	std::cout << "stack.Front - " << stack.Front() << '\n';
	std::cout << "stack.Back - " << stack.Back() << '\n';

	Stack<int> second = stack;

	std::cout << "second.Front - " << second.Front() << '\n';
	std::cout << "second.Back - " << second.Back() << '\n';
}


