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

	~TNode() { 
		cout << "Destructor called" << endl;
		delete this->pLeft; 
		delete this->pRight;
		delete this->parent;
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


	bool insert(K key, E data) {
		
		if (key == this->key)
		{
			//cout << "id is the same" << endl;
			return false;
		}
		else if (key < this->key)
		{
			//cout << "else if statement" << endl;
			if (pLeft == nullptr)
			{
				pLeft = new TNode<K, E>(key, data);
				pLeft->parent = this;
				//cout << "inserted into left child" << endl;
				return true;
			}
			else
			{
				//cout << "left child is not null" << endl;
				pLeft->insert(key, data);
			}

			return true;
		}
		else
		{
			//cout << "else statement" << endl;
			if (pRight == nullptr)
			{
				pRight = new TNode<K, E>(key, data);
				pRight->parent = this;
				//cout << "inserted into right child" << endl;
				return true;
			}
			else
			{
				//cout << "right child is not null" << endl;
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

	void printNode() {
		Student student = this->getData();

		cout << "*******************************************************" << endl;
		cout << "User ID            : " << student.getUser_id() << endl;
		cout << "Current Ranking    : " << student.getCurrent_ranking() << endl;
		cout << "First Name         : " << student.getFirst_name() << endl;
		cout << "Surname            : " << student.getSurname() << endl;
		cout << "Gender             : " << student.getGender() << endl;
		cout << "Date of Birth      : " << student.getDate_of_birth() << endl;
		cout << "Email              : " << student.getEmail() << endl;
		cout << "Phone Number       : " << student.getPhone() << endl;
		cout << "Postcode           : " << student.getPostcode() << endl;
		cout << "Country            : " << student.getCountry() << endl;
		cout << "Date last logged on: " << student.getLast_log_on_date() << endl;
		cout << "Time last logged on: " << student.getLast_log_on_time() << endl;
		cout << "Date joined on     : " << student.getJoined_on() << endl;
		cout << "Account Credit     : " << student.getAccount_credit() << endl;
		cout << "*******************************************************" << endl;
	}


	/*std::size_t hash() const
	{
		size_t hash = std::hash<string>()(this->key.getUser_id())
			+ 101 * std::hash<string>()(this->key.getFirst_name())
			+ 149 * std::hash<string>()(this->key.getEmail());
		return hash;
	}*/
};
