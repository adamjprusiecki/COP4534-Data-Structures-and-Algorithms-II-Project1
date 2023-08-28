#ifndef SINGLYLINKEDLIST_HPP_
#define SINGLYLINKEDLIST_HPP_

#include <iostream>
#include "UserNode.hpp"

class SinglyLinkedList
{
	private:
		UserNode* head;
		UserNode* CreateUserNode(std::string userId,std::string encryptedPassword);
	public:
		SinglyLinkedList();
		void LoadList();
		void Prepend(std::string userId,std::string encryptedPassword);
		UserNode* Search(std::string userId);
		void DeleteList();
};

#endif // SINGLYLINKEDLIST_HPP_