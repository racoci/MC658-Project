#include <csignal>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Flags para controlar a interrupcao por tempo
volatile int pare = 0;       // Indica se foi recebido o sinal de interrupcao
volatile int escrevendo = 0; // Indica se estah atualizando a melhor solucao

// Variaveis para guardar a melhor solucao encontrada
vector<int> melhor_solucao;
int melhor_custo;

void imprime_saida() {
    // Lembre-se: a primeira linha da saida deve conter n inteiros,
    // tais que o j-esimo inteiro indica o dia de gravacao da cena j!
    for (int j = 0; j < melhor_solucao.size(); j++)
        cout << melhor_solucao[j] << " ";
    // A segunda linha contem o custo (apenas de dias de espera!)
    cout << endl << melhor_custo << endl;
}

void atualiza_solucao(const vector<int> &solucao, int custo) {
    escrevendo = 1;
    melhor_solucao = solucao;
    melhor_custo = custo;
    escrevendo = 0;
    if (pare == 1) {
        // Se estava escrevendo a solucao quando recebeu o sinal,
        // espera terminar a escrita e apenas agora imprime a saida e
        // termina
        imprime_saida();
        exit(0);
    }
}

void interrompe(int signum) {
    pare = 1;
    if (escrevendo == 0) {
        // Se nao estava escrevendo a solucao, pode imprimir e terminar
        imprime_saida();
        exit(0);
    }
}

int main() {
    // Registra a funcao que trata o sinal
    signal(SIGINT, interrompe);

    // Continue sua implementacao aqui. Sempre que encontrar uma nova
    // solucao, utilize a funcao atualiza_solucao para atualizar as
    // variaveis globais.

    return 0;
}
