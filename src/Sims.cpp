#include <iostream>
#include <string>
#include <unistd.h>
#include <cmath>
#include <assert.h>

using std::cout;

#include "Sims.h"

// CONSTRUTORES
// Construtor padrão -> inicializar objetos com valores padrão pré-definidos.
Sims::Sims()
: nome("Fulana"), sobrenome("da Silva"), genero('F'),tonalidadeDaPele(7),energia(20),simCash(300),endereco(""),experiencia(0),conquistasPtr(0),conquistasSize(0),contatosPtr(0),contatosSize(0),aparencia()
{
}

// Construtor com com parâmetros -> permite a personalização dos atributos
Sims::Sims(string nome, string sobrenome, char genero, int tonalidadeDaPele,double energia,double simCash,string endereco)
:aparencia()
{
    conquistasSize = 0;
    proxConquista=0;
    conquistasPtr=0;

    contatosSize = 0;
    proxContato=0;
    contatosPtr=0;
    experiencia = 0;

    setNome(nome);
    setSobrenome(sobrenome);
    setGenero(genero);
    setTonalidadeDaPele(tonalidadeDaPele);
    setEnergia(energia);
    setSimCash(simCash);
    setEndereco(endereco);
}

Sims::Sims(const Sims & simCopia)
:aparencia(simCopia.aparencia)
{
    this->nome = simCopia.nome;
    this->sobrenome = simCopia.sobrenome;
    this->genero = simCopia.genero;
    this->tonalidadeDaPele = simCopia.tonalidadeDaPele;
    this->energia = simCopia.energia;
    this->simCash = simCopia.simCash;
    this->endereco = simCopia.endereco;
    this->experiencia = simCopia.experiencia;

    //alocação dinâmica pra lista de coquistas do personagem
    this->conquistasSize = simCopia.conquistasSize;
    this->proxConquista = simCopia.proxConquista;
    this->conquistasPtr = new string[ this->conquistasSize ];

    //alocação dinâmica pra lista de coquistas do personagem
    this->contatosSize = simCopia.contatosSize;
    this->proxContato = simCopia.proxContato;
    this->contatosPtr = new Sims[ this->contatosSize ];

    for( int i = 0; i < proxConquista; i++ )
        this->conquistasPtr[ i ] = simCopia.conquistasPtr[ i ];

    for( int i = 0; i < proxContato; i++ )
        this->contatosPtr[ i ] = simCopia.contatosPtr[ i ];

}
//Destrutor
Sims::~Sims( )
{  
    delete [] conquistasPtr;
    delete [] contatosPtr;
}

// Métodos Get -> obter o valor de um atributo privado de uma classe sem modificação direta > controle + preciso sobre quem pode acessá-lo.
string Sims::getNome() const 
{
  return nome; 
}

string Sims::getSobrenome() const 
{
    return sobrenome; 
}

char Sims::getGenero() const 
{
    return genero;
}

int Sims::getTonalidadeDaPele() const 
{
    return tonalidadeDaPele; 
}

double Sims::getEnergia() const 
{
    return energia;
}

double Sims::getSimCash() const 
{
    return simCash;
}

string Sims::getEndereco() const 
{
    return endereco;
}

// Métodos Set -> pra modificar o valor de um atributo da classe.

void Sims::setNome(string nome)
{
    if ( nome.length( ) > MAXTAMNOMES ) // limitar o tamanho da string 
    {
        this->nome = nome.substr( 0, MAXTAMNOMES );
        cout << "\033[1;31m Nome alterado. Excedeu o valor máximo de "<<MAXTAMNOMES<<" caracteres.\033[0m\n";
        return;
    }
    this->nome = nome;
}

void Sims::setSobrenome(string sobrenome) 
{
    if ( sobrenome.length( ) > MAXTAMNOMES ) // limitar o tamanho da string 
    {
        cout << "\033[1;31m Sobrenome alterado. Excedeu o valor máximo de "<<MAXTAMNOMES<<" caracteres.\033[0m\n";
        return;
    }
    this->sobrenome = sobrenome;
}

void Sims::setGenero(char genero) 
{  
    this->genero = genero; 
}

void Sims::setTonalidadeDaPele(int tonalidadeDaPele) 
{
    // Verifica se a nova tonalidadeDaPele está dentro do intervalo válido
    if (tonalidadeDaPele >= 1 && tonalidadeDaPele <= 9)
    {
        this->tonalidadeDaPele = tonalidadeDaPele;
        return;
    }
    this->tonalidadeDaPele = 7;
}

void Sims::setEnergia(double energia)
{
    // Verifica se a nova energia está dentro do intervalo válido
    if (energia >= 0 && energia <= 30)
    {
        this->energia = energia;
        return;
    }
    this->energia = 30;
}

