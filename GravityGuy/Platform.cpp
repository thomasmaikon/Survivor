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

#include "Platform.h"
#include "Level1.h"
#include "Level2.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType, Color tint, uint level) : color(tint)
{
    this->level = level;
    switch (platType)
    {
    case MEDIUM:  platform = new Sprite("Resources/platformMedium.png"); type = MEDIUM; break;
    case SMALL: platform = new Sprite("Resources/platformSmall.png"); type = SMALL; break;
    //case LARGE:  platform = new Sprite("Resources/LongGray.png"); type = LARGE; break;
    //case FINISH: platform = new Sprite("Resources/Finish.png"); type = FINISH; break;
    }
    
    height = platform->Height();
    width = platform->Width();
    BBox(new Rect(-platform->Width()/2.0f, 
                  -platform->Height()/2.0f, 
                   platform->Width()/2.0f, 
                   platform->Height()/2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
    type = PLATFORM;
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    
    // move plataforma apenas no eixo x
    Translate(-300.0f * gameTime, 0);
   /*
    if (x + platform->Width() <= 0)
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
    */
}

// -------------------------------------------------------------------------------
