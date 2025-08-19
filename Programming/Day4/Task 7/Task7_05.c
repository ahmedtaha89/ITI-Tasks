#include <stdio.h>
#include <stdlib.h>
struct Customer{
char name[32];
int account_no;
int balance;

};
void printnames(struct Customer *customers[100],int balance,int size);
void increment_balance(struct Customer *customers[100],int balance,int size);
int main() {

struct Customer *customers[100];
int size;
int balance;


printf("Enter the number of the customers \n");
scanf("%d",&size);

        for(int i=0;i<size;i++)
        {
            customers[i]=(struct Customer *)malloc(sizeof(struct Customer));
            printf("Enter your name \n");
            scanf("%s",customers[i]->name);
            printf("Enter the account number \n");
            scanf("%d",&customers[i]->account_no);
            printf("Enter the balance \n");
            scanf("%d",&customers[i]->balance);


        }
printf("The names of customers that have balance less than 200$ are : \n");

printnames(customers,balance,size);
printf("===================================================");
increment_balance(customers,balance,size);



    }

void printnames(struct Customer *customers[100],int balance,int size){

    for(int i=0;i<size;i++)
    {
        if(customers[i]->balance<200)
            printf(" %s \n",customers[i]->name);

    }


}

void increment_balance(struct Customer *customers[100],int balance,int size){

for(int i=0;i<size;i++)
    {
        if(customers[i]->balance>1000){
            customers[i]->balance+=100;
            printf(" %s \t Salary after being updated : %d \n",customers[i]->name,customers[i]->balance);

        }

    }


}

