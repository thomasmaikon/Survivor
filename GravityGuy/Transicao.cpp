#pragma once

#include "Engine.h"
#include "Survivor.h"
#include "Transicao.h"
#include "Level2.h"
#include "Home.h"

Transicao::Transicao(){}

// ------------------------------------------------------------------------------

void Transicao::Init()
{
    backg = new Sprite("Resources/transicao.png");
    select = new SeletorTransicao(Color{ 1,1,1,1 });

    Survivor::audio->Play(MENU, true);
}

// ------------------------------------------------------------------------------

void Transicao::Update()
{


    switch (select->Position())
    {
    case TRANSICAONIVEL::CONTINUAR:
        Survivor::audio->Stop(MENU);
        Survivor::NextLevel<Level2>();
        break;

    case TRANSICAONIVEL::RETORNARMENU:
        //GravityGuy::audio->Play(MENU, true);
        Survivor::NextLevel<Home>();
        break;

    default:
        select->Update();
        break;
    }
}

// ------------------------------------------------------------------------------

void Transicao::Draw()
{
    score.str("");
    score << "Score: " << Survivor::player->score;
    Survivor::gameFont->Draw(30, 30, score.str(), Color{ 1.0f,1.0f,1.0f,1.0f });

    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    select->Draw();
}

// ------------------------------------------------------------------------------

void Transicao::Finalize()
{
    delete select;
    delete backg;
}

// ------------------------------------------------------------------------------