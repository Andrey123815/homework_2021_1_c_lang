#include <gtest/gtest.h>
#include <cstring>

extern "C" {
    #include "equation.h"
}


TEST(EQUATION_TEST, Null_Case) {
    double x1, x2, y2, x3, y3;
    Coefficients equation = {};
    EXPECT_EQ(get_coefficients(&x1, NULL, &x2, &y2, &x3, &y3, &equation), -1);
}

TEST(EQUATION_TEST, Sample_Points) {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 1, y3 = -6;

    Coefficients equation = {};
    EXPECT_EQ(get_coefficients(&x1, &y1, &x2, &y2, &x3, &y3, &equation), -1);
}


TEST(EQUATION_TEST, Simple_Points) {
    double x1 = 0, y1 = 0, x2 = 1, y2 = 1, x3 = -1, y3 = 1;
    Coefficients equation = {}, eq_tst = {1, 0, 0};
    get_coefficients(&x1, &y1, &x2, &y2, &x3, &y3, &equation);
    EXPECT_EQ(equation.square_term, eq_tst.square_term);
    EXPECT_EQ(equation.linear_term, eq_tst.linear_term);
    EXPECT_EQ(equation.free_term, eq_tst.free_term);
    EXPECT_EQ(equation.y_x_system, eq_tst.y_x_system);
}


TEST(EQUATION_TEST, Reverse_SC) {
    double x1 = 0, y1 = 0, x2 = 1, y2 = 1, x3 = 1, y3 = -1;

    Coefficients equation = {}, eq_tst = {1, 0, 0, 1};
    get_coefficients(&x1, &y1, &x2, &y2, &x3, &y3, &equation);
    EXPECT_EQ(equation.square_term, eq_tst.square_term);
    EXPECT_EQ(equation.linear_term, eq_tst.linear_term);
    EXPECT_EQ(equation.free_term, eq_tst.free_term);
    EXPECT_EQ(equation.y_x_system, eq_tst.y_x_system);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}