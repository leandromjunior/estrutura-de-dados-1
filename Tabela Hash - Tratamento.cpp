
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct aluno {
int mat;
char nome[81]; /* encadeamento na lista de colisão */
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno* Hash[N];

int hash(int mat) {
  return(mat % N);
}

int insere(Hash tab, int mat, char* n){
  int h = hash(mat);
  while(tab[h] != NULL){
    if(tab[h]->mat == mat){
      return -1;
    }
    h = (h+1) % N;
  }
  tab[h] = (Aluno*) malloc(sizeof(Aluno));
  tab[h]->mat = mat;

  strcpy(tab[h]->nome, n);

  return h;
}

int busca(Hash tab, int mat){
  int h = hash(mat);
  while(tab[h] != NULL){
    if(tab[h]->mat == mat){
      return h;
    }
    h = (h+1) % N;
  }
  return -1;
}

int busca_cheia(Hash tab, int mat){
  int h = hash(mat);
  int x = h;

  do{
    if(tab[x] == NULL){
      return -1;
    }
    if(tab[x]->mat == mat){
      return x;
    }
    x = (x+1) % N;
  }while(x!=h);

  return -1;
}

int main()
{
   Hash tab;
   int i, h;
   char nome[81];
   for(i=0;i<N;i++)
      tab[i]= NULL;

// A função insere (int insere(Hash tab, int mat, char*nome)), insere
// o aluno na próxima posição consecutiva livre, em relação à posição de mapeamento.
// Caso a matrícula já exista, não insere e retorna -1. Caso não exista, o aluno é inserido e a
//função retorna a posição "h" em que o aluno foi inserido.
      
   strcpy(nome,"Marco");
   h = insere (tab,127,nome);
   strcpy(nome,"Maria");
   h = insere (tab,254,nome);
   strcpy(nome,"Carlos");
   h = insere (tab,381,nome);
   strcpy(nome,"Sueli");
   h = insere (tab,508,nome);
   h = insere (tab,508,nome); //Não vai inserir!!
   if (h==-1) printf ("Aluno(a) %s ja existe! - nao inserido(a)", nome);
   printf("\n");
   printf("\n");

//vai consultar se um aluno existe na tabela, considerando que a tabela nunca estará completa.
// A função retorna a posição "h" em que o aluno está. Caso não seja encontrado, retorna -1. 
  
   int matric = 381;
   h = busca(tab,matric);
   if(h==-1) printf("Aluno nao encontrado(a)!");
   else printf("Aluno(a) %s pertence a tabela!", tab[h]->nome);
   
   printf("\n");
   printf("\n");

// vai fazer uma nova busca na tabela, dessa vez considerando a possibilidade de a tabela estar completa.
// A função retorna a posição "h" em que o aluno está. Caso não seja encontrado, retorna -1. 
   
   matric = 1200;
   h = busca_cheia(tab,matric);
   if(h==-1) printf("Aluno(a) nao encontrado(a)!");
   else printf("Aluno(a) %s pertence a tabela!", tab[h]->nome); 
     
   return 0;
}
