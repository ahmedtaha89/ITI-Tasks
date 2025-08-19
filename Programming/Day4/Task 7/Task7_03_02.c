#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
int *data[MAX];
void push(int val);
int pop();
int isFull();
int isEmpty();
void print();
void main(void)
{
    int val;
    int size;

    printf("Enter the number of values you wanna add \n");
    scanf("%d",&size);


    for(int i=0;i<size;i++)
    {
        data[i]=(int *)malloc(sizeof(int));
        printf("Enter the value \n");
        scanf("%d",&val);
        push(val);
    }
    print();
    pop();
    print();
    push(11);
    print();
    push(12);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    pop();
    pop();
    pop();
}

int isFull(){
 if(top==MAX-1)
    return 1;
    else
    return 0;
}

int isEmpty(){
if(top==-1)
    return 1;
else
    return 0;
}

void push(int val){
if(isFull())
    printf("The stack is full and cannot add more values %d \n",val);
else{
    top++;
    data[top] = (int *)malloc(sizeof(int));
    *data[top] = val;

    }

}

int pop(){
if(isEmpty())
    printf("The stack is empty you cannot retrieve any value from it \n");
else{
       int val = *data[top];
        free(data[top]);
        top--;
        return val;
}

}
void print()
{
    printf("The data in stack is : \n");
    for(int i=top;i>=0;i--)
        printf("%d\n",*data[i]);
}
