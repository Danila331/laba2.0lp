#include <stdio.h>
#include <math.h>
#include <assert.h>

double double_factorial(int n) {
    double res = 1;
    for (int k = n; k > 0; k -= 2) {
        res *= k;
    }
    return res;
};

double t(double num) {
    double sum1, sum2;
    sum1 = 0.0;
    sum2 = 0.0;

    for (int n = 0; n <= 10;  n++) {
        sum1 += pow(num, 2*n+1) / double_factorial(2*n + 1);
    };

    for (int n = 0; n <= 10; n++) {
        sum2 += pow(num, 2*n) / double_factorial(2*n);
    }
    return sum1/sum2;
}

void test_double_factorial() {
    assert(double_factorial(0) == 1);
    assert(double_factorial(1) == 1);
    assert(double_factorial(2) == 2);
    assert(double_factorial(5) == 15);
    assert(double_factorial(6) == 48);
    assert(double_factorial(9) == 945);
    printf("Тесты для double_factorial пройдены.\n");
}

void test_t() {
    assert(fabs(t(0) - 0.0) < 0.2);
    assert(fabs(t(0.5) - 0.583920) < 0.2);
    assert(fabs(t(1) - 0.687421) < 0.2);
    assert(fabs(t(0.25) - 0.544106) < 0.3);
    printf("Тесты для t пройдены.\n");
}

int main(void) {
    test_double_factorial();
    test_t();

    double result, y;
    int input_result;

    printf("Введите значение y: ");
    input_result = scanf("%lf", &y);

    if (input_result != 1) {
        printf("Ошибка: некорректный ввод. scanf вернул %d.\n", input_result);
        return 1;
    }

    result = (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(pow(y, 2) - 1));
    printf("Результат: %lf\n", result);

    return 0;
}
