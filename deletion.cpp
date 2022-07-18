#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
    ~Node()
    {
        int val=this->data;
        if(this->data==NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout << " memory is free for node with data " <<val<< endl;
    }
};
void insertAtTheTail(Node* &head,int val)
{
    Node* new_node=new Node(val);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
void deleteNode(Node* &head, int pos)
{
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev= curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } 
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head=NULL;
    //insert at the Tail of LinkedList
    insertAtTheTail(head, 1);
    insertAtTheTail(head, 2);
    insertAtTheTail(head, 4);
    insertAtTheTail(head, 5);
    print(head);
    //delete from of LinkedList
    deleteNode(head, 1);
    print(head);

    return 0;
}