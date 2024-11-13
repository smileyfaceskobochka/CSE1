#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define MAX_ITEMS 4

double curve(double x) {
    return 2 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 1;
}

double integrate(double a, double b, int n) {
    double width = (b - a) / n;
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * width;
        area += curve(x) * width;
    }
    return area;
}

double estimate_error(double a, double b, int n) {
    double width = (b - a) / n;
    double error = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * width;
        double derivative = 6 * pow(x, 2) + 4 * x + 3;
        error += fabs(derivative) * width * width / 2;
    }
    return error;
}

void print_menu(int highlight, double a, double b, int n) {
    const char *choices[MAX_ITEMS] = {
        "Ввести данные",
        "Вычислить площадь",
        "Найти Погрешность",
        "Завершить"
    };
    system("cls");
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (highlight == i) {
            printf("> %s (a: %lf, b: %lf, n: %d)\n", choices[i], a, b, n);
        } else {
            printf("%s\n", choices[i]);
        }
    }
}

int main() {
    int highlight = 0;
    int choice = -1;
    double a, b;
    int n;
    while (1) {
        print_menu(highlight, a, b, n);
        int c = _getch();
        // Скролл меню стрелками и выбор ентером
        switch (c) {
            case 224:
                switch (_getch()) {
                    case 72: // Стрелка вверх
                        highlight = (highlight == 0) ? MAX_ITEMS - 1 : highlight - 1;
                        break;
                    case 80: // Стрелка вниз
                        highlight = (highlight == MAX_ITEMS - 1) ? 0 : highlight + 1;
                        break;
                }
                break;
            case 13: // Enter
                choice = highlight;
                break;
            default:
                continue;
        }
        if (choice >= 0) {
            switch (choice) {
                case 0: // Ввести данные
                    printf("Введите пределы интегрирования (a b): ");
                    scanf("%lf %lf", &a, &b);
                    printf("Введите количество прямоугольников: ");
                    scanf("%d", &n);
                    if (n <= 0) {
                        printf("Количество прямоугольников должно быть положительным.\n");
                    }
                    printf("Нажмите любую клавишу, чтобы вернуться в меню...");
                    _getch();
                    break;

                case 1: // вычислить площадь
                    double area = integrate(a, b, n);
                    printf("------------------------------------------------\n");
                    printf("Площадь: %.6lf\n", area);
                    printf("Нажмите любую клавишу, чтобы вернуться в меню...");
                    _getch();
                    break;

                case 2: // Вычислить погрешность
                    double error = estimate_error(a, b, n);
                    printf("Оценка погрешности: %.6lf\n", error);
                    printf("Нажмите любую клавишу, чтобы вернуться в меню...");
                    _getch();
                    break;

                case 3: // Завершить
                    printf("Выход...\n");
                    return 0;
            }
            choice = -1; // Сброс выбора после выполнения действия, иначе 😡
        }
    }
    return 0;
}