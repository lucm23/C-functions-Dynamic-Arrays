The Nature of the Problem to be Solved.
The project's goal was to create a program called "my_number" that engages the user in a number-guessing game. The program asks the user to guess a number within a specified range and provides feedback on whether the guess is correct, close, or way off.

Abstract Description of the Method of Solving the Problem
In this project, I created a number-guessing game using C programming. The program first greets the user and informs them of the range within which they should make their guess. It then prompts the user to input their guess, evaluates the guess, and provides feedback based on whether the guess falls within the correct range and how close it is to the computer's chosen number.

Concrete Steps in Implementation
1.	Constants Definition: I defined constants such as the minimum and maximum numbers in the range, the "close" distance, the computer's chosen number, and the program's success code.
2.	Variable Declaration: I declared a variable to store the user's chosen number.
3.	Greeting and Range Display: The program displays a greeting and informs the user of the number range they should choose from.
4.	User Input: It prompts the user to input their guess and stores it in the declared variable.
5.	Guess Evaluation: The program evaluates the user's guess, checking if it's within the specified range if it matches the computer's number, or if it's close to the computer's number.
6.	Output Messages: The program displays appropriate messages based on the evaluation, including feedback for guesses outside the range.
7.	Program Completion: Finally, the program returns a success code to the operating system.

Issues and Problems Addressed
During implementation, I encountered an issue where the program would display "killed" and terminate unexpectedly. After investigation (a lot of debugging and rereading instructions from the professor’s project guide), I realized that this happened because I used values with a small range (0-10) in my initial testing, and the "close_distance" was set too low. The program couldn't handle values that were too close to the computer's chosen number. I resolved this issue by adjusting the range and "close_distance, maximum_number, and minimum_number" values to provide a more balanced and user-friendly experience.




Concepts Learned
Throughout the course of this project, I gained invaluable knowledge of C programming and Unix commands. This marked my first foray into utilizing Unix commands for program compilation and operation. The experience provided me with valuable insights into the creation, compiling, and execution of C programs using Unix, which will undoubtedly prove advantageous for future programming endeavors. Additionally, I acquired a keen understanding of crafting a rudimentary interactive program that engages users and provides feedback based on their input. Overall, this undertaking has established a solid foundation upon which to build my programming skills going forward.

Reference: 
1.	Lee, Kim. “CS 1313 010: Programming for Non-majors in C, Fall 2022 Programming Project #1: Thinking of a Number Due by 10:20 am Wednesday Se.” CS 1313, http://cs1313.ou.edu/proj1.pdf. Accessed 5 September 2023.

