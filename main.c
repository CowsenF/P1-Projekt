#include <stdio.h>
#include "shopping_list.h"
#include "database_gen.h"
#include "CalculateCheapestOption.h"
#include "stdlib.h"
#include "string.h"

int main() {

    tree_t list_of_items = {NULL};
    char name[30];
    while (1){
        printf("Input name and cost (end with 'exit 0')\n");
        scanf("%s", name);
        if(strcmp(name, "exit") == 0){
            print_items(&list_of_items);
            deallocate_list(&list_of_items);
            exit(EXIT_SUCCESS);
        } else {
            add_item(&list_of_items, name);
        }
    }




    return 0;
}
