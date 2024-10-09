#include <stdio.h>

int main ()
{ /* main */

  /* Declaration of constants for conversion factors. */
  
  const float gallons_per_barrel    = 42.0;      // Number of US gallons in one barrel
  const float quarts_per_gallon     = 4.0;       // Number of US quarts in one US gallon
  const float quarts_per_liter      = 1.05669;   // Number of US quarts in one liter
  const float milliliters_per_liter = 1000.0;    // Number of milliliters per liter
  const float mph_per_knot          = 1.1507794; // Number of miles per hour (mph in short) per knot 
  const float kilometers_per_mile   = 1.609344;  // Number of kilometers in a mile
  const float meters_per_kilometer  = 1000.0;    // Number of meters in a kilometr
  const int   minutes_per_hour      = 60;        // Number of minutes in an hour
  const int   seconds_per_minute    = 60;        // Number of seconds in a second

  /* Declaration of variables for user input and calculations. */

  float volume_in_barrels, volume_in_milliliters;
  // Note: mps is short for meters per second.
  float speed_in_knots, speed_in_mps; 

  /* Greeting subsection. */
  // Introduction and expalanation to the user about the program.
  
  printf("\n\nHello!! welcome to the English to Metric Unit converter.\n");
  printf("This program helps you convert volume from barrels to milliliters\n");
  printf("and speed from knots to meters per second.\n"); 

  /* Input subsection */
  // prompting the user to input the volume in barrels.
 
  printf("\nEnter the volume in barrels: ");
  scanf("%f", &volume_in_barrels);

  // prompting the user to input the speed in knots.

  printf("Enter the speed in knots: ");
  scanf("%f", &speed_in_knots);

  /* Calculation subsection */
  // Calculating the volume from barrels to milliliters.

  volume_in_milliliters = volume_in_barrels * gallons_per_barrel * quarts_per_gallon * quarts_per_liter * milliliters_per_liter;

  // Calculating the speed from knots to meters per second (mps in short).
  // Note: mph is short for miles per hour.

  speed_in_mps = speed_in_knots * mph_per_knot * kilometers_per_mile * meters_per_kilometer / ( minutes_per_hour * seconds_per_minute);

  /* Output subsection */
  // Outputting the volume in both barrels and milliliters.

  printf("\nVolume in barrels: %1.2f\n", volume_in_barrels);
  printf("Volume in milliliters: %1.2f\n", volume_in_milliliters);

  // outputting the speed in both knots and meters per second.

  printf("\nSpeed in knots: %1.2f\n", speed_in_knots);
  printf("Speed in meters per second: %1.2f\n\n", speed_in_mps);


  return 0;

} /* main */
