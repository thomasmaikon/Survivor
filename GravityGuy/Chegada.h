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

    void OnCollision(Object* obj);           // resolução da colisão
    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif