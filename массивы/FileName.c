#include <stdio.h>
#include <math.h>
#include <float.h>
#include <locale.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


double f(double x) {
    if (x < -M_PI / 6.0) {
       
        return tan(x);
    }
    else if (x < 2.0) {
        
        if (fabs(x + 3.0) < 1e-10) {
            return NAN; 
        }
        return (x * x - 9.0) / (x + 3.0);
    }
    else {
       
        double sum = 0.0;
        for (int n = 0; n <= 11; n++) {
            double denominator = sqrt(n * n * n + 1.0);
            if (denominator == 0) continue;
            sum += pow(x, n) / denominator;
        }
        return sum;
    }
}


void calculate_value() {
    double x;
    printf("Введите x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }

    double result = f(x);
    if (isnan(result)) {
        printf("f(%.2f) не определена\n", x);
    }
    else {
        printf("f(%.2f) = %.6f\n", x, result);
    }
}


void build_table() {
    double start, end, step;
    printf("Введите начало интервала: ");
    if (scanf("%lf", &start) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }
    printf("Введите конец интервала: ");
    if (scanf("%lf", &end) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }
    printf("Введите шаг: ");
    if (scanf("%lf", &step) != 1) {
        printf("Ошибка ввода!\n");
        return;
    }

    if (step <= 0) {
        printf("Шаг должен быть положительным!\n");
        return;
    }

    printf("\n| %-10s | %-15s |\n", "x", "f(x)");
    printf("|------------|-----------------|\n");

    for (double x = start; x <= end; x += step) {
        double result = f(x);
        if (isnan(result)) {
            printf("| %-10.2f | %-15s |\n", x, "не определена");
        }
        else {
            printf("| %-10.2f | %-15.6f |\n", x, result);
        }
    }
}


void find_extremum() {
    printf("Здесь будет поиск минимума/максимума\n");
 
}

void find_x_by_y() {
    printf("Здесь будет поиск X по Y\n");

}


void calculate_derivative() {
    printf("Здесь будет вычисление производной\n");

}

void print_menu() {
    printf("\n=== МЕНЮ ПРОГРАММЫ ===\n");
    printf("1. Значение функции в точке\n");
    printf("2. Таблица значений\n");
    printf("3. Поиск минимума/максимума\n");
    printf("4. Поиск X по Y\n");
    printf("5. Производная в точке\n");
    printf("6. Выход\n");
    printf("Выберите пункт: ");
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    int choice;

    printf("Программа анализа функции f(x)\n");
    printf("f(x) = {\n");
    printf("  tan(x),                   x < -π/6\n");
    printf("  (x² - 9)/(x + 3),        -π/6 ≤ x < 2\n");
    printf("  Σ(xⁿ/√(n³+1)), n=0..11,  x ≥ 2\n");
    printf("}\n");

    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n'); // Очистка буфера
            continue;
        }

        switch (choice) {
        case 1:
            calculate_value();
            break;
        case 2:
            build_table();
            break;
        case 3:
            find_extremum();
            break;
        case 4:
            find_x_by_y();
            break;
        case 5:
            calculate_derivative();
            break;
        case 6:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 6);

    return 0;
}