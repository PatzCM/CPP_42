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
	std::ifstream inputFile (_inputFile.c_str());
	std::string input;

	if (inputFile.is_open() == false || inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: Input file is not valid or empty." << std::endl;
		return;
	}
	if (inputFile.is_open())
	{
		std::ofstream outputFile(_outputFile.c_str());
		while (getline(inputFile, input))
		{
			size_t pos = input.find(s1, 0);
			{
				while (pos != std::string::npos)
				{
					input.erase(pos, s1.length());
					outputFile << s2 << " ";
					pos = input.find(s1);
				}
				outputFile << input << std::endl;
			}
		}
		inputFile.close();
		outputFile.close();
	}
}

