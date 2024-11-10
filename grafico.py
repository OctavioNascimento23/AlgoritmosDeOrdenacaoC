import matplotlib.pyplot as plt

# Tamanhos de entrada e tempos de execução (em segundos) simulados para cada algoritmo
sizes = [100, 1000, 10000, 50000, 100000]
selection_times = [0.0, 0.001, 0.1, 2.489, 9.837]
insertion_times = [0.0, 0.008, 0.05, 1.352, 5.053]
bubble_times = [0.0, 0.002, 0.151, 5.64, 22.935]
merge_times = [0.00, 0.0, 0.002, 0.006, 0.013]
quick_times = [0.0, 0.0, 0.001, 0.004, 0.011]
heap_times = [0.0, 0.0, 0.001, 0.008, 0.016]

# Criando o gráfico de linha
plt.figure(figsize=(10, 6))
plt.plot(sizes, selection_times, label="Selection Sort", marker='o')
plt.plot(sizes, insertion_times, label="Insertion Sort", marker='o')
plt.plot(sizes, bubble_times, label="Bubble Sort", marker='o')
plt.plot(sizes, merge_times, label="Merge Sort", marker='o')
plt.plot(sizes, quick_times, label="Quick Sort", marker='o')
plt.plot(sizes, heap_times, label="Heap Sort", marker='o')

# Configurações do gráfico
plt.xlabel("Tamanho do Array")
plt.ylabel("Tempo de Execução (segundos)")
plt.title("Comparação de Desempenho dos Algoritmos de Ordenação")
plt.xscale("log")
plt.yscale("log")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Exibindo o gráfico
plt.show()
