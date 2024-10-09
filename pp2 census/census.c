#include <stdio.h>

int main ()
{ /* main */

	/* Declaration Section */
	
	float Average_Hours_Spent_With_Friends;	// On a weekly basis.
	float Average_Number_Of_Help_Sessions_Attended_Per_Semester;
	int   Feet;
	int   Inches;	// To the nearest inch. 

	/* Execution Section */

		/* Greeting Subsection */
		
	printf("\n\n\n Hello, I think I can guess the average time you");
	printf(" spend by friends,\n the average number of  help sessions");
	printf(" you have attended this semester\n and your height. Just try ");
	printf(" to answer questions below, Let's go !!!\n\n");
		
		/* Input subsection */

	printf(" 1. Can you type in the average number of hours");
	printf(" spent with friends in a week?\n\n");
	scanf("%f",&Average_Hours_Spent_With_Friends);
	printf("\n\n 2. Can you enter the average number of help");
	printf(" sessions you attend this semester?\n\n");
	scanf("%f",&Average_Number_Of_Help_Sessions_Attended_Per_Semester);
	printf("\n\n 3. What is your height in feet and inches,\n");
	printf(" to the nearest inch, separated by a blank space?\n\n");
	scanf("%d %d", &Feet, &Inches);

		/* Output Subsection */
	printf("\n\n Now i can guess that:\n");		
	printf(" You have on average you have spent");
	printf(" %f hours with friends per week.\n", Average_Hours_Spent_With_Friends);
	printf(" and on average you have attended %f help sessions per semester.", Average_Number_Of_Help_Sessions_Attended_Per_Semester);
	printf(" \n and your height is %d ft %d in.\n\n\n", Feet, Inches);

		/* end of the program */

	return 0;

} /* main */

