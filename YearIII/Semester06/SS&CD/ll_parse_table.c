#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char
prod[3][10] = {
    "A->aBa",
    "B->bB",
    "B->@"
}, input[10], stack[25];
int top = -1, i = 0, k, l;

void pop() {
    --top;
}

void push(char p) {
    if (p == 'A') {
        pop();
        for (int i = strlen(prod[0]) - 1; i >= 3; i--)
            stack[++top] = prod[0][i];
    } else {
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
    if (stack[top] == '$' && input[i] == '$')
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
    scanf("%s", input);
    incorrect_input();
    stack[++top] = '$';
    stack[++top] = 'A';
    printf("\n\nstack\tInput\taction\n\n----------\n");
    while (i != strlen(input) && stack[top] != '$') {
        printf("\n");
        for (l = top; l >= 0; l--)
            printf("%c", stack[l]);
        printf("\t");
        for (l = i; l < strlen(input); l++)
            printf("%c", input[l]);
        printf("\t");
        if (stack[top] == 'A') {
            printf("A->aBa");
            push('A');
        } else if (stack[top] == 'B') {
            if (input[i] != 'b') {
                printf("B->@\n\t Matched @");
                pop();
            } else {
                printf("B->bB");
                push('B');
            }
        } else {
            if (stack[top] == input[i]) {
                printf("POP %c", input[i]);
                printf("\tMatched %c", input[i]);
                pop();
                i++;
            } else
                break;
        }
    }
    check_valid();
    return 0;
}