/**
 * @file filter.cpp
 * @author Marko
 * @brief Filters library source code.
 * @version 1.0
 * @date 2024-01-17
 *
 * @copyright Copyright (c) 2024
 */

#include "filter.h"
#include "Arduino.h"

#define CHECK_IS_NULL(A) (A == nullptr) ? true : false

/**
 * @brief Constructor for the LowPassFIR class.
 * @param order The order of the filter.
 */
LowPassFIR::LowPassFIR(unsigned char order) : order(order)
{
    coefficients = new float[order];
    prevInputs = new float[order];
    for (char i = 0; i < order; i++)
    {
        prevInputs[i] = 0.0f;
    }
}

/**
 * @brief Destructor for the LowPassFIR class.
 */
LowPassFIR::~LowPassFIR()
{
    delete[] coefficients;
    delete[] prevInputs;
}

/**
 * @brief Set the coefficients for the filter.
 * @param input Array of filter coefficients.
 * @return A character indicating success (0) or failure (-1).
 */
char LowPassFIR::setCoefficients(float *input)
{
    if (CHECK_IS_NULL(input))
        return -1;

    for (unsigned char i = 0; i < order; i++)
    {
        coefficients[i] = input[i];
    }

    return 0;
}

/**
 * @brief Perform filtering on the input value.
 * @param input The input value to be filtered.
 * @return The filtered output value.
 */
float LowPassFIR::performFiltering(float input)
{
    float output = 0.0f;

    for (unsigned char i = order; i > 0; i--)
    {
        prevInputs[i] = prevInputs[i - 1];
    }

    prevInputs[0] = input;

    for (unsigned char i = 0; i < order; i++)
    {
        output += prevInputs[i] * coefficients[i];
    }

    return output;
}
