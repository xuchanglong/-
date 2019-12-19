//test.cpp
#include "src/iostream"
#include "src/string"

using namespace std;

int main(int argc, char *argv[])
{
	string *msg = new string("this is my c++ test message!");
	cout << *msg << endl;
	delete msg;
	return 0;
}