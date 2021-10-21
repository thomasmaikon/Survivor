
#ifndef _SURVIVOR_VITORIA_H_
#define _SURVIVOR_VITORIA_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Vitoria : public Game
{
private:
    Sprite* tile = nullptr;       // tela de fim

public:
    void Init();                    // inicialização do nível
    void Update();                  // lógica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finalização do nível
};

// ---------------------------------------------------------------------------------

#endif