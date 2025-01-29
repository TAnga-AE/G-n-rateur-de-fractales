#include <stdio.h>
#include <stdlib.h>

void printPattern(int size) {
    for (int row = size - 1; row >= 0; row--) {
        for (int i = 0; i < row; i++)
            printf(" ");

        for (int x = 0; (x + row) < size; x++)
            printf((x & row) ? "  " : "* ");
        
        printf("\n");
    }
}

int main() {
    int size;
    
    while (1) {
        printf("Entrez la taille (ou -1 pour quitter) : ");
        scanf("%d", &size);
        
        if (size == -1) {
            break; // Sortir de la boucle si l'utilisateur entre -1
        } else if (size < 1) {
            printf("Veuillez entrer une taille valide (1 ou plus).\n");
            continue; // Demander à nouveau en cas de taille invalide
        }
        printPattern(size);
    }

    return 0;
} 




