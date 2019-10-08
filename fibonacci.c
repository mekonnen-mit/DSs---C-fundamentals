#include <stdio.h>
#include <stdlib.h>

/*
~~~By name: mekonnen hileslassie
                        id: mit/ur/1092/10
*/
void fibonacci1(int n);
void fibonacci2(int* ptr);
int main()
{
   int n;
   printf("please enter the maximum(ceiling) number n\n");
   scanf("%d",&n);
   fibonacci1(n);//this is calling by value
   fibonacci2(&n);//this is calling by reference
   return 0;
}
void fibonacci1(int n){
    int x=0,y=1,z;
    while(x<=n){
            printf("%d  ",x);
            z=x+y;
            x=y;
            y=z;
   }
}
void fibonacci2(int* ptr){
    int x=0,y=1,z;
    printf("\n");
    while(x<=*ptr){
            printf("%d  ",x);
            z=x+y;
            x=y;
            y=z;
   }
}


