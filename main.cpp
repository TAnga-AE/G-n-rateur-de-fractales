#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int WIDTH = 119;
const int HEIGHT = 119;

void drawLine(char grille[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    double xIncrement = static_cast<double>(dx) / steps;
    double yIncrement = static_cast<double>(dy) / steps;

    double x = x1;
    double y = y1;

    for (int i = 0; i <= steps; ++i) {
        if (static_cast<int>(y) >= 0 && static_cast<int>(y) < HEIGHT &&
            static_cast<int>(x) >= 0 && static_cast<int>(x) < WIDTH) {
            grille[static_cast<int>(y)][static_cast<int>(x)] = (i == 0 || i == steps) ? '@' : '*';
        }
        x += xIncrement;
        y += yIncrement;
    }
}
void drawFractalTree(char grille[HEIGHT][WIDTH], int x, int y, double angle, int depth) {
    if (depth == 0) return;

    int length = 10; // Longueur de la branche
    int x2 = x + static_cast<int>(length * cos(angle));
    int y2 = y - static_cast<int>(length * sin(angle));

    // dessiner une ligne entre deux points
    drawLine(grille, x, y, x2, y2);

    // dessin de l'arbre fractal grâce à la recursivité
    drawFractalTree(grille, x2, y2, angle - M_PI / 6, depth - 1);
    drawFractalTree(grille, x2, y2, angle + M_PI / 6, depth - 1);
}


void clearGrille(char grille[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grille[i][j] = ' ';
        }
    }
}

int main() {
    int choix;
    char grille[HEIGHT][WIDTH];

    cout << "Choisissez une fractale:\n";
    cout << "1. Arbre fractal\n";
    cout << "2. Tapis de Sierpinski\n";
    cout << "Votre choix: ";
    cin >> choix;
 if (choix == 1) {
        int depth;
        while (true) {
            clearGrille(grille);
            cout << "Entrez la profondeur de l'arbre (ou -1 pour quitter) : ";
            cin >> depth;

            if (depth == -1) break;

            int x = WIDTH / 2;
            int y = HEIGHT - 1;
            drawFractalTree(grille, x, y, M_PI / 2, depth);

            // Display the fractal
            for (int i = 0; i < HEIGHT; ++i) {
                for (int j = 0; j < WIDTH; ++j) {
                    cout << grille[i][j];
                }
                cout << endl;
            }
        }
 }
    return 0;
}
