#include <stdio.h>
#include <stdlib.h>

            /*----------------CREATING A LINKED LIST------------------------------*/
struct node{
    int x;
    struct node *link;
};
typedef struct node LS;

void insert_end(LS *top);
void insert_beg(LS *top);
void insert_mid(LS *top);
void del_end(LS *top);
void check_alloc(LS *check);

void check_alloc(LS *check)     //make sure that the memory is aloocated
{
    if(check == NULL){
        perror("Memory not allocated");
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    LS *top = malloc(sizeof(LS));       //top pointer must be fixed so that you always have access to the first node hence to the entire list.
    check_alloc(top);
    LS *cur2 = NULL;
    LS *trav = top;
    printf("Enter data of node 1: ");
    scanf("%d", &top->x);
    top -> link = NULL;
    LS *cur1 = malloc(sizeof(LS));
    printf("Enter data of node 2: ");
    scanf("%d", &cur1->x);
    top -> link = cur1;
    cur1 -> link = NULL;
   // printf("%d", cur1 -> x);

    for(i = 2; i < n;){     //inserting data to the nodes
        cur2 = malloc(sizeof(LS));
        cur1 -> link = cur2;
        printf("Enter data of node %d: ", ++i);
        scanf("%d", &cur2 -> x);
        cur2 -> link = NULL;
        cur1 = cur2;
    }
    cur1 -> link = NULL;
    i = 1;
    system("cls");
    while(trav != NULL){        //printing the data of the linked list
        printf("data of node %d: ", i++);
        printf("%d\n", trav -> x);
        trav = trav -> link;
    }
    printf("\nTotal %d nodes in the list.\n", --i);

    printf("\n\nDo you want to insert an additional node? ");
    printf("\n1- YES\n2- NO\n   YOUR CHOICE: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("\n Insert the node at the:\n  1- END\n  2- BEGINNING\n  3- MIDDLE");
            printf("   \nYOUR CHOICE: ");
            scanf("%d", &i);
            switch (i){
                case 1:
                    insert_end(top);
                    break;
                case 2:
                    insert_beg(top);
                    break;
                case 3:
                    insert_mid(top);
                    break;
                }
            break;
        case 2:
            break;
    }

    printf("\nDo you want to delete a node? ");
    scanf("%d", &n);
    if (n == 1){
        system("cls");
        printf("\n Delete the node at the:\n  1- END\n  2- BEGINNING\n  3- MIDDLE\n  4- ALL");
        scanf("%d", &i);
        if(i == 1){     //delete the first node
            del_end(top);
        }
        else if(i == 2){
            del_beg(top);
        }
        else if (i == 4)
            del_all(top);
        else    del_mid(top);
    }
    free(top); top = NULL;
    free(cur1); cur1 = NULL;
    free(cur2); cur2 = NULL;

    return 0;
}


  /*-----------------PRINTING THE DATA OF THE LINKED LIST----------------------------*/
void print(LS *top)
{
    LS *pr = top;
    while(pr != NULL){
        printf("%d  ", pr -> x);
        pr = pr -> link;
    }
}

    /*-----------------------------------------inserting at the end----------------------*/
void insert_end(LS *top)
{
    LS *in = malloc(sizeof(LS));
    check_alloc(in);
    LS *kp = top;
    int n;
    //printf("%d", kp ->x);     //testing
    printf("Enter the data of the new node: ");
    scanf("%d", &n);
    while (kp -> link != NULL){
        //kp1 = kp;
        kp = kp -> link;
    }
    kp -> link = in;
    kp = kp -> link;
    kp -> x = n;
    kp -> link = NULL;
    //printf("ALI");        //testing
    print(top);
    free(in);  in = NULL;
}
/*-------------------------------------INSERTING AT THE BEGINNING---------------------------*/

void insert_beg(LS *top)
{
    int n;
    LS *beg = malloc(sizeof(LS));
    check_alloc(beg);
    printf("Enter the data of the new node: ");
    scanf("%d", &n);
    beg -> link = top;
    beg -> x = n;
    top = beg;
    print(top);
    free(beg);  beg = NULL;
}

/*-------------------------------------INSERTING AT THE MIDDLE------------------------------*/

void insert_mid(LS *top)
{
    LS *mid = malloc(sizeof(LS));
    LS *trav = top;
    int n, node;
    printf("Insert the new node at node number: ");
    scanf("%d", &node);
    if (node == 1){
        insert_beg(top);
    }
    else {
        printf("Enter the data of the new node: ");
        scanf("%d", &n);
        mid -> x = n;
        mid -> link = NULL;
        for(int i = 1; i < node-1; i++){
            trav = trav -> link;
        }
        //printf("%d\n", trav -> x);    //testing that the pointer is at the right node
        mid -> link = trav -> link;
        trav -> link = mid;

        print(top);
        free(mid);  mid = NULL;
    }
}

/*-------------------------------DELETE THE LAST NODE---------------------------------*/

void del_end(LS *top)
{
    LS *trav = top;     //trav used to traverse the list
    LS *del = NULL;
    while(trav -> link != NULL){
        del = trav;     // del will point to the node before the last one
        trav = trav -> link;
    }
    del -> link = NULL;
    free(trav);
    trav = NULL;
    print(top);
}

/*-------------------------------DELETE THE FIRST NODE---------------------------------*/

void del_beg(LS *top)
{
    LS *beg = top;
    top = top -> link;
    beg -> link = NULL;
    free(beg);
    beg = NULL;
    print(top);
}

/*-------------------------------DELETE A NODE IN THE MIDDLE---------------------------------*/

void del_mid(LS *top)
{
    int n;
    LS *trav = top;
    LS *kp = NULL;
    printf("Enter the number of the node to be deleted: ");
    scanf("%d", &n);
    for(int i=1;i<n-1;i++){
        trav = trav -> link;
    }
    kp = trav -> link;
    trav -> link = kp -> link;
    kp -> link = NULL;
    free(kp);
    //trav -> link -> link = NULL;
    print(top);

}

/*-------------------------------DELETING THE ENTIRE LIST---------------------------------*/

void del_all(LS *top)
{
    LS *kp = top;
    while (kp != NULL){
        top = top -> link;
        free(kp);
        kp = top;
    }
    //kp = NULL;
    //top = NULL;
    return;
}















