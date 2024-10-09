#include <stdio.h>
#include <stdlib.h>
#include "stitch_io.h"

int main ()
{ /* main */


  int Stitch_mood;  

  input_Stitch_mood(&Stitch_mood);  

  /* Declaring variables */

  /* constants to define user phrases, and program codes.*/ 
  int help_code = 0;
  int I_love_you_code = 1;
  int youre_rotten_code = 2;
  int aloha_code = 3;
  int ohana_code = 4;
  int will_you_play_code = 5;
  int are_you_hurt_code = 6;
  int go_to_sleep_code = 7;
  int loving_mood = 1;
  int rotten_mood = 2;
  int program_failure_code = -1;
  int program_success_code = 0;
  

  /* Variables for reading user inputs. */
  int user_code;
  
  /* Input Subsection */

  
  /*
   * Idiotproof Stitch's mood.
   */
   if ((Stitch_mood != loving_mood) &&
       (Stitch_mood != rotten_mood)) {
      /*
       * Output error message for invalid mood.
       */
       printf ("ERROR: unrecognized Stitch mood %d\n", Stitch_mood);
       printf ("  (must be %d or %d).\n",loving_mood, rotten_mood);
      /*
       * Exit the program.
       */
       exit(program_failure_code);
   } /* if ((Stitch_mood != loving_mood) && ...) */

         
  /* Prompting the user to input a code that indicates a predefined
     phrase or a help code */
  
  printf("\n\nInput a code that defines a phrase to tell sticth\n");
  printf(" or input a help code to display the predefined phrases.\n\n");
  scanf ("%d", &user_code);
  

  /* 
   * Idiotproofing user's input for predefined phrases.
   */ 
   if ((user_code != help_code)          &&
       (user_code != I_love_you_code)    &&
       (user_code != youre_rotten_code)  &&
       (user_code != aloha_code)         &&
       (user_code != ohana_code)         &&
       (user_code != will_you_play_code) &&
       (user_code != are_you_hurt_code)  &&
       (user_code != go_to_sleep_code)) {
       printf("Stitch: Whatever!\n");
       exit (program_failure_code);
   } /* if ((user_code != aloha_code) && ... */


  /*
   * Output Stitch's response to the input, or the menu
   */
 
   if (user_code == help_code) {
      /*
       * Output the menu of possible inputs.
       */
       printf("\nMenu of the Stitch's phrases:\n");
       printf("%2d: [This help menu]\n", help_code);
       printf("%2d: I love you.\n",      I_love_you_code);
       printf("%2d: You're rooten!\n",   youre_rotten_code);
       printf("%2d: Aloha, Stitch.\n",   aloha_code);
       printf("%2d: Ohana.\n",           ohana_code);
       printf("%2d: Will you play?\n",   will_you_play_code);
       printf("%2d: Are you hurt?\n",      are_you_hurt_code);
       printf("%2d: Go to sleep.\n",     go_to_sleep_code );
   } /* if (user_code == help_code) */
 
   else if (user_code == I_love_you_code){
      /*
       * Output Stitch's response to being told "I love you."
       */
      printf("\nUser: I love you.\n");
      printf("Stictch: I love you too.\n");
     /*
      * Set Stitch's mood to loving.
      */ 
      Stitch_mood = loving_mood;
   } /* if (user_code == I_love_you_code) */

   else if (user_code == youre_rotten_code){
      /*
       * Output Stitch's response to being told "You're rotten."
       */    
      printf("User: You're rotten.\n");
      printf("Stitch: Ahh ha ha ha ha ha ha!\n");
     /*
      * Set Stitch's mood to rotten.
      */
      Stitch_mood = rotten_mood;
   } /* if (user_code == youre_rotten_code) */

  /*
   * Outputting Stitch's response to the input (3,4,5,6,7)
   */  
   if (user_code == aloha_code){
 
    /*
     * Prompting the users code. 
     */
 
      printf("User: Aloha, Stitch.\n");

    /*
     * Checking the stitch's mood. 
     */
  
      if (Stitch_mood == loving_mood ){

          printf("Stitch: Aloha.\n");

      } else{

            printf("Stitch: What do you want?\n");

        }
   } /* if (user_code == aloha_code) */

   else if (user_code == ohana_code){
          
           /*
            * Output the message for Ohana.
            */
           
           printf("User: Ohana.\n");
           printf("Stitch: Ohana means family. And family means,");
           printf("nobody gets left behind, or forgotten.\n");

   } /* if (user_code == ohana_code) */

   else if (user_code == will_you_play_code){
     /*
      * Output the message for will you play?
      */      
           printf("User: Will you play?\n");

           if (Stitch_mood == loving_mood){

           printf("Stitch: Surf's up! Cowabunga!\n");

           } else {
             
             printf("Stitch: I'm busy! Get Lost!\n");

             } 
   } /* if (user_code == will_you_play_code) */

   else if (user_code == are_you_hurt_code){
     
     /*
      * Output the message for Are you hurt?
      */
           printf("User: Are you hurt?\n");
           
           if (Stitch_mood == loving_mood){

           printf("Stitch: I'm okay; I'm fluffy!\n");
           
           } else{
             
             printf("Stitch: Ow! I hit my head!\n");

             } 
   } /* if (user_code == are_you_hurt_code) */

   else if (user_code == go_to_sleep_code){
     
     /*
      * Output the message for Go to sleep!
      */
           printf("User: Go to sleep.\n");

           if ( Stitch_mood == loving_mood){
           
           printf("Stitch: Very sleepy ... Zzzz ...\n\n");

           } else {

             printf("Stitch: No! Make me a sandwich!\n\n");

             }
   } /* if (user_code == go_to_sleep_code) */

  /*
   * Output to the mood file
   */

   output_Stitch_mood(Stitch_mood);
   
  /*
   * executing the program success code. 
   */     
   return program_success_code;

}
