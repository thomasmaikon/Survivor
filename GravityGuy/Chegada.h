#pragma once



#ifndef _SURVIVOR_CHEGADA_H_
#define _SURVIVOR_CHEGADA_H_

#include "Survivor.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------

class Chegada : public Object
{
private:
    TileSet* chegada = nullptr;            // sprite da plataforma
    Animation* anim;
    Color color;                            // cor da plataforma
    uint level;

public:
    Chegada(float posX, float posY, Color tinta, uint level);                   // construtor    
    ~Chegada();                            // destrutor

    void OnCollision(Object* obj);           // resolu��o da colis�o
    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline
#endif