void Sims::setSimCash(double simCash) 
{  
    this->simCash = simCash; 
}

void Sims::setEndereco(string endereco) 
{ 
    if ( endereco.length( ) > MAXTAMENDERECO ){
        this->endereco = endereco.substr( 0, MAXTAMENDERECO );
        cout << "\033[1;31m Nome de endereço alterado. Excedeu o valor máximo de " <<MAXTAMENDERECO <<" caracteres. \033[0m \n";
        return;
    }
    this->endereco = endereco; 
}

// Demais métodos
void Sims::verAparencia() const
{
    cout << "==========================\n";
    cout << "\033[1;32m Aparência " << nome << " " << sobrenome << "\033[0m\n";
    cout << aparencia;
}

void Sims::descansar() 
{
    // Método que recarrega energia do sim e mostra a animação de uma barra de progresso conforme a energia vai aumentando. 
    cout << "Iniciando descanso...\n";
    string barra = "|";  // Caractere da barra de progresso

    // Loop para simular o carregamento de energia
    do
    {
        setEnergia(energia+=5);
        // Imprime a barra de progresso
        for (int x = 0; x <= energia; x+=1)
        {
            cout << barra;
        }

        sleep (1);  // Pausa de 1 segundo
        // Define a cor da barra de progresso com base na energia
        if (energia <= 10)
        {
            cout << "\033[1;31m";  // Vermelho em negrito
        } else if (energia <= 20)
        {
            cout << "\033[1;33m";  // Amarelo em negrito
        } else
        {
            cout << "\033[1;32m";  // Verde em negrito
        }

        cout << "\r" << std::flush;  // carriage return e limpeza do buffer
    } while (energia < ENERGIAMAX);

    // Restaura a cor padrão do texto e informa que o descanso foi finalizado
    cout << "\033[0m";
    cout << "\nDescanso concluído!🔋\n";
}

string Sims::getColor(int color )
{   
    // Recebe um valor inteiro color e retorna a string correspondente ao emoji da cor.
    
    if ( color <= 1 || color<=9)
    {  
        switch (color) 
        {
            case 1:
                return "🟥";
            case 2:
                return "🟧";
            case 3:
                return "🟨";
            case 4:
                return "🟩";
            case 5:
                return "🟦";
            case 6:
                return "🟪";
            case 7:
                return "🟫";
            case 8:
                return "⬛";
            case 9:
                return "⬜";
        }
    }
    return "⬛";
}

void Sims::limparSimsHouse()
{   
    if ( endereco == "")
    {
        cout<< "\n\033[1;31mUma SimsHouse deve ser vendida pra você antes de realizar essa ação!\033[0m\n";
        return;
    }

    int gastoTotalEnergia =10; // quanto de energia custa limpar a casa

    if (energia<=gastoTotalEnergia){
        cout<< "\033[1;33m Sua Energia está abaixo dos limites pra realizar essa ação. Por favor, descanse primeiro !\033[0m \n";
        return;
    }

    cout << "\n================ "<< nome<<" vai limpar sua SimHouse ==========" << "\n";

    while ( energia > ENERGIAMIN && gastoTotalEnergia>0)
    {
        energia -= 5;
        gastoTotalEnergia -=5;
        //Ação de limpar (simulação)
        cout << "Limpando... ";
        sleep(2);
        cout << "Energia restante: " << energia << "\n";
        
    }

    cout << "\033[1;32mA limpeza foi concluída com sucesso!\033[0m\n";
    cout<< "\033[1;32m 🎉🎊 + 2 px 🎉🎊\033[0m\n";
    experiencia+=2; // aumenta a experiência em 2 xp
    
    // mensagem de alerta sobre a energia
    if (energia <= ENERGIAMIN )
        cout << "\033[1;33mSua energia está muito baixa. Descanse para recuperá-la!\033[0m\n";

    return;
}

void::Sims::alocarConquistas(const string &conquista)
{  
    //Aloca mais memória pra armazenar dinâmicamente a lista de conquistas do personagem
    conquistasSize += int( ceil( conquistasSize * 0.5 ) );//Aumenta a memória em 50%
    string *conquistaTemp = new string[ conquistasSize ];
    for( int i = 0; i < proxConquista; i++ )
        conquistaTemp[ i ] = conquistasPtr[ i ];

    delete [] conquistasPtr;   
   
    conquistasPtr = conquistaTemp;

    conquistasPtr[ proxConquista++ ] = conquista;;
    
}

