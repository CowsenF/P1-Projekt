#ifndef P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H
#define P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H
#include <stdio.h>
#include "string.h"



typedef struct{
    char item_name[15];
    int price;
}final_items;

typedef struct{
    char store_name[11];
    final_items finalItems[11];
    double distance;
}final_stores;

typedef struct{
    size_t number_of_stores;
    final_stores *finalStores;
}best_stores;

best_stores get_list_of_best_stores(final_stores *list_of_stores, size_t number_of_stores, int stores_willing_to_visit);

#endif //P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H