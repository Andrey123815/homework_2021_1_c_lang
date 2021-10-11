#include <gtest/gtest.h>
#include <cstring>

extern "C" {
    #include "equation.h"
}


TEST(EQUATION_TEST, NULL_CASE) {
    double first_point_x, second_point_x, second_point_y, third_point_x, third_point_y;
    Coefficients equation = {};

    EXPECT_EQ(get_coefficients(&first_point_x, NULL, &second_point_x, &second_point_y,
                                            &third_point_x, &third_point_y, &equation), -1);
}


TEST(EQUATION_TEST, SAMPLE_POINTS) {
    double first_point_x = 0, first_point_y = 0, second_point_x = 0, second_point_y = 0,
                                                        third_point_x = 1, third_point_y = -6;
    Coefficients equation = {};

    EXPECT_EQ(get_coefficients(&first_point_x, &first_point_y, &second_point_x,
                               &second_point_y, &third_point_x, &third_point_y, &equation), -1);
}


TEST(EQUATION_TEST, SIMPLE_POINTS) {
    double first_point_x = 0, first_point_y = 0, second_point_x = 1, second_point_y = 1,
                                                        third_point_x = -1, third_point_y = 1;
    Coefficients equation = {}, eq_tst = {1, 0, 0};
    get_coefficients(&first_point_x, &first_point_y, &second_point_x, &second_point_y,
                                                    &third_point_x, &third_point_y, &equation);

    EXPECT_EQ(equation.square_term, eq_tst.square_term);
    EXPECT_EQ(equation.linear_term, eq_tst.linear_term);
    EXPECT_EQ(equation.free_term, eq_tst.free_term);
    EXPECT_EQ(equation.y_x_system, eq_tst.y_x_system);
}


TEST(EQUATION_TEST, REVERSE_SC) {
    double first_point_x = 0, first_point_y = 0, second_point_x = 1, second_point_y = 1,
                                                            third_point_x = 1, third_point_y = -1;

    Coefficients equation = {}, eq_tst = {1, 0, 0, 1};
    get_coefficients(&first_point_x, &first_point_y, &second_point_x, &second_point_y,
                                                        &third_point_x, &third_point_y, &equation);

    EXPECT_EQ(equation.square_term, eq_tst.square_term);
    EXPECT_EQ(equation.linear_term, eq_tst.linear_term);
    EXPECT_EQ(equation.free_term, eq_tst.free_term);
    EXPECT_EQ(equation.y_x_system, eq_tst.y_x_system);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}