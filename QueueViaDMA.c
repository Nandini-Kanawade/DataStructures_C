#include<stdio.h>
#include<stdlib.h>

struct queue
{
int data;
struct queue *next;
}*front,*rear,*p,*q;

void add();
void del();
void display();

void main(){
    int ch;
    rear=NULL;
    front=NULL;
    do{
        printf("\n\t*****MENU*****");
        printf("\n\t1.ADD\n\t2.DELETE\n\t3.DISPLAY\n\t4.EXIT");
        printf("\n\tENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            default: exit(0);
        }
    }while(ch!=4);
}

void add(){
    p=(struct queue*)malloc(sizeof(struct queue));
    printf("\n\tENTER THE data: ");
    scanf("%d",&p->data);
    p->next=NULL;
    if(rear==NULL){
        rear=p;
        front=p;
    }else{
        rear->next=p;
        rear=rear->next;
    }
}
    

void del(){
    q=front;
    if(q==NULL)
        printf("\n\tTHE QUEUE IS EMPTY");
    else{
        printf("\n\tTHE NO. DELETED IS: %d",front->data);
        front=front->next;
        q->next=NULL;
        free(q);
    }
}

void display(){
    q=front;
    if(q==NULL)
        printf("\n\tTHE QUEUE IS EMPTY!");
    else{
        while(q!=NULL){
            printf("\t%d",q->data);
            q=q->next;
        }
        printf("\n");
    }
}

