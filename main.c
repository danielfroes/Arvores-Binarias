#include "system.h"

// TODO: 
//DONE -Insert com loop
//DONE -Insert com recursão 
// -Insert com ponteiro duplo

int main(){
int chave, valor;
int loop = TRUE;
NodePtr root = NULL; //Inicia a raiz como root

while(loop == TRUE){
    cleanScreen();
    int inputUser = menu();
    switch(inputUser){
        case 1:
            printf("Digite a chave:");
            scanf("%d", &chave);
            cleanBuffer();
            printf("Digite o valor:");
            scanf("%d", &valor);
            InsertRecursion(root, chave, valor);
        break;

        case 2:
            printf("Digite a chave:");
            scanf("%d", &chave);
            cleanBuffer();
            removeNode(root, chave);
        break;

        case 3:
            printf("Digite a chave:");
            scanf("%d", &chave);
            cleanBuffer();
            searchRecursion(root, chave, ROOT);
        break;

        case 4:
            MenuSobre();
        break;

        case 5:
            exit(0);
        break;

        default:
            printf("Opcao inexistente");
        break;
    }
    pressEnter();
}
// InsertLoop(&root, 5, 5);
// InsertLoop(&root, 3, 3);
// InsertLoop(&root, 7, 7);
// InsertLoop(&root, 2, 2);
// InsertLoop(&root, 4, 4);
// InsertLoop(&root, 6, 6);
// InsertLoop(&root, 8, 8);
// InsertLoop(&root, 20, 20);
// InsertLoop(&root, 19, 19);
// InsertLoop(&root, 18, 18);
// InsertLoop(&root, 17, 17);

// InsertLoop(&root, 40, 40);
// InsertLoop(&root, 41, 41);
// InsertLoop(&root, 35, 35);
// InsertLoop(&root, 30, 30);
// InsertLoop(&root, 36, 36);
// InsertLoop(&root, 38, 38);
// InsertLoop(&root, 37, 37);

// removeNode(root, 20);


// searchRecursion(root, 17, ROOT);


}