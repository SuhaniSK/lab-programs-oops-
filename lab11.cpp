#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* llink;
    struct node* rlink;
};

class dlist {
    node* first;
    node* last;
    int count;

public:
    dlist() {
        first = last = NULL;
        count = 0;
    }

    void insertfirst(int data);
    void insertnode(int data, int pos);
    void delnode(int pos);
    void show();
};

void dlist::insertfirst(int data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;

    if (first == NULL) {
        first = last = newnode;
    } else {
        newnode->rlink = first;
        first->llink = newnode;
        first = newnode;
    }

    count++;
    cout << "Inserted successfully\n";
}

void dlist::insertnode(int data, int pos) {
    if (pos < 1 || pos > count + 1) {
        cout << "Invalid position\n";
        return;
    }

    node* newnode = new node;
    newnode->data = data;

    if (pos == count + 1) {
        if (last == NULL) {
            first = last = newnode;
        } else {
            last->rlink = newnode;
            newnode->llink = last;
            last = newnode;
        }
    } 
     else {
        node* temp = first;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->rlink;
        }
        newnode->rlink = temp->rlink;
        newnode->llink = temp;
        if (temp->rlink != NULL)
            temp->rlink->llink = newnode;
        temp->rlink = newnode;
    }
    count++;
    cout << "Inserted successfully\n";
}

void dlist::show() {
    cout << "the number of nodes: " << count << "\n";
    cout << "the contents in the list are:\n";
    node* temp = first;
    if (temp == NULL) {
        cout << "empty list\n";
        return;
    } else {
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->rlink;
        }
        cout << endl;
    }
}

void dlist::delnode(int pos) {
    if (pos < 1 || pos > count) {
        cout << "Invalid position\n";
        return;
    }

    node* temp;
    int data;

    if (pos == count) {
        temp = last;
        last = last->llink;
        if (last != NULL)
            last->rlink = NULL;
        data = temp->data;
        delete temp;
        if (count == 1)
            first = NULL;
    } else if (pos == 1) {
        temp = first;
        first = first->rlink;
        if (first != NULL)
            first->llink = NULL;
        data = temp->data;
        delete temp;
        if (count == 1)
            last = NULL;
    } else {
        temp = first;
        for (int i = 1; i < pos; i++) {
            temp = temp->rlink;
        }
        temp->llink->rlink = temp->rlink;
        if (temp->rlink != NULL)
            temp->rlink->llink = temp->llink;
        data = temp->data;
        delete temp;
    }
    count--;
    cout << "Deleted " << data << " at position " << pos << " successfully\n";
}

int main() {
    int pos, choice, ele;
    dlist l;

    do {
        cout << "\nmenu\n1.insert\n2.delete\nenter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter an integer element to insert: ";
                cin >> ele;
                cout << "\nEnter a position to insert: ";
                cin >> pos;
                if (pos == 1)
                    l.insertfirst(ele);
                else
                    l.insertnode(ele, pos);
                l.show();
                break;

            case 2:
                cout << "\nEnter a position to delete: ";
                cin >> pos;
                l.delnode(pos);
                l.show();
                break;

            case 3:
                cout << "Exiting the program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}
