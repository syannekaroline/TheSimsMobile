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
        Sims(string,string,char,int,double = 30); // declarando o construtor com parâmetros. Energia com valor default igual a 30
        ~Sims();//Destrutor -> relacionado a desalocaçao de memória 

        // declarando get e set -> acesso seguro na alteração dos atributos
        void setNome(string);
        void setSobrenome(string);
        void setGenero(char);
        void setTonalidadeDaPele(int);
        void setEnergia(double);

        string getNome() const;
        string getSobrenome() const;
        char getGenero() const;
        int getTonalidadeDaPele() const;
        double getEnergia() const;

        void simVisaoGeral() const; //método mostra os atributos de um sim
        void descansar();  //método que carrega a energia do sim
        string getColor(int) const;

    private:
        // atributos sempre na parte privada
        string nome;
        string sobrenome;
        char genero; //F ou M
        int tonalidadeDaPele; // entre 1 a 9
        double energia; // entre 0 a 30
};

#endif // SIMS_H