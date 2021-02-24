#include <iostream>
#include <gtest/gtest.h>
#include "../calcFunctions.h"

using namespace std;

TEST(VectorInputsSuite, findArithmeticMean1)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 6, 10, 8, 9};

    vector<Student> input{newStudent};
    vector<Student> output = FindArithmeticMean(input);

    EXPECT_EQ(output[0].arithMeanGrade, 7) << "The arithmetic mean is not correct";
}

TEST(VectorInputsSuite, findArithmeticMean2)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 3, 10, 9};

    vector<Student> input{newStudent};
    vector<Student> output = FindArithmeticMean(input);

    EXPECT_EQ(output[0].arithMeanGrade, (17 / 3.0))<< "The arithmetic mean is not correct";
}

TEST(VectorInputsSuite, findMedian1)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 3, 10, 9};

    vector<Student> input{newStudent};
    vector<Student> output = FindMedian(input);

    EXPECT_EQ(output[0].medianGrade, 4) << "The arithmetic mean is not correct";
}

TEST(VectorInputsSuite, findMedian2)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 3, 3, 10, 9};

    vector<Student> input{newStudent};
    vector<Student> output = FindMedian(input);

    EXPECT_EQ(output[0].medianGrade, 3.5) << "The arithmetic mean is not correct";
}

TEST(VectorInputsSuite, FindFinalGrade1)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 3, 10, 9};

    vector<Student> input{newStudent};
    input = FindArithmeticMean(input);
    vector<Student> output = FindFinalGrade(input, true);
    double result = (17 / 3.0) * 0.4 + 0.6 * 9;

    EXPECT_EQ(output[0].finalGrade, result) << "The arithmetic mean is not correct";
}

TEST(VectorInputsSuite, FindFinalGrade2)
{
    Student newStudent;
    newStudent.grades = vector<int>{4, 3, 3, 10, 9};

    vector<Student> input{newStudent};
    input = FindMedian(input);
    vector<Student> output = FindFinalGrade(input, false);
    double result = 3.5 * 0.4 + 0.6 * 9;

    EXPECT_EQ(output[0].finalGrade, result) << "The arithmetic mean is not correct";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}