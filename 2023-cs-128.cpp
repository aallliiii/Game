#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

void level1();
void level2();
void level3();
void info();
void descrp();
void maze();

void logo();
void controlmenu();
int arrow(int increase, int size, int arrowx, int arrowy);
void printmainmenu();
void printLevels();
void selectLevel(int level);
void winner();
void header();
void gotoxy(int x, int y);
char getcharAtxy(short int x, short int y);

void printspaceship();
void erasespaceship();
void viewscore();
void moveplayerleft();
void moveplayerright();
void moveplayerup();
void moveplayerdown();

void printenemy1();
void eraseenemy1();
void printenemy2();
void eraseenemy2();
void printenemy3();
void eraseenemy3();
void printenemy4();
void eraseenemy4();
void printenemy5();
void eraseenemy5();
void plane();
void moveenemy1();
void moveenemy2();
void moveenemy3();
void moveenemy4();
void moveenemy5();

void createBullet();
void movebullet();
void printbullet(int x, int y);
void erasebullet(int x, int y);
void makebulletInactive(int index);
void deletebullet(int index);
void bulletcollisionwidenemy3();


void gameover();

void addscore();
void updatescore();

void bulletcollisionwidenemy1();
void loselife();
void updatelives();
void bulletcollisionwidenemy2();

void AssignScoreLevelOne();
void AssignScoreLevelTwo();
void AssignScoreLevelThree();
int arraySize(string size[]);
char enemyChar1 = 23;
char enemyChar2 = 6;
int PlayerX = 5;
int PlayerY = 30;
int Enemy1X = 20;
int Enemy1Y = 26;
int Enemy2X = 108;
int Enemy2Y = 2;
int Enemy3X = 140;
int Enemy3Y = 20;
int Enemy4X = 76;
int Enemy4Y = 16;
int Enemy5X = 50;
int Enemy5Y = 10;
char bulletshape = 178;
int score = 0;
int gameWidth = 150;
int totalWidth = 180;
int height = 40;

int lives = 3;
int bulletcount = 0;
bool run = true;
string enemydirection = "down";

int bullet_x[1000];
int bullet_y[1000];
bool bulletValue[1000];
string levelOne[1000];
string levelTwo[1000];
string levelThree[1000];
int one = 0;
int two = 0;
int three = 0;
string fileLevel1 = "levelOneScore.txt";
string filelevel2 = "levelTwoScore.txt";
string filelevel3 = "levelThreeScore.txt";

char player[7][13] = {{' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', '/', ' ', '\\', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', '/', ' ', '_', ' ', '\\', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', '/', ' ', ' ', '_', ' ', ' ', '\\', ' ', ' ', ' '},
                      {' ', '_', '/', ' ', ' ', ' ', '_', ' ', ' ', ' ', '\\', '_', ' '},
                      {'|', '_', '_', '_', '_', '_', ' ', '_', '_', '_', '_', '_', '|'},
                      {' ', ' ', ' ', ' ', ' ', '\\', '_', '/', ' ', ' ', ' ', ' '}};

char enemy2[5][5] = {{' ', '_', '_', '_', ' '},
                     {'[', '_', '_', '0', ']'},
                     {'|', '_', '_', '_', '|'},
                     {' ', '/', ' ', '\\', ' '},
                     {'.', '~', '.', '~', '.'}};

char enemy3[4][4] = {{'_', '^', '^', '_'},
                     {'*', '*', '*', '*'},
                     {'*', '*', '*', '*'},
                     {'.', '*', '*', '.'}};

char enemy4[6][7] = {{enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2},
                     {enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2},
                     {enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2},
                     {enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2},
                     {enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2, enemyChar2},
                     {' ', ' ', '^', '-', '^', ' ', ' '}};

char enemy5[4][4] = {{enemyChar1, enemyChar1, enemyChar1, enemyChar1},
                     {enemyChar1, enemyChar1, enemyChar1, enemyChar1},
                     {enemyChar1, enemyChar1, enemyChar1, enemyChar1},
                     {' ', '_', '_', ' '}};

char enemy1[5][7] = {
    {' ', ' ', '_', '_', '_', ' ', ' '},
    {' ', '/', '_', '_', '0', '\\', ' '},
    {'/', '_', '-', '_', '-', '_', '\\'},
    {'/', ' ', ' ', ' ', ' ', ' ', '\\'},
    {'_', '.', '~', '.', '~', '.', '_'}};
main()
{
    AssignScoreLevelOne();
    AssignScoreLevelTwo();
    AssignScoreLevelThree();
    one = arraySize(levelOne);
    two = arraySize(levelTwo);
    three = arraySize(levelThree);

    header();
    Sleep(200);

    int level = 0;

    while (run)
    {
        int select = 0;
        system("cls");
        plane();
        logo();
        printmainmenu();
        select = arrow(1, 4, 28, 21);
        if (select == 1)
        {
            system("Cls");
            plane();
            logo();
            printLevels();
            level = arrow(1, 3, 28, 21);
            selectLevel(level);
        }

        else if (select == 2)
        {
            system("cls");
            plane();
            info();
            getch(); // wait for user input before going back to main screen
        }
        else if (select == 3)
        {
            system("cls");
            plane();
            viewscore();
        }
        else if (select == 4)
        {
            system("Cls");
            break;
        }
    }
}

