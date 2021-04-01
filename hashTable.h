/**
 * Full Name: Andrew Boeger
 * Pengo Account: aboeger@pengo.cabrillo.edu
 * Email: andrew.boeger@gmail.com
 * File: hashTable.h
 * Assignment 5 (Create Hashtable)
*/

#include <vector>
#include <string>
#include <cmath>
#include <list>
#include <iostream>

struct Record {
	Record(int key, std::string value);
	Record* Copy(const Record);
	int key;
	std::string value;
};

class hashTable {
private:
	int hash(Record*); // hash value for record
	int hash(int); // hash value for key  
	const int size; // size of table
	Record* find(int); // helper search fn
	std::vector<std::list<Record>> Table; // array of lists that hold records

public:
	hashTable();
	hashTable(int size); // build a table
	~hashTable();
	Record* copyRec(Record*);
	void insert(int, std::string); // insert copy of record
	bool deleteValue(int); // delete a record
	Record* search(int); // return pointer to a copy of found node, or 0
	void clear();
	int getSize(){return size;}

};

