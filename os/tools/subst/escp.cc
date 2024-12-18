#include <iostream>

using std::cout;
using std::endl;

int main() {
	cout << R"([^\]"[^"]*%[^"]*[^\]")" << std::endl;
    return 0;
}


