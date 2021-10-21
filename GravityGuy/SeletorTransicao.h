#pragma once


#ifndef _SURVIVOR_SELECTORTRANSICAO_H_
#define _SURVIVOR_SELECTORTRANSICAO_H_

#include "Survivor.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------
enum TRANSICAONIVEL {  CONTINUAR, RETORNARMENU };

#define QTDESCOLHATRANSICAO 2

class SeletorTransicao : public Object
{
private:
    TileSet* tileset = nullptr;            // sprite da plataforma
    Animation* left;
    Animation* right;

    uint espacamentoX[QTDESCOLHATRANSICAO];                         // contem o espacamento de cada elemento
    uint posicaoY[QTDESCOLHATRANSICAO];                         // contem o espacamento de cada elemento
    uint position;

    Color color;                            // cor da plataforma
    uint level;

public:
    SeletorTransicao(Color tinta);                   // construtor    
    ~SeletorTransicao();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    int Position();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif