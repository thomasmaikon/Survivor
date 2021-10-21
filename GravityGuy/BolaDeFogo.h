#pragma once



#ifndef _SURVIVOR_BOLADEFOGO_H_
#define _SURVIVOR_BOLADEFOGO_H_

#include "Survivor.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum EXPLOSION{DOWN, COLLIDED};
// ---------------------------------------------------------------------------------

class BolaDeFogo : public Object
{
private:
    TileSet* bolaDeFogo = nullptr;            // sprite da plataforma
    Animation* anim;
    Color color;                            // cor da plataforma
    bool collided = false;
    bool isFirst = true;
    bool isOut;
    uint level;

public:
    BolaDeFogo(float posX, float posY, Color tinta, uint level);                   // construtor    
    ~BolaDeFogo();                            // destrutor

    void OnCollision(Object* obj);           // resolução da colisão
    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif