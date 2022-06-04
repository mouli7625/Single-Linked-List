#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node* head=NULL;
    Node* first=NULL;
    Node* second=NULL;
    Node* third=NULL;
    head =new Node();
    first =new Node();
    second =new Node();
    third =new Node();
    head->data=0;
    head->next=first;
    first->data=1;
    first->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printlist(head);
    return 0;
}