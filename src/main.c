#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 50

// SEC_INIT


// SEC_DRAW
void screen_clear()
{
    printf("\033[2J"); // clear screen

    printf("\033[H"); // put the cursor to the
                      // top left 
}

void draw()
{
    for(int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for(int j = 0; j < SCREEN_HEIGHT; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// SEC_LOGIC


int main()
{
    for(;;)
    {
        screen_clear();

        sleep(1);
    }

    return 0;
}
