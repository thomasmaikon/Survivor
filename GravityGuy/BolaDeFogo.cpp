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

#include "BolaDeFogo.h"
#include "Timer.h"
#include "Level1.h"
// ---------------------------------------------------------------------------------

BolaDeFogo::BolaDeFogo(float posX, float posY, Color tinta, uint level) : color(tinta)
{
    this->level = level;
    bolaDeFogo = new TileSet("Resources/FireBall.png", 40, 50, 4, 8);
    uint caindo[5] = { 0,1,2,3,4 };
    uint bateu[4] = { 5,6,7 };
    anim = new Animation(bolaDeFogo, 0.05f, true);
    
    anim->Add(DOWN, caindo, 5);
    anim->Add(COLLIDED, bateu, 3);

    BBox(new Rect(
        -1.0f * bolaDeFogo->TileWidth() / 2.0f,
        -1.0f * bolaDeFogo->TileHeight() / 2.0f,
        bolaDeFogo->TileWidth() / 2.0f,
        bolaDeFogo->TileHeight() / 2.0f));

    MoveTo(posX, posY, Layer::FRONT);
   
    anim->Select(DOWN);
    type = COIN;
}



// ---------------------------------------------------------------------------------

BolaDeFogo::~BolaDeFogo() {
    delete bolaDeFogo;
    delete anim;
}


// -------------------------------------------------------------------------------

void BolaDeFogo::OnCollision(Object* obj) 
{
    if (isFirst) {
        isFirst = false;
        GravityGuy::audio->Play(FIRE); 
        anim->Select(EXPLOSION::COLLIDED);
        collided = true;
        MoveTo(x, obj->Y() - 40, z);
    }
}

// -------------------------------------------------------------------------------

void BolaDeFogo::Draw()
{
    anim->Draw(x, y, z, color);
}

// -------------------------------------------------------------------------------

void BolaDeFogo::Update()
{
    // \gravidade 
    Translate(0, 200 * gameTime);

    anim->NextFrame();
    short endFrame = 7;
    if (collided && anim->Frame() == endFrame)
    {
        switch (level)
        {
        default:
        case 1:
            Level1::scene->Delete();
            break;
        }
    }
}

