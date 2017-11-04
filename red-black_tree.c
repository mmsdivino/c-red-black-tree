#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define N 100

///////////////////////////////////////////////////////////////////////
/*                    TRABALHO ESTRUTURA DE DADOS                    */
/*           Aluna: Michelle Mendes de Araujo Amor Divino            */
/*                 Turma: Terças e Quintas, 17h/19h                  */
/*     Nome do arquivo zipado: TrabEstDados02-MichelleMendes.zip     */
///////////////////////////////////////////////////////////////////////


// ESTRUTURA ARVORE //
typedef struct RedBlackTree{
	int numero;
	int cor;
	struct RedBlackTree *esq, *dir, *pai;
} rbt;

/* ESTRUTURA FILA //
typedef struct FilaPercursoLargura{
	int chave, ini, vet[N];
}Fila;

Fila* CriarFila(){
	Fila*f=(Fila*)malloc(sizeof(Fila));
	f->chave=0;
	f->ini=0;
	return f;
}

void InsereFila (Fila*f,int v){
	int fim;
	if (f->chave==N){ puts("\aFila nao tem espaco disponivel!"); exit (1);}
	fim=(f->ini+f->chave)%N;
	f->vet[fim]=v;
	f->n++;
}

int FilaVazia(Fila*f){
	return (f->chave==0);
}

int RetiraFila (Fila *f){
	int v;
	if (FilaVazia(f)) { puts("\aFila vazia!"); exit (1); }
	v=f->vet[f->ini];
	f->ini=(f->ini+1)%N;
	f->chave--;
	return f;
}*/

// INICIALIZANDO ARVORE //
rbt* criaArvore (void){
	return NULL;
}

// INSERINDO NA ARVORE //
/*Função Rotação a Esquerda*/
rbt* RotacaoEsq (rbt* Arvore, rbt* x){
	rbt*y=x->dir;
	x->dir=y->esq;
	if (y->esq!=NULL) y->esq->pai=x;
	y->pai=x->pai;
	if (x->pai==NULL) Arvore=y;
	else {
		if (x==x->pai->esq) x->pai->esq=y;
		else x->pai->dir=y;
	}
	y->esq=x;
	x->pai=y;
	return (Arvore);
}

/*Função Rotação a Direita*/
rbt* RotacaoDir (rbt* Arvore, rbt* x){
	rbt*y=x->esq;
	x->esq=y->dir;
	if (y->dir!=NULL) y->dir->pai=x;
	y->pai=x->pai;
	if (x->pai==NULL) Arvore=y;
	else {
		if (x==x->pai->dir) x->pai->dir=y;
		else x->pai->esq=y;
	}
	y->dir=x;
	x->pai=y;
	return (Arvore);
}

/*Função Inserir Rotacionado*/
rbt* InserirRotacionado (rbt* Arvore, rbt* z){
	rbt*y;
	while ((z->pai!=NULL)&&(z->pai->cor==1)){
		if (z->pai==z->pai->pai->esq){
			y=z->pai->pai->dir;
			if ((y!=NULL)&&(y->cor==1)){
				z->pai->cor=0;
				y->cor=0;
				z->pai->pai->cor=1;
				z=z->pai->pai;
			}
			else {
				if (z==z->pai->dir){
					z=z->pai;
					Arvore=RotacaoEsq(Arvore,z);
				}
				z->pai->cor=0;
				z->pai->pai->cor=1;
				Arvore=RotacaoDir(Arvore,z->pai->pai);
			}
		}
		else {
			y=z->pai->pai->esq;
			if ((y!=NULL)&&(y->cor==1)){
				z->pai->cor=0;
				y->cor=0;
				z->pai->pai->cor=1;
				z=z->pai->pai;
			}
			else {
				if (z==z->pai->esq){
					z=z->pai;
					Arvore=RotacaoDir(Arvore,z);
				}
				z->pai->cor=0;
				z->pai->pai->cor=1;
				Arvore=RotacaoEsq(Arvore,z->pai->pai);
			}
		}
	}
	Arvore->cor=0;
	return (Arvore);
}

