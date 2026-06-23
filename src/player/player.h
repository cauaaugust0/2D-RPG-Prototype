#ifndef PLAYER_H
#define PLAYER_H

#include"raylib.h"
#include"inventory/inventory.h"

typedef struct Player{
    Camera2D camera;
    Vector2 size;
    Rectangle box;

    Vector2 position;

    Inventory inventory;

    int on_menu;

    int alive;
    
    int on_running;

    int life;
    float speed;
    Vector2 velocity;
    float physicalDmg;
    float physicalArmor;
    float stamina;
    float magicDmg;
    float magicResistence;
    float mana;
    //float agility;
}Player;

Player InitializePlayer(int screenWidth, int screenHeight);
void PlayerMovement(Player *p);
void PlayerInventoryInteraction(Player *player);
void PauseInteraction(Player *player);
void DrawPlayer(Player *player);
void InitPlayerAttributes(Player *player);

#endif 