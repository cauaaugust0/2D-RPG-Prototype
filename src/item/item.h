#ifndef ITEM_H
#define ITEM_H

#include<stdio.h>
#include<stdlib.h>

#include"raylib.h"

typedef struct Item{
    int durability; // 1 ou 0
    //float durabilityVal; // 0 - 100
    int itemId;
}Item;


#endif