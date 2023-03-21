#include<stdio.h>
#define N 10

struct stack{
    int stackArray[N];
    int top;
}stackStruct;

void push();
void pop();
void display();

int main(){
    int choice, data;
    stackStruct.top=-1;
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
  if(stackStruct.top==N-1){
    printf("\n--Stack is Full--");
  }
  else{
    int x;
    printf("\nData:= ");
    scanf("%d", &x);
    stackStruct.top++;  
    stackStruct.stackArray[stackStruct.top]=x;
    printf("--%d is added in the Stack--", x);
  }
}

void pop(){
    if(stackStruct.top==-1){
        printf("\n--Stack is Empty--");
    }
    else{
        int num=stackStruct.stackArray[stackStruct.top];
        stackStruct.top--;
        printf("--%d is removed out of Stack--", num);
    }
}

void display(){
    printf("--STACK--");
    for(int i=stackStruct.top; i>=0; i--){
        printf("\n%d", stackStruct.stackArray[i]);
    }
}
