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
    score = 0;

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
        (tileset->TileHeight() / 2.0f)-10));
    
    // inicializa estado do player
    typeAnim = CAINDO;
    
    level = 0;
    type = PLAYER;
    // posição inicial
    MoveTo(window->CenterX(), window->Height()-80.0f, Layer::FRONT);
    jump = 0;

    platformCollided = false;
    soundControllerMove = true;
    colidiu = false;
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
    MoveTo(window->CenterX(), window->Height() - 120.0f, Layer::FRONT);
    typeAnim = CAINDO;
    level = 0;
    score = 0;
    isJumping = false;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{

    if (obj->Type() == PLATFORM) {  
        auto* plat = (Platform*)obj;
        
        colidiu = true;
        
        if(plat->Y() >= y) // o player esta na parte de cima
        {
            if (!isJumping)
                MoveTo(x, plat->Y()-(tileset->Height()/3));
        }else if (plat->Y() + plat->Altura() <= y) // o player esta na parte de baixo
        {
            //if(!isJumping)
                MoveTo(x, plat->Y() + plat->Altura() + (tileset->Height() / 4));
        }else if( plat->Y() <= y && plat->X() - (plat->Largura() / 2) >= x) // o player esta batendo ou na lateral esquerda ou direita
        {
            MoveTo(plat->X() - (plat->Largura()/2) - 20, y); // esta batendo na esquerda
            
        }else
        {
            MoveTo(plat->X() + (plat->Largura() / 2) +20, y); // esta batendo na direita
        }

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
        if(window->KeyPress(VK_UP))
        {
            isJumping = true;
        }
       
    }
    if (obj->Type() == ListTypes::COIN)
        ++score;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    //gravidade
    Translate(0, 300 * gameTime);

   if(isJumping)
   {
       GravityGuy::audio->Stop(MOVINGPLAYER);
       if (jump < 10)
       {
           ++jump;
           Translate(50 * gameTime, -700 * gameTime);
           colidiu = false;
       }
       else if(!colidiu)
       {
           Translate(50 * gameTime, 0);
       }
       else {
           jump = 0;
           isJumping = false;
           GravityGuy::audio->Play(MOVINGPLAYER, true);
       }
   }
  
   
    if (window->KeyDown(VK_DOWN))
    {
        Translate(0, 300 * gameTime);
    }

    //Translate(-100 * gameTime, 0);// empurrado para tras por nao fazer nada
    
    // atualiza animação
    //anim->Select(gravity);
    anim->NextFrame();    
    

}

// ---------------------------------------------------------------------------------