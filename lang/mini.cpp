#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

class Scanner {
  public:
  
}

class ErrorReporter {
public:
  void report(std::string type, std::string message) {
    std::cout << "[" << type << "] " << message << "\n";
  }
  void reportError(int line, std::string message) {
    this->report("error", message + " on line " + std::to_string(line));
  }
};

class MiniLang {
public:
  ErrorReporter reporter;
  int runFromSource(std::string &source) { return 0; }
};

int main() {
  std::cin >> std::noskipws;
  std::istream_iterator<char> it(std::cin);
  std::istream_iterator<char> end;
  std::string source(it, end);
  MiniLang mini;
  return mini.runFromSource(source);
}