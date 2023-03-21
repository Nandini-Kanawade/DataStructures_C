#include<stdio.h>

struct poly{

  int coef;

  int exp;

}p1[10], p2[10], p3[20];

int readPoly(struct poly p1[10]){

   int t;

   printf("Enter the number of terms in Polynomial:= ");

   scanf("%d", &t);

    for(int i=0; i<t; i++){

      printf("Coefficient of term %d:= ", i+1);

      scanf("%d", &p1[i].coef);

      printf(" Exponenet of term %d:= ", i+1);

      scanf("%d", &p1[i].exp);

    }

    return t;

}

int displayPoly(struct poly p1[10], int t){

    for(int k=0;k<t-1;k++)

    printf("%dx^%d + ",p1[k].coef,p1[k].exp);

    printf("%dx^%d",p1[t-1].coef,p1[t-1].exp);

    return 0;

}

int main(){

  

  int t1, t2;

  int i=0, j=0, k=0;

  printf("**1st Polynomial (Enter in descending order) **\n");

  t1=readPoly( p1);

  displayPoly(p1, t1);

  

  printf("\n\n**2st Polynomial (Enter in descending order) **\n");

  t2=readPoly(p2);

  displayPoly(p2,t2);

  while(i<t1 || j<t2){

    if(p1[i].exp==p2[j].exp){

      p3[k].coef=p1[i].coef + p2[j].coef;

      p3[k].exp=p1[i].exp;

      i++;

      j++;

      k++;

    }else if(p1[i].exp>p2[j].exp){

      p3[k].coef=p1[i].coef;

      p3[k].exp=p1[i].exp;

      i++;

      k++;

    }else{

      p3[k].coef=p2[j].coef;

      p3[k].exp=p2[j].exp;

      j++;

      k++;

    }

  }

  printf("\n\n**Final added Polynomial**\n");

  displayPoly(p3,k);

  printf("\n");

return 0;

}
