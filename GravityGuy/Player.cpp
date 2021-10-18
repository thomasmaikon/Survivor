/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/


#include "Player.h"
#include "GravityGuy.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/dino.png", 40, 48, 4, 8);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint invert[4] = {1};
    uint normal[4] = {1,2,3,4};

    anim->Add(ANDANDO, normal, 4);
    anim->Add(CAINDO, invert, 1);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    typeAnim = CAINDO;
    
    level = 0;
    type = PLAYER;
    // posição inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    jump = 0;

    platformCollided = false;
    soundControllerMove = true;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    typeAnim = CAINDO;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() != COIN) {
        MoveTo(x, obj->Y() - 32);
    }

    if (obj->Type() == PLATFORM) { 
        
            platformCollided = true;
            if (soundControllerMove) {
                GravityGuy::audio->Play(MOVINGPLAYER, true);
                soundControllerMove = false;
            }
            anim->Select(ANDANDO);

            if (window->KeyDown(VK_RIGHT))
            {
                Translate(300 * gameTime, 0);
                GravityGuy::audio->Frequency(MOVINGPLAYER, 1.1f);
            }

            if (window->KeyDown(VK_LEFT) && platformCollided)
            {
                Translate(-150 * gameTime, 0);
                GravityGuy::audio->Frequency(MOVINGPLAYER, 0.9f);
            }
           
            if (window->KeyPress(VK_UP) && platformCollided)
            {
                //Translate(0, -4800 * gameTime);
                isJumping = true;
            }else{ isJumping = false; }
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    //gravidade
    
    Translate(0, 100 * gameTime);

    if(window->KeyDown(VK_DOWN))
    {
        Translate(0, 300 * gameTime);
    }

    if(isJumping)
    {
        if (jump <= 2400) {
            jump += 400;
            Translate(400 * gameTime, -600 * gameTime);
            GravityGuy::audio->Stop(MOVINGPLAYER);
            anim->Select(CAINDO);
        }
        else {
            isJumping = false; jump = 0;
            Translate(200 * gameTime, 0);
            soundControllerMove = true;
        }
        
    }

    Translate(-100 * gameTime, 0);// empurrado para tras por nao fazer nada
    
    // atualiza animação
    //anim->Select(gravity);
    anim->NextFrame();    
    

}

// ---------------------------------------------------------------------------------