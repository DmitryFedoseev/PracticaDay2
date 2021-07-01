#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

//Инициализации элемента односвязного списка нулями
void init(Node* node)
{
	if (node != nullptr)
	{
		node->val = 0;
		node->next = nullptr;
	}
}

// Отображения односвязного списка на экран
void show(Node* head)
{
	Node* p = head;
	while (p->next != nullptr)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

// Добавления элемента в односвязный список
void pushNode(Node* head, Node* node)
{
	Node* p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next = new Node;
	init(p->next);
	p->val = node->val;
}

//Функцию сдвига значений влево на n - элементов с переносом вытесненных элементов в конец
void lRoundShiftNode(Node* head, int n)
{
	for (int i = 0; i < n; i++)
	{
		Node* p = head;
		int num = p->val;

		while (p->next->next != nullptr)
		{
			p->val = p->next->val;
			p = p->next;
		}

		p->val = num;
	}
}
//Тесты
int testInit()
{
	Node* head = new Node;
	init(head);
	if (head->val != 0)
		return -1;
	else
		return 0;
}

int testPushNode()
{
	Node* head = new Node;
	init(head);
	Node node{1};
	pushNode(head, &node);
	if ((head->val != 0) || (head->next->val != 1))
		return -1;
	else
		return 0;
}



static void runTest(int (*testFunction)(), const string& testName)
{
	if (testFunction() == 0)
		cout << "Test " << testName << " - OK" << endl;
	else
		cout << "Test " << testName << " - FAIL" << endl;
}

int main()
{
	runTest(testInit, "testInit");
	runTest(testPushNode, "testPushNode");
}	



