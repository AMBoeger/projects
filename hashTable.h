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

struct Record {
	Record(int key, std::string value);
	int key;
	std::string value;
};

class hashTable {
private:

	 // helper search fn
	int hash(Record*); // hash value for record
	int hash(int); // hash value for key  
	const int size; // size of table
	std::vector<std::list<Record>> Table; // array of lists that hold records

public:
	
	hashTable();
	hashTable(int size); // build a table
	void insert(Record*); // insert copy of record
	void deleteValue(int); // delete a record
	Record* find(int);
	Record* search(int); // return pointer to a copy of found node, or 0
	void clear();
	int getSize(){return size;}

};

