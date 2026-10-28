
#include <stdio.h>
#include <string.h>

char in[30];
int k = 1;

void process(char op)
{
    for (int i = 0; in[i] != '\0'; i++)
    {
        if (in[i] == op)
        {
            printf("t%d=", k);

            if (in[i - 1] >= 'A' && in[i - 1] <= 'Z')
                printf("t%d", in[i - 1] - 'A' + 1);
            else
                printf("%c", in[i - 1]);

            printf("%c", op);

            if (in[i + 1] >= 'A' && in[i + 1] <= 'Z')
                printf("t%d\n", in[i + 1] - 'A' + 1);
            else
                printf("%c\n", in[i + 1]);

            in[i - 1] = 'A' + k - 1;

            for (int j = i; in[j] != '\0'; j++)
                in[j] = in[j + 2];

            k++;
            i--;
        }
    }
}

int main(void)
{
    printf("Enter the expression\n");
    scanf("%29s", in);

    process('/');
    process('*');
    process('+');
    process('-');

    printf("Result = t%d\n", k - 1);

    return 0;
}
