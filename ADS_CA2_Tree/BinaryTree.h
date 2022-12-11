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
	TNode<K, E>* root;

	BinaryTree()
	{
		this->root = nullptr;
	}

	BinaryTree(TNode<K, E>* root) {
		this->root = root;
	}


	void addItemToArray(TNode<K, E>* node, int& pos, TNode<K, E>* arr)
	{
		if (node != nullptr)
		{
			addItemToArray(node->getpLeft(), pos, arr);
			arr[pos] = *node;
			pos++;
			addItemToArray(node->getpRight(), pos, arr);
		}

	}


	TNode<K, E>* toArray()
	{
		TNode<K, E>* arr = new TNode<K, E>[root->count()];
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


	bool printToDepthN(int maxDepth)
	{
		this->printToDepthN(root, maxDepth, 0);
		cout << endl;
		return true;
	}
	void printToDepthN(TNode<K, E>* node, int maxDepth, int currentDepth)
	{
		if (node != nullptr)
		{
			//As long as the current depth is less than or equal to the max depth, the function will continue to print the contents of the nodes
			if (currentDepth++ <= maxDepth) {
				cout << "Current depth: " << currentDepth << endl;
				printToDepthN(node->getpLeft(), maxDepth, currentDepth++);
				node->getData().print();

				//We are decrementing currentDepth as the current node has 2 children, which are on the same depth, so have to decrement it so that the children of
				//any node don't end up getting missed
				currentDepth--;
				printToDepthN(node->getpRight(), maxDepth, currentDepth++);
			}
		}
	}


	BinaryTree getSubTree(TNode<K, E>* newRoot) {
		return BinaryTree(newRoot);
	}

	bool insert(K key, E data)
	{
		if (root == nullptr)
		{
			//If the root is a nullptr, the node that we are trying to insert into the tree will become the root of that tree
			root = new TNode<K, E>(key, data);
			return true;
		}
		else
		{
			bool insertHappened = root->insert(key, data);
			return insertHappened;
		}
	}


	TNode<K, E>* search(K key) {
		TNode<K, E>* toBeFound = root;
		TNode<K, E>* parent = nullptr;
		bool found = false;

		//As long as found is false and as long as the current node is not a nullptr, repeat this while loop
		while (!found && toBeFound != nullptr)
		{
			//If the key of the current node matches the key of the passed in key, then return that node
			if (toBeFound->getKey() == key)
			{
				return toBeFound;
			}
			else
			{
				parent = toBeFound;

				//If the key of the current node is larger than the passed in key, assign the left child of that node to 'toBeFound' and go back to beginning of loop
				if (toBeFound->getKey() > key)
				{
					toBeFound = toBeFound->getpLeft();
				}
				//Otherwise, assign the right child of the current node to 'toBeFound' and go back to beginning of loop
				else
				{
					toBeFound = toBeFound->getpRight();
				}
			}
		}
		//If there is no node which has the passed in key associated with it, then we return nullptr
		return nullptr;
	}

	bool remove(K currentKey, K originalKey)
	{
		//In the first call, we pass in the originalKey and currentKey which will initially be the same key
		//As the function gets called recursively, the value of originalKey will stay the same

		TNode<K, E>* toBeRemoved = search(currentKey);
		if (toBeRemoved == nullptr) {
			return false;
		}

		//If the left child of the node that we are trying to delete is not null, then we call the remove function on that left child by passing in the left child's
		//key and also the key of the original key that we want to delete (we need to keept track of it at all times)
		if (toBeRemoved->getpLeft() != nullptr) {
			cout << "call remove left" << endl;
			remove(toBeRemoved->getpLeft()->getKey(), originalKey);
		}

		//Similarily to the left child of the node, if the right child of the node that we want to delete is not null, then we also call the remove function by passing in
		//the right child's key + the original key
		if (toBeRemoved->getpRight() != nullptr) {
			cout << "call remove right" << endl;
			remove(toBeRemoved->getpRight()->getKey(), originalKey);
		}



		//As long as the two if statements above return true, the remove function will be called recursively on the node's children. Once we reach a node that does not have
		//any children, we can safely delete that node, and then we call the remove function on the original node that we wanted to delete

		//We continue calling the the remove function on the original key as long as the node that we want to delete still has children
		//Once it has no more remaining children, then we can finally delete that node




		//If the two above if statements return false, then this statement is guaranteed to return true
		if (toBeRemoved->getpLeft() == nullptr && toBeRemoved->getpRight() == nullptr) {
			cout << "deleting: " << currentKey << endl;
			TNode<K, E>* parentNode = toBeRemoved->getParent();

			//If the node that we want to delete does not have a parent node, then we know that the node that we want to delete is the root node of the binary tree,
			//and we call the clear function to set the root node to nullptr
			if (parentNode == nullptr) {
				this->clear();
				return true;
			}

			//We check if the node that we currently want to delete is it's parent's left or right child
			//If the node that we currently want to delete is it's parent's left child, then we delete that parent node's left child and set it to nullptr
			if (parentNode->getpLeft() != nullptr && parentNode->getpLeft()->getKey() == currentKey) {
				delete parentNode->getpLeft();
				parentNode->setPLeft(nullptr);
				return true;
			}

			//If the node that we currently want to delete is it's parent's right child, then we delete that parent node's right child and set it to nullptr
			if (parentNode->getpRight() != nullptr && parentNode->getpRight()->getKey() == currentKey) {
				delete parentNode->getpRight();
				parentNode->setPRight(nullptr);
				return true;
			}

			//As long as the currentKey is not equal to the original key, or in other words, as long as the original node that we want to delete has children, we call the
			//remove function recursively. This check is just so that the function doesn't continue to delete the original nodes' parent nodes after we already deleted
			//the node that we wanted to delete
			if (currentKey != originalKey) {
				remove(originalKey, originalKey);
			}

		}

	}

	size_t depth(K key) {
		TNode<K, E>* toBeFound = root;
		TNode<K, E>* parent = nullptr;
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
		//return -1;
		throw std::out_of_range("Node doesn't exist in tree");
	}

	void getHeight(int& counter, int& max, K key)
	{
		TNode<K, E>* toBeFound = search(key);
		toBeFound->getHeight(counter, max);
	}

	
};
