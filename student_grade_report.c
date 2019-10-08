#include <stdio.h>
#include <stdlib.h>
/*
~~~By name: mekonnen hileslassie
                        id: mit/ur/1092/10
*/
struct result{
           char code[20] ;
           char grade;
       };

  struct Course_matrix{
           char code[20] ;
           char course_name[2][20] ;
           int credit;
       };

struct student{
       char id[20] ;
       char name[3][20];
       struct result re[2];
       struct Course_matrix c_m[2];

   };
   void get_data();
   void show_data(struct student* ptr);
int main()
{
get_data();
}
void get_data(){
    struct student std[3];
    for(int i=0;i<3;i++){
            printf("Please enter first name,last name,middle name and Id of the student %d\n",i+1);
            scanf("%s %s %s %s",std[i].name[0],std[i].name[1],std[i].name[2],std[i].id);
             for(int j=0;j<2;j++){
                 printf("Please enter curse_code %d and grade %d\n",j+1,j+1);
                 scanf("%s %c",std[i].re[j].code,&std[i].re[j].grade);
             }
             for(int k=0;k<2;k++){
                 printf("Please enter curse_code %d,course_name %d and credit of  course %d:\n",k+1,k+1,k+1);
                 //by convention take a course name with two words
                 scanf("%s %s %s %d",std[i].c_m[k].code,std[i].c_m[k].course_name[0],std[i].c_m[k].course_name[1],&std[i].c_m[k].credit);
             }
    }
    show_data(std);
}
void show_data(struct student* ptr){
     for(int i=0;i<3;i++){
            printf("\nName: %s %s %s \n  Id: %s",ptr->name[0],ptr->name[1],ptr->name[2],ptr->id);
             for(int j=0;j<2;j++){
                    if(j==0)
                    printf("\nCode                Grade \n");
                    printf("%s                 %c\n",ptr->re[j].code,ptr->re[j].grade);
             }
             for(int k=0;k<2;k++){
                     if(k==0){
                         printf("\nCourse matrix\n");
                         printf("Code                Course name               Credit ");
                     }
                     printf("\n%s                %s %s                  %d",ptr->c_m[k].code,ptr->c_m[k].course_name[0],ptr->c_m[k].course_name[1],ptr->c_m[k].credit);
             }
             printf("\n\n");
             ptr++;
    }
    free(ptr);//dynamic  memory allocation making free the pointer
}

