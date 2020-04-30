#include <iostream>
using namespace std;

union {
	int i;
	char c;
} status;

int main(int argc,char* argv[])
{
	status.i = 0x12345678;
	if (status.c == 0x12) cout << "big bian" << endl;
	else if (status.c == 0x78) cout << "little bian" << endl;
	else cout << "error" << endl;
	return 0;
 } 
