#include <stdio.h>

// Função para exibir o array
void exibirArray(int arr[], int tamanho, char *titulo) {
    printf("%s: [", titulo);
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}

// Função para copiar arrays
void copiarArray(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Algoritmo Bubble Sort (decrescente)
void bubbleSort(int arr[], int tamanho) {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Array original com as pontuações
    int pontuacoes_originais[] = {85, 92, 78, 95, 88, 76, 100, 89, 83, 91, 87, 94};
    int tamanho = sizeof(pontuacoes_originais) / sizeof(pontuacoes_originais[0]);
    
    // Cria cópia para ordenação
    int pontuacoes_ordenadas[12];
    copiarArray(pontuacoes_originais, pontuacoes_ordenadas, tamanho);
    
    printf("=== RANKING DE PONTUAÇÃO DO TORNEIO ===\n\n");
    
    // 1. Exibe a lista original
    exibirArray(pontuacoes_originais, tamanho, "Lista original das pontuações");
    printf("\n");
    
    // Ordena as pontuações
    bubbleSort(pontuacoes_ordenadas, tamanho);
    
    // 2. Exibe a lista final ordenada
    exibirArray(pontuacoes_ordenadas, tamanho, "Lista ordenada (decrescente)");
    printf("\n");
    
    // 3. Mostra em qual posição ficou o jogador com a maior pontuação
    printf("=== RESULTADO FINAL ===\n");
    printf("O jogador com a maior pontuação (%d pontos) ficou na:\n", pontuacoes_ordenadas[0]);
    printf("→ POSIÇÃO 1° LUGAR\n\n");
    
    // Bônus: Mostra o ranking completo
    printf("=== RANKING COMPLETO ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d° lugar: %d pontos\n", i + 1, pontuacoes_ordenadas[i]);
    }
    
    return 0;
}