# Trabalho Grafos - Grupo 1

## Compilação dos Exemplos

### Algoritmo de Alcance
g++ -std=c++11 alcance.cpp graph/*.cpp -o alcance

### Busca em Largura
g++ -std=c++11 bfs.cpp graph/*.cpp -o bfs

### Busca em Profundidade
g++ -std=c++11 dfs.cpp graph/*.cpp -o dfs

### Componentes Conectados
g++ -std=c++11 connected.cpp graph/*.cpp -o connected

### Ordenação Topológica
g++ -std=c++11 topological.cpp graph/*.cpp -o topological