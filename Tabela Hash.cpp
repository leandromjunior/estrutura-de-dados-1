#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct aluno {
int mat;
char nome[81];
struct aluno* prox; /* encadeamento na lista de colisão */
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno* Hash[N];

int hash(int mat){
  return (mat%N);
}

Aluno* busca (Hash tab, int mat){
  int h = hash(mat);
  Aluno* a = tab[h];
  while (a != NULL){
  	if(a->mat == mat){
      return a;
    }
  	a = a->prox;
  }
  return NULL;	
}

int insere_ult (Hash tab, int mat, char nome[81]){
  int h = hash(mat);

  Aluno* a = tab[h];
  Aluno* ant = NULL;
  while (a != NULL) 
  {
    ant = a;
    if (a->mat == mat)
    {
      return 1;
    }
    a = a->prox;
  }

/*Ultimo elemento*/
  a = (Aluno*) malloc(sizeof(Aluno));
  a->mat = mat;
  strcpy(a->nome,nome);
  a->prox = NULL;
  if(ant==NULL){
    tab[h] = a;
  } 
  else
   ant->prox = a;

  return 0;
}

int retira (Hash tab, int mat){
  int h = hash(mat);
  Aluno* a = tab[h];
  Aluno* ant = NULL;
  while (a != NULL) {
    if (a->mat == mat)
      break;
    ant = a;
    a = a->prox;
  }
 
  if (a==NULL) return 1; //Se não achar o  elemento, retorna 1 

  if (ant == NULL){
    tab[h] = a->prox; 
  }
  else{ 
    ant->prox = a->prox; 
  }

  free(a);

  return 0 ;
}



int main(){
   Hash tab;
   int i;
   char nome[81];
   for(i=0;i<N;i++)
      tab[i]= NULL;
// A função insere_ult (int insere_ult(Hash tab, int mat, char*nome)), insere
// o aluno na última posição da lista, caso ele não exista, retornando 0.
// Caso a matrícula exista, não insere e retorna 1.      
   strcpy(nome,"Marco");
   i = insere_ult (tab,127,nome);
   strcpy(nome,"Maria");
   i = insere_ult (tab,254,nome);
   strcpy(nome,"Carlos");
   i = insere_ult (tab,381,nome);
   strcpy(nome,"Sueli");
   i = insere_ult (tab,508,nome);
   i = insere_ult (tab,508,nome); //Não vai inserir!!
   if (i==1) printf ("Aluno(a) %s ja existe! - nao inserido(a)", nome);
   printf("\n");
   printf("\n");

//vai consultar se um aluno existe na tabela

   Aluno* k = busca(tab,381);
   if(k==NULL) printf("Aluno(a) nao encontrado(a)!");
   else printf("Aluno(a) %s pertence a tabela!", k->nome);
   
   printf("\n");
   printf("\n");

//caso o aluno seja encontrado, a função retira do encadeamento, retornando 0.
//Caso contrário, retorna 1.   
   i = retira(tab,381);
   k = busca(tab,381);
   if(k==NULL) printf("Aluno(a) nao encontrado(a)!");
   else printf("Aluno(a) %s pertence a tabela!", k->nome); 
     
   return 0;
}
