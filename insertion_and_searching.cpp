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

void insertAtFirst(Node* &head, int val)
{
	Node* new_node=new Node(val);
	new_node->next= head;
	head=new_node;
}
void insertAtThePos(Node* &head,int pos,int val)
{
	Node* temp=head;
	int cnt=1;
	while(cnt<pos-1)
	{
		temp=temp->next;
		cnt++;
	}
	Node* new_node= new Node(val);
	new_node->next=temp->next;
	temp->next=new_node;
	if(pos==1)
	{
		insertAtFirst(head,val);
	
	}
	if(temp->next==NULL)
	{
		insertAtTheTail(head,val);
		return;
	}
}

int searchNode(Node* &head, int val)
{
    Node* temp=head;
    while(temp !=NULL)
    {
        if(temp->data==val)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
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
    //insert at the Starting of LinkedList
    insertAtFirst(head, 77);
    print(head);
    //insert at a position Starting of LinkedList
    insertAtThePos(head,1 ,3);
    print(head);
    //searching value
    cout<<searchNode(head, 1)<<endl;
    cout<<searchNode(head, 99)<<endl;
    return 0;
}