void level1()
{

    system("cls");
    descrp();
    plane();
    getch();
    system("cls");
    maze();
    controlmenu();
    updatescore();
    updatelives();
    printspaceship();
    printenemy1();
    printenemy2();
    fstream levelOneScore;

    levelOneScore.open(fileLevel1, ios::app);

    while (1)
    {

        moveenemy1();
        moveenemy2();

        if (GetAsyncKeyState(VK_LEFT))
        {

            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {

            moveplayerright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveplayerup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveplayerdown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            createBullet();
        }

        if (run == false)
        {
            system("cls");
            gameover();
            plane();
            cin.get();
            levelOne[one] = to_string(score);
            levelOneScore << levelOne[one] << endl;
            one++;
            levelOneScore.close();
            break;
        }
        movebullet(); // to move bullets
        bulletcollisionwidenemy1();
        
        if (score >= 20)
        {

            run = false;
            system("Cls");
            winner();
            plane();
            cin.get();
            levelOne[one] = to_string(score);
            levelOneScore << levelOne[one] << endl;
            one++;
            levelOneScore.close();
            break;
        }
        Sleep(70);
    }
}
void level2()
{

    system("cls");
    descrp();
    plane();
    getch();
    system("cls");
    maze();
    controlmenu();
    updatescore();
    updatelives();
    printspaceship();
    printenemy1();
    printenemy2();
    printenemy3();
    fstream levelTwoScore;

    levelTwoScore.open(filelevel2, ios::app);

    while (1)
    {

        moveenemy1();
        moveenemy2();
        moveenemy3();

        if (GetAsyncKeyState(VK_LEFT))
        {

            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {

            moveplayerright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveplayerup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveplayerdown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            createBullet();
        }

        if (run == false)
        {
            system("cls");
            gameover();
            plane();
            cin.get();
            levelTwo[two] = to_string(score);
            levelTwoScore << levelTwo[two] << endl;
            two++;
            levelTwoScore.close();
            break;
        }
        movebullet(); // to move bullets
        bulletcollisionwidenemy2();
         
        if (score >= 20)
        {

            run = false;
            system("Cls");
            winner();
            plane();
            cin.get();
            levelTwo[two] = to_string(score);
            levelTwoScore << levelTwo[two] << endl;
            two++;
            levelTwoScore.close();
            break;
        }
        Sleep(70);
    }
}
void level3()
{

    system("cls");
    descrp();
    plane();
    getch();
    system("cls");
    maze();
    controlmenu();
    updatescore();
    updatelives();
    printspaceship();
    printenemy1();
    printenemy2();
    printenemy3();
    printenemy4();
    printenemy5();
    fstream levelThreeScore;

    levelThreeScore.open(filelevel3, ios::app);

    while (1)
    {

        moveenemy1();
        moveenemy2();
        moveenemy3();
        moveenemy4();
        moveenemy5();

        if (GetAsyncKeyState(VK_LEFT))
        {

            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {

            moveplayerright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveplayerup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveplayerdown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            createBullet();
        }

        if (run == false)
        {
            system("cls");
            gameover();
            plane();
            cin.get();
            levelThree[three] = to_string(score);
            levelThreeScore << levelThree[three] << endl;
            three++;
            levelThreeScore.close();
            break;
        }
        movebullet(); // to move bullets
        bulletcollisionwidenemy3();
        
        if (score >= 20)
        {
            run = false;
            system("Cls");
            winner();
            plane();
            cin.get();
            levelThree[three] = to_string(score);
            levelThreeScore << levelThree[three] << endl;
            three++;
            levelThreeScore.close();
            break;
        }
        Sleep(70);
    }
}

void moveplayerleft()
{

    char next = getcharAtxy(PlayerX - 1, PlayerY);
    if (next == ' ')
    {
        erasespaceship();
        PlayerX--;
        printspaceship();
    }
}
void moveplayerright()
{

    char next = getcharAtxy(PlayerX + 13, PlayerY);
    if (next == ' ')
    {
        erasespaceship();
        PlayerX++;
        printspaceship();
    }
}
void moveplayerup()
{

    char next = getcharAtxy(PlayerX, PlayerY - 1);
    if (next == ' ')
    {
        erasespaceship();
        PlayerY--;
        printspaceship();
    }
}
void moveplayerdown()
{

    char next = getcharAtxy(PlayerX, PlayerY + 7);
    if (next == ' ')
    {
        erasespaceship();
        PlayerY++;
        printspaceship();
    }
}

void createBullet()
{
    bullet_x[bulletcount] = PlayerX + 6;
    bullet_y[bulletcount] = PlayerY - 1;
    bulletValue[bulletcount] = true;
    printbullet(bullet_x[bulletcount], bullet_y[bulletcount]);

    bulletcount++;
}
void movebullet()
{

    for (int x = 0; x < bulletcount; x++)
    {
       
            char next = getcharAtxy(bullet_x[x], bullet_y[x] - 1);
            if (next == ' ')
            {
                erasebullet(bullet_x[x], bullet_y[x]);
                bullet_y[x] = bullet_y[x] - 1;
                printbullet(bullet_x[x], bullet_y[x]);
            }
            else // remove the bullets
            {
                erasebullet(bullet_x[x], bullet_y[x]);
                makebulletInactive(x);
                deletebullet(x);
            
        }
    }
}
void printbullet(int x, int y)
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 4);
    gotoxy(x, y);
    cout << bulletshape;
    SetConsoleTextAttribute(c, 6);
}
void erasebullet(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}
void makebulletInactive(int index)
{
    bulletValue[index] = false;
}
void deletebullet(int index)
{
    for (int i = index; i < bulletcount; i++)
    {
        bullet_x[i] = bullet_x[i + 1];
        bullet_y[i] = bullet_y[i + 1];
    }
    bulletcount--;
}

void moveenemy1()
{

    if (enemydirection == "down")
    {
        char next = getcharAtxy(Enemy1X, Enemy1Y + 5);
        if (next == ' ')
        {
            eraseenemy1();
            Enemy1Y++;
            printenemy1();
        }
        if (next == '*')
        {
            eraseenemy1();
            Enemy1Y = 1;
            printenemy1();
        }
        for (int i = 0; i < 6; i++)
        {
            next = getcharAtxy(Enemy1X + i, Enemy1Y + 5);
            if (next == '_' || next == '\\' || next == '/' || next == '|')
            {

                loselife();
                updatelives();
            }
        }
    }
}
void moveenemy2()
{

    if (enemydirection == "down")
    {
        char next = getcharAtxy(Enemy2X, Enemy2Y + 5);
        if (next == ' ')
        {
            eraseenemy2();
            Enemy2Y++;
            printenemy2();
        }
        if (next == '*')
        {
            eraseenemy2();
            Enemy2Y = 4;
            printenemy2();
        }
        for (int i = 0; i < 6; i++)
        {
            next = getcharAtxy(Enemy2X + i, Enemy2Y + 5);
            if (next == '_' || next == '\\' || next == '/' || next == '|')
            {
                loselife();
                updatelives();
            }
        }
    }
}
void moveenemy3()

{

    if (enemydirection == "down")
    {
        char next = getcharAtxy(Enemy3X, Enemy3Y + 4);
        if (next == ' ')
        {
            eraseenemy3();
            Enemy3Y++;
            printenemy3();
        }
        if (next == '*')
        {
            eraseenemy3();
            Enemy3Y = 1;
            printenemy3();
        }
        for (int i = 0; i < 6; i++)
        {
            next = getcharAtxy(Enemy3X + i, Enemy3Y + 5);
            if (next == '_' || next == '\\' || next == '/' || next == '|')
            {
                loselife();
                updatelives();
            }
        }
    }
}
void moveenemy4()
{

    if (enemydirection == "down")
    {
        char next = getcharAtxy(Enemy4X, Enemy4Y + 6);
        if (next == ' ')
        {
            eraseenemy4();
            Enemy4Y++;
            printenemy4();
        }
        if (next == '*')
        {
            eraseenemy4();
            Enemy4Y = 1;
            printenemy4();
        }
        for (int i = 0; i < 6; i++)
        {
            next = getcharAtxy(Enemy4X + i, Enemy4Y + 5);
            if (next == '_' || next == '\\' || next == '/' || next == '|')
            {
                loselife();
                updatelives();
            }
        }
    }
}
void moveenemy5()
{

    if (enemydirection == "down")
    {
        char next = getcharAtxy(Enemy5X, Enemy5Y + 4);
        if (next == ' ')
        {
            eraseenemy5();
            Enemy5Y++;
            printenemy5();
        }
        if (next == '*')
        {
            eraseenemy5();
            Enemy5Y = 1;
            printenemy5();
        }
        for (int i = 0; i < 6; i++)
        {
            next = getcharAtxy(Enemy5X + i, Enemy5Y + 5);
            if (next == '_' || next == '\\' || next == '/' || next == '|')
            {
                loselife();
                updatelives();
            }
        }
    }
}

void printspaceship()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 5);
    for (int rows = 0; rows < 7; rows++)
    {
        gotoxy(PlayerX, PlayerY + rows);
        for (int col = 0; col < 13; col++)
        {
            cout << player[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void erasespaceship()
{
    for (int rows = 0; rows < 7; rows++)
    {
        gotoxy(PlayerX, PlayerY + rows);
        for (int col = 0; col < 13; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void printenemy1()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 2);
    for (int rows = 0; rows < 5; rows++)
    {
        gotoxy(Enemy1X, Enemy1Y + rows);
        for (int col = 0; col < 7; col++)
        {
            cout << enemy1[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void eraseenemy1()
{
    for (int rows = 0; rows < 5; rows++)
    {
        gotoxy(Enemy1X, Enemy1Y + rows);
        for (int col = 0; col < 7; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void printenemy2()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 8);
    for (int rows = 0; rows < 5; rows++)
    {
        gotoxy(Enemy2X, Enemy2Y + rows);
        for (int col = 0; col < 5; col++)
        {
            cout << enemy2[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void eraseenemy2()
{
    for (int rows = 0; rows < 5; rows++)
    {
        gotoxy(Enemy2X, Enemy2Y + rows);
        for (int col = 0; col < 5; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void printenemy3()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 11);
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(Enemy3X, Enemy3Y + rows);
        for (int col = 0; col < 4; col++)
        {
            cout << enemy3[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void eraseenemy3()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(Enemy3X, Enemy3Y + rows);
        for (int col = 0; col < 4; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void printenemy4()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 1);
    for (int rows = 0; rows < 6; rows++)
    {
        gotoxy(Enemy4X, Enemy4Y + rows);
        for (int col = 0; col < 7; col++)
        {
            cout << enemy4[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void eraseenemy4()
{
    for (int rows = 0; rows < 6; rows++)
    {
        gotoxy(Enemy4X, Enemy4Y + rows);
        for (int col = 0; col < 7; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void printenemy5()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 7);

    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(Enemy5X, Enemy5Y + rows);
        for (int col = 0; col < 4; col++)
        {
            cout << enemy5[rows][col];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(c, 6);
}
void eraseenemy5()
{
    for (int rows = 0; rows < 4; rows++)
    {
        gotoxy(Enemy5X, Enemy5Y + rows);
        for (int col = 0; col < 4; col++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char getcharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void maze()
{

    for (int i = 0; i < totalWidth; i++)
    {
        cout << "*";
    }

    for (int i = 0; i < totalWidth; i++)
    {
        gotoxy(i, height);
        cout << "*";
    }
    for (int i = 0; i < height; i++)
    {
        gotoxy(0, i);
        cout << "*";
        gotoxy(totalWidth, i);
        cout << "*";
    }
    for (int i = 0; i < height; i++)
    {
        gotoxy(gameWidth, i);
        cout << "-";
    }
}

void logo()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 6);
    gotoxy(0, 4);
    cout << "     _______..______      ___       ______  _______     __    __   __    __  .__   __. .___________. _______ .______      \n"
            "    /       ||   _  \\    /   \\     /      ||   ____|   |  |  |  | |  |  |  | |  \\ |  | |           ||   ____||   _  \\     \n"
            "   |   (----`|  |_)  |  /  ^  \\   |  ,----'|  |__      |  |__|  | |  |  |  | |   \\|  | `---|  |----`|  |__   |  |_)  |    \n"
            "    \\   \\    |   ___/  /  /_\\  \\  |  |     |   __|     |   __   | |  |  |  | |  . `  |     |  |     |   __|  |      /     \n"
            ".----)   |   |  |     /  _____  \\ |  `----.|  |____    |  |  |  | |  `--'  | |  | \\  |     |  |     |  |____ |  |\\  \\----.\n"
            "|_______/    | _|    /__/     \\__\\ \\______||_______|   |__|  |__|  \\______/  |__| \\__|     |__|     |_______|| _| `._____|\n";
}

void gameover()
{

    system("cls");

    cout << "\n\n\t\t\t  ************************************************" << endl;
    cout << "\t\t\t  *              Space Hunter Game               *" << endl;
    cout << "\t\t\t  ************************************************" << endl
         << endl
         << endl;
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 4);
    cout << "\n\n\t\t\t-----------------------------------------------------" << endl;
    cout << "\t\t\t-----------------------Game Over---------------------" << endl;
    cout << "\t\t\t-----------------------------------------------------" << endl
         << endl
         << endl;

    cout << "\t\t\t Your score is : " << score << endl
         << endl;
    SetConsoleTextAttribute(c, 6);

    cout << "\n\n\n\n\n\n\t\t\t\t\t     Press any key to continue." << endl;
}

void controlmenu()
{
    int x = 150;
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 4);
    gotoxy(x + 8, 12);
    cout << "Space Shooter";
    gotoxy(x + 9, 14);
    cout << "-----------";
    gotoxy(x + 9, 16);
    cout << "-----------";
    gotoxy(x + 9, 18);
    cout << "-----------";
    gotoxy(x + 10, 27);
    cout << "Control";
    gotoxy(x + 10, 28);
    cout << "---------";
    gotoxy(x + 4, 29);
    cout << "Right Arrow Key - Right";
    gotoxy(x + 4, 30);
    cout << "Left Arrow Key  - Left";
    gotoxy(x + 4, 31);
    cout << "Upper Arrow Key - Up";
    gotoxy(x + 4, 32);
    cout << "Lower Arrow Key - Down";
    gotoxy(x + 4, 33);
    cout << "Spacebar - Shoot";
    SetConsoleTextAttribute(c, 6);
}

void info()
{
    int x = 30;
    int y = 15;
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    cout << endl
         << endl;
    gotoxy(x + 15, y - 5);
    cout << "***************************" << endl;
    gotoxy(x + 15, y - 4);
    cout << "     Space Shooter Game" << endl;
    gotoxy(x + 15, y - 3);
    cout << "***************************" << endl;
    cout << "\n\n";

    gotoxy(x, y);
    cout << "info" << endl;
    cout << "\n\n";
    gotoxy(x, y + 1);
    cout << "1. Use the arrow keys to move your spaceship left and right." << endl;
    gotoxy(x, y + 2);
    cout << "2. Press the space bar to fire bullets at the enemy spaceships." << endl;
    gotoxy(x, y + 3);
    cout << "3. Avoid getting hit by enemy bullets or colliding with their spaceships." << endl;
    gotoxy(x, y + 4);
    cout << "4. Shoot down as many enemy spaceships as possible to score points." << endl;
    gotoxy(x, y + 5);
    cout << "5. The game will display your score on the right side of the console." << endl;
    gotoxy(x, y + 6);
    cout << "6. Press any key to go back to the main screen." << endl;

    SetConsoleTextAttribute(c, 6);
}

void descrp()
{

    int x, y;
    x = 48;
    y = 3;
    gotoxy(x, y);
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    cout << "WELCOME TO SPACE SHOOTER GAME";
    x = 12;
    y = 5;

    gotoxy(x, y);
    cout << "Welcome to Space Shooter 2.0!";
    gotoxy(x, y + 1);
    cout << "The galaxy is in turmoil as 'The Yincas' continue their onslaught.";
    gotoxy(x, y + 2);
    cout << "It's up to you to defend our solar system from their invasion.";

    gotoxy(x, y + 4);
    cout << "MISSION BRIEFING:";
    gotoxy(x, y + 5);
    cout << "Eliminate the Yincas and their armada to secure our future.";
    gotoxy(x, y + 7);
    cout << "YOUR SHIP:";
    gotoxy(x, y + 8);
    cout << "Pilot the StarFighter spacecraft with agility using arrow keys.";
    gotoxy(x, y + 10);
    cout << "ARMAMENT:";
    gotoxy(x, y + 11);
    cout << "Equip the laser cannon and unleash destruction with SPACEBAR.";

    x = 33;
    y = 20;

    gotoxy(x, y);
    cout << "Ready for action? PRESS ENTER to launch into space!";

    SetConsoleTextAttribute(c, 6);
}

void updatescore()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    gotoxy(gameWidth + 9, 15);
    cout << "  Score: " << score << endl;
    SetConsoleTextAttribute(c, 6);
}

void addscore()
{
    score = score + 5;
}

void updatelives()
{

    gotoxy(gameWidth + 9, 17);
    cout << "  Lives: " << lives << endl;
}
void loselife()
{
    erasespaceship();
    PlayerX = 2;
    gotoxy(PlayerX, PlayerY);
    printspaceship();
    lives--;
    if (lives == 0)
    {
        run = false;
    }
}

int arrow(int increase, int size, int arrowx, int arrowy)

{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    int a = increase;
    int b = 0;
    int menusizeleast = 1;

    int count = 1;
    gotoxy(arrowx, arrowy);
    cout << "----->";
    while (1)
    {
        char c;

        c = _getch();

        if (c == 80 && menusizeleast < size)
        {
            c = 'd';

            menusizeleast = menusizeleast + 1;
        }
        else if (c == 72 && menusizeleast > 1)
        {
            c = 'u';
            menusizeleast -= 1;
        }
        if (c == 'd')
        {
            gotoxy(arrowx, arrowy + b);
            cout << "       ";
            gotoxy(arrowx, arrowy + a);
            cout << "----->";
            a += increase;
            b += increase;
            Sleep(200);
            c = 'b';
            count = count + 1;
        }
        else if (c == 'u')
        {
            a -= increase, b -= increase;
            gotoxy(arrowx, arrowy + a);
            cout << "       ";
            gotoxy(arrowx, arrowy + b);
            cout << "---->";
            Sleep(200);
            c = 'b';
            count = count - 1;
        }

        if (c == 13)
        {

            break;
        }
    }
    Sleep(100);

    SetConsoleTextAttribute(c, 6);
    return count;
}

void printmainmenu()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    gotoxy(40, 21);
    cout << "PLAY";
    gotoxy(40, 22);
    cout << "INSTRUCTIONS";
    gotoxy(40, 23);
    cout << "PRINT PREVIOUS SCORE";
    gotoxy(40, 24);
    cout << "EXIT";
    SetConsoleTextAttribute(c, 6);
}
void printLevels()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    gotoxy(35, 19);
    cout << "SELECT DIFFICULTY...";
    gotoxy(40, 21);
    cout << "BEGINNER";
    gotoxy(40, 22);
    cout << "INTERMEDIATE";
    gotoxy(40, 23);
    cout << "EXPERT";
    SetConsoleTextAttribute(c, 6);
}

void selectLevel(int level)
{
    if (level == 1)
    {
        level1();
    }
    else if (level == 2)
    {
        level2();
    }
    else if (level == 3)
    {
        level3();
    }
}

void winner()
{
    system("cls");

    cout << "\n\n\t\t\t  ************************************************" << endl;
    cout << "\t\t\t  *              Space Hunter Game               *" << endl;
    cout << "\t\t\t  ************************************************" << endl
         << endl
         << endl;
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 10);
    cout << "\n\n\t\t\t-----------------------------------------------------" << endl;
    cout << "\t\t\t-----------------------Winner!!!---------------------" << endl;
    cout << "\t\t\t-----------------------------------------------------" << endl
         << endl
         << endl;

    cout << "\t\t\tCongratulations! You've won the space shooter game!" << endl;
    cout << "\t\t\tYou're the ultimate space conqueror!" << endl;
    SetConsoleTextAttribute(c, 6);
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t     Press any key to continue." << endl;
}

void bulletcollisionwidenemy1()
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (bulletValue[i] == true)
        {
            if (bullet_y[i] == Enemy1Y + 5 && (bullet_x[i] == Enemy1X || bullet_x[i] == Enemy1X + 1 || bullet_x[i] == Enemy1X + 2 || bullet_x[i] == Enemy1X + 3 || bullet_x[i] == Enemy1X + 4 || bullet_x[i] == Enemy1X + 5 || bullet_x[i] == Enemy1X + 6))
            {
                eraseenemy1();
                addscore();
                updatescore();
                Enemy1X = rand() % gameWidth;
                Enemy1Y = 2;

                moveenemy1();
            }
            if (bullet_y[i] == Enemy2Y + 5 && (bullet_x[i] == Enemy2X || bullet_x[i] == Enemy2X + 1 || bullet_x[i] == Enemy2X + 2 || bullet_x[i] == Enemy2X + 3 || bullet_x[i] == Enemy2X + 4))
            {
                eraseenemy2();
                addscore();
                updatescore();

                Enemy2X = rand() % gameWidth;
                Enemy2Y = 10;
                moveenemy2();
            }
        }
    }
}
void bulletcollisionwidenemy2()
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (bulletValue[i] == true)
        {
            if (bullet_y[i] == Enemy1Y + 5 && (bullet_x[i] == Enemy1X || bullet_x[i] == Enemy1X + 1 || bullet_x[i] == Enemy1X + 2 || bullet_x[i] == Enemy1X + 3 || bullet_x[i] == Enemy1X + 4 || bullet_x[i] == Enemy1X + 5 || bullet_x[i] == Enemy1X + 6))
            {
                eraseenemy1();
                addscore();
                updatescore();
                Enemy1X = rand() % gameWidth;
                Enemy1Y = 2;

                moveenemy1();
            }
            if (bullet_y[i] == Enemy2Y + 5 && (bullet_x[i] == Enemy2X || bullet_x[i] == Enemy2X + 1 || bullet_x[i] == Enemy2X + 2 || bullet_x[i] == Enemy2X + 3 || bullet_x[i] == Enemy2X + 4))
            {
                eraseenemy2();
                addscore();
                updatescore();

                Enemy2X = rand() % gameWidth;
                Enemy2Y = 10;
                moveenemy2();
            }
            if (bullet_y[i] == Enemy3Y + 4 && (bullet_x[i] == Enemy3X || bullet_x[i] == Enemy3X + 1 || bullet_x[i] == Enemy3X + 2 || bullet_x[i] == Enemy3X + 3))
            {
                eraseenemy3();
                addscore();
                updatescore();

                Enemy3X = rand() % gameWidth;
                Enemy3Y = 4;
                moveenemy3();
            }
        }
    }
}
void bulletcollisionwidenemy3()
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (bulletValue[i] == true)
        {
            if (bullet_y[i] == Enemy1Y + 5 && (bullet_x[i] == Enemy1X || bullet_x[i] == Enemy1X + 1 || bullet_x[i] == Enemy1X + 2 || bullet_x[i] == Enemy1X + 3 || bullet_x[i] == Enemy1X + 4 || bullet_x[i] == Enemy1X + 5 || bullet_x[i] == Enemy1X + 6))
            {
                eraseenemy1();
                addscore();
                updatescore();
                Enemy1X = rand() % gameWidth;
                Enemy1Y = 2;

                moveenemy1();
            }
            if (bullet_y[i] == Enemy2Y + 5 && (bullet_x[i] == Enemy2X || bullet_x[i] == Enemy2X + 1 || bullet_x[i] == Enemy2X + 2 || bullet_x[i] == Enemy2X + 3 || bullet_x[i] == Enemy2X + 4))
            {
                eraseenemy2();
                addscore();
                updatescore();

                Enemy2X = rand() % gameWidth;
                Enemy2Y = 10;
                moveenemy2();
            }
            if (bullet_y[i] == Enemy3Y + 4 && (bullet_x[i] == Enemy3X || bullet_x[i] == Enemy3X + 1 || bullet_x[i] == Enemy3X + 2 || bullet_x[i] == Enemy3X + 3))
            {
                eraseenemy3();
                addscore();
                updatescore();

                Enemy3X = rand() % gameWidth;
                Enemy3Y = 4;
                moveenemy3();
            }
            if (bullet_y[i] == Enemy4Y + 6 && (bullet_x[i] == Enemy4X || bullet_x[i] == Enemy4X + 1 || bullet_x[i] == Enemy4X + 2 || bullet_x[i] == Enemy4X + 3 || bullet_x[i] == Enemy4X + 4 || bullet_x[i] == Enemy4X + 5 || bullet_x[i] == Enemy4X + 6))
            {
                eraseenemy4();
                addscore();
                updatescore();

                Enemy4X = rand() % gameWidth;
                Enemy4Y = 9;
                moveenemy4();
            }
            if (bullet_y[i] == Enemy5Y + 4 && (bullet_x[i] == Enemy5X || bullet_x[i] == Enemy5X + 1 || bullet_x[i] == Enemy5X + 2 || bullet_x[i] == Enemy5X + 3))
            {
                eraseenemy5();
                addscore();
                // Enemy5X = 90;
                Enemy5X = rand() % gameWidth;
                Enemy5Y = 5;
                updatescore();
                moveenemy5();
            }
        }
    }
}

void header()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    system("Cls");
    int x = 0;
    int y = 2;

    SetConsoleTextAttribute(c, 9);
    Sleep(20);
    gotoxy(x, y);
    cout << "          _____                    _____                    _____                    _____                    _____    \n";
    Sleep(20);
    gotoxy(x, y + 1);
    cout << "         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\   \n";
    Sleep(20);
    gotoxy(x, y + 2);
    cout << "        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\  \n";
    Sleep(20);
    gotoxy(x, y + 3);
    cout << "       /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\ \n";
    Sleep(20);
    gotoxy(x, y + 4);
    cout << "      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\\n";
    Sleep(20);
    gotoxy(x, y + 5);
    cout << "     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\\n";
    Sleep(20);
    gotoxy(x, y + 6);
    cout << "    /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/  \\:::\\    \\        /:::/__\\:::\\    \\\n";
    Sleep(20);
    gotoxy(x, y + 7);
    cout << "    \\:::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\\n";
    SetConsoleTextAttribute(c, 6);
    Sleep(20);
    gotoxy(x, y + 8);
    cout << "  ___\\:::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\\n";
    Sleep(20);
    gotoxy(x, y + 9);
    cout << " /\\   \\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\    \\  /:::/    /   \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\\n";
    Sleep(20);
    gotoxy(x, y + 10);
    cout << "/::\\   \\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    |/:::/  \\:::\\   \\:::\\____\\/:::/____/     \\:::\\____\\/:::/__\\:::\\   \\:::\\____\\\n";
    Sleep(20);
    gotoxy(x, y + 11);
    cout << "\\:::\\   \\:::\\   \\::/    /\\::/    \\:::\\  /:::|____|\\::/    \\:::\\  /:::/    /\\:::\\    \\      \\::/    /\\:::\\   \\:::\\   \\::/    /\n";
    Sleep(20);
    gotoxy(x, y + 12);
    cout << " \\:::\\   \\:::\\   \\/____/  \\/_____/\\:::\\/:::/    /  \\/____/ \\::: \\/:::/    /  \\:::\\    \\      \\/____/  \\:::\\   \\:::\\   \\/____/ \n";
    SetConsoleTextAttribute(c, 9);
    Sleep(20);
    gotoxy(x, y + 13);
    cout << "  \\:::\\   \\:::\\    \\               \\::::::/    /            \\::::::/    /    \\:::\\    \\               \\:::\\   \\:::\\    \\     \n";
    Sleep(20);
    gotoxy(x, y + 14);
    cout << "   \\:::\\   \\:::\\____\\               \\::::/    /              \\::::/    /      \\:::\\    \\               \\:::\\   \\:::\\____\\    \n";
    Sleep(20);
    gotoxy(x, y + 15);
    cout << "    \\:::\\  /:::/    /                \\::/____/               /:::/    /        \\:::\\    \\               \\:::\\   \\::/    /    \n";
    Sleep(20);
    gotoxy(x, y + 16);
    cout << "     \\:::\\/:::/    /                  ~~                    /:::/    /          \\:::\\    \\               \\:::\\   \\/____/     \n";
    Sleep(20);
    gotoxy(x, y + 17);
    cout << "      \\::::::/    /                                        /:::/    /            \\:::\\    \\               \\:::\\    \\         \n";
    Sleep(20);
    gotoxy(x, y + 18);
    cout << "       \\::::/    /                                        /:::/    /              \\:::\\____\\               \\:::\\____\\        \n";
    Sleep(20);
    gotoxy(x, y + 19);
    cout << "        \\::/    /                                         \\::/    /                \\::/    /                \\::/    /        \n";
    Sleep(20);
    gotoxy(x, y + 20);
    cout << "         \\/____/                                           \\/____/                  \\/____/                  \\/____/         \n";
    SetConsoleTextAttribute(c, 4);
    Sleep(50);
    gotoxy(x + 40, y + 23);
    cout << "          _____                    _____                    _____                _____                    _____                    _____          \n";
    Sleep(20);
    gotoxy(x + 40, y + 24);
    cout << "         /\\    \\                  /\\    \\                  /\\    \\              /\\    \\                  /\\    \\                  /\\    \\         \n";
    Sleep(20);
    gotoxy(x + 40, y + 25);
    cout << "        /::\\____\\                /::\\____\\                /::\\____\\            /::\\    \\                /::\\    \\                /::\\    \\        \n";
    Sleep(20);
    gotoxy(x + 40, y + 26);
    cout << "       /:::/    /               /:::/    /               /::::|   |            \\:::\\    \\              /::::\\    \\              /::::\\    \\       \n";
    Sleep(20);
    gotoxy(x + 40, y + 27);
    cout << "      /:::/    /               /:::/    /               /:::::|   |             \\:::\\    \\            /::::::\\    \\            /::::::\\    \\      \n";
    Sleep(20);
    gotoxy(x + 40, y + 28);
    cout << "     /:::/    /               /:::/    /               /::::::|   |              \\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\     \n";
    SetConsoleTextAttribute(c, 6);
    Sleep(20);
    gotoxy(x + 40, y + 29);
    cout << "    /:::/____/               /:::/    /               /:::/|::|   |               \\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\    \n";
    Sleep(20);
    gotoxy(x + 40, y + 30);
    cout << "   /::::\\    \\              /:::/    /               /:::/ |::|   |               /::::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\   \n";
    Sleep(20);
    gotoxy(x + 40, y + 31);
    cout << "  /::::::\\    \\   _____    /:::/    /      _____    /:::/  |::|   | _____        /::::::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\  \n";
    Sleep(20);
    gotoxy(x + 40, y + 32);
    cout << " /:::/\\:::\\    \\ /\\    \\  /:::/____/      /\\    \\  /:::/   |::|   |/\\    \\      /:::/\\:::\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\ \n";
    Sleep(20);
    gotoxy(x + 40, y + 33);
    cout << "/:::/  \\:::\\    /::\\____\\|:::|    /      /::\\___ \\/:: /    |::|   /::\\____\\    /:::/  \\:::\\____\\/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    |\n";
    Sleep(20);
    gotoxy(x + 40, y + 34);
    cout << "\\::/    \\:::\\  /:::/    /|:::|____\\     /:::/    /\\::/    /|::|  /:::/    /   /:::/    \\::/    /\\:::\\   \\:::\\   \\::/    /\\::/   |::::\\  /:::|____|\n";
    Sleep(20);
    gotoxy(x + 40, y + 35);
    cout << " \\/____/ \\:::\\/:::/    /  \\:::\\    \\   /:::/    /  \\/____/ |::| /:::/    /   /:::/    / \\/____/  \\:::\\   \\:::\\   \\/____/  \\/____|:::::\\/:::/    / \n";
    Sleep(20);
    gotoxy(x + 40, y + 36);
    cout << "          \\::::::/    /    \\:::\\    \\ /:::/    /           |::|/:::/    /   /:::/    /            \\:::\\   \\:::\\    \\            |:::::::::/    /  \n";
    Sleep(20);
    gotoxy(x + 40, y + 37);
    cout << "           \\::::/    /      \\:::\\    /:::/    /            |::::::/    /   /:::/    /              \\:::\\   \\:::\\____\\           |::|\\::::/    /   \n";
    SetConsoleTextAttribute(c, 4);
    Sleep(20);
    gotoxy(x + 40, y + 38);
    cout << "           /:::/    /        \\:::\\__/:::/    /             |:::::/    /    \\::/    /                \\:::\\   \\::/    /           |::| \\::/____/    \n";
    Sleep(20);
    gotoxy(x + 40, y + 39);
    cout << "          /:::/    /          \\::::::::/    /              |::::/    /      \\/____/                  \\:::\\   \\/____/            |::|  ~|          \n";
    Sleep(20);
    gotoxy(x + 40, y + 40);
    cout << "         /:::/    /            \\::::::/    /               /:::/    /                                 \\:::\\    \\                |::|   |          \n";
    Sleep(20);
    gotoxy(x + 40, y + 41);
    cout << "        /:::/    /              \\::::/    /               /:::/    /                                   \\:::\\____\\               \\::|   |          \n";
    Sleep(20);
    gotoxy(x + 40, y + 42);
    cout << "        \\::/    /                \\::/____/                \\::/    /                                     \\::/    /                \\:|   |          \n";
    Sleep(20);
    gotoxy(x + 40, y + 43);
    cout << "         \\/____/                  ~~                       \\/____/                                       \\/____/                  \\|___|          \n";
}

void plane()

{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(c, 6);
    gotoxy(110, 0);
    cout << "                                                                                          " << endl;
    gotoxy(110, 1);
    cout << "                                                                                          " << endl;
    gotoxy(110, 2);
    cout << "                                           .   .                                           " << endl;
    gotoxy(110, 3);
    cout << "                                          =..= +                                           " << endl;
    gotoxy(110, 4);
    cout << "                                         -+ =* :*                                          " << endl;
    gotoxy(110, 5);
    cout << "                                        :#. ##- *=                                         " << endl;
    gotoxy(110, 6);
    cout << "                                       .++ -##* =+-                                        " << endl;
    gotoxy(110, 7);
    cout << "                                       ++- #%#%:.+*.                                       " << endl;
    gotoxy(110, 8);
    cout << "                                      +=* +%%%%# +-*                                      " << endl;
    gotoxy(110, 9);
    cout << "                                     +===:%**++#=:+-*                                     " << endl;
    gotoxy(110, 10);
    cout << "                                    -+-* +#***+## *-=+                                    " << endl;
    gotoxy(110, 11);
    cout << "                                   :+:=* %%###*#%:+=:+-                                   " << endl;
    gotoxy(110, 12);
    cout << "                                  .*:+##=%%@*-##%++#+:*:                                  " << endl;
    gotoxy(110, 13);
    cout << "                                  +=+*+%%%%@*:*%%%%+**-+                                  " << endl;
    gotoxy(110, 14);
    cout << "                                  +=+=*@@%@@*:#%#@@*=+=*                                  " << endl;
    gotoxy(110, 15);
    cout << "                                  ++=*%@@@@@+:#@%%@@*==*                                  " << endl;
    gotoxy(110, 16);
    cout << "                                  +=+%@@##@@+:#%+#@@%+=*                                  " << endl;
    gotoxy(110, 17);
    cout << "                                  ++*#@#%%@@+:#%###@%*+*                                  " << endl;
    gotoxy(110, 18);
    cout << "                                  +**%##%%@@*-#%##**#+**                                  " << endl;
    gotoxy(110, 19);
    cout << "                                  =*@*###%@@*=#%*#*+*%*=                                  " << endl;
    gotoxy(110, 20);
    cout << "                                .*%%@####%@@#+#%##***%%%*.                                 " << endl;
    gotoxy(110, 21);
    SetConsoleTextAttribute(c, 4);
    cout << "                              .*%%%%@%%%%%#@#*##%%%%%%%%%%+.                               " << endl;
    gotoxy(110, 22);
    cout << "                       .=*#-.+####%%@#####%#**##*****%%%####+.:**=:                        " << endl;
    gotoxy(110, 23);
    cout << "                     :#%@@%#-####*#%@#%%%#%%*%##*%%*#%%**####=*#@%%#=                      " << endl;
    gotoxy(110, 24);
    cout << "                    :%@@%##%=***%@#*##%%%#%*=+###%#*##*#@%#**=%*#%%@%:                     " << endl;
    gotoxy(110, 25);
    cout << "                    #*#####@+%#*===+######%#+*#%%%%%%#+++==++*@%%%%#*%                     " << endl;
    gotoxy(110, 26);
    cout << "                   .%##%###%*+++++++%%%%%%%#**#%%%%*##*==-=+**@#####*#-                    " << endl;
    gotoxy(110, 27);
    cout << "                   =%###***%#*+====*%%%%%%%#+*#%%%%*##*==-==+*@##%##*#*++-                 " << endl;
    gotoxy(110, 28);
    cout << "               .-++###%##**@*++====##%%@@%%#+*#%%%%*##*=====+*@%%@@%%%#*=-==-:             " << endl;
    gotoxy(110, 29);
    cout << "            .=++==*%%%@@%%#@*+=====*%%#%%#%%+*%####*##*===++*@%%@@%%%#**+=--===-          " << endl;
    gotoxy(110, 30);
    cout << "         -=+=--=+**#%%@@%%#@*++===#%%%#####%*#%*##**%%%#++**@%%%@%%%#*+++=------:        " << endl;
    gotoxy(110, 31);
    cout << "       :=-----=++**%%%@@%%%@**+*#%%%%@%#%%##**%#%##%%%%%%%%%#@%######*++=-------:=        " << endl;
    gotoxy(110, 32);
    cout << "       +-------==++#%######%*#%%%%%%%@%#%%##**%#%##%%%%%%%%%#@%######*++=-------:=        " << endl;
    gotoxy(110, 33);
    cout << "       *-==+++++++++%####*##===-----:@%###%#+*%%#%#%%-::----==#%####*#+++++++++==-+        " << endl;
    SetConsoleTextAttribute(c, 5);
    gotoxy(110, 34);
    cout << "       :::...       +####*%:     .:=##%###@%**%%#@#%**-:      :@####*+        ..:::        " << endl;
    gotoxy(110, 35);
    cout << "                    :%%###*   .-=+*#*##%##@%**%%#@@%+*#*=--    *%%%##:                     " << endl;
    gotoxy(110, 36);
    cout << "                     -****:   -=++++######%%*#@%#@@@*+==+==:   .****=                     " << endl;
    gotoxy(110, 37);
    cout << "                              -=--=*#**%%%%%+*%%%@@%##+---=:                              " << endl;
    gotoxy(110, 38);
    cout << "                                   :+*+*%%%  #%%%***+.                                   " << endl;
    gotoxy(110, 39);
    cout << "                                    =*+=#**:  -*#*-+*=                                    " << endl;
    gotoxy(110, 40);
    cout << "                                    :+*+-.      --=+*.                                    " << endl;
    gotoxy(110, 41);
    cout << "                                     =*+=-     :--+*+.                                    " << endl;
    gotoxy(110, 42);
    cout << "                                     :+*+-:   .--=**:                                     " << endl;
    gotoxy(110, 43);
    cout << "                                     .+*+=-: .---+*=                                      " << endl;
    gotoxy(110, 44);
    cout << "                                      -**+--:---=*+:                                      " << endl;
    gotoxy(110, 45);
    cout << "                                      .+*+=-----+*+                                       " << endl;
    gotoxy(110, 46);
    cout << "                                       :+*+=---+*+:                                       " << endl;
    gotoxy(110, 47);
    cout << "                                        -+*+--=+*=.                                       " << endl;
    gotoxy(110, 48);
    SetConsoleTextAttribute(c, 10);
    cout << "                                         -*+==+*+.                                        " << endl;
    gotoxy(110, 49);
    cout << "                                         .+*++*+-                                         " << endl;
    gotoxy(110, 50);
    cout << "                                          :+**+=.                                         " << endl;
    gotoxy(110, 51);
    cout << "                                           .:--                                           " << endl;
    SetConsoleTextAttribute(c, 6);
}

void AssignScoreLevelOne()
{
    int idx = 0;
    fstream levelOneScore;
    levelOneScore.open(fileLevel1, ios::in);
    string line = "";

    while (!(levelOneScore.eof()))
    {
        line = "";
        getline(levelOneScore, line);
        if (!(line.empty()))
        {

            levelOne[idx] = line;
            idx++;
        }
    }
}

void AssignScoreLevelTwo()
{
    int idx = 0;
    fstream levelTwoScore;
    levelTwoScore.open(filelevel2, ios::in);
    string line = "";
    while (!(levelTwoScore.eof()))
    {
        line = "";
        getline(levelTwoScore, line);
        if (!(line.empty()))
        {

            levelTwo[idx] = line;
            idx++;
        }
    }
}

void AssignScoreLevelThree()
{
    int idx = 0;
    fstream levelThreeScore;
    levelThreeScore.open(filelevel3, ios::in);
    string line = "";
    while (!(levelThreeScore.eof()))
    {
        line = "";
        getline(levelThreeScore, line);
        if (!(line.empty()))
        {

            levelThree[idx] = line;
            idx++;
        }
    }
}

int arraySize(string size[])
{
    int count = 0;

    while (size[count] != "")
    {
        count++;
    }
    return count;
}

void viewscore()
{
    HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
    int b = 2;
    int z = 2;
    int f = 2;
    system("Cls");
    logo();
    int x = 45;
    int a = 0;
    int y = 14;
    gotoxy(x - 20, y);
    cout << "SCORES";
    gotoxy(x + 9, y);
    cout << "LEVEL 1";
    gotoxy(x + 38, y);
    cout << "LEVEL 2";
    gotoxy(x + 67, y);
    cout << "LEVEL 3";
    SetConsoleTextAttribute(c, 4);
    for (int i = 0; i < one; i++)
    {

        gotoxy(x + 9, y + b);
        cout << levelOne[i];

        b++;
    }
    for (int d = 0; d < two; d++)
    {
        gotoxy(x + 38, y + z);
        cout << levelTwo[d];
        z++;
    }

    for (int l = 0; l < three; l++)

    {
        gotoxy(x + 67, y + f);
        cout << levelThree[l];
        f++;
    }

    SetConsoleTextAttribute(c, 6);

    getch();
}
