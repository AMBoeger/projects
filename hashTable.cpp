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
	for (int i = 0; i < size - 1; i++) {
		Table.emplace_back(std::list<Record>());
	}
}
hashTable::hashTable(int tableSize) : size(tableSize)
{
	for (int i = 0; i < size - 1; i++) {
		Table.emplace_back(std::list<Record>());
	}
}
hashTable::~hashTable(){	
}
Record* hashTable::copyRec(Record* Rec){
	auto newRec = new Record(Rec->key, Rec->value);
	return newRec;
}
void hashTable::insert(int key, std::string value)
{
	Record* newRecord = new Record(key, value);
	Table[hash(key)].push_back(*newRecord);
}
bool hashTable::deleteValue(int key)
{
	Record* Target = find(key);
	if (Target != nullptr) {
		return true;
	}
	return false;
}
Record* hashTable::search(int key)
{	
	Record* found = find(key);
	if(found == nullptr){return 0;}
	return copyRec(found);
}
void hashTable::clear() 
{
	for (int i = 0; i < size - 1; i++){
		for(std::list<Record>::iterator it = Table[i].begin(); it != Table[i].end(); it++){
			delete &*it;
		}
	}
}
Record* hashTable::find(int key) {
	std::list<Record>* MyList = &Table[hash(key)];
		for(auto it = MyList->begin(); it != MyList->end(); it++){
			if (it->key == key) {
				std::cout << it->key << it->value;
				return &*it; }
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



