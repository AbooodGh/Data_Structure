#pragma once

#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;

template <class T> 

class clsMyQueue
{

protected:
	clsDblLinkedList <T> _MyStack;

public:

	void Push(T value)
	{
		_MyStack.InsertAtTheEnd(value);
	}

	void Pop()
	{
		_MyStack.DeleteFirstDL();
	}

	T Front()
	{
		return _MyStack.GetItem(0);
	}

	T Back()
	{
		return _MyStack.GetItem(Size() - 1);
	}

	void PrintQueue()
	{
		_MyStack.PrintDoubleList();
	}

	bool IsEmpty()
	{
		return _MyStack.IsEmpty();
	}

	int Size()
	{
		return _MyStack.Size();
	}

	T GetItem(T Item)
	{
		return _MyStack.GetItem(Item);
	}

	void Reverse()
	{
		_MyStack.ReverseDoubleList();
	}

	void UpdateItem(T index, T value)
	{
		_MyStack.UpdateValue(index, value);
	}

	void InsertAfter(T Index, T value)
	{
		_MyStack.InsertAtPosition(Index, value);
	}
	
	void InsertAtFront(T Value)
	{
		_MyStack.InsertAtBeginning(Value);
	}

	void InsertAtBack(T value)
	{
		_MyStack.InsertAtTheEnd(value);

	}

	void Clear()
	{
		_MyStack.Clear();
	}

};

