#pragma once
#include<iostream>
using namespace std;

template <class T> 
class clsDynamicArray
{

protected :
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int Size)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T Value)
	{
		if (index < 0 || index >= _Size)
			return false;

		OriginalArray[index] = Value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}
		_TempArray = new T[NewSize];

		if(NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[_Size];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItem(int index)
	{
		if (index >= _Size || index < 0)
		{
			return false;
		}
		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}
		delete OriginalArray;
		OriginalArray = _TempArray;
	}

	void DeleteFirstItem()
	{
		DeleteItem(0);
	}

    // In Resize(int NewSize)
//    int CopyCount = (_Size < NewSize) ? _Size : NewSize;
//    for (int i = 0; i < CopyCount; i++)
//    {
//        _TempArray[i] = OriginalArray[i];
//    }
	void DeleteLastItem()
	{
		DeleteItem(_Size - 1);
	}


	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == vlaue)
			{
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		int index = Find(Value);
		if (index == -1)
		{
			return false;
		}
		return DeleteItem(index);
		return true;
	}

	bool InsertAt(T index, T value)
	{
		if (index < 0 || index > _Size)
		{
			return false;
		}

		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = value;
		for (int i = index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	void InsertAtBack(T value)
	{
		InsertAt(_Size, value);
	}

	bool InsertBefore(T index , T value)
	{
		if(index < 1)
			return InsertAt(0, value);

		else
			return InsertAt(index - 1, value);
	}
	
	bool InsertAfter(int Index, T value)
	{
		if (Index < 0)
			return false;

		if (Index >= _Size - 1)
			return InsertAt(_Size, value);   // insert at end
		else
			return InsertAt(Index + 1, value);

	}



};

