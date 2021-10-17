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

// ---------------------------------------------------------------------------------

Moeda::Moeda(float posX, float posY, Color tinta) : color(tinta)
{
    
    moeda = new TileSet("Resources/moeda.png", 32, 32, 8, 8);
    anim = new Animation(moeda, 0.05f, true);

    BBox(new Rect(
        -1.0f * moeda->TileWidth() / 2.0f,
        -1.0f * moeda->TileHeight() / 2.0f,
        moeda->TileWidth() / 2.0f,
        moeda->TileHeight() / 2.0f));

    MoveTo(posX, posY, Layer::FRONT);
    anim->Select(0);
    type = COIN;
}

// ---------------------------------------------------------------------------------

Moeda::~Moeda()
{
    delete moeda;
}

// -------------------------------------------------------------------------------

void Moeda::Update()
{
    // move plataforma apenas no eixo x
    //Translate(-200.0f * gameTime, 0);
    anim->NextFrame();
}

// -------------------------------------------------------------------------------

void Moeda::OnCollision(Object* obj) {
    
    if( obj->Type() == PLAYER && isFirst)
    {
        isFirst = false;
        GravityGuy::audio->Play(GETCOIN);
        colided = true;
        //Translate(x, y-50);
        //Timer timer;
        //timer.Elapsed(1.90f);
        MoveTo(LIMBOX, LIMBOY, z);
    }
}

// -------------------------------------------------------------------------------

void Moeda::Draw()
{
    if (!colided) {
        
        anim->Draw(x, y, z, color);
    }
}