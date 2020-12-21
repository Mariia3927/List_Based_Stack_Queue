#pragma once
#include "pch.h"


template <typename T>
struct Node
{
	Node(const T& data) : m_data(data), m_next(nullptr) {}
	std::unique_ptr<Node<T> > m_next;
	T m_data;
};
