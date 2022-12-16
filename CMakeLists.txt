cmake_minimum_required(VERSION 3.23)
project(P1_Projekt C)

set(CMAKE_C_STANDARD 99)

add_executable(P1_Projekt main.c CalculateCheapestOption.c CalculateCheapestOption.h StoreListGeneration.c StoreListGeneration.h shopping_list.c shopping_list.h)