/* Função Consulta*/
int Consulta (rbt* Arvore, int n){
	if (Arvore==NULL) return -1;
	else {
		if (n==Arvore->numero) return 1;
		else {
			if (n < Arvore->numero) return (Consulta(Arvore->esq,n));
			else return (Consulta(Arvore->dir,n));
		}
	}	
}

/*Função Inserir (Geral)*/
rbt* Inserir (rbt* Arvore, int n){
	rbt*z=(rbt*)malloc(sizeof(rbt));
	if (z==NULL){
		puts("\aErro de memoria! Saindo do programa..."); exit(1);
	}
	if (Consulta(Arvore,n)==-1){
		z->numero=n; z->esq=NULL; z->dir=NULL; z->cor=1;
		rbt*y=NULL;
		rbt*x=Arvore;
		while (x!=NULL){
			y=x;
			if (z->numero < x->numero) x=x->esq;
			else x=x->dir;
		}
		z->pai=y;
		if (y==NULL) Arvore=z;
		else {
			if (z->numero < y->numero) y->esq=z;
			else y->dir=z;
		}
		Arvore=InserirRotacionado(Arvore,z);
	}
	return (Arvore);
}

/*Função para imprimir arvore em ordem crescente*/
void printCrescente(rbt* Arvore) { 
	if (Arvore != NULL){
		printCrescente(Arvore->esq);
		printf("%d\n", Arvore->numero);
		printCrescente(Arvore->dir); 
	}
}

/*Função para imprimir arvore em ordem decrescente*/
void printDecrescente(rbt* Arvore){
	if (Arvore!=NULL){
		printDecrescente(Arvore->dir);
		printf("%d\n",Arvore->numero);
		printDecrescente(Arvore->esq);
	}
}

/*Função para imprimir em largura*/
void printNivel(rbt* Arvore, int nivel){
	if (Arvore){
		if (nivel==1) printf("%d\n",Arvore->numero);
		else {
				printNivel(Arvore->esq,nivel-1);
				printNivel(Arvore->dir,nivel-1);
		}
	}
}

