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
#include "GameOver.h"
#include "GravityGuy.h"
#include "Home.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
    title = new Sprite("Resources/GameOver.png");
    GravityGuy::audio->Volume(DEATH, GravityGuy::musica);
    GravityGuy::audio->Play(DEATH, true);
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
    {
        GravityGuy::audio->Stop(DEATH);
        GravityGuy::NextLevel<Home>();
    }
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    GravityGuy::sysFont->Draw(window->CenterX() - 40, 350, "Pressione [ENTER]", Color(0.9F, 0.9f, 0.0f, 1.0f), Layer::FRONT, 0.8f);
    title->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete title;
}

// ----------------------------------------------------------------------

