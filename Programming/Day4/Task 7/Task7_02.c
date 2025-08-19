#include <stdio.h>
#include <stdlib.h>
struct student{
char id_num[5];
char name [10] ;
char gender;
int age;
};
void main(void) {

struct student *s[100];
int size;
int total;

printf("Enter how many students you want to add \n");
scanf("%d",&size);

for(int i=0;i<size;i++)
{
    s[i]=(struct student *)malloc(sizeof(struct student));
    printf("Enter your ID : \n");
    scanf("%s", s[i]->id_num);
    printf("Enter your name : \n");
    scanf("%s", s[i]->name);
    printf("Enter your gender (M - F) \n");
    scanf(" %c", &s[i]->gender);
    printf("Enter your age \n");
    scanf("%d", &s[i]->age);

}

printf("The Students information are \n ID \t Name \t Gender \t Age \n");
for(int i=0;i<size;i++)
    {
        printf("%s \t %s \t       %c \t %d \n",s[i]->id_num,s[i]->name,s[i]->gender,s[i]->age);
    }


total= sizeof(struct student);
printf("Size of one student struct = %d bytes\n",total);
total*=20;
printf("The whole size of the students = %d bytes \n",total);

}

