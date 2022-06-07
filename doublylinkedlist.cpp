#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void displayLinkedList(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if (head!=NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node* &head, int val){

    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    
}
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}
int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    displayLinkedList(head);
    insertAtHead(head,5);
    displayLinkedList(head);
    deletion(head,2);
    displayLinkedList(head);
    deleteAtHead(head);
    displayLinkedList(head);
return 0;
}
