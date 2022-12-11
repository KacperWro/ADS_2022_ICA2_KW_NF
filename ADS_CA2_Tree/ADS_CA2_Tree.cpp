// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "TNode.h"
#include "Date.h"
#include "Utilities.h"
#include "StudentKey.h"
#include "Student.h"
#include "BinaryTree.h"
#include "TNode.h"
#include "Benchmark.h"
using namespace std;

void demoBenchmarkVectorFindLast();
void demoBenchmarkTreeFindNode();
void demoBenchmarkTreeDeleteNode();
void demoBenchmarkVectorDeleteLast();
void demoBenchmarkVectorinsert();
void demoBenchmarkTreeinsert();
int main()
{
	cout << "----------------------------- VECTOR BENCHMARKS ----------------------------- " << endl;

	cout << endl << "demoBenchmarkVectorFindLast()..........." << endl;
	demoBenchmarkVectorFindLast();
	cout << endl << "demoBenchmarkVectorDeleteLast()..........." << endl;
	demoBenchmarkVectorDeleteLast();
	cout << endl << "demoBenchmarkVectorinsert()..........." << endl;
	demoBenchmarkVectorinsert();


	cout << endl << "----------------------------- TREE BENCHMARKS ----------------------------- " << endl;

	cout << endl << "demoBenchmarkTreeFindNode()..........." << endl;
	demoBenchmarkTreeFindNode();
	cout << endl << "demoBenchmarkTreeDeleteNode()..........." << endl;
	demoBenchmarkTreeDeleteNode();
	cout << endl << "demoBenchmarkTreeinsert()..........." << endl;
	demoBenchmarkTreeinsert();


	return 0;

}

/*********************************** Benchmarking ***********************************/

/// <summary>
/// Search for a T in a vector of T objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename T, typename V>
int linearSearch(vector<T> data, V value)
{
	for (int i = 0; i < data.size(); i++)
		if (data[i].getUser_id() == value) return i;
	return -1;
}

/// <summary>
/// A functor that we make to test the linearSearch in a vector - we need a functor because that's what measureTime takes!
/// </summary>
class LinearStringSearchFunctor {
	vector<Student> data;
	string target;
public:
	LinearStringSearchFunctor(vector<Student> data, string target) : data(data), target(target) {};

	int operator()() {
		return linearSearch(data, target);
	}
};



/// <summary>
/// Search for a T in a vector of T objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename T, typename V>
int linearDelete(vector<T> data, V value)
{
	for (int i = 0; i < data.size(); i++)
		if (data[i].getUser_id() == value) {
			data.erase(i);
			return i;
		}
	return -1;
}

/// <summary>
/// A functor that we make to test the linearSearch in a vector - we need a functor because that's what measureTime takes!
/// </summary>
class LinearDeleteFunctor {
	vector<Student> data;
	string target;
public:
	LinearDeleteFunctor(vector<Student> data, string target) : data(data), target(target) {};

	int operator()() {
		return linearSearch(data, target);
	}
};


/// <summary>
/// Search for a T in a vector of T objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename T, typename V>
int linearInsert(vector<T> data, V value)
{
	data.push_back(value);
			return 1;
}

/// <summary>
/// A functor that we make to test the linearSearch in a vector - we need a functor because that's what measureTime takes!
/// </summary>
class LinearInsertFunctor {
	vector<Student> data;
	Student target;
public:
	LinearInsertFunctor(vector<Student> data, Student target) : data(data), target(target) {};

	int operator()() {
		return linearInsert(data, target);
	}
};


/// <summary>
/// Search for a size_t hash in a tree of student objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename K, typename E>
int treeSearch(BinaryTree<K, E> data, size_t value)
{
	//for (int i = 0; i < data.size(); i++)
	//	if (data[i] == value) return i;
	//return -1;

	TNode<size_t, Student>* searchedNode = data.search(value);
		if (searchedNode != nullptr) return 1001;
	return -1;

}

/// <summary>
/// A functor that we make to test the search in a binary search tree
/// </summary>
class TreeSearchFunctor {
	BinaryTree<size_t, Student> data;
	size_t target;
public:
	TreeSearchFunctor(BinaryTree<size_t, Student> data, size_t target) : data(data), target(target) {};

	int operator()() {
		return treeSearch(data, target);
	}
};



/// <summary>
/// Search for a size_t hash in a tree of student objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename K, typename E>
int treeDelete(BinaryTree<K, E> data, size_t value)
{
	//for (int i = 0; i < data.size(); i++)
	//	if (data[i] == value) return i;
	//return -1;

	bool deleted_from_tree = data.remove(value, value);
	if (deleted_from_tree) return 1001;
	return -1;

}

