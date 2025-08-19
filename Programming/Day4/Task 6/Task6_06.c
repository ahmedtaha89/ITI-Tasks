#include <stdio.h>
#include <stdlib.h>
void main(void)
{
    char * name1;
    int size1;
    char * name2;
    int size2;
    char * name3;

    printf("Enter the size of your first name \n");
    scanf("%d",&size1);


    name1 = (char *) malloc (size1* sizeof(char));

    printf("Enter your first name \n ");

        scanf("%s",name1);


    printf("Enter the size of your last name \n");
    scanf("%d",&size2);

    name2 = (char *) malloc (size2* sizeof(char));

        printf("Enter your last name \n ");
        scanf("%s",name2);

      //  printf("Your first name is %s ",name1);

    name3= (char *) malloc ((size1+size2+1)*sizeof(char));


    for(int i=0;i<size1;i++)
    {
        name3[i]=name1[i];
    }

    for(int j=0;j<size2;j++){
        name3[j+size1]=name2[j];
    }

    name3[size1 + size2] = '\0';
    printf("Your full name is %s ",name3);

}


