#pragma once

#include "Engine.h"
#include "GravityGuy.h"
#include "Transicao.h"
#include "Level2.h"
#include "Home.h"

Transicao::Transicao(){}

// ------------------------------------------------------------------------------

void Transicao::Init()
{
    backg = new Sprite("Resources/transicao.png");
    select = new SeletorTransicao(Color{ 1,1,1,1 });

    GravityGuy::audio->Play(MENU, true);
}

// ------------------------------------------------------------------------------

void Transicao::Update()
{


    switch (select->Position())
    {
    case TRANSICAONIVEL::CONTINUAR:
        GravityGuy::audio->Stop(MENU);
        GravityGuy::NextLevel<Level2>();
        break;

    case TRANSICAONIVEL::RETORNARMENU:
        //GravityGuy::audio->Play(MENU, true);
        GravityGuy::NextLevel<Home>();
        break;

    default:
        select->Update();
        break;
    }
}

// ------------------------------------------------------------------------------

void Transicao::Draw()
{
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