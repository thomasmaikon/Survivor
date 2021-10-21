/**********************************************************************************
// Level2 (Código Fonte)
//
// Criação:     27 Set 2021
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 2 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"
#include "Chao.h"
#include "Chegada.h"
#include "Moeda.h"
#include <random>
#include "BolaDeFogo.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    score << std::fixed;

    GravityGuy::player->score = 0;
    GravityGuy::player->level = 1; // ele esta vindo do nivel 1

    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 }, 2);
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    Chao* chao;
    uint  platType;
    float posX, posY;
    Color white{ 1,1,1,1 };
    Platform* plat;

    chao = new Chao(window->CenterX(), window->Height() - 16, white);
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
            plat = new Platform(posX, posY, platType, white, 2);
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
    this->inserirMoedaPlataforma(730, 5,2);// plataforma pequena so suporta 5 moedas

    //plataforma 2
    this->inserirMoedaPlataforma(925, 11,2); // plataforma media suporta 11

    //plataforma 3
    this->inserirMoedaPlataforma(1355, 11,2);

    //plataforma 4
    this->inserirMoedaPlataforma(1880, 5,2);

    //plataforma 5
    this->inserirMoedaPlataforma(2120, 5,2);

    //plataforma 6
    this->inserirMoedaPlataforma(2380, 5,2);

    //plataforma 7
    this->inserirMoedaPlataforma(2630, 5,2);

    //plataforma 8
    this->inserirMoedaPlataforma(2855, 11,2);

    //plataforma 9
    this->inserirMoedaPlataforma(3320, 5,2);

    //plataforma 10
    this->inserirMoedaPlataforma(3578, 5,2);

    //plataforma 11
    this->inserirMoedaPlataforma(3795, 11,2);

    //plataforma 12
    this->inserirMoedaPlataforma(4250, 5,2);

    //plataforma 13
    this->inserirMoedaPlataforma(4507, 11,2);

    //plataforma 14
    this->inserirMoedaPlataforma(5020, 5,2);

    //plataforma 15
    this->inserirMoedaPlataforma(5240, 5,2);

    //plataforma 16
    this->inserirMoedaPlataforma(5475, 11,2);

    //plataforma 17
    this->inserirMoedaPlataforma(5929, 5,2);

    //plataforma 18
    this->inserirMoedaPlataforma(6150, 5,2);

    //plataforma 19
    this->inserirMoedaPlataforma(6335, 11, 2);

    Chegada* chegada = new Chegada(6910, 0, white, 2);
    scene->Add(chegada, ObjectGroup::MOVING);

    this->inserirBolasDeFogo(6335, 40, 2);
    GravityGuy::audio->Play(DUNGEON, true);
    GravityGuy::audio->Volume(DUNGEON, GravityGuy::musica);
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (window->KeyPress(VK_ESCAPE) || GravityGuy::player->Level() == 2 || window->KeyPress('N'))
    {
        GravityGuy::audio->Stop(DUNGEON);
        GravityGuy::player->Reset();
        GravityGuy::NextLevel<Home>();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height() || GravityGuy::player->State())
    {
        GravityGuy::audio->Stop(DUNGEON);
        GravityGuy::player->Reset();
        GravityGuy::NextLevel<GameOver>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    backg->Draw();
    scene->Draw();

    score.str("");
    score << "Score: " << GravityGuy::player->score;
    GravityGuy::gameFont->Draw(30, 30, score.str(), Color{ 1.0f,1.0f,1.0f,1.0f });

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------

void Level2::inserirMoedaPlataforma(int posicaoInicial, int qtd, int level) {
    Moeda* moeda;
    Color white{ 1,1,1,1 };
    int espacamento = 35;
    for (int quantidade = 0; quantidade < qtd; ++quantidade) {
        moeda = new Moeda(posicaoInicial + espacamento * quantidade, 0, white, level);
        scene->Add(moeda, ObjectGroup::MOVING);
    }
}

// ------------------------------------------------------------------------------

void Level2::inserirBolasDeFogo(int posicaoFinal, int qtd, int level) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(400, posicaoFinal);

    BolaDeFogo* bola;

    for (int i = 0; i < qtd; ++i)
    {
        bola = new BolaDeFogo(dist(mt), 150, Color{ 1,1,1,1 }, level);
        scene->Add(bola, ObjectGroup::MOVING);
    }
}