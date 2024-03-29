/**********************************************************************************
// Background (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint,int level) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = x;

    // carrega imagens
    switch (level)
    {
    case 1:
        imgF = new Image("Resources/BG.png");
        break;
    case 2:
        imgF = new Image("Resources/BG2.png");
        break;
    default:
        imgF = new Image("Resources/BG.png");
        break;
    }
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
    xF -= 150 * gameTime;

}

// -------------------------------------------------------------------------------

void Background::Draw()
{


    // desenha pr�dios mais pr�ximos
    backgF1->Draw(xF, y, Layer::MIDDLE, 1.0f, 0.0f, color);
    backgF2->Draw(xF + imgF->Width(), window->Height()/2.0f, Layer::MIDDLE, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width()/2.0f < 0)
        xF += imgF->Width();
}

// -------------------------------------------------------------------------------
