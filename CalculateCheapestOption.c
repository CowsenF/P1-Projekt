#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>


int cmpfunc (const void * a, const void * b) {

    final_stores *storeA = (final_stores *)a;
    final_stores *storeB = (final_stores *)b;

    int sum_storeA = 0;
    int sum_storeB = 0;

    //The price of each item is compared to get the best store
    for (int i = 0; i < sizeof(storeA->finalItems)/sizeof(storeA->finalItems[0]); ++i) {
        sum_storeA += storeA->finalItems[i].price;
        sum_storeB += storeB->finalItems[i].price;
    }

    return (sum_storeB - sum_storeA);
}

//Get an ordered list of stores
best_stores get_list_of_best_stores(final_stores *list_of_stores, size_t number_of_stores, int stores_willing_to_visit) {
    best_stores bestStores;
    //To get an ordered list of stores there is used qsort
    //qsort(list_of_stores, number_of_stores, sizeof(final_stores), cmpfunc);

    return bestStores;
}