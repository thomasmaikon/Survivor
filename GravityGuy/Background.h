/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _SURVIVOR_BACKGROUND_H_
#define _SURVIVOR_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xF;                       // posi��o horizontal dos sprites
    Image * imgF;                       // imagem de fundo frontal
    Sprite * backgF1;                   // pano de fundo din�mico (frontal 1)
    Sprite * backgF2;                   // pano de fundo din�mico (frontal 2)
    Color color;                        // cor do pano de fundo

public:
    Background(Color tint, int level);             // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif