/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Vitoria.h"
#include "Survivor.h"
#include "Home.h"

// ----------------------------------------------------------------------


void Vitoria::Init()
{
    tile = new Sprite("Resources/win.png");
}

// ----------------------------------------------------------------------

void Vitoria::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
    {
        Survivor::NextLevel<Home>();
    }
}

// ----------------------------------------------------------------------

void Vitoria::Draw()
{
    Survivor::sysFont->Draw(window->CenterX() - 40, 350, "Pressione [ENTER]", Color(0.9F, 0.9f, 0.0f, 1.0f), Layer::FRONT, 0.8f);
    tile->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ----------------------------------------------------------------------

void Vitoria::Finalize()
{
    delete tile;
}

// ----------------------------------------------------------------------

