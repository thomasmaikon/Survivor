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
    MoveTo(window->CenterX(), window->Height()-80.0f, Layer::FRONT);
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

    if (obj->Type() == PLATFORM) { 

            isJumping = false;

            if(!isJumping)
                MoveTo(x, obj->Y() - 32);

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

            if (window->KeyDown(VK_LEFT) )
            {
                Translate(-150 * gameTime, 0);
                GravityGuy::audio->Frequency(MOVINGPLAYER, 0.9f);
            }

            
            
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    //gravidade
    
    Translate(0, 100 * gameTime);

    if (window->KeyPress(VK_UP))
    {
        isJumping = true;
        //MoveTo(x, window->Height() - 60);
        int xapica = 0;
        while(xapica < 150 ){
        Translate(50 * gameTime, -500 * gameTime);
        xapica += 1;
        }
        xapica = 0;
    }
   
   

    //Translate(-100 * gameTime, 0);// empurrado para tras por nao fazer nada
    
    // atualiza animação
    //anim->Select(gravity);
    anim->NextFrame();    
    

}

// ---------------------------------------------------------------------------------