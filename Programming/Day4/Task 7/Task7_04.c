#include <stdio.h>
#include <stdlib.h>
struct student{
int roll_no;
char name [10] ;
int age;
};

void print_age(struct student *s[100],int age,int size);
void print_roll(struct student  *s[100],int roll_num,int size);


void main(void) {

struct student *s[100];
int size;
int age;
int roll;

printf("Enter how many students you want to add \n");
scanf("%d",&size);

for(int i=0;i<size;i++)
{
    s[i]=(struct student *)malloc(sizeof(struct student));
    printf("Enter your Roll Number : \n");
    scanf("%d", &s[i]->roll_no);
    printf("Enter your name : \n");
    scanf("%s", s[i]->name);
    printf("Enter your age \n");
    scanf("%d", &s[i]->age);

}

    printf("Enter the specified age \n");
    scanf("%d",&age);
    printf("The Data less than this age are : \n");
    print_age(s,age,size);


    printf("\n Enter specified roll number \n");
    scanf("%d",&roll);
    printf("The Data less than this Roll number are : \n");
    print_roll(s,roll,size);

}

void print_age(struct student *s[100],int age,int size){

    for(int i=0;i<size;i++)
    {
        if(s[i]->age < age)
        {
           printf("%d \t %s \t %d \n",s[i]->roll_no,s[i]->name,s[i]->age);
        }
    }

}

void print_roll(struct student *s[100],int roll_num,int size){

    for(int i=0;i<size;i++)
    {
        if(s[i]->roll_no < roll_num)
        {
           printf("%d \t %s \t %d \n",s[i]->roll_no,s[i]->name,s[i]->age);
        }
    }


}
