#include<iostream>
using namespace std;
//Structure for the Node
typedef class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node( int value)
    {
        data = value;
        next = NULL;
    }
}* NodePointer;

//Declaring and initializing head and current node
NodePointer head=NULL,curr=NULL;

NodePointer createNewNode(int value)
{
    NodePointer newNode = new Node(value);
    return newNode;
}
//insertion of N elements for the first time
void insertNelements(int n)
{
    int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> value;
        NodePointer newNode = createNewNode(value);
        if (head == NULL)
        {
            head = curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }

}
//insert a value as node at the Beginning of Linked List
void insertAtFirst(int value)
{
    NodePointer newNode = createNewNode(value);
    if (head == NULL)
    {
        head = curr = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

}

//insert a value as node at the End of Linked List
void insertAtLast(int value)
{
    NodePointer newNode = createNewNode(value);
    if (head == NULL)
    {
        head = curr = newNode;
    }
    else
    {
        curr->next = newNode;
        curr = newNode;
    }
}

void insertBefore(int value, int p)
{
    NodePointer newNode = createNewNode(value);
    if (head == NULL)
    {
        head = curr = newNode;
    }
    else
    {
        NodePointer temp = head, prev = NULL;
        while (temp != NULL && temp->data != p)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Element " << p << " not found in the list." << endl;
        }
        else if (temp == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = temp;
            prev->next = newNode;
        }
    }


}
void insertAfter(int value,int p)
{


    NodePointer newNode = new Node(value);
    NodePointer current = head;
    for (int i = 0; i < p-1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        newNode->next = current->next;
        current->next = newNode;
    }


}

void deleteFirst()
{


    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    NodePointer temp = head;
    head = head->next;
    delete temp;


}

void deleteLast()
{
    if(head == NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    if(head->next == NULL)
    {
        delete head;
        head = curr = NULL;
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    curr = temp;

}

void deleteData(int p)
{
    if(head==NULL)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    NodePointer temp = head;
    if(p==0)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<p-1 && temp!=NULL; i++)
    {
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
    {
        cout<<"Position out of range."<<endl;
        return;
    }
    NodePointer nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;
}


void display()
{
    if(head==NULL)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    NodePointer temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int choice, value, position;

    while (true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert a value at the beginning\n";
        cout << "2. Insert a value at the end\n";
        cout << "3. Insert a value before a given node\n";
        cout << "4. Insert a value after a given node\n";
        cout << "5. Delete the first node\n";
        cout << "6. Delete the last node\n";
        cout << "7. Delete a node at a given position\n";
        cout << "8. Display the linked list\n";
        cout << "9. Exit\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAtFirst(value);
            break;

        case 2:
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAtLast(value);
            break;

        case 3:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the value of the node before which to insert: ";
            cin >> position;
            insertBefore(value, position);
            break;

        case 4:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the value of the node after which to insert: ";
            cin >> position;
            insertAfter(value, position);
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            deleteLast();
            break;

        case 7:
            cout << "Enter the position of the node to delete: ";
            cin >> position;
            deleteData(position);
            break;

        case 8:
            display();
            break;

        case 9:
            return 0;

        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}
