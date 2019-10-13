#pragma once
#include <cassert>
#include <iostream>
using namespace std;

const int MAX = 20;

template<typename T>
struct node
{
	T arr[MAX];
	int size;
	node* link;
	node() :arr(NULL), size(0), link(NULL)
	{};
};

template<typename T=int>
class UnrolledLinkedList
{
	public:
		UnrolledLinkedList();
		~UnrolledLinkedList();
		UnrolledLinkedList(const UnrolledLinkedList<T>& other);
		UnrolledLinkedList<T>& operator=(const UnrolledLinkedList<T>& other);

		void push(const T element);
		void add(int i, const T element);
		void add(int i, int j, const T element);
		void filter(const T element);
		void isEmpty() const;
		int numberOfElements() const;
		
		class Iterator
		{
			public:
				friend class UnrolledLinkedList;
				Iterator(node<T>* p=start, int i=0):pointer(p),index(i)
				{}
				Iterator(const Iterator& other):pointer(other.pointer),index(other.index)
				{}
				Iterator& operator++()
				{
					if (index < pointer->size - 1)
					{
						index++;
					}
					else
					{
						pointer = pointer->link;
						index = 0;
					}
					return this;
				}
				T operator*() const
				{
					return pointer->arr[index];
				}
				Iterator& operator+(int n)
				{
					int counter = 0;
					while (counter != n)
					{
						this++;
						counter++;
					}
				}
				bool operator==(const Iterator& other) const
				{
					return this == &other;
				}
				bool operator!=(const Iterator& other) const
				{
					return this != &other;
				}
				node<T>* getIterator() const
				{
					return this->pointer;
				}
				int getIndex() const
				{
					return this->index;
				}
			private:
				node<T> *pointer;
				int index;
		};
	private:
		node<T> *start,
				*end;
		void copyList(const UnrolledLinkedList<T>& other);
		void deleteList();
};


	