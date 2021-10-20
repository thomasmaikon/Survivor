#pragma once


#ifndef _GRAVITYGUY_SELECTORCONFIGURACAO_H_
#define _GRAVITYGUY_SELECTORCONFIGURACAO_H_

#include "GravityGuy.h"
#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ---------------------------------------------------------------------------------
enum TYPE { MUSICA, EFEITO, RETORNAR };

#define QTDESCOLHACONFIG 3

class SeletorConfiguracao : public Object
{
private:
    TileSet* tileset = nullptr;            // sprite da plataforma
    Animation* left;
    Animation* right;

    uint espacamentoX[QTDESCOLHACONFIG];                         // contem o espacamento de cada elemento
    uint posicaoY[QTDESCOLHACONFIG];                         // contem o espacamento de cada elemento
    uint position;

    Color color;                            // cor da plataforma
    uint level;

public:
    SeletorConfiguracao(Color tinta);                   // construtor    
    ~SeletorConfiguracao();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    int Position();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline
#endif