#include "Configuracoes.h"
#include "GravityGuy.h"
#include "Home.h"
//-------------------------------------------------------------------------------

Configuracoes::Configuracoes(){}

//-------------------------------------------------------------------------------

void Configuracoes::Init() 
{
	this->musica = GravityGuy::musica;
	this->efeito = GravityGuy::efeito;

	barra = new Sprite("Resources/Bar.png");
	nivel = new Sprite("Resources/Level.png");

    GravityGuy::audio->Volume(TESTSOUNDMUSIC, GravityGuy::musica);
	GravityGuy::audio->Play(TESTSOUNDMUSIC,true);
	select = new SeletorConfiguracao(Color{1,1,1,1});
}

//-------------------------------------------------------------------------------

void Configuracoes::Update()
{

    select->Update();
    GravityGuy::audio->Volume(TESTSOUNDMUSIC, musica);
    
    switch (select->Position())
    {
    case TYPE::MUSICA:
        if(window->KeyDown(VK_RIGHT))
        {
            musica += 0.5f * gameTime;
            if (musica > 2) { musica = 2; }
        }

        if (window->KeyDown(VK_LEFT))
        {
            musica -= 0.5f * gameTime;
            if (musica < 0) { musica = 0; }
        }
        break;

    case TYPE::EFEITO:
        if (window->KeyDown(VK_RIGHT))
        {
            efeito += 0.5f * gameTime;
            if (musica > 2) { musica = 2; }
        }

        if (window->KeyDown(VK_LEFT))
        {
            efeito -= 0.5f * gameTime;
            if (musica < 0) { musica = 0; }
        }
        break;

    case TYPE::RETORNAR:
        GravityGuy::musica = this->musica;
        GravityGuy::efeito = this->efeito;
        GravityGuy::audio->Stop(TESTSOUNDMUSIC);
        GravityGuy::NextLevel<Home>();
        break;
    
    default:    
        break;
    }
    
}

//-------------------------------------------------------------------------------

void Configuracoes::Draw()
{
    
    select->Draw();
    barra->Draw(window->CenterX(), 200);
    nivel->Draw(window->CenterX() - 134 + musica * 134, 200);

    barra->Draw(window->CenterX(), 245);
    nivel->Draw(window->CenterX() - 134 + efeito * 134, 245);
    

}

//-------------------------------------------------------------------------------

void Configuracoes::Finalize()
{
    delete select;
    delete barra;
    delete nivel;
}