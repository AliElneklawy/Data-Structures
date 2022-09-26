#include <stdio.h>
#include <stdlib.h>
#define MAX 5

short top = -1;   //-1 means the stack is empty
int stack_arr[MAX];                           /*SINCE WE ARE GOING TO USE top AND stack_arr HEAVILY, THEY ARE DECLARED GOLBALLY*/

int isFull()
{
    if(top == MAX-1){
        return 1;
    }
    else return 0;
}

int isEmpty()
{
    if(top == -1){
        return 1;
    }
    else return 0;
}

void push()
{

    system("cls");
    if(!isFull()){
        top = top + 1;
        printf(" Enter the data to be pushed: ");
        scanf("%d", &stack_arr[top]);
    }
    else
        printf("\nStack is full.\n");
}

void pop()
{
    if(!isEmpty()){
        stack_arr[top] = '\0';
        top -= 1;
    }
    else
        printf("\nStack is empty.\n");
}

void print_stack()
{
    for(int i = top; i >= 0;){
        printf("%d ", stack_arr[i--]);
    }
}

int main()
{
    int ch = 0, check = 0;
    while(1){
        printf("\n1. push\n2. pop\n3. print the stack contents\n4. exit\n   your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            print_stack();
            break;
        case 4:
            exit(1);
        default:
            system("cls");
            printf("\nPlease enter a valid value. \n");
        }
        //system("cls");
    }

}














