#include"bits/stdc++.h"
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
         data=val;
         next=NULL;
         prev=NULL; 
    }
};

void insert_at_tail(node* &head, int val){
    node* n = new node(val);
    node* temp;
    temp = head;

    if(head==NULL){
        head = n;
        
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    n->prev = temp;
   
}

void insert_at_head(node*&head, int val){
    node*n = new node(val);
    if(head==NULL){
        head = n;
    }
    n->next = head;
    head->prev = n;
    head = n;

}

void display(node* head){
    node* temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void delete_at_last(node*&head){
    node* temp;
    temp=head;
    if(head==NULL){
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev = NULL;
    free(temp);
}

void delete_at_first(node*&head){
    node* temp = head;
    head = head->next;
    head->prev = NULL; 
    free(temp);
}

void delete_by_number(node*& head,int key){
    node* temp;
    temp = head;
    node*delnode;
    while(temp->data!=key){
        temp=temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);

}

void delete_by_position(node*& head, int pos){
    if(pos==1){
        delete_at_first(head);
        return;
    }
    
    int count=1;
    node* temp;
    temp = head;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }   
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    free(temp);
}


int main(){
    node* head =new node(1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);
    insert_at_head(head,6);
    display(head);
    delete_at_last(head);
    display(head);
    delete_by_position(head,1);
    display(head);
    delete_by_number(head,2);
    display(head);
    
    
    return 0;
}