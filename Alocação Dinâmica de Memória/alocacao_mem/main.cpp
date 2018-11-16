#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Calculadora
{

public:

    int *ptr;
    int idx = 0;
    int tamanho = 0;

    Calculadora();
    Calculadora(int valor)
    {
        ptr = (int *)calloc(valor, sizeof(int));
        tamanho = valor;
    }
    void adicionarNumero(int valor)
    {
        if(idx < tamanho){
        *(ptr + idx) = valor;
        idx++;
        }
    }
    void aumentarCapacidade(int valor)
    {
        ptr = (int *)realloc(ptr,valor*sizeof(int));
    }
    void limparNumeros();
    int produtorio();
    int somatorio()
    {
        int val=0;
        int idx=0;
        if(tamanho > idx){
        val += *(ptr+idx);
        idx++;
        }
        return val;
    }
};

int main(int argc, const char * argv[])
{
    //int *ptr;

    //ptr = argv;

    Calculadora calc(5);
    calc.adicionarNumero(1);
    calc.adicionarNumero(2);
    calc.adicionarNumero(3);
    calc.adicionarNumero(4);
    calc.adicionarNumero(5);
    cout << calc.somatorio() << endl;
    //cout << calc.produtorio() << endl;
    //calc.aumentarCapacidade(2);
    //calc.adicionarNumero(6);
    //calc.adicionarNumero(7);
    //cout << calc.somatorio() << endl;
    //cout << calc.produtorio() << endl;
    //calc.limparNumeros();
    //cout << calc.somatorio() << endl;
    //cout << calc.produtorio() << endl;
    return 0;
}
