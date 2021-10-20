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
#include "SeletorMenu.h"

// ---------------------------------------------------------------------------------

SeletorMenu::SeletorMenu(Color tinta) : color(tinta)
{
    espacamentoX[CONTROLLERMENU::PLAY] = 75;
    espacamentoX[CONTROLLERMENU::SETTINGS] = 115;
    espacamentoX[CONTROLLERMENU::EXIT] = 75;

    posicaoY[CONTROLLERMENU::PLAY] = 210;
    posicaoY[CONTROLLERMENU::SETTINGS] = 280;
    posicaoY[CONTROLLERMENU::EXIT] = 345;


    tileset = new TileSet("Resources/fly.png", 40, 32, 4, 4);
    left = new Animation(tileset, 0.1f, true);
    
    tileset = new TileSet("Resources/fly2.png", 40, 32, 4, 4);
    right = new Animation(tileset, 0.1f, true);

    left->Draw(window->CenterX() - espacamentoX[CONTROLLERMENU::PLAY], posicaoY[CONTROLLERMENU::PLAY], Layer::FRONT);
    
    uint invert[4] = { 3,2,1,0 };
    right->Draw(window->CenterX() + espacamentoX[CONTROLLERMENU::PLAY] , posicaoY[CONTROLLERMENU::PLAY], Layer::FRONT);

    position = CONTROLLERMENU::PLAY;
}

// ---------------------------------------------------------------------------------

SeletorMenu::~SeletorMenu()
{
    delete tileset;
    delete left;
    delete right;
}

// -------------------------------------------------------------------------------

void SeletorMenu::Update()
{
    if (window->KeyPress(VK_UP)) {// A SETA PRA CIMA NAO ESTA FUNCIONANDO
        if (position == 0) { position = QTDESCOLHASSELETOR; }
        position = (position - 1) % QTDESCOLHASSELETOR;
    }

    if (window->KeyPress(VK_DOWN)) {
        position = (position + 1) % 3;
    }

    // move plataforma apenas no eixo x
    left->NextFrame();
    right->NextFrame();
}

// -------------------------------------------------------------------------------

void SeletorMenu::Draw()
{
    left->Draw(window->CenterX() - espacamentoX[position], posicaoY[position], z);
    right->Draw(window->CenterX() + espacamentoX[position], posicaoY[position], z);
}

// -------------------------------------------------------------------------------

int SeletorMenu::Position() {
    if(window->KeyPress(VK_RETURN))
        return position; 
    
    return -1;
}