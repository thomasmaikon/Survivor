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

#include "Moeda.h"
#include "Timer.h"
#include "Level1.h"
#include "Level2.h"

// ---------------------------------------------------------------------------------

Moeda::Moeda(float posX, float posY, Color tinta, uint level) : color(tinta)
{
    this->level = level;
    moeda = new TileSet("Resources/moeda.png", 32, 32, 8, 8);
    anim = new Animation(moeda, 0.05f, true);

    /*BBox(new Rect(
        (-1.0f * moeda->TileWidth() / 2.0f )+10,
        (-1.0f * moeda->TileHeight() / 2.0f),
        (moeda->TileWidth() / 2.0f)-10,
        (moeda->TileHeight() / 2.0f)-10));*/
    
    BBox(new Circle(16.0f));

    MoveTo(posX, posY, Layer::FRONT);
    anim->Select(0);
    type = COIN;
}

// ---------------------------------------------------------------------------------

Moeda::~Moeda()
{
    delete moeda;
    delete anim;
}

// -------------------------------------------------------------------------------

void Moeda::Update()
{
    // move plataforma apenas no eixo x
    Translate(-200.0f * gameTime, 500.0f * gameTime);
    anim->NextFrame();
}

// -------------------------------------------------------------------------------

void Moeda::OnCollision(Object* obj) {
    
    if( obj->Type() == PLAYER)
    {
        GravityGuy::audio->Play(GETCOIN);
        colided = true;
        //MoveTo(LIMBOX, LIMBOY, z);
    }
    if(obj->Type() == ListTypes::PLATFORM)
        MoveTo(x, obj->Y() - 26, z);
}

// -------------------------------------------------------------------------------

void Moeda::Draw()
{
   anim->Draw(x, y, z, color);
   
   if(colided)
   {
       switch (level)
       {
       case 1:
           Level1::scene->Delete();
           break;
       case 2:
           Level2::scene->Delete();
           break;
       default:
           break;
       }
   }
}