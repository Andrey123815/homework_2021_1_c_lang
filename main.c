#include <stdio.h>

#include "include/equation.h"


int main() {
    Coefficients equation = {};
    double x1 = 0, y1 = 0, x2 = 1, y2 = 1, x3 = 1, y3 = -1;

    if (get_coefficients(&x1, &y1, &x2, &y2, &x3, &y3, &equation) == 1) {
        printf("Equation: %3.2f * y^2 + %3.2f * y + %3.2f", equation.square_term, equation.linear_term, equation.free_term);
        return 0;
    }
    printf("Equation: %3.2f * x^2 + %3.2f * x + %3.2f", equation.square_term, equation.linear_term, equation.free_term);

    return 0;
}
