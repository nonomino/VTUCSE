#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char
prod[3][10] = {
	"A->aBa",
	"B->bB",
	"B->@"
}, input[10], stack[25];
int top = -1, buflen = 0;

void pop() {
	--top;
}

void push_production(char p) {
	if (p == 'A') {
		pop();
		for (int i = strlen(prod[0]) - 1; i >= 3; i--)
		stack[++top] = prod[0][i];
	} else if (p == 'B') {
		pop();
		for (int i = strlen(prod[1]) - 1; i >= 3; i--)
		stack[++top] = prod[1][i];
	}
}
void incorrect_input() {
	for (int i = 0; input[i] != '\0'; i++) {
		if ((input[i] != 'a') && (input[i] != 'b') && (input[i] != '$')) {
			printf("Invalid string");
			exit(0);
		}
	}
	if (input[strlen(input) - 1] != '$') {
		printf("\n\nInput string entered without end marker $");
		exit(0);
	}
}

void check_valid() {
	if (stack[top] == '$' && input[buflen] == '$')
		printf("\n$\t$\nValid string Accepted\n");
	else
		printf("\nInvalid string rejected\n");
}
int main() {
	printf("first(A)={a}\t");
	printf("follow(A)={$}\n");
	printf("first(B)={b,@}\t");
	printf("follow(B)={a}\n\n");
	printf("\t a \t b \t $ \n");
	printf("A\t%s\n", prod[0]);
	printf("B\t%s\t%s\n", prod[2], prod[1]);
	printf("Enter the input string terminated with $ to parse:-");
	strcpy(input, "abba");
	incorrect_input();
	stack[++top] = '$';
	stack[++top] = 'A';
	printf("\n\nstack\tInput\taction\n\n----------\n");
	while (buflen != strlen(input) && stack[top] != '$') {
		printf("\n");
		for (int j = top; j >= 0; j--)
		printf("%c", stack[j]);
		printf("\t");
		for (int j = buflen; j < strlen(input); j++)
		printf("%c", input[j]);
		printf("\t");
		if (stack[top] == 'A') {
			printf("A->aBa");
			push_production('A');
		} else if (stack[top] == 'B') {
			if (input[buflen] == 'b') {
				printf("B->bB");
				push_production('B');
			} else {
				printf("B->@\tMatched @");
				pop();
			}
		} else {
			if (stack[top] == input[buflen]) {
				printf("POP %c", input[buflen]);
				printf("\tMatched %c", input[buflen]);
				pop();
				buflen++;
			} else
			break;
		}
	}
	check_valid();
	return 0;
}