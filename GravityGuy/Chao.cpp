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

#include "Chao.h"
#include "Timer.h"

// ---------------------------------------------------------------------------------

Chao::Chao(float posX, float posY, Color tinta) : color(tinta)
{
    xF = x;
    chao = new Sprite("Resources/chao.png");
    chao2 = new Sprite("Resources/chao.png");
    //GravityGuy::audio->Frequency(STEP, 0.025f);
    BBox(new Rect(
        -1.0f * chao->Width() / 2.0f,
        -1.0f * chao->Height() / 2.0f,
        chao->Width() / 2.0f,
        chao->Height() / 2.0f));
    BBox(new Rect(
        -1.0f * chao2->Width() / 2.0f,
        -1.0f * chao2->Height() / 2.0f,
        chao2->Width() / 2.0f,
        chao2->Height() / 2.0f));

    MoveTo(posX, posY, Layer::FRONT);
    type = PLATFORM;
}

// ---------------------------------------------------------------------------------

Chao::~Chao()
{
    delete chao;
}

// -------------------------------------------------------------------------------

void Chao::Update()
{
    xF -= 200 * gameTime;
}

// -------------------------------------------------------------------------------

void Chao::OnCollision(Object* obj) {

    if (obj->Type() == PLAYER)
    {
        //GravityGuy::audio->Play(STEP);
    }
}

// -------------------------------------------------------------------------------

void Chao::Draw()
{   
    //chao->Draw(x, y, z);
    // desenha pr�dios mais pr�ximos
    chao->Draw(xF, y, Layer::FRONT, 1.0f, 0.0f, color);
    chao2->Draw(xF + chao->Width(), y, Layer::MIDDLE, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xF + chao->Width() / 2.0f < 0)
        xF += chao->Width();
}
    
