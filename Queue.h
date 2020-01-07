#pragma once
#include "List.h"

template <typename T>
class Queue :
	public List<T>
{
public:
	Queue() : List<T>() { }
	Queue(const Queue<T>& queue) : List<T>(queue) { }
	~Queue() { List<T>::Clear(); }

	Queue<T>& operator=(const Queue<T>& queue) { return List<T>::operator=(queue); }

	void Push(const T& data) { List<T>::PushBack(data); }
	void Emplace(int pos, const T& data) { List<T>::Emplace(pos, data); }
	void Pop() { List<T>::PopFront(); }

	const T& Front() const { return List<T>::Front(); }
	const T& Back() { return List<T>::Back(); }

	bool Empty() const { return List<T>::Empty(); }
	int Size() const { return List<T>::Size(); }
};
