#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	char symbol = 'a';
	for (int i = 0; i < 5; i++)
	{
		cout << ++symbol << endl;
	}

	return 0;
}