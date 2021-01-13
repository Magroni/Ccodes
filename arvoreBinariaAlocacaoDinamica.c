// Implementação de uma arvore binária alocada dinamicamente
#include <stdlib.h>
#include <stdio.h>
// TAD que representa um no da arvore binária
struct no{
    int info;
    struct no *esq;
    struct no *dir;
};
// Renomeia a estrutura
typedef struct no* arvBin;
// Função que cria uma arvore binária
arvBin* criaArvBin (){
    // Aloca dinâmicamente
    arvBin *raiz = (arvBin*)malloc(sizeof(arvBin));
    // Testa se a alocação foi bem sucedida e atribui o valor NULL a ela
    if(raiz != NULL) *raiz = NULL;
    // Retorna a arvore criada 
    // A função deverá ser chamada desta forma: "arvBin* raiz = criaArvBin();"
}
arvBin* arv_criavazia(void){
   return NULL;
 }

arvBin* criaNo(int info, arvBin e, arvBin d){
    arvBin* p = (arvBin*)malloc(sizeof(arvBin));
    p->info = info;
    p->esq = e;
    p->dir = d;
    return p;
}
// Função que libera um nó através de recursão
void liberaNo (struct no* no){
    // Verifica se no está alocado
    if(no == NULL) return;
    // Percore recursivamente através dos nós
    liberaNo(no->esq);
    liberaNo(no->dir);
    // Libera o nó
    free(no);
    no=NULL;
}
// Funcção que libera inteiramente a árvore
void liberaArvBin (arvBin* raiz){
     // Verifica se raiz está alocado
    if(raiz == NULL) return;
    // Utiliza de outra função para liberar os nós da árvore
    liberaNo(*raiz);
    // Por fim, libera a raiz
    free(raiz);
}
// Função que verifica se a árvore binária está vazia
int arvBinEstaVazia (arvBin *raiz){
    // Retorna 1 se o conteudo de raiz ou raiz apontar para NULL (vazia)
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;
    // Retorna 0 se não estiver vazia
    return 0;
    }
    // Função que retorna a altura da árvore
int alturaArvBin (arvBin *raiz){
    // Retorna 0 se a árvore estiver vazia
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;
    // Percorre a árvore recursivamente
    int alturaEsq = alturaArvBin(&((*raiz)->esq));
    int alturaDir = alturaArvBin(&((*raiz)->dir));
    // Retorna a altura da árvore
    if (alturaEsq>alturaDir) return alturaEsq  + 1;
    else return alturaDir + 1;
}
int totalDeNos(arvBin *raiz){
    // Retorna 0 se a árvore estiver vazia
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;
    // Percorre a árvore recursivamente
    int alturaEsq = totalDeNos(&((*raiz)->esq));
    int alturaDir = totalDeNos(&((*raiz)->dir));
    // Retorna a soma das alturas pela esquerda e pela direita mais um (raiz)
    return (alturaDir * alturaEsq + 1);
}

void imprimePreOrdemArvBin (arvBin *raiz){
    // Tratamento do ponteiro
    if(raiz == NULL) return;
    if(*raiz != NULL){
        // Imprime recursivamente cada nó da arvore
        printf("%d\n", (*raiz)->info);
        imprimePreOrdemArvBin(&((*raiz)->esq));
        imprimePreOrdemArvBin(&((*raiz)->dir));
    }
}

void imprimeEmOrdemArvBin (arvBin *raiz){
    // Tratamento do ponteiro
    if(raiz == NULL) return;
    if(*raiz != NULL){
        // Imprime recursivamente de forma ordenada cada nó da arvore
        imprimeEmOrdemArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        imprimeEmOrdemArvBin(&((*raiz)->dir));
    }
}

void imprimePosOrdemArvBin (arvBin *raiz){
 if(raiz == NULL) return;
    if(*raiz != NULL){
        // Imprime recursivamente de forma ordenada os ultimos nó da arvore
        imprimePosOrdemArvBin(&((*raiz)->esq));
        imprimePosOrdemArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int main(){
    arvBin *raiz = criaArvBin();
    int a;
    a = arvBinEstaVazia(raiz);
    printf("%i\n", a);

    (*raiz)->esq = criaArvBin();
    a = arvBinEstaVazia(raiz);
    printf("%i", a);
    imprimeEmOrdemArvBin(raiz);
    return 0;
}