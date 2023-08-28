#ifndef USER_HPP_
#define USER_HPP_

#include <iostream>

class UserNode
{
	private:
		UserNode* nextUser;
		std::string id;
		std::string password;
	public:
		UserNode(std::string id,std::string password);
		UserNode* GetNext();
		void SetNext(UserNode* nextUser);
		std::string GetId();
		std::string GetPassword();
};

#endif // USER_HPP_