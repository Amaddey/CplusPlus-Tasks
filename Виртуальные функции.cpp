#pragma once
#include <iostream>
#include <string>

using namespace std;

class DoubleList
{
	struct Node
	{
		int data;
		Node* pNext;
		Node* pPrev;
	};

private:
	Node* tail;
	Node* head;
	int counter = 0;
public:
	DoubleList() : tail(nullptr), head(nullptr) {}
	~DoubleList()
	{
		while (head)
		{
			tail = head->pNext;
			delete head;
			head = tail;
		}
	}

	virtual void addToTail(int num)
	{
		Node* newNode = new Node;
		newNode->data = num;
		newNode->pNext = nullptr;

		if (counter == 0)
		{
			newNode->pNext = nullptr;
			this->head = newNode;
			this->tail = newNode;
		}
		counter++;
	}
	virtual int deleteElemFromTail()
	{
		Node* temp = tail->pPrev;
		Node* del = tail;
		tail = temp;
		tail = temp;
		tail->pNext = nullptr;
		counter--;
		delete[] del;
	}
	void DeleteFromHead()
	{
		if (counter == 1)
		{
			delete head->pNext;
			delete tail->pPrev;
			counter = 0;
		}
		else
		{
			Node* temp = head;
			head = temp->pNext;
			temp->pNext = nullptr;
			temp->pPrev = nullptr;
			temp->pPrev = nullptr;
			counter--;
			delete[] temp;
		}
	}
	void show()
	{
		Node* temp = head;
		for (int i = 0; i < counter; i++)
		{
			cout << temp->data << " ";
			temp = temp->pNext;
		}
		cout << endl << endl;
	}

};

