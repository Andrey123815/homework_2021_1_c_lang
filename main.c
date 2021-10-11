#include <stdio.h>

#include "equation.h"


int main() {
    Coefficients equation;

    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

    int flag_get_coefficients = get_coefficients(&x1, &y1, &x2, &y2, &x3, &y3, &equation);
    print_coefficients(flag_get_coefficients, &equation);

    return 0;
}
