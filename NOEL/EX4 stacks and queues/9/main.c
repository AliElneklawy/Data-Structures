#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int i = 0;

struct node
{
    char x;
    struct node *next;
    struct node *prev;
};
typedef struct node ls;
ls *head = NULL;

int calc(char b, char a, char op)
{
    int res = 0;
    int x = a - '0';    //convert char to to int
    int y = b - '0';
    switch(op){
    case '+':
        res = x + y;
        break;
    case '*':
        res = x * y;
        break;
    case '-':
        res = x - y;
        break;
    case '/':
        res = x/y;
        break;
    case '^':
        res = pow(x, y);
        break;
    }
    push(res + '0');    //push res as  a charachter
    return res;
}

void eval_postfix()
{
    system("cls");
    int res;
    char exp[100];
    char ints[4];
    int j = 0;
    int num;
    int nonBlanks = 0;
    fflush(stdin);
    printf("Enter a postfix expression: ");
    gets(exp);
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] != ' '){
            //int num = exp[i] - '0';
            ints[j] = exp[i];
            j++;
        }
        else{
            j = 0;
            while(ints[j+1] != '\0'){
                ints[0] = strcat(ints[0], ints[++j]);
            }
        }
        num = ints[0] - '0';
    }
    printf("%d", num);

        /*else if((exp[i] >= 48) && (exp[i] <= 57)){     //if an operand is encountered
            push(exp[i]);
            j=0;
        }
        else{       //if an operator is encountered
            char b = pop();
            char a = pop();
            res = calc(b, a, exp[i]);
            j=0;
        }
    }
    printf("%d", res);
    memset(exp, 0,sizeof(exp));     //clear the array for other operations*/

}

void inToPos()
{

    printf("Enter the infix expression: ");

}

ls *add_end(char data, ls* head)
{
    ls *ptr = malloc(sizeof(ls));
    ptr -> x = data;
    ptr -> next = NULL;
    ptr -> prev = head;
    head = ptr;
    return head;
}

ls *create_ls(char data, ls *head)
{
    head = malloc(sizeof(ls));
    head -> x = data;
    head -> prev = NULL;
    head -> next = NULL;
    return head;
}

void push(char data)
{
    if(i == 0){
        head = create_ls(data, head);
        ++i;
    }
    else{
        head = add_end(data, head);
    }
}

int pop()
{
    int p = head -> x;
    ls *del = head;
    head = head -> prev;
    free(del);  del = NULL;
    return p;
}

int main()
{
    int ch = 1;

    while(ch == 1)
    {
        inToPos();
        //eval_postfix();
        printf("\nTry another expression? ");
        scanf("%d", &ch);
    }

}
