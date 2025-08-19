#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;

};
struct node *top;
void push(int value);
void pop();
void print_stack();
void main(void)
{
    int val;

    for(int i=0;i<3;i++)
    {
        printf("Enter the value \n");
        scanf("%d",&val);
        push(val);
    }

print_stack();
push(50);
print_stack();

pop();
pop();
print_stack();
pop();
pop();
pop();
print_stack();


}
void push(int value){

struct node *ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
    printf("There is no memory allocated \n");
else{
    ptr->data=value;
    ptr->next=top;
    top=ptr;
    }


}
void pop(){

if(top==NULL)
printf("The Stack is empty \n");
else
{
    struct node *temp = top;
    printf("The poped value is %d \n",temp->data);
    top=top->next;
    free(temp);


}




}
void print_stack() {
    struct node *ptr = top;
    if (ptr == NULL) {
        printf("The Stack is empty.\n");
        return;
    }
    printf("Stack values:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}


