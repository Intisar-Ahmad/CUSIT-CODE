#include <iostream>//For basic
#include <string>//For String Operations
#include <conio.h>//for _getch() and _kbhit()
#include <windows.h>//for console manipulation functions
#include <ctime>//for random number seeding
#include<stdlib.h>//for srand & rand
#include <vector>//for vectors
#include <math.h>//for Floor() and max()

using namespace std;


//Helper Function
void gotoXY(int x, int y)
{
    COORD coord;//COORD Struct defines screen coordinates
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//moves the cursor to (x,y)
}


class SpaceShooter
{
private:
    int x, y;//Players position
    int width, height;//Game's boundaries
    bool GameOver;//Game's State Flag
    int score;
    int lives;

    struct coordinate
    {
        int x, y;//Struct to represnt the coordinates of bullets and enemies
    };

    vector<coordinate> bullets;
    vector<coordinate> enemies;

public:
    SpaceShooter(int width, int height) {
        this->width = width;
        this->height = height;
        this->x = width/2;
        this->y = height - 2;
        this->score = 0;
        this->GameOver = false;
        this->lives = 3;
    }

    void drawPlayer()
    {
        gotoXY(x, y);
        cout << "<^>";
    }

    

    void moveLeft()
    {
        if (x > 1)
        {
            x--;
        }
    }

    void moveRight()
    {
        if (x < width - 3)
        {
            x++;
        }
    }

    void shoot()
    {
        bullets.push_back({x + 1, y - 1}); // Shoot from the center of the player
    }

    void drawBullets()
    {
        for (int i = 0; i < bullets.size(); i++)
        {
            gotoXY(bullets[i].x, bullets[i].y);
            cout << ".";
        }
    }
 
    void moveBullets()
    {
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].y--;
            bool bulletHit = false;

            for (int j = 0; j < enemies.size(); j++)
            {
                if (bullets[i].x == enemies[j].x && bullets[i].y == enemies[j].y)
                {
                    // Bullet hits enemy
                    bullets.erase(bullets.begin() + i);
                    enemies.erase(enemies.begin() + j);
                    score += 10;
                    bulletHit = true;
                    break; // Exit the enemy loop after a hit
                }
            }

            if (bulletHit)
            {
                i--;  // Adjust the index since we removed a bullet
                continue;  // Skip the rest of the bullet processing
            }

            // Remove bullets that go off the screen
            if (bullets[i].y < 1)
            {
                bullets.erase(bullets.begin() + i);
                i--;  // Adjust the index since we removed a bullet
            }
        }
    }

    void drawEnemies()
    {
        for (int i = 0; i < enemies.size(); i++)
        {
            gotoXY(enemies[i].x, enemies[i].y);
            cout << "V";
        }
    }

    void moveEnemies()
    {
        for (int i = enemies.size() - 1; i >= 0; i--)  // Start from the last enemy
        {
            enemies[i].y++;
            if ((enemies[i].x == x && enemies[i].y == y) || 
                (enemies[i].x == x + 1 && enemies[i].y == y) || 
                (enemies[i].x == x + 2 && enemies[i].y == y))
            {
                // Player collides with an enemy
                lives--;
                enemies.erase(enemies.begin() + i); // Remove the enemy
                if (lives <= 0) 
                {
                    GameOver = true;
                }
            }
            if (enemies[i].y >= height - 1)
            {
                enemies.erase(enemies.begin() + i);
            }
        }
    }

    void generateEnemies(float level)
    {
        float spawnRate = level*1.5;
        int roundedSpawnRate = static_cast<int>(floor(spawnRate));
        if ((rand() % (100 - 1 + 1) + 1) <= roundedSpawnRate)
        {
            int enemyX = rand() % ((width - 2) - 1) + 1;
            enemies.push_back({enemyX, 1});
        }
    }

    bool isGameOver() const
    {
        return GameOver;
    }

    int getScore() const
    {
        return score;
    }

    int getLives() const
    {
        return lives;
    }
};


int main()
{
    system("mode con: lines=40 cols=40"); 
 
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorinfo;
    cursorinfo.bVisible = false;
    cursorinfo.dwSize = 1;
    SetConsoleCursorInfo(hconsole, &cursorinfo);
    srand(time(0));
    int width = 40, height = 40;
    SpaceShooter game(width, height);

    cout << "Instructions" << endl;
    cout << "************" << endl;
    cout << "Use left and right keys to move" << endl;
    cout << "Press esc to exit" << endl;
    cout << "Press spacebar to fire" << endl;

    cout << "Please enter any key" << endl;
     _getch();

    float level = 1;
    while (!game.isGameOver())
    {
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 75) // Left arrow key
            {
                game.moveLeft();
            }
            else if (ch == 77) // Right arrow key
            {
                game.moveRight();
            }
            else if (ch == ' ') // Spacebar to shoot
            {
                game.shoot();
            }
            else if (ch == 27) // Escape key to exit
            {
                break;
            }
        }

        // Game logic
        game.generateEnemies(level);
        game.drawPlayer();
        game.drawBullets();
        game.drawEnemies();
        game.moveEnemies();
        game.moveBullets();
        level += 0.25; // Increase level as time passes

        // Update speed/difficulty
        if (level > 20)
        {
            
            level = 20; // Max level cap
        }

        Sleep(100 - static_cast<int>(level)); // Speed up the game as level increases

        system("cls");
 

        // Display score and lives
        gotoXY(1, height - 2);
        cout << "Score: " << game.getScore();
        gotoXY(1, height - 1);
        cout << "Lives: " << game.getLives();
    }

    gotoXY(width / 2 - 5, height / 2);
   
    cout << "Game Over" << endl;
    gotoXY(width / 2 - 7, height / 2 + 1);
    cout << "Score: " << game.getScore() << endl;
    cout << "Press Any key To continue...";
    char end = _getch();
    return 0;
}
