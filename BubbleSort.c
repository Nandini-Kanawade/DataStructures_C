#include<stdio.h>
int main(){

    int num, t;
    printf("Enter number of elemnts:= ");
    scanf("%d", &num);
    int array[num];
    for(int i=0; i<num; i++){
        printf("DATA[%d]=", i+1);
        scanf("%d", &array[i]);
    }
    
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(array[j]>array[j+1]){
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;                
            }
        }
    }

    printf("\n**AFTER SORTING**\n");

    for(int i=0; i<num; i++){
        printf("%d ", array[i]);
    }

}
