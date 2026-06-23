#ifndef SAVE_H
#define SAVE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"cjson.h"
#include"raylib.h"

#include"player/player.h"
#include"inventory/inventory.h"

typedef struct Save{
    char *saveBuffer;
    int sizeOfSaveBuffer;

    char *playerBuffer;
    int sizeOfPlayerBuffer;

    char *inventoryBuffer;
    int sizeOfInventoryBuffer;
}Save;


#endif