/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Survivor.h"
#include "Home.h"
#include "Level1.h"
#include "Configuracoes.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/TitleScreen.png");
    select = new SeletorMenu(Color{ 1,1,1,1 });
    
    Survivor::audio->Volume(MENU, Survivor::musica);
    Survivor::audio->Play(MENU, true);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    
    
    switch (select->Position())
    {
    case CONTROLLERMENU::PLAY:
        Survivor::audio->Stop(MENU);
        Survivor::NextLevel<Level1>();
        break;

    case CONTROLLERMENU::SETTINGS:
        Survivor::audio->Stop(MENU);
        Survivor::NextLevel<Configuracoes>();
        break;

    case CONTROLLERMENU::EXIT:
        window->Close();
        break;
    default:
        select->Update();
        break;
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    select->Draw();
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete select;
    delete backg;
}

// ------------------------------------------------------------------------------