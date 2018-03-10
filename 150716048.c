#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
int id;
char name[20];
struct person* next;

};

typedef struct person Person;

void Read(Person *headPtr);
void printOdd(Person* headPtr);
void printEven(Person* headPtr);
void printPrime(Person* headPtr);

int main() {


Person* head;
head = malloc(sizeof(Person));


int input;
char ch[20];

Read(head);

printf("1) For odd names:\n");
printf("2) For even names:\n");
printf("3) For prime names:\n");

while(1)
{
    printf("\nEnter a number: ");
    scanf("%d", &input);

    if(input == 1) {
        printOdd(head);
    }else if(input == 2) {
        printEven(head);
    }else if(input == 3) {
        printPrime(head);
    }
}

return 0;
}

void printOdd(Person* headPtr) {
    Person* iter;
    iter = headPtr;

    while(iter != NULL) {
        if((iter->id)%2 == 1)
        {
            printf("\n%d %s", iter->id, iter->name);
        }
        iter = iter->next;

    }

}
void Read(Person *headPtr)
{
    FILE *dosya = fopen("names.txt","r");

    int num, count=0; char ch[25];
    Person *iter;
    iter = headPtr;

    while(!feof(dosya))
    {
        fscanf(dosya,"%d %s", &num, ch);
        iter->id = num;
        strcpy(iter->name, ch);
        iter->next = malloc(sizeof(Person));
        iter = iter->next;
        count++;
            if(count==100) {
                iter->next = NULL;
            }

    }
    fclose(dosya);
}
void printEven(Person* headPtr) {
    Person* iter;
    iter = headPtr;

    while(iter != NULL) {
        if((iter->id)%2 == 0)
        {
            printf("\n%d %s", iter->id, iter->name);
        }
        iter = iter->next;

    }

}
void printPrime(Person* headPtr) {
    Person* iter;
    iter = headPtr;

    int i, count, controller;

    for(i=1; i<=100; i++){
        controller=1;
        for(count=2; count<i; count++){
            if(i%count == 0){
            controller=0;
            break;
            }
        }
        if(i!=1 && controller==1){
            printf("\n%d\t%s",i, iter->name);
            iter = iter->next;
        }
    }
        count=2;

}

