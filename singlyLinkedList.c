#include<stdio.h>
#include<stdlib.h>

//structure for node
struct node{
    int data;
    struct node* next;
};

//insert at the begining function
void insertAtBegnning(struct node**head_ref,int item){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=*head_ref;
    *head_ref=newNode;
    printf("\nNode inserted at the beginning\n");
    return;
};

void insertAtEnd(struct node** head_ref,int item){
    struct node* newNode=(struct node*) malloc(sizeof(struct node));
    struct node* last=*head_ref;
    newNode->data=item;
    newNode->next=NULL;
    if(*head_ref==NULL){
        *head_ref=newNode;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
    printf("\nNode inserted at the end\n");
    return;
};
void insertInBetween(struct node** head_ref,int item,int pos){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    struct node* temp=*head_ref;
    newNode->data=item;
    int i=0;
    while(i!=pos-2){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("\nNode inserted at specific position %d\n",pos);
    return;
};

void delete_front(struct node**head_ref){
    struct node* ptr;
    if(*head_ref==NULL){
        printf("List empty");
    }
    else{
        ptr=*head_ref;
        *head_ref=ptr->next;
        free(ptr);
        printf("\nNode deleted\n");

    }
};

void delete_end(struct node**head_ref){
    struct node *ptr,*ptr1;
    ptr=*head_ref;
    if(*head_ref==NULL){
        printf("\nEmpty List\n");
    }
    else if(ptr->next==NULL){
        free(ptr);
        *head_ref=NULL;
        printf("\nOnly node is deleted\n");
    }
    else{
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\nDeleted node from last\n");
    }
}
void delete_in_between(struct node**head_ref,int loc){
    struct node* ptr,*ptr1;
    ptr=*head_ref;
    for(int i=0;i<loc-1;i++){
        ptr1=ptr;
        ptr=ptr->next;

        if(ptr==NULL){
            printf("\nthere are less than %d elements int list",loc);
            return;
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("\n node deleted at location %d",loc);
}
void main(){
    struct node* head=NULL;
    insertAtBegnning(&head,22);
    insertAtEnd(&head,100);
    insertAtBegnning(&head,45);
    insertAtEnd(&head,592);
    insertInBetween(&head,89,2);
    insertInBetween(&head,8888,3);
    
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    delete_front(&head);
    delete_front(&head);
    delete_end(&head);
    delete_in_between(&head,2);
    ptr=head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
}