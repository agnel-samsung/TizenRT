//  boost regex tester

#include <iostream>
#include <string>

#include <boost/regex.hpp>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

bool get_string(std::string& input) {
    cout << "> ";
    return static_cast<bool>(std::getline(std::cin, input));
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "insufficient args" << endl;
    return 1;
  }

  std::string input;
  boost::regex rex(argv[1]);

  while (get_string(input)) {
    cout << input << endl;

    // std::string result;
    boost::sregex_iterator srit(input.begin(), input.end(), rex);
    boost::sregex_iterator itend;
    boost::sregex_iterator itlast;

    while (srit != itend) {
      cout << srit->str() << endl;
      srit++;
    }
  }

  return 0;

}
