#include <iostream>
#include <algorithm>

using namespace std;
class Node{
    public: 
    int data;
    Node* next;
};

   Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}

Node* insertAtFirst(Node* head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = head_ref;
    head_ref = new_node;
    return head_ref;
}



void insertAfter(Node* temp,  int position, int data){

    Node* new_node = new Node();
    new_node->data = data;
    for(int i=1;i<=position-1;i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void append(Node* temp, int data){
    Node* new_node = new Node();
    new_node->data = data;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    
    temp->next = new_node;
    new_node->next = NULL;
}

void deleteNode(Node* temp, int key){
    Node* prev;
    while(temp!=NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next = NULL;
}

Node* reverse(Node* temp){
    Node *prev,*current,*next;
    current = temp;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    temp = prev;
    return temp;

}


int main(){
 

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);
    cout<<endl;

    // head = insertAtFirst(head,0);
    // printList(head);

    // insertAfter(head, 2,9);
    // printList(head);
    // append(head,100);
    // printList(head);

    // deleteNode(head, 2);
    head = reverse(head);
    printList(head);
    return 0;
}