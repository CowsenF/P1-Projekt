#include <stdio.h>
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

int main() {



    database_gen();

    int exit_con=0;
    double range = 0;
    // For database
    FILE *fptr2;
    fptr2 = fopen ("store_list.txt","r");
    stores stores1[11];
    // For the final struct
    final_stores finalStores[11];
    item_holder itemHolder[11];


    printf("Please input the maximum radius of your shopping trip in KM\n");
    scanf("%lf",&range);

    //To print out user desired item name (Shopping list)
    tree_t list_of_items = {NULL};
    char name[30];
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


    for (int i = 0; i < 11; ++i) {
        fscanf(fptr2,"%[^ ] distance: %lf ",stores1[i].store_name,&stores1[i].distance);
        for (int j = 0; j < 11; ++j) {
            fscanf(fptr2,"%*d: %[^:]: %d ",stores1[i].items[j].item_name,&stores1[i].items[j].item_price);
        }
    }


    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            finalStores[i].finalItems[j].price = 0;
            strcpy(finalStores[i].finalItems[j].item_name,"");
        }
    }


    node_t* current = list_of_items.head;

    int g = 0;
    while(current != NULL){
        strcpy(itemHolder[g].item,current->item.name);
        g++;
        current = current->next;
    }



    while(exit_con == 1){

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
        exit_con = 0;
    }


    deallocate_list(&list_of_items);



    for (int i = 0; i < 11; ++i) {
        printf("Store: %s\n",finalStores[i].store_name);

        for (int j = 0; j < 11; ++j) {
            if(finalStores[i].finalItems[j].price != 0) {
                printf("Product: %s PRICE:%d\n", finalStores[i].finalItems[j].item_name,finalStores[i].finalItems[j].price);
            }
        }
        printf("\n");
    }

    printf("HEJEHJEJJ \n\n");

    final_stores *new_final_store = get_list_of_best_stores(finalStores, sizeof(finalStores)/sizeof(finalStores[0]));

    for (int i = 0; i < 11; ++i) {
        printf("Store: %s\n",new_final_store[i].store_name);

        for (int j = 0; j < 11; ++j) {
            if(finalStores[i].finalItems[j].price != 0) {
                printf("Product: %s PRICE:%d\n", new_final_store[i].finalItems[j].item_name,new_final_store[i].finalItems[j].price);
            }
        }
        printf("\n");
    }



    // Lav en struct af struct hvor vis string compair er true så sæt varens info ind i struct

    // sammelign alle varer for at finde hvor det er billgeste

    // Print Endlig struct





    fclose(fptr2);






    return 0;
}
