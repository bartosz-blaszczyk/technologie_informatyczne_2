#include <stdio.h>

void printvariables(const int *ptr1 , const int *ptr2) {
       printf("*ptr1 = %d\n", *ptr1);
       printf("*ptr2 = %d\n", *ptr2);


}

// void swap (int a, int b) {
//     printf("\ta = %d\n", a);
//     printf("\tb = %d\n", b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("\ta = %d\n", a);
//     printf("\tb = %d\n", b);

// }
void swap (int *ptr1 , int *ptr2) {
       printf("\t*ptr1 = %d\n", *ptr1);
       printf("\t*ptr2 = %d\n", *ptr2);
       int temp = *ptr1;
       *ptr1 = *ptr2;
       *ptr2 = temp;
       printf("\t*ptr1 = %d\n", *ptr1);
       printf("\t*ptr2 = %d\n", *ptr2);
}
int main() {
       int a = 2;
       int b = 5;
       printf("\ta = %d\n", a);
       printf("\tb = %d\n", b);
       swap (&a, &b);
       printf("\ta = %d\n", a);
       printf("\tb = %d\n", b);


       // int a = 2;
       // int b = 5;
       // printf("a = %d\n", a);
       // printf("b = %d\n", b);
       // swap (a, b);
       // printf("a = %d\n", a);
       // printf("b = %d\n", b);
       //
       // printvariables(a, b);

       return 0;
}