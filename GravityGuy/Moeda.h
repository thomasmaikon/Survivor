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
    uint level;

public:
    Moeda(float posX, float posY, Color tinta, uint level);                   // construtor    
    ~Moeda();                            // destrutor

    void OnCollision(Object* obj);           // resolução da colisão
    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif