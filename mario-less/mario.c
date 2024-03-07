#include <cs50.h>
#include <stdio.h>

int main(void)
{
    ////promt user to choose a hight between 1 and 8
    int h;
    do
    {

        h = get_int("Choose a number between 1 and 8: ");
    }
    while (h < 1 || h > 8);

    // build pyramid

    // for each row

    for (int i = 0; i < h; i++)
    {

        // for the space infront of the #
        // got some help from youtube on this part
        for (int dot = 0; dot < h - i - 1; dot++)
        {
            printf(" ");
        }
        // for each column

        for (int j = 0; j <= i; j++)

        {
            printf("#");
        }
        printf("\n");
    }
}
