#include "HashTable.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

HashTable::HashTable()
{
	this->size = 88801;
	this->table = new SinglyLinkedList[this->size];
}

HashTable::~HashTable()
{
	for(int i = 0; i < this->size; i++)
	{
		this->table[i].DeleteList();
	}
	delete this->table;
}

unsigned int HashTable::GetHash(std::string key)
{
	unsigned int hash = 5381;
	unsigned int keySize = key.length();
	for(unsigned int i = 0; i < keySize; i++)
	{
		hash = ((hash << 5) + hash) + key[i];
	}
	return hash % this->size;
}

void HashTable::LoadHashTable()
{
	std::ifstream in;
	std::string userId = "";
	std::string encryptedPassword = "";
	in.open("encrypted.txt");
	if(!in.is_open())
	{
		std::cout << "File Not Found" << std::endl;
	}
	else
	{
		int bucketNum = 0;
		int index = 1;
		while(!in.eof())
		{
			in >> userId;
			in >> encryptedPassword;
			bucketNum = this->GetHash(userId);
			this->table[bucketNum].Prepend(userId,encryptedPassword);
			++index;
		}
		in.close();
	}
}

std::string HashTable::GetMatch(std::string userId,std::string password)
{
	int i = this->GetHash(userId);
	UserNode* thisUser = this->table[i].Search(userId);

	if(thisUser == nullptr)
	{
		return "no match";
	}
	if(thisUser->GetPassword() != password)
	{
		return "no match";
	}
	else
	{
		return "match";
	}

	return "no match";
}

