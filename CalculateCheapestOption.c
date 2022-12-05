#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>


int cmpfunc (const void * a, const void * b) {

    final_stores *storeA = (final_stores *)a;
    final_stores *storeB = (final_stores *)b;

    int sum_storeA = 0;
    int sum_storeB = 0;

    //To find the best store there will be used a point system to find the best store.
    for (int i = 0; i < sizeof(storeA->finalItems)/sizeof(storeA->finalItems[0]); ++i) {
        sum_storeA += storeA->finalItems[i].price;
        sum_storeB += storeB->finalItems[i].price;
    }

    return (sum_storeB - sum_storeA);
}

//Get an ordered list of stores
final_stores* get_list_of_best_stores(final_stores list_of_stores[11], size_t number_of_stores) {

    qsort(list_of_stores, number_of_stores, sizeof(final_stores), cmpfunc);

    return list_of_stores;
}