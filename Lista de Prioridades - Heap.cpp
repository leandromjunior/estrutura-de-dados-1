#include<stdio.h>
#include<stdlib.h>

#define N 100

struct _heap {
int max; /* tamanho maximo do heap máximo */
int pos; /* proxima posicao disponivel no vetor */
float* prioridade; /* vetor das prioridades */
};
typedef struct _heap Heap;

Heap* heap_cria(int max){
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->max = max;
  heap->pos = 0;
  heap->prioridade = (float*)malloc(max*sizeof(float));
  
  return heap;
}

static void troca (int a, int b, float*v){
  float f = v[a];
  v[a] = v[b];
  v[b] = f;
}

static void corrige_acima(Heap* heap, int pos){
  while(pos > 0){
    int pai = (pos-1) / 2;
    if(heap->prioridade[pai] < heap->prioridade[pos]){
      troca(pos,pai,heap->prioridade);
    }
    else{
      break;
    }

    pos = pai;
  }
}

void heap_insere(Heap* heap, float prioridade){
  if(heap->pos < heap->max){
    heap -> prioridade[heap->pos] = prioridade;
    corrige_acima(heap,heap->pos);
    heap->pos++;
  }
  else{
    printf("Heap Lotado ! \n");
  }
}

static void corrige_abaixo(Heap* heap){
  int pai = 0;
  while(2*pai + 1 < heap->pos){
    int filho_esq = 2*pai + 1;
    int filho_dir = 2*pai + 2;
    int filho;

    if(filho_dir >= heap->pos){
      filho_dir = filho_esq;
    }

    if(heap->prioridade[filho_esq] > heap->prioridade[filho_dir]){
      filho = filho_esq;
    }
    else{
      filho = filho_dir;
    }

    if(heap->prioridade[pai] < heap->prioridade[filho]){
      troca(pai, filho, heap->prioridade);
    }
    else{
      break;
    }

    pai = filho;
  }
}

float heap_remove(Heap* heap){
  if(heap->pos > 0){
    float topo = heap->prioridade[0];
    heap->prioridade[0] = heap->prioridade[heap->pos-1];
    heap->pos--;
    corrige_abaixo(heap);
    return topo;
  }
  else{
    printf("O Heap está vazio!");
    return -1;
  }
}

void imprime_vetor(Heap* heap){
  int i;
  for(i=0; i<heap->pos; i++){
    printf("%6.2f", heap->prioridade[i]);
  }
}

int heap_vazio(Heap* heap){
  return heap->pos == 0;
}

int heap_cheio(Heap* heap){
  return heap->pos == N;
}

float consulta_segunda(Heap* heap){
  if(heap->pos >= 2){
    float e1, e2;
    e1 = heap->prioridade[1];
    if(heap->pos > 2){
      e2 = heap->prioridade[2];
    }
    else{
      e2 = e1;
    }

    if(e2 > e1){
      return e2;
    }
    else{
      return e1;
    }
  }
  else{
    return -1;
  }
}

void imprime_maiores(Heap* heap){
  float v[3] = {-1,-1,-1};
  int i = 0;

  while(!heap_vazio(heap) && i < 3){
    v[i] = heap_remove(heap);
    i++;
  }

  for(i=0; i < 3; i++){
    if(v[i] != -1){
      printf("\n Prioridade %d: %.2f", i+1, v[i]);
      heap_insere(heap, v[i]);
    }
    else{
      printf("\n Sem prioridade %d", i+1);
    }
  }
}

void imprime_em_ordem(Heap* heap){
  Heap* aux = heap_cria(N);
  float v;
  while(!heap_vazio(heap)){
    v = heap_remove(heap);
    printf("%6.2f", v);
    heap_insere(aux, v);
  }

  while(!heap_vazio(aux)){
    heap_insere(heap, heap_remove(aux));
  }
}
int main(){

    //vai criar um heap vazio
    Heap *heap = heap_cria(N);
    
   float v;
    
    //vai inserir elementos no heap
    heap_insere(heap, 11.0);
    heap_insere(heap, 8.0);
    heap_insere(heap, 5.0);
    heap_insere(heap, 4.0);
    heap_insere(heap, 3.0);
    heap_insere(heap, 16.0);
    heap_insere(heap, 8.5);
    heap_insere(heap, 4.3);
    
    //vai imprimir o vetor das prioridades
    imprime_vetor(heap);
    
    //vai remover um elemento do heap
    v = heap_remove(heap);
    printf("\nElemento removido: %6.2f\n", v);
    imprime_vetor(heap);
    printf("\n");

    //vai consultar o segunda maior prioridade
    v = consulta_segunda(heap);
    if(v!= -1)   printf("\nSegunda maior prioridade: %6.2f\n", v);
	
    
   //vai imprimir as 3 maiores prioridades usando as funções anteriores (insere e remove)
    imprime_maiores(heap);
    printf("\n");
   
    //vai imprimir as prioridades em ordem decrescente, usando as funções anteriores (insere e remove) - use um heap auxiliar!
    imprime_em_ordem(heap);
    printf("\n");
    imprime_vetor(heap);
    printf("\n");
    
    v = heap_remove(heap);
    v = heap_remove(heap);
    v = heap_remove(heap);
    v = heap_remove(heap);
    
    imprime_maiores(heap);
    printf("\n");
    imprime_vetor(heap);
    printf("\n");
    
	
    system("pause");
    return 0;
}
