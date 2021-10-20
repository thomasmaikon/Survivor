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
#include "SeletorTransicao.h"

// ---------------------------------------------------------------------------------

SeletorTransicao::SeletorTransicao(Color tinta) : color(tinta)
{
    espacamentoX[TRANSICAONIVEL::CONTINUAR] = 125;
    espacamentoX[TRANSICAONIVEL::RETORNARMENU] = 160;


    posicaoY[TRANSICAONIVEL::CONTINUAR] = 200;
    posicaoY[TRANSICAONIVEL::RETORNARMENU] = 245;



    tileset = new TileSet("Resources/fly.png", 40, 32, 4, 4);
    left = new Animation(tileset, 0.05f, true);

    tileset = new TileSet("Resources/fly2.png", 40, 32, 4, 4);
    right = new Animation(tileset, 0.05f, true);

    left->Draw(window->CenterX() - espacamentoX[TRANSICAONIVEL::CONTINUAR], posicaoY[TRANSICAONIVEL::CONTINUAR], Layer::FRONT);

    uint invert[4] = { 3,2,1,0 };
    right->Draw(window->CenterX() + espacamentoX[TRANSICAONIVEL::CONTINUAR], posicaoY[TRANSICAONIVEL::CONTINUAR], Layer::FRONT);

    position = TRANSICAONIVEL::CONTINUAR;
}

// ---------------------------------------------------------------------------------

SeletorTransicao::~SeletorTransicao()
{
    delete tileset;
    delete left;
    delete right;
}

// -------------------------------------------------------------------------------

void SeletorTransicao::Update()
{
    if (window->KeyPress(VK_UP)) {// A SETA PRA CIMA NAO ESTA FUNCIONANDO
        if (position == 0) { position = QTDESCOLHATRANSICAO; }
        position = (position - 1) % QTDESCOLHATRANSICAO;
    }

    if (window->KeyPress(VK_DOWN)) {
        position = (position + 1) % QTDESCOLHATRANSICAO;
    }

    // move plataforma apenas no eixo x
    left->NextFrame();
    right->NextFrame();
}

// -------------------------------------------------------------------------------

void SeletorTransicao::Draw()
{
    left->Draw((window->CenterX() - 185) - espacamentoX[position], posicaoY[position], z);
    right->Draw((window->CenterX() - 185) + espacamentoX[position], posicaoY[position], z);
}

// -------------------------------------------------------------------------------

int SeletorTransicao::Position() {
    if (window->KeyPress(VK_RETURN))
        return position;

    return -1;
}