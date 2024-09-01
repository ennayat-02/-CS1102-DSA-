#include <stdio.h>
#include <conio.h>
#define MAXSIZE 10
int Que[MAXSIZE],rear=-1,front=0,n;
void main(){
    int choice;
   do{ printf("\n ------Queue------");
    printf("\n Enter your choice:");
    printf("\n 1.Insert \n 2.Delete \n 3.Display");
    printf("\n ------------------");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {case 1: insert();break;
     case 2: delete1();break;
     case 3: display();break;
     default: printf("\n Invalid choice");
    }
    }
    while(choice!=4);
}

void insert(){
    if(rear==MAXSIZE-1){
     printf("\n Queue overflow");
    }
    else{
     printf("\n Enter an element:");
    scanf("%d",&n);
    rear++;
    Que[rear]=n;
    }
}

void delete1(){
 if(front>rear){
    printf("Queue is empty");
 }
 else{
    n=Que[front];
    printf("deleted element %d",n);
    front++;
 }
}

void display(){
    if(front>rear){
        printf("\n Queue is empty");
    }
    else{
        int i;
        printf("\n Queue Elements are:");
        for(i=front;i<=rear;i++){
            printf("\n %d",Que[i]);
        }
    }
}

