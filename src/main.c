#include <stdio.h>
#include <unistd.h>

#define SCREEN_WIDTH 15
#define SCREEN_HEIGHT 15

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
void init_player(player *player)
{

}

void init_ball(ball *ball)
{
    ball->posx = 4;
    ball->posy = 10;
    ball->radius = 1;
    ball->speedx = 1;
    ball->speedy = 1;
}

// SEC_DRAW
void screen_clear()
{
    printf("\033[2J"); // clear screen

    printf("\033[H"); // put the cursor to the
                      // top left 
}

void draw(player player, ball ball)
{
    for(int i = 1; i <= SCREEN_HEIGHT; i++)
    {
        for(int j = 1; j <= SCREEN_WIDTH; j++)
        {
            if(i == 1 || i == SCREEN_HEIGHT || j == 1 || j == SCREEN_WIDTH)
            {
                printf("#");
            }
            else if(j == ball.posx && i == ball.posy)
            {
                printf("@");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}

void debug_player(player player)
{
    printf("player: posx = %d, posy = %d, width = %d, height = %d, speed = %d",
            player.posx, player.posy, player.width, player.height, player.speed);
}

void debug_ball(ball ball)
{
    printf("ball: posx = %d, posy = %d, speedx = %d, speedy = %d, radius = %d",
            ball.posx, ball.posy, ball.speedx, ball.speedy, ball.radius);
}

// SEC_LOGIC
void logic_player(player *player);

void logic_ball(ball *ball)
{
    ball->posx += ball->speedx;
    ball->posy += ball->speedy;

    if(ball->posx > SCREEN_WIDTH - 1)
    {
        ball->speedx *= -1;
        ball->posx = SCREEN_WIDTH - 2;
    }
    if(ball->posx < 2)
    {
        ball->speedx *= -1;
        ball->posx = 3;
    }

    if(ball->posy > SCREEN_HEIGHT - 1)
    {
        ball->speedy *= -1;
        ball->posy = SCREEN_HEIGHT - 2;
    }
    if(ball->posy < 2)
    {
        ball->speedy *= -1;
        ball->posy = 3;
    }
}

int main()
{
    player player;
    ball ball;

    init_player(&player);
    init_ball(&ball);

    for(;;)
    {
        screen_clear();
        logic_ball(&ball);
        draw(player, ball);

        debug_player(player);
        printf("\n");
        debug_ball(ball);

        fflush(stdout); //UNDEFINED! idc lolz
        sleep(1);
    }

    return 0;
}
