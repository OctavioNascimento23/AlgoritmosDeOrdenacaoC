#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 5

// Algoritmos de ordenação
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Função para gerar arrays aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Função para copiar arrays
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Função para medir o tempo de execução de cada algoritmo
void measurePerformance(int arr[], int n) {
    int testArr[n];
    clock_t start;
    double time_taken;

    // Selection Sort
    copyArray(arr, testArr, n);
    start = clock();
    selectionSort(testArr, n);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f segundos\n", time_taken);

    // Insertion Sort
    copyArray(arr, testArr, n);
    start = clock();
    insertionSort(testArr, n);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f segundos\n", time_taken);

    // Bubble Sort
    copyArray(arr, testArr, n);
    start = clock();
    bubbleSort(testArr, n);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f segundos\n", time_taken);

    // Merge Sort
    copyArray(arr, testArr, n);
    start = clock();
    mergeSort(testArr, 0, n - 1);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f segundos\n", time_taken);

    // Quick Sort
    copyArray(arr, testArr, n);
    start = clock();
    quickSort(testArr, 0, n - 1);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f segundos\n", time_taken);

    // Heap Sort
    copyArray(arr, testArr, n);
    start = clock();
    heapSort(testArr, n);
    time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort: %f segundos\n", time_taken);
}

int main() {
    srand(time(NULL));
    int sizes[NUM_TESTS] = {100, 1000, 10000, 50000, 100000};

    for (int i = 0; i < NUM_TESTS; i++) {
        int n = sizes[i];
        int arr[n];
        generateRandomArray(arr, n);
        printf("\nTestando arrays de tamanho %d:\n", n);
        measurePerformance(arr, n);
    }
    printf("Pressione Enter para encerrar...\n");
    scanf("%*c");
    return 0;
}
