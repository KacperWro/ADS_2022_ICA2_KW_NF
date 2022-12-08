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

	/*E* search(K key) {
		return nullptr;
	}*/

	// Currently not 100% sure whether to make this one return a true/false value or a pointer
	// If such an object exists then the insertion won't happen, but it it's already there
	// Do we really care if the insertion happened or not?
	// do we provide both a key and a full object? for example, use the key's hash for navigation
	// and then attach the data object to the tree?

	/*E* insert(K key, E dataObj) {
		return nullptr;
	}*/

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


	void printInOrder(int maxDepth)
	{
		this->printInOrder(root, maxDepth, 0);
		cout << endl;
	}
	void printInOrder(TNode<K, E>* node, int maxDepth, int currentDepth)
	{
		if (node != nullptr)
		{
			if (currentDepth++ <= maxDepth) {
				printInOrder(node->getpLeft(), maxDepth, currentDepth++);
				node->getData().print();
				currentDepth--;
				printInOrder(node->getpRight(), maxDepth, currentDepth++);
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
		//if (root == nullptr)
		//	return 0;

		TNode<size_t, Student>* toBeFound = search(key);
		toBeFound->getHeight(counter, max);
	}

	// Pretty sure this one would require a search first, then a recursive deletion algorithm
	// similar to the count algorithm... but that is only if nodes are dynamically allocated
	// if they are not recursively allocated, wouldn't c++ just clean them up itself?
	// return false could signify the key wasnt in the tree or key was entered wrong by user
	//bool deleteSubTree(K key) {
	//	return false;
	//}

	// return a string or make this one as an ostream???
	/*string printTree(size_t depth) {
		string compilestr = "";
		return compilestr;
	}*/
};
