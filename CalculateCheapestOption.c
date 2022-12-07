#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>

/*
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
}*/

int is_store_the_store_in_bestStores(final_stores store, best_stores bestStores) {
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        if(strcmp(bestStores.finalStores[i].store_name, store.store_name) == 0) {
            return 1;
        }
    }
    return 0;
}


//Get an ordered list of stores
best_stores get_list_of_best_stores(final_stores *list_of_stores, size_t number_of_stores, int stores_willing_to_visit) {
    best_stores bestStores;
    int stores_to_visit = 0;
    bestStores.number_of_stores = 0;

    int *saved_stores = (int*)malloc(stores_willing_to_visit);
    bestStores.finalStores = (final_stores*) malloc(stores_willing_to_visit);
    int saved_sum = 0;
    int saved_store = 0;
    for (int i = 0; i < number_of_stores; ++i) {
        int sum = 0;
        for (int j = 0; j < sizeof(list_of_stores[i].finalItems)/ sizeof(list_of_stores[i].finalItems[0]); ++j) {
            sum += list_of_stores[i].finalItems[j].price;
        }
        if(sum < saved_sum || saved_sum == 0) {
            saved_sum = sum;
            saved_store = i;
        }
    }
    bestStores.finalStores[0] = list_of_stores[saved_store];
    bestStores.number_of_stores++;
    for (int i = 1; i < stores_willing_to_visit; ++i) {
        for (int j = 0; j < number_of_stores; ++j) {
            if(is_store_the_store_in_bestStores(list_of_stores[j], bestStores)) {
                continue;
            }
            int biggest_save = 0;
            for (int k = 0; k < sizeof(list_of_stores[j].finalItems)/ sizeof(list_of_stores[j].finalItems[0]); ++k) {
                if(list_of_stores[j].finalItems[k].price == 0) {
                    continue;
                }

            }


        }
    }

    return bestStores;
}

