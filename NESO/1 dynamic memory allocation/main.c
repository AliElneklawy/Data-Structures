#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, i, ch;
    printf("Enter the number of integers: ");
    scanf("%d", &n1);
    int* ptr = (int*)calloc(n1, sizeof(int));    //malloc(n * sizeof(int)) is an equivalent
    //malloc and calloc return the address of the first byte of the allocated memory and it is stored in ptr
    //malloc and calloc return NULL if the memory is not allocated
    if (ptr == NULL){
        printf("Memory couldn't be allocated");
        exit(1);
    }
    //system("cls");
    for(i =0; i<n1; i++){
        printf("ENTER THE NUMBER: ");
        scanf("%d", ptr+i);     //ptr already contains the address so & is not needed
    }
   // system("cls");


    //suppose now that the user decided to add more integers. Obviously more memort must be allocated. This can be achieved using realloc function
    printf("do you want to add more integers? ");
    scanf("%d", &ch);   //notice here that & is needed to store the data entered by the user in the address of ch
    if(ch == 1){
        printf("Enter the new total number of integers: ");
        scanf("%d", &n2);
        ptr = (int*)realloc(ptr, n2*sizeof(int));  /*reallocate the size of the allocated memory pointed by ptr to n2 instaed of n1
                                                        to add (n2 - n1) more integers*/

                                                        /*the size of the reallocated memory must be greater than the previously allocated memort
                                                        otherwise, previously stored data will get lost. we want to reallocate the memory pointed by
                                                        ptr, so ptr is the firts argument */
        if(ptr == NULL){
            printf("Memory not allocated");
            for (i =0; i<n1; i++)
                printf("%d  ", *(ptr+i));
            exit(1);
        }
        for (i = n1; i<n2;i++){         /*add the new data to the memory location starting from n1 not 0 so that the old data don't get overwritten*/
            printf("enter the number: ");
            scanf("%d", ptr + i);
        }
        for (i =0; i<n2; i++)
            printf("%d  ", *(ptr+i));
    }
    else {
        for (i =0; i<n1; i++)
        printf("%d  ", *(ptr+i));
    }

    free(ptr);      //deallocating the memory. But the pointer is still containing the address of the allocated memory which is invalid
    ptr = NULL;     //assigning ptr to null so it is not dangling anymore
}
