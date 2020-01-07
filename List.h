#pragma once
#include "pch.h"


template<typename T>
class List
{
public:
	List() : m_head(nullptr), m_size(0) {}
	List(const List<T>& list);
	List(List<T>&& list);
	~List() { Clear(); }

	List<T>& operator=(const List<T>& list);

protected:
	void PushFront(const T& data);
	void Emplace(int pos, const T& data);
	void PushBack(const T& data);

	void PopFront();
	void PopBack();

	bool Empty() const { return m_size == 0; }
	int Size() const { return m_size; };
	void Clear();

	const T& Front() const { return m_head ? m_head->m_data : T(); }
	const T& Back();

private:
	void CopyList(const List<T>& list);

private:
	std::unique_ptr<Node<T> > m_head{ nullptr };
	Node<T> *m_currentNode;
	int m_size;
};

template <typename T>
void List<T>::CopyList(const List<T>& list)
{
	Node<T> *root = list.m_head.get();
	std::unique_ptr<Node<T> > newHead{ nullptr };
	Node<T> *currentPtr{ nullptr };

	while (root)
	{
		auto temp = std::make_unique<Node<T> >(root->m_data);
		if (!newHead)
		{
			newHead = std::move(temp);
			currentPtr = newHead.get();
		}
		else
		{
			currentPtr->m_next = std::move(temp);
			currentPtr = currentPtr->m_next.get();
		}
		root = root->m_next.get();
	}
	m_head = std::move(newHead);
	m_size = list.m_size;
	m_currentNode = m_head.get();
}

template <typename T>
List<T>::List(const List<T>& list)
{
	CopyList(list);
}

template <typename T>
List<T>::List(List<T>&& list)
{
	m_head = std::move(list.m_head);
	m_size = list.m_size;
	m_currentNode = m_head.get();
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& list)
{
	if (m_head)
	{
		Clear();
	}

	CopyList(list);

	return *this;
}

template <typename T>
void List<T>::PushFront(const T& data)
{
	auto temp(std::make_unique<Node<T> >(data));
	if (m_head)
	{
		temp->m_next = std::move(m_head);
		m_head = std::move(temp);
	}
	else
	{
		m_head = std::move(temp);
	}
	++m_size;
	m_currentNode = m_head.get();
}

template <typename T>
void List<T>::Emplace(int pos, const T& data)
{
	if (!m_head || !m_head->m_next || pos == 0)
	{
		PushFront(data);
	}
	else if (pos >= m_size)
	{
		PushBack(data);
	}
	else
	{
		int curIdx = 0;
		Node<T> *ptr = m_head.get();
		while (++curIdx != pos)
		{
			ptr = ptr->m_next.get();
		}

		auto temp(std::make_unique<Node<T> >(data));
		if (curIdx == pos)
		{
			temp->m_next = std::move(ptr->m_next);	
		}

		ptr->m_next = std::move(temp);
		m_currentNode = ptr->m_next.get();
		++m_size;
	}
}

template <typename T>
void List<T>::PushBack(const T& data)
{
	if (!m_head)
	{
		PushFront(data);
	}
	else
	{
		Node<T> *ptr = m_head.get();
		while (ptr->m_next)
		{
			ptr = ptr->m_next.get();
		}

		auto temp(std::make_unique<Node<T> >(data));
		ptr->m_next = std::move(temp);
		m_currentNode = ptr->m_next.get();
		++m_size;
	}
}

template <typename T>
void List<T>::PopFront()
{
	if (m_head)
	{
		m_head = std::move(m_head->m_next);
		--m_size;
		m_currentNode = m_head != nullptr ? m_head.get() : nullptr;
	}
}

template <typename T>
void List<T>::PopBack()
{
	if (m_head)
	{
		Node<T> *ptr = m_head.get();
		while (ptr->m_next->m_next)
		{
			ptr = ptr->m_next.get();
		}
		ptr->m_next = nullptr;
		--m_size;
		m_currentNode = ptr;
	}
}

template <typename T>
void List<T>::Clear()
{
	while (m_head)
	{
		m_head = std::move(m_head->m_next);
	}
	m_size = 0;
	m_currentNode = nullptr;
}

template <typename T>
const T& List<T>::Back()
{
	if (!Empty())
	{
		Node<T> *ptr = m_head.get();
		while (ptr->m_next)
		{
			ptr = ptr->m_next.get();
		}
		m_currentNode = ptr;

		return ptr->m_data;
	}
}