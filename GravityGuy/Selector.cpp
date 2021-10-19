/**********************************************************************************
// Platform (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/
#include "Level1.h"
#include "Level2.h"
#include "Selector.h"

// ---------------------------------------------------------------------------------

Selector::Selector(Color tinta) : color(tinta)
{
    espacamentoX[CONTROLLER::PLAY] = 75;
    espacamentoX[CONTROLLER::SETTINGS] = 115;
    espacamentoX[CONTROLLER::EXIT] = 75;

    posicaoY[CONTROLLER::PLAY] = 210;
    posicaoY[CONTROLLER::SETTINGS] = 280;
    posicaoY[CONTROLLER::EXIT] = 345;


    tileset = new TileSet("Resources/fly.png", 40, 32, 4, 4);
    left = new Animation(tileset, 0.05f, true);
    
    tileset = new TileSet("Resources/fly2.png", 40, 32, 4, 4);
    right = new Animation(tileset, 0.05f, true);

    left->Draw(window->CenterX() - espacamentoX[CONTROLLER::PLAY], posicaoY[CONTROLLER::PLAY], Layer::FRONT);
    
    uint invert[4] = { 3,2,1,0 };
    right->Draw(window->CenterX() + espacamentoX[CONTROLLER::PLAY] , posicaoY[CONTROLLER::PLAY], Layer::FRONT);

    position = CONTROLLER::PLAY;
}

// ---------------------------------------------------------------------------------

Selector::~Selector()
{
    delete tileset;
    delete left;
    delete right;
}

// -------------------------------------------------------------------------------

void Selector::Update()
{
    if (window->KeyPress(VK_UP)) {// A SETA PRA CIMA NAO ESTA FUNCIONANDO
        if (position == 0) { position = 3; }
        position = (position - 1) % 3;
    }

    if (window->KeyPress(VK_DOWN)) {
        position = (position + 1) % 3;
    }

    // move plataforma apenas no eixo x
    left->NextFrame();
    right->NextFrame();
}

// -------------------------------------------------------------------------------

void Selector::Draw()
{
    left->Draw(window->CenterX() - espacamentoX[position], posicaoY[position], z);
    right->Draw(window->CenterX() + espacamentoX[position], posicaoY[position], z);
}

// -------------------------------------------------------------------------------

int Selector::Position() { 
    if(window->KeyPress(VK_RETURN))
        return position; 
    
    return -1;
}