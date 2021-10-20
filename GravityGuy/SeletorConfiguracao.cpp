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
    espacamentoX[TYPE::RETORNAR] = 100;

    posicaoY[TYPE::MUSICA] = 195;
    posicaoY[TYPE::EFEITO] = 240;
    posicaoY[TYPE::RETORNAR] = 295;

    // configurando box do + e - para som
    tileset = new TileSet("Resources/menos.png", 40, 32, 4, 4);
    left = new Animation(tileset, 0.05f, true);

    tileset = new TileSet("Resources/mais.png", 40, 32, 4, 4);
    right = new Animation(tileset, 0.05f, true);
    
    // configurando box dos passaros para retorno
    tileset = new TileSet("Resources/fly.png", 40, 32, 4, 4);
    birdLeft = new Animation(tileset, 0.05f, true);

    tileset = new TileSet("Resources/fly2.png", 40, 32, 4, 4);
    birdRight = new Animation(tileset, 0.05f, true);


    uint amarelo[1] = { 0 };
    uint vermelho[1] = { 1 };
    left->Add(1, vermelho, 1); // adiciona a cor vermelha
    left->Add(0, amarelo, 1); // adiciona a cor amarela
    
    right->Add(1, vermelho,1);// vermelho
    right->Add(0, amarelo, 1); // amarelo

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
    delete birdLeft;
    delete birdRight;
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

    if (position != TYPE::RETORNAR) // so altera a cor se estiver no local correto
    {
        if (window->KeyDown(VK_LEFT)) 
            left->Select(1);
        else 
            left->Select(0);

        if (window->KeyDown(VK_RIGHT)) 
            right->Select(1);
        else 
            right->Select(0);

        left->NextFrame();
        right->NextFrame();
    }else
    {
        birdLeft->NextFrame();
        birdRight->NextFrame();
    }

    // move plataforma apenas no eixo x
    
}

// -------------------------------------------------------------------------------

void SeletorConfiguracao::Draw()
{
    if(position != TYPE::RETORNAR)
    {
        left->Draw(window->CenterX() - espacamentoX[position], posicaoY[position], z);
        right->Draw(window->CenterX() + espacamentoX[position], posicaoY[position], z);
    }
    else {
        birdLeft->Draw(window->CenterX() - espacamentoX[position], posicaoY[position], z);
        birdRight->Draw(window->CenterX() + espacamentoX[position], posicaoY[position], z);
    }
    
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