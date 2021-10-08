#include <stdio.h>
#include <math.h>

#include "../include/equation.h"


void get_square_term (Points_ratio *p, Coefficients *q) {
    double coef = p->delta_x32 / p->delta_x21;
    q->square_term = (p->delta_y32 - coef * p->delta_y21) / (p->delta_x32 * (p->sum_x32) - coef * p->delta_x21 * (p->sum_x21));
}


void get_linear_term (Points_ratio *p, Coefficients *q) {
    q->linear_term = (p->delta_y32 - q->square_term * p->delta_x32 * (p->sum_x32)) / (p->delta_x32) + 0;
}


void get_free_term (Points_ratio *p, Coefficients *q) {
    q->free_term = p->y1 - q->square_term * pow(p->x1, 2) - q->linear_term * p->x1;
}


void swap_coord(double *elem_1, double *elem_2) {
    double tmp = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = tmp;
}

void reverse_coord_system(Points_ratio *p) {
    swap_coord(&p->delta_x32, &p->delta_y32);
    swap_coord(&p->delta_x21, &p->delta_y21);
    swap_coord(&p->x1, &p->y1);
    p->sum_x32 = p->y3 + p->y2;
    p->sum_x21 = p->y2 + p->y1;
}


_Bool get_coefficients (const double *x1, const double *y1, const double *x2, const double *y2,
                        const double *x3, const double *y3, Coefficients *equation) {
    // Check input values on null
    if (!x1 || !x2 || !x3 || !y1 || !y2 || !y3) {
        return NULL;
    }

    // Check input values on equal
    if ((*x1 == *x2 && *y1 == *y2) || (*x1 == *x3 && *y1 == *y3) || (*x2 == *x3 && *y2 == *y3)) {
        return NULL;
    }

    // Initialization
    Points_ratio points = {.x1= *x1, .y1 = *y1, .y2 = *y2, .y3 = *y3, .delta_x32 = *x3 - *x2,
            .delta_y32 = *y3 - *y2, .delta_x21 = *x2 - *x1, .delta_y21 = *y2 - *y1,
            .sum_x32 = *x3 + *x2, .sum_x21 = *x2 + *x1};

    _Bool y_x_system = 0;

    // Calculation coefficients
    get_square_term(&points, equation);
    if (isnan(equation->square_term) == 0 && isfinite(equation->square_term) == 0) {
        reverse_coord_system(&points);
        get_square_term(&points, equation);
        y_x_system = 1;
    }
    get_linear_term(&points, equation);
    get_free_term(&points, equation);

    return y_x_system;
}
