/**********************************************************************************
// Level2 (Arquivo de Cabe�alho)
//
// Cria��o:     27 Set 2021
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 2 do jogo
//
**********************************************************************************/

#ifndef _SURVIVOR_LEVEL2_H_
#define _SURVIVOR_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include <sstream>

using namespace std;
// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado

public:
    static Scene* scene;           // cena do n�vel
    stringstream score;

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel

    void inserirMoedaPlataforma(int posicaoInicial, int qtd, int level);
    void inserirBolasDeFogo(int posicaoFinal, int qtd, int level);
};

// -----------------------------------------------------------------------------

#endif