#include "StoreListGeneration.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* get_store_name(int store_num){
    // This function takes a given integer and retus a string value with the stores name
    switch (store_num) {
        case 0:
            return "Bilka";//
        case 1:
            return "Rema"; //
        case 2:
            return "Fotex"; //
        case 3:
            return "Spar"; //
        case 4:
            return "Daglig_Brusen"; //
        case 5:
            return "Coop_365"; //
        case 6:
            return "Nem_handel"; //
        case 7:
            return "Min_kobmand"; //
        case 8:
            return "Fleggard"; //
        case 9:
            return "Netto";
        case 10:
            return "Meny";
    }
}
char* get_product_name(int product_num){
    // This function takes a given integer and retus a string value with the products name
    switch (product_num) {
        case 0:
            return "beef";//
        case 1:
            return "milk"; //
        case 2:
            return "bread"; //
        case 3:
            return "honey"; //
        case 4:
            return "salami"; //
        case 5:
            return "cooking_oil"; //
        case 6:
            return "toilet_paper"; //
        case 7:
            return "coffee"; //
        case 8:
            return "noodles"; //
        case 9:
            return "monster";
        case 10:
            return "pizza";
    }
}


int point_maker(){
    // To get a point it starts by generating a random value between 0-10
    int x = rand() % 10;
    // A 50/50 chance will decide if it will be a negative or a positive coordinate.
    if(rand() % 2 == 0){
        x = x - (x * 2);
    }
    return x;

}



void Storelistgeneration(size_t *store_num){


    // First we setup the right paramerters for rand to work this is time for each seed to be more random and srand to set the seed
    time_t t;
    srand((unsigned) time(&t));

    // A file pointer is setup that looks at a text file in write mode
    FILE *fptr;
    fptr = fopen ("store_list.txt","w");


    //we know that we only have eleven stores
    *store_num = 11;

    // Two for loops are then used to place the store name and the product name
    for (int i = 0; i < *store_num; ++i) {
        // The store is first printed with a name gooten by the for loops i value, and then two points in a coordinate system is made.
        fprintf(fptr,"%s cordinates: x:%d y:%d\n", get_store_name(i), point_maker(),point_maker());
        for (int j = 0; j < 11; ++j) {
            // 10 products are then made with their names coming from the j value given to the fuction.
            // A price between 1 and 101 is also generated with rand
            fprintf(fptr,"%d: %s: %d\n",j+1,get_product_name(j),rand()%100 +1);

        }
    }

    // Now that the file is no longer used we close it to avoid memory problems.
    fclose(fptr);


}