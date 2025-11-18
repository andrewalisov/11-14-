#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <locale.h>

#define N 1000  


double* full_elements(double* ptr_array, int n) {
    printf("Заполнение массива...\n");
    for (int i = 0; i < n; i++) {
        
        double x = 0.1 + i * (2.0 / (n - 1));  
        ptr_array[i] = pow(x, 2) + sin(5 * x);
    }
    return ptr_array;
}


int put_elements(double* ptr_array, int n) {
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.6f\n", i, ptr_array[i]);
    }
    return n;
}


double* calc_elements(double* ptr_array, int n) {
    printf("Обработка элементов массива...\n");

    double sum_positive = 0.0;
    double sum_negative = 0.0;
    int count_positive = 0;
    int count_negative = 0;

    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > 0) {
            sum_positive += ptr_array[i];
            count_positive++;
        }
        else if (ptr_array[i] < 0) {
            sum_negative += ptr_array[i];
            count_negative++;
        }
    }

    printf("Сумма положительных элементов: %.6f\n", sum_positive);
    printf("Сумма отрицательных элементов: %.6f\n", sum_negative);
    printf("Количество положительных элементов: %d\n", count_positive);
    printf("Количество отрицательных элементов: %d\n", count_negative);

    if (count_positive > 0) {
        printf("Среднее положительных: %.6f\n", sum_positive / count_positive);
    }

    return ptr_array;
}

// ЗАДАНИЕ 2.1: 
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// ЗАДАНИЕ 2.2: 
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < 1e-10) {  
            return i;
        }
    }
    return -1;  // элемент не найден
}

// ЗАДАНИЕ 3:
double find_max_in_interval(double* ptr_array, int n, ...) {
    va_list args;
    va_start(args, n);

    int K = va_arg(args, int);
    int M = va_arg(args, int);

    va_end(args);

    
    if (K < 0) K = 0;
    if (M >= n) M = n - 1;
    if (K > M) {
        int temp = K;
        K = M;
        M = temp;
    }

    double max_val = ptr_array[K];
    for (int i = K + 1; i <= M; i++) {
        if (ptr_array[i] > max_val) {
            max_val = ptr_array[i];
        }
    }

    return max_val;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    
    if (size <= 0 || size > N) {
        printf("Ошибка: размер должен быть от 1 до %d\n", N);
        return 1;
    }

    
    full_elements(array, size);
    put_elements(array, size);
    calc_elements(array, size);

    
    printf("\n=== ЗАДАНИЕ 2 ===\n");

    
    int begin, end;
    printf("Введите начальный индекс (begin): ");
    scanf("%d", &begin);
    printf("Введите конечный индекс (end): ");
    scanf("%d", &end);

    if (begin >= 0 && end < size && begin <= end) {
        double sum = sum_elements(array, begin, end);
        printf("Сумма элементов от array[%d] до array[%d] = %.6f\n", begin, end, sum);
    }
    else {
        printf("Некорректные индексы!\n");
    }

    
    double search_element;
    printf("Введите элемент для поиска: ");
    scanf("%lf", &search_element);

    int found_index = find_element(array, size, search_element);
    if (found_index != -1) {
        printf("Элемент %.6f найден по индексу %d\n", search_element, found_index);
    }
    else {
        printf("Элемент %.6f не найден в массиве\n", search_element);
    }

    
    printf("\n=== ЗАДАНИЕ 3 ===\n");
    int K, M;
    printf("Введите начальный индекс интервала K: ");
    scanf("%d", &K);
    printf("Введите конечный индекс интервала M: ");
    scanf("%d", &M);

    double max_in_interval = find_max_in_interval(array, size, K, M);
    printf("Максимальное значение в интервале [%d, %d] = %.6f\n", K, M, max_in_interval);

    return 0;
}