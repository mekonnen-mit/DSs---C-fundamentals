#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* start=NULL;

void create(int x){
     struct node* newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     start=newNode;
     newNode->data=x;
     newNode->next=NULL;
}

void insert_at_begining(int data){
     struct node* newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
     newNode->next=start;
     start=newNode;
}

void insert_at_loc(int loc,int data){
    struct node* temp;
     temp=start;
     int k=2;
     while(k<loc){
        temp=temp->next;
        if(temp==NULL){
            printf("position is greater than size\n");
            break;
        }
        k++;
     }
     struct node* newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
     newNode->next=temp->next;
     temp->next=newNode;
}

void add_at_end(int data){
     struct node* temp;
     temp=start;
     while(temp->next!=NULL){
        temp=temp->next;
     }
     struct node* newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
     newNode->next=temp->next;
     temp->next=newNode;
}
/*
if there is repetition of data we need also the location
 and use another logic but now since our data is id and can't be repeated we can use only data
 to remove a node........
*/
void remove_data(int data){
    struct node* temp;
    temp=start;
    if(start->data==data){
        start=start->next;
        free(temp);
    }else{
        while(temp->next!=NULL){
        if(temp->data==data)
            break;
         temp=temp->next;
    }
    if(temp->data==data){
        struct node* p;
        p=start;
        while(p->next!=temp){
            p=p->next;
        }
        p->next=temp->next;
        free(temp);
    }
    else{
        printf("data %d don't exist!\n",data);
    }
    }
}

/*
Also here we assume there is no repetition of data.but if it were we should write
additional algorithm to find the location of the other
*/
void search(int data){
    struct node* temp;
    temp=start;
    int k=1;
    while(temp->next!=NULL){
        if(temp->data==data)
            break;
        temp=temp->next;
        k++;
    }
    if(temp->data==data){
        printf("\nthe data %d is found at location %d\n",data,k);
    }else{
        printf("\ndata %d does not exist in the linked list\n",data);
    }
}
void traverse(){
     struct node* temp;
     temp=start;
     if(temp==NULL){
        printf("linked list is empty!");
     }else{
         while(temp->next!=NULL){
        printf("%p %d\n",temp->next,temp->data);
        temp=temp->next;
     }
     printf("%p %d\n",temp->next,temp->data);
     }
}

int main()
{
    //case A:create linked list with the id of hagos
    create(825);
    //case B:add birhan's data before hagos's because it is less than hagos's
    insert_at_begining(297);
    //case C:add tsige's id at position 2
    insert_at_loc(2,406);
    //case D:add bahta's id at position 2
     insert_at_loc(2,331);
     //case E:remove birhan's which is 297
     remove_data(297);
     //case F:add tsedals's id at position 3
     insert_at_loc(3,527);
     //case G:add the ids of all the students at appropriate position
     insert_at_loc(4,544);
     add_at_end(963);
     insert_at_begining(201);
    //case H:remove selam's id
    remove_data(201);
    //case I:add hadgay's id at position 2
    insert_at_loc(2,390);
    traverse();
    search(78);
}

