#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Sed {
private:
  std::string _inputFile;
  std::string _outputFile;

public:
  Sed(std::string file);
  ~Sed();

  void replace(std::string s1, std::string s2);
};

#endif
