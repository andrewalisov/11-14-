#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define N 10
void main()
{
	task3();
}
int task1()
{



    setlocale(LC_CTYPE, "RUS");
        float A[N];
        float sum = 0;
        int i;


        puts("Введите 10 чисел:");
        for (i = 0; i < N; i++) {
            printf("Число %d: ", i + 1);
            scanf("%f", &A[i]);
        }


        puts("\nРезультаты:");
        puts("Индекс | Исходное| Новое");


        for (i = 0; i < N; i++) {
            printf("%d | %.2f | %.2f\n", i, A[i], A[i] * 2);
        }


        for (i = 0; i < N; i++) {
            sum = sum + A[i];
        }


        printf("Среднее: %f\n", sum / N);

        return 0;
    

}
int task2() {
   
        
    setlocale(LC_CTYPE, "RUS"); 
    int n, i;

        puts("Введите количество чисел: ");
        scanf("%d", &n);

        int arr[100];

        
        printf("Введите %d чисел:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }


        int min = arr[0];
        for (i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }


        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += arr[i];
        }


        int sum_without = sum - min;


        float average = (float)sum_without / (n - 1);

        printf("Самое маленькое число: %d\n", min);
        printf("Среднее арифметическое без самого маленького числа: %.2f\n", average);

        return 0;
    
}

  