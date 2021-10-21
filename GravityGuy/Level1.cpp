/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "Moeda.h"
#include <string>
#include <fstream>
#include "Chao.h"
#include "BolaDeFogo.h"
#include <random>
#include "Chegada.h"
#include "Transicao.h"



using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene * Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    score << std::fixed;

    GravityGuy::player->score = 0;
    GravityGuy::player->level = 0;// ele esta comecando
    
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 }, 1);
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    Chao * chao;
    uint  platType;
    float posX, posY;
    Color white { 1,1,1,1 };
    Platform * plat;
 
    chao = new Chao(window->CenterX(), window->Height()-16, white);
    scene->Add(chao, ObjectGroup::STATIC);

    ifstream fin;
    fin.open("Level1.txt");

    fin >> posX;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha com informações da plataforma
            fin >> posY; fin >> platType;
            plat = new Platform(posX, posY, platType, white,1);
            scene->Add(plat, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();

    //plataforma 1
    this->inserirMoedaPlataforma(730,5);// plataforma pequena so suporta 5 moedas
    
    //plataforma 2
    this->inserirMoedaPlataforma(925, 11); // plataforma media suporta 11

    //plataforma 3
    this->inserirMoedaPlataforma(1355, 11);

    //plataforma 4
    this->inserirMoedaPlataforma(1880, 5);

    //plataforma 5
    this->inserirMoedaPlataforma(2120, 5);

    //plataforma 6
    this->inserirMoedaPlataforma(2380, 5);

    //plataforma 7
    this->inserirMoedaPlataforma(2630, 5);

    //plataforma 8
    this->inserirMoedaPlataforma(2855, 11);

    //plataforma 9
    this->inserirMoedaPlataforma(3320, 5);

    //plataforma 10
    this->inserirMoedaPlataforma(3578, 5);

    //plataforma 11
    this->inserirMoedaPlataforma(3795, 11);

    //plataforma 12
    this->inserirMoedaPlataforma(4250, 5);

    //plataforma 13
    this->inserirMoedaPlataforma(4507, 11);

    //plataforma 14
    this->inserirMoedaPlataforma(5020, 5);

    //plataforma 15
    this->inserirMoedaPlataforma(5240, 5);

    //plataforma 16
    this->inserirMoedaPlataforma(5475, 11);

    //plataforma 17
    this->inserirMoedaPlataforma(5929, 5);

    //plataforma 18
    this->inserirMoedaPlataforma(6150, 5);

    //plataforma 19
    this->inserirMoedaPlataforma(6335, 11);

    Chegada* chegada = new Chegada(6910,0, white,1);
    scene->Add(chegada, ObjectGroup::MOVING);

    //this->inserirBolasDeFogo(6335, 40);

    GravityGuy::audio->Play(DUNGEON, true);
    GravityGuy::audio->Volume(DUNGEON, GravityGuy::musica);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        GravityGuy::audio->Stop(DUNGEON);
        GravityGuy::player->Reset();
        GravityGuy::NextLevel<Home>();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height() || GravityGuy::player->State())
    {
        GravityGuy::audio->Stop(DUNGEON);
        GravityGuy::audio->Stop(MOVINGPLAYER);
        GravityGuy::player->Reset();
        GravityGuy::NextLevel<GameOver>();
    }
    else if (GravityGuy::player->Level() == 1 || window->KeyPress('N'))
    {
        GravityGuy::audio->Stop(DUNGEON);
        GravityGuy::audio->Stop(MOVINGPLAYER);
        GravityGuy::player->Reset();
        GravityGuy::NextLevel<Transicao>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }    
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    
    backg->Draw();
    scene->Draw();
    
    score.str("");
    score << "Score: "  << GravityGuy::player->score;
    GravityGuy::gameFont->Draw(30, 30, score.str(), Color{1.0f,1.0f,1.0f,1.0f});

    if (GravityGuy::viewBBox)
        scene->DrawBBox();

}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
void Level1::inserirMoedaPlataforma(int posicaoInicial, int qtd) {
    Moeda* moeda;
    Color white{ 1,1,1,1 };
    int espacamento = 35;
    for (int quantidade = 0; quantidade < qtd; ++quantidade) {
        moeda = new Moeda(posicaoInicial + espacamento * quantidade, 0, white, 1);
        scene->Add(moeda, ObjectGroup::MOVING);
    }
}
// ------------------------------------------------------------------------------
void Level1::inserirBolasDeFogo(int posicaoFinal, int qtd) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(400, posicaoFinal);

    BolaDeFogo* bola;

    for(int i = 0; i < qtd; ++i)
    {
        bola = new BolaDeFogo(dist(mt), 150, Color{ 1,1,1,1 }, 1);
        scene->Add(bola, ObjectGroup::MOVING);
    }
}