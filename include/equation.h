#ifndef INC_1SEM_C_CPP_EQUATION_H
#define INC_1SEM_C_CPP_EQUATION_H


typedef struct {
    double square_term;
    double linear_term;
    double free_term;
    int y_x_system;
} Coefficients;


typedef struct {
    double x1;
    double y1;
    double y2;
    double y3;
    double delta_x32;
    double delta_y32;
    double delta_x21;
    double delta_y21;
    double sum_x32;
    double sum_x21;
} Points_ratio;


void get_linear_term (Points_ratio *p, Coefficients *q);
void get_square_term (Points_ratio *p, Coefficients *q);
void get_free_term (Points_ratio *p, Coefficients *q);
int get_coefficients (double *x1, double *y1, double *x2, double *y2,
                                double *x3, double *y3, Coefficients *equation);

#endif //INC_1SEM_C_CPP_EQUATION_H
