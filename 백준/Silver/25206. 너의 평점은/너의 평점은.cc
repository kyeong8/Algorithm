#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char* argv[])
{
	//freopen("input.txt", "r", stdin);

	string temp;
	string* str = new string[20];
	float arr[20];
	float total = 0;
	float grade = 0;
	map<string, float> m;
	
	m.insert({ "A+", 4.5 });
	m.insert({ "A0", 4.0 });
	m.insert({ "B+", 3.5 });
	m.insert({ "B0", 3.0 });
	m.insert({ "C+", 2.5 });
	m.insert({ "C0", 2.0 });
	m.insert({ "D+", 1.5 });
	m.insert({ "D0", 1.0 });
	m.insert({ "F", 0.0 });



	for (int i = 0; i < 20; i++)
	{
		cin >> temp >> arr[i] >> str[i];
		if (str[i] != "P")
		{
			total += arr[i] * m[str[i]];
			grade += arr[i];
		}
	}

	cout << fixed;
	cout.precision(6);
	cout << total / grade;
}