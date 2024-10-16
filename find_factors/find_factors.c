#include "array.c"
#include<stdio.h>


int *find_factors(int number) {
    static Array factor_list;
    initArray(&factor_list, 4);
    int n_factors = 0;
    for (int i=2; i<=number; i++) {
        if ((number % i) == 0) {
            n_factors += 1;
            insertArray(&factor_list, i);
        }
        printf("%d ", i);
    }
    return factor_list.array;
}