/*Funcao para imprimir arvore em Pre Ordem*/
void PercursoEmOrdem(rbt* Arvore){
	if (Arvore!=NULL){
		PercursoEmOrdem(Arvore->esq);
		if (Arvore->cor==1){
			if ((Arvore->esq!=NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Vermelho FEsq: %d FDir: %d\n",Arvore->numero,Arvore->esq->numero,Arvore->dir->numero);
			else if ((Arvore->esq!=NULL)&&(Arvore->dir==NULL)) printf("Chave: %d Cor: Vermelho FEsq: %d FDir: nil\n",Arvore->numero,Arvore->esq->numero);
			else if ((Arvore->esq==NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Vermelho FEsq: nil FDir: %d\n",Arvore->numero,Arvore->dir->numero);
			else printf("Chave: %d Cor: Vermelho FEsq: nil FDir: nil\n",Arvore->numero);
		}
		else if (Arvore->cor==0){
			if ((Arvore->esq!=NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Preto FEsq: %d FDir: %d\n",Arvore->numero,Arvore->esq->numero,Arvore->dir->numero);
			else if ((Arvore->esq!=NULL)&&(Arvore->dir==NULL)) printf("Chave: %d Cor: Preto FEsq: %d FDir: nil\n",Arvore->numero,Arvore->esq->numero);
			else if ((Arvore->esq==NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Preto FEsq: nil FDir: %d\n",Arvore->numero,Arvore->dir->numero);
			else printf("Chave: %d Cor: Preto FEsq: nil FDir: nil\n",Arvore->numero);	
		}
		PercursoEmOrdem(Arvore->dir);
	}
}

/*Função para imprimir a altura da arvore*/
void AlturaArv(rbt* Arvore, int *x){
	int hr,hl;
	if (Arvore!=NULL){
		(*x)++;
		hr=(*x); hl=(*x);
		AlturaArv(Arvore->esq,&hl);
		AlturaArv(Arvore->dir,&hr);
		if (hr>(*x)) (*x)=hr;
		if (hl>(*x)) (*x)=hl;
	}
}

int AlturaArvRetorno(rbt* Arvore, int *x){
	int hr,hl;
	if (Arvore!=NULL){
		(*x)++;
		hr=(*x); hl=(*x);
		AlturaArv(Arvore->esq,&hl);
		AlturaArv(Arvore->dir,&hr);
		if (hr>(*x)) (*x)=hr;
		if (hl>(*x)) (*x)=hl;
	}
	return (*x);
}

/*Função para imprimir arvore busca em largura*/
void printNivel02(rbt* Arvore, int nivel){
	if (Arvore){
		if (nivel==1) {
			if (Arvore->cor==1){
				if ((Arvore->esq!=NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Vermelho FEsq: %d FDir: %d\n",Arvore->numero,Arvore->esq->numero,Arvore->dir->numero);
				else if ((Arvore->esq!=NULL)&&(Arvore->dir==NULL)) printf("Chave: %d Cor: Vermelho FEsq: %d FDir: nil\n",Arvore->numero,Arvore->esq->numero);
				else if ((Arvore->esq==NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Vermelho FEsq: nil FDir: %d\n",Arvore->numero,Arvore->dir->numero);
				else printf("Chave: %d Cor: Vermelho FEsq: nil FDir: nil\n",Arvore->numero);
			}
			else if (Arvore->cor==0){
				if ((Arvore->esq!=NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Preto FEsq: %d FDir: %d\n",Arvore->numero,Arvore->esq->numero,Arvore->dir->numero);
				else if ((Arvore->esq!=NULL)&&(Arvore->dir==NULL)) printf("Chave: %d Cor: Preto FEsq: %d FDir: nil\n",Arvore->numero,Arvore->esq->numero);
				else if ((Arvore->esq==NULL)&&(Arvore->dir!=NULL)) printf("Chave: %d Cor: Preto FEsq: nil FDir: %d\n",Arvore->numero,Arvore->dir->numero);
				else printf("Chave: %d Cor: Preto FEsq: nil FDir: nil\n",Arvore->numero);	
			}
		}
		else {
				printNivel02(Arvore->esq,nivel-1);
				printNivel02(Arvore->dir,nivel-1);
		}
	}
}

void percursoLargura (rbt* Arvore){
	int y=0,i;
	int h=AlturaArvRetorno(Arvore,&y);
	for (i=0;i<h;i++) printNivel02(Arvore,i);
}

// FUNCOES DO MENU PRINCIPAL //
void ConsultarNo (rbt* Arvore, int n){
	if (Consulta(Arvore,n)==1) printf("Existe no com chave: %i.\n",n);
	else if (Consulta(Arvore,n)==-1) printf("Nao existe no com chave: %i.\n",n);
}

int main(void){
	rbt*ArvoreVP=criaArvore();
	char op1, op4, op;
	int op2, op3, op5,n;
	do {
		scanf("%c",&op1); op=getchar();
		switch (op1){
			case 'i': scanf("%i",&op2); getchar(); ArvoreVP=Inserir(ArvoreVP,op2); break;
			case 'c': scanf("%i",&op3); getchar(); ConsultarNo(ArvoreVP,op3); break;
			case 'p': scanf("%c",&op4); getchar(); switch (op4) {
				case 'd': printDecrescente(ArvoreVP); break;
				case 'c': printCrescente(ArvoreVP); break;
				}
				break;
			case 'n': scanf("%i",&op5); getchar(); printNivel(ArvoreVP,op5); break;
			case 'd': PercursoEmOrdem(ArvoreVP); break;
			case 'l': percursoLargura(ArvoreVP); break;
			case 'a': n=0; n=AlturaArvRetorno(ArvoreVP,&n); printf("%d\n",n); break;
		}
	} while (op1!='e');
	return 0;
}
