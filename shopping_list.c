#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "shopping_list.h"


//adds an item based on user input
void add_item(tree_t* list, char* name){
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->next = list->head;
    strcpy(new_node->item.name, name);
    list->head = new_node;
}

void print_items(tree_t* list){
    FILE *fptr;
    fptr = fopen("shopping_list.txt", "w");
    node_t* current = list->head;
    while(current != NULL){
        printf("%s \n", current->item.name);
        //fprintf(fptr,"%s \n", current->item.name);
        current = current->next;
    }
    fclose(fptr);
}
//Free's memory form the list of items
void deallocate_list(tree_t* list){
    node_t* current = list->head;
    while(current != NULL){
        node_t* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
