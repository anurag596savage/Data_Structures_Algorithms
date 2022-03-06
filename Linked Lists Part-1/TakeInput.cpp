#include <iostream>
using namespace std;
#include "Node.cpp"


Node* TakeInputBetter() // Time Complexity is O(N)
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;

    while(data!=-1)
    {
        Node* newNode = new Node(data);
        if(head==NULL)
        {
            head = newNode;
            tail=head; 
        }
        else
        {
            tail->next = newNode;
            tail = newNode; // We can alternatively write tail=tail->next
        }
        cin>>data;
    }
    return head;
}

Node* TakeInput() // Time Complexity is O(N^2) 
{
    int data;
    cin>>data;
    Node* head = NULL;
    while(data!=-1)
    {
        Node* newNode = new Node(data); // Dynamically created since in static creation it gets deallocated
        // after one single iteration within the while loop because the scope is only inside the loop

        if(head==NULL)
        {
            head = newNode;

        }
        else
        {
            Node* temp = head;
            while(temp->next!=NULL) // This loop terminates when we are in the last node of the LL
            {
                temp=temp->next;
            }
            temp->next = newNode;
        }
        cin>>data;
    }

    return head;
}

void PrintLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL) // If we put the condition temp->next!=NULL we skip the last node in that case
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
//   Node *head = TakeInput();
//   PrintLL(head);
//   cout<<endl;
  Node* head = TakeInputBetter();
  PrintLL(head);
  
  return 0;
}
