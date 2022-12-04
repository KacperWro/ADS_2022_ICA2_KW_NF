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
		root = nullptr;
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


	bool remove(K key)
	{
		TNode<size_t, Student>* toBeRemoved = root;
		TNode<size_t, Student>* parent = nullptr;
		bool found = false;

		while (!found && toBeRemoved != nullptr)
		{
			if (toBeRemoved->getKey() == key)
			{
				found = true;
			}
			else
			{
				parent = toBeRemoved;
				if (toBeRemoved->getKey() > key)
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

		if (toBeRemoved->getpLeft() == nullptr || toBeRemoved->getpRight() == nullptr)
		{
			TNode<size_t, Student>* newChild;
			if (toBeRemoved->getpLeft() == nullptr)
			{
				newChild = toBeRemoved->getpRight();
			}
			else
			{
				newChild = toBeRemoved->getpLeft();
			}
			if (parent == nullptr)
			{
				root = newChild;
			}
			else if (parent->getpLeft() == toBeRemoved)
			{
				parent->setPLeft(newChild);
			}
			else
			{
				parent->setPRight(newChild);
			}
			return true;
		}

		TNode<size_t, Student>* smallestParent = toBeRemoved;
		TNode<size_t, Student>* smallest = toBeRemoved->getpRight();
		while (smallest->getpLeft() != nullptr)
		{
			smallestParent = smallest;
			smallest = smallest->getpLeft();
		}
		toBeRemoved->setData(smallest->getData());
		if (smallestParent == toBeRemoved)
		{
			smallestParent->setPRight(smallest->getpRight());
		}
		else
		{
			smallestParent->setPLeft(smallest->getpLeft());
		}

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
