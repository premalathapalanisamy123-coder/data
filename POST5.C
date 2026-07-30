#include <stdio.h>
#include <ctype.h>

int main()
{
    int stack[50], top = -1, i, op1, op2;
    char postfix[50], ch;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isdigit(ch))
            stack[++top] = ch - '0';
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];

            switch(ch)
            {
                case '+': stack[++top] = op1 + op2; break;
                case '-': stack[++top] = op1 - op2; break;
                case '*': stack[++top] = op1 * op2; break;
                case '/': stack[++top] = op1 / op2; break;
            }
        }
    }

    printf("Result = %d\n", stack[top]);

    return 0;
}