#include<stdio.h>
#include<stdlib.h>

#include"raylib.h"

#include"inventory.h"
#include"item/item.h"

void InitInventory(Inventory *inventory){
    inventory->inventorySize = 31;
    inventory->slots = malloc(inventory->inventorySize * sizeof(Slot));
    if(!inventory->slots){
        printf("ERROR: i = malloc(inventory->inventorySize * sizeof(Slot))\n");
        return;
    }
    
    for(int i = 0; i < inventory->inventorySize; i++){
        inventory->slots[i].is_selected = 0;
        inventory->slots[i].is_hovered = 0;
        inventory->slots[i].slotRectangle.width = 90;
        inventory->slots[i].slotRectangle.height = 90;
        inventory->slots[inventory->inventorySize - 1].has_item= 0;
    }

    inventory->slots[0].has_item = 1;

    inventory->slots[inventory->inventorySize - 1].is_selected = 0;
    inventory->slots[inventory->inventorySize - 1].is_hovered = 0;
    inventory->slots[inventory->inventorySize - 1].slotRectangle.width = 0;
    inventory->slots[inventory->inventorySize - 1].slotRectangle.height = 0;
    inventory->slots[inventory->inventorySize - 1].has_item = 0;

    inventory->on_usage = 0;
}

void FreeInventory(Inventory *inventory){
    free(inventory->slots);
}

void DrawInventory(Inventory *inventory, int screenWidth, int screenHeight){
    if(inventory->on_usage){
        int w = screenWidth - 125;
        int h = screenHeight - 100;
        int x = 60;
        int y = 60;

        inventory->inventoryRect = (Rectangle){x, y, w, h};

        DrawRectangleRec(inventory->inventoryRect, DARKGRAY);
    }
}

void InteractWithInventory(Inventory *inventory, Vector2 mousePos){
    if(!inventory->on_usage){
        inventory->hoveredSlot = inventory->inventorySize - 1;
        inventory->selectedSlot = inventory->inventorySize - 1;
        inventory->selectedSecondSlot = inventory->inventorySize - 1;
        inventory->is_selected = 0;
        return;
    }
    if(!inventory->is_selected){
        for(int i = 0; i < inventory->inventorySize; i++){
            inventory->slots[i].is_hovered = CheckCollisionPointRec(mousePos, inventory->slots[i].slotRectangle);

            if(inventory->slots[i].is_hovered){
                inventory->hoveredSlot = i;
            }
            if(inventory->slots[i].is_hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && inventory->slots[i].has_item){
                inventory->slots[i].is_selected = 1;
                inventory->selectedSlot = i;
                inventory->is_selected = 1;
            }
        }
    }
    else{
        for(int i = 0; i < inventory->inventorySize; i++){
            inventory->slots[i].is_double_selecting = CheckCollisionPointRec(mousePos, inventory->slots[i].slotRectangle);

            if(inventory->slots[i].is_double_selecting){
                inventory->selectedSecondSlot = i;
            }
            if(inventory->slots[i].is_double_selecting && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !inventory->slots[i].has_item){
                inventory->slots[inventory->selectedSecondSlot].has_item = 1;
                inventory->slots[inventory->selectedSecondSlot].is_selected = 0;

                inventory->slots[inventory->selectedSlot].has_item = 0;
            }
            if(inventory->slots[i].is_double_selecting && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && inventory->slots[i].has_item){
                inventory->slots[inventory->selectedSlot].is_selected = 0;
                inventory->is_selected = 0;
            }
        }
    }
}

void DrawSlots(Inventory *inventory){
    if(inventory->on_usage){
        int temp = inventory->inventorySize;
        int sx = inventory->inventoryRect.x + 40;
        int sy = inventory->inventoryRect.y + 40;

        int slotsPerRow = 5;
        int spacing = 95;

        for(int i = 0; i < temp-1; i++){
            int row = i / slotsPerRow; 
            int col = i % slotsPerRow; 

            int x = sx + col * spacing;
            int y = sy + row * spacing;

            inventory->slots[i].slotRectangle = (Rectangle){x, y, inventory->slots[i].slotRectangle.width, inventory->slots[i].slotRectangle.height};
            
            DrawRectangleRec(inventory->slots[i].slotRectangle, RAYWHITE);

            if(inventory->on_usage){
                if(inventory->slots[inventory->hoveredSlot].is_hovered){
                    DrawRectangleLinesEx(inventory->slots[inventory->hoveredSlot].slotRectangle, 10.0f, RED);
                }
                if(inventory->slots[inventory->selectedSlot].is_selected){
                    DrawRectangleLinesEx(inventory->slots[inventory->selectedSlot].slotRectangle, 10.0f, GREEN);
                }
            }
        }
    }
}

