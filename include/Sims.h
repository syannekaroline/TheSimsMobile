#ifndef SIMS_H
#define SIMS_H
// A classe é protegida contra inclusões múltiplas em outros arquivos usando a diretiva de pré-processamento

#include <string>
using std::string;

class Sims 
{
    public:
        // construtores e destrutores sempre começam a parte pública da classe
        Sims(); // Construtor-> método chamado pra inicializar os atributos a classe
        Sims(string,string,char,int,double = 30,double = 300,string=""); // declarando o construtor com parâmetros. Energia com valor default igual a 30, simCash = 300 e endereço = ""
        Sims( const Sims & ); //construtor de cópia
        ~Sims();//Destrutor -> relacionado a desalocaçao de memória 

        // declarando get e set -> acesso seguro na alteração dos atributos
        void setNome(string);
        void setSobrenome(string);
        void setGenero(char);
        void setTonalidadeDaPele(int);
        void setEnergia(double);
        void setSimCash(double);
        void setEndereco(string);        

        string getNome() const;
        string getSobrenome() const;
        char getGenero() const;
        int getTonalidadeDaPele() const;
        double getEnergia() const;
        double getSimCash() const;
        string getEndereco() const;

        void simVisaoGeral() const; //método mostra os atributos de um sim
        void descansar();  //método que carrega a energia do sim
        string getColor(int) const;
        void limparSimsHouse(); 

    private:
        // atributos sempre na parte privada
        string nome;
        string sobrenome;
        char genero; //F ou M
        int tonalidadeDaPele; // entre 1 a 9
        double energia; // entre 0 a 30
        double simCash;
        string endereco;

        const int MAXTAMNOMES = 12; // Tamanho max pra nomes, sobrenomes
        const int MAXTAMENDERECO = 25;
        const double ENERGIAMAX = 30;

        //atributo static const
        static const int ENERGIAMIN = 5; // energia min pra bem estar do Sim
};

#endif // SIMS_H