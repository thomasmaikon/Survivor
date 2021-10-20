#pragma once

#ifndef _GRAVITYGUY_TRANSICAO_H_
#define _GRAVITYGUY_TRANSICAO_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "SeletorTransicao.h"
// ------------------------------------------------------------------------------

class Transicao : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo
    SeletorTransicao* select = nullptr;
    uint level;

public:
    Transicao();

    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif