/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
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

    // sequ�ncias de anima��o do player
    uint invert[4] = {6,7,8,9};
    uint normal[4] = {1,2,3,4};

    anim->Add(INVERTED, invert, 4);
    anim->Add(NORMAL, normal, 4);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = NORMAL;  
    level = 0;
    type = PLAYER;
    // posi��o inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    jump = 0;
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
    gravity = NORMAL;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() != COIN) {
        MoveTo(x, obj->Y() - 32);
    }

   /*if (obj->Type() == FINISH)
    {
        // chegou ao final do n�vel
        level++;
    }
    else
    {
        // mant�m personagem em cima da plataforma
       // if (gravity == NORMAL)
           
        //else
         //   MoveTo(window->CenterX(), obj->Y() + 32);
    }*/

    if (obj->Type() == PLATFORM) { isCollided = true; }
    else{ isCollided = false; }

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar
    // ----------------------------------------------------------

    if (window->KeyPress(VK_SPACE))
    {
        gravity = !gravity;

        // toca efeito sonoro
        //GravityGuy::audio->Play(TRANSITION);

        // tira player da plataforma para evitar 
        // detec��o de colis�o no quadro seguinte
        //if (gravity == NORMAL)
            //Translate(0, 12);
        //else
            //Translate(0 , -12);
    }
    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    Translate(0, 300 * gameTime);
    
    if (window->KeyDown(VK_RIGHT) && isCollided) 
    {
        Translate(300 * gameTime, 0);
        GravityGuy::audio->Play(MOVINGPLAYER);

    }

    if (window->KeyDown(VK_LEFT) && isCollided)
    {
        Translate(-300 * gameTime, 0);
        GravityGuy::audio->Play(MOVINGPLAYER);
    }

    if(window->KeyDown(VK_DOWN))
        Translate(0, 300 * gameTime);

    if ((window->KeyPress(VK_UP)|| isJumping) && isCollided) {
            //altura testada e recomendada � 1100
            if (jump <= 1200)
            {
                isJumping = true;
                jump += 200;
            }
            else {
                isJumping = false;
                jump = 0;
            }
        Translate(0, -jump * gameTime);
    }
        
    
    // atualiza anima��o
    anim->Select(gravity);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------