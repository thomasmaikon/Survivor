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

#include "Chegada.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Chegada::Chegada(float posX, float posY, Color tinta, uint level) : color(tinta)
{
    this->level = level;
    chegada = new TileSet("Resources/pontoChegada.png", 128, 128, 8, 32);
    uint animation[8] = { 0,1,2,3,4,5,6,7 };
    anim = new Animation(chegada, 0.05f, true);
    
    anim->Add(0,animation,8);

    BBox(new Rect(
        (-1.0f * chegada->TileWidth() / 2.0f)+40,
        (-1.0f * chegada->TileHeight() / 2.0f) + 55,
        (chegada->TileWidth() / 2.0f)-40,
        (chegada->TileHeight() / 2.0f)-20));

    MoveTo(posX, posY, Layer::FRONT);

  //  anim->Select(DOWN);
    type = ListTypes::CHECKPOINT;
}



// ---------------------------------------------------------------------------------

Chegada::~Chegada() {
    delete chegada;
    delete anim;
}


// -------------------------------------------------------------------------------

void Chegada::OnCollision(Object* obj)
{
    if (obj->Type() == PLATFORM)
        MoveTo(x, obj->Y() - 50, z);
}

// -------------------------------------------------------------------------------

void Chegada::Draw()
{
    anim->Draw(x, y, z, color);
}

// -------------------------------------------------------------------------------

void Chegada::Update()
{
    anim->NextFrame();
    Translate(-200 * gameTime, 200 * gameTime); // acompanha os demais objetos
}

