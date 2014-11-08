#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	string stringValues = "I love you";
	istringstream iss(stringValues);
	string tmp;
	string out;
	string s;
	while (iss >> tmp) {
		tmp += " ";
		std::cout << tmp << std::endl;
		tmp += out;
		out = tmp;
	}
	s = out.substr(0, out.length() - 1);
	std::cout << "  " << s << std::endl;
	return 0;
}
