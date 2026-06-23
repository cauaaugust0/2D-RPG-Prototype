#include<stdio.h>
#include<stdlib.h>

#include"raylib.h"
#include"cjson.h"

#include"player/player.h"
#include"map/map.h"
#include"inventory/inventory.h"
#include"item/item.h"
#include"save/save.h"


int main(void)
{
    InitWindow(1280, 720, "FPS");
    SetTargetFPS(60);

    Vector2 mousePos;

    Player p = InitializePlayer(GetScreenWidth(), GetScreenHeight()); 
    InitInventory(&p.inventory);
    InitPlayerAttributes(&p);

    while (!WindowShouldClose())
    {
        PlayerInventoryInteraction(&p);
        PauseInteraction(&p);
        InteractWithInventory(&p.inventory, mousePos);
        
        BeginDrawing();
            mousePos = GetMousePosition();

            ClearBackground(BLACK);
            BeginMode2D(p.camera);

            if(!p.on_menu){
                PlayerMovement(&p);
                UpdateMap();
                DrawPlayer(&p);
            }

            EndMode2D();
            
            DrawInventory(&p.inventory, GetScreenWidth(), GetScreenHeight());
            DrawSlots(&p.inventory);
        
        EndDrawing();
    }

    FreeInventory(&p.inventory);

    CloseWindow();
}