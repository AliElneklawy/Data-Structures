#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    struct node *link;
};
typedef struct node ls;

ls *create_ls();
ls *add_end(ls *, int *, int *);
int check_sort(ls *);

int main()
{
    int n, x;
    printf("How many nodes in the list? ");
    scanf("%d", &n);
    ls *head = create_ls();
    for(int i = 1; i < n; i++){
        head = add_end(head, &n, &i);
    }
    x = check_sort(head);

    if(x == 0){
        printf("\nNot sorted.");
    }else if(x == 1){
        printf("\nSorted in ascending order.");
    }else{
        printf("\nSorted in ascending order.");
    }
    return 0;
}

void print(ls *head)
{
    ls *trav = head;
    while(trav != NULL){
        printf("%d ", trav -> x);
        trav = trav -> link;
    }
}

ls *create_ls()
{
    ls *head = malloc(sizeof(ls));
    printf("Enter data of node 1: ");
    scanf("%d", &head -> x);
    head -> link = NULL;
    return head;
}

ls *add_end(ls *head, int *n, int *i)
{
    ls *ptr = malloc(sizeof(ls));
    ls *trav = head;
    int x;
    printf("Enter data of node %d: ", *i+1);
    scanf("%d", &x);
    while(trav -> link != NULL){
        trav = trav -> link;
    }
    trav -> link = ptr;
    ptr -> x = x;
    ptr -> link = NULL;
    ptr = NULL;
    return head;
}

int check_sort(ls *head)
{
    ls *trav = head;
    while(trav -> link != NULL)
    {
        if(trav -> x > trav -> link -> x){
            return 0;
        }
        trav = trav -> link;
    }
    return 1;
}





