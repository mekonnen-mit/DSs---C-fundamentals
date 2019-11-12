#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node* previous;
    int id;
    char title[15];
    struct node* next;
};

struct node* start;

void create(int id,char title[15]){
    struct node* newnode;
    newnode =(struct node* )malloc(sizeof(struct node));
    start=newnode;
    newnode->id=id;
    strcpy(newnode->title, title);
    newnode->previous=NULL;
    newnode->next=NULL;
}

void add_at_begin(int id,char title[15]){
    struct node* newnode;
    newnode =(struct node* )malloc(sizeof(struct node));
    newnode->id=id;
    strcpy(newnode->title, title);
    newnode->previous=NULL;
    newnode->next=start;
    start->previous=newnode;
    start=newnode;
}

void add_at_end(int id,char title[15]){
    struct node* newnode;
    struct node* temp=start;
    newnode =(struct node* )malloc(sizeof(struct node));
    newnode->id=id;
    strcpy(newnode->title, title);
    newnode->previous=NULL;
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->previous=temp;
    temp->next=newnode;
}

void insert(int id,int pos,char title[15]){
    struct node* newnode;
    struct node* p;
    struct node* temp=start;
    newnode =(struct node* )malloc(sizeof(struct node));
    newnode->id=id;
    strcpy(newnode->title, title);
    newnode->previous=NULL;
    newnode->next=NULL;
    if(pos==1){
        newnode->next=start;
        start=newnode;
    }else{
        int i=2;
        while(i<pos){
                temp=temp->next;
                i++;
        }
        if(temp->next==NULL){
            add_at_end(id,title);
        }else{
            p=temp->next;
            p->previous=newnode;
            newnode->previous=temp;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

void remove_music(char title[15]){
    struct node* temp;
    struct node* temp1;
    struct node* temp2;
    temp=start;
    while(strcmp(temp->title,title)){
        temp=temp->next;
        if(temp->next==NULL)
            break;
    }
    if(temp->next==NULL&&temp->title!=title){
        printf(" there is no like that music\n");
    }else{
        temp1=temp->previous;
        temp2=temp->next;
        temp1->next=temp2;
        temp2->previous=temp1;
        free(temp);
    }

}

void search(char title[15]){
    struct node* temp;
    temp=start;
    int count=1;
    while(strcmp(temp->title,title)){
        temp=temp->next;
        count++;
        if(temp->next==NULL)
            break;
    }
    if(temp->next==NULL&&temp->title!=title){
        printf(" there is no like that music\n");
    }else{
        printf(" the music %s is at position %d\n",title,count);
    }

}

void traverse(){
    struct node* temp;
    temp=start;
    while(temp!=NULL){
        printf(" previous address:%p\n music id:%d \n music title:%s\n next address:%p\n\n",temp->previous,temp->id,temp->title,temp->next);
        temp=temp->next;
    }
}

int main(){
    int music_id,pos;
    char music_name[15];
    while(1){
        int choice;
        printf("what do you want my friend?Enter\n");
        printf("1: to create a linked list!\n");
        printf("2: to add music at the beginning!\n");
        printf("3: to add music at the end!\n");
        printf("4: to add music at any position!\n");
        printf("5: to remove music!\n");
        printf("6: to search music!\n");
        printf("7: to see all the musics!\n");
        printf("0: to exit!\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("please enter name and id of the music!\n");
                scanf("%s %d",music_name,&music_id);
                create(music_id,music_name);
                break;
            case 2:
                printf("please enter name and id of the music!\n");
                scanf("%s %d",music_name,&music_id);
                add_at_begin(music_id,music_name);
                break;
            case 3:
                printf("please enter name and id of the music!\n");
                scanf("%s %d",music_name,&music_id);
                add_at_end(music_id,music_name);
                break;
            case 4:
                printf("please enter name,id of the music and position to insert!\n");
                scanf("%s %d %d",music_name,&music_id,&pos);
                insert(music_id,pos,music_name);
                break;
             case 5:
                printf("please enter name of the music to remove!\n");
                scanf("%s",music_name);
                remove_music(music_name);
                break;
            case 6:
                printf("please enter name of the music to search!\n");
                scanf("%s",music_name);
                search(music_name);
                break;
            case 7:
                traverse();
                break;
            case 0:
               exit(1);
            default:
                printf("you entered an invalid value!\n\n");
        }
    }
}
