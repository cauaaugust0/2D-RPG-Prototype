#ifndef INVENTORY_H
#define INVENTORY_H

#include<stdio.h>
#include<stdlib.h>

#include"raylib.h"
#include"item/item.h"

typedef struct Slot{
    Item items;
    
    int is_hovered;
    int is_selected;
    int is_double_selecting;
    int has_item;
    
    Rectangle slotRectangle;
}Slot;

typedef struct Inventory{
    Slot *slots;
    int inventorySize;

    int on_usage;
    int is_selected;

    int hoveredSlot;
    int selectedSlot;
    int selectedSecondSlot;

    Rectangle inventoryRect;
}Inventory;

void InitInventory(Inventory *inventory);
void FreeInventory(Inventory *inventory);
void DrawInventory(Inventory *inventory, int screenWidth, int screenHeight);
void InteractWithInventory(Inventory *inventory, Vector2 mousePos);
void DrawSlots(Inventory *inventory);

#endif