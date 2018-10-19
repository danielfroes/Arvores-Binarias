#include "system.h"

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

}
