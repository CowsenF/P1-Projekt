#include <stdio.h>
#include "database_gen.h"


int main() {

    int num_of_stores;

    printf("Please input the number of stores you want\n");
    scanf("%d",&num_of_stores);

    database_gen(num_of_stores,0);



    return 0;
}
