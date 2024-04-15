/*
 *
 *
 *
 * the dev is dumb lol work on it after I smarting
 *
 *
 *
*/

#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 50

typedef struct player
{
    int posx;
    int posy;
    int width;
    int height;
    int speed;
} player;

typedef struct ball
{
    int posx;
    int posy;
    int radius;
    int speedx;
    int speedy;
} ball;

// SEC_INIT
void init(player *player, ball *ball)
{
    player->posx = 0;
    player->posy = 
}

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

        fflush(stdout); //UNDEFINED! idc lolz
        sleep(1);
    }

    return 0;
}
