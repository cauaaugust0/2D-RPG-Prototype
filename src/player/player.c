#include"raylib.h"
#include"player.h"
#include"inventory/inventory.h"

Player InitializePlayer(int screenWidth, int screenHeight){
    Player p = {0};

    p.position = (Vector2){1000.0f, 1000.0f};

    p.velocity = (Vector2){0.0f,  0.0f};
    
    p.speed = 100.0f;

    p.size = (Vector2){20.0f,  50.0f};

    p.camera.target = p.position;
    p.camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    p.camera.rotation = 0.0f;
    p.camera.zoom = 1.0f;

    p.box = (Rectangle){p.position.x, p.position.y, p.size.x, p.size.y};

    p.on_menu = 0;
    p.on_running = 0;

    return p;
}

void PlayerMovement(Player *player){
    float delta = GetFrameTime();

    float currentSpeed = player->speed;
    if(IsKeyDown(KEY_LEFT_SHIFT)){
        player->on_running = 1;
        currentSpeed *= 2.0f;
    }
    else{
        player->on_running = 0;
    }

    if(IsKeyDown(KEY_W)){
        player->position.y -= currentSpeed * delta;
    }
    if(IsKeyDown(KEY_S)){
        player->position.y += currentSpeed * delta;
    }
    if(IsKeyDown(KEY_D)){
        player->position.x += currentSpeed * delta;
    }
    if(IsKeyDown(KEY_A)){
        player->position.x -= currentSpeed * delta;
    }

    player->camera.target = player->position;
    player->box = (Rectangle){player->position.x, player->position.y, player->size.x, player->size.y};
    
}

void PlayerInventoryInteraction(Player *player){
    if(IsKeyDown(KEY_TAB)){
        player->inventory.on_usage = 1;
    }
    else{
        player->inventory.on_usage = 0;
    }
}

void PauseInteraction(Player *player){
    player->on_menu = player->inventory.on_usage == 1 ? 1 : 0;
}

void DrawPlayer(Player *p){
    DrawRectangleRec(p->box, RED);
}

void InitPlayerAttributes(Player *player){
    /*
    int life;
    float physicalDmg;
    float physicalArmor;
    float stamina;
    float magicDmg;
    float magicResistence;
    float mana;
    float agility;
    */
    player->alive = 1;
    player->life = 100;
    player->physicalDmg = 0.0f;
    player->physicalArmor = 0.0f;
    player->stamina = 100.0f;
    player->magicDmg = 0.0f;
    player->magicResistence = 0.0f;
    player->mana = 100.0f;
}
