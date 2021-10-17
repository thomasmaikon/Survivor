#pragma once



#ifndef _GRAVITYGUY_MOEDA_H_
#define _GRAVITYGUY_MOEDA_H_

#include "GravityGuy.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------

class Moeda : public Object
{
private:
    TileSet* moeda = nullptr;            // sprite da plataforma
    Animation* anim;
    Color color;                            // cor da plataforma
    bool colided = false;
    bool isFirst = true;

public:
    Moeda(float posX, float posY, Color tinta);                   // construtor    
    ~Moeda();                            // destrutor

    void OnCollision(Object* obj);           // resolu��o da colis�o
    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline
#endif