#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>

int is_store_the_store_in_bestStores(final_stores store, best_stores bestStores) {
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        if(strcmp(bestStores.finalStores[i].store_name, store.store_name) == 0) {
            return 1;
        }
    }
    return 0;
}

int check_price_difference_item(final_stores store, best_stores bestStores, int item_number) {
    int biggest_save = 0;
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        if(store.finalItems[item_number].price - bestStores.finalStores[i].finalItems[item_number].price > 0) {
            continue;
        }
        biggest_save = store.finalItems[item_number].price - bestStores.finalStores[i].finalItems[item_number].price;
    }
    return biggest_save;
}

best_stores copy_store(best_stores bestStores, final_stores finalStores, int number) {

    for (int i = 0; i < 11; ++i) {
        bestStores.finalStores[number].finalItems[i].price = finalStores.finalItems[i].price;
        strcpy(bestStores.finalStores[number].finalItems[i].item_name, finalStores.finalItems[i].item_name);
    }
    strcpy(bestStores.finalStores[number].store_name, finalStores.store_name);

    return bestStores;
}


//Get an ordered list of stores
best_stores get_list_of_best_stores(final_stores *list_of_stores, size_t number_of_stores, int stores_willing_to_visit) {
    best_stores bestStores;
    bestStores.number_of_stores = 0;

    bestStores.finalStores = (final_stores*) malloc(stores_willing_to_visit * sizeof(final_stores));
    bestStores.bestStoreForItem = (best_store_for_item*) malloc(11 * sizeof(best_store_for_item));
    int saved_sum = 0;
    int saved_store = 0;

    for (int i = 0; i < number_of_stores; ++i) {
        int sum = 0;
        for (int j = 0; j < sizeof(list_of_stores[i].finalItems)/ sizeof(list_of_stores[i].finalItems[0]); ++j) {
            sum += list_of_stores[i].finalItems[j].price;
        }
        if(sum == 0) { continue;}
        if(sum < saved_sum || saved_sum == 0) {
            saved_sum = sum;
            saved_store = i;
        }
    }
    //bestStores = copy_store(bestStores, list_of_stores[saved_store], 0);
    for (int i = 0; i < 11; ++i) {
        bestStores.finalStores[0].finalItems[i].price = list_of_stores[saved_store].finalItems[i].price;
        strcpy(bestStores.finalStores[0].finalItems[i].item_name, list_of_stores[saved_store].finalItems[i].item_name);
    }
    strcpy(bestStores.finalStores[0].store_name, list_of_stores[saved_store].store_name);

    bestStores.number_of_stores++;

    for (int i = 1; i < stores_willing_to_visit; ++i) {
        int biggest_save = 0;
        saved_store = 0;
        for (int j = 0; j < number_of_stores; ++j) {
            if(is_store_the_store_in_bestStores(list_of_stores[j], bestStores)) {
                continue;
            }
            int saved_money = 0;
            for (int k = 0; k < sizeof(list_of_stores[j].finalItems)/ sizeof(list_of_stores[j].finalItems[0]); ++k) {
                if(list_of_stores[j].finalItems[k].price == 0) {
                    continue;
                }
                saved_money += check_price_difference_item(list_of_stores[j], bestStores, k);
            }
            if(saved_money > biggest_save) {
                continue;
            }
            biggest_save = saved_money;
            saved_store = j;
        }
        if(biggest_save == 0) { break;}
        bestStores = copy_store(bestStores, list_of_stores[saved_store], i);
        bestStores.number_of_stores++;
    }


    if(bestStores.number_of_stores == 1) {
        strcpy(bestStores.bestStoreForItem[0].storeName, bestStores.finalStores[0].store_name);
        for (int i = 0; i < 11; i++) {
            if (bestStores.finalStores[0].finalItems[i].price == 0) { continue;}
            bestStores.bestStoreForItem[0].bestFinalItems[i].price = bestStores.finalStores[0].finalItems[i].price;
            strcpy(bestStores.bestStoreForItem[0].bestFinalItems[i].item_name, bestStores.finalStores[0].finalItems[i].item_name);
        }
        return bestStores;
    }

    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        strcpy(bestStores.bestStoreForItem[i].storeName, bestStores.finalStores[i].store_name);
    }

    for (int i = 0; i < 11; ++i) {

        int saved_best_store_for_item = 0;
        for (int j = 0; j < bestStores.number_of_stores; ++j) {
            if(bestStores.finalStores[j].finalItems[i].price == 0) {
                continue;
            }
            if(bestStores.finalStores[j].finalItems[i].price < saved_best_store_for_item || saved_best_store_for_item == 0) {
                saved_store = j;
                saved_best_store_for_item = bestStores.finalStores[j].finalItems[i].price;
            }
        }
        bestStores.bestStoreForItem[saved_store].bestFinalItems[i].price = bestStores.finalStores[saved_store].finalItems[i].price;
        strcpy(bestStores.bestStoreForItem[saved_store].bestFinalItems[i].item_name, bestStores.finalStores[saved_store].finalItems[i].item_name);
    }

    return bestStores;
}