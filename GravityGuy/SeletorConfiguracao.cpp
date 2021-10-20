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
#include "SeletorConfiguracao.h"

// ---------------------------------------------------------------------------------

SeletorConfiguracao::SeletorConfiguracao(Color tinta) : color(tinta)
{
    espacamentoX[TYPE::MUSICA] = 150;
    espacamentoX[TYPE::EFEITO] = 150;


    posicaoY[TYPE::MUSICA] = 200;
    posicaoY[TYPE::EFEITO] = 245;



    tileset = new TileSet("Resources/fly.png", 40, 32, 4, 4);
    left = new Animation(tileset, 0.05f, true);

    tileset = new TileSet("Resources/fly2.png", 40, 32, 4, 4);
    right = new Animation(tileset, 0.05f, true);

    left->Draw(window->CenterX() - espacamentoX[TYPE::MUSICA], posicaoY[TYPE::MUSICA], Layer::FRONT);

    uint invert[4] = { 3,2,1,0 };
    right->Draw(window->CenterX() + espacamentoX[TYPE::MUSICA], posicaoY[TYPE::MUSICA], Layer::FRONT);

    position = TYPE::MUSICA;
}

// ---------------------------------------------------------------------------------

SeletorConfiguracao::~SeletorConfiguracao()
{
    delete tileset;
    delete left;
    delete right;
}

// -------------------------------------------------------------------------------

void SeletorConfiguracao::Update()
{
    if (window->KeyPress(VK_UP)) {// A SETA PRA CIMA NAO ESTA FUNCIONANDO
        if (position == 0) { position = QTDESCOLHACONFIG; }
        position = (position - 1) % QTDESCOLHACONFIG;
    }

    if (window->KeyPress(VK_DOWN)) {
        position = (position + 1) % QTDESCOLHACONFIG;
    }

    // move plataforma apenas no eixo x
    left->NextFrame();
    right->NextFrame();
}

// -------------------------------------------------------------------------------

void SeletorConfiguracao::Draw()
{
    left->Draw(window->CenterX() - espacamentoX[position], posicaoY[position], z);
    right->Draw(window->CenterX() + espacamentoX[position], posicaoY[position], z);
}

// -------------------------------------------------------------------------------

int SeletorConfiguracao::Position() 
{
    if(position == TYPE::RETORNAR)
    {
        if (window->KeyPress(VK_RETURN)) { return position; }
        return -1;
    }
    
    return position;
}