#include "find_factors.c"
#include<stdio.h>

int main() {
    int *factors = find_factors(20);
    printf("%d", sizeof(factors) / sizeof(factors[0]));
    // int number = 20;
    // int factor_list[6] = {1};
    // int n_factors = 0;
    // // printf("%d\n", 20);
    // int i;
    // for (i=2; i<=20; i++) {
    //     if ((number % i) == 0) {
    //         n_factors += 1;
    //         factor_list[n_factors] = i;
    //         printf("%d\n", i);
    //     }
    //     // printf("%d ", i);
    //     // printf("\n");
    // }
    // int *factors = factor_list;
    printf("%d\n", sizeof(factors) / sizeof(factors[0]));
    for (int i=0; i<sizeof(factors); i++) {
        printf("%d ", factors[i]);
    }
}