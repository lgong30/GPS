#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "minHeap.hpp"

template <class TYPE,class Compare = std::greater<TYPE> >
class PriorityQueue: public MinHeap<TYPE,Compare> {
public:
	using MinHeap<TYPE,Compare>::MinHeap;
	void Enqueue(TYPE t)
	{
		MinHeap<TYPE,Compare>::Insert(t);
	}
	TYPE PeekMin()
	{
		return MinHeap<TYPE,Compare>::Min();
	}
	void PopMin()
	{
		MinHeap<TYPE,Compare>::ExtractMin();
	}
};


#endif