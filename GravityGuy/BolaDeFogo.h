#pragma once



#ifndef _GRAVITYGUY_BOLADEFOGO_H_
#define _GRAVITYGUY_BOLADEFOGO_H_

#include "GravityGuy.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

enum EXPOLOSION{DOWN, COLLIDED};
// ---------------------------------------------------------------------------------

class BolaDeFogo : public Object
{
private:
    TileSet* bolaDeFogo = nullptr;            // sprite da plataforma
    Animation* anim;
    Color color;                            // cor da plataforma
    bool colided = false;
    bool isFirst = true;

public:
    BolaDeFogo(float posX, float posY, Color tinta);                   // construtor    
    ~BolaDeFogo();                            // destrutor

    void OnCollision(Object* obj);           // resolu��o da colis�o
    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline
#endif