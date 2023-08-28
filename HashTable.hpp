#ifndef HASHTABLE_HPP_
#define HASHTABLE_HPP_

#include <iostream>
#include "SinglyLinkedList.hpp"

class HashTable
{
	private:
		int size;
		SinglyLinkedList* table;
		unsigned int GetHash(std::string key);
	public:
		HashTable();
		~HashTable();
		void LoadHashTable();
		std::string GetMatch(std::string userId,std::string password);
};

#endif // HASHTABLE_HPP_