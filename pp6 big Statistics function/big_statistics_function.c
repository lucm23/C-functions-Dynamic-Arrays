/*
 **************************************************************************
 *** Project #6:  Big statistics functions                              ***
 *** Program:     big_statistic_function                                ***
 *** Author:      Luc Thierry Mwizerwa (luc.thierry.mwizerwa-1@ou.edu   *** 
 *** Class:       CS 1313 010 Computer Programming, Fall 2023           ***
 *** Lab:         Sec 012 Fridays 10:30am                               ***
 *** Description: Calculating the regression line of the inputed        ***
 ***              lists of elements by calling functions.               ***
 ***                                                                    ***
 **************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

int main() { /* main */
    
    
    /* DECLARATION SUBSECTION */
    
    
    /* Declartion of named constants. */
    
    const float initial_sum = 0.0; /* keeps the initial value of every variable that keeps the sum. */
    const int minimum_number_of_elements = 0; /* the amount of elements that can be put in an array. */
    const int first_element = 0; /* keeps the index of the first element in a given array. */
    const int program_success_code = 0; /* a program succes code that is returned when the program is succesuccessfully completed. */
    const int program_failure_code = -1; /* a progrm failure code that is returned when the program fails. */
    
    /* Declartion of varibales. */
    
    /* Array variables. */
    
    float* list1_input_value = (float*)NULL; /*Pointer to the first list of elemnts. */
    float* list2_input_value = (float*)NULL; /* Pointer to the second list of elements. */
    
    /* Scalar variables. */
    
    float list1_input_value_sum; /* keeps the sum of all elements in the first list. */
    float list2_input_value_sum; /* keeps the sum of all elements in the second list. */
    float sum_squares_of_list1;  /* keeps the sum of the squares of elements in the first list. */
    float sum_of_pairwise_products; /* keeps the pairwise product of the elements from both lists. */ 
    float slope_of_regression_line; /* keeps the slope of the regression line. */
    float y_intercept; /* keeps the y intercept of the regression line. */
    int shared_length_of_elements; /* records the number of the elements that are going to be in a corresponding list. */
    int element; /* represents the index of every element in a given list. */
    
    /* Declartion of function prototypes. */
    
    float sum (float* list, int number_of_elements); /* returns the sum of elements in a lists. */
    float sum_of_squares(float* list, int number_of_elements);/* returns the sum of squares of the elements in a list. */
    float sum_of_products(float* list1, float* list2, int number_of_elements); /* returns the pairwise product of elements from both lists. */
    float linear_regression_slope(float sum1, float sum2, float sum_of_products, float sum_of_squaresl1, int shared_length); /* returns the slope. */
    float linear_regression_intercept(float sum1, float sum2, float slope, int shared_length); /* returns the y_intercept of the reggresiion line. */

    
    /* INPUT SUBSECTION */
    
    
    /* Inputting shared length of the arrays from the file */
    
    scanf("%d", &shared_length_of_elements);

    /* 
     * Idiotproofing the shared length  
     */
    
    if (shared_length_of_elements <= minimum_number_of_elements) {
        /* 
         * Output the error message for invalid length of the lists. 
         */
        printf("\n\nError: The shared length must be a positive integer range.\n");
        printf("And can't calculate the regression line of %d values.\n", shared_length_of_elements); 
        /* 
         *Exits the program 
         */
        exit(program_failure_code);
    }   /* if (shared_length_of_elements < minimum_number_of_elements) */

    /* Allocating memory for arrays */
    
    list1_input_value = (float*)malloc(shared_length_of_elements * sizeof(float));
    list2_input_value = (float*)malloc(shared_length_of_elements * sizeof(float));

    /*
     *Idiotproofing the array memory allocation 
     */
    
    if (list1_input_value == (float*)NULL) {
        /* 
         * Output the error message for invalid allocation of the first list. 
         */
       printf("\n\nERROR: Can't allocate the 1st float array\n");
       printf("of length %d.\n", shared_length_of_elements);
       /* 
        * exits the program. 
        */
       exit  (program_failure_code);
    }  /* if (list1_input_value == (float*)NULL) */
    
    if (list2_input_value == (float*)NULL) {
        /* 
         * Output the error message for invalid allocation of the second list. 
         */
       printf("\n\nERROR: Can't allocate the 2nd float array\n");
       printf("of length %d.\n", shared_length_of_elements);
        /* 
         * Exits the program 
         */
       exit  (program_failure_code);
    } /* if (list2_input_value == (float*)NULL) */
    

    /* Inputting values for the two lists of elements */
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        /* 
         * Inputting the values of each list accordingly. 
         */
        scanf("%f %f", &list1_input_value[element],&list2_input_value[element]);
    } /* for element */

    
    /* CALCULATION SUBSECTION */   
    
    
    /* 
     * Function calls, for calculating the the sum of 
     * the first list’s values
     */ 
    
    list1_input_value_sum = sum (list1_input_value, shared_length_of_elements);
    
    /* 
     * Function calls, for calculating the sum of 
     * the second list’s values 
     */ 
    
    list2_input_value_sum = sum (list2_input_value, shared_length_of_elements);
    
   
    
    /* 
     * Calculating the sum of squares of the first list’s values 
     */ 
    
    sum_squares_of_list1 = sum_of_squares (list1_input_value, shared_length_of_elements);
    
    
    
    /* 
     * Calculating the sum of the pairwise products of the 
     * corresponding values of the first and the second list
     */ 
    
    sum_of_pairwise_products = sum_of_products (list1_input_value, list2_input_value, shared_length_of_elements);
    
    

    /* Calculate regression line parameters: slope and the y_intercept */
    
    slope_of_regression_line = linear_regression_slope (list1_input_value_sum, list2_input_value_sum, sum_of_pairwise_products, sum_squares_of_list1, shared_length_of_elements);
    y_intercept = linear_regression_intercept (list1_input_value_sum, list2_input_value_sum, slope_of_regression_line, shared_length_of_elements);


    /* OUTPUT SUBSECTION */
    
    
    /* Outputting statistics */
    
    printf("\n\nThe shared length of the lists: %d\n", shared_length_of_elements);
    printf("\nAll of the values of the first list:\n");
    for (element = first_element; element < shared_length_of_elements; element++) {
        /* 
         * Output the values of the first list. 
         */
        printf("                                    %10.5f\n", list1_input_value[element]);
    } /* for element */
    printf("\n\nAll of the values of the second list:\n");
    for (element = first_element; element < shared_length_of_elements; element++) {
        /* 
         * Output the values of the second list. 
         */
        printf("                                    %10.5f\n", list2_input_value[element]);
    } /* for element */
    printf("\n\nRegression Line: y = %10.5fx + %10.5f\n\n", slope_of_regression_line, y_intercept);

    /* Deallocating arrays */
    
    free(list1_input_value);
    list1_input_value = (float*)NULL;
    free(list2_input_value);
    list2_input_value = (float*)NULL;
    
    return program_success_code;

} /* main */



