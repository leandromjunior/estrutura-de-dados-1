#include <stdio.h>
#include <stdlib.h>

struct arv {
  char info[81];
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;

int cheia (Arv* a);

Arv* arv_criavazia(void){
  return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad) {
  Arv* p = (Arv*)malloc(sizeof(Arv));
  if(p==NULL) {
    printf("Erro de memória");
    exit(1);
  }
  p  -> info[c] = c; //char
  p -> esq = sae;
  p -> dir = sad;
  return p;
}

int main(){
  int num_return = 0; //Variável de retorno

  Arv* l = arv_cria('L', arv_criavazia(), arv_criavazia());
  Arv* k = arv_cria('K',arv_criavazia(),l);
  Arv* j = arv_cria('J',arv_criavazia(),arv_criavazia());
  Arv* i = arv_cria('I',arv_criavazia(),j);
  Arv* f = arv_cria('F',arv_criavazia(),arv_criavazia());
  Arv* e = arv_cria('E',k,f);
  Arv* m = arv_cria('M',arv_criavazia(),arv_criavazia());
  Arv* h = arv_cria('H',m,i);
  Arv* g = arv_cria('G',arv_criavazia(),arv_criavazia());
  Arv* d = arv_cria('D',h,arv_criavazia());
  Arv* c = arv_cria('C',g,d);
  Arv* b = arv_cria('B',e,c);
  Arv* a = arv_cria('A',b,arv_criavazia());

  num_return = cheia(a); //cheia(protótipo da função)

  printf("\n Retorno: %d\n", num_return);

  if(num_return == 1) {
    printf("A árvore está cheia");
  }
  else {
    printf("A árvore está vazia");
  }

  return 0;
}

int cheia (Arv* a) {
  if (a == NULL) {
    return 0;
  }
  else if ((a->dir == NULL && a->esq != NULL) || (a->dir != NULL && a->esq == NULL)) {
    return 1;
  }
  else{
    return cheia(a->dir) && cheia(a->esq);
  }
}
