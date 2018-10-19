#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ROOT 0

struct Node {
   int chave;
   int valor;
   struct Node *esq;
   struct Node *dir;
};

typedef struct Node Node;
typedef struct Node* NodePtr;

// Functions
NodePtr InsertRecursion(NodePtr root, int chave, int valor);
void InsertLoop(NodePtr* root, int chave, int valor);
void searchRecursion(NodePtr root, int chave, int level);
void removeNode(NodePtr root, int chave);
int menu();
void cleanScreen();
void cleanBuffer();
void pressEnter();
void MenuSobre();

#endif //SYSTEM_H