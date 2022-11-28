#ifndef P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H
#define P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H
#include <stdio.h>

typedef struct {
    char item_name[15];
    int item_price;
}item;

typedef struct {
    char store_name[11];
    double distance;
    item items[11];
}stores;

stores* get_list_of_best_stores(stores list_of_stores[], size_t number_of_stores);

#endif //P1_PROJEKT_CALCULATE_CHEAPEST_OPTION_H