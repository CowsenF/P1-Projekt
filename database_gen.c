#include "database_gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* get_store_name(int store_num){

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
            return "nem_handel"; //
        case 7:
            return "kobmand"; //
        case 8:
            return "Fleggard"; //
        case 9:
            return "Netto";
        case 10:
            return "Meny";
    }

}
char* get_product_name(int product_num){
    switch (product_num) {
        case 0:
            return "Beef";//
        case 1:
            return "Milk"; //
        case 2:
            return "Bread"; //
        case 3:
            return "Honey"; //
        case 4:
            return "Salami"; //
        case 5:
            return "Cooking_oil"; //
        case 6:
            return "Toilet_paper"; //
        case 7:
            return "Coffee"; //
        case 8:
            return "Noodles"; //
        case 9:
            return "Monster";
        case 10:
            return "Pizza";
    }
}

double drand ( double low, double high )
{
    return ( (double)rand() * ( high - low ) ) / (double)RAND_MAX + low;
}



void database_gen(size_t *store_num){
    // Jeg tænker at man starter med at sætte to lister op som indenholder hvad navne på butikerne er og en som
    // kigger på mad navne

    // database gen er lavet med to for loops
    // den ydrer laver butikker
    // den indre laver produkter
    time_t t;
    srand((unsigned) time(&t));
    FILE *fptr;
    fptr = fopen ("store_list.txt","w");


    //test:
    *store_num = 11;


    for (int i = 0; i < *store_num; ++i) {
        // den har først brug for et butik navn
        fprintf(fptr,"%s distance: %.2f\n", get_store_name(i), drand(0,10));
        for (int j = 0; j < 11; ++j) {
            fprintf(fptr,"%d: %s: %d\n",j+1,get_product_name(j),rand()%100 +1);

        }
    }

    fclose(fptr);


}