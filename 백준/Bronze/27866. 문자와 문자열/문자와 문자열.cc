#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
	//freopen("input.txt", "r", stdin);

	string str = "";
	int N;
	cin >> str;
	cin >> N;

	cout << str[N - 1];
}