#include <iostream>
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

    void delete_by_value(int value) {
        node* temp = head;
        while (temp) {
            if (temp->data == value) {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                delete temp;
                cout << "Value " << value << " deleted.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << value << " not found.\n";
    }

    void delete_by_position(int position) {
        node* temp = head;
        int count = 0;
        while (temp) {
            if (count == position) {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                delete temp;
                cout << "Node at position " << position << " deleted.\n";
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Invalid position: " << position << endl;
    }

    void search(int data) {
        node* temp = head;
        int pos = 0;
        while (temp) {
            if (temp->data == data) {
                cout << "Value " << data << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << data << " not found.\n";
    }

    int count_nodes() {
        int count = 0;
        node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void dsplay() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    link_list myList;
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at any position\n";
        cout << "3. Delete by value\n";
        cout << "4. Delete by position\n";
        cout << "5. Search for value\n";
        cout << "6. Display list\n";
        cout << "7. Count nodes\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            myList.add_node(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position (0-based index): ";
            cin >> pos;
            myList.add_node_AT_ANY_POSITION(value, pos);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            myList.delete_by_value(value);
            break;
        case 4:
            cout << "Enter position of node to delete: ";
            cin >> pos;
            myList.delete_by_position(pos);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            myList.search(value);
            break;
        case 6:
            myList.dsplay();
            break;
        case 7:
            cout << "Number of nodes: " << myList.count_nodes() << endl;
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
