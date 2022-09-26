#include <stdio.h>
#include <stdlib.h>

    /*-----------REVERSING THE ORDER OF A LINKED LIST------------*/

struct node
{
   int x;
   struct node *link;
};
typedef struct node ls;

ls *create_ls(void);
ls *revers(ls *);

int main()
{
    ls *top = NULL;
    top = create_ls();
    top = revers(top);
}

ls *create_ls()
{
    int n = 0, i = 0, k = 0;
    ls *top = NULL, *cur = NULL, *cur1 = NULL, *trav = NULL;
    top = malloc(sizeof(ls));
    cur = malloc(sizeof(ls));
    trav = top;
    printf("Enter the number of nodes: ");
    scanf("%d" , &n);
    printf("Enter data of node 1: ");
    scanf("%d" , &k);
    top -> x = k;
    top -> link = NULL;
    printf("Enter data of node 2: ");
    scanf("%d" , &k);
    cur -> x = k;
    top -> link = cur;
    cur -> link = NULL;

    for(i=2; i<n; i++){
        cur1 = malloc(sizeof(ls));
        cur -> link = cur1;
        printf("Enter data of node %d: ", i+1);
        scanf("%d" , &cur1 -> x);
        cur1 -> link = NULL;
        cur = cur1;
    }
    cur -> link = NULL;

    print(top);

    return top;
}

ls *revers(ls *top)        //reverse the order
{


}


void print(ls *top)
{
    ls *trav = top;
    while (trav != NULL){
        printf("%d ", trav -> x);
        trav = trav -> link;
    }
}




















