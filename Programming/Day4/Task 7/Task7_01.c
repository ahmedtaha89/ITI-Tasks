#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student{
int code;
char name [50] ;
char gender [10] ;
int age;
};
void main(void) {

struct student s[2];


for(int i=0;i<2;i++)
{
    printf("Enter your code : \n");
    scanf("%d",&s[i].code);
    printf("Enter your name : \n");
    scanf("%s",s[i].name);
    printf("Enter your gender \n");
    scanf("%s",s[i].gender);
    printf("Enter your age \n");
    scanf("%d",&s[i].age);


}

for(int i=0;i<2;i++)
{
    if(s[i].age>s[i+1].age)
    {
        printf("The eldest student information are \n Code \t Name \t Gender \t Age \n %d \t %s \t %s \t %d",s[i].code,s[i].name,s[i].gender,s[i].age);
        break;
    }
    else
    {
        printf("The eldest student information are \n Code \t Name \t Gender \t Age \n %d \t %s \t %s \t %d",s[i+1].code,s[i+1].name,s[i+1].gender,s[i+1].age);
        break;
    }
}



}

