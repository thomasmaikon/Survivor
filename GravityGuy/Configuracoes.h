/**********************************************************************************
// GravityGuy (Arquivo de Cabeçalho)
//
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _CONFIGURACOES_H_
#define _CONFIGURACOES_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Player.h"
#include "Resources.h"
#include "SeletorConfiguracao.h"

// ------------------------------------------------------------------------------

class Configuracoes : public Game
{
private:
    SeletorConfiguracao* select = nullptr;

    float musica;
    float efeito;

    Sprite* barra = nullptr;
    Sprite* nivel = nullptr;

public:
    Configuracoes();

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

};

// ---------------------------------------------------------------------------------

#endif