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



void database_gen(int num_of_stores,int num_of_items){
    // Jeg tænker at man starter med at sætte to lister op som indenholder hvad navne på butikerne er og en som
    // kigger på mad navne

    // database gen er lavet med to for loops
    // den ydrer laver butikker
    // den indre laver produkter
    time_t t;
    srand((unsigned) time(&t));
    FILE *fptr;
    fptr = fopen ("store_list.txt","w");

    for (int i = 0; i < num_of_stores; ++i) {
        // den har først brug for et butik navn
        fprintf(fptr,"%s\n", get_store_name(rand() % 11));
        for (int j = 0; j < num_of_items; ++j) {

        }
    }


}