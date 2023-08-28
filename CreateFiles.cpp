#include "CreateFiles.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

CreateFiles::CreateFiles()
{

}

std::string CreateFiles::MakePassword()
{
	std::srand(time(NULL) + rand());
	int randomNumber = 0;
	char c = 'a';
	std::string password = "";
	for(int i = 0; i < 9; i++)
	{
		randomNumber = rand() % 26 + 97;
		c = randomNumber;
		password += c;
	}
	return password;
}

void CreateFiles::LoadRawFile()
{
	std::ifstream in;
	in.open("lastNames.txt");
	if(!in.is_open())
	{
		std::cout << "File Not Found" << std::endl;
	}
	else
	{
		std::ofstream out;
		out.open("raw.txt");

		std::string line;
		std::string id = "";
		std::string password = "";
		while(getline(in,line))
		{
			for(unsigned int i = 0; i < line.length(); i++)
			{
				if(line[i] == ' ')
				{
					id = line.substr(0,i);
					password = this->MakePassword();
					out << id << " " << password << std::endl;
					break;
				}
			}
		}
		in.close();
		out.close();
	}
}

std::string CreateFiles::MakeEncryptedPassword(std::string plaintext,std::string key)
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

void CreateFiles::LoadEncryptedFile()
{
	std::ifstream in;
	in.open("raw.txt");
	if(!in.is_open())
	{
		std::cout << "File Not Found" << std::endl;
	}
	else
	{
		std::ofstream out;
		out.open("encrypted.txt");
		std::string line;
		std::string id = "";
		std::string password = "";
		while(!in.eof())
		{
			in >> id;
			in >> password;
			password = this->MakeEncryptedPassword(password,"foobarbaz");
			out << id << " " << password << std::endl;
		}
		in.close();
		out.close();
	}
}