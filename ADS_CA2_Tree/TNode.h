#pragma once
#include "Student.h"
#include "StudentKey.h"

using namespace std;
template <typename K, typename E>
class TNode {
private:
	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E data;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight, *parent;

public:
	TNode(K key, E data) {     // Constructor
		this->key = key;
		this->data = data;
	}

	TNode() {
		
	}

	bool insert(K key, E data) {
		
		if (key.getUser_id() == this->key.getUser_id())
		{
			cout << "id is the same" << endl;
			return false;
		}
		else if (key.getUser_id() < this->key.getUser_id())
		{
			cout << "else if statement" << endl;
			if (pLeft == nullptr)
			{
				pLeft = new TNode<K, E>(key, data);
				pLeft->parent = this;
				cout << "inserted into left child" << endl;
				return true;
			}
			else
			{
				cout << "left child is not null" << endl;
				pLeft->insert(key, data);
			}

			return true;
		}
		else
		{
			cout << "else statement" << endl;
			if (pRight == nullptr)
			{
				pRight = new TNode<K, E>(key, data);
				pRight->parent = this;
				cout << "inserted into right child" << endl;
				return true;
			}
			else
			{
				cout << "right child is not null" << endl;
				pRight->insert(key, data);
			}

		}
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }
	TNode* getpLeft() const { return this->pLeft; }
	TNode* getpRight() const { return this->pRight; }
	TNode* getParent() const { return this->parent; }
};
