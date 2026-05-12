#include <stdio.h>
#include <string.h>

/* Struct que armazena as informações de um território */

typedef struct {
    char nome[30]; /* Nome do território (até 29 caracteres) */
    char cor[10]; /* Cor do exército    (até 9 caracteres) */
    int tropas; /* Quantidade de tropas no território     */
} Territorio;
/* Função responsável por ler e armazenar os dados de um território.
   Recebe um ponteiro para o território a ser preenchido e seu índice. */

void cadastrar(Territorio *t, int index) {
    printf("\n=== Cadastro do Territorio %d ===\n", index + 1);

/* Lê o nome usando fgets para evitar estouro de buffer */
    printf("Nome do territorio: ");
    fgets(t->nome, 30, stdin);
    t->nome[strcspn(t->nome, "\n")] = '\0';

    /* Lê a cor do exército */
    printf("Cor do exercito: ");
    fgets(t->cor, 10, stdin);
    t->cor[strcspn(t->cor, "\n")] = '\0';

    /* Lê a quantidade de tropas como inteiro */

    printf("Quantidade de tropas: ");
    scanf("%d", &t->tropas);
    getchar();
}
/* Função responsável por exibir os dados de um território.
   Recebe o território por valor (cópia) e seu índice para exibição. */

void exibir(Territorio t, int index) {
    printf("\n--- Territorio %d ---\n", index + 1);
    printf("Nome:   %s\n", t.nome);
    printf("Cor:    %s\n", t.cor);
    printf("Tropas: %d\n", t.tropas);
}

int main() {

    /* Array que armazena os 5 territórios */

    Territorio territorios[5];

    for (int i = 0; i < 5; i++) {
        cadastrar(&territorios[i], i);
    }

    /* Cabeçalho exibido após o cadastro de todos os territórios */
    
    printf("\n=============================");
    printf("\n   TERRITORIOS CADASTRADOS   ");
    printf("\n=============================");

    for (int i = 0; i < 5; i++) {
        exibir(territorios[i], i);
    }

    return 0;
}