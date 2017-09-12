/*
 ============================================================================
 Name        : Lab3.c
 Author      : Kyle Deppe
 Course		 : ECE 3220
 Description : Calculates the area of a circle, the profit after a cost, and then executes a 4-button calculator.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi M_PI

void areaOfCircle();
void profitCalculator();
void calculator();

// Description:	Calculates the area of a circle, the profit after a cost, and then a 4-button calculator.
// Returns:		0.
int main(void) {
	areaOfCircle();
	profitCalculator();
	calculator();

	printf("\n\n");
	return EXIT_SUCCESS;
}

// Description:	Calculates the area of a circle from the radius and pi imported from math.h.
// Returns:		n/a.
void areaOfCircle() {
	float radius = 0;
	float area = 0;

	printf("\n***AREA OF A CIRCLE***");
	printf("\nEnter a radius to calculate the area of a circle: ");
	if (scanf("%f", &radius) == 1) {// Checks if there is 1 float in the input. This helps prevent characters in the input.
		// The input is correct.
	} else {
		printf("Error! Invalid input.");
		getchar();	// Collects the \n from the scanf().
		return;
	}
	getchar();

	if (radius < 0) {
		printf("Error! Negative input.");
		return;
	}

	area = pi * pow(radius, 2);

	printf("The area of the circle is %.3f.", area);
}

// Description: Calculates the profit or incurred loss.
// Returns:		n/a.
void profitCalculator() {
	float cost = 0;
	float sells = 0;

	printf("\n\n***NET PROFIT CALCULATOR***");
	printf("\nEnter the cost: ");
	if (scanf("%f", &cost) == 1) {
		// The input is correct.
	} else {
		printf("Error! Invalid input.");
		getchar();
		return;
	}
	getchar();

	if (cost < 0) {
		printf("Error! Negative input.");
		return;
	}

	printf("Enter how much it sells for: ");
	if (scanf("%f", &sells) == 1) {
		// The input is correct.
	} else {
		printf("Error! Invalid input.");
		getchar();
		return;
	}
	getchar();

	if (sells < 0) {
		printf("Error! Negative input.");
		return;
	}

	if ((cost - sells) > 0) {
		printf("Your incurred loss is $%.2f.", (cost - sells));
	} else if ((sells - cost) > 0) {
		printf("Your profit is $%.2f!", (sells - cost));
	} else {
		printf("You broke even at a net profit of $0.00.");
	}
}

// Description:	Executes +, -, *, /.
// Returns:		n/a.
void calculator() {
	float operand1 = 0;
	float operand2 = 0;
	char operator = 0;

	printf("\n\n***4 BUTTON CALCULATOR***");
	printf("\nEnter the first operand: ");
	if (scanf("%f", &operand1) == 1) {
		// The input is correct.
	} else {
		printf("Wrong format! Please re-enter: ");
		getchar();
		while (scanf("%f", &operand1) != 1) {
			getchar();
			printf("Wrong format! Please re-enter: ");
		}
	}
	getchar();

	printf("Enter the second operand: ");
	if (scanf("%f", &operand2) == 1) {
		// The input is correct.
	} else {
		printf("Wrong format! Please re-enter: ");
		getchar();
		while (scanf("%f", &operand2) != 1) {
			getchar();
			printf("Wrong format! Please re-enter: ");
		}
	}
	getchar();

	printf("Enter the operator: ");
	operator = getchar();

	while (operator != '+' && operator != '-' && operator != '*'
			&& operator != '/') {
		printf("Wrong format! Please re-enter.");
		printf("\nEnter the operator: ");
		getchar();
		operator = getchar();
	}

	switch (operator) {
	case '+':
		printf("%.3f + %.3f = %.3f.", operand1, operand2,
				(operand1 + operand2));
		break;

	case '-':
		printf("%.3f - %.3f = %.3f.", operand1, operand2,
				(operand1 - operand2));
		break;

	case '*':
		printf("%.3f * %.3f = %.3f.", operand1, operand2,
				(operand1 * operand2));
		break;

	case '/':
		if (operand2 == 0) {
			printf("Error! Division by 0.");
			break;
		} else {
			printf("%.3f / %.3f = %.3f.", operand1, operand2, (operand1 / operand2));
		}
		break;

	default:
		printf("Error: Invalid Operator.");
	}
}

