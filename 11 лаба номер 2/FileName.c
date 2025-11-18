#include <stdio.h>
#include <math.h>  
#include <locale.h>

float calculate(float x) {
    float result;
    result = x * x + sin(5 * x);
    return result;
}


int main() {
    setlocale(LC_CTYPE, "RUS");
    float arr[100];


    float sum_positive = 0;
    float sum_negative = 0;

    int count_positive = 0;
    int count_negative = 0;

    int i;

    for (i = 0; i < 100; i++) {
        float x = 0.1 + i * (2.0 / 99.0);


        arr[i] = calculate(x);
    }

    for (i = 0; i < 100; i++) {
        if (arr[i] > 0) {
            sum_positive = sum_positive + arr[i];
            count_positive = count_positive + 1;
        }
        else if (arr[i] < 0) {
            sum_negative = sum_negative + arr[i];
            count_negative = count_negative + 1;
        }
    }

    float average;
    if (count_positive > 0) {
        average = sum_positive / count_positive;
    }
    else {
        average = 0;
    }
    printf("Имя массива: arr ");
    printf("Сумма положительных: %.3f ", sum_positive);
    printf("Сумма отрицательных: %.3f ", sum_negative);
    printf("Количество положительных: %d ", count_positive);
    printf("Количество отрицательных: %d ", count_negative);
    printf("Среднее положительных: %.3f ", average);


    return 0;
}