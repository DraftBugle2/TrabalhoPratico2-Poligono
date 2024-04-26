#include <stdio.h>
#include <stdlib.h>

// Definição da struct Ponto
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a area de um triangulo dados seus vertices A, B e C
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float det = (A.X * B.Y + A.Y * C.X + B.X * C.Y) - (C.X * B.Y + C.Y * A.X + B.X * A.Y);
    return abs(det) / 2.0;
}

int main() {
    FILE *poligonos;
    int numVertices;
    Ponto *vertices;
    float areaTotal = 0.0;

    // Abrir o poligonos
    poligonos = fopen("TrabalhoPratico2-Poligono.txt", "r");
    if (poligonos == NULL) {
        printf("Erro ao abrir o poligonos.\n");
        return 1;
    }

    // Ler o numero de vertices do poligono
    fscanf(poligonos, "%d", &numVertices);

    // Alocar memoria para armazenar os vertices
    vertices = (Ponto*)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Ler as coordenadas dos vertices do poligonos
    for (int i = 0; i < numVertices; i++) {
        fscanf(poligonos, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // Fechar o poligonos
    fclose(poligonos);

    // Calcular a area total dividindo o poligono em triangulos
    for (int i = 1; i < numVertices - 1; i++) {
        areaTotal += AreaTriangulo(vertices[0], vertices[i], vertices[i+1]);
    }

    // Exibir a area total do poligono
    printf("A area do poligono eh %.2f\n", areaTotal);

    // Liberar a memoria alocada
    free(vertices);

    return 0;
}
