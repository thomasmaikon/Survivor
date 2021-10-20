/**********************************************************************************
// GravityGuy (C�digo Fonte)
// 
// Cria��o:     05 Out 2011
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game*   GravityGuy::level = nullptr;
Player* GravityGuy::player = nullptr;
Audio*  GravityGuy::audio = nullptr;
bool    GravityGuy::viewBBox = false;

float    GravityGuy::efeito = 1.0f;
float    GravityGuy::musica = 1.0f;

Font* GravityGuy::titleFont = nullptr;     // fonte do t�tulo 
Font* GravityGuy::gameFont = nullptr;     // fonte do jogo
Font* GravityGuy::sysFont = nullptr;     // fonte padr�o

// ------------------------------------------------------------------------------

void GravityGuy::Init() 
{

    titleFont = new Font("Resources/Bauhaus72.png");
    titleFont->Spacing("Resources/Bauhaus72.dat");

    gameFont = new Font("Resources/Tahoma16.png");
    gameFont->Spacing("Resources/Tahoma16.dat");

    sysFont = new Font("Resources/Tahoma10.png");
    sysFont->Spacing("Resources/Tahoma10.dat");


    // cria sistema de �udio
    audio = new Audio();
    audio->Add(MENU, "Resources/sounds/menu.wav");
    audio->Add(MUSIC, "Resources/Music.wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");
    audio->Add(GETCOIN, "Resources/sounds/moeda_sound.wav");
    audio->Add(DEATH, "Resources/sounds/morte.wav");
    audio->Add(MOVINGPLAYER, "Resources/sounds/andando.wav");
    audio->Add(FIRE, "Resources/sounds/fire.wav");

    audio->Add(TESTSOUNDMUSIC, "Resources/sounds/musicaTeste.wav");
    audio->Add(TESTSOUNDEFFECT, "Resources/sounds/fire.wav");

    // bounding box n�o vis�vel
    viewBBox = false;

    // cria jogador
    player = new Player();

    // inicializa n�vel de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void GravityGuy::Update()
{
    // habilita/desabilita visualiza��o da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza n�vel
    level->Update();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Draw()
{
    // desenha n�vel
    level->Draw();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(800, 400);
    engine->window->Color(30, 50, 80);
    engine->window->Title("Gravity Guy");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new GravityGuy());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

