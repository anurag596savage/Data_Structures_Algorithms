#include <iostream>
using namespace std;
#include "Node.cpp"

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
    // Statically

    Node n1(1);

    Node *head = &n1; // head is a pointer variable of 8 bytes

    Node n2(2);
    n1.next = &n2;

    Node n3(3);
    n2.next = &n3;

    Node n4(4);
    n3.next = &n4;

    Node n5(5);
    n4.next = &n5;

    PrintLL(head); // Note -> We may change the value of head in function but it does not affect head of main() since it is passed by value
  
    cout<<endl;
  
  // Dynamically

    Node *a = new Node(10); //  This node is created inside heap
    Node *h = a;

    Node *b = new Node(20);
    a->next = b;

    Node *c = new Node(30);
    b->next = c;
    
    PrintLL(h);
  
   return 0;
}

   
