#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

int nodeCnt = 0;
Node node[1000000];
int nodeSize = 0;

Node Head;
Node Tail;

Node* newNode(int data)
{
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	node[nodeCnt].prev = nullptr;
	return &node[nodeCnt++];
}

void Insert(int data)
{
	if (nodeSize == 0)
	{
		Head.prev = nullptr;
		Tail.next = nullptr;

		Node* ptr = newNode(data);
		
		ptr->next = &Tail;
		Head.next = ptr;
		Tail.prev = ptr;
		ptr->prev = &Head;
	}
	else
	{
		Node* ptr = newNode(data);
		ptr->next = &Tail;
		ptr->prev = Tail.prev;
		Tail.prev->next = ptr;
		Tail.prev = ptr;
	}
	nodeSize++;
}

void printTopDelete()
{
	if (nodeSize > 0)
	{
		cout << Tail.prev->data << "\n";
		Tail.prev = Tail.prev->prev;
		nodeSize--;
	}
	else
		cout << "-1" << "\n";
}

void printCnt()
{
	cout << nodeSize << "\n";
}

void isEmpty()
{
	if (nodeSize > 0)
		cout << 0 << "\n";
	else
		cout << 1 << "\n";
}

void printTop()
{
	if (nodeSize > 0)
		cout << Tail.prev->data << "\n";
	else
		cout << "-1" << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int op, value;
	int n;
	cin >> n;
	

	for (int i = 0; i < n; i++)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> value;
			Insert(value);
		}
		else if (op == 2)
			printTopDelete();
		else if (op == 3)
			printCnt();
		else if (op == 4)
			isEmpty();
		else
			printTop();
	}
}