/*
 ***************************************************************
 *** Function: sum                                           ***
 *** Return Type: float                                      ***
 *** Return Value: sum_value                                 ***
 *** Arguments:                                              ***
 ***    array: The array of values                           ***
 ***    number_of_elements: the length of the array          ***
 *** Description: Calculates the sum of a float array by     ***
 ***    summing the elements.                                ***
 ***************************************************************
 */


float sum (float* list, int number_of_elements) { /* sum */


    /* DECLARATION SUBSECTION */
    
    /* Named Constants. */
    
    const float initial_sum = 0.0; /* keeps the initial sum of every addition Variables. */
    const int minimum_number_of_elements = 1; /* the least amount of elements a list can have. */
    const int program_failure_code = -1; /* a program failure code, for exiting the program. */
    const int first_element = 0; /* represents the index of the first element in a list. */
    
    
    /* Scalar Variables. */
    
    float sum_value; /* keeps the sum of all elements in a list added up. */
    int element; /* represents the index of every element in the list. */
    
    
    /* IDIOTPROOFING SUBSECTION */
    
    /* Idiotproofing the length of the list. */
    
    if (number_of_elements < minimum_number_of_elements) {
        /* 
         * Output error message for invalid length of the array. 
         */
        printf("ERROR: can't have an array of length %d:\n", number_of_elements);
        printf(" it must have at least %d element.\n", minimum_number_of_elements);
        /* 
         * Exits the program 
         */
        exit(program_failure_code);
    } /* if (number_of_elements < ...) */
    
    
    /* Idiotproofing the allocation
    of the second list of elements. */
    
    if (list == (float*)NULL) {
        /* 
         * Output error message for invalid arry allocation.
         */
        printf("ERROR: can't calculate the sum of ");
        printf("a nonexistent array.\n");
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (array == (float*)NULL) */
    
    
    /* CALCULATION SUBSECTION */
    
    /* Calculating the sum of elements. */
    
    sum_value = initial_sum;
    for (element = first_element; element < number_of_elements; element++) {
        /* 
         * returns the sum of all elements in a single list added up. 
         */
        sum_value += list[element];
    } /* for element */
    
    return sum_value;

} /* sum */



/*
 ***************************************************************
 *** Function: sum_of_squares                                ***
 *** Return Type: float                                      ***
 *** Return Value: sum_squares_value                         ***
 *** Arguments:                                              ***
 ***    array: The array of values                           ***
 ***    number_of_elements: the length of the array          ***
 *** Description: Calculates the sum of squares of a float   ***
 ***    array by adding up the squares of the elements.      ***
 ***************************************************************
 */

float sum_of_squares (float* list, int number_of_elements) { /* sum_of_squares */

    /* DECLARATION SUBSECTION */
    
    /* Named Constants. */

    const float initial_sum = 0.0; /* keeps the initial sum of every addition Variables. */
    const int minimum_number_of_elements = 1; /* the least amount of elements a list can have. */
    const int program_failure_code = -1; /* a program failure code, for exiting the program. */
    
    /* Scalar Variables. */
    
    float sum_squares_value; /* keeps the sum of all squares of each and every element in a list. */
    int element; /* represents the index of every element in the list. */
    
    
    /* IDIOTPROOFING SUBSECTION */
    
    /* Idiotproofing the length of the list. */

    if (number_of_elements < minimum_number_of_elements) {
        /* 
         * Output error message for invalid number of element. 
         */
        printf("ERROR: can't have an array of length %d:\n", number_of_elements);
        printf(" it must have at least %d element.\n", minimum_number_of_elements);
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (number_of_elements < ...) */

    /* Idiotproofing the allocation
    of the second list of elements. */

    if (list == (float*)NULL) {
        /* 
         * Output error message for invalid array allocation. 
         */
        printf("ERROR: can't calculate the sum of squares of ");
        printf("a nonexistent array.\n");
        /* 
         * exits the program. 
         */
        exit(program_failure_code);
    } /* if (list == (float*)NULL) */
    
    
    /* CALCULATION SUBSECTION */

    /* Calculating the sum of squares. */

    sum_squares_value = initial_sum;
    for (element = 0; element < number_of_elements; element++) {
        /* 
         * returns the sum of squares of corresponding elements in a list. 
         */
        sum_squares_value += (list[element] * list[element]);
    } /* for element */

    return sum_squares_value;

} /* sum_of_squares */



/*
 ***************************************************************
 *** Function: sum_of_products                               ***
 *** Return Type: float                                      ***
 *** Return Value: sum_products_value                        ***
 *** Arguments:                                              ***
 ***    array1: The first array of values                    ***
 ***    array2: The second array of values                   ***
 ***    number_of_elements: the length of the arrays         ***
 *** Description: Calculates the sum of products of two float***
 *** arrays by adding the pairwise products.                 ***
 ***************************************************************
 */

float sum_of_products (float* list1, float *list2, int number_of_elements) { /* sum_of_products */

    /* DECLARATION SUBSECTION */
    
    /* Named Constants. */

    const float initial_sum = 0.0; /* keeps the initial sum of every addition Variables. */
    const int minimum_number_of_elements = 1; /* the least amount of elements a list can have. */
    const int program_failure_code = -1; /* a program failure code, for exiting the program. */
    
    /* Scalar Variables. */
    
    float sum_products_value; /* keeps the sum of the pairwise products of elements in both lists. */
    int element; /* represents the index of every element in the list. */
    
    
    /* IDIOTPROOFING SUBSECTION */
    
    /* Idiotproofing the length of the lists. */

    if (number_of_elements < minimum_number_of_elements) {
        /* 
         * Output the error message for invalid number of elements. 
         */
        printf("ERROR: can't have arrays of length %d:\n", number_of_elements);
        printf(" they must have at least %d element.\n", minimum_number_of_elements);
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (number_of_elements < ...) */

    /* Idiotproofing the allocation
    of the second list of elements. */

    if (list1 == (float*)NULL || list2 == (float*)NULL) {
        /* 
         * Output error message for invalid allocation of list1 or list2 or both. 
         */
        printf("ERROR: can't calculate the sum of products of ");
        printf("nonexistent arrays.\n");
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (list1 == (float*)NULL || list2 == (float*)NULL) */

    
    /* CALCULATION SUBSECTION */
    
    /* Calculating the sum of products. */

    sum_products_value = initial_sum;
    for (element = 0; element < number_of_elements; element++) {
        /* 
         * returs the pairwise product of elements. 
         */
        sum_products_value += (list1[element] * list2[element]);
    } /* for element */

    return sum_products_value;

} /* sum_of_products */



/*
 ***************************************************************
 *** Function: linear_regression_slope                       ***
 *** Return Type: float                                      ***
 *** Return Value: slope                                     ***
 *** Arguments:                                              ***
 ***    sum_of_products: the sum of products of two arrays   ***
 ***    sum1: the sum of the first array                     ***
 ***    sum2: the sum of the second array                    ***
 ***    sum_of_squaresl1: the sum of squares of the first    ***
 ***                      array                              ***
 ***    shared_length: the length of the arrays              ***
 *** Description: Calculates the linear regression slope by  ***
 *** using the given sums and shared length.                 ***
 ***************************************************************
 */


float linear_regression_slope (float sum1, float sum2, float sum_of_products, float sum_of_squaresl1, int shared_length) { /* linear_regression_slope */

    /* DECLARATION SUBSECTION */
    
    /* Named Constants. */

    const int minimum_shared_length = 1; /* the least amount of elements a list can have. */
    const int program_failure_code = -1; /* a program failure code, for exiting the program. */
    
    /* Scalar Variables. */
    
    float numerator; /* the numerator (change in list 2 elements basically) for Calculating slope. */
    float denominator; /* the numerator (change in list 2 elements basically) for Calculating slope. */
    float slope; /* the slope of the regression line. */
    

    /* IDIOTPROOFING SUBSECTION */
    
    /* Idiotproofing the shared length. */

    if (shared_length < minimum_shared_length) {
        /* 
         * Output the error message for invalid length of the list. 
         */
        printf("ERROR: can't calculate the linear regression slope ");
        printf("with a shared length of %d:\n", shared_length);
        printf(" it must be at least %d.\n", minimum_shared_length);
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (shared_length < ...) */
    
    
    /* CALCULATION SUBSECTION */

    /* Calculating the slope. */
    
    numerator = sum_of_products - ((sum1 * sum2)/shared_length);
    denominator = sum_of_squaresl1 - ((sum1 * sum1)/shared_length);
    slope = numerator / denominator;

    return slope;

} /* linear_regression_slope */



/*
 ***************************************************************
 *** Function: linear_regression_intercept                   ***
 *** Return Type: float                                      ***
 *** Return Value: intercept                                 ***
 *** Arguments:                                              ***
 ***    sum1: the sum of the first array                     ***
 ***    sum2: the sum of the second array                    ***
 ***    slope: the linear regression slope                   ***
 ***    shared_length: the length of the arrays              ***
 *** Description: Calculates the linear regression intercept ***
 *** by using the provided sums, slope, and shared length.   ***
 ***************************************************************
 */
 

float linear_regression_intercept (float sum1, float sum2, float slope, int shared_length) { /* linear_regression_intercept */

    /* DECLARATION SUBSECTION */
    
    /* Named Constants. */ 

    const int minimum_shared_length = 1; /* the least amount of elements a list can have. */
    const int program_failure_code = -1; /* a program failure code, for exiting the program. */
    
    /* Scalar Variables. */
    
    float intercept; /* the y intercept of the regression line. */
    
    
    /* IDIOTPROOFING SUBSECTION */
    
    /* Idiotproofing the shared length. */

    if (shared_length < minimum_shared_length) {
        /* 
         * Output the error message for invalid shared length of lists. 
         */
        printf("ERROR: can't calculate the linear regression intercept ");
        printf("with a shared length of %d:\n", shared_length);
        printf(" it must be at least %d.\n", minimum_shared_length);
        /* 
         * Exits the program. 
         */
        exit(program_failure_code);
    } /* if (shared_length < ...) */
    
    
    /* CALCULATION SUBSECTION */

    /* Calculating the intercept. */

    intercept = (sum2 - (slope * sum1))/ shared_length;
    
    return intercept;
    
} /* linear_regression_intercept */



