#include <iostream>
#include <cmath>
#include <ctime>

struct node
{
	node* next;
	int value;
};


bool isCycle(node* head)
{
	node *fast = head, *slow = head;

	while (fast && slow && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return true;
	}

	return false;
}


int main()
{
	unsigned int count = 10000, next;
	node **el = new node*[count];

	srand((unsigned int)time(NULL));

	for (unsigned int i = 0; i < count; i++)
	{
		el[i] = new node();
		el[i]->value = i;
	}
	for (unsigned int i = 0; i < count - 1; i++)
	{
		el[i]->next = el[i + 1];
	}

	for (unsigned int i = 0; i < count; i++)
	{
		next = rand() % count;
		el[count - 1]->next = el[next];

		std::cout << isCycle(el[0]) << " " << next << std::endl;
	}

	return 0;
}