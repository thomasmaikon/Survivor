/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _SURVIVOR_HOME_H_
#define _SURVIVOR_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "SeletorMenu.h"
// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    SeletorMenu* select = nullptr;

public:
    void Init();                    // inicia n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif