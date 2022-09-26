#include <stdio.h>
#include <stdlib.h>
#define IntMax 2147483647

struct node
{
    int x;
    struct node *link;
};
typedef struct node ls;

ls *create_ls(int *);
ls *add_end(ls *, int *);
ls *reverse(ls *);
void dec2bin(int );

int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if (n==0){
        printf("\nThe binary equivalent is: 0\n");
        exit(1);
    }
    dec2bin(n);
    printf("\n");
    return 0;
}

void dec2bin(int n)
{
    int i = 0, rem;
    ls *trav = NULL, *head = NULL;
    while(n != 0){
        rem = n%2;
        if(i == 0){
           head = create_ls(&rem);
           trav = head;
           i = 1;
        }
        else{
            head = add_end(head, &rem);
        }
        n = n/2;
    }
    head = reverse(head);
    print(head);
}

void print(ls *head)
{
    ls *trav = head;
    printf("\nThe decimal equivalent is: ");
    while(trav != NULL){
        printf("%d", trav -> x);
        trav = trav -> link;
    }
}

ls *create_ls(int *rem)
{
    ls *head = malloc(sizeof(ls));
    head -> x = *rem;
    head -> link = NULL;
    return head;
}

ls *add_end(ls *head, int *n)
{
    ls *ptr = malloc(sizeof(ls));
    ls *trav = head;
    while(trav -> link != NULL){
        trav = trav -> link;
    }
    trav -> link = ptr;
    ptr -> x = *n;
    ptr -> link = NULL;
    ptr = NULL;
    return head;
}

ls *reverse(ls *head)
{
    ls *prev = head, *next = head -> link;

    short i = 1;
    while(1){
        if(next == NULL){
            prev = NULL;
            break;
        }
        if(i == 1){
            prev -> link = NULL;
            i = 0;
        }
        head = next;
        next = next -> link;
        head -> link = prev;
        prev = head;
    }
    return head;

}

