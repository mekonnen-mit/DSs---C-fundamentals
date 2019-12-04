#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    struct node* next;
};

struct node* id_card_front=NULL;
struct node* id_card_rear=NULL;

struct node* patient_treatment_front=NULL;
struct node* patient_treatment_rear=NULL;

struct node* laboratory_front=NULL;
struct node* laboratory_rear=NULL;

struct node* finance_front=NULL;
struct node* finance_rear=NULL;

struct node* dragStorage_front=NULL;
struct node* dragStorage_rear=NULL;

void push_at_rear(int id,struct node* temp,struct node** temp1){
    struct node* newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->id=id;
    newNode->next=NULL;
    if(temp==NULL){
        *temp1=newNode;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void pop_at_front(struct node* temp,struct node** temp1){
    if(temp==NULL){
        printf("underflow!");
    }else{
        int data=temp->id;
        if(temp==id_card_front){
            push_at_rear(data,patient_treatment_front,&patient_treatment_front);
        }else if(temp==patient_treatment_front){
            push_at_rear(data,laboratory_front,&laboratory_front);
        }else if(temp==laboratory_front){
            push_at_rear(data,finance_front,&finance_front);
        }else if(temp==finance_front){
            push_at_rear(data,dragStorage_front,&dragStorage_front);
        }
        *temp1=temp->next;
        temp->next=NULL;
        free(temp);
    }
}

int traverse(int i,struct node* temp){
        switch(i){
            case 0:
                if(temp==NULL){
                printf("Umm! ur queue is empty!\n\n");
                }else{
                    while(temp!=NULL){
                        printf("patient id:%d\nnext:%p\n\n",temp->id,temp->next);
                        temp=temp->next;
                    }
                }
                traverse(++i,patient_treatment_front);
                break;
            case 1:
                if(temp==NULL){
                printf("Umm! ur queue is empty!\n\n");
                }else{
                    while(temp!=NULL){
                        printf("patient id:%d\nnext:%p\n\n",temp->id,temp->next);
                        temp=temp->next;
                    }
                }
                traverse(++i,laboratory_front);
                break;
            case 2:
                if(temp==NULL){
                printf("Umm! ur queue is empty!\n\n");
                }else{
                    while(temp!=NULL){
                        printf("patient id:%d\nnext:%p\n\n",temp->id,temp->next);
                        temp=temp->next;
                    }
                }
                traverse(++i,finance_front);
                break;
            case 3:
                if(temp==NULL){
                printf("Umm! ur queue is empty!\n\n");
                }else{
                    while(temp!=NULL){
                        printf("patient id:%d\nnext:%p\n\n",temp->id,temp->next);
                        temp=temp->next;
                    }
                }
                traverse(++i,dragStorage_front);
                break;
            case 4:
                if(temp==NULL){
                printf("Umm! ur queue is empty!\n\n");
                }else{
                    while(temp!=NULL){
                        printf("patient id:%d\nnext:%p\n\n",temp->id,temp->next);
                        temp=temp->next;
                    }
                }
        }
        return (1);
}
int main()
{
    while(1){
     int chose;
     printf("what do u want to do?\n");
     printf("Enter!\n");
     printf("     1:To push new patient!\n");
     printf("     2:To pop patient from id card room!\n");
     printf("     3:To pop patient from patient treatment room!\n");
     printf("     4:To pop patient from laboratory room!\n");
     printf("     5:To pop patient from finance room!\n");
     printf("     6:To pop patient from drag storage room!\n");
     printf("     7:To traverse!\n");
     printf("     0:To exit!\n");
     scanf("%d",&chose);
     switch(chose){
         int data;
         case 1:
             printf("enter the id of the patient to push!\n");
             scanf("%d",&data);
             push_at_rear(data,id_card_front,&id_card_front);
             break;
         case 2:
            pop_at_front(id_card_front,&id_card_front);
            break;
        case 3:
            pop_at_front(patient_treatment_front,&patient_treatment_front);
            break;
        case 4:
            pop_at_front(laboratory_front,&laboratory_front);
            break;
        case 5:
            pop_at_front(finance_front,&finance_front);
            break;
        case 6:
            pop_at_front(dragStorage_front,&dragStorage_front);
            break;
        case 7:
            traverse(0,id_card_front);
            break;
        case 0:
            exit(1);
        default:
            printf("please enter correct value!\n\n");
     }
   }

}
