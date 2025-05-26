#include<iostream>
using namespace std;
struct node {
	int data;
	node* prev;
	node* next;
};
struct link_list {
	node* head;
	node* tail;
	void add_node(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->prev = NULL;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = head;
			return;
		}
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	
void dsplay()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->prev << "    " << temp->data << "                " << temp->next << endl;
		temp = temp->next;
	}
}
};
int main() {
	link_list myList;
	myList.head = NULL;
	myList.tail = NULL;

	myList.add_node(10);
	myList.add_node(20);
	myList.add_node(30);

	cout << "Prev Address   Data   Next Address\n";
	myList.dsplay();

	return 0;
}
