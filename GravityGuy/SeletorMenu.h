#pragma once



#ifndef _SURVIVOR_SELECTOR_H_
#define _SURVIVOR_SELECTOR_H_

#include "Survivor.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------
enum CONTROLLERMENU {PLAY, SETTINGS, EXIT};

#define QTDESCOLHASSELETOR 3

class SeletorMenu : public Object
{
private:
    TileSet* tileset = nullptr;            // sprite da plataforma
    Animation* left;
    Animation* right;
    
    uint espacamentoX[QTDESCOLHASSELETOR];                         // contem o espacamento de cada elemento
    uint posicaoY[QTDESCOLHASSELETOR];                         // contem o espacamento de cada elemento
    uint position;

    Color color;                            // cor da plataforma
    uint level;

public:
    SeletorMenu(Color tinta);                   // construtor    
    ~SeletorMenu();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    int Position();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif