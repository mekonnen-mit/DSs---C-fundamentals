#include <stdio.h>
#include <stdlib.h>

int arr[100],top=95,size=100;
void push(int book_id){
    if(top==size-1){
        printf("the store is full by now!(overflow)\n\n");
    }else{
        top+=1;
        arr[top]=book_id;
    }
}
void pop(){
    if(top<0){
        printf("there is no any book in the store(underflow)\n");
    }else{
        int book_id=arr[top];
        top-=1;
        printf("the id of the book at the top is->%d \n",book_id);
    }
}
int main()
{
    int book_id;
    while(1){
        int choice;
        printf("what do you want to add a book or take a book?\n");
        printf("enter 1 to add a book(push), 2 to take a book(pop) and 0 to stop!\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("please enter the book id!\n");
                scanf("%d",&book_id);
                push(book_id);
                break;
            case 2:
                pop();
                break;
            case 0:
                exit(1);
            default:
                printf("you entered an invalid value!\n");
        }
    }
}


