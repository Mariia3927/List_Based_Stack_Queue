#pragma once
#include "pch.h"

template <typename T>
class Stack :
	public List<T>
{
public:
	Stack() : List<T>() { }
	Stack(const Stack<T>& stack) : List<T>(stack) { }
	Stack(Stack<T>&& stack) : List<T>(stack) { }
	~Stack() { List<T>::Clear(); }

	Stack<T>& operator=(const Stack<T>& stack) { return List<T>::operator=(stack); }

	void Push(T data) { List<T>::PushFront(data); }
	void Emplace(int pos, const T& data) { List<T>::Emplace(pos, data); }
	void Pop() { List<T>::PopFront(); }

	const T& Front() const { return List<T>::Front(); }
	const T& Back() { return List<T>::Back(); }

	bool Empty() const { return List<T>::Empty(); }
	int Size() const { return List<T>::Size(); }
};
