6b) WAP to Implement Single Link List to simulate Stack &amp; Queue Operations.- 5M
//implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

//structure for node
struct node{
    int data;
    struct node* next;
};

//insert at the begining function
void push(struct node**head_ref,int item){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=*head_ref;
    *head_ref=newNode;
    printf("%d inserted\n",item);
    return;
};
void pop(struct node**head_ref){
    struct node* ptr;
    if(*head_ref==NULL){
        printf("Stack Underflow");
    }
    else{
        ptr=*head_ref;
        int item=ptr->data;
        *head_ref=ptr->next;
        free(ptr);
        printf("%d deleted \n",item);

    }
};

//implementation queue using linked list
void enqueue(struct node**head_ref,int item){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=*head_ref;
    *head_ref=newNode;
    printf("%d inserted\n",item);
    return;
};
void dequeue(struct node**head_ref){
    struct node *ptr,*ptr1;
    ptr=*head_ref;
    if(*head_ref==NULL){
        printf("\nEmpty queue\n");
    }
    else if(ptr->next==NULL){
        int item=ptr->data;
        free(ptr);
        *head_ref=NULL;
        printf("\nOnly %d deleted\n",item);
    }
    else{
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        int item=ptr->data;
        ptr1->next=NULL;
        free(ptr);
        printf("\n%d deleted",item);
    }
}
void main(){
    //stack implementation
    printf("\nStack Implemntation\n");
    struct node* stktop=NULL;
    push(&stktop,10);
    push(&stktop,20);
    push(&stktop,30);
    push(&stktop,40);
    push(&stktop,50);
    printf("\nStack elements:\n");
    struct node* ptr=stktop;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
    pop(&stktop);
    pop(&stktop);
    ptr=stktop;
    printf("\nStack after removing 2 top elements:\n");
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    
    printf("\n\n");
    //queue implementation
    printf("\nQueue Implemntation\n");
    struct node* rear=NULL;
    enqueue(&rear,100);
    enqueue(&rear,200);
    enqueue(&rear,300);
    enqueue(&rear,400);
    enqueue(&rear,500);
    printf("\nQueue elements:\n");
    ptr=rear;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    dequeue(&rear);
    dequeue(&rear);
    printf("\n\nQueue elements after deletion:\n");
    ptr=rear;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    
}

    
2. Leet code challenge- 5M
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* a = headA;
    struct ListNode* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
