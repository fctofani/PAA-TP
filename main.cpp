#include <iostream>

using namespace std;

int** leGrafo(int&);
void imprimeMatriz(int**, int);
short deletaMatriz(int**, int);
int solucaoInicial(int**, int);

int main()
{
    int tam;
    int** mat = leGrafo(tam);
    int* solucao = new int[tam];
    int otima = solucaoInicial(mat, tam);
    cout << otima << endl;
    imprimeMatriz(mat, tam);
    deletaMatriz(mat, tam);
    return 0;
}

int** leGrafo(int& tamanho){
    FILE* arquivo;
    if((arquivo = fopen("grafo.txt","r")) == nullptr) exit(1);
    fscanf(arquivo, "%d", &tamanho);
    int** matriz = new int*[tamanho];
    for(int i = 0; i < tamanho; i++) matriz[i] = new int [tamanho];

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++) fscanf(arquivo, "%d", &matriz[i][j]);
    }
    fclose(arquivo);
    return matriz;
}

int solucaoInicial(int** grafo, int tam){
    int* solucao = new int[tam];
    for(int i = 0; i < tam; i++) solucao[i] = 0;

    solucao[0] = 1; // coloca o primeiro vértice na solução
    bool flag = true; // checa se o vértice atual é adjacente ao que está sendo comparado
    int cont = 1; // qtd de vértices na solução

    for(int i = 1; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(grafo[i][j] == 1 && solucao[j] == 1){
                j = tam;
                flag = false;
            }
        }
        if(flag){
            solucao[i] = 1;
            cont++;
        }
        flag = true;
    }
    for(int i = 0; i < tam; i++) cout << " | " << solucao[i];
    cout << endl;

    return cont;
}

void imprimeMatriz(int** matriz, int tamanho){
    cout << "  | ";
    for(int i = 0; i < tamanho; i++) cout << i+1 << "|";
    cout << endl;
    for(int i = 0; i < tamanho; i++){
        cout << i+1 << " | ";
        for(int j = 0; j < tamanho; j++) cout << matriz[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

short deletaMatriz(int** matriz, int tamanho){
    for(int i = 0; i < tamanho; i++) delete [] matriz[i];
    delete [] matriz;
    return 1;
}
