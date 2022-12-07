#include <stdio.h>
#include <math.h>
#include "shopping_list.h"
#include "database_gen.h"
#include "CalculateCheapestOption.h"
#include "stdlib.h"
#include "string.h"


typedef struct {
    char item[15];
}item_holder;

typedef struct {
    char item_name[15];
    int item_price;
}item;

typedef struct {
    char store_name[11];
    double distance;
    int x;
    int y;
    item items[11];
}stores;



int store_array_name(char* store_name) {

    if (strcmp(store_name, "Bilka") == 0) {
        return 0;
    } else if (strcmp(store_name, "Rema") == 0) {
        return 1;
    } else if (strcmp(store_name, "Fotex") == 0) {
        return 2;
    } else if (strcmp(store_name, "Spar") == 0) {
        return 3;
    } else if (strcmp(store_name, "Daglig_Brusen") == 0) {
        return 4;
    } else if (strcmp(store_name, "Coop_365") == 0) {
        return 5;
    } else if (strcmp(store_name, "nem_handel") == 0) {
        return 6;
    } else if (strcmp(store_name, "kobmand") == 0) {
        return 7;
    } else if (strcmp(store_name, "Fleggard") == 0) {
        return 8;
    } else if (strcmp(store_name, "Netto") == 0) {
        return 9;
    } else if (strcmp(store_name, "Meny") == 0) {
        return 10;
    }
}

tree_t get_list_of_items();
stores * scan_file_into_stores(FILE * fptr2, size_t size_of_list);
final_stores * setup_finalStores(size_t size_of_list);
item_holder * setup_itemHolder(node_t* current, size_t size_of_list);
final_stores * convert_store_type(stores *stores1, final_stores *finalStores, item_holder *itemHolder, double range);
void print_stores_prices(final_stores *final_stores);
double distance_formula(int x1,int x2, int y1, int y2);




int main() {

    //test:
    size_t test_size_of_list_of_stores = 11;


    database_gen();

    double range = 0;
    // For database
    FILE *fptr2;
    fptr2 = fopen ("store_list.txt","r");
    // For the final struct

    printf("Please input the maximum radius of your shopping trip in KM\n");
    scanf("%lf",&range);

    tree_t list_of_items = get_list_of_items();


    //VI SKAL HAVE EN MÅDE HVORPÅ VI VED HVOR LANG LISTEN ER
    stores *stores1 = scan_file_into_stores(fptr2, 11);

    final_stores *finalStores = setup_finalStores(11);

    node_t* current = list_of_items.head;
    item_holder *itemHolder = setup_itemHolder(current, 11);

    for (int i = 0; i < 11; ++i) {
        stores1[i].distance = distance_formula(0,stores1[i].x,0,stores1[i].y);
    }

    finalStores = convert_store_type(stores1, finalStores, itemHolder, range);

    deallocate_list(&list_of_items);

    print_stores_prices(finalStores);

    final_stores *new_final_store = get_list_of_best_stores(finalStores, test_size_of_list_of_stores);

    print_stores_prices(finalStores);

    // Lav en struct af struct hvor vis string compair er true så sæt varens info ind i struct

    // sammelign alle varer for at finde hvor det er billgeste

    // Print Endlig struct

    fclose(fptr2);

    //get_list_of_items()
    //return: list_of_items

    //To print out user desired item name (Shopping list)

    return 0;
}

//To print out user desired item name (Shopping list)
tree_t get_list_of_items(){
    tree_t list_of_items = {NULL};
    char name[30];
    int exit_con=0;
    while (exit_con == 0){
        printf("Enter product (end with 'exit')\n");
        scanf("%s", name);
        if(strcmp(name, "exit") == 0){
            print_items(&list_of_items);
            //deallocate_list(&list_of_items);
            exit_con = 1;
        } else {
            add_item(&list_of_items, name);
        }
    }
    return list_of_items;
}

stores * scan_file_into_stores(FILE * fptr2, size_t size_of_list) {
    stores *stores1 = calloc(size_of_list, sizeof(stores));
    for (int i = 0; i < size_of_list; ++i) {
        fscanf(fptr2,"%[^ ] cordinates: x:%d y:%d ",stores1[i].store_name,&stores1[i].x,&stores1[i].y);
        for (int j = 0; j < size_of_list; ++j) {
            fscanf(fptr2,"%*d: %[^:]: %d ",stores1[i].items[j].item_name,&stores1[i].items[j].item_price);
        }
    }
    return stores1;
}

final_stores * setup_finalStores(size_t size_of_list) {
    final_stores *finalStores = calloc(size_of_list, sizeof(final_stores));

    if (finalStores == NULL) {
        printf("Unable to allocate memory\n");
    }

    for (int i = 0; i < size_of_list; ++i) {
        for (int j = 0; j < size_of_list; ++j) {
            finalStores[i].finalItems[j].price = 0;
            strcpy(finalStores[i].finalItems[j].item_name,"");
        }
    }
    return finalStores;
}

item_holder * setup_itemHolder(node_t* current, size_t size_of_list) {
    item_holder *itemHolder = calloc(size_of_list, sizeof(item_holder));;
    int g = 0;
    while(current != NULL){
        strcpy(itemHolder[g].item,current->item.name);
        g++;
        current = current->next;
    }
    return itemHolder;
}

final_stores * convert_store_type(stores *stores1, final_stores *finalStores, item_holder *itemHolder, double range) {

    for (int i = 0; i < 11; ++i) {
        if(stores1[i].distance > range) {
            continue;
        }
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 11; ++k) {
                if(strcmp(stores1[i].items[j].item_name,itemHolder[k].item) == 0){
                    finalStores[store_array_name(stores1[i].store_name)].finalItems[j].price = stores1[i].items[j].item_price;

                    strcpy(finalStores[store_array_name(stores1[i].store_name)].finalItems[j].item_name,itemHolder[k].item);
                    strcpy(finalStores[store_array_name(stores1[i].store_name)].store_name,stores1[i].store_name);

                }
            }
        }
    }

    return finalStores;
}

void print_stores_prices(final_stores *final_stores){

    for (int i = 0; i < 11; ++i) {
        printf("Store: %s\n",final_stores[i].store_name);

        for (int j = 0; j < 11; ++j) {
            if(final_stores[i].finalItems[j].price != 0) {
                printf("Product: %s PRICE:%d\n", final_stores[i].finalItems[j].item_name,final_stores[i].finalItems[j].price);
            }
        }
        printf("\n");
    }

}

double distance_formula(int x1,int x2, int y1, int y2){
    return sqrt(pow((x2-x1),2)+ pow((y2-y1),2));
}