/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = x;

    // carrega imagens
    imgF = new Image("Resources/BG.png");

    // cria sprites do plano de fundo
 
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete imgF;   
    delete backgF1;
    delete backgF2;

}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
    xF -= 200 * gameTime;

}

// -------------------------------------------------------------------------------

void Background::Draw()
{


    // desenha prédios mais próximos
    backgF1->Draw(xF, y, Layer::MIDDLE, 1.0f, 0.0f, color);
    backgF2->Draw(xF + imgF->Width(), window->Height()/2.0f, Layer::MIDDLE, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width()/2.0f < 0)
        xF += imgF->Width();
}

// -------------------------------------------------------------------------------
