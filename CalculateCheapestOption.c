#include "CalculateCheapestOption.h"
#include <malloc.h>
#include <string.h>
//Function for to compare store name to the list of stores in bestStores.
int is_store_the_store_in_bestStores(final_stores store, best_stores bestStores) {
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        if(strcmp(bestStores.finalStores[i].store_name, store.store_name) == 0) {
            return 1;
        }
    }
    return 0;
}
//This function is used when we need to know how much we save on a new store compared to any store in bestStores.
//Therefore, will this be called for every store and item.
int check_price_difference_item(final_stores store, best_stores bestStores, int item_number) {
    int biggest_save = 0;
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        //If an item will not save money then we will ignore it.
        if(store.finalItems[item_number].price - bestStores.finalStores[i].finalItems[item_number].price > 0) {
            continue;
        }
        biggest_save = store.finalItems[item_number].price - bestStores.finalStores[i].finalItems[item_number].price;
    }
    return biggest_save;
}
//This function is used to copy a store's data and save it on to bestStore as a store.
best_stores copy_store(best_stores bestStores, final_stores finalStores, int number) {

    for (int i = 0; i < 11; ++i) {
        bestStores.finalStores[number].finalItems[i].price = finalStores.finalItems[i].price;
        strcpy(bestStores.finalStores[number].finalItems[i].item_name, finalStores.finalItems[i].item_name);
    }
    strcpy(bestStores.finalStores[number].store_name, finalStores.store_name);
    bestStores.finalStores[number].distance = finalStores.distance;

    return bestStores;
}


//This function gets a list of stores and how many we are willing to visit.
//Thereafter, will make a 'list' of stores which is the best.
//Items are already handled.
//The code don't go through all the possible combinations, but takes the best path one step at a time.
best_stores get_list_of_best_stores(final_stores *list_of_stores, size_t number_of_stores, int stores_willing_to_visit) {
    best_stores bestStores;

    bestStores.number_of_stores = 0;
    bestStores.finalStores = (final_stores*) malloc(stores_willing_to_visit * sizeof(final_stores));
    bestStores.bestStoreForItem = calloc(11, sizeof(best_store_for_item));

    //these int's will be used as compares in for loops:
    int saved_sum = 0;
    int saved_store = 0;

    //The code is spilt op in 3 main parts
    //The fist part is used to get the first best store.
    //Thereafter, in part 2 we get x number of extra stores we could use if they have a better price for some items.
    //In part 3 we prepare the data for use outside the function. So it easier to display to the user.

    //We find out which store has the best prices on the items we are looking after.
    for (int i = 0; i < number_of_stores; ++i) {
        int sum = 0;
        for (int j = 0; j < sizeof(list_of_stores[i].finalItems)/ sizeof(list_of_stores[i].finalItems[0]); ++j) {
            sum += list_of_stores[i].finalItems[j].price;
        }
        if(sum == 0) { continue;}
        //We save the best store for the next code block
        if(sum < saved_sum || saved_sum == 0) {
            saved_sum = sum;
            saved_store = i;
        }
    }
    //Here we use the saved store and copy the data in bestStores
    for (int i = 0; i < 11; ++i) {
        bestStores.finalStores[0].finalItems[i].price = list_of_stores[saved_store].finalItems[i].price;
        strcpy(bestStores.finalStores[0].finalItems[i].item_name, list_of_stores[saved_store].finalItems[i].item_name);
    }
    strcpy(bestStores.finalStores[0].store_name, list_of_stores[saved_store].store_name);
    bestStores.finalStores[0].distance = list_of_stores[saved_store].distance;
    bestStores.number_of_stores++;

    //In this code block we compare the rest of stores to bestStores stores.
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
        //We save the store in bestStores for a later use.
        bestStores = copy_store(bestStores, list_of_stores[saved_store], i);

        bestStores.number_of_stores++;
    }

    //The rest of code prepares the data in the list bestStoreForItem in bestStores

    //If their only one store then this code block will be run:
    if(bestStores.number_of_stores == 1) {
        strcpy(bestStores.bestStoreForItem[0].storeName, bestStores.finalStores[0].store_name);
        bestStores.bestStoreForItem[0].distance = bestStores.finalStores[0].distance;
        for (int i = 0; i < 11; i++) {
            if (bestStores.finalStores[0].finalItems[i].price == 0) { continue;}

            bestStores.bestStoreForItem[0].bestFinalItems[i].price = bestStores.finalStores[0].finalItems[i].price;
            strcpy(bestStores.bestStoreForItem[0].bestFinalItems[i].item_name, bestStores.finalStores[0].finalItems[i].item_name);
        }
        return bestStores;
    }

    //Here prepares multiple stores

    //First copies the name of the stores:
    for (int i = 0; i < bestStores.number_of_stores; ++i) {
        strcpy(bestStores.bestStoreForItem[i].storeName, bestStores.finalStores[i].store_name);
        bestStores.bestStoreForItem[i].distance = bestStores.finalStores[i].distance;
    }

    //Thereafter the items:
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