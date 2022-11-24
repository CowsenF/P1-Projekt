#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {

    stores *storeA = (stores *)a;
    stores *storeB = (stores *)b;

    int best_storeA = 0;
    int best_storeB = 0;

    //To find the best store there will be used a point system to find the best store.
    for (int i = 0; i < 10; ++i) {
        if(storeA->items[i].item_price < storeB->items[i].item_price) {best_storeA++;}
        if(storeB->items[i].item_price > storeA->items[i].item_price) {best_storeB++;}
    }

    return (best_storeB - best_storeA);
}

//Get an ordered list of stores
stores* get_list_of_best_stores(stores list_of_stores[], size_t number_of_stores) {
    stores *return_list_of_stores = malloc(number_of_stores);

    for (int i = 0; i < number_of_stores; ++i) {
        return_list_of_stores[i] = list_of_stores[i];
    }

    qsort(return_list_of_stores, number_of_stores, sizeof(stores), cmpfunc);

    return return_list_of_stores;
}




