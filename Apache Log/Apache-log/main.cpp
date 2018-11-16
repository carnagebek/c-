#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Registro{

  string origem;
  string data;
  string hora;
  string metodo;
  string url;
  string versaoHTTP;
  int codigoHTTP;
  int tamanho;

public:

    Registro(string log){

    stringstream ss;

    ss << log;
    getline(ss, origem, ' ');
    getline(ss, data, '[');
    getline(ss, data, ':');
    getline(ss, hora, ' ');
    getline(ss, metodo, '"');
    getline(ss, metodo, '/');
    getline(ss, url, ' ');
    getline(ss, versaoHTTP, '"');
    ss >> codigoHTTP;
    ss >> tamanho;
    };


    string getOrigem(){
    return this->origem;
    }
    int getCodigoHTTP(){
    return this->codigoHTTP;
    }
    string getData(){
    return this->data;
    }
    string getHora(){
    return this->hora;
    }
    string getMetodo(){
    return this->metodo;
    }
    string getUrl(){
    return this->url;
    }
    string getVersaoHTTP(){
    return this->versaoHTTP;
    }
    int getTamanho(){
    return this->tamanho;
    }

};

class Controle{

    vector<Registro*>logs;
    string linha;

public:
    void carregar(){

    fstream fs;
    fs.open("apache-access-log.txt", fstream::in);
    if(fs.is_open()){
        while(!fs.eof()){
            getline(fs, linha);
            logs.push_back(new Registro(linha));
        }
    }
    fs.close();
    }

    void listar_origem(){

    string origem;
    cout << "Informe uma origem: ";
    cin >> origem;

    for(vector<Registro*>::iterator it = logs.begin(); it != logs.end(); it++)
            if((*it)->getOrigem()== origem){
                cout << "Data: " << (*it)->getData() << endl;
                cout << "URL: " << (*it)->getUrl() << endl;
                cout << "Codigo HTTP: " << (*it)->getCodigoHTTP() << endl;
    }
}
    void listar_code(){

    int code;
    cout << "Informe um status code: ";
    cin >> code;

    for(vector<Registro*>::iterator it = logs.begin(); it != logs.end(); it++)
            if((*it)->getCodigoHTTP()== code){
                cout << "Origem: " << (*it)->getOrigem() << endl;
                cout << "URL: " << (*it)->getUrl() << endl;
                cout << "Tamanho do pacote: " << (*it)->getTamanho() << endl;
    }
}
    void dados_do_dia(){

    string data;
    int ttotal = 0;
    cout << "Informe uma data(dd/mm/yyyy): ";
    cin >> data;

    for(vector<Registro*>::iterator it = logs.begin(); it != logs.end(); it++)
            if((*it)->getData()== data){
                cout << "Metodo HTTP: " << (*it)->getCodigoHTTP() << endl;
                ttotal += (*it)->getTamanho();
    }
        cout << "Total de pacotes transferidos no dia: " << ttotal << endl;
    }

};

int main()
{
    int option;

    Controle *aux = new Controle();
    aux->carregar();
    //aux->listar_origem();
    //aux->listar_code();
    //aux->dados_do_dia();

    while(1){

    cout << "1.Listar registros no log de uma determinada origem." << endl;
    cout << "2.Listar registros por status code." << endl;
    cout << "3.Apresentar total de dados transferidos no dia." << endl;
    cout << endl;
    cout << "Informe uma opcao: ";
    cin >> option;
    cout << endl;

        switch(option)
        {
        case 1:
           aux->listar_origem();
           cout << endl;
           system("pause");
           system("cls");
        break;
        case 2:
           aux->listar_code();
           cout << endl;
           system("pause");
           system("cls");
        break;
        case 3:
           aux->dados_do_dia();
           cout << endl;
           system("pause");
           system("cls");
        break;
        }
    };



}
