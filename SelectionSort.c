#include<stdio.h>
void selection(int ar[], int n);
int main(){
  
  int n;
  printf("Enter the number of elements in the array:= ");
  scanf("%d", &n);
  int array[n];
  selection(array, n);
  printf("\n");

}
void selection(int ar[], int n){
  ar[n];
  for(int i=0; i<n; i++){
    printf("DATA[%d]=", i+1);
    scanf("%d", &ar[i]);
  }

  printf("\n**Bfore Sorting**:= ");
  for(int a=0; a<n; a++){
    printf("%d,", ar[a]);
  }

  for(int i=0; i<n-1; i++){
    int min = i;
    for(int j=i+1; j<n; j++){
      if(ar[j]<ar[min]){
        min=j;
      }
    }
    if(i!=min){
      int t;
      t=ar[min];
      ar[min]=ar[i];
      ar[i]=t;
    }
  }

  printf("\n**After Sorting**:= ");
  for(int i=0; i<n; i++){
    printf("%d,", ar[i]);
  }
}
