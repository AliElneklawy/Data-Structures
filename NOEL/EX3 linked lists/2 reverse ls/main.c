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
ls *reverse(ls *);

int main()
{
    int n, x;
    printf("How many nodes in the list? ");
    scanf("%d", &n);
    ls *head = create_ls();
    for(int i = 1; i < n; i++){
        head = add_end(head, &n, &i);
    }

    head = reverse(head);
    print(head);    //reversed
    /*x = check_sort(head);

    if(x == 0){
        printf("\nNot sorted.");
    }else if(x == 1){
        printf("\nSorted in ascending order.");
    }else{
        printf("\nSorted in ascending order.");
    }*/
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

/*int check_sort(ls *head)
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
}*/

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

/*head -> link = prev;
        prev = head;
        next = next -> link;
        head = next;
        printf("%d\n", prev -> x);*/



