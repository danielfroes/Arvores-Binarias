#include "system.h"

void splashScreen() {
    //Telinha
}

void cleanScreen(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void cleanBuffer(){
	while ( getchar() != '\n' );
}

void pressEnter(){
	printf("\n\n        Pressione ENTER para prosseguir\n\n");
	char c = getchar();
	while (c != '\n')
		c = getchar();
}

void MenuSobre(){
	cleanScreen();
	printf("              Implentacao de Arvores Binarias\n");
	printf("                       Sobre o projeto       \n\n\n\n\n\n");
	printf("      Programa para criacao e manipulacao de arvores binarias\n\n");
	printf(" Projeto da disciplina de Introducao a Ciencia da Computacao II\n\n");
	printf("                 Universidade de Sao Paulo\n\n\n");
	printf("\n\nPressione ENTER para seguir para as informacoes dos autores\n\n");
	char c = getchar();
	while (c != '\n')
		c = getchar();

	cleanScreen();
	printf("                     Criado por:\n");
	printf("                   Daniel Froes\n");
	printf("                      email seu\n");
	printf("                        seu github\n\n");
	printf("                         e\n\n");
	printf("              Gabriel Santos Nicolau:\n");
	printf("            gabriel.nicolau97@hotmail.com\n");
	printf("                 github.com/7Nic\n\n");
}

int menu(){
    int inputUser;
    printf("                       Menu principal\n");
    printf("\n");
    printf("1 - Inserir elemento                   2 - Remover elemento\n");
    printf("3 - Buscar elemento                    4 - Sobre\n");
    printf("5 - Sair do programa\n");
    printf("\n");
    printf("Digite sua escolha:");
    scanf("%d", &inputUser);
    cleanBuffer();
    return inputUser;
}

NodePtr InsertRecursion(NodePtr root, int chave, int valor){
    if(root == NULL){
        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        newNode->chave = chave;
        newNode->valor = valor;
        return newNode;
    }
    else if(chave == root->chave){
        root->valor = valor;
        return root;
    }
    else if(chave > root->chave){
        root->dir = InsertRecursion(root->dir, chave, valor);
    }
    else if(chave < root->chave){
        root->esq = InsertRecursion(root->esq, chave, valor);
    }
}

void InsertLoop(NodePtr* root, int chave, int valor){
    if(*root == NULL){
        *root = (NodePtr)malloc(sizeof(Node));
        (*root)->chave = chave;
        (*root)->valor = valor;
        (*root)->dir = NULL;
        (*root)->esq = NULL;
        return;
    }
    NodePtr current = *root;
    NodePtr Daddy = *root;
    while(current != NULL){
        if(current->chave == chave){
            current->valor = valor;
            return;
        } 
        else if(chave > current->chave){
            Daddy = current;
            current = current->dir;
        }
        else if(chave < current->chave){
            Daddy = current;
            current = current->esq;
        }
    }
    current = (NodePtr)malloc(sizeof(Node));
    current->chave = chave;
    current->valor = valor;
    current->esq = NULL;
    current->dir = NULL;
    if(chave > Daddy->chave){
        Daddy->dir = current;
    } else {
        Daddy->esq = current;
    }
}

//O level será acrescido de um a cada chamada da função
void searchRecursion(NodePtr root, int chave, int level){
    level++;
    if(root == NULL){
        printf("Chave nao encontrada na busca\n");
        return;
    } 
    if(chave == root->chave){
        printf("O valor associado a chave e: %d, e seu nivel e: %d\n", root->valor, level);
        return;
    }
    else if(chave > root->chave){
        searchRecursion(root->dir, chave, level);
    } else {
        searchRecursion(root->esq, chave, level);
    }
}

void removeNode(NodePtr root, int chave){
    NodePtr current = root;
    NodePtr Daddy = root;
    int childIsOnTheRight;

    //Buscar o elemento
    while(current != NULL && current->chave != chave){
        Daddy = current;
        if(chave > current->chave){
            childIsOnTheRight = TRUE;
            current = current->dir;
        } else{
            childIsOnTheRight = FALSE;
            current = current->esq;
        }
    }

    //Se nao achar o valor
    if(current == NULL){
        printf("Chave nao encontrada na remoção\n");
        return;
    }

    //Se nao houver filhos
    if(current->dir == NULL && current->esq == NULL){
        free(current);
        if(childIsOnTheRight == TRUE){
            Daddy->dir = NULL;
        } else {
            Daddy->esq = NULL;
        }
        return;
    }

    //If has two childs
    if(current->dir != NULL && current->esq != NULL){
        NodePtr predecessor = current;
        NodePtr DaddyOfPredecessor = current;

        //Find the predecessor
        predecessor = predecessor->esq;        
        while(predecessor->dir != NULL){
            DaddyOfPredecessor = predecessor;
            predecessor = predecessor->dir;
        }

        if(DaddyOfPredecessor == current){
            DaddyOfPredecessor->esq = predecessor->esq;
        } else {
            //If predecessor->esq is NULL, it's ok, if predecessor has a child on the left, it's also ok 
            DaddyOfPredecessor->dir = predecessor->esq;
        }

        // Once found, make the new bounds
        predecessor->dir = current->dir;
        predecessor->esq = current->esq;
        if(childIsOnTheRight == TRUE){
            Daddy->dir = predecessor;
        } else {
            Daddy->esq = predecessor;
        }
        free(current);
        return;
    }
    
    //Se houver um filho (por eliminação, se o código chegar aqui necessariamente será isso)
    
    //Se o filho do no a ser eliminado for da direita
    if(current->dir != NULL){
        //Verificar para que lado do pai o current esta
        if(childIsOnTheRight == TRUE){
            Daddy->dir = current->dir;
        } else{
            Daddy->esq = current->dir;
        }
    } else{ //Se o filho do no a ser eliminado for da esquerda
        //Verificar para que lado do pai o current esta
        if(childIsOnTheRight == TRUE){
            Daddy->dir = current->esq;
        } else{
            Daddy->esq = current->esq;
        }
    }
    free(current);
}