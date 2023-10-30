#include "SimsGame.h"
#include <iostream>
#include <random>
#include <algorithm>
using std::cout;

enum estagioDeVida{CRIANCA,ADOLESCENTE,ADULTO,IDOSO};

SimsGame::SimsGame( int dia, int mes, int ano)
:IDUSUARIO(gerarIdAleatorio()),DATANASCIMENTO(dia, mes, ano)
{
    setEstiloJogo();
    cout << "Inicializando Game.\n";
}

SimsGame::SimsGame( map<string, long int>& infosGame)
:IDUSUARIO(infosGame["id"]),DATANASCIMENTO(infosGame["dia"], infosGame["mes"], infosGame["ano"])
{
    setEstiloJogo();
    cout << "Inicializando Game.\n";
}

//construtor de cópia
SimsGame::SimsGame(const SimsGame & simsGameCopia)
:IDUSUARIO(simsGameCopia.IDUSUARIO),DATANASCIMENTO(simsGameCopia.DATANASCIMENTO)
{
    //Update contact list
    estiloJogo = simsGameCopia.estiloJogo;
	simsList.resize( simsGameCopia.simsList.size( ) );
	for( int i = 0; i < simsList.size( ); i++ )
		simsList[ i ] = new Sims( *simsGameCopia.simsList[ i ] );//deferenciar o ponteiro. simsList é um vector de Sims e alocação de memória

    cout << "Inicializando SimGameCopia.\n";
}

//Destrutor
SimsGame::~SimsGame() {
    //desalocação de memória
    cout << "Jogo finalizado!" << "\n";
    for (auto sim : simsList) {
        delete sim;
    }
}

long int SimsGame::gerarIdAleatorio(){

    std::random_device rd;  // Semente aleatória baseada em hardware
    std::mt19937_64 gen(rd());  // Mersenne Twister 64-bit
    std::uniform_int_distribution<long long> distribution(1000000000000LL, 9999999999999LL);  // Intervalo de 13 dígitos

    return distribution(gen);
}
// lista sims

void SimsGame::printSimsList( ) const
{
	cout << "Lista de Sims Ativos no jogo:\n\n";
	for( int i = 0; i < simsList.size( ); i++ )
		cout << *simsList[ i ] << '\n'; // vai dar a visão geral de cada um
}

void SimsGame::addSim( const Sims &newsim )
{
	simsList.push_back( new Sims( newsim ) );	
}

void SimsGame::deleteLastSim( )
{
	delete simsList[ simsList.size() - 1 ];
	simsList.pop_back( );
}
//operadores
ostream &operator<<(ostream &out, const SimsGame&usuarioPrincipal)
{
    cout << "\n==========================\n";
    cout << "\033[1;32m ❇️ Infos Jogo ❇️ \033[0m";
    cout << "\n==========================\n";
    cout <<"Id: "<< usuarioPrincipal.IDUSUARIO << "\n";
    cout << "Data nascimento: ";
    usuarioPrincipal.DATANASCIMENTO.print();
    cout << "\nEstilo de Jogo: " << usuarioPrincipal.estiloJogo << "\n"; 
    cout << "\n==========================\n";
    cout << "Lista de sims ativos no jogo: \n";

    for_each(usuarioPrincipal.simsList.begin(), usuarioPrincipal.simsList.end(),
            [](const Sims *sim) {cout << "\033[1;32m ❇️ \033[0m" << sim->getNome() << " " << sim->getSobrenome() << "\n";});
    return out;
}

const SimsGame &SimsGame::operator=(const SimsGame &other) { //copia lista de sims
    if (this != &other)
    {
        // Limpar a lista de Sims atual
        for (auto sim : simsList) {
            delete sim;
        }
        simsList.clear();

        // Copiar a lista de Sims do outro objeto
        for (auto sim : other.simsList) {
            simsList.push_back(new Sims(*sim));
        }
    }
    return *this;
}

int SimsGame::operator==(const SimsGame &other) const {
    return IDUSUARIO == other.IDUSUARIO;
}

int SimsGame::operator!=(const SimsGame &other) const {
    return !(*this == other);
}

bool SimsGame::operator!() const {
    return simsList.empty();
}

void SimsGame::setEstiloJogo(){
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int anoAtual = timeinfo->tm_year + 1900; // Ano atual
    int mesAtual = timeinfo->tm_mon + 1;     // Mês atual
    int diaAtual = timeinfo->tm_mday;        // Dia atual

    int idade = anoAtual - DATANASCIMENTO.getAno();

    
    // Verifica se já fez aniversário neste ano
    if (mesAtual < DATANASCIMENTO.getMes() || (mesAtual == DATANASCIMENTO.getMes() && diaAtual < DATANASCIMENTO.getDia()))
        idade--;

    // cout<<"idade: "<<idade<<"\n";
    // Lógica para determinar o estágio de vida com base na idade
    if (idade < 12)
    {   
        estiloJogo = CRIANCA;
        return;
    }
        
    if (idade < 18)
    {
        estiloJogo = ADOLESCENTE;
        return;
    }
    if (idade < 65)
    {
        estiloJogo = ADULTO;
        return;
    }
    estiloJogo = IDOSO;
    return;
}