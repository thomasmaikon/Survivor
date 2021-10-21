/**********************************************************************************
// GravityGuy (Arquivo de Cabe�alho)
// 
// Cria��o:     05 Out 2011
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
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
    static Game * level;            // n�vel atual do jogo

public:
    static Player * player;         // jogador 
    static Audio * audio;           // sistema de �udio
    static bool viewBBox;           // estado da bounding box

    static Font* titleFont;     // fonte do t�tulo 
    static Font* gameFont;     // fonte do jogo
    static Font* sysFont;     // fonte padr�o

    static float musica;
    static float efeito;

    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
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