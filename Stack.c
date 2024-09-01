#include <stdio.h>
#include <conio.h>
#define MAXSIZE 10
int stack[MAXSIZE],top=-1,n,i;
void main()
{   int choice;
    do{printf("------Stack------");
    printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
    printf("------------------");
    printf("\n--Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {case 1: push(); break;
     case 2: pop();break;
     case 3: display();break;
     default: printf("invalid choice \n");
    }

    }while(choice!=4);
}

    void push(){
        printf("\n");
        if(top==MAXSIZE-1){
        printf("\n stack is full \n");
    }
    else{
        printf("\n enter an element:");
        scanf("%d",&n);
        top++;
        stack[top]=n;
        }
        printf("\n");

    }


    void pop(){
        if(top==-1){
            printf("stack empty");
        }

        else{
            n=stack[top];
            top--;
            printf("%d has been popped",n);
        }printf("\n");

              }

    void display(){
        printf("\n");
        if(top==-1){
        printf("\n Stack empty \n");
    }
    else{
        printf("\n element of stack:");
        for(i=top;i>=0;i--){
            printf("\n %d",stack[i]);

        }printf("\n");

    }
    }






