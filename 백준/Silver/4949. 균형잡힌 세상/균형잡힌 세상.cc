#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str;
	vector<char> v;
	bool flag;

	while (true)
	{
		flag = true;
		getline(cin, str);
		if (str[0] == '.')
			break;

		for (auto i : str)
		{
			if (i == '(')
				v.push_back(i);
			else if (i == '[')
				v.push_back(i);
			else if (i == ')')
			{
				if (v.back() != '(')
				{
					flag = false;
					break;
				}
				else
					v.pop_back();
			}
			else if (i == ']')
			{
				if (v.back() != '[')
				{
					flag = false;
					break;
				}
				else
					v.pop_back();
			}
		}
		if (flag && v.empty())
			cout << "yes" << "\n";
		else
		{
			cout << "no" << "\n";
			v.clear();
		}	
	}
}