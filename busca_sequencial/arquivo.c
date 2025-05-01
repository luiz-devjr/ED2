#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 30000

// Função para gravar o vetor em um arquivo texto
void gravar_vetor(const char *nome_arquivo, int vetor[], size_t tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

// Função para ler o vetor de um arquivo texto
void ler_vetor(const char *nome_arquivo, int vetor[], size_t tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &vetor[i]) != 1) {
            fprintf(stderr, "Erro de leitura no elemento %zu\n", i);
            fclose(arquivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(arquivo);
}

// Exemplo de uso
int main() {
    int vetor[TAMANHO];

    // Preencher vetor com dados de exemplo
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i;
    }

    gravar_vetor("vetor.txt", vetor, TAMANHO);

    // Zerar o vetor para testar a leitura
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = 0;
    }

    ler_vetor("vetor.txt", vetor, TAMANHO);

    // Exibir alguns elementos para confirmar que leu certo
    for (int i = 0; i < 10; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
