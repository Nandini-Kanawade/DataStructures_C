#include<stdio.h>
void insertion(int ar[], int n);
int main(){
  
  int n;
  printf("Enter the number of elements in the array:= ");
  scanf("%d", &n);
  int array[n];
  insertion(array, n);
  printf("\n");
  return 0;

}

void insertion(int ar[], int n){
  int temp,j;
  ar[n];
  for(int i=0; i<n; i++){
    printf("DATA[%d]=", i+1);
    scanf("%d", &ar[i]);
  }

  printf("\n**Bfore Sorting**:= ");
  for(int a=0; a<n; a++){
    printf("%d,", ar[a]);
  }

  for(int i=1; i<n; i++){
    temp=ar[i];
    j=i-1;
    while(j>=0 && ar[j]>temp){
         ar[j+1]=ar[j];
         j=j-1;
    }
    ar[j+1]=temp;
  }

  printf("\n**After Sorting**:= ");
  for(int i=0; i<n; i++){
    printf("%d,", ar[i]);
  }
}
