#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "CreateFiles.hpp"
#include "HashTable.hpp"

class Driver
{
	private:
		CreateFiles cf;
		HashTable ht;
		std::string ids[5];
		std::string passwords[5];
		std::string GetEncryptedPassword(std::string plaintext,std::string key);
		void LoadObjects();
		void PopulateLegalCredentials();
		void PrintLegalOutput();
		void PrintIllegalOutput();
	public:
		Driver();
		void Run();
};

#endif //DRIVER_HPP