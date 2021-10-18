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

// ---------------------------------------------------------------------------------

BolaDeFogo::BolaDeFogo(float posX, float posY, Color tinta) : color(tinta)
{

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

BolaDeFogo::~BolaDeFogo()
{
    delete bolaDeFogo;
}

// -------------------------------------------------------------------------------

void BolaDeFogo::Update()
{
    // move plataforma apenas no eixo x
    Translate(0, 100*gameTime);

    if (y > 300) {
        anim->Select(COLLIDED);
        
    }
    anim->NextFrame();
}

// -------------------------------------------------------------------------------

void BolaDeFogo::OnCollision(Object* obj) {

    if (obj->Type() == PLAYER && isFirst)
    {
        isFirst = false;
        GravityGuy::audio->Play(FIRE);
        colided = true;
        MoveTo(LIMBOX, LIMBOY, z);
    }
}

// -------------------------------------------------------------------------------

void BolaDeFogo::Draw()
{
    if (!colided) {

        anim->Draw(x, y, z, color);
    }
}