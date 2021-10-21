#pragma once



#ifndef _SURVIVOR_CHAO_H_
#define _SURVIVOR_CHAO_H_

#include "Survivor.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------

class Chao : public Object
{
private:
    float xF;
    Sprite* chao = nullptr;            // sprite da plataforma
    Sprite* chao2 = nullptr;
    Color color;                            // cor da plataforma
public:
    Chao(float posX, float posY, Color tinta);                   // construtor    
    ~Chao();                            // destrutor

    void OnCollision(Object* obj);           // resolução da colisão
    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif