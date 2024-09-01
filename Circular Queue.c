#include <stdio.h>
#include <conio.h>
#define MAXSIZE 10
int Cq[MAXSIZE],rear=-1,front=-1,n;
void main(){
    int choice;
    do{printf("\n ------Circular Queue------");
    printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit");
    printf("\n --------------------------");
    printf("\n Enter your Choice:");
    scanf("%d",&choice);


    switch(choice){
    case 1: insert();break;
    case 2: delete1();break;
    case 3: display();break;
    default: printf("\n Invalid choice");
    }
    }while(choice!=4);

}
void insert(){
    if((rear+1)%MAXSIZE==front){
       printf("\n Queue is overflow");
       }
    else{
        printf("\n Enter an element:");
        scanf("%d",&n);
        if(rear==-1&front==-1){
            rear=0;
            front=0;
        }
        else{
            rear=(rear+1)%MAXSIZE;
        }
        Cq[rear]=n;
    }
 }


void delete1(){
 if(rear==-1 && front==-1){
    printf("\n Queue is empty");
 }
 else{
    n=Cq[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAXSIZE;
    }
    printf("\n Deleted element %d",n);
 }
}

void display(){
    int i;
   if(rear==-1&&front==-1){
    printf("\n Queue is empty");
   }
   else{
    printf("\n Elements are:");
    for(i=front;i!=rear;i=(i+1)%MAXSIZE){
        printf("\n %2d",Cq[i]);
    } printf("\n %2d",Cq[i]);
   }
}
