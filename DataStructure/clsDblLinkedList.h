#pragma once
#include<iostream>
#include<string>
using namespace std;

template <class T>

class clsDblLinkedList
{

protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;

		Node(T value)
		{
			this->value = value;
			this->next = nullptr;
			this->prev = nullptr;
		}
	};



	Node* head = nullptr;

	void InsertAtBeginning(T value)
	{
		//		Node1* node1 = new Node1(0);
		//		Node1* head = node1;

		Node* temp = new Node(value);
		//Node* head = temp;


		if (head == nullptr)
		{
			head = temp;
			++_Size;
			return;
		}

		temp->next = head;
		head->prev = temp;

		head = temp;

		++_Size;
	}


	void InsertAtTheEnd(T value)
	{
		Node* temp = new Node(value);
		Node* last = head;

		if (head == nullptr)
		{
			head = temp;
			++_Size;
			return;
		}

		while (last->next != nullptr)
		{
			last = last->next;
		}

		last->next = temp;
		temp->prev = last;

		++_Size;
	}


	void InsertAtPosition(T position, T value)
	{
		Node* temp = new Node(value);
		Node* here = head;
		Node* next = here->next;

		T cunt = 0;

		while (cunt < position - 1)
		{
			here = here->next;
			next = next->next;
			cunt++;
		}

		here->next = temp;
		temp->prev = here;
		temp->next = next;
		next->prev = temp;

		++_Size;
	}

	Node* Find(T value)
	{
		Node* temp = head;

		while (temp->next != nullptr)
		{
			if (temp->value == value)
				return temp;

			temp = temp->next;
		}

		return nullptr;

	}


	void DeleteNode(T value)
	{

		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;
		Node* cur = temp;
		Node* next = temp->next;

		while (temp->value != value)
		{
			temp = temp->next;
			cur = temp->prev;
			next = temp->next;
		}

		cur->next = next;
		next->prev = cur;
		temp->next = NULL;
		temp->prev = NULL;

		--_Size;
	}

	void DeleteLastDlNode()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;
		Node* cur = temp;

		while (temp->next != NULL)
		{
			temp = temp->next;
			cur = temp->prev;
		}

		cur->next = NULL;
		temp->prev = NULL;

		--_Size;

	}

	void DeleteFirstDL()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;
		Node* cur = temp->next;

		temp->next = NULL;
		cur->prev = NULL;
		head = cur;

		--_Size;

	}

	void ReverseDoubleList()
{
    if (head == nullptr)
    {
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    // 1. عملية التبديل
    while (current != nullptr)
    {
        // تبديل المؤشرات داخل العقدة
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // الانتقال للعقدة التالية (التي أصبحت الآن في الـ prev بسبب التبديل)
        current = current->prev;
    }

    // 2. تحديث رأس القائمة (Head)
    // بعد الحلقة، temp سيشير إلى العقدة التي كانت قبل الأخيرة، 
    // لذا نحتاج للرجوع خطوة واحدة للخلف للوصول للرأس الجديد.
    if (temp != nullptr)
    {
        head = temp->prev;
    }
}


	Node* GetNode(T index)
	{
		T temp = 0;
		Node* current = head;

		if (head == nullptr)
		{
			return NULL;
		}

		while (current != nullptr)
		{
			if (temp == index)
			{
				return current;
			}
			temp++;

			current = current->next;
		}

		return NULL;
	}
	
	T GetItem(T index)
	{

		Node * ItemNode = GetNode(index);

		if (ItemNode != nullptr)
		{
			return ItemNode->value;
		}


//		T temp = 0;
//		Node* current = head;
//
//		if (head == nullptr)
//		{
//			return NULL;
//		}
//
//		while (current != nullptr)
//		{
//			if (temp == index)
//				return current->value;
//			
//			temp++;
//			current = current->next;
//		}

		return 0;
	}

	T UpdateValue(T index , T NewValue)
	{

		Node* ItemNode = GetNode(index);

		if (ItemNode != nullptr)
		{
			ItemNode->value = NewValue;
			return ItemNode->value;
		}

//		T temp = 0;
//		Node* current = head;
//
//		if (head == nullptr)
//		{
//			return NULL;
//		}
//
//		while (current != nullptr)
//		{
//			if (temp == index)
//				current->value = NewValue;
//
//			temp++;
//			current = current->next;
//		}

		return 0;
	}


	bool InsertAfter(int Index, T value)
	{
//		Node * ItemNode = GetNode(Index);
//
//		if (ItemNode != nullptr)
//		{
//			InsertAtPosition(ItemNode , value)
//		}
	}

	void PrintDoubleList()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		//		while (!IsEmpty())
		//		{
		//			DeleteFirstDL();
		//		}

				//while (_Size > 0)
				//{
				//	DeleteFirstDL();
				//}

		head = nullptr;
		_Size = 0;

	};



};