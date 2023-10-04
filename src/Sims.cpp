#include <iostream>
#include <string>
#include <unistd.h>

using std::cout;

#include "Sims.h"

// CONSTRUTORES
// Construtor padrão -> inicializar objetos com valores padrão pré-definidos.
Sims::Sims()
: nome("Fulana"), sobrenome("da Silva"), genero('F'),tonalidadeDaPele(7),energia(20),simCash(300),endereco("")
{
    cout << "Inicializando Sim.\n";
}

// Construtor com com parâmetros -> permite a personalização dos atributos
Sims::Sims(string nome, string sobrenome, char genero, int tonalidadeDaPele,double energia,double simCash,string endereco)
{
    cout << "Inicializando Sim.\n";
    setNome(nome);
    setSobrenome(sobrenome);
    setGenero(genero);
    setTonalidadeDaPele(tonalidadeDaPele);
    setEnergia(energia);
    setSimCash(simCash);
    setEndereco(endereco);
}

Sims::Sims(const Sims & simCopia)
{
  cout << "Inicializando Sim.\n";
  
  this->nome = simCopia.nome;
  this->sobrenome = simCopia.sobrenome;
  this->genero = simCopia.genero;
  this->tonalidadeDaPele = simCopia.tonalidadeDaPele;
  this->energia = simCopia.energia;
  this->simCash = simCopia.simCash;
  this->endereco = simCopia.endereco;
}
//Destrutor -> ainda será implementado
Sims::~Sims( )
{  

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
void Sims::simVisaoGeral() const 
{
    string generoSimbolo =  (genero == 'F') ? "♀" : "♂";

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
    cout << "\033[1;32m ❇️ Nome: \033[0m" << nome << " " << sobrenome << "\n";
    cout << "\033[1;32m ❇️ Gênero: \033[0m" << generoSimbolo << "\n";
    cout << "\033[1;32m ❇️ Tonalidade da Pele \033[0m: " << getColor(tonalidadeDaPele) << "\n";
    cout << "\033[1;32m ❇️ Energia: \033[0m" << energia << "\n";
    cout << "\033[1;32m ❇️ SimCash: \033[0m" << simCash <<"\n";
    cout << "\033[1;32m ❇️ Endereço: \033[0m" << endereco <<"\n";
    cout << "==========================\n";
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

string Sims::getColor(int color ) const 
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
    
    // mensagem de alerta sobre a energia
    if (energia <= ENERGIAMIN )
        cout << "\033[1;33mSua energia está muito baixa. Descanse para recuperá-la!\033[0m\n";

    return;
}