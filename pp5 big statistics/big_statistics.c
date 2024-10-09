#include <stdio.h>
#include <stdlib.h>

int main() { /* main */
    
    
    /* DECLARATION SUBSECTION */
    
    
    /* declartion of variables, named constants and arrays. */
    
    const float initial_sum = 0.0;
    const int minimum_number_of_elements = 0;
    const int first_element = 0;
    const int program_success_code = 0;
    const int program_failure_code = -1;
    float* list1_input_value = (float*)NULL;
    float* list2_input_value = (float*)NULL;
    float list1_input_value_sum;
    float list2_input_value_sum;
    float sum_squares_of_list1;
    float sum_of_pairwise_products;
    float numerator_of_slope;
    float denominator_of_slope;
    float slope_of_regression_line;
    float y_intercept;
    int shared_length_of_elements; 
    int element;
    
    
    /* INPUT SUBSECTION */
    
    
    /* Inputting shared length of the arrays from the file */
    
    scanf("%d", &shared_length_of_elements);

    /* 
     *Idiotproofing the shared length  
     */
    
    if (shared_length_of_elements <= minimum_number_of_elements) {
        printf("\n\nError: The shared length must be a positive integer range.\n");
        printf("And can't calculate the regression line  of %d values.\n", shared_length_of_elements); 
        exit(program_failure_code);
    }   /* if (shared_length_of_elements <= minimum_number_of_elements) */

    /* Allocating memory for arrays */
    
    list1_input_value = (float*)malloc(shared_length_of_elements * sizeof(float));
    list2_input_value = (float*)malloc(shared_length_of_elements * sizeof(float));

    /*
     *Idiotproofing the array memory allocation 
     */
    
    if (list1_input_value == (float*)NULL) {
       printf("\n\nERROR: Can't allocate the 1st float array\n");
       printf("of length %d.\n", shared_length_of_elements);
       exit  (program_failure_code);
    }  /* if (list1_input_value == (float*)NULL) */
    
    if (list2_input_value == (float*)NULL) {
       printf("\n\nERROR: Can't allocate the 2nd float array\n");
       printf("of length %d.\n", shared_length_of_elements);
       exit  (program_failure_code);
    } /* if (list2_input_value == (float*)NULL) */
    

    /* Inputting values for the two lists of elements */
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        scanf("%f %f", &list1_input_value[element],&list2_input_value[element]);
    } /* for element */

    
    /* CALCULATION SUBSECTION */   
    
    
    /* 
     *Calculating the the sum of the first list’s values
     */ 
    
    list1_input_value_sum = initial_sum;
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        /*
         * Increase the first list’s sum by the current element of
         * the first list.
         */
        list1_input_value_sum += list1_input_value[element];
    } /* for element */
    
    /* 
     * Calculating the sum of the second list’s values 
     */ 
    
    list2_input_value_sum = initial_sum;
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        /*
         * Increase the second list’s sum by the current element of
         * the second list.
         */
        list2_input_value_sum += list2_input_value[element];
    } /* for element */
    
    /* 
     * Calculating the sum of squares of the first list’s values 
     */ 
    
    sum_squares_of_list1 = initial_sum;
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        /*
         * Increase the first list’s sum of squares by the current element of
         * the first list.
         */
        sum_squares_of_list1 += list1_input_value[element] * list1_input_value[element];
    } /* for element */
    
    /* 
     * Calculating the sum of the pairwise products of the corresponding values of the first and the second list
     */ 
    
    sum_of_pairwise_products = initial_sum;
    
    for (element = first_element; element < shared_length_of_elements; element++) {
        /*
         * Increase the sum of the pairwise products of the corresponding values of the first and the second list
         * by the current elements
         */
        sum_of_pairwise_products += list1_input_value[element] * list2_input_value[element];
    } /* for element */

    /* Calculate regression line parameters */
    
    numerator_of_slope = sum_of_pairwise_products - ((list1_input_value_sum * list2_input_value_sum)/shared_length_of_elements);
    denominator_of_slope = sum_squares_of_list1 - ((list1_input_value_sum * list1_input_value_sum)/shared_length_of_elements);
    slope_of_regression_line = numerator_of_slope / denominator_of_slope;
    y_intercept= (list2_input_value_sum - (slope_of_regression_line * list1_input_value_sum))/ shared_length_of_elements;


    /* OUTPUT SUBSECTION */
    
    
    /* Outputting statistics */
    
    printf("\n\nThe shared length of the lists: %d\n", shared_length_of_elements);
    printf("\nAll of the values of the first list:\n");
    for (element = first_element; element < shared_length_of_elements; element++) {
        printf("                                    %10.5f\n", list1_input_value[element]);
    }
    printf("\n\nAll of the values of the second list:\n");
    for (element = first_element; element < shared_length_of_elements; element++) {
        printf("                                    %10.5f\n", list2_input_value[element]);
    }
    printf("\n\nRegression Line: y = %10.5fx + %10.5f\n\n", slope_of_regression_line, y_intercept);

    /* Deallocating arrays */
    
    free(list1_input_value);
    list1_input_value = (float*)NULL;
    free(list2_input_value);
    list2_input_value = (float*)NULL;
    
    return program_success_code;

} /* main */



