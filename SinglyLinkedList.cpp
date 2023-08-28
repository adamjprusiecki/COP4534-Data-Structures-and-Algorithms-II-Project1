#include "SinglyLinkedList.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

SinglyLinkedList::SinglyLinkedList()
{
	this->head = nullptr;
}

UserNode* SinglyLinkedList::CreateUserNode(std::string userId,std::string encryptedPassword)
{
	UserNode* newUserNode = new UserNode(userId,encryptedPassword);
	newUserNode->SetNext(nullptr);
	return newUserNode;
}

void SinglyLinkedList::Prepend(std::string userId,std::string encryptedPassword)
{
	UserNode* newUserNode = this->CreateUserNode(userId,encryptedPassword);
	if(this->head == nullptr)
	{
		head = newUserNode;
	}
	else
	{
		newUserNode->SetNext(this->head);
		this->head = newUserNode;
	}
}

UserNode* SinglyLinkedList::Search(std::string userId)
{
	for(UserNode* thisNode = this->head; thisNode != nullptr; thisNode = thisNode->GetNext())
	{
		if(thisNode->GetId() == userId)
		{
			return thisNode;
		}
	}
	return nullptr;
}

void SinglyLinkedList::LoadList()
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
		while(!in.eof())
		{
			in >> userId;
			in >> encryptedPassword;
			this->Prepend(userId,encryptedPassword);
		}
		in.close();
	}
}


void SinglyLinkedList::DeleteList()
{
	UserNode* temp = this->head;
	while(temp != nullptr)
	{
		UserNode* nextNode = temp->GetNext();
		delete temp;
		temp = nextNode;
	}
}
