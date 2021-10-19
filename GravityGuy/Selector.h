#pragma once



#ifndef _GRAVITYGUY_SELECTOR_H_
#define _GRAVITYGUY_SELECTOR_H_

#include "GravityGuy.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------
enum CONTROLLER {PLAY, SETTINGS, EXIT};

class Selector : public Object
{
private:
    TileSet* tileset = nullptr;            // sprite da plataforma
    Animation* left;
    Animation* right;
    
    uint espacamentoX[3];                         // contem o espacamento de cada elemento
    uint posicaoY[3];                         // contem o espacamento de cada elemento
    uint position;

    Color color;                            // cor da plataforma
    uint level;

public:
    Selector(Color tinta);                   // construtor    
    ~Selector();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    int Position();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif