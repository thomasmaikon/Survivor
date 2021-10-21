/**********************************************************************************
// Background (Arquivo de Cabeçalho)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _SURVIVOR_BACKGROUND_H_
#define _SURVIVOR_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xF;                       // posição horizontal dos sprites
    Image * imgF;                       // imagem de fundo frontal
    Sprite * backgF1;                   // pano de fundo dinâmico (frontal 1)
    Sprite * backgF2;                   // pano de fundo dinâmico (frontal 2)
    Color color;                        // cor do pano de fundo

public:
    Background(Color tint, int level);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif