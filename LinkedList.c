      #include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*temp, *head, *newnode;

int n;

void search();
void display(int n);
void insert(int n);
void insert_b();
void insert_m();
void insert_p(int n);
void insert_e();
void delete(int n);
void delete_b();
void delete_m();
void delete_p(int n);
void delete_e();
void reverseDisplay(struct node *temp);
void revert(int n);

int main(){

    int choice;

    do{
    printf("Enter the number nodes:= ");
    scanf("%d", &n);
    }while(n==0);
    
    head=NULL;

    for(int i=1; i<=n; i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Data[%d]:= ", i);
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    
    do{
        printf("\n-----------------------------------------------------------------------------------------------\n\n***MENU***");
        printf("\n\"1\" => Displaying all nodes\n\"2\" => Search a node\n\"3\" => Inserting a node\n\"4\" => Deleting a node\n\"5\" => Displaying all nodes in Reverse order\n\"6\" => Reverting the Linked List\n\"0\" => EXIT");
        printf("\n::= ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display(n);
                break;
            case 2:
                search();
                break;
            case 3:
                insert(n);
                break;
            case 4:
                delete(n);
                break;
            case 5:
                temp=head;
                reverseDisplay(temp);        
                break;
            case 6:
                revert(n);
                break;    
            case 7:
                printf("ThankYou\n");
                break;
            default:
                printf("\n");
        }
    }while(choice!=0); 
}

void display(int n){
    printf("\nLINKED_LIST\n");
    struct node* current=head;
    if(current == NULL && n==0){
        printf("---empty");
    }
    while(current != NULL){
        printf("%d\t", current->data);
        current=current->next;
    }

}

void search(){
    int item;
    int count=1;
    int found=0;
    printf("\nSEARCH\nEnter the number you want to search: ");
    scanf("%d", &item);
    struct node* current = head;
    while(found==0 && current!=NULL){
        if (current->data == item){
            found=1;
        }
        else{
            count++;
            current = current->next;  
        }    
    }
    if(found==1){
        printf("\"%d\" is found at position %d", item, count);
    }else{
        printf("\"%d\" is not found", item);
    }

}

void insert_b(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nINSERT_BEGINNING\nData:= ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
    printf("DATA INSERTED");
    n++;
}

void insert_m(){
    int count, mid;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nINSERT_MIDDLE\nData:= ");
    scanf("%d", &newnode->data);
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count%2==0){
        mid=(count/2);
    }else{
        mid=(count+1)/2;        
    }
    temp=head;
    for(int i=1; i<mid; i++){
        temp = temp->next;
    }
    newnode->next = temp-> next;
    temp->next = newnode;
    printf("DATA INSERTED");
    n++;
}

void insert_p(int n){
    int position;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nINSERT_AT_A_POSITION\nEnter the position at which you want to add the node:= ");
    scanf("%d", &position);
    
    if(position==1){
        printf("\nData:= ");
        scanf("%d", &newnode->data);
        newnode->next=head;
        head=newnode;
    }
    else if(position==n){
        printf("\nData:= ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=newnode;
    }
    else{
        printf("Data:= ");
        scanf("%d", &newnode->data);
        for(int i=1; i<position-1; i++){
            temp=temp->next;
        }
       newnode->next=temp->next;
       temp->next=newnode;
    }
    printf("DATA INSERTED");
    n++;
}

void insert_e(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nINSERT_AT_END\nData:= ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("DATA INSERTED");
    n++;
}

void insert(int n){
    int choice;
    do{
        printf("\n-----------------------------------------------------------------------------------------------\n\n***INSERT_MENU***");
        printf("\n\"1\" => Inserting node at beginning\n\"2\" => Inserting node at Middle\n\"3\" => Inserting node at Specific position\n\"4\" => Inserting node at End\n\"0\" => MAIN MENU");
        printf("\n::= ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                insert_b();
                break;
            case 2:
                insert_m();
                break;
            case 3:
                insert_p(n);
                break;
            case 4:
                insert_e();
                break;   
            case 0:
                printf("\n");
                break;
            default:
                printf("\n");
        }
    }while(choice!=0);

}

void delete_b(){
    temp=head;
    head=head->next;
    free(temp);
    printf("\nSTART_NODE_DELETED\n");
    n--;
}

void delete_m(){
    struct node* temp2;
    int count=0, mid;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count%2==0){
        mid=(count/2)+1;
    }else{
        mid=(count+1)/2;        
    }
    temp=head;
    int i=1;
    while(i<mid-1){
        temp=temp->next;
        i++;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    printf("\nMIDDLE_NODE_DELETED\n");
    n--;
}

void delete_p(int n){
    int position;
    printf("Specify the node to be deleted:= ");
    scanf("%d", &position);
    struct node* temp2;
    temp=head;
    if(position==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else if(position==n){
        struct node* temp2;
        temp=head;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
    }
    else{
        for(int i=1; i<position-1; i++){
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }
    printf("\nNODE_AT_%d_DELETED\n", position);
    n--;
}

void delete_e(){
    struct node* temp2;
    temp=head;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    printf("\nEND_NODE_DELETED\n");
    n--;
}

void delete(int n){
    int choice;
    do{
        printf("\n-----------------------------------------------------------------------------------------------\n\n***DELETE_MENU***");
        printf("\n\"1\" => Deleting the beginning node\n\"2\" => Deleting the Middle node\n\"3\" => Deleting the node from a Specific position\n\"4\" => Deleting the end node\n\"0\" => MAIN MENU");
        printf("\n::= ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                delete_b();
                break;
            case 2:
                delete_m();
                break;
            case 3:
                delete_p(n);
                break;
            case 4:
                delete_e();
                break;   
            case 0:
                printf("\n");
                break;
            default:
                printf("\n");
        }
    }while(choice!=0);
}

void reverseDisplay(struct node *temp){
    if(temp!=NULL){
        reverseDisplay(temp->next);
        printf("\t%d", temp->data);
    }
}

void revert(int n){
    struct node *temp2;
    struct node *new;
    temp=head;
    temp2=NULL;
    while(temp!=NULL){
        new = temp2;
        temp2=temp;
        temp=temp->next;
        temp2->next=new;
    }
    head=temp2;
    printf("\nREVERTION_COMPLETE\n");
    display(n);
}
