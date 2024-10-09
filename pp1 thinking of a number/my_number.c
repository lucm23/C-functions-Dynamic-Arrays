


/*
 **********************************************************************
 *** Project #1:  Thinking of a Number                              ***
 *** Program:     my_number                                         ***
 *** Author:      Thierry Mwizerwa (luc.thierry.mwizerwa-1@ou.edu   ***                     ***
 *** Class:       CS 1313 010 Computer Programming, Fall 2023       ***
 *** Lab:         Sec 012 Fridays 10:30am                           ***
 *** Description: Asks the user to pick a number within a range,    ***
 ***   then tells whether the user's number matches the program's.  ***
 **********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{ /* main */
   /*
    ***************************
    *** Declaration Section ***
    ***************************
    *
    *****************************
    * Named Constant Subsection *
    *****************************
    *
    * minimum_number:       The user's number should be at least this.
    * maximum_number:       The user's number should be at most this.
    * close_distance:       How close the user has to be to be told
    *                       that they're close.
    * computers_number:     The number the computer is "thinking" of.
    * program_success_code: By convention, returning 0 from a program
    *                       to the operating system (in this case,
    *                       Linux) means that the program has finished
    *                       successfully.
    */
    const int minimum_number       = 0;
    const int maximum_number       =  20;
    const int close_distance       =  4;
    const int computers_number     =  15;
    const int program_success_code  =  0;
   /*
    ***********************
    * Variable Subsection *
    ***********************
    *
    * users_number: The user's chosen number.
    */
    int users_number;

   /*
    *************************
    *** Execution Section ***
    *************************
    *
    ***********************
    * Greeting Subsection *
    ***********************
    *g
    * Describe what the program does.
    */
    printf("Let's see whether you can guess ");
    printf("the number that I'm thinking of.\n");

   /*
    * Tell the user the range to choose from.
    */
    printf("It's between %d and %d.\n",
        minimum_number, maximum_number);

   /*
    ********************
    * Input Subsection *
    ********************
    *
    * Prompt the user to guess.
    */

    printf("What number am I thinking of?\n");

   /*
    * Input the user's number.
    */

    scanf("%d", &users_number);

   /*
    *********************
    * Output Subsection *
    *********************
    *
    * Judge the user's number.
    */
    if ((users_number < minimum_number) ||
        (users_number > maximum_number)) {
       /*
        * Idiotproof: they're outside the range, so complain.
        */
        printf("whatsup dude!");
        printf(" That's not between %d and %d!\n",
            minimum_number, maximum_number);
    } /* if ((users_number < minimum_number) || ...) */
    else if (users_number == computers_number) {
       /*
        * They're correct, so be amazed.
        */
        printf("That's great for real! you ate!!\n");
    } /* if (users_number == computers_number) */
    else if (abs(users_number - computers_number) <= close_distance) {
       /*
        * They're within close_distance, so say that they're close.
        */
        printf("Close, but no cigar.\n");
    } /* if (abs(users_number - computers_number) <= ...) */
    else {
       /*
        * They're not even close, so be cruel.
        */
        printf("Uhhh, that was way far from the number I'm thinking, haha! .\n");
    } /* if (abs(users_number - computers_number) <= ...)...else */
   /*
    * Tell the operating system (in this case, Linux) that
    * the program finished successfully.
    */
    return program_success_code;
} /* main */

