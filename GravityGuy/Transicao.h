#pragma once

#ifndef _SURVIVOR_TRANSICAO_H_
#define _SURVIVOR_TRANSICAO_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "SeletorTransicao.h"
#include <sstream>
using namespace std;
// ------------------------------------------------------------------------------

class Transicao : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo
    SeletorTransicao* select = nullptr;
    uint level;

public:
    Transicao();

    void Init();                    // inicia nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nível
    stringstream score;
};

// -----------------------------------------------------------------------------

#endif