#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;
using std::cout;
using std::cin;
using std::make_tuple;
using std::cerr;

#include <map>
using std::map;
#include "SimsGame.h"
#include <unistd.h>

bool createInfos(string nameFile )
{
    ifstream inputFile(nameFile);
    //verifica se o arquivo de texto está vazio
    if (inputFile.peek() != ifstream::traits_type::eof())
        return true;
    
    //recebe dados do usuário
    int dia;
    int mes;
    int ano;

    cout << "Para jogar, insira sua data de nascimento (dia mês ano): ";
    if (!(cin >> dia >> mes >> ano)) {
        cerr << "entrada inválida!" << '\n';
        return false; // Exit with an error code
    }    

    //abre o arquivo pra escrita de dados
    ofstream outputFile(nameFile, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return false; // Exit with an error code
    }
    //registra os dados 
    outputFile << "id = " << SimsGame::gerarIdAleatorio() << '\n';
    outputFile << "dia = " << dia << '\n';
    outputFile << "mes = " << mes << '\n';
    outputFile << "ano = " << ano << '\n';  

    outputFile.close();
    cout << "Dados salvos com sucesso!" << '\n';
    return true;
}

bool loadConfig(map<string, long int>& variables,string nameFile )
{
    //verifica se o arquivo tá vazio e escreve -> qualquer erro retorna false,se escreveu corretamente retorna true
    if (!createInfos(nameFile))
        return false;

    ifstream inputFile(nameFile);
    if ( !inputFile.is_open() )  //tenta abrir o arquivo
    {
        cerr << "Error opening file." << '\n';
        return false; // Exit with an error code
    }
    string line;    
    string variableName;
    char equalsSign;
    double value;
    //carrega linha a linha do txt e arqmazena no map
    while (getline(inputFile, line)) 
    {
        istringstream iss(line);
        if (iss >> variableName >> equalsSign >> value && equalsSign == '=') 
            variables[variableName] = value;
        else
            cerr << "Error parsing line: " << line << '\n';
    }

    inputFile.close();
    return true;
}

void prosseguir() {
    char resposta;
    cout << "\n\n Digite s pra limpar o terminal: ";
    cin >> resposta;

    if (resposta == 's' || resposta == 'S') {
    // Verificar se o sistema operacional é Windows ou Unix-like
    #ifdef _WIN32
        system("cls"); // Comando para limpar o terminal no Windows
    #else
        system("clear"); // Comando para limpar o terminal em sistemas Unix-like (Linux, macOS)
    #endif
    } else {
        cout << "Operação cancelada pelo usuário.\n";
    } 
}