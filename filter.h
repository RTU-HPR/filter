/**
 * @file filter.h
 * @author Marko
 * @brief Filters library include file.
 * @version 1.0
 * @date 2024-01-17
 *
 * @copyright Copyright (c) 2024
 */

#ifndef FILTER_H
#define FILTER_H

/**
 * @class LowPassFIR
 * @brief Represents a Low Pass Finite Impulse Response (FIR) filter.
 */
class LowPassFIR
{
private:
    unsigned char order;    /**< Order of the filter. */
    float *coefficients;    /**< Array of filter coefficients. */
    float *prevInputs;      /**< Array of previous input values for filtering. */

public:
    /**
     * @brief Constructor for LowPassFIR.
     * @param order The order of the filter.
     */
    LowPassFIR(unsigned char order);

    /**
     * @brief Destructor for LowPassFIR.
     */
    ~LowPassFIR();

    /**
     * @brief Set the coefficients for the filter.
     * @param input Array of filter coefficients.
     * @return A character indicating success (1) or failure (0).
     */
    char setCoefficients(float *input);

    /**
     * @brief Perform filtering on the input value.
     * @param input The input value to be filtered.
     * @return The filtered output value.
     */
    float performFiltering(float input);
};

#endif
