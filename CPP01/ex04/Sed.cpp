#include "Sed.hpp"

Sed::Sed(std::string file)
{
	this-> _inputFile = file;
	this->_outputFile = file + ".replace";
}

Sed::~Sed()
{

}

void Sed::replace(std::string s1, std::string s2)
{
	std::ifstream inputFile(_inputFile);
	std::ofstream outputFile(_outputFile);
	std::string input;

	if (inputFile.is_open() && outputFile.is_open())
	{
		while (getline(inputFile, input))
		{
			size_t pos = input.find(s1, 0);
			{
				while (pos != std::string::npos)
				{
					input.erase(pos, s1.length());
					input.insert(pos, s2);

				}
			}
		}
	}
}

