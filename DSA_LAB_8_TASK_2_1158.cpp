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

	link_list() {
		head = tail = NULL;
	}

	void add_node(int value) {
		node* temp = new node{ value, tail, NULL };
		if (!head) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void add_node_AT_ANY_POSITION(int value, int pos) {
		node* temp = new node{ value, NULL, NULL };
		if (pos == 0) {
			temp->next = head;
			if (head) head->prev = temp;
			head = temp;
			if (!tail) tail = temp;
			return;
		}

		node* curr = head;
		for (int i = 0; i < pos - 1 && curr; ++i) {
			curr = curr->next;
		}

		if (!curr || !curr->next) {
			temp->prev = tail;
			if (tail) tail->next = temp;
			tail = temp;
			if (!head) head = temp;
		}
		else {
			temp->next = curr->next;
			temp->prev = curr;
			curr->next->prev = temp;
			curr->next = temp;
		}
	}

	void delete_by_value(int val) {
		node* temp = head;
		while (temp) {
			if (temp->data == val) {
				if (temp->prev) 
					temp->prev->next = temp->next;
				else
					head = temp->next;

				if (temp->next) temp->next->prev = temp->prev;
				else tail = temp->prev;

				delete temp;
				return;
			}
			temp = temp->next;
		}
	}

	void dsplay() {
		node* temp = head;
		while (temp) {
			cout << temp->prev << "    " << temp->data << "                " << temp->next << endl;
			temp = temp->next;
		}
	}
};
int main() {
	link_list myList;

	myList.add_node(10);
	myList.add_node(20);
	myList.add_node(30);
	cout << "After adding 10, 20, 30:\n";
	myList.dsplay();

	cout << "\nAdding 15 at position 1:\n";
	myList.add_node_AT_ANY_POSITION(15, 1);
	myList.dsplay();

	cout << "\nAdding 5 at position 0 (head):\n";
	myList.add_node_AT_ANY_POSITION(5, 0);
	myList.dsplay();

	cout << "\nDeleting value 20:\n";
	myList.delete_by_value(20);
	myList.dsplay();

	cout << "\nDeleting value 5 (head):\n";
	myList.delete_by_value(5);
	myList.dsplay();

	cout << "\nDeleting value 30 (tail):\n";
	myList.delete_by_value(30);
	myList.dsplay();

	return 0;
}
