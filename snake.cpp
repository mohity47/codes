#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int snake_length=5;
int max_row=20,max_col=40;
int score;
queue<pair<char,pair<int,int> > > change;
char cur_dir='r',tail_dir='r';
pair<int,int> head_coordinates,next_coordinates,tail_coordinates;
pair<int,int> food_coordinates;
int snake_coordinates[20][40];
int gameover=0;
COORD coord={0,0};
 void gotoxy(int x,int y)
 {
   coord.X=y;
   coord.Y=x;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void initialize_box()
{
    int i,j;
    for(i=0;i<=max_row;i++)
    {
        if(i==0||i==max_row)
        {
            for(j=0;j<=max_col;j++)
                printf("%c",178);
        }
        else
        {
            printf("%c",178);
            for(j=1;j<max_col;j++)
                printf(" ");
            printf("%c",178);
        }
        printf("\n");
    }
}
void initialize_snake()
{
    int i;
    head_coordinates.first=5;
    head_coordinates.second=10+snake_length-1;
    tail_coordinates.first=5;
    tail_coordinates.second=10;
    for(i=0;i<snake_length;i++)
        snake_coordinates[5][10+i]=1;
    gotoxy(5,10);
    for(i=0;i<snake_length;i++)
        printf("%c",2);
}
void generate_food()
{
    int x,y;
    x=rand()%19+1;
    y=rand()%40+1;
    while(snake_coordinates[x][y]!=0)
    {
         x=rand()%19+1;
         y=rand()%40+1;
    }
    food_coordinates.first=x;
    food_coordinates.second=y;
    gotoxy(food_coordinates.first,food_coordinates.second);
        printf("%c",2);
}
bool check_food(int x,int y)
{
    if(food_coordinates.first==x&&food_coordinates.second==y)
        return true;
    return false;
}
void manage_score()
{
    score=(snake_length-5)*5;
}
void move_tail()
{
    pair<char,pair<int,int> > temp;
    gotoxy(tail_coordinates.first,tail_coordinates.second);
    snake_coordinates[tail_coordinates.first][tail_coordinates.second]=0;
    printf(" ");
    if(change.empty()==0)
    {
        temp=change.front();
        if(temp.second==tail_coordinates)
            {tail_dir=temp.first;
            change.pop();
            }
    }
    if(tail_dir=='r')
    {
        tail_coordinates.second++;
        if(tail_coordinates.second==40)
            tail_coordinates.second=1;
    }
    else if(tail_dir=='l')
    {
        tail_coordinates.second--;
        if(tail_coordinates.second==0)
            tail_coordinates.second=39;
    }
    else if(tail_dir=='u')
    {
        tail_coordinates.first--;
        if(tail_coordinates.first==0)
            tail_coordinates.first=19;
    }
    else
    {
        tail_coordinates.first++;
        if(tail_coordinates.first==20)
            tail_coordinates.first=1;
    }
}
void check_gameover(int x,int y)
{
    if(snake_coordinates[x][y]==1)
        gameover=1;
}
void right()
{
    next_coordinates.first=head_coordinates.first;
    next_coordinates.second=head_coordinates.second+1;
    if(next_coordinates.second==40)
        next_coordinates.second=1;
    if(check_food(next_coordinates.first,next_coordinates.second))
    {
        snake_length++;
        manage_score();
        snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
        generate_food();
    }
    else
    {
    move_tail();
    check_gameover(next_coordinates.first,next_coordinates.second);
    if(gameover)
        return;
    snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
    gotoxy(next_coordinates.first,next_coordinates.second);
    printf("%c",2);
    }
    head_coordinates=next_coordinates;
}
void left()
{
    next_coordinates.first=head_coordinates.first;
    next_coordinates.second=head_coordinates.second-1;
    if(next_coordinates.second==0)
        next_coordinates.second=39;
    if(check_food(next_coordinates.first,next_coordinates.second))
    {
        snake_length++;
        manage_score();
        snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
        generate_food();
    }
    else
    {
    move_tail();
    check_gameover(next_coordinates.first,next_coordinates.second);
    if(gameover)
        return;
    snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
    gotoxy(next_coordinates.first,next_coordinates.second);
    printf("%c",2);
    }
    head_coordinates=next_coordinates;
}
void up()
{
    next_coordinates.first=head_coordinates.first-1;
    next_coordinates.second=head_coordinates.second;
    if(next_coordinates.first==0)
        next_coordinates.first=19;
    if(check_food(next_coordinates.first,next_coordinates.second))
    {
        snake_length++;
        manage_score();
        snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
        generate_food();
    }
    else
    {
    move_tail();
    check_gameover(next_coordinates.first,next_coordinates.second);
    if(gameover)
        return;
    snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
    gotoxy(next_coordinates.first,next_coordinates.second);
    printf("%c",2);
    }
    head_coordinates=next_coordinates;
}
void down()
{
    next_coordinates.first=head_coordinates.first+1;
    next_coordinates.second=head_coordinates.second;
    if(next_coordinates.first==20)
        next_coordinates.first=1;
    if(check_food(next_coordinates.first,next_coordinates.second))
    {
        snake_length++;
        manage_score();
        snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
        generate_food();
    }
    else
    {
    move_tail();
    check_gameover(next_coordinates.first,next_coordinates.second);
    if(gameover)
        return;
    snake_coordinates[next_coordinates.first][next_coordinates.second]=1;
    gotoxy(next_coordinates.first,next_coordinates.second);
    printf("%c",2);
    }
    head_coordinates=next_coordinates;
}
void scoreboard()
{
    for(int i=0;i<6;i++)
    {
        gotoxy(i+8,9);
        for(int j=0;j<21;j++)
            printf("%c",178);
    }
    gotoxy(10,11);
    printf("     Game Over   ");
    gotoxy(11,11);
    printf("        %d        ",score);
}
int main()
{
    initialize_box();
    initialize_snake();
    generate_food();
    while(gameover==0)
    {
        Sleep(100);
        if(kbhit())
        {
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                break;
            }
            else if(GetAsyncKeyState(VK_RIGHT))
            {
                if(cur_dir!='r'&&cur_dir!='l')
                {
                 change.push(make_pair('r',make_pair(head_coordinates.first,head_coordinates.second)));
                 cur_dir='r';
                }
            }
            else if(GetAsyncKeyState(VK_LEFT))
            {
                if(cur_dir!='r'&&cur_dir!='l')
                {
                 change.push(make_pair('l',make_pair(head_coordinates.first,head_coordinates.second)));
                 cur_dir='l';
                }
            }
            else if(GetAsyncKeyState(VK_DOWN))
            {
                if(cur_dir!='d'&&cur_dir!='u')
                {
                 change.push(make_pair('d',make_pair(head_coordinates.first,head_coordinates.second)));
                 cur_dir='d';
                }
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                if(cur_dir!='u'&&cur_dir!='d')
                {
                 change.push(make_pair('u',make_pair(head_coordinates.first,head_coordinates.second)));
                 cur_dir='u';
                }
            }
        }
        if(cur_dir=='r')
            right();
        else if(cur_dir=='l')
            left();
        else if(cur_dir=='d')
            down();
        else
            up();
    }
    scoreboard();
    gotoxy(22,0);
    printf("Press Enter to Exit");
    getchar();
    return 0;
}