/// <summary>
/// A functor that we make to test the search in a binary search tree
/// </summary>
class TreeDeleteFunctor {
	BinaryTree<size_t, Student> data;
	size_t target;
public:
	TreeDeleteFunctor(BinaryTree<size_t, Student> data, size_t target) : data(data), target(target) {};

	int operator()() {
		return treeDelete(data, target);
	}
};



/// <summary>
/// Search for a size_t hash in a tree of student objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
template <typename K, typename E, typename X>
int treeInsert(BinaryTree<K, E> data, E value, X robbysHash)
{
	//for (int i = 0; i < data.size(); i++)
	//	if (data[i] == value) return i;
	//return -1;

	data.insert(robbysHash, value);
		return 1;
	

}

/// <summary>
/// A functor that we make to test the search in a binary search tree
/// </summary>
class TreeInsertFunctor
{
	BinaryTree<size_t, Student> data;
	Student robby;
	size_t robbysHash;
public:
	TreeInsertFunctor(BinaryTree<size_t, Student> data, Student robby, size_t robbysHash) : data(data), robby(robby), robbysHash(robbysHash) {};

	int operator()() {
		return treeInsert(data, robby, robbysHash);
	}
};



BinaryTree<size_t, Student> loadDataFromCsv(int N)
{
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//OneDrive - Dundalk Institute of Technology//Algs + Data//data_1000.csv");
	//vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

	BinaryTree<size_t, Student> newTree;

	for (int i = 1; i < N; i++) {
		string timeDelimiter = ":";

		//DATE OF BIRTH
		Date dateOfBirth(delimitedRows[i][5]);

		//LAST LOG ON DATE
		Date lastLogOnDate(delimitedRows[i][10]);

		//LAST LOG ON TIME
		string logOnTime = delimitedRows[i][11];
		unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
		logOnTime = logOnTime.substr(3);
		unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));

		TimeHHMM lastLogOnTime(hours, minutes);

		//JOINED ON
		Date joinedOn(delimitedRows[i][12]);

		Student newStudent(delimitedRows[i][0], stoi(delimitedRows[i][1]), delimitedRows[i][2], delimitedRows[i][3], delimitedRows[i][4], dateOfBirth,
			delimitedRows[i][6], delimitedRows[i][7], delimitedRows[i][8], delimitedRows[i][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[i][13]);

		StudentKey newKey(newStudent.getUser_id(), newStudent.getFirst_name(), newStudent.getEmail());
		//TNode<StudentKey, Student> newNode(newKey, newStudent);
		newTree.insert(newKey.getHash(), newStudent);
		//cout << newKey.getHash() << endl;

	}

	return newTree;
}

/*vector<string> loadData(int N)
{
	vector<string> data;

	//load data (e.g., random strings) into a vector (this is like your tree or linked list)
	int stringLength = 4;

	for (int i = 0; i < N; i++)
		data.push_back(getRandomString(stringLength));

	return data;
}*/


