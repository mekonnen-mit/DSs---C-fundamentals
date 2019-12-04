#include <stdio.h>
#include <stdlib.h>

int front=-1,rear=-1,arr[7],size=7;

void push(int data){
    int temp=(rear+1)%size;
    if(front==temp){
        printf("overflow!\n");
    }else{
        rear=temp;
        if(front==-1){
            front=0;
            rear=0;
        }
        arr[rear]=data;
    }
}

void pop(){
    int data=0;
    if(front==-1){
        printf("underflow!\n");
    }else{
        data=arr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }else{
            front=(front+1)%size;
        }
        printf("data:%d\n",data);
    }
}

int main()
{
    int choice=0,data=0;
    while(1){
        printf("please enter ur choice\n");
        printf("1:To push()!\n");
        printf("2:To pop()!\n");
        printf("0:To exit!\n");
        scanf("%d",&choice);
        switch(choice){
             case 1:
                 printf("please enter what u want to push()!\n");
                 scanf("%d",&data);
                 push(data);
                 break;
             case 2:
                 pop();
                 break;
             case 0:
                exit(1);
             default:
                printf("please enter valid choice!\n");
        }
    }
}
