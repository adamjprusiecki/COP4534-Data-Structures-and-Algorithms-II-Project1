#include "Driver.hpp"

#include <iostream>
#include <fstream>

Driver::Driver()
{
	
}

void Driver::Run()
{
	this->LoadObjects();
	this->PopulateLegalCredentials();
	this->PrintLegalOutput();
	std::cout << std::endl;
	this->PrintIllegalOutput();
}

void Driver::LoadObjects()
{
	this->cf.LoadRawFile();
	this->cf.LoadEncryptedFile();
	this->ht.LoadHashTable();
}

void Driver::PopulateLegalCredentials()
{
	std::ifstream in;
	in.open("raw.txt");
	if(!in.is_open())
	{
		std::cout << "File Not Found" << std::endl;
	}
	else
	{
		for(int i = 0; i < 5; i++)
		{
			in >> this->ids[i];
			in >> this->passwords[i];
		}
		in.close();
	}
}

void Driver::PrintLegalOutput()
{
		std::string formatedUserString = "";
		std::string encryptedPassword = "";

		std::cout << "Legal:"   << std::endl;
		std::cout << "Userid       " << "Password   " << "Result" << std::endl;

		for(int i = 0; i < 5; i++)
		{
			formatedUserString = this->ids[i];
			formatedUserString.append(12 - formatedUserString.length(), ' ');
			encryptedPassword = this->GetEncryptedPassword(passwords[i],"foobarbaz");

			std::cout << formatedUserString 
			<< " " << passwords[i] << "  " 
			<< this->ht.GetMatch(ids[i],encryptedPassword) << std::endl;
		}
}

void Driver::PrintIllegalOutput()
{
	std::string formatedUserString = "";
	std::string encryptedPassword = "";
	std::string illegalPassword = "";

	std::cout << "Illegal:"   << std::endl;
	std::cout << "Userid       " << "Password   " << "Result" << std::endl;

	for(int i = 0; i < 5; i++)
	{
		formatedUserString = ids[i];
		formatedUserString.append(12 - formatedUserString.length(), ' ');
		illegalPassword = passwords[i];
		if(illegalPassword[0] == 'x')
		{
			illegalPassword[0] = 'y';
		}
		else
		{
			illegalPassword[0] = 'x';
		}
		encryptedPassword = this->GetEncryptedPassword(illegalPassword,"foobarbaz");
	
		std::cout << formatedUserString 
		<< " " << illegalPassword << "  " 
		<< ht.GetMatch(ids[i],encryptedPassword) << std::endl;
	}
}

std::string Driver::GetEncryptedPassword(std::string plaintext,std::string key)
{
	int diff = 0;
	int c = 0;
	std::string encryptedPassword = "";
	for(int i = 0; i < 9; i++)
	{
		diff = plaintext[i] - 97;
		if(diff == 0)
		{
			encryptedPassword += key[i];
			continue;
		}
		if(diff < 97)
		{
			c = key[i] + diff;
			if(c > 122)
			{
				c -= 26;
				encryptedPassword += c;
				continue;
			}
			encryptedPassword += c;
			continue;
		}
	}
	return encryptedPassword;
}