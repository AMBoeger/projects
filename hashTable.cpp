/**
 * Full Name: Andrew Boeger
 * Pengo Account: aboeger@pengo.cabrillo.edu
 * Email: andrew.boeger@gmail.com
 * File: hashTable.cpp
 * Assignment 5 (Create Hashtable)
*/
#include "hashTable.h"

hashTable::hashTable() : size(100) 
{
	for (unsigned i = 0; i < size - 1; i++) {
		std::list<Record> List;
		Table.push_back(List);
	}
}

hashTable::hashTable(int tableSize) : size(tableSize)
{
	for (unsigned i = 0; i < size - 1; i++) {
		std::list<Record> List;
		Table.push_back(List);
	}
}
void hashTable::insert(Record* record)
{
	Table[hash(record->key)].push_back(*record);
}
void hashTable::deleteValue(int key)
{
	if (Table[hash(key)].size() == 0) { return; }
	Record* Target = find(key);
	if (Target != nullptr) {
		//delete Target;
	}
	return;
}
Record* hashTable::search(int key)
{	
	int index = hash(key);
	return 0;
}
void hashTable::clear() {
	for (unsigned i = 0; i < size - 1; i++){
		Table[i].clear();
	}
}
Record* hashTable::find(int key) {
	std::list<Record>* MyList = &Table[hash(key)];
	if(MyList->size() > 0) {
		for(std::list<Record>::iterator it = MyList->begin(); it != MyList->end(); it++)
			if (it->key == key) { return &(*it); }
	}
	return nullptr;
}
int hashTable::hash(Record* record) 
{
	int hashKey = (int) floor(size * (record->key * 0.618034 - floor(record->key * 0.618034)));
	return hashKey;
} 
int hashTable::hash(int k)
{
	int hashKey = (int) floor(size * (k * 0.618034 - floor(k * 0.618034)));
	return hashKey;
}

Record::Record(int a, std::string b) {
	key = a;
	value = b;
}
