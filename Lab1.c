#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;
void push(){
	if (top==N){
		printf("Stack is full/ Stack Overflow\n");	
	}
	else{
	int x;
	printf("Enter the element to be inserted:");
	scanf("%d",&x);
	top++;
	stack[top]=x;
	}
	};
void pop(){
	if (top==-1){
		printf("Stack is empty/ Stack underflow\n");
	}
	else{
	int item=stack[top];
	stack[top]=0;
	printf("Element removed from stack is %d",item);
	top--;
	}
	};
void display(){
	printf("Elements of stack:\n");
	for(int i=N;i>0;i--){
		printf("%d --> ",stack[i]);
	}
	};
void main(){

	while(1){
	int choice;
	printf("\n1.Push element to the stack\n");
	printf("2.Pop element from the stack\n");
	printf("3.Display elements of the stack\n");
	printf("4.Exit\n");
	scanf("%d",&choice);

	switch(choice){
	case 1:
           push();
           break;
 
        case 2:
          pop();
          break;
 
        case 3:
           display();
           break;
	
	case 4:
           break;

	default: 
	   printf("Invalid Choice\n");
		
     	}
	if (choice==4){
	break;
	}
    }
}
