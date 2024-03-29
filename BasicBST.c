#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

typedef struct bstree{ 
    int data;
    struct bstree *lchild,*rchild;
}node;

struct STACK{
    node *item[max];
    int top;
};

typedef struct STACK stack;
stack s;

node *createbstree(node *);
node *getnode();
void search(node *,int);
void inorder_rec(node*);
void preorder_rec(node*);
void postorder_rec(node*);
void push(node*);
int checkfull();
node *pop();
int checkempty();
void inorder_nonrec(node*);
void preorder_nonrec(node *);
node *del(node*);

void main(){

    node *root=NULL;
    int ch=0,srno=0;
    do{
        printf("\n\n1.create tree");
        printf("\n2.inorder with recursion");
        printf("\n3.preorder with recursion");
        printf("\n4.postorder with recursion");
        printf("\n5.inorder without recursion");
        printf("\n6.preorder without recursion");
        printf("\n7.search\n8.Delete node");
        printf("\n9.exit");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                root=createbstree(root);
                break;
            case 2:
                printf("\n Inorder with recursion\n");
                inorder_rec(root);
                break;
            case 3:
                printf("\n Preorder with recursion\n");
                preorder_rec(root);
                break;
            case 4:
                printf("\n Postorder with recursion\n");
                postorder_rec(root);
                break;
            case 5:
                printf("\n Inorder without recursion\n");
                s.top=-1; 
                inorder_nonrec(root);
                break;
            case 6:
                printf("\n Preorder without recursion\n");
                s.top=-1; 
                preorder_nonrec(root);
                break;
            case 7:
                printf("\nEnter the search data:");
                scanf("%d",&srno);
                search(root,srno);
                break;
            case 8:
                root=del(root);
                inorder_rec(root);// call inorder
                break;
            default: exit(0);
        }
    }while(ch!=9);
}

node *createbstree(node *root){
    node *newnode=NULL,*oldnode=NULL;
    char ch;
    do{
        newnode=getnode();
        if(root==NULL){
            root=newnode;
        }else{
            oldnode=root;
            while(1){
                if(newnode->data < oldnode->data){
                    if(oldnode->lchild==NULL){
                        oldnode->lchild=newnode;
                        break;
                    }
                    else
                        oldnode=oldnode->lchild;
                }else{
                    if(newnode->data > oldnode->data){
                        if(oldnode->rchild==NULL){
                            oldnode->rchild=newnode;
                            break;
                        }
                        else
                            oldnode=oldnode->rchild;
                        }
                    else{
                        printf("\nDuplicate node cant be created!");
                        break;
                    }
                }
            }
        }
        printf("\nDo you want to add more nodes?(y/n)");
        scanf(" %c",&ch);
    }while(ch!='n');//end of do...while
    return root;
}

node *getnode(){
    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));

    if(temp==NULL){
        printf("\nmemory allocation error!");
        exit(0);
    }else{
        temp->lchild=NULL;
        temp->rchild=NULL;
        printf("\nenter the data:");
        scanf("%d",&temp->data);
    }
    return temp;
}

void search(node *root,int srno){
    int flag=0;
    node *pt=NULL;
    if(root==NULL)
        printf("\n tree is empty!");
    else{
        pt=root;
        while(1){
            while(pt!=NULL){
                if(pt->data==srno){
                    flag=1;
                    break;
                }
                if(pt->rchild!=NULL)
                push(pt->rchild);
                pt=pt->lchild;
            }
            if(checkempty()||flag==1)
            break;
            pt=pop();
        }
    }
    if(flag==1)
    printf("\n search element found");
    else
    printf("\nsearch element not found!");
}

void inorder_rec(node *pt){
    if(pt!=NULL){
        inorder_rec(pt->lchild);
        printf("\t%d",pt->data);
        inorder_rec(pt->rchild);
    }
}

void preorder_rec(node *pt){
    if(pt!=NULL){
        printf("\t%d",pt->data);
        preorder_rec(pt->lchild);
        preorder_rec(pt->rchild);
    }
}

void postorder_rec(node *pt){
    if(pt!=NULL){
        postorder_rec(pt->lchild);
        postorder_rec(pt->rchild);
        printf("\t%d",pt->data);
    }
}

void push(node *pt){
    if(checkfull())
        printf("overflow!");
    else{
        s.top++;
        s.item[s.top]=pt;
    }
}

node *pop(){
    node *pt=NULL;
    if(checkempty())
        printf("underflow!");
    else{
        pt=s.item[s.top];
        s.top--;
    }
    return pt;
}

int checkempty(){
    if(s.top==-1)
        return 1;
     else
        return 0;
}

int checkfull(){
    if(s.top==max-1)
        return 1;
     else
        return 0;
}

void inorder_nonrec(node *root){
 node *pt=NULL;
 if(root==NULL)
    printf("\n tree is empty!");
 else
 {    
    pt=root;
    while(1)
    {
        while(pt!=NULL)
        {
            push(pt);
            pt=pt->lchild;
        }
        if(checkempty())
            break;
        pt=pop();
        printf("\t%d",pt->data);
        pt=pt->rchild;
    }
  }
}

void preorder_nonrec(node *root){
 node *pt=NULL;
 if(root==NULL)
    printf("\n tree is empty!");
 else
 {   
    pt=root;
    while(1)
    {
        while(pt!=NULL)
        {
            printf("\t%d",pt->data);
            push(pt);
            pt=pt->lchild;
        }
        if(checkempty())
            break;
        pt=pop(); 
        pt=pt->rchild;
    }
  }
}

node *del(node *root){
    int no;
    node *temp,*prev,*x,*succ;
    printf("\n\t enter the data to be deleted:");
    scanf("%d",&no);
    temp=root;
    prev=temp;
    while(temp!=NULL){
        if(temp->data==no)
        break;
        prev=temp;
        if(no < temp->data)
            temp=temp->lchild;
        else     
            temp=temp->rchild;
    }
    if(temp->lchild==NULL &&temp->rchild==NULL){
        if(prev->lchild==temp)
            prev->lchild=NULL;
        else
            prev->rchild=NULL;
        printf("\n Leaf node is deleted\n");
    }else if(temp->rchild!=NULL && temp->lchild==NULL){
        if(prev->lchild==temp)
            prev->lchild=temp->rchild;
        else
            prev->rchild=temp->rchild;
        printf("\n Node with right subtree is deleted\n");
    }
    else if(temp->rchild==NULL && temp->lchild!=NULL){
        if(prev->lchild==temp)
            prev->lchild=temp->lchild;
        else
            prev->rchild=temp->lchild;
        printf("\n Node with left subtree is deleted\n");     
    }else if(temp->lchild!=NULL && temp->rchild!=NULL){ 
        succ=temp;
        x=temp->rchild;
        while(x!=NULL){
            prev=succ;
            succ=x;
            x=x->lchild;
        }
        temp->data=succ->data;
        if(temp->rchild!=succ)
            prev->lchild=succ->rchild; 
        else
            prev->rchild=succ->rchild;
        temp=succ;
        printf("\n Node with both subtree is deleted using inoreder successor method\n");
    }
    free(temp);
    return root;
    if(temp==NULL){
        printf("\n\t Node not present in the BST!=\n");
        return ;
    }
}



