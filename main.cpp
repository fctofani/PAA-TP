#include <iostream>

using namespace std;

int** leGrafo(int&);
void imprimeMatriz(int**, int);
short deletaMatriz(int**, int);

int main()
{
    int tam;
    int** mat = leGrafo(tam);
//    imprimeMatriz(mat, tam);
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
