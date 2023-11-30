#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
int main(){
    struct Node*head=NULL;
    struct Node *copyhead=NULL;
   push(&head,5);
    push(&head,6);
     push(&head,7);
      push(&head,8);
       push(&head,9);
       display(head);
       circulardouble(&head);
       displaycir(head);
       search(&head,6);
       
}
void display(struct Node *head){
    while (head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}
void push(struct Node**head_ref,int data) { 
    // 1. allocate node
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    // 2. put in the data
    new_node->data = data;
 
    // 3. Make next of new node as head and previous as NULL
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    // 4. change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // 5. move the head to point to the new node
    (*head_ref) = new_node;
}
void insertafter(struct Node **head_ref,int position,int data){
    struct Node *copyhead=(*head_ref);
    for (int i=0;i<position;i++){
        copyhead=copyhead->next;
    }
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=copyhead->next;
    copyhead->next=new_node;
}
void insertbefore(struct Node **head_ref,int position,int data){
    struct Node *copyhead=(*head_ref);
    for (int i=0;i<position-1;i++){
        copyhead=copyhead->next;
    }
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=copyhead->next;
    copyhead->next=new_node;
}
void delete(struct Node **head,int position){
    struct Node *copyhead=(*head);
    for(int i =0;i<position-1;i++){
        copyhead=copyhead->next;
    }
    struct Node *temp1=copyhead->next->next;
     free(copyhead->next);
    copyhead->next=temp1;
   
}
void search(struct Node**head,int variable){
    struct Node*copyhead=*head;
    int count=0;
    int sign=0;
    while(copyhead!=NULL){
        if(copyhead->data==variable){
            sign=count;
            break;
        }
        count=count+1;
        copyhead=copyhead->next;
    }
    if(sign!=0){
        printf("andis %d of the %d variable",sign,variable);
    }
    else {
        printf("%d is not available ",variable);
    
    }
    
}
void circulardouble(struct Node **head){
    struct Node *copy=(*head);
    struct Node *movecopy=(*head);
    while (movecopy!=NULL)
    {
        if(movecopy->next==NULL){
            movecopy->next=copy;
            break;
        }
        movecopy=movecopy->next;
    }
    
}
displaycir(struct Node *head){
    struct Node *copy=head;
    while(head->next!=copy){
        printf("%d",head->data);
        head=head->next;
    }
    printf("%d",head->data);
}