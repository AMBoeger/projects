/**
 * Full Name: Andrew Boeger
 * Pengo Account: aboeger@pengo.cabrillo.edu
 * Email: andrew.boeger@gmail.com
 * File: main.cpp
 * Assignment 5 (Create Hashtable)
*/


/**
 * Purpose: Practice implementing a Hashtable
 * Status: Unfinished
 * Compile: No
 */

#include "hashTable.h"
#include <iostream>

int main()
{
    hashTable MyTable(178000);
    int choice = 0;
    int key = 0;
    
    while (choice != 7) {
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
        std::cin >> choice;

        if (choice == 1){
    }
        else if (choice == 2){
            std::cout << "input new record: ";
            std::string value;
            std::cin >> key >> std::ws;
            std::getline(std::cin, value);
            Record* MyRec = new Record(key, value);
            MyTable.insert(MyRec);
        }
        else if (choice == 3) {
            std::cout << "delete record - key? ";
            std::cin >> key;
            Record* Test = MyTable.find(key);
            if (Test == nullptr) {
                std::cout << "Delete not found: " << key << std::endl;
            }
            else {
                std::cout << "Delete: " << key << " " << Test->value << std::endl;
                MyTable.deleteValue(key);
            }
           
        }
        else if (choice == 4) {
            std::cout << "search for record - key? ";
            std::cin >> key;
            Record* Test = MyTable.find(key);
            if(Test == nullptr) {
                std::cout << "Search not found: " << key << std::endl;
            }
            else {
                std::cout << "Found: " << key << " " << Test->value << std::endl;
            }
        }
        else if (choice == 5) {
            std::cout << "clearing hash table." << std::endl;
            MyTable.clear();
        }
        else if (choice == 6) {
        }
    }
    return 0;
}

