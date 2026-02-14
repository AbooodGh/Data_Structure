// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
#include"clsMyStack.h"
#include"clsDynamicArray.h"

using namespace std;


class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class Node1
{
public:
    int value;
    Node1* prev;
    Node1* next;

    Node1(int value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};


void InsertAtBeginning(Node*& head, int value)
{
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;

}

void InsertAtlast(Node*& head, int value)
{
  Node * temp = new Node(value);
  head->next = temp;
  head = head->next;
}

Node* Find(Node* head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
            return head;

        head = head->next;
    }
    return NULL;
}

void insertAtPosition(Node*& head, int position, int value)
{
    Node* temp = head;
    int cnt = 1;
     
    while (cnt < position -1)
    {
        temp = temp->next;
        cnt++;
    }

    Node* nodeToInsert = new Node(value);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert; 

}

void InsertAtEnd(Node*& head, int value)
{
    Node* temp = head;
    Node* Test = new Node(value);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = Test;

    cout << endl;
}

void DeletNode(Node*& head, int value)
{
    Node* temp = head;
    Node* prev = head;

    if (head == NULL)
    {
        return;
    }

    if (temp->value == value)
    {
        head = temp->next;
        delete temp;
        return ;
    }
   
    while (temp->next != NULL && temp->value != value)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

void DeleteFirstNode(Node*& head)
{
    Node* cur = head;
    if (head == NULL)
    {
        return;
    }

    head = cur->next;
    cur->next = NULL;

}

void DeleteLastNode(Node*& head)
{
    Node* temp = head;
    Node* prev = head;
    if (head == NULL)
    {
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;

}

void PrintList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int GetLength(Node1* head)
{
    Node1* temp = head;
    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void InsertAtHead(Node1*& head , int value)
{
    Node1* temp = new Node1(value);
    
    if (head == NULL)
    {
        return;
    }

    temp->next = head;
    head->prev = temp;

    head = temp;
}

void InsertAtTheEnd(Node1*& head, int value)
{
    Node1* temp = new Node1(value);
    Node1* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;

}


void InsertAtPosition(Node1*& head, int position, int value)
{
    Node1* temp = new Node1(value);
    Node1* here = head;
    Node1* next = here->next;

    int cunt = 1;

    while (cunt < position-1)
    {
        here = here->next;
        next = next->next;
        cunt++;
    }



    here->next = temp;
    temp->prev = here;
    temp->next = next;
    next->prev = temp;

}

void DeleteNode(Node1*& head, int value)
{
    Node1* temp = head;
    Node1* cur = temp;
    Node1 *next = temp->next;

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

}

void DeleteFirstDL(Node1*& head)
{
    Node1* temp = head;
    Node1* cur = temp->next;

    temp->next = NULL;
    cur->prev = NULL;
    head = cur;

}

void DeleteLastDlNode(Node1*& head)
{
    Node1* temp = head;
    Node1* cur = temp;

    while (temp->next != NULL)
    {
        temp = temp->next;
        cur = temp->prev;
    }

    cur->next = NULL;
    temp->prev = NULL;
}

void PrintDoubleList(Node1* head)
{
    Node1* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{

    clsDynamicArray <int> MyArray(5);

    MyArray.SetItem(0, 10);
    MyArray.SetItem(1, 20);
    MyArray.SetItem(2, 30);
    MyArray.SetItem(3, 40);
    MyArray.SetItem(4, 50);

    cout << "\nIs Empty ? " <<MyArray.IsEmpty() << endl;
    cout << "\nSize is : " << MyArray.Size() << endl;
    cout << "\nArray Items : \n";
    MyArray.PrintList();

    cout << "\nItem(2) : " << MyArray.GetItem(2) << "\n";


    MyArray.DeleteItem(2);
    cout << "\nArray After Deleteing Item 2 is : \n";
    MyArray.PrintList();

   // clsMyStack <int> MyStack;
   // 
   // MyStack.Push(10);
   // MyStack.Push(20);
   // MyStack.Push(30);
   // MyStack.Push(40);
   // MyStack.Push(50);

   // MyStack.PrintQueue();
   //cout <<  MyStack.Bottom() << endl;
   //cout << MyStack.Top() << endl;

//    clsMyQueue <int> MyQueue;
//
//    MyQueue.Push(10);
//    MyQueue.Push(20);
//    MyQueue.Push(30);
//    MyQueue.Push(40);
//    MyQueue.Push(50);
//
//    cout << "\nQueue : \n";
//    MyQueue.PrintQueue();



    //cout << "\nQueue Size is : " << MyQueue.Size() << endl;
    //cout << "\nFront Item is : " << MyQueue.Front() << endl;
    //cout << "\nBack Item is : " << MyQueue.Back() << endl;

    //MyQueue.Pop();

    //cout << "\nQueue After Pop : \n";
    //MyQueue.PrintQueue();

    //cout << "\n\n Item(2) : " << MyQueue.GetItem(2);
    //
    //MyQueue.Reverse();
    //cout << "\n\nQueue After reverse() : \n";
    //MyQueue.PrintQueue();

    //MyQueue.UpdateItem(2, 111);
    //cout << "\n\nQueue After Updating item(2) to 111 is : \n";
    //MyQueue.PrintQueue();

    //MyQueue.InsertAfter(0, 800);
    //cout << "\n\nQueue after inserting 800 After Item(2) is : \n";
    //MyQueue.PrintQueue();


    //MyQueue.InsertAtFront(96);
    //cout << "\n\nQueue after inserting at the front is : \n";
    //MyQueue.PrintQueue();

    //MyQueue.InsertAtBack(966);
    //cout << "\n\nQueue after inserting at the Back is : \n";
    //MyQueue.PrintQueue();

    //MyQueue.Clear();
    //cout << "\n\nQueue after Clearing is : \n";
    //MyQueue.PrintQueue();

    //cout << "\nQueue Size is : " << MyQueue.Size() << endl;

//    clsDblLinkedList <int> dblList;
//    //dblList.InsertAtBeginning(10);
//    //dblList.InsertAtBeginning(20);
//    //dblList.InsertAtBeginning(30);
///*
//    if (dblList.IsEmpty())
//        cout << "\nYes list is Empty.\n";
//    else
//        cout << "\nNo list is not Empty.\n";
//  */  
//    dblList.InsertAtBeginning(10);
//    dblList.InsertAtBeginning(20);
//    dblList.InsertAtBeginning(30);
//    dblList.InsertAtTheEnd(50);
//    dblList.InsertAtTheEnd(60);
//    dblList.InsertAtTheEnd(70);
//
//      dblList.PrintDoubleList();
//
//      clsDblLinkedList <int>::Node* N;
//      N = dblList.GetNode(2);
//
//      cout << "\nNode Value is :" << N->value << endl;
//
//      cout << "\nItem value is : " << dblList.GetItem(2) << endl;
//
//      dblList.UpdateValue(2, 100);
//      cout << "\nItem value is : " << dblList.GetItem(2) << endl;
//
//      dblList.PrintDoubleList();

//    cout << "Before reversing the list : " << endl;
//
//    dblList.PrintDoubleList();
//
//
//    dblList.ReverseDoubleList();
//
//    cout << "After reversing the list : " << endl;
//
//    dblList.PrintDoubleList();

//    if (dblList.IsEmpty())
//        cout << "\nYes list is Empty.\n";
//    else
//        cout << "\nNo list is not Empty.\n";
//
//    cout << "\nNumber of Nodes is " << dblList.Size() << endl;
//
//    dblList.InsertAtPosition(4, 40);
//    dblList.PrintDoubleList();
//
//
//    dblList.DeleteNode(40);
//
//    dblList.PrintDoubleList();
//
//    cout << "\nNumber of Nodes before clearing is " << dblList.Size() << endl;
//
//    cout << "\nExecuting .Clear()";
//    dblList.Clear();
//    cout << "\nNumber of Nodes after clearing is " << dblList.Size() << endl;
//    dblList.PrintDoubleList();


    //dblList.DeleteFirstDL();
    //dblList.PrintDoubleList();
    //dblList.DeleteFirstDL();
    //dblList.PrintDoubleList();
    //dblList.DeleteFirstDL();
    //dblList.DeleteLastDlNode();
    //dblList.DeleteLastDlNode();
    //dblList.DeleteLastDlNode();

    //dblList.PrintDoubleList();

 /*
    clsDblLinkedList<int>::Node* A = dblList.Find(20);
    clsDblLinkedList<int>::Node* B = dblList.Find(50);


    clsDblLinkedList<int>::Node * N = dblList.Find(10);
    
    cout << "\n\nValue N is " << N->value << endl;
    cout << "\n\nAddress N is " << &N << endl;

    cout << "\n\nValue A is " << A->value << endl;
    cout << "\n\nAddress A is " << &A << endl;

    cout << "\n\nValue B is " << B->value << endl;
    cout << "\n\nAddress B is " << &(*B) << endl;

    cout << "\n\nAddress N.Next is " << &(*N->next) << endl;

    cout << "\n\nAddress B.prev is " << &(*B->prev) << endl;

    cout << "\n\nAddress N.next is " << &(*N) << endl;

    cout << "\n\nAddress A.next is " << &(*A->next) << endl;
    cout << "\n\nAddress N is " << &(*N) << endl;

    cout << "\n\nAddress N.prev is " << &(*N->prev) << endl;
    cout << "\n\nAddress A is " << &(*A) << endl;
    */

    //if (N != nullptr)
    //{
    //    cout << "Node It's Found \n";
    //}
    //else
    //{
    //    cout << "It's not found \n";
    //}
    //Node1* node1 = new Node1(0);
    //Node1* head = node1;

  

    //InsertAtHead(head, 1);
    //InsertAtHead(head, 2);
    //InsertAtHead(head, 3);

    //PrintDoubleList(head);

    //InsertAtTheEnd(head, 2);
    //
    //InsertAtTheEnd(head, 3);
    //InsertAtTheEnd(head, 4);
    //InsertAtTheEnd(head, 5);
    //InsertAtTheEnd(head, 6);
    //InsertAtTheEnd(head, 7);


    //InsertAtTheEnd(head, 8);

    //PrintDoubleList(head);


    //InsertAtPosition(head, 4, 20);

    //PrintDoubleList(head);

    //DeleteNode(head, 2);

    //PrintDoubleList(head);


    //DeleteFirstDL(head);

    //DeleteFirstDL(head);

    //PrintDoubleList(head);


    //DeleteLastDlNode(head);
    //DeleteLastDlNode(head);
    //DeleteLastDlNode(head);

    //PrintDoubleList(head);

    //cout << GetLength(head) << endl;
    //Node* Node1 = new Node(1);
    //Node* head = Node1;
    //Node* tail = Node1;
    //

    //InsertAtlast(tail, 2);
    //             
    //InsertAtlast(tail, 3);
    //             
    //InsertAtlast(tail, 4);
    //             
    //InsertAtlast(tail, 5);

    //cout << endl;

    ////insertAtPosition(head, 2, 22);

    //InsertAtEnd(tail, 522);

    //InsertAtEnd(tail, 500);


    //PrintList(head);

    //DeleteFirstNode(head);
    //DeleteFirstNode(head);

    //DeleteLastNode(head);

    ////DeletNode(head, 500);

    ////DeletNode(tail, 1);


    //PrintList(head);


//    InsertAtBeginning(head, 3);
//    InsertAtBeginning(head, 4);
//    InsertAtBeginning(head, 5);

    

    system("pause>0");
    return 0;
}

