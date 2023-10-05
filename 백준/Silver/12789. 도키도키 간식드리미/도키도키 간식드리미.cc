#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> space;
	deque<int> line;

	int order = 1;
	int num;
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> num;
		space.push_back(num);
	}

	space.push_back(0);
	line.push_back(0);

	while (space.front() != 0)
	{
		//cout << "space.front(): " << space.front() << " line.back(): " << line.back() << " order: " << order << "\n";

		if (space.front() == order)
		{
			space.pop_front();
			++order;
		}
		else if (line.back() == order)
		{
			line.pop_back();
			++order;
		}	
		else
		{
			line.push_back(space.front());
			space.pop_front();
		}
	}

	while (line.back() != 0)
	{
		if (line.back() != order)
		{
			cout << "Sad" << "\n";
			break;
		}
		else
		{
			line.pop_back();
			++order;
		}
	}

	if (space.front() == 0 && line.back() == 0)
		cout << "Nice" << "\n";
}
