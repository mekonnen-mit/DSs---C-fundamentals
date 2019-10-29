#include <stdio.h>
#include <stdlib.h>

struct node{
    int book_id;
    struct node* next;
};

struct node* root=NULL;

void push(int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->book_id=data;
    temp->next=root;
    root=temp;
}

void pop(){
    if(root==NULL){
        printf("there is no any book in the store(underflow)\n\n");
    }else{
        struct node* temp;
        int data=root->book_id;
        temp=root;
        root=root->next;
        free(temp);
        printf("the id of the book at the top is->%d \n\n",data);
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
                printf("you entered an invalid value!\n\n");
        }
    }
}

