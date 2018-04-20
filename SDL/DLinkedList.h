#pragma once;
#include <stdio.h>
template <class T> class DLinkedListIterator;
template <class T> class DLinkedList;
template <class T> class Node;


template <class T>
class Node
{
public:
	T data;
	Node *prev;
	Node *next;

	void InsertAfterNode(T data)
	{
		Node<T> *newNode=new Node<T>();
		newNode->prev = this;
		newNode->next = next;
		next = newNode;

		if (0 != newNode->next)
			newNode->next->prev = newNode;

		newNode->data=data;
	}

	void InsertBeforeNode(T data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->next = this;
		newNode->prev = this->prev;

		if (0 != this->prev)
			this->prev->next = newNode;
	
		this->prev = newNode;
		
		newNode->data = data;
	}

	void DLink()
	{
		if(0!=prev)
			prev->next = next;

		if(0!=next)
			next->prev = prev;
	}
};


template <class T>
class DLinkedList
{
public:
	Node<T> *_head;
	Node<T> *_tail;
	int _count;

	DLinkedList()
	{
		_head = 0, _tail = 0;
		_count = 0;
	}

	void apend(T data)//마지막의 data대입
	{
		Node<T> *Link_data;
		if (0 == _head)
		{
			Link_data = new Node<T>();
			_head = Link_data;
			_tail = Link_data;
			_head->data = data;
			_head->next = 0;
			_tail->prev = 0;
		}
		else
		{
			_tail->InsertAfterNode(data);
			_tail = _tail->next;
		}
		_count++;
	}

	void prepend(T data)
	{
		Node<T> *Link_data;

		if (0 == _head)
		{
			Link_data = new Node<T>();
			_head = Link_data;
			_tail = Link_data;
			_head->data = data;
			_head->next = 0;
			_tail->prev = 0;
		}
		else
		{
			_head->InsertBeforeNode(data);
			_head = _head->prev;
		}
		_count++;
	}
	void removeHead()
	{
		if (0 != _head) 
		{
			Node<T> *node = _head->next;
			delete _head;
			_head = node;

			if (0 == _head)
				_tail = 0;
			else
			_head->prev = 0;

		}
	}
	void removeTail()
	{
		if (0 != _tail)
		{
			Node<T> *node = _tail->prev;
			delete _tail;
			_tail= node;

			if (0 == _tail)
				_head = 0;
			else
				_tail->next= 0;
		}
	}

	~DLinkedList()
	{
		Node<T> *node = _head;
		Node<T> *next;
		while (0!=node)
		{
			next = node->next;
			delete node;
			node = next;
		}
	}

	void saveData()
	{
		FILE *fp = fopen("aaa", "w+b");
		if (0==fp)return;

		fwrite(&_count, sizeof(int), 1, fp);
		Node<T> *node = _head;
		
		while (node!=0)
		{
			fwrite(&node->data, sizeof(T), 1, fp);
			node = node->next;
		}

		fclose(fp);
	}

	void loadData()
	{
		FILE *fp = fopen("aaa", "rb");
		if (0 == fp)return;

		int tmp_count;

		fread(&tmp_count, sizeof(int), 1, fp);

		//for(tmp_count;tmp_count>0;tmp_count--)
		for(int i=0 ; i<tmp_count ; i++)
		{
			T buffer;
			fread(&buffer, sizeof(T), 1, fp);
			apend(buffer);
		}
		fclose(fp);
	}

	DLinkedListIterator<T> GetIterator()
	{
		return DLinkedListIterator<T>(this, _head);
	}

	void Remove(DLinkedListIterator<T>& itr )
	{
		if (0 != itr._node)
		{
			Node<T> *node = itr._node;

			if (itr._node == _head)//노드가 해드인지 체크후 노드위치 변경
				_head = _head->next;

			if (itr._node == _tail)//노드가 테일인지 체크후 노드위치 변경
				_tail = _tail->prev;

			node->DLink();

			itr.Forth();

			delete node;

			if (0 == _head)
				_tail = 0;

			_count--;
		}
		else
			return;
	}

	void InsertAfter(DLinkedListIterator<T>& itr, T data)
	{
		if (0 != itr._node)
		{
			itr._node->InsertAfterNode(data);
			if (itr._node == _tail)
			{
				_head = itr._node->next;
				_count++;
			}

		}
		else
			apend(data);
	}

	void InsertBefore(DLinkedListIterator<T>& itr, T data)
	{
		if (0 != itr._node)
		{
			itr._node->InsertBeforeNode(data);
			if (itr._node == _head)
			{
				_tail = itr._node->prev;
				_count++;
			}
		}

		else
			prepend(data);
	}

	int Count()
	{
		return _count;
	}

};

template <class T>

class DLinkedListIterator
{
public:

	DLinkedList<T> *_DLinked;
	Node<T> *_node;

	DLinkedListIterator(DLinkedList<T>  *LinkedList, Node<T> *node)
	{
		_DLinked = LinkedList;
		_node = node;
	}

	void start()
	{
		_node = _DLinked->_head;
	}
	void End() 
	{
		_node = _DLinked->_tail;
	}
	void Forth()
	{
		if(0!=_node)
		_node = _node->next;
	}
	void Back()
	{
		if(0!=_node)
		_node = _node->prev;
	}

	bool valid() 
	{
		if (0 != _node)
			return true;
		else 
			return false;
	}

	T item() 
	{ 
		return _node->data;
	}
};

