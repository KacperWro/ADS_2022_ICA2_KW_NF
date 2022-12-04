#pragma once
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
	TNode* pLeft, * pRight;

public:
	TNode() {     // Constructor
		cout << "Hello World!";
	}

	bool insert(K key, E data) {
		return false;
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }

	std::size_t hash() const
	{
		size_t hash = std::hash<string>()(this->key.getUser_id())
			+ 101 * std::hash<string>()(this->key.getFirst_name())
			+ 149 * std::hash<string>()(this->key.getEmail());
		return hash;
	}
};
