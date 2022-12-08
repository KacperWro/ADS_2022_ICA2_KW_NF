#pragma once
//if E == Student (email, dob, address, id,...)
// create Student class
// read data from csv
// create StudentKey class
//then K = StudentKey(email, dob, address)
// create hash number from three selected fields and use as Key in node object
//hashcode method for Key (gives unique number)
#include <string>
#include "TNode.h"
#include "Student.h"
#include "StudentKey.h"

template <typename K, typename E>
class BinaryTree
{
public:
	TNode<size_t, Student>* root;

	BinaryTree()
	{
		this->root = nullptr;
	}

	BinaryTree(TNode<size_t, Student>* root) {
		this->root = root;
	}


	void addItemToArray(TNode<size_t, Student>* node, int& pos, TNode<size_t, Student>* arr)
	{
		if (node != nullptr)
		{
			addItemToArray(node->getpLeft(), pos, arr);
			arr[pos] = *node;
			pos++;
			addItemToArray(node->getpRight(), pos, arr);
		}

	}


	TNode<size_t, Student>* toArray()
	{
		TNode<size_t, Student>* arr = new TNode<size_t, Student>[root->count()];
		int pos = 0;
		addItemToArray(root, pos, arr);
		return arr;
	}

	int count()
	{
		if (root == nullptr)
			return 0;
		return root->count();
	}

	void clear()
	{
		delete root;
		root = nullptr;
	}


	void printToDepthN(int maxDepth)
	{
		this->printToDepthN(root, maxDepth, 0);
		cout << endl;
	}
	void printToDepthN(TNode<K, E>* node, int maxDepth, int currentDepth)
	{
		if (node != nullptr)
		{
			if (currentDepth++ <= maxDepth) {
				cout << "Current depth: " << currentDepth << endl;
				printToDepthN(node->getpLeft(), maxDepth, currentDepth++);
				node->getData().print();
				currentDepth--;
				printToDepthN(node->getpRight(), maxDepth, currentDepth++);
			}
		}
	}


	BinaryTree getSubTree(TNode<size_t, Student>* newRoot) {
		return BinaryTree(newRoot);
	}

	void insert(K key, E data)
	{
		if (root == nullptr)
		{
			//cout << "\nroot pointer is null" << endl;
			root = new TNode<size_t, Student>(key, data);
		}
		else
		{
			//cout << "\nroot pointer is not null" << endl;
			root->insert(key, data);
		}
	}


	TNode<size_t, Student>* search(K key) {
		TNode<size_t, Student>* toBeFound = root;
		TNode<size_t, Student>* parent = nullptr;
		bool found = false;

		while (!found && toBeFound != nullptr)
		{
			if (toBeFound->getKey() == key)
			{
				return toBeFound;
			}
			else
			{
				parent = toBeFound;
				if (toBeFound->getKey() > key)
				{
					toBeFound = toBeFound->getpLeft();
				}
				else
				{
					toBeFound = toBeFound->getpRight();
				}
			}
		}
		return nullptr;
	}

	bool remove(K currentKey, K originalKey)
	{
		TNode<size_t, Student>* toBeRemoved = this->root;
		TNode<size_t, Student>* parent = nullptr;
		bool found = false;

		while (!found && toBeRemoved != nullptr)
		{
			if (toBeRemoved->getKey() == currentKey)
			{
				found = true;
			}
			else
			{
				parent = toBeRemoved;
				if (toBeRemoved->getKey() > currentKey)
				{
					toBeRemoved = toBeRemoved->getpLeft();
				}
				else
				{
					toBeRemoved = toBeRemoved->getpRight();
				}
			}
		}
		if (!found)
			return false;

		if (toBeRemoved->getpLeft() != nullptr) {
			cout << "call remove left" << endl;
			remove(toBeRemoved->getpLeft()->getKey(), originalKey);
		}
		if (toBeRemoved->getpRight() != nullptr) {
			cout << "call remove right" << endl;
			remove(toBeRemoved->getpRight()->getKey(), originalKey);
		}

		if (toBeRemoved->getpLeft() == nullptr && toBeRemoved->getpRight() == nullptr) {
			cout << "deleting: " << currentKey << endl;

			TNode<size_t, Student>* parentNode = toBeRemoved->getParent();

			if (parentNode == nullptr) {
				this->clear();
				return true;
			}

			if (parentNode->getpLeft() != nullptr && parentNode->getpLeft()->getKey() == currentKey) {
				delete parentNode->getpLeft();
				parentNode->setPLeft(nullptr);
				return true;
			}

			if (parentNode->getpRight() != nullptr && parentNode->getpRight()->getKey() == currentKey) {
				delete parentNode->getpRight();
				parentNode->setPRight(nullptr);
				return true;
			}

			if (currentKey != originalKey) {
				remove(originalKey, originalKey);
			}

		}

	}

	size_t depth(K key) {
		TNode<size_t, Student>* toBeFound = root;
		TNode<size_t, Student>* parent = nullptr;
		bool found = false;
		size_t layer_num = 0;

		while (!found && toBeFound != nullptr)
		{
			if (toBeFound->getKey() == key)
			{
				return layer_num;
			}
			else
			{
				parent = toBeFound;
				layer_num++;
				if (toBeFound->getKey() > key)
				{
					toBeFound = toBeFound->getpLeft();
				}
				else
				{
					toBeFound = toBeFound->getpRight();
				}
			}
		}
		return -1;
	}

	void getHeight(int& counter, int& max, K key)
	{
		TNode<size_t, Student>* toBeFound = search(key);
		toBeFound->getHeight(counter, max);
	}

	
};
