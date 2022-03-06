#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head==NULL)
    {
        return head;
    }
    if(pos==0)
    {
        Node* a = head;
        head = head->next;
        delete a;
        return head;
    }
    int count = 0;
    Node* temp = head;
    while(count<pos-1 && temp!=NULL)
    {
        count = count + 1;
        temp=temp->next;
    }
    if(temp!=NULL && temp->next!=NULL)
    {
        Node *a = temp->next;
        Node* b = a->next;
        temp->next = b;
        delete a;
    }
    return head;
    
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}
