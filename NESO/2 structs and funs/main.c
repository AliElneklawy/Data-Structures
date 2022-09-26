#include <stdio.h>
#include <stdlib.h>

/*typedef struct{

    int x;
    int y;
}ex;

void print(ex p)
{
    printf("%d  %d  ", p.x, p.y);
}

int main()
{
    ex p1, p2;    //declaring p1 and p2 of type "ex"
    p1.x = 10;      //assigning values to the members of the structure
    p1.y = 20;
    p2.x = 30;
    p2.y = 40;
    print(p1);      //passing the structure variable p1 and p2 to the function print
    print(p2);
}
/* when we have a very large structure, it is always a good practice to pass the address of the structure not the entire structure. for example:

void print(ex *p)     //receiving the address of p1 and storing it in a pointer to datatype 'ex'. p is a pointer to structure
{
    printf("%d  %d  ", p->x, p->y);     //accessing the member of the structure by the pointer to structure p
}

int main()
{
    ex p1, p2;
    p1.x = 10;
    p1.y = 20;
    p2.x = 30;
    p2.y = 40;
    print(&p1);   here we are passing the address of p1 to the function
    print(&p2);
}
*/

/*--------------------------------------------ARRAY OF STRUCTS--------------------------------------------------------------*/

typedef struct{

    int x;
    char y;
} test;

void print(test arr[], int* n)      //arr is an array of tests, so it is received in an array arr of type test
{
    for(int i = 0; i<*n; i++){
        printf("%d%c  ", arr[i].x, arr[i].y);
    }
}

int main()
{
    int n,x1,y1,i;
    printf("How many elements in the array? ");
    scanf("%d", &n);
    test arr[n];    //array of tests (just like array of integers)
    for(i = 0; i < n; i++){
        printf("Enter a number: ");
        scanf("%d", &x1);
        arr[i].x = x1;
        fflush(stdin);
        printf("Enter a charachter: ");
        scanf("%c", &y1);
        arr[i].y = y1;
    }

    print(arr, &n);     //passing the address of n since n is local to the main function
    //test arr[2] = {{1, 'A'}, {2, 'B'}};

}























