#include <stdio.h>
#include <stdlib.h>

                /*-----CREATING DOUBLY LINKED LIST----------*/

struct node
{
    struct node *prev;
    int x;
    struct node *next;
};
typedef struct node ls;

ls *create_ls();
ls* add_end(ls *, int *, int *);
ls *del(ls *, ls *, int *, int *);
ls *add(ls *, ls *, int *, int *);
void print(ls *);

int main()
{
    int n, data;
    unsigned short ch;
    ls *trav = 0;
    printf("How many nodes in the list? ");
    scanf("%d", &n);
    ls *head = create_ls();
    for(int i = 1; i < n; i++){
        printf("enter data of node %d: ", i+1);
        scanf("%d", &data);
        head = add_end(head, &data, &i);
    }
    print(head);

    printf("\n1- Delete a node\n2-Add a node\n  YOUR CHOICE: ");
    scanf("%d", &ch);
    if(ch==1){
        printf("\nEnter the number of the node to be deleted: ");
        scanf("%d", &data);
        head = del(head, trav, &data, &n);
    }
    else if(ch == 2){
        printf("\nAdd the new node after node number: ");
        scanf("%d", &data);
        head = add(head, trav, &data, &n);
    }
    print(head);
    free(head); head = NULL;
}

ls *create_ls()     //create the first node
{
    int n;
    ls *head = malloc(sizeof(ls));
    check_alloc(head);      //check whether the memory is allocated
    printf("enter data of node 1: ");
    scanf("%d", &n);
    head -> prev = NULL;
    head -> next = NULL;
    head -> x = n;

    return head;
}

ls *add_end(ls *head, int *n, int *i)  //attaching nodes at the end
{
    ls *trav = head;
    ls *ptr = malloc(sizeof(ls));
    check_alloc(ptr);
    if(*i == 1)
        trav = head;
    else{
        while(trav -> next != NULL){    //go to the end of the list
            trav = trav -> next;
        }
    }

    trav -> next = ptr;
    ptr -> prev = trav;
    ptr -> next = NULL;
    ptr -> x = *n;

    return head;
}

ls *del(ls *head, ls* trav, int *node, int *n)      // "node": number of node to be deleted. "n" number of nodes
{
    trav = head;
    if(*node == 1){     //delete the first node
        head = head -> next;
        head -> prev -> next = NULL;
        free(head -> prev);
    }
    else if(*node == *n){   //delete the last node
        while(trav -> next -> next != NULL){
            trav = trav -> next;
        }
        trav -> next -> prev = NULL;
        free(trav -> next);
        trav -> next = NULL;
    }
    else{
        *node = (*node) - 1;
        while((*node)--){
            trav = trav -> next;
        }
        trav -> prev -> next = trav -> next;
        trav -> next -> prev = trav -> prev;
        trav -> next = NULL;
        trav -> prev = NULL;
        free(trav);
        trav = NULL;
    }
    return head;

}

ls *add(ls *head, ls *trav, int *node, int *n)
{
    trav = head;
    ls *ptr = NULL;
    int data;

    if(*node == 0){
        head = create_ls();
        trav -> prev = head;
        head -> next = trav;
    }
    else if(*node == *n){
        printf("\nEnter the data of the new node: ");
        scanf("%d", &data);
        head = add_end(head, &data, &n);        //the third argument is any number other than 1
    }
    else{

        *node = (*node) - 1;
        while((*node)--){
            trav = trav -> next;
        }
        ptr = create_ls();
        ptr -> next = trav -> next;
        trav -> next -> prev = ptr;
        trav -> next = ptr;
        ptr -> prev = trav;
    }

    return head;
}


void check_alloc(ls *head)
{
    if (head == NULL){
        perror("Memory not allocated");
        exit(-1);
    }
}

void print(ls *head)
{
    ls *trav = head;
    while(trav != NULL){
        printf("%d ", trav -> x);
        trav = trav -> next;
    }
}

