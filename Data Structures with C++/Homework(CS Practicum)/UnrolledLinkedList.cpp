#include "UnrolledLinkedList.h"

template<typename T>
UnrolledLinkedList<T>::UnrolledLinkedList()
{
	start = end = NULL;
}
template<typename T>
UnrolledLinkedList<T>::~UnrolledLinkedList()
{
	deleteList();
}
template<typename T>
UnrolledLinkedList<T>::UnrolledLinkedList(const UnrolledLinkedList<T>& other)
{
	copyList(other);
}
template<typename T>
UnrolledLinkedList<T>& UnrolledLinkedList<T>::operator=(const UnrolledLinkedList<T>& other)
{
	if (this != &other)
	{
		deleteList();
		copyList(other);
	}
	return *this;
}
template<typename T>
void UnrolledLinkedList<T>::copyList(const UnrolledLinkedList<T>& other)
{
	start = end = NULL;
	node<T>* p = other.start;
	while (p)
	{
		node<T>* q = end;
		end = new node<T>;
		assert(end != NULL);
		for (int i = 0; i < p->size; i++)
		{
			end->arr[i] = p->arr[i];
		}
		end->size = p->size;
		end->link = NULL;
		if (q) q->link = end;
		else start = end;
		p = p->link;
	}
}
template<typename T>
void UnrolledLinkedList<T>::deleteList()
{
	node<T>* q;
	while (start)
	{
		q = start;
		start = start->link;
		delete q;
	}
	end = NULL;
}
template<typename T>
void UnrolledLinkedList<T>::push(const T element)
{
	node<T>* p = end;
	if (p->size < MAX)
	{
		p->arr[p->size] = element;
		p->size++;
	}
	else
	{
		end = new node<T>;
		p->link = end;
		end->link = NULL;
		end->size = 0;
		for (int i = p->size / 2; i < p->size; i++)
		{
			end->arr[end->size] = p->arr[i];
			end->size++;
		}
		p->size /= 2;
		end->arr[end->size] = element;
		end->size++;
	}
}
template<typename T>
void UnrolledLinkedList<T>::add(int i, const T element)
{
	int counter = 0;
	node<T> * p = start;
	while (counter != i && p != NULL)
	{
		counter++;
		p = p->link;
	}

	if (p->size < MAX)
	{
		p->arr[p->size] = element;
		p->size++;
	}
	else
	{
		if (p->link != NULL)
		{
			node<T>* q = new node<T>;
			assert(q);
			q->link = p->link;
			p->link = q;
			q->size = 0;
			for (int i = p->size / 2; i < p->size; i++)
			{
				q->arr[q->size] = p->arr[i];
				q->size++;
			}
			p->size /= 2;
			q->arr[q->size] = element;
			q->size++;
		}
		else
		{
			end = new node<T>;
			assert(end);
			end->link = NULL;
			p->link = end;
			end->size = 0;
			for (int i = p->size / 2; i < p->size; i++)
			{
				end->arr[end->size] = p->arr[i];
				end->size++;
			}
			p->size /= 2;
			end->arr[end->size] = element;
			end->size++;
		}
	}
}
template<typename T>
void UnrolledLinkedList<T>::add(int i, int j, const T element)
{
	node<T> *p = start;
	int counter = 0;
	while (counter != i && p != NULL)
	{
		counter++;
		p = p->link;
	}

	if (j < MAX && p->arr[j] == NULL)
	{
		p->arr[j] = element;
		p->size++;
	}
	else if (j < MAX && p->arr[j] != NULL && p->size < MAX)
	{
		for (int k = p->size; k > j; k--)
		{
			p->arr[k] = p->arr[k - 1];
		}
		p->arr[j] = element;
		p->size++;
	}
	else if (j < MAX && p->arr[j] != NULL && p->size >= MAX)
	{
		if (p->link != NULL)
		{
			node<T>* q = new node<T>;
			assert(q);
			q->link = p->link;
			p->link = q;
			int t = 0;
			for (int i = p->size / 2; i < p->size; i++)
			{
				q->arr[t] = p->arr[i];
				t++;
			}
			q->size = t;
			p->size /= 2;
			int n = p->size;
			if (j < n)
			{
				for (int k = p->size; k > j; k--)
				{
					p->arr[k] = p->arr[k - 1];
				}
				p->arr[j] = element;
				p->size++;
			}
			else
			{
				for (int k = q->size; k > j - n; k--)
				{
					q->arr[k] = q->arr[k - 1];
				}
				q->arr[j - n] = element;
				q->size++;
			}
		}
		else
		{
			end = new node<T>;
			assert(end);
			end->link = NULL;
			p->link = end;
			int t = 0;
			for (int i = p->size / 2; i < p->size; i++)
			{
				end->arr[t] = p->arr[i];
				t++;
			}
			end->size = t;
			p->size /= 2;
			int n = p->size;
			if (j < n)
			{
				for (int k = p->size; k > j; k--)
				{
					p->arr[k] = p->arr[k - 1];
				}
				p->arr[j] = element;
				p->size++;
			}
			else
			{
				for (int k = end->size; k > j - n; k--)
				{
					end->arr[k] = end->arr[k - 1];
				}
				end->arr[j - n] = element;
				end->size++;
			}
		}
	}

}
template<typename T>
void UnrolledLinkedList<T>::filter(const T element)
{
	node<T> *p = start;
	while (p)
	{
		for (int i = 0; i < p->size; i++)
		{
			if (p->arr[i] == element)
			{
				for (int j = i; j < p->size - 1; j++)
				{
					p->arr[j] = p->arr[j + 1];
				}
				p->size--;
			}
		}
		p = p->link;
	}

	p = start;
	node<T> *q = p->link;
	while (p&&q)
	{
		while (p->size < MAX / 2)
		{
			p->arr[p->size] = q[0];
			p->size++;
			q->size--;
			for (int i = 0; i < q->size; i++)
			{
				q->arr[i] = q->arr[i + 1];
			}
		}
		if (q->size < MAX / 2)
		{
			for (int i = 0; i < q->size; i++)
			{
				p->arr[p->size] = q->arr[i];
				p->size++;
			}
			p->link = q->link;
			delete q;
		}
		p = p->link;
		q = q->link;
	}
}
template<typename T>
void UnrolledLinkedList<T>::isEmpty() const
{
	return start == NULL;
}
template<typename T>
int UnrolledLinkedList<T>::numberOfElements() const
{
	node<T> *p = start;
	int counter = 0;
	while (p)
	{
		counter += p->size;
		p = p->link;
	}
	return counter;
}