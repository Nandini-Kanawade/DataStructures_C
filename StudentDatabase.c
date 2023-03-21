#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

char temp;
int n, m;
struct student{
    int rollNo;
    char name[20];
    char year[20];
    char programme[20];
    int sub1, sub2, sub3;
    int total;
    float avg;
}s[50];
struct student temps;

void display(int n);
void search(int n);
void searchByName(int n);
void searchByRollNo(int n);
void modify(int n);
void modifyName(int n);
void modifyRollNo(int n);
void modifyMarks(int n);
void append(int n, int m);
void sort(int n);

int main(){

    int i, choice;
    printf("Enter the number of students:= ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("\n--STUDENT_%d--", i+1);
        printf("\nRoll Number:= ");
        scanf("%d", &s[i].rollNo);
        printf("Name of Student:= ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", s[i].name);
        printf("Program: ");
        scanf("%[^\n]%*c", s[i].programme);
        printf("Year: " );
        scanf("%[^\n]%*c", s[i].year);
        printf("***MARKS***\n");
        printf("Data Structure And Algorithm: ");
        scanf("%d", &s[i].sub1);
        printf("Mathematics : ");
        scanf("%d", &s[i].sub2);
        printf("Electronic Circuits And Applications: ");
        scanf("%d", &s[i].sub3);
        s[i].total=s[i].sub1+s[i].sub2+s[i].sub3;
        s[i].avg=s[i].total/3;
    }

    do{
        printf("\n-----------------------------------------------------------------------------------------------\n\n***MENU***");
        printf("\n\"1\" for Displaying all Students\n\"2\" for Search a Student Database\n\"3\" for Edit a Student Sata Fields\n\"4\" for Append the database\n\"5\" for Sort the database\n\"6\" for EXIT");
        printf("\n::= ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                display(n);
                break;
            case 2:
                search(n);
                break;
            case 3:
                modify(n);
                break;
            case 4:
                printf("-----------------------------------------------------------------------------------------------\nEnter number of students to be added more:= ");
                scanf("%d", &m);
                append(n,m);
                n=n+m;
                printf("\nNEW APPENDED DATABASE\n");
                display(n);
                break;
            case 5:
                sort(n);        
                break;
            case 6:
                printf("ThankYou\n");
                break;
            default:
                printf("Wrong Choice Enetered\n");
        }
    }while(choice!=6);        
}

void display(int n){
    
    printf("\n-------------------------------------------------------------------------------------------------------");
    printf("\nRollNo.     Name                Program     Year        DSA         Maths       ECA         Percentage");
    printf("\n-------------------------------------------------------------------------------------------------------");
    for(int i=0; i<n; i++){
        printf("\n%-12d%-20s%-12s%-12s%-12d%-12d%-12d%-12f", s[i].rollNo, s[i].name, s[i].programme, s[i].year, s[i].sub1, s[i].sub2, s[i].sub3, s[i].avg);
    }

}

void searchByName(int n){
    printf("-------------------------------------------------------------------------------------------------------\nName_Search\n");
    char key[20];
    int i, flag;
    printf("Enter the Name of the Student whose data is to be fetched:= ");
    scanf("%c", &temp);
    scanf("%[^\n]%*c", key);
    
    for(i=0; i<n; i++){
        if(strcmp(key, s[i].name)==0){
            flag=1;
            break;}
        else{
            flag=0;
        }
    }

    if(flag==1){
        printf("\nRecord of %s", s[i].name);
        printf("\n-------------------------------------------------------------------------------------------------------");
        printf("\nRollNo.     Name                Program     Year        DSA         Maths       ECA         Percentage");
        printf("\n-----------------------------------------------------------------------------------------------");
        printf("\n%-12d%-20s%-12s%-12s%-12d%-12d%-12d%-12f", s[i].rollNo, s[i].name, s[i].programme, s[i].year, s[i].sub1, s[i].sub2, s[i].sub3, s[i].avg);
    }else{
        printf("RECORD NOT FOUND\n");
    }
}
void searchByRollNo(int n){

    printf("-------------------------------------------------------------------------------------------------------\nRollNumber_Search\n");
    int key, flag, i;
    printf("\nEnter the Roll Number of the student whose data is to be fetched:= ");
    scanf("%d", &key);
    
    for(i=0; i<n; i++){
        if (s[i].rollNo == key){
            flag=1;
            break;
        }else{
            flag=0;  
        }
    }
    if (flag==1){
        printf("\nRecord of Roll Number:= %d", s[i].rollNo);
        printf("\n-------------------------------------------------------------------------------------------------------");
        printf("\nRollNo.     Name                Program     Year        DSA         Maths       ECA         Percentage");
        printf("\n-----------------------------------------------------------------------------------------------");
        printf("\n%-12d%-20s%-12s%-12s%-12d%-12d%-12d%-12f", s[i].rollNo, s[i].name, s[i].programme, s[i].year, s[i].sub1, s[i].sub2, s[i].sub3, s[i].avg);
    }else{
        printf("RECORD NOT FOUND\n");
    }        

}
void search(int n){
    printf("-------------------------------------------------------------------------------------------------------\n");
    int x;
    do{
        printf("\n\nEnter \"1\" for Search By Name\nEnter \"2\" for Search By Roll Number\nEnter \"3\" for Main Menu\n:=");
        scanf("%d", &x);
        switch(x){
            case 1:
                searchByName(n);
                break;
            case 2:
                searchByRollNo(n);
                break;
            case 3:
                printf("\n");
                break;
            default:
                printf("Wrong Choice Enetered\n");
        }
    }while(x!=3); 
}