void Sims::registrarConquista( const string &conquista)
{
    
    cout<<"🥳 \033[1;32mParabéns!! Uma nova conquista foi realizada!!\033[0m 🥳 \n";
    cout<< "\033[1;32m 🎉🎊 "<<conquista << " 🎉🎊\033[0m\n";
    experiencia+=5;
    cout<< "\033[1;32m 🎉🎊 + 5 px 🎉🎊\033[0m\n";
    if(proxConquista < conquistasSize)
    {
        conquistasPtr[proxConquista++] = conquista;
        return;
    }

    if( conquistasSize==0)
    {
        conquistasSize = 1;
        conquistasPtr = new string[conquistasSize];
        conquistasPtr[proxConquista++] = conquista;
        return;
    }

    alocarConquistas(conquista); // caso não tenha espaço pra alocar -> chama o método alocarConquistas(conquista) para aumentar a memória e adicionar a conquista no novo Sims.
}

void Sims::verConquistas( ) const
 {
    //percorre dinâmicamente a lista de conquisa do personagem e mostra de forma estilizada ao jogador

    cout<<R"(
    ____    ____                        _     _            
   / /\ \  / ___|___  _ __   __ _ _   _(_)___| |_ __ _ ___ 
  / /  \ \| |   / _ \| '_ \ / _` | | | | / __| __/ _` / __|
 / /    \ \ |__| (_) | | | | (_| | |_| | \__ \ || (_| \__ \
/_/__  _ \_\____\___/|_| |_|\__, |\__,_|_|___/\__\__,_|___/
/ ___|(_)_ __ ___  ___         |_|                         
\___ \| | '_ ` _ \/ __|                                    
 ___) | | | | | | \__ \                                    
|____/|_|_|_|_| |_|___/                                    
\ \      / /                                               
 \ \    / /                                                
  \ \  / /                                                 
   \_\/_/                                                  )"<<"\n";

    cout<<"Conquistas "<<nome <<" "<<sobrenome<<"\n";
    cout << "==========================\n";
    for( int i = 0; i < proxConquista; i++ )
        cout << "❇️ "<< conquistasPtr[ i ] << '\n';
    cout << "==========================\n";

    
 }

void Sims::alocarContatos(const Sims &contato) {
    // Aloca mais memória para armazenar dinamicamente a lista de contatos do personagem
    contatosSize += int(ceil(contatosSize * 0.5)); // Aumenta a memória em 50%
    Sims *contatosTemp = new Sims[contatosSize];
    
    for (int i = 0; i < proxContato; i++) {
        contatosTemp[i] = contatosPtr[i];
    }
    
    delete[] contatosPtr;
    contatosPtr = contatosTemp;
    contatosPtr[proxContato++] = contato;
}

bool Sims::verificarContatoExistente(const Sims& contato) const
{
    //verifica se um personagem já faz parte da lista de contatos
    for (int i = 0; i < proxContato; ++i)
    {
        if (contatosPtr[i] == contato)
            return true;  // O contato já foi registrado
    }
    return false;  // novo contato
}

void Sims::fazerApresentacaoAgradavel(const Sims &sim) {
    // Adiciona um personagem na lista dinâmica de contatos
    if (verificarContatoExistente(sim)) {
        cout << nome << " " << sobrenome << " e " << sim.getNome() << " " << sim.getSobrenome() << " já se conhecem\n";
        return;
    }
    cout << "\nApresentação agradável entre " << nome << " " << sobrenome << " e " << sim.getNome() << " " << sim.getSobrenome() << "\n";
    int ganhoXp = 5;
    // Loop para simular a apresentação dos sims
    for (int i = 0; i < ganhoXp; i++) {
        experiencia += 1;
        cout << "💬" << std::flush;
        sleep(1); // Pausa de 1 segundo
    }
    cout << "\nApresentação agradável concluída 👥 \n";

    if (proxContato < contatosSize) {
        contatosPtr[proxContato++] = sim;
        return;
    }

    if (contatosSize == 0) {
        contatosSize = 1;
        contatosPtr = new Sims[contatosSize];
        contatosPtr[proxContato++] = sim;
        return;
    }

    alocarContatos(sim); // Caso não tenha espaço para alocar, chama o método alocarContatos para aumentar a memória e adicionar o contato no novo Sims.
}

void Sims::verContatos() const {
    // Mostra a lista de contatos do personagem
    cout << "Contatos de " << nome << " " << sobrenome << "\n";
    cout << "==========================\n";
    for (int i = 0; i < proxContato; i++) {
        cout << "❇️ " << contatosPtr[i].getNome() << " " << contatosPtr[i].getSobrenome() << '\n';
    }
    cout << "==========================\n";
}


