#include<stdio.h>
int main(){

  int n, ar[10], key, result,mid, low, high, flag=0;
  printf("Enter the number of elements in the array:= ");
  scanf(" %d", &n);

  printf("Enter an sorted array\n");
  for(int i=0; i<n; i++){
    scanf(" %d,", &ar[i]);
  }

  printf("Enter the element to find in the array:= ");
  scanf(" %d", &key);

  low=0;
  high=n-1;

   mid=(low+high)/2;

  while(low<=high){
   if(ar[mid]==key){
     printf("\n*****Element found at position %d*****\n", mid+1);
     flag=1;
     break;
   }if(ar[mid]<key){
     low=mid+1;
   }else{
     high=mid-1;
   }
  mid=(low+high)/2;
  }

  if(flag=0){
   printf("Elemnt not found");
  }

return 0; 
}
