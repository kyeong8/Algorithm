#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
	//freopen("input.txt", "r", stdin);

	int n = 0;
	bool flag = true;
	string str;
	cin >> str;

	while (n < str.length() / 2)
	{
		if (str[n] != str[str.length() - n - 1])
		{
			flag = false;
			break;
		}
		n++;
	}

	if (flag)
		cout << "1";
	else
		cout << "0";
}