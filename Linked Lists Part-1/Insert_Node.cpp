#include <iostream>
using namespace std;
#include "Node.cpp"

Node* insertNode(Node* head,int i,int data)
{
    if(i==0)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    int count=0;
    Node* temp = head;
    while(count<i-1 && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        Node* newNode = new Node(data);
        Node* a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}

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
  Node* head = TakeInputBetter();
  PrintLL(head);
  cout<<endl;
  
  int pos,data;
  cout<<"Enter the position and data you want to insert in the LL : ";
  cin>>pos>>data;
  
  head = insertNode(head,pos,data);
  
  PrintLL(head);
  cout<<endl;
  
  return 0;
}
