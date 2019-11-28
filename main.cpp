#include <iostream>

#define FOR_I(n) for(int i = 0; i < n; i++)
#define FOR_J(n) for(int j = 0; j < n; j++)

using namespace std;

int** leGrafo(int&);
void imprimeMatriz(int**, int);
short deletaMatriz(int**, int);

int solucaoInicial(int**, int);

bool completa(int*, int); // checa se a solução tem algum valor com -1
int numvertices(int*, int); // retorna a quantidade de 1 da solucao
bool consistente(int*, int, int**); // vê se tem dois vértices adjacentes na solucao.

void buscaMelhor(int*, int, int*, int**);


int main()
{
    int tam;
    int** mat = leGrafo(tam);
    int* solucao = new int[tam];
    FOR_I(tam) solucao[i] = -1;

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
    FOR_I(tamanho) matriz[i] = new int [tamanho];

    FOR_I(tamanho){
        FOR_J(tamanho) fscanf(arquivo, "%d", &matriz[i][j]);
    }
    fclose(arquivo);
    return matriz;
}

int solucaoInicial(int** grafo, int tam){
    int* solucao = new int[tam];
    FOR_I(tam) solucao[i] = 0;

    solucao[0] = 1; // coloca o primeiro vértice na solução
    bool flag = true; // checa se o vértice atual é adjacente ao que está sendo comparado
    int cont = 1; // qtd de vértices na solução

    FOR_I(tam){
        FOR_J(tam){
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
    FOR_I(tam) cout << " | " << solucao[i];
    cout << endl;

    return cont;
}

bool completa(int* solucao, int tam){
    FOR_I(tam){
        if (solucao[i] == -1) return false;
    }
    return true;
}

int numvertices(int* solucao, int tam){
    int cont = 0;
    FOR_I(tam){
        if(solucao[i] == 1) cont++;
    }
    return cont;
}

bool consistente(int* solucao, int tam, int** grafo){
    FOR_I(tam){
        if(solucao[i] == 1){
            FOR_J(tam){
                if(grafo[i][j] == 1 && solucao[j] == 1) return false;
            }
        }
    }
    return true;
}

void buscaMelhor(int* solucao, int tam, int* otima, int** grafo){
    if(completa(solucao, tam)){
        *otima = numvertices(solucao, tam);
    }
    else{

    }
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
