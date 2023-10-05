#include <iostream>

using namespace std;

int main()
{
	int first, second;

	while (true)
	{
		bool flag = false;
		cin >> first >> second;
		if (!first && !second)
			return 0;

		if (second % first == 0)
		{
			cout << "factor" << "\n";
			flag = true;
		}
			
		else if (first % second == 0)
		{
			cout << "multiple" << "\n";
			flag = true;
		}

		if (!flag)
			cout << "neither" << "\n";
	}
}