#include <stdio.h>
#include "shopping_list.h"
#include "database_gen.h"
#include "CalculateCheapestOption.h"
#include "stdlib.h"
#include "string.h"


typedef struct{
    char item_name[15];
    int price;
}final_items;


typedef struct{
    char store_name[10];
    final_items finalItems;

}final_stores;











int main() {



    database_gen();

    int exit_con=0;
    double range = 0;
    // For database
    FILE *fptr2;
    fptr2 = fopen ("store_list.txt","r");
    stores stores1[10];
    // For the final struct
    final_stores finalStores[10];


    printf("Please input the maximum radius of your shopping trip in KM");
    scanf("%lf",&range);

    //To print out user desired item name (Shopping list)
    tree_t list_of_items = {NULL};
    char name[30];
    while (exit_con == 0){
        printf("Input name(end with 'exit')\n");
        scanf("%s", name);
        if(strcmp(name, "exit") == 0){
            print_items(&list_of_items);
            //deallocate_list(&list_of_items);
            exit_con = 1;
        } else {
            add_item(&list_of_items, name);
        }
    }






    for (int i = 0; i < 10; ++i) {
        fscanf(fptr2,"%[^ ] distance: %lf ",stores1[i].store_name,&stores1[i].distance);
        for (int j = 0; j < 10; ++j) {
            fscanf(fptr2,"%*d: %[^:]: %d ",stores1[i].items[j].item_name,&stores1[i].items[j].item_price);
        }
    }

    node_t* current = list_of_items.head;
    while(current != NULL){

        for (int i = 0; i < 10; ++i) {
            if(stores1[i].distance > range) continue;
            for (int j = 0; j < 10; ++j) {
                if(strcmp(stores1[i].items[j].item_name,current->item.name) == 1){
                    finalStores->finalItems.price = stores1[i].items->item_price;
                    // mangler array plads til final finalstores
                    strcpy(finalStores->finalItems.item_name,current->item.name);
                }
            }

        }




        printf("%s \n", current->item.name);
        current = current->next;
    }



    // Lav en struct af struct hvor vis string compair er true så sæt varens info ind i struct

    // sammelign alle varer for at finde hvor det er billgeste

    // Print Endlig struct





    fclose(fptr2);






    return 0;
}
