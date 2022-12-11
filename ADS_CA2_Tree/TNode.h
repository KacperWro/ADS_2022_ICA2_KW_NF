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
		this->pLeft = nullptr;
		this->pRight = nullptr;
		this->parent = nullptr;
	}

	int count()
	{
		int c = 1;
		if (pLeft != nullptr)
		{
			//cout << "\nHash: " << pLeft->getKey();
			c += pLeft->count();
		}
		if (pRight != nullptr)
		{
			//cout << "\nHash: " << pRight->getKey();
			c += pRight->count();
		}
		return c;
	}

	void getHeight(int& counter, int& max)
	{
		if (pLeft == nullptr && pRight == nullptr)
		{
			if (counter > max) {
				max = counter;
			}
		}
		else {
			if (pLeft != nullptr)
			{
				counter += 1;
				pLeft->getHeight(counter, max);
				counter--;
			}
			if (pRight != nullptr)
			{
				counter += 1;
				pRight->getHeight(counter, max);
				counter--;

			}
		}

	}

	bool insert(K key, E data) {
		
		if (key == this->key)
		{
			//If the binary tree already has a node associated with the passed in key, then we don't insert anything into the tree
			return false;
		}
		else if (key < this->key)
		{
			//If the value of the passed in key is smaller than they value of the key of the node that this function is being invoked on
			//then go to the left child of the invoked node
			
			if (pLeft == nullptr)
			{
				//If that left child is a nullptr, create a new TNode made up of the passed in key and data and assign it to the left child
				pLeft = new TNode<K, E>(key, data);
				pLeft->parent = this;
				return true;
			}
			else
			{
				//Otherwise, invoke the insert function on that left child
				pLeft->insert(key, data);
			}

			return true;
		}
		else
		{
			//The right child is treated the same way as the left child (described above)
			if (pRight == nullptr)
			{
				pRight = new TNode<K, E>(key, data);
				pRight->parent = this;
				return true;
			}
			else
			{
				pRight->insert(key, data);
			}

		}
	}

	E getData() const { return this->data; }
	K getKey() const { return this->key;  }
	TNode* getpLeft() const { return this->pLeft; }
	TNode* getpRight() const { return this->pRight; }
	TNode* getParent() const { return this->parent; }
	void setPLeft(TNode* newLeft) { this->pLeft = newLeft; }
	void setPRight(TNode* newRight) { this->pRight = newRight; }
	void setData(E data) { this->data = data; }
};