void modifyName(int n){

    printf("-------------------------------------------------------------------------------------------------------\nMODIFY NAME\n");
    char old[20], new[20];
    int i, flag;
    printf("\nEnter the Name to be modified:= ");
    scanf("%c",&temp);
    scanf("%[^\n]%*c", old);

    for(i=0; i<n; i++){
        if (strcmp(old, s[i].name)==0){
            flag=1;
            break;
        }else{
            flag=0;
        }
    }

    if(flag==1){
        printf("\nEnter new Name:= ");
        scanf("%[^\n]%*c", new);
        strcpy(s[i].name, new);
        printf("**Data Mofified**");

    }if(flag==0){
        printf("RECORD NOT FOUND\n");
    }
}
void modifyRollNo(int n){

    printf("-------------------------------------------------------------------------------------------------------\nMODIFY ROLL NUMBER\n");
    int old, new, i, j, flag;
    printf("\nEnter the Roll Number to be modified:= ");
    scanf("%d", &old);

    for(i=0; i<n; i++){
        if (s[i].rollNo==old){
            flag=1;
            j=i;
            break;
        }else{
            flag=0;
        }
    }
    if(flag==1){
        printf("\nEnter new Roll Number:= ");
        scanf("%d", &new);
        s[j].rollNo=new;
        printf("**Data Mofified**");

    }if(flag==0){
        printf("RECORD NOT FOUND\n");
    }
}
void modifyMarks(int n){

    printf("-------------------------------------------------------------------------------------------------------\nMODIFY MARKS\n");
    int roll, ss, j, new;
    printf("\nEnter the Roll Number of the students whose Marks are needed to be changed:= ");
    scanf("%d", &roll);
    for(j=0; j<n; j++){
        if (s[j].rollNo==roll){
            break;
        }
    }
    printf("\nEnter the Subject to be modified:\n\'1\' Data Structres and Algorithms\n\'2\' Mathematics\n\'3\' Electronic Circuits and Applications\n:= ");
    scanf("%d", &ss);
    
    if(ss==1){
        printf("\n Enter new Marks:= ");
        scanf("%d", &new);
        s[j].sub1=new;
        printf("**Data Mofified**");
        s[j].total=s[j].sub1+s[j].sub2+s[j].sub3;
        s[j].avg=s[j].total/3;
    }
    if(ss==2){
        printf("\n Enter new Marks:= ");
        scanf("%d", &new);
        s[j].sub2=new;
        printf("**Data Mofified**");
        s[j].total=s[j].sub1+s[j].sub2+s[j].sub3;
        s[j].avg=s[j].total/3;
    }
    if(ss==3){
        printf("\n Enter new Marks:= ");
        scanf("%d", &new);
        s[j].sub3=new;
        printf("**Data Mofified**");
        s[j].total=s[j].sub1+s[j].sub2+s[j].sub3;
        s[j].avg=s[j].total/3;
    }  
}
void modify(int n){
    printf("-------------------------------------------------------------------------------------------------------\n");
    int x;
    do{
        printf("\n\nEnter \"1\" to Edit Name\nEnter \"2\" to Edit Roll Number\nEnter \"3\" to Edit Marks\nEnter \"4\" for Main Menu\n:=");
        scanf("%d", &x);
        switch(x){
            case 1:
                modifyName(n);
                break;
            case 2:
                modifyRollNo(n);
                break;
            case 3:
                modifyMarks(n);
                break;
            case 4:
                printf("\n");
                break;
            default:
                printf("Wrong Choice Enetered\n");
        }
    }while(x!=4);
}

void append(int n, int m){
    int i;
    for(i=n; i<n+m; i++){
        printf("\n--STUDENT_%d--", i+1);
        printf("\nRoll Number:= ");
        scanf("%d", &s[i].rollNo);
        printf("Name of Student:= ");
        scanf("%c", &temp);
        scanf("%[^\n]%*c", s[i].name);
        printf("Program: ");
        scanf("%[^\n]%*c", s[i].programme);
        printf("Year: " );
        scanf("%[^\n]%*c", s[i].year);
        printf("\n*MARKS*\n");
        printf("Data Structure & Algorithm: ");
        scanf("%d", &s[i].sub1);
        printf("Mathematics : ");
        scanf("%d", &s[i].sub2);
        printf("Electronic Circuits and Applications: ");
        scanf("%d", &s[i].sub3);
        s[i].total=s[i].sub1+s[i].sub2+s[i].sub3;
        s[i].avg=s[i].total/3;
    }
}

void sort(int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if (s[j].rollNo>s[j+1].rollNo){
                temps = s[j];
                s[j]=s[j+1];
                s[j+1]=temps;
            }
        }
    }
    display(n);
}
