#include<stdlib.h>
#include<stdio.h>

struct arv {
  int info;
  struct arv*pai;
  struct arv* esq;
  struct arv* dir;
};
typedef struct arv Arv;

Arv* arv_criavazia() {
  return NULL;
}

int arv_vazia(Arv*a) {
  return a == NULL;
}

Arv* cria_filha(Arv* a, int v) {
  Arv* no = (Arv*)malloc(sizeof(Arv));
  no ->info = v;
  no->pai = a;
  no->esq = no->dir = NULL;
  return no;
}

Arv* abb_insere(Arv* r, int val) {
  Arv* z = cria_filha(NULL, val);
  if(r == NULL){
    return z;
  }
  else{
    Arv* p = NULL;
    Arv* x = r;
    while(x != NULL){
      p = x;
      x = (val < x->info)? x->esq : x->dir;
    }
    z -> pai = p;
    if(val < p->info){
      p->esq = z;
    }
    else{
      p->dir = z;
    }
    return r;
  }
}

Arv* busca_no(Arv* a) {
  if(a == NULL) {
    return NULL;
  }
  Arv* f = a->esq;
  if(f == NULL){
    return NULL;
  }
  while(f->dir != NULL){
    f = f->dir;
  }
  return f;
}

Arv *menor(Arv*a)
{
	if(a->esq!=NULL)
  {
    return menor(a->esq);
	}
	else return a;
}

Arv* abb_busca_pai(Arv* r, int v){
  if(r == NULL){
    return NULL;
  }
  else if(r->info > v){
    return abb_busca_pai(r->esq, v);
  }

  else if(r->info < v) {
    return abb_busca_pai(r->dir, v);
  }
  else{
    return r->pai;
  }
}

Arv* raiz(Arv* a){
  if(a->pai == NULL){
    return a;
  }
  else{
    return raiz(a->pai);
  }
}

Arv* arv_libera(Arv* a){
  if(!arv_vazia(a)){
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
  return NULL;
}

void imprime_crescente(Arv* a){
  if(!arv_vazia(a)){
    imprime_crescente(a->esq);
    printf("%2d", a->info);
    imprime_crescente(a->dir);
  }
}

void showmenor(Arv* a, int num){
  if(!arv_vazia(a)){
    showmenor(a->esq, num);
    if(a->info <= num){
      printf("%2d", a->info);
    }
    showmenor(a->dir, num);
  }
}


int main(){
    
    Arv*a, *b;

    /*implementar  a fun��o "Arv* arv_criavazia();" */
    a = arv_criavazia();

    /*implementar  a fun��o "Arv* abb_insere (Arv* r, int val);" que vai inserir, iterativamente, valores na �rvore*/
    a = abb_insere (a,6);
    a = abb_insere (a,2);
    a = abb_insere (a,8);
    a = abb_insere (a,1);
    a = abb_insere (a,4);
    a = abb_insere (a,3);
   
    
    /* implementar a fun��o "void imprime_crescente(Arv *a);" que vai imprimir, recursivamente, todos os elementos em ordem crescente */
    imprime_crescente(a); 
    printf("\n");

    /* implementar a fun��o "Arv* abb_busca_pai (Arv* r, int v);" que vai buscar, recursivamente, um valor na �rvore, retornando um ponteiro para o SEU N� PAI*/
    Arv*k = abb_busca_pai(a,1);
    if (k!=NULL) printf(" A informacao do PAI do no encontrado = %d\n", k->info);

    printf("\n");
  
    /*implementar a fun��o "void showmenor(Arv* a, int x);" que imprime, recursivamente, todos os valores nos n�s da �rvore a que sejam menores que x, em ordem
crescente.*/
    showmenor(a,5);
    printf("\n");
    
    /* implementar a fun��o "Arv* menor (Arv* a);" que encontra, iterativamente, um ponteiro para o menor valor da �rvore*/
    k = menor(a);
    if (k!=NULL) printf(" A menor informacao = %d\n", k->info);

    /*implementar a fun��o "Arv* raiz (Arv*a);" que encontra a raiz da �rvore a partir do ponteiro k, qua aponta para o menor valor*/
    b = raiz(k);
    printf(" A informa��o da raiz = %d\n", b->info);
    
    printf("\n");
    /*implementar a fun��o "Arv* busca_no (Arv*a);" que encontra um ponteiro para o n� que imediatamente antecede a raiz*/
    k = busca_no(a);
    if (k!=NULL) printf(" Valor que antecede a raiz = %d\n", k->info);
	else printf("N�o ha valor!");

    /*implementar a fun��o "Arv* arv_libera (Arv*a);" que libera a mem�ria alocada para toda �rvore, retornando um ponteiro NULL*/
    arv_libera(a);
    system("pause");
    return 0;
}
