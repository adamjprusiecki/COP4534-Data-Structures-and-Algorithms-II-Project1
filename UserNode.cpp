#include "UserNode.hpp"

UserNode::UserNode(std::string id,std::string password)
{
	this->id = id;
	this->password = password;
}

UserNode* UserNode::GetNext()
{
	return this->nextUser;
}

void UserNode::SetNext(UserNode* nextUser)
{
	this->nextUser = nextUser;
}

std::string UserNode::GetId()
{
	return this->id;
}

std::string UserNode::GetPassword()
{
	return this->password;
}