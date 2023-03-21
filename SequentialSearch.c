#include<stdio.h>

void linearSearch(int ar[], int n);
int main(){
  
  int n;
  printf("Enter the number of elements in the array:= ");

  scanf("%d", &n);
  int array[n];
  linearSearch(array, n);
  printf("\n");
  return 0;

}
void linearSearch(int ar[], int n){
  int x, flag=0;
  ar[n];
  printf("Enter the elements in the array:= ");
  for(int i=0; i<n; i++){
    scanf("%d", &ar[i]);
  }

  printf("Enter the element to find in the array:= ");
  scanf("%d", &x);

  for(int i=0; i<n; i++){
    if(x==ar[i]){
       printf("The Element '%d' is present at position ''%d'' in the array", x, i+1);
       flag=1;
       break;
    }
  }
  
  if(flag==0){
     printf("The Element '%d' is not present in the array", x);
  }
 
}
