#ifndef CREATEFILES_HPP_
#define CREATEFILES_HPP_

#include <iostream>

class CreateFiles
{
	private:
		std::string MakePassword();
		std::string MakeEncryptedPassword(std::string plaintext,std::string key);
	public:
		CreateFiles();
		void LoadRawFile();
		void LoadEncryptedFile();
};

#endif // CREATEFILES_HPP_