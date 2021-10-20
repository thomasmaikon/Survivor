#include "Configuracoes.h"
#include "GravityGuy.h"
#include "Home.h"
#include <sstream>
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
            if (efeito > 2) { efeito = 2; }
        }

        if (window->KeyDown(VK_LEFT))
        {
            efeito -= 0.5f * gameTime;
            if (efeito < 0) { efeito = 0; }
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
    std::stringstream ss;

    GravityGuy::titleFont->Draw(window->CenterX()-150, 80, "Sound Control", Color(0.9f, 0.9f, 0.0f, 1.0f), Layer::FRONT, 0.8f);
    GravityGuy::gameFont->Draw(window->CenterX()-15, 300, "Retrun", Color(1.0, 1.0f, 1.0f, 1.0f),Layer::FRONT, 0.8f);

    select->Draw();
    
    ss.str("");
    ss << "Musica: " << musica;

    barra->Draw(window->CenterX(), 200);
    nivel->Draw(window->CenterX() - 134 + musica * 134, 200);
    GravityGuy::sysFont->Draw(window->CenterX()-15, 180, ss.str().c_str() , Color(1.0, 1.0f, 1.0f, 1.0f), Layer::FRONT, 0.8f);

    ss.str("");
    ss << "Efeito: " << efeito;

    barra->Draw(window->CenterX(), 245);
    nivel->Draw(window->CenterX() - 134 + efeito * 134, 245);
    
    GravityGuy::sysFont->Draw(window->CenterX() -15, 230, ss.str().c_str(), Color(1.0, 1.0f, 1.0f, 1.0f), Layer::FRONT, 0.8f);

}

//-------------------------------------------------------------------------------

void Configuracoes::Finalize()
{
    delete select;
    delete barra;
    delete nivel;
}