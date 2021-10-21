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

#ifndef _SURVIVOR_H_
#define _SURVIVOR_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Player.h"
#include "Resources.h"
#include "Font.h"
// ------------------------------------------------------------------------------

enum Sounds {MENU, MUSIC, TRANSITION, GETCOIN, MOVINGPLAYER, FIRE, DEATH, DUNGEON,TESTSOUNDMUSIC, TESTSOUNDEFFECT};
    
// ------------------------------------------------------------------------------
class Survivor : public Game
{
private:
    static Game * level;            // nível atual do jogo

public:
    static Player * player;         // jogador 
    static Audio * audio;           // sistema de áudio
    static bool viewBBox;           // estado da bounding box

    static Font* titleFont;     // fonte do título 
    static Font* gameFont;     // fonte do jogo
    static Font* sysFont;     // fonte padrão

    static float musica;
    static float efeito;

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif