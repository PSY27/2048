//75(left arrow)
//72(up arrow)
//77(right arrow)
//80(down arrow)
#include<stdio.h>
#include <conio.h>

#define C 5

int a[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
int r=5;
int k=0;


int main()
{

    int extended = 0;
    srand(time(NULL));

    int i = 0;
    random();
    random();
    display();
    int x;
    while(x!=27)
    {
        x = getch();

        //x = 0;
        switch(x)
        {
            case 'a':
            case 75:
                merge_left();
                move_left();
                random();
                display();
                winner();
                loser();
                printf("Left\n");
                break;
            case 'd':
            case 77 :
                merge_right();
                move_right();
                random();
                display();
                winner();
                loser();
                printf("Right\n");
                break;
            case 'w':
            case 72 :
               merge_top();
                move_top();
                random();
                display();
                winner();
                loser();
                 printf("Up\n");
                break;
            case 's':
            case 80 :
                merge_bottom();
                move_bottom();
                random();
                display();
                winner();
                loser();
                printf("Down\n");
                break;
            case 27:
                break;

        }
    }


    return 0;
}



void display()
{

//Windows:
system("cls");



    int i;
    int j;
    int emptyCount = 0;
    printf("\n\n\t\tPSY 27 PRESENTS\n");
    printf("\n\t\t2048\n");
    printf("\n+------+------+------+------+------+\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<C;j++)
        {
            printf("|");
            if(a[i][j] == 0)
            {
                printf("      ");
                emptyCount++;
            }
            else
            {
                printf(" %4d ",a[i][j]);
            }
        }
        printf("|");
        printf("\n|      |      |      |      |      |\n");
        printf("+------+------+------+------+------+\n");
    }
    //printf("Empty Cells : %d\n", emptyCount);

}

void random()
{
    int posr;
    int posc;
    int num;
    int n;
    int i;
    int j;
    int count = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(a[i][j] == 0)
            {
                count++;
            }
        }
    }

    if(count == 0)
    {
        printf("\nAll Cells have been filled\n");
        return;
    }

    n = rand() %10;
    //switch(n)
   /* {
        case 0: num = 2;
                break;
        case 1: num = 4;
                break;
    }*/
    if(n==2 || n==4)
    {
        num = 4;
    }
    else{
        num = 2;
    }



    while(1)
    {
        posr = rand() %4;
        posc = rand() %4;

        if(a[posr][posc] == 0)
        {
            //printf("\n%d : [%d]-[%d]", count, posr,posc);
            a[posr][posc] = num;
            break;
        }
        count++;

    }

}

void move_left()
{
       int i;
    int j;

    for (i = 0; i < 5; i++)
    {
        int eCell = -1;
        int nCell = -1;
        for(j = 0; j < 5; j++)
        {
            if(a[i][j] == 0 && eCell == -1)
            {
                eCell = j;
            }
            else if(a[i][j] > 0 && eCell >= 0  && nCell == -1)
            {
                nCell = j;
            }

            if(eCell >= 0 && nCell >= 0)
            {
                a[i][eCell] = a[i][nCell];
                a[i][nCell] = 0;
                eCell++;
                nCell = -1;
            }
        }
    }

}

void move_right()
{
     int i;
    int j;

    for (i = 0; i < 5; i++)
    {
        int eCell = -1;
        int nCell = -1;
        for(j = 4; j >= 0; j--)
        {
            if(a[i][j] == 0 && eCell == -1)
            {
                eCell = j;
            }
            else if(a[i][j] > 0 && eCell >= 0  && nCell == -1)
            {
                nCell = j;
            }

            if(eCell >= 0 && nCell >= 0)
            {
                a[i][eCell] = a[i][nCell];
                a[i][nCell] = 0;
                eCell--;
                nCell = -1;
            }
        }
    }

}

void move_top()
{
    int i;
    int j;

    for (j = 0; j < 5; j++)
    {
        int eCell = -1;
        int nCell = -1;
        for(i = 0; i < 5; i++)
        {
            if(a[i][j] == 0 && eCell == -1)
            {
                eCell = i;
            }
            else if(a[i][j] > 0 && eCell >= 0  && nCell == -1)
            {
                nCell = i;
            }

            if(eCell >= 0 && nCell >= 0)
            {
                a[eCell][j] = a[nCell][j];
                a[nCell][j] = 0;
                eCell++;
                nCell = -1;
            }
        }
    }
}

void move_bottom()
{
     int i;
    int j;

    for (j = 0; j < 5; j++)
    {
        int eCell = -1;
        int nCell = -1;
        for(i = 4; i >= 0; i--)
        {
            if(a[i][j] == 0 && eCell == -1)
            {
                eCell = i;
            }
            else if(a[i][j] > 0 && eCell >= 0  && nCell == -1)
            {
                nCell = i;
            }

            if(eCell >= 0 && nCell >= 0)
            {
                a[eCell][j] = a[nCell][j];
                a[nCell][j] = 0;
                eCell--;
                nCell = -1;
            }
        }
    }

}

void merge_top()
{
    int i;
    int j;
    for(j=0;j<5;j++)
    {
        //for(k=0;k<4;k++)
        //{

            int fno = -1;

            for(i=0;i<5;i++)
            {
                if(a[i][j] > 0)
                {
                    if (fno == -1)
                    {
                       fno = i;
                    }
                    else if(a[fno][j] == a[i][j])
                    {
                        a[fno][j] = a[fno][j] + a[i][j];
                        a[i][j] = 0;
                        fno = -1;

                    }
                    else
                    {
                        fno = i;
                    }
                }
            }
    }
}

void merge_bottom()
{
    int i;
    int j;
    int k;
    for(j=0;j<5;j++)
    {
      int fno = -1;
        for(i=4;i>=0;i--)
        {

            if(a[i][j] > 0)
            {
                if (fno == -1)
                {
                   fno = i;
                }
                else if(a[fno][j] == a[i][j])
                {
                    a[fno][j] = a[fno][j] + a[i][j];
                    a[i][j] = 0;
                    fno = -1;
                }
                else
                    {
                        fno = i;
                    }
            }
        }
    }
}

void merge_left()
{
    int i;
    int j;
    for(i=0;i<5;i++)
    {
            int fno = -1;
            for(j=0;j<5;j++)
            {

                if(a[i][j] > 0)
                {
                    if (fno == -1)
                    {
                       fno = j;
                    }
                    else if(a[i][fno] == a[i][j])
                    {
                        a[i][fno] = a[i][fno] + a[i][j];
                        a[i][j] = 0;
                        fno = -1;
                    }
                    else
                    {
                        fno = j;
                    }
                }
            }
    }
}

void merge_right()
{
    int i;
    int j;
    int k;
    for(i=0;i<5;i++)
    {
      int fno = -1;
        for(j=4;j>=0;j--)
        {

            if(a[i][j] > 0)
            {
                if (fno == -1)
                {
                   fno = j;
                }
                else if(a[i][fno] == a[i][j])
                {
                    a[i][fno] = a[i][fno] + a[i][j];
                    a[i][j] = 0;
                    fno = -1;
                }
                 else
                    {
                        fno = j;
                    }
            }
        }
    }
}

void winner()
{
    int i;
    int j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[i][j] == 2048)
            {
                printf("You Win!");
            }
        }
    }
}

void loser()
{
    int i;
    int j;
    int p = 0;
    int q = 0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j] == a[i][j+1])
            {
                p = 1;
            }
        }
    }
    for(j=0;j<5;j++)
    {
        for(i=0;i<4;i++)
        {
            if(a[i][j] == a[i+1][j])
            {
                q = 1;
            }
        }
    }

    if(p==0 && q==0)
    {
        printf("You Lose!");
    }
}
