#include <stdio.h>
#include <conio.h> // required to use clrscr function
#include <stdlib.h>
#include <string.h>

int main() {
	// declare variables
	int choice = 0;
	int pin1[6] = { 0 };
	char pin2[7] = { '\0' };
	char ch;
	int temp[6] = { 0 };
	int x = 0;
	int check = 0;

	// run menu until choice is exit
	do {
		// clear the screen before ever pass
		system("cls");
		printf("Welcome to your PIN program! What do you want to do? Please enter:\n");
		printf(" 1 for entering a PIN twice\n");
		printf(" 2 for checking if PINs are equal\n");
		printf(" 3 for checking if PIN Number violates rule\n");
		printf(" 4 for exit\n");
		scanf_s("%d", &choice);

		// switch function for the choices
		switch (choice) {
		case 1:
			printf("\nWelcome to the pin verification program.\n");
			printf("Please enter your 6 digit pin numbers separated by spaces\n");
			printf("PIN# must not start with a zero (0)\n");
			for (x = 0; x < 6; x++) {
				scanf_s("%d", &pin1[x]);
			}
			printf("\nPlease re-enter pin as a 6 digit number without spaces to verify it is the same number\n");
			ch = getchar();
			for (x = 0; x < 6; x++) {
				ch = getchar();
				pin2[x] = ch;
				temp[x] = ch - '0';
			}
			// printf("%s", pin2); // check to make sure pin2 isn't null
			printf("\nPress enter to continue\n");
			_getch();
			break;
		case 2:
			for (x = 0; x < 6; x++) {
				// printf("\n%d %d", pin1[x], temp[x]); // check to ensure values match
				if (pin1[x] == temp[x])
					check += 0;
				else
					check += 1;
			}
			if (check == 0)
				printf("\nPINs match\n");
			else
				printf("\nPINs do not match! Please re-enter the PINs\n");
			printf("\nPress enter to continue\n");
			_getch();
			break;
		case 3:
			if (pin1[0] == 0)
				printf("\nPINs start with a zero. PIN is not valid!\n");
			else
				printf("\nPIN is valid. You have sucessfully entered a PIN\n");
			printf("\nPress enter to continue\n");
			_getch();
			break;
		case 4:
			printf("\nEnd of Program\n");
			break;
		} // end switch
	} while (choice != 4); // end do while loop
} // end main