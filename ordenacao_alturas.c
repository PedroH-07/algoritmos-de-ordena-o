#include <stdio.h>

#define TAM 10

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
int bubble_sort(int arr[], int n) {
    int i, j, temp;
    int trocas = 0;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}

// Insertion Sort
int insertion_sort(int arr[], int n) {
    int i, j, key, trocas = 0;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
            trocas++;
        }
        arr[j+1] = key;
        // Se houve troca para inserir o elemento, conta como passo
        if(j+1 != i) trocas++;
    }
    return trocas;
}

// Selection 
int selection_sort(int arr[], int n) {
    int i, j, min_idx, temp, trocas = 0;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            trocas++;
        }
    }
    return trocas;
}

int main() {
    int alturas[TAM] = {170, 165, 180, 175, 160, 185, 172, 168, 177, 163};
    int arr_bubble[TAM], arr_insertion[TAM], arr_selection[TAM];
    int i, trocas_bubble, trocas_insertion, trocas_selection;

    // Copiando os vetores para cada algoritmo
    for(i = 0; i < TAM; i++) {
        arr_bubble[i] = alturas[i];
        arr_insertion[i] = alturas[i];
        arr_selection[i] = alturas[i];
    }

    printf("Vetor original:\n");
    print_array(alturas, TAM);

    trocas_bubble = bubble_sort(arr_bubble, TAM);
    printf("\nBubble Sort:\n");
    print_array(arr_bubble, TAM);
    printf("Trocas: %d\n", trocas_bubble);

    trocas_insertion = insertion_sort(arr_insertion, TAM);
    printf("\nInsertion Sort:\n");
    print_array(arr_insertion, TAM);
    printf("Trocas/Passos: %d\n", trocas_insertion);

    trocas_selection = selection_sort(arr_selection, TAM);
    printf("\nSelection Sort:\n");
    print_array(arr_selection, TAM);
    printf("Trocas: %d\n", trocas_selection);

    printf("\nComparação de trocas/passos:\n");
    printf("Bubble Sort: %d\n", trocas_bubble);
    printf("Insertion Sort: %d\n", trocas_insertion);
    printf("Selection Sort: %d\n", trocas_selection);

    return 0;
}