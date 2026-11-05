#include<stdio.h>
#include<stdlib.h>

typedef struct No {
    struct No* right;
    struct No* left;
    int height;
    int value;
} No;

// função de criar No
No* createNewNo(int value) {
    No* no = malloc(sizeof(No));
    no->height = 1;
    no->right = NULL;
    no->left = NULL;
    no->value = value;
}

int height(No* tree) {
    return tree ? tree->height : 0;
}

int bigger(int a, int b) {
    return a > b ? a : b;
}

void updateHeight(No* tree) {
    // olha qual dos filhos é maior
    // pega o maior e soma + 1
    tree->height = bigger(tree->left->height, tree->right->height) + 1;
}

int balancingFactor(No* tree) {
    // subtrai a altura dos filhos Esquerda - Direita
    return tree ? height(tree->left) - height(tree->right) : 0;
}

No* rotacaoEsquerda(No* tree) {

}

// criar função de inserção na arvore
No* addNewNo(No* tree, int value) {
    // cria o nó quando a arvore chega na base.
    if (tree == NULL){
        return createNewNo(value);
    }

    // encontra onde será inserido
    if (value < tree->left) {
        // adiciona na esquerda
        tree->left = addNewNo(tree->right, value);
    }   
    else if (value > tree->right) {
        // adiciona na direita
        tree->right = addNewNo(tree->right, value);
    } else {
        // igual, não adiciona
        return tree;
    }

    // atualiza a altura do no
    updateHeight(tree);

    // verifica fator de balanceamento
    int factor = balancingFactor(tree);

    // se for LL (left left)
    if (factor > 1 && value < tree->left->value) {
        return rotacaoEsquerda(tree);
    }

    // se for RR (right right)
    if (factor < -1 && value > tree->right->value) {
        return rotacaoDireita(tree);
    }

    // se for LR (left right)
    if (factor > 1 && value > tree->left->value) {
        tree->left = rotacaoEsquerda(tree->left);
        return rotacaoDireita(tree);
    }

    // se for RL (right left)
    if (factor < -1 && value < tree->right->value) {
        tree->right = rotacaoDireita(tree->right);
        return rotacaoEsquerda(tree);
    }

    return tree;

}


int main() {

    No* tree = NULL;

    printf("Criando arvore");

    // adicionando primeiro elemento:
    tree = addNewNo(tree, 10);
    
}