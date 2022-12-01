#pragma once

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
	TNode* pLeft, * pRight;

public:
	TNode() {     // Constructor
		cout << "Hello World!";
	}
	// This inserts the key and the data into the node, making it sort of a staggered constructor
	bool insert(K key, E data) {
		return false;
		// Google if pointers need to be initialised explicitly as nullptrs or if this automatically
		// happends when they are not assigned an L value
	}

	void setData(E data) { this->data = data; } // if the key and the data are tied at the hip, shouldn't there also be a getter/setter for key, and why not re-use insert()???
	E getData() const { return this->data; }
};
