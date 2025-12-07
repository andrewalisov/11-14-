#include <stdio.h>
#include <math.h>
#include <float.h>
#include<locale.h>

#define PI 3.14159265358979323846

double f(double x) {
    //  x < -π/6
    if (x < -PI / 6.0) {
        // Проверка 1: (x не должен быть 0)
        if (fabs(x) < 0.000000000001) {
            return NAN;  
        }
        // Проверка 2: тангенс не имеет решений  когда cos(x) = 0
        if (fabs(cos(x)) < 0.000000000001) {
            return NAN;  // Возвращаем "не число" (NaN)
        }
        // Если проверки пройдены, вычисляем tan(x)/x
        return tan(x) / x;
    }
    //   -pi/6 <= x < 2
    else if (x >= -PI / 6.0 && x < 2.0) {
        // Проверка: знаменатель не должен быть равен 0
        if (fabs(x + 3.0) < 0.000000000001) {
            return NAN;
        }
        return ((pow(x,2)) - 9.0) / (x + 3.0);
    }
    //  x >= 2
    else {
        double sum = 0.0;
        for (int n = 0; n <= 11; n++) {
            double numerator = pow(x, n);
            double denominator = sqrt((pow(n,3)) + 1.0);
            sum += numerator / denominator;
        }
        return sum;
    }
}

//  1: Вычисление значения функции в точке
void calculate_value() {
    double x;
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n'); // Очистка буфера
        return;
    }

    double result = f(x);
    if (isnan(result)) {
        printf("Ошибка: функция не определена в точке x = %lf\n", x);
    }
    else {
        printf("f(%lf) = %lf\n", x, result);
    }
}

//  2: Таблица значений на интервале
void print_table() {
    double start, end;
    int steps;

    printf("Введите начало интервала: ");
    if (scanf("%lf", &start) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Введите конец интервала: ");
    if (scanf("%lf", &end) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Введите количество шагов: ");
    if (scanf("%d", &steps) != 1 || steps <= 0) {
        printf("Ошибка: количество шагов должно быть положительным числом!\n");
        while (getchar() != '\n');
        return;
    }

    printf("\n x \t\t|\t f(x)\n");
    printf("--------------------------------\n");

    double step = (end - start) / steps;
    for (int i = 0; i <= steps; i++) {
        double x = start + i * step;
        double y = f(x);

        if (isnan(y)) {
            printf("%lf\t|\t не определена\n", x);
        }
        else {
            printf("%lf\t|\t %lf\n", x, y);
        }
    }
}

//  3: Поиск минимума и максимума на отрезке
void find_min_max() {
    double a, b;
    int steps;

    printf("Введите начало отрезка: ");
    if (scanf("%lf", &a) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Введите конец отрезка: ");
    if (scanf("%lf", &b) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Введите количество точек для поиска: ");
    if (scanf("%d", &steps) != 1 || steps <= 0) {
        printf("Ошибка: количество точек должно быть положительным числом!\n");
        while (getchar() != '\n');
        return;
    }

    double min_val = DBL_MAX;
    double max_val = -DBL_MAX;
    double min_x = a, max_x = a;
    int found_points = 0;

    double step = (b - a) / steps;
    for (int i = 0; i <= steps; i++) {
        double x = a + i * step;
        double y = f(x);

        if (!isnan(y)) {
            found_points++;
            if (y < min_val) {
                min_val = y;
                min_x = x;
            }
            if (y > max_val) {
                max_val = y;
                max_x = x;
            }
        }
    }

    if (found_points == 0) {
        printf("На отрезке [%lf, %lf] не найдено ни одной точки определения функции\n", a, b);
    }
    else {
        printf("Минимум: f(%lf) = %lf\n", min_x, min_val);
        printf("Максимум: f(%lf) = %lf\n", max_x, max_val);
    }
}
//  4: Поиск x такого, что f(x) ≈ Y
void find_x_by_y() {
    double target_y;
    double precision;

    printf("Введите значение Y: ");
    if (scanf("%lf", &target_y) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Введите точность поиска: ");
    if (scanf("%lf", &precision) != 1 || precision <= 0) {
        printf("Ошибка: точность должна быть положительным числом!\n");
        while (getchar() != '\n');
        return;
    }

    double start_x, end_x;
    printf("Введите начало интервала поиска: ");
    if (scanf("%lf", &start_x) != 1) {
        printf("Ошибка ввода начала интервала!\n");
        return;
    }

    printf("Введите конец интервала поиска: ");
    if (scanf("%lf", &end_x) != 1 || end_x <= start_x) {
        printf("Ошибка ввода конца интервала!\n");
        return;
    }

    double step;
    printf("Введите шаг поиска (рекомендуется 0.01-0.1): ");
    if (scanf("%lf", &step) != 1 || step <= 0) {
        printf("Ошибка ввода шага!\n");
        return;
    }

    printf("\nПоиск x, таких что f(x) ≈ %lf на [%lf, %lf]\n", target_y, start_x, end_x);
    printf("Точность: %lf, Шаг: %lf\n\n", precision, step);

    int solutions_found = 0;

    for (double x = start_x; x <= end_x; x += step) {
        double y = f(x);

        if (!isnan(y) && fabs(y - target_y) < precision) {
            solutions_found++;
            static double last_solution_x = -1e9;

            if (solutions_found == 1 || fabs(x - last_solution_x) > 3 * step) {
                printf("Решение %d: x ≈ %lf, f(x) = %lf\n", solutions_found, x, y);
                last_solution_x = x;
            }
        }
    }

    printf("\nИтого найдено решений: %d\n", solutions_found);


}
//  5: Вычисление производной в точке 
void calculate_derivative() {
    double x;
    double h = 1e-6; 

    printf("Введите точку x для вычисления производной: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return;
    }

    // Проверяем, определена ли функция в  точке x
    double y1 = f(x - h);
    double y2 = f(x + h);

    if (isnan(y1) || isnan(y2)) {
        printf("Ошибка: невозможно вычислить производную - функция не определена в окрестности точки x = %lf\n", x);
        return;
    }

    // Численная производная по центральной разностной схеме
    double derivative = (f(x + h) - f(x - h)) / (2.0 * h);

    printf("f'(%lf) ≈ %lf (вычислено численно)\n", x, derivative);
}

// Главное меню программы
void print_menu() {
    setlocale(LC_CTYPE, "RUS");
    printf("\n   МЕНЮ ПРОГРАММЫ АНАЛИЗА ФУНКЦИИ   \n");
    printf("1. Значение функции в точке\n");
    printf("2. Таблица значений на интервале\n");
    printf("3. Поиск минимума/максимума на отрезке\n");
    printf("4. Поиск x: f(x) ≈ Y\n");
    printf("5. Производная в точке\n");
    printf("0. Выход\n");
    printf("Выберите операцию: ");
}
// Главная функция программы
int main() {
    setlocale(LC_CTYPE, "RUS");
    int choice;

    printf("Программа анализа функции f(x)\n");
    printf("f(x) = {\n");
    printf(" tan(x)/x для x < -pi/6\n");
    printf(" (x²-9)/(x+3) для -pi/6 <= x < 2\n");
    printf(" Сумма ряда для x >= 2\n }\n");

    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: некорректный ввод!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            calculate_value();
            break;
        case 2:
            print_table();
            break;
        case 3:
            find_min_max();
            break;
        case 4:
            find_x_by_y();
            break;
        case 5:
            calculate_derivative();
            break;
        case 0:
            printf("Выход из программы...\n");
            break;
        default:
            printf("Ошибка: неверный выбор операции!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}