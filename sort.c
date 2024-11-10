#include <stdio.h>
#include <time.h>

// Função para ordenar usando Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para ordenar usando Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para ordenar usando Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função auxiliar para mesclar duas metades no Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Função para ordenar usando Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Função para particionar o array no Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Função para ordenar usando Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para construir o heap no Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Função para ordenar usando Heap Sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Função para exibir o menu e selecionar o algoritmo de ordenação
void menu() {
    int arr[] = {4, 123, 45, 4688, 5148, 648, 76};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    do {
        printf("\nEscolha um algoritmo de ordenacao:\n");
        printf("1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n");
        printf("4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Sair\nOpcao: ");
        scanf("%d", &choice);

        clock_t start = clock();
        switch (choice) {
            case 1: selectionSort(arr, n); break;
            case 2: insertionSort(arr, n); break;
            case 3: bubbleSort(arr, n); break;
            case 4: mergeSort(arr, 0, n - 1); break;
            case 5: quickSort(arr, 0, n - 1); break;
            case 6: heapSort(arr, n); break;
            case 7: printf("Saindo do programa...\n"); return;
            default: printf("Opcao invalida!\n"); continue;
        }
        double time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao: %f segundos\n", time_taken);

        printf("Array ordenado: ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");

    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
