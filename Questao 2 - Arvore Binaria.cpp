#include <stdio.h>
#include<stdlib.h>

struct arv {
char info;
struct arv *esq;
struct arv *dir;
};
typedef struct arv Arv;

void pre(Arv* a){
  if(a!=NULL){
    printf(" %c", a->info);
    pre(a->esq);
    pre(a->dir);
  }
}

void pos(Arv* a){
  if(a!=NULL){
    pos(a->esq);
    pos(a->dir);
    printf(" %c", a->info);
  }
}

void ordemSimetrica(Arv* a){
  if(a!=NULL){
    ordemSimetrica(a->esq);
    printf(" %c", a->info);
    ordemSimetrica(a->dir);
  }
}

Arv* arv_criavazia(void){
  return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad) {
  Arv* p = (Arv*)malloc(sizeof(Arv));
  if(p==NULL) {
    printf("Erro de memória");
    exit(1);
  }
  p  -> info = c;
  p -> esq = sae;
  p -> dir = sad;
  return p;
}

int main(){

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

  printf("\n Pre-Ordem: \n");
  pre(a);

  printf("\n Pos-Ordem: \n");
  pos(a);

  printf("\n Ordem Simetrica: \n");
  ordemSimetrica(a);

  return 0;
}
