#include <stdio.h>

int main ()
{ /* main */

  /* Declaration section */
  // Constants for the number of the (x,y) points that will be inputted.

  const int number_of_points = 6;

  // Variables for the user input.
  
  /* The following variables will hold the values of the corresponding
     (x,y) values that will be used in the program */

  float first_x_value, first_y_value;   // (x,y) inputs for the first point.
  float second_x_value, second_y_value; // (x.y) inputs for the second point.
  float third_x_value, third_y_value;   // (x,y) inputs for the third point.
  float fourth_x_value, fourth_y_value; // (x.y) inputs for the fourth point.
  float fifth_x_value, fifth_y_value;   // (x,y) inputs for the fifth point.
  float sixth_x_value, sixth_y_value;   // (x,y) inputs for the sixth point.

  // Variables for calculations.

  float sum_of_x_values;          // The sum of all x inputs given.
  float sum_of_y_values;          // The sum of all y inputs given. 
  float sum_of_x_squared;         // The sum of all x inputs, each squared.
  float sum_of_product_of_xy;     /* The sum of the product results of corresponding x and y inputs. */
  float numerator_of_slope;       /* Calculate the numerator of the slope of the regression line. */
  float denominator_of_slope;     /* Calculate the denominator of the slope of the regression line. */
  float slope_of_regression_line; /* Calculate the slope of the regression line. */
  float y_intercept;              /* Calculate the Y-intercept of the regression line. */

  /* Greeting subsection */
  // Introduction and explanation to the user about the program.

  printf("\n\nWelcome!! This is  the Least Squares Regression Calculator.\n");
  printf("This program calculates the regression line "); 
  printf("for six (x,y) points.\n\n");

  /* Input subsection */
  // Prompting the user to input the x and y values for the fisrt point.

  printf("Enter the x,y values for the first point (separated by a space): ");
  
  // Inputting the x and y values for the first point.

  scanf("%f %f", &first_x_value, &first_y_value);

  // Prompting the user to input the x and y values for the second point.

  printf("Enter the x,y values for the second point (separated by a space): ");

  // Inputting the x and y values for the second point.

  scanf("%f %f", &second_x_value, &second_y_value);

  // Promptiing the user to input the x and y values for the third point.

  printf("Enter the x,y values for the third point (separated by a space): ");

  // Inputting the x and y values for the third point.

  scanf("%f %f", &third_x_value, &third_y_value);

  // prompting the user to input the x and y values for the fourth point.

  printf("Enter the x,y values for the fourth point (separated by a space): ");

  // Inputting the x and y values for the fourth point.

  scanf("%f %f", &fourth_x_value, &fourth_y_value);

  // Prompting the user to input the x and y values for the fifth point.

  printf("Enter the x,y values for the fifth point (separated by a space): ");
 
  // Inputting the x and y values for the fifth point.

  scanf("%f %f", &fifth_x_value, &fifth_y_value);
  
  // Prompting the user to input the x and y values for the sixth point.

  printf("Enter the x,y values for the sixth point (separated by a space): ");

  // Inputting the  and y values for the sixth point.

  scanf("%f %f", &sixth_x_value, &sixth_y_value);

  /* Calculation subsection */
  // Calculating the sum of all x inputs given.

  sum_of_x_values = first_x_value + second_x_value + third_x_value + fourth_x_value + fifth_x_value + sixth_x_value;
  
  // Calculating the sum of all y inputs given.

  sum_of_y_values = first_y_value + second_y_value + third_y_value + fourth_y_value + fifth_y_value + sixth_y_value;
 
  // Calculating the the sum all x inputs, each squared. 

  sum_of_x_squared = (first_x_value * first_x_value)+(second_x_value * second_x_value)+(third_x_value * third_x_value)+(fourth_x_value * fourth_x_value)+(fifth_x_value * fifth_x_value)+(sixth_x_value * sixth_x_value);

  // Calculating the sum of the product results of corresponding x,y inputs.

  sum_of_product_of_xy = (first_x_value * first_y_value)+(second_x_value * second_y_value)+(third_x_value * third_y_value)+(fourth_x_value * fourth_y_value)+(fifth_x_value * fifth_y_value)+(sixth_x_value * sixth_y_value);

  // Calculating the numerator of the slope of the regression line.

  numerator_of_slope = sum_of_product_of_xy - ((sum_of_x_values * sum_of_y_values)/number_of_points);
 
  // Calculating the denominator of the slope of the regression line.

  denominator_of_slope = sum_of_x_squared - ((sum_of_x_values * sum_of_x_values)/number_of_points);

  // Calculating the slope of the regression line.

  slope_of_regression_line = numerator_of_slope / denominator_of_slope;

  // Calculating the Y-intercept of the regression line.

  y_intercept = (sum_of_y_values - (slope_of_regression_line * sum_of_x_values))/number_of_points;

  /* Output subsection */
  // Outputting the number of points.
  
  printf("\nNumber of points: %d\n\n", number_of_points);

  // Outputting the first point.

  printf("First point: (%1.3f, %1.3f)\n", first_x_value, first_y_value);

  // Outputting the second point.

  printf("Second point: (%1.3f, %1.3f)\n", second_x_value, second_y_value);

  // Outputting the third point.

  printf("Third point: (%1.3f, %1.3f)\n", third_x_value, third_y_value);

  // Outputting the fourth point.

  printf("Fourth point: (%1.3f, %1.3f)\n", fourth_x_value, fourth_y_value); 

  // Outputting the fifth point.

  printf("Fifth point: (%1.3f, %1.3f)\n", fifth_x_value, fifth_y_value);

  // Outputting the sixth point.

  printf("Sixth point: (%1.3f, %1.3f)\n\n", sixth_x_value, sixth_y_value);

  // Outputting the equation of the regression line in thr forme of y = mx + b

  printf("The equation of the regression line: y = %1.3fx + %1.3f\n\n", slope_of_regression_line, y_intercept);



  return 0; 

}
