/*
	C++ Implementation for Min Heap 
	version 1.0.0
	
*/

#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <iostream>
#include <vector>
#include <functional> // greater
#include <assert.h>     // assert 
#include <stdexcept> // underflow overflow

//! The minHeap class
/*!
 	Generic min binary heap using an array.
	Can be used with an customized comparator instead of the natural order,
	but the generic Value type must still be comparable.
*/
template <class TYPE,class Compare=std::greater<TYPE> >
class MinHeap{
	//! capacity of the heap
	int mCapacity;
	//! # of elements
	int mSize;
	//! elements
	TYPE *mpElements;
	//! comparison function
	/*! The comparison function can be user-defined, if unspecified, std::greater<TYPE> would be used. 
	*/
	Compare mGreater; 
	//! A function to build a MinHeap from an unordered array
	void BuildMinHeap()
	{
		for (int i = (mSize - 1) / 2 + 1;i >= 1;-- i)
			MinHeapify(i);
	}
	//! A function to make the sub-tree rooted at node i a minHeap, if the sub-trees rooted at all its descendants are already minHeap 
	void MinHeapify(int i)
	{
		int j;
		while (2 * i <= mSize)
		{
			j = i;
			if (mGreater(mpElements[j],mpElements[2 * i])) j = 2 * i;
			if (2 * i + 1 <= mSize && mGreater(mpElements[j],mpElements[2 * i + 1])) j = 2 * i + 1;
			if (j == i) break;
			Swap(i,j);
			i = j;
		}
	}
	//! A function to exchange mpElements[i] and mpElements[j]
	inline void Swap(int i,int j)
	{
		TYPE tmp = mpElements[i];
		mpElements[i] = mpElements[j];
		mpElements[j] = tmp;
	}
	//! A function to check whether the array satisfies the minHeap property or not
	bool IsMinHeap()
	{
		if (Empty()) return true;
		for (int i = 1;2 * i <= mSize;++ i)
			{
				if (mGreater(mpElements[i],mpElements[2 * i])) return false;
				if (2 * i + 1 <= mSize && mGreater(mpElements[i],mpElements[2 * i + 1])) return false;
			}
		return true;
	}
	//! A function to make the minHeap still satisfy the minHeap property when inserting a node at i.
	void Swim(int i)
	{
		int parent;
		while (i > 1)
		{
			parent = i / 2;
			if (mGreater(mpElements[parent],mpElements[i]))
				Swap(parent,i);
			else
				break;
			i = parent;
		}

	}
	//! The same as MinHeapify()
	void Sink(int i)
	{
       MinHeapify(i);
	}

public:
	//! A constructor
	explicit MinHeap(Compare uGreater = Compare())// constructor
	{
		mCapacity = 100;
		mSize = 0;
		mpElements = new TYPE[mCapacity];
		mGreater = uGreater;
	}
	//! A constructor with mCapacity specified
	explicit MinHeap(int capacity,Compare uGreater = Compare())// constructor
	{
		mCapacity = capacity + 1;
		mSize = 0;
		mpElements = new TYPE[mCapacity];
		mGreater = uGreater;
	}
	//! A constructor
	explicit MinHeap(TYPE *data,int len,Compare uGreater = Compare())// constructor
	{
		std::vector<TYPE> vecData(data,data + len);
		MinHeap(vecData,uGreater);
	}
	//! A constructor
	explicit MinHeap(std::vector<TYPE>& data, Compare uGreater = Compare())// constructor
	{
		mSize = data.size();
		mCapacity = mSize + 1;
		mpElements = new TYPE[mCapacity];
		for (int i = 1;i <= mSize;++ i)
			mpElements[i] = data[i - 1];

		mGreater = uGreater;
		BuildMinHeap();
		assert(IsMinHeap()); // please comment this line when using
	}
	//! A function to print out the elements in the heap
	void Print()
	{
		for (int i = 1;i <= mSize;++ i)
		{
	        std::cout << mpElements[i] << " ";
		}
		std::cout << std::endl;
	}
	//! A function to insert a value in the heap
	void Insert(TYPE x)
	{
		if (mSize >= mCapacity - 1) Resize(2 * mCapacity);
		++ mSize;
		mpElements[mSize] = x;
        Swim(mSize);
        assert(IsMinHeap());// please comment this line when using
	}
	//! A function to answer the query of the minimum element in the heap
	TYPE Min()
	{
        if (Empty())
        {
        	throw new std::underflow_error("MaxHeap underflow.");
        }
        return mpElements[1];
	}
    //! A function to answer the query of the minimum element in the heap amd then remove the minimum element 
	TYPE ExtractMin()
	{
		TYPE minElem = Min();
        
		if (mSize > 1)
		{
			Swap(1,mSize);
			-- mSize;
			Sink(1);
		}
		else
		{
		    -- mSize;
		}

		assert(IsMinHeap()); // please comment this line when using
		if (mSize > 0 && mSize == (mCapacity - 1) / 4) Resize(mCapacity / 2);

		return minElem;
	}
    //! A function to track whether the heap is empty
	bool Empty()
	{
		return (mSize == 0);
	}
    //! A function to change the mCapacity of the heap
	void Resize(int capacity)
	{
		assert(capacity >= mSize + 1);
        mCapacity = capacity;
        TYPE *tmp = new TYPE[mCapacity];
        for (int i = 1;i <= mSize;++ i)
        	tmp[i] = mpElements[i];
        mpElements = tmp;
	}
	//! A function to get the current size of the minHeap
	int Size()
	{
		return mSize;
	}
};



#endif



