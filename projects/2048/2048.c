#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// 游戏主界面是一个 4*4 的 16 宫格，使用二维数组进行表示，用 0 表示空格
int boxes[4][4] = {0};
// 16 宫格中空格的个数
int empty;
int old_y, old_x;

// 声明函数原型
void play();                 // main logical unit of game running
void init();                 // initiate the game
void draw_border();          // draw the ui of 2048 game
void draw_digital();
void draw_one(int y, int x); // draw a single unit
void cnt_value(int *new_y, int *new_x);
int game_over();
int cnt_one(int y, int x);

void
init()
{
    int x, y;

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    empty = 15;
    srand(time(0));
    x = rand() % 4;
    y = rand() % 4;
    boxes[y][x] = 2;
    clear();
    draw_border();
    draw_one(y, x);
}

void
draw_border()
{
    int n, m, x, y;
    char c[4] = {'0'};

    for (n = 0; n < 9; n += 2) {
        for (m = 0; m < 21; m++) {
            move(n, m);
            addch('-');
            refresh();
        }
    }
    for (m = 0; m < 22; m += 5) {
        for (n = 1; n < 8; n += 2) {
            move(n, m);
            addch('|');
            refresh();
        }
    }
    for (n = 0; n < 9; n += 2) {
        for (m = 0; m < 22; m += 5) {
            move(n, m);
            addch('+');
            refresh();
        }
    }
}

void
draw_digital()
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            draw_one(y, x);
}

void
draw_one(int y, int x)
{
    int num, dig;
    char tmp;

    num = boxes[y][x];
    for (int i = 3; i >= 0; i--) {
        dig = num % 10;
        num /= 10;
        tmp = dig? dig + '0': 0x20;
        move((y << 1) + 1, 5 * x + 1 + i);
        addch(tmp);
    }
    refresh();
}

void
play()
{
    int x, y, i, j, new_x, new_y, temp;
    int move;
    char ch;

    while(1) {
        move = 0;
        ch = getch();
        switch(ch) {
            case 97:    //左移  a
            case 104:   // h
            case 68:    // 左移方向键
                for (y = 0; y < 4; y++) {
                    // 清除空格
                    for (x = i = 0; x < 4; x++) {
                        if (boxes[y][x] != 0) {
                            boxes[y][i++] = boxes[y][x];
                        }
                        if (0 < i && i < 4)
                            move = 1;
                    }
                    // 合并相同数字
                    for (x = j = 0; x < i; x++) {
                        if (x < i - 1 && boxes[y][x] == boxes[y][x + 1]) {
                            boxes[y][j++] = boxes[y][x++] << 1;
                            move = 1;
                        }
                        else {
                            boxes[y][j++] = boxes[y][x];
                        }
                    }
                    // 后面归零
                    while (j < 4)
                        boxes[y][j++] = 0;
                }
                break;
            case 100:   //右移 d
            case 108:   // l
            case 67:    //右移方向键
                for (y = 0; y < 4; y++) {
                    // 清除空格
                    for (x = i = 3; x >= 0; x--) {
                        if (boxes[y][x] != 0) {
                            boxes[y][i--] = boxes[y][x];
                        }
                        if (0 <= i && i < 3)
                            move = 1;
                    }
                    // 合并相同数字
                    for (x = j = 3; x > i; x--) {
                        if (x > i + 1 && boxes[y][x] == boxes[y][x - 1]) {
                            boxes[y][j--] = boxes[y][x--] << 1;
                            move = 1;
                        }
                        else {
                            boxes[y][j--] = boxes[y][x];
                        }
                    }
                    // 后面归零
                    while (j >= 0)
                        boxes[y][j--] = 0;
                }
                break;
            case 119:   //上移 w
            case 107:   //k
            case 65:    //上移方向键
                for (x = 0; x < 4; x++) {
                    // 清除空格
                    for (y = i = 0; y < 4; y++) {
                        if (boxes[y][x] != 0) {
                            boxes[i++][x] = boxes[y][x];
                        }
                        if (0 < i && i < 4)
                            move = 1;
                    }
                    // 合并相同数字
                    for (y = j = 0; y < i; y++) {
                        if (y < i - 1 && boxes[y][x] == boxes[y + 1][x]) {
                            boxes[j++][x] = boxes[y++][x] << 1;
                            move = 1;
                        }
                        else {
                            boxes[j++][x] = boxes[y][x];
                        }
                    }
                    // 后面归零
                    while (j < 4)
                        boxes[j++][x] = 0;
                }
                break;
            case 115:   //下移 s
            case 106:   //j
            case 66:    //下移方向键
                for (x = 0; x < 4; x++) {
                    // 清除空格
                    for (y = i = 3; y >= 0; y--) {
                        if (boxes[y][x] != 0) {
                            boxes[i--][x] = boxes[y][x];
                        }
                        if (0 <= i && i < 3)
                            move = 1;
                    }
                    // 合并相同数字
                    for (y = j = 3; y > i; y--) {
                        if (y > i + 1 && boxes[y][x] == boxes[y - 1][x]) {
                            boxes[j--][x] = boxes[y--][x] << 1;
                            move = 1;
                        }
                        else {
                            boxes[j--][x] = boxes[y][x];
                        }
                    }
                    // 后面归零
                    while (j >= 0)
                        boxes[j--][x] = 0;
                }
                break;
            case 'Q':
            case 'q':
                game_over();
                break;
            default:
                continue;
                break;
        }
        if (empty <= 0)
            game_over();
        if (move == 1) {
            do{
                new_x = rand() % 4;
                new_y = rand() % 4;
            }while(boxes[new_y][new_x] != 0);

            cnt_value(&new_y, &new_x);

            do {
                temp = rand() % 4;
            }while(temp == 0 || temp == 2);
            boxes[new_y][new_x] = temp + 1;
            empty--;
        }
        draw_digital();
    }
}

// 统计(y, x)对应的格子周围一圈的空格的个数
int cnt_one(int y, int x)
{
    int value = 0;

    if(y - 1 > 0)  
        boxes[y-1][x] ? 0 : value++;
    if(y + 1 < 4)
        boxes[y+1][x] ? 0 : value++;
    if(x - 1 >= 0)
        boxes[y][x-1] ? 0 : value++;
    if(x + 1 < 4)
        boxes[y][x+1] ? 0 : value++;
    if(y - 1 >= 0 && x - 1 >= 0)
        boxes[y-1][x-1] ? 0 : value++;
    if(y - 1 >= 0 && x + 1 < 4)
        boxes[y-1][x+1] ? 0 : value++;
    if(y + 1 < 4 && x - 1 >= 0)
        boxes[y+1][x-1] ? 0 : value++;
    if(y + 1 < 4 && x + 1 < 4)
        boxes[y+1][x+1] ? 0 : value++;

    return value;
}

void cnt_value(int *new_y, int *new_x)
{
    int max_x, max_y, x, y, value;
    int max = 0;

    max = cnt_one(*new_y, *new_x);
    for(y = 0; y < 4; y++)
        for(x = 0; x < 4; x++) 
        {
            // 如果(y, x)对应的空格为空
            if(!boxes[y][x]) 
            {
                // 优先选取周围空格最多的空格展示新数字
                value = cnt_one(y, x);
                if(value > max && old_y != y && old_x != x) 
                {  
                    // 避免在同一位置反复出现新数字
                    *new_y = y;
                    *new_x = x;
                    old_x = x;
                    old_y = y;
                    break;
                }
            }
        }
}

int game_over()
{
    endwin();
    exit(0);
}

int
main(int argc, char *argv[])
{
    init();
    play();
    endwin();

    return 0;
}
