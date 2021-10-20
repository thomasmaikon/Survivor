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
#include <random>
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

    /*BBox(new Rect(
        -1.0f * bolaDeFogo->TileWidth() / 2.0f,
        -1.0f * bolaDeFogo->TileHeight() / 2.0f,
        bolaDeFogo->TileWidth() / 2.0f,
        bolaDeFogo->TileHeight() / 2.0f));*/
    BBox(new Circle(12.0f));

    MoveTo(posX, posY, Layer::FRONT);
   
    anim->Select(DOWN);
    type = ListTypes::ENEMY;
    
    isOut = (posX <= 850) ? false : true;
}



// ---------------------------------------------------------------------------------

BolaDeFogo::~BolaDeFogo() {
    delete bolaDeFogo;  
    delete anim;
}


// -------------------------------------------------------------------------------

void BolaDeFogo::OnCollision(Object* obj) 
{
    if (isFirst && (obj->Type() == ListTypes::PLAYER || obj->Type() == ListTypes::PLATFORM)) { // evita que ele colida com ele mesmo e so colida com player e plataforma
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
    Translate(-200 * gameTime, 0);
    if (x >= 0 && x <= 800) 
    {
        if(isOut)
        {
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(200, 800); // para o caso de algum objeto estar fora da tela antes de entrar
            isOut = false;
            MoveTo(dist(mt), 0, z);
        }
        //gravidade 
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
}

