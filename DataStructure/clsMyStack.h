#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
#include"clsMyQueue.h"

template <class T>
class clsMyStack : public clsMyQueue <T>
{
public:
	void Push(T Item)
	{
		this->InsertAtFront(Item);
//		clsMyQueue <T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return this->Front();
	}

	T Bottom()
	{
		return this->Back();
	}
};

