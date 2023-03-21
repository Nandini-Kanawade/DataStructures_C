#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
}*new, *temp, *top;

void push();
int pop();
void display();

int main(){
    top=NULL;
    int n, choice;
    printf("Enter number of intial stack elements:= ");
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        push();
    }
    printf("---MENU---");
    do{
        printf("\n\n\"1\" => Inserting an item.\n\"2\" => Removing the item\n\"3\" => Displaying stack elements\n\"4\" ==> EXIT\n:=");
        scanf("%d", &choice);
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
                printf("\nThankYou\n");
                break;
            default:
                printf("Wrong Option Entered");
        }
    }while(choice!=4);
}

void push(){
    printf("Data:= ");
    new=(struct stack*)malloc(sizeof(struct stack));
    scanf("%d", &new->data);
    new->next=top;
    top=new;
}

int pop(){
    int x;
    if(top==NULL){
        printf("The stack is Empty!!\n");
        return 0;
    }else{
        temp=top;
        x=top->data;
        top=top->next;
        free(temp);
        printf("\n--%d is removed from the stack--", x);
        return x;
    }
    
}
void display(){
    if(top==NULL){
        printf("The stack is Empty!!\n");
    }else{
        printf("The stack is: \n");
        temp=top;
        while(temp!=NULL){
            printf("%d\t\n", temp->data);
            temp=temp->next;
        }
    }
}