//Operadores
ostream &operator<<(ostream &out, const Sims &sim)
{
    string generoSimbolo =  (sim.genero == 'F') ? "♀" : "♂";

        cout<<R"(
    ______     ___      /\/|                              _ 
   / /\ \ \   / (_)___ |/\/_  ___     __ _  ___ _ __ __ _| |
  / /  \ \ \ / /| / __|/ _` |/ _ \   / _` |/ _ \ '__/ _` | |
 / / _  \ \ V / | \__ \ (_| | (_) | | (_| |  __/ | | (_| | |
/_/_(_)_ \_\_/_ |_|___/\__,_|\___/   \__, |\___|_|  \__,_|_|
/ __| | '_ ` _ ||                     |___/                  
\__ \ | | | | |||                                           
|___/_|_| |_| |||                                           
\ \      / /                                                
 \ \    / /                                                 
  \ \  / /                                                  
   \_\/_/                                                   )"<<"\n";

    cout << "\n==========================\n";
    cout << "\033[1;32m ❇️ Nome: \033[0m" << sim.nome << " " << sim.sobrenome << "\n";
    cout << "\033[1;32m ❇️ Gênero: \033[0m" << generoSimbolo << "\n";
    cout << "\033[1;32m ❇️ Tonalidade da Pele \033[0m: " << sim.getColor(sim.tonalidadeDaPele) << "\n";
    cout << "\033[1;32m ❇️ Energia: \033[0m" << sim.energia << "\n";
    cout << "\033[1;32m ❇️ SimCash: \033[0m" << sim.simCash <<"\n";
    cout << "\033[1;32m ❇️ Endereço: \033[0m" << sim.endereco <<"\n";
    cout << "\033[1;32m ❇️ Experiência: \033[0m" << sim.experiencia <<" xp \n";
    cout << "==========================\n";

    return out;
}

// Operador de atribuição
const Sims &Sims::operator=(const Sims &other)
{
    if (this != &other) {  // Verifica se não estamos atribuindo a si mesmo
        nome = other.nome;
        sobrenome = other.sobrenome;
        genero = other.genero;
        tonalidadeDaPele = other.tonalidadeDaPele;
        energia = other.energia;
        simCash = other.simCash;
        endereco = other.endereco;
        experiencia = other.experiencia;
        aparencia = other.aparencia;

        // Copiar as conquistas
        if (conquistasSize != other.conquistasSize) {
            delete[] conquistasPtr;
            conquistasSize = other.conquistasSize;
            conquistasPtr = new string[conquistasSize];
        }
        for (int i = 0; i < conquistasSize; i++) {
            conquistasPtr[i] = other.conquistasPtr[i];
        }
        proxConquista = other.proxConquista;

        // Copiar os contatos
        if (contatosSize != other.contatosSize) {
            delete[] contatosPtr;
            contatosSize = other.contatosSize;
            contatosPtr = new Sims[contatosSize];
        }
        for (int i = 0; i < contatosSize; i++) {
            contatosPtr[i] = other.contatosPtr[i];
        }
        proxContato = other.proxContato;
    }
    return *this;
}

// Operador de comparação igual (compare equal)
bool Sims::operator==(const Sims &other) const 
{
    // Comparar os atributos simples
    if (nome != other.nome || sobrenome != other.sobrenome ||
        genero != other.genero || tonalidadeDaPele != other.tonalidadeDaPele ||
        energia != other.energia || simCash != other.simCash ||
        endereco != other.endereco || experiencia != other.experiencia || aparencia != other.aparencia) {
        return false;  // Não são iguais
    }

    // Comparar as alocações de memória para conquistas
    if (conquistasSize != other.conquistasSize) {
        return false;  // Não são iguais
    }
    for (int i = 0; i < conquistasSize; i++) {
        if (conquistasPtr[i] != other.conquistasPtr[i]) {
            return false;  // Não são iguais
        }
    }

    // Comparar as alocações de memória para contatos
    if (contatosSize != other.contatosSize) {
        return false;  // Não são iguais
    }
    for (int i = 0; i < contatosSize; i++) {
        if (contatosPtr[i] != other.contatosPtr[i]) {
            return false;  // Não são iguais
        }
    }

    // Se todos os atributos e alocações de memória coincidirem, são iguais
    return true;
}

// Operador de comparação não igual (compare !equal)
int Sims::operator!=(const Sims &other) const
{
    return !(*this == other);
}

//operador not verifica se o sim não está ativo no jogo
bool Sims::operator!() const
{
    return (experiencia == 0)? true : false;
}

void Sims::addXp(int xp){
    this->experiencia+=xp;
    return;
}

void Sims::addSimCash(double simCash){
    this->simCash+=simCash;
    return;
}

void Sims::diminuirEnergia(int energia){
    this->energia-=energia;
    return;
}