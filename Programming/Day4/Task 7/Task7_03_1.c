#include<stdio.h>
#define MAX 5
int top=-1;
int data[MAX];
void push(int val);
int pop();
int isFull();
int isEmpty();
void print();
void main(void)
{
    int val;

    for(int i=0;i<3;i++)
    {
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
    push(26);
    print();
    push(27);
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
    data[top]=val;
    }

}

int pop(){
if(isEmpty())
    printf("The stack is empty you cannot retrieve any value from it \n");
else{
    int temp;
    temp=top;
    top--;
    return data[temp];
}

}
void print()
{
    printf("The data in stack is : \n");
    for(int i=top;i>=0;i--)
        printf("%d\n",data[i]);
}