vector<Student> loadData(int N)
{
	//vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//OneDrive - Dundalk Institute of Technology//Algs + Data//data_1000.csv");
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

	vector<Student> data;

	for (int i = 1; i < N; i++) {
		string timeDelimiter = ":";

		//DATE OF BIRTH
		Date dateOfBirth(delimitedRows[i][5]);
		
		//LAST LOG ON DATE
		Date lastLogOnDate(delimitedRows[i][10]);
		

		//LAST LOG ON TIME
		string logOnTime = delimitedRows[i][11];
		unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
		logOnTime = logOnTime.substr(3);
		unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
		

		TimeHHMM lastLogOnTime(hours, minutes);
		


		//JOINED ON
		Date joinedOn(delimitedRows[i][12]);
		

		Student newStudent(delimitedRows[i][0], stoi(delimitedRows[i][1]), delimitedRows[i][2], delimitedRows[i][3], delimitedRows[i][4], dateOfBirth,
			delimitedRows[i][6], delimitedRows[i][7], delimitedRows[i][8], delimitedRows[i][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[i][13]);
		

		data.push_back(newStudent);
		
		
	}
		

	return data;
}


//lets benchmark how long it takes to find the last string in a vector
//we should repeat the test below and run multiple tests on finding last string in a vector and get average run time
void demoBenchmarkTreeFindNode() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;

	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	BinaryTree<size_t, Student> data = loadDataFromCsv(N);

	// get key of the last inserted node 
	StudentKey newKey("EPA78CWQ7FF", "Rhonda", "ut@icloud.net");

	size_t hash_to_search = newKey.getHash();


	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		TreeSearchFunctor searchFunc(data, hash_to_search);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(searchFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Binary Search Tree - Average last element search time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}



//lets benchmark how long it takes to find the last string in a vector
//we should repeat the test below and run multiple tests on finding last string in a vector and get average run time
void demoBenchmarkTreeDeleteNode() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;

	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	BinaryTree<size_t, Student> data = loadDataFromCsv(N);

	// get key of the last inserted node 
	StudentKey newKey("EPA78CWQ7FF", "Rhonda", "ut@icloud.net");

	size_t hash_to_search = newKey.getHash();


	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		TreeDeleteFunctor searchFunc(data, hash_to_search);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(searchFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Binary Search Tree - Average last element find and delete Time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}


void demoBenchmarkTreeinsert() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;


	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	BinaryTree<size_t, Student> data = loadDataFromCsv(N);

	string timeDelimiter = ":";
	//DATE OF BIRTH
	Date dateOfBirth("13/12/1990");
	//LAST LOG ON DATE
	Date lastLogOnDate("10/12/2022");
	//LAST LOG ON TIME
	string logOnTime = "17:31";
	unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
	logOnTime = logOnTime.substr(3);
	unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));

	TimeHHMM lastLogOnTime(hours, minutes);
	//JOINED ON
	Date joinedOn("06/10/2021");
	Student robbyStudent("rayjhugbvlkle", 33, "Robby", "McDonall", "Male", dateOfBirth,
		"Robby@gmail.com", "0853345780", "aerluiyhg", "Ireland", lastLogOnDate, lastLogOnTime, joinedOn, "$559.56");

	StudentKey robbyKey("rayjhugbvlkle", "Robby", "Robby@gmail.com");

	size_t robbysHash = robbyKey.getHash();




	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		TreeInsertFunctor insertFunc(data, robbyStudent, robbysHash);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(insertFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Binary Search Tree - Average Insert Time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;


}



//lets benchmark how long it takes to find a specified node in the tree
void demoBenchmarkVectorFindLast() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;

	

	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	vector<Student> data = loadData(N);
	

	//pick the last string in the structure
	//string searchString = data[data.size() - 1];

	//string name = data[data.size() - 2].getFirst_name();
	string id = "EPA78CWQ7FF";

	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		LinearStringSearchFunctor searchFunc(data, id);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(searchFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Vector - Average last element search time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}

//lets benchmark how long it takes to find a specified node in the tree
void demoBenchmarkVectorDeleteLast() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;


	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	vector<Student> data = loadData(N);


	//pick the last string in the structure
	//string searchString = data[data.size() - 1];

	//string name = data[data.size() - 2].getFirst_name();
	string id = "EPA78CWQ7FF";

	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		LinearDeleteFunctor searchFunc(data, id);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(searchFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Vector - Average Find and Delete time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}

//lets benchmark how long it takes to find a specified node in the tree
void demoBenchmarkVectorinsert() {
	//number of strings in the vector (like your CSV where N=1000,10000,100000)
	int N = 1001;


	//get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
	vector<Student> data = loadData(N);

	string timeDelimiter = ":";
	//DATE OF BIRTH
	Date dateOfBirth("13/12/1990");
	//LAST LOG ON DATE
	Date lastLogOnDate("10/12/2022");
	//LAST LOG ON TIME
	string logOnTime = "17:31";
	unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
	logOnTime = logOnTime.substr(3);
	unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));

	TimeHHMM lastLogOnTime(hours, minutes);
	//JOINED ON
	Date joinedOn("06/10/2021");
	Student robbyStudent("rayjhugbvlkle", 33, "Robby", "McDonall", "Male", dateOfBirth,
		"Robby@gmail.com", "0853345780", "aerluiyhg", "Ireland", lastLogOnDate, lastLogOnTime, joinedOn, "$559.56");






	/******************************* IMPORTANT PART > *******************************/
	int numberOfTests = 100;
	double totalTestTimeInNS = 0;
	for (int i = 0; i < numberOfTests; i++)
	{
		//make up the functor
		LinearInsertFunctor insertFunc(data, robbyStudent);

		//pass the functor into measureTime
		totalTestTimeInNS += measureTime(insertFunc);
	}

	//get average across all tests
	double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

	//convert ns to ms
	averageSearchTimeInMS /= 1000;

	//see how long it takes to find the string
	cout << "Vector - Average Insert Time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

	/******************************* < IMPORTANT PART *******************************/
}



