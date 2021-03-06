///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Christian Li <lichrist@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "config.h"

void printCat(const int index){
    if(index < 0){
        fprintf(stderr, "%s animalFarm1: Bad cat [%d]\n", PROGRAM_NAME,  index);
    }
    if(index >= numberOfCats){
        fprintf(stderr, "%s animalFarm1: Bad cat [%d]\n", PROGRAM_NAME, index);
    }

    printf("cat index = [%d] name = [%s] gender = [%s] breed = [%s] isFixed = [%d] weight = [%f] color#1 = [%s] color#2 = [%s] license = [%llu] \n", index, cats[index].name, genderList(cats[index].gender), breedList(cats[index].breed), cats[index].isFixed, cats[index].weight, colorList(cats[index].collarColor1), colorList(cats[index].collarColor2), cats[index].license);
}

void printAllCats(){
    if(numberOfCats == 0){
        fprintf(stderr, "%s No cats in database!\n", PROGRAM_NAME);
    }
    for(int i=0; i < numberOfCats; i++){
        //printCat(i);
        printf("cat index = [%d] name = [%s] gender = [%s] breed = [%s] isFixed = [%d] weight = [%f] color#1 = [%s] color#2 = [%s] license = [%llu] \n", i, cats[i].name, genderList(cats[i].gender), breedList(cats[i].breed), cats[i].isFixed, cats[i].weight, colorList(cats[i].collarColor1), colorList(cats[i].collarColor2), cats[i].license);
    }

}

int findCat(const char name[]){
    if(strlen(name) <= 0 || strlen(name) > MAXIMUM_CHAR_CAT){
        fprintf(stderr, "%s Error: Cat is either not there or character length is greather than 30!\n", PROGRAM_NAME);
        return 0;
    }
    for(int i=0; i < numberOfCats; i++){
        if(strcmp(cats[i].name,name) == 0){
            printf("Index of cat: %d\n",i);
            return i;
        }
    }
    fprintf(stderr, "%s Cat was not found\n", PROGRAM_NAME);
    return 0;
}
