1.   6a) WAP to Implement Single Link List with following operations: Sort the linked list, Reverse the linked
list, Concatenation of two linked lists.
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

Node* sortList(Node* head) {
    Node* i = head;
    Node* j = NULL;
    int temp;
    if(head == NULL) {
        return head;
    }
    for(; i != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

Node* concatenateLists(Node* head1, Node* head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    Node* temp = head1;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    head1 = insertNode(head1, 3);
    head1 = insertNode(head1, 2);
    head1 = insertNode(head1, 5);
    head1 = insertNode(head1, 1);
    printf("List 1: ");
    printList(head1);
    head1 = sortList(head1);
    printf("Sorted List 1: ");
    printList(head1);
    head1 = reverseList(head1);
    printf("Reversed List 1: ");
    printList(head1);
    head2 = insertNode(head2, 8);
    head2 = insertNode(head2, 6);
    printf("List 2: ");
    printList(head2);
    Node* head = concatenateLists(head1, head2);
    printf("Concatenated List: ");
    printList(head);
    return 0;
}

2.   8)WAP to Implement doubly link list with primitive operations                   
I.Create a doubly linked list.                   
II. Insert a new node to the left of the node.                   
III. Delete the node based on a specific value                    
IV. Display the contents of the list
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*prev;
    int data;
    struct node*next;
};

void traversal(struct node**head_ref){
    struct node*ptr=*head_ref;
    if(*head_ref==NULL){
        printf("Empty List\n");
        return;
    }
    else{
        while(ptr!=NULL){
            printf("%d <->",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
};

void insertAtBeginning(struct node**head_ref,int value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    struct node*ptr=*head_ref;
    if(*head_ref==NULL){
        newNode->prev=NULL;
        newNode->data=value;
        newNode->next=NULL;
        *head_ref=newNode;
    }
    else{
        newNode->prev=NULL;
        newNode->data=value;
        newNode->next=*head_ref;
        ptr->prev=newNode;
        *head_ref=newNode;
    }
    printf("Node inserted at front\n");
    return;
};
void deleteNode(struct node **head_ref, int data) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *node = *head_ref;
    while (node != NULL && node->data != data) {
        node = node->next;
    }

    if (node == NULL) {
        printf("Node with value %d not found\n", data);
        return;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *head_ref = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    printf("Node deleted \n");
    free(node);
}
void main(){
    struct node*head=NULL;
    traversal(&head);
    insertAtBeginning(&head,100);
    insertAtBeginning(&head,22);
    insertAtBeginning(&head,98);
    traversal(&head);
    deleteNode(&head,22);
    traversal(&head);
}
