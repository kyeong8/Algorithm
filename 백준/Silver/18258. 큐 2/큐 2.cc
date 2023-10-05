#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

int nodeSize = 0;
int nodeCnt = 0;
Node node[2000000];

Node* newNode(int data)
{
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;

	return &node[nodeCnt++];
}

Node Head;
Node Tail;

void Push(int data)
{
	Node* ptr = newNode(data);

	ptr->prev = Tail.prev;
	Tail.prev->next = ptr;
	ptr->next = &Tail;
	Tail.prev = ptr;

	++nodeSize;
}

void Pop()
{
	if (nodeSize == 0)
	{
		cout << -1 << "\n";
		return;
	}

	Node* ptr = Head.next;

	Head.next = Head.next->next;
	Head.next->prev = &Head;

	--nodeSize;

	cout << ptr->data << "\n";
}

void Size()
{
	cout << nodeSize << "\n";
}

void Empty()
{
	if (nodeSize == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

void Front()
{
	if (nodeSize == 0)
		cout << -1 << "\n";
	else
		cout << Head.next->data << "\n";
}

void Back()
{
	if (nodeSize == 0)
		cout << -1 << "\n";
	else
		cout << Tail.prev->data << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Head.next = &Tail;
	Tail.prev = &Head;
	Head.prev = nullptr;
	Tail.next = nullptr;

	string op;
	int num;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> num;
			Push(num);
		}
		else if (op == "pop")
			Pop();
		else if (op == "size")
			Size();
		else if (op == "empty")
			Empty();
		else if (op == "front")
			Front();
		else if (op == "back")
			Back();
	}
}