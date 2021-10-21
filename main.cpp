#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <string>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;


///Collision when Ghost is moving right
bool CollisionRight(Sprite S1, RectangleShape R1, bool Right)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Right == true)
    {
        return true;
    }

    else
    {
        return false;
    }

}
///Collision when Ghost is moving left
bool CollisionLeft(Sprite S1, RectangleShape R1, bool Left)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Left == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}
///Collision when Ghost is moving up
bool CollisionUp(Sprite S1, RectangleShape R1, bool Up)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Up == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}
///Collision when Ghost is moving down
bool CollisionDown(Sprite S1, RectangleShape R1, bool Down)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Down == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

///Ghost colliding with entrance after leaving lair
bool CollisionWall(Sprite S1, RectangleShape R1, bool Down)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Down == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

///Collision when he is moving right
bool CollisionRight2(Sprite S1, RectangleShape R1, bool Right, RectangleShape R2)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Right == true)
    {
        return true;
    }

    if (S1.getGlobalBounds().intersects(R2.getGlobalBounds()) && Right == true)
    {
        return true;
    }

    else
    {
        return false;
    }

}
///Collision when he is moving left
bool CollisionLeft2(Sprite S1, RectangleShape R1, bool Left, RectangleShape R2)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Left == true)
    {
        return true;
    }

    if (S1.getGlobalBounds().intersects(R2.getGlobalBounds()) && Left == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}
///Collision when he is moving up
bool CollisionUp2(Sprite S1, RectangleShape R1, bool Up, RectangleShape R2)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Up == true)
    {
        return true;
    }

    if (S1.getGlobalBounds().intersects(R2.getGlobalBounds()) && Up == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}
///Collision when he is moving down
bool CollisionDown2(Sprite S1, RectangleShape R1, bool Down, RectangleShape R2)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()) && Down == true)
    {
        return true;
    }

    if (S1.getGlobalBounds().intersects(R2.getGlobalBounds()) && Down == true)
    {
        return true;
    }

    else
    {
        return false;
    }
}

///Fruit - Pacman Collision
bool FruitCollision(Sprite S1, RectangleShape R1)
{
    if (S1.getGlobalBounds().intersects(R1.getGlobalBounds()))
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{
    RenderWindow window(VideoMode(800,600),"SFML Works"); //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    srand(time(0));

    RectangleShape Map;

    RectangleShape Startscreen;
    Startscreen.setSize(Vector2f(753, 552));
    Startscreen.setOrigin(376.5, 276);
    Startscreen.setPosition(400, 300);
    Texture StartscreenTexture;
    StartscreenTexture.loadFromFile("Startscreen.png");
    Startscreen.setTexture(&StartscreenTexture);

    RectangleShape Gameover;
    Gameover.setSize(Vector2f(753, 552));
    Gameover.setOrigin(376.5, 276);
    Gameover.setPosition(400, 300);
    Texture TextGameover;
    TextGameover.loadFromFile("Gameover.png");
    Gameover.setTexture(&TextGameover);


    vector<RectangleShape> barrier;
    Map.setSize(Vector2f(753, 552));
    Map.setPosition(400, 300);
    Map.setOrigin(376.5, 276);
    Texture MapTexture;
    MapTexture.loadFromFile("maps.png");
    Map.setTexture(&MapTexture);
    Sprite Pacman;
    Texture sprites;
    sprites.loadFromFile("pacman.png");
    int texty = 125;
    int counter = 0;
    Pacman.setTexture(sprites);
    Pacman.setPosition(400, 400);
    Pacman.setOrigin(50, 50);
    Pacman.setScale(0.3, 0.3);
    bool Right = false;
    bool Left = false;
    bool Up = false;
    bool Down = false;
    bool move_Right = false;
    bool move_Left = false;
    bool move_Up = false;
    bool move_Down = false;
    bool PacRight = true;
    bool PacLeft = true;
    bool pacdead = false;
    bool collideleft = false;
    bool collideright = false;
    bool collideup = false;
    bool collidedown = false;
    vector<RectangleShape> Paclives;
    int PaclivesX = 650;
    int ScoreCounter = 0;
    int DotScores = 0;
    int DeadX = 1200;
    int DeadY = 800;

    ///Controls Sounds
    ///For Death
    Sound Dead;
    SoundBuffer DeadBuff;
    DeadBuff.loadFromFile("Death.wav");
    Dead.setBuffer(DeadBuff);

    ///For Eating Ghost
    Sound EatGhost;
    SoundBuffer GhostBuff;
    GhostBuff.loadFromFile("Ghost.wav");
    EatGhost.setBuffer(GhostBuff);

    ///For Eating Fruit
    Sound EatFruit;
    SoundBuffer FruitBuff;
    FruitBuff.loadFromFile("Fruit.wav");
    EatFruit.setBuffer(FruitBuff);

    ///Background music
    Sound backs;
    SoundBuffer backsound;
    backsound.loadFromFile("Backgroundmusic.wav");
    backs.setBuffer(backsound);

    ///Controls levels
    float Level = 0.0;
    bool LevelUp = false;
    int LevelX = 100;
    int ActualLevel;
    bool Levelledup = true;
    vector<RectangleShape> Showlevel;

    ///Times
    Time t1;
    Clock c1;
    Time t2;
    Clock c2;

    ///Controlling Power Pellets
    bool RightPower = false;
    bool LeftPower = false;
    bool UpPower = false;
    bool DownPower = false;

    ///Blocks pacman from entering ghost's lair
    RectangleShape borderline;
    borderline.setSize(Vector2f(150, 50));
    borderline.setOrigin(75, 25);
    borderline.setPosition(400, 250);

    ///Ghost Specs
    Sprite Blinky;
    Texture Ghost;
    Ghost.loadFromFile("Ghosts.png");
    Blinky.setTexture(Ghost);
    Blinky.setOrigin(8, 8);
    Blinky.setScale(2, 2);
    Blinky.setPosition(400, 300);
    bool GhostRight = false;
    bool GhostLeft = false;
    bool GhostUp = false;
    bool GhostDown = false;
    bool GhostOutside = false;
    bool Blinkydead = false;
    int Blinkymovex1 = 0;
    int Blinkymovex2 = 0;
    int Blinkymovey1 = 0;
    int Blinkymovey2 = 0;
    int GhostX = 0;
    int Ghostcounter = 0;
    int colourtimer = 0;
    int EatCounter = 0;

    ///Fruit Code
    RectangleShape Fruit;
    Fruit.setSize(Vector2f(50, 50));
    Fruit.setOrigin(25, 25);
    Fruit.setTexture(&Ghost);
    bool Fruits = true;

    ///Powering Up
    bool Powerup = false;

    ///Score
    Text Scores;
    Font fonts;
    fonts.loadFromFile("techno_hideo.ttf");
    Scores.setFont(fonts);
    Scores.setPosition(25, 572.5);
    Scores.setScale(0.75, 0.75);
    int LetterCounter = 0;

    int Pacmovex1 = 0;
    int Pacmovey1 = 0;
    int Pacmovex2 = 2;
    int Pacmovey2 = 2;
    float dotx = 3.0;
    float dotx2 = 5.0;
    int dotsx = 45;
    int dotsy = 45;
    bool gamestart = false;
    bool Gameovers = false;
    char grid[11][15];
    vector<vector<CircleShape> > dots(11, vector<CircleShape>(15));
    ifstream infile;
    infile.open("grid.txt");
    for (int i = 0; i <11; i++)
    {
        for (int j = 0 ; j < 15; j++)
        {
            ///Regular Pellets
            infile>>grid[i][j];
            dots[i][j].setRadius(5.0);
            dots[i][j].setOrigin(5.0,5.0);
            dots[i][j].setPosition(50 + j*50, 50+i*50);

            if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 8 && j == 2) || (i == 8 && j == 1) || (i == 9 && j == 2) || (i == 9 && j == 2) || (i == 4 && j == 1) || (i == 6 && j == 1) || (i == 4 && j == 2) || (i == 5 && j == 2) || (i == 6 && j == 2) || (i == 5 && j == 2) || (i == 9 && j == 1))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if ((i == 1 && j == 6) || (i == 1 && j == 8) || (i == 2 && j == 6) || (i == 2 && j == 7) || (i == 2 && j == 8))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if ((i == 9 && j == 6) || (i == 9 && j == 8) || (i == 8 && j == 6) || (i == 8 && j == 7) || (i == 8 && j == 8))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if ((i == 1 && j == 13) || (i == 1 && j == 12) || (i == 2 && j == 13) || (i == 2 && j == 12))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if ((i == 4 && j == 12) || (i == 4 && j == 13) || (i == 5 && j == 12) || (i == 6 && j == 12) || (i == 6 && j == 13))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if ((i == 8 && j == 12) || (i == 8 && j == 13) || (i == 9 && j == 12) || (i == 9 && j == 13))
            {
                barrier.push_back(RectangleShape(Vector2f(50, 50)));
                barrier.back().setOrigin(25.0, 25.0);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if (i == 5 && j == 5)
            {
                barrier.push_back(RectangleShape(Vector2f(50, 150)));
                barrier.back().setOrigin(25, 75);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if (i == 5 && j == 9)
            {
                barrier.push_back(RectangleShape(Vector2f(50, 150)));
                barrier.back().setOrigin(25, 75);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            if (i == 6 && j == 7)
            {
                barrier.push_back(RectangleShape(Vector2f(250, 50)));
                barrier.back().setOrigin(125, 25);
                barrier.back().setPosition(50 + j*50, 50 + i*50);
            }

            ///Power Pellets
            if (i == 1 && j == 7)
            {
                dots[i][j].setRadius(7.5);
                dots[i][j].setOrigin(7.5, 7.5);
            }

            if (i == 5 && j == 1)
            {
                dots[i][j].setRadius(7.5);
                dots[i][j].setOrigin(7.5, 7.5);
            }

            if (i == 5 && j == 13)
            {
                dots[i][j].setRadius(7.5);
                dots[i][j].setOrigin(7.5, 7.5);
            }

            if (i == 9 && j == 7)
            {
                dots[i][j].setRadius(7.5);
                dots[i][j].setOrigin(7.5, 7.5);
            }
        }
    }
    infile.close();

    backs.play();
    backs.setLoop(false);
    int soundcounter = 0;

    int gridx = 7;
    int gridy = 7;
    int gridx2 = 4;
    int gridy2 = 7;

    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))
        ///the main game loop, exits if someone closes the window
    {
        Event event; ///creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) ///loop that checks for events
        {
            if (event.type == Event::Closed) ///checks if window is closed


            window.close();
        } ///ends the event loop

        window.clear(); ///clears the screen

    soundcounter++;
    backs.setVolume(20);
    EatGhost.setVolume(100);

    if (soundcounter >= 1020)
    {
        backs.play();
        soundcounter = 0;
    }

    if (gamestart == false)
    {
        window.draw(Startscreen);
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            gamestart = true;
            c1.restart();
            c2.restart();
        }
    }

    if (gamestart == true)
    {
            if (pacdead == false)
            {
                ///Places the barriers beneath the background so that the hit collision works with the background
                for (int i = 0; i < barrier.size(); i++)
                {
                    window.draw(barrier[i]);
                }

                ///Draws the blockage for the Ghost's lair
                window.draw(borderline);

                ///Draws the map
                window.draw(Map);

                ///Fruit in the game
                if (LetterCounter >= 40 && LetterCounter <= 65 && Fruits == true)
                {
                    Fruit.setPosition(400, 400);
                    window.draw(Fruit);
                    Fruit.setTextureRect(IntRect((Level*16), 32, 16, 16));

                    if (FruitCollision(Pacman, Fruit) == true)
                    {
                        Fruits = false;
                        ScoreCounter = ScoreCounter + (100*Level);
                        EatFruit.setVolume(100);
                        EatFruit.play();
                        c1.restart();
                    }
                }

                if (Level >= 13.0)
                {
                    ActualLevel = Level + 1;
                    Level = 13.0;
                }

                for (int i = 0; i < Level + 1; i++)
                {
                    Showlevel.push_back(RectangleShape(Vector2f(25, 25)));
                    Showlevel.back().setPosition(LevelX + (i*25), 572.5);
                    Showlevel.back().setTexture(&Ghost);
                    Showlevel.back().setTextureRect(IntRect((i*16), 32, 16, 16));
                }

                cout << Showlevel.size() << endl;

                for (int i = 0; i < Showlevel.size(); i++)
                {
                    window.draw(Showlevel[i]);
                    Showlevel.erase(Showlevel.begin() + i);
                }

                if (Fruits == false && (t1.asSeconds() <= 3.0))
                {
                    Fruit.setTextureRect(IntRect((Level*16.0), 48, 16, 16));
                    window.draw(Fruit);
                }

                ///Used to count the number of dots eaten
                LetterCounter = 0;
                for (int i = 0; i <11; i++)
                {
                    for (int j = 0 ; j < 15; j++)
                    {
                        if (grid[i][j] == 'R')
                        {
                            LetterCounter = LetterCounter + 1;
                        }
                    }
                }

                counter++;
                t1 = c1.getElapsedTime();

                if (LevelUp == true)
                {
                    for (int i = 0; i <11; i++)
                    {
                        for (int j = 0 ; j < 15; j++)
                        {

                            if (grid[i][j] == 'R')
                            {
                                grid[i][j] = 'P';
                            }

                            ///Regular Pellets
                            infile>>grid[i][j];
                            dots[i][j].setRadius(5.0);
                            dots[i][j].setOrigin(5.0,5.0);
                            dots[i][j].setPosition(50 + j*50, 50+i*50);

                            ///Power Pellets
                            if (i == 1 && j == 7)
                            {
                                dots[i][j].setRadius(7.5);
                                dots[i][j].setOrigin(7.5, 7.5);
                            }

                            if (i == 5 && j == 1)
                            {
                                dots[i][j].setRadius(7.5);
                                dots[i][j].setOrigin(7.5, 7.5);
                            }

                            if (i == 5 && j == 13)
                            {
                                dots[i][j].setRadius(7.5);
                                dots[i][j].setOrigin(7.5, 7.5);
                            }

                            if (i == 9 && j == 7)
                            {
                                dots[i][j].setRadius(7.5);
                                dots[i][j].setOrigin(7.5, 7.5);
                            }
                        }
                    }

                    if (Levelledup == true)
                    {
                        Level = Level + 0.5;
                        Levelledup = false;
                        ///Placement of all entities
                        Pacman.setPosition(400, 400);
                        Blinky.setPosition(400, 300);
                        Blinkydead = false;
                        Powerup = false;
                        Right = false;
                        Left = false;
                        Down = false;
                        Up = false;
                        GhostRight = false;
                        GhostLeft = false;
                        GhostDown = false;
                        GhostUp = false;
                        gridx = 7;
                        gridy = 7;
                        gridx2 = 4;
                        gridy2 = 7;
                        GhostOutside = false;
                        LevelUp = false;
                        Fruits = true;
                        DownPower = false;
                        LeftPower = false;
                        RightPower = false;
                        UpPower = false;
                    }
                }

                ///Deals with the score (Bottom left corner)
                ScoreCounter++;
                ScoreCounter = ScoreCounter + DotScores;
                Scores.setString(to_string(ScoreCounter));

                ///Checks if Blinky leaves his lair
                if (Blinky.getPosition().y <= 210)
                {
                    GhostOutside = true;
                }

                ///If outside of his lair, he cannot go back inside until Pacman has either died or moved on to another level
                if (GhostOutside == true && Blinkydead == false)
                {
                    if (CollisionWall(Blinky, borderline, GhostDown) == true)
                    {
                        Blinkymovey2 = 0;
                        Blinky.setPosition(Blinky.getPosition().x, Blinky.getPosition().y - 12.0);
                    }
                }

                ///When blinky dies, checks when he enters his lair so he may revive
                if (grid[gridx2][gridy2] == 'T')
                {
                    Blinkydead = false;
                    Powerup = false;
                }

                if (ScoreCounter == 10000)
                {
                    Paclives.push_back(RectangleShape(Vector2f(25, 25)));
                    Paclives.back().setOrigin(12.5, 12.5);
                    Paclives.back().setTexture(&sprites);
                    Paclives.back().setTextureRect(IntRect(1100, 110, 100, 100));
                    Paclives.back().setPosition(PaclivesX, 582.5);
                    PaclivesX = PaclivesX + 25;
                }
                ///Sets the number of lives for pacman
                if (Paclives.size() == 0)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        Paclives.push_back(RectangleShape(Vector2f(25, 25)));
                        Paclives.back().setOrigin(12.5, 12.5);
                        Paclives.back().setTexture(&sprites);
                        Paclives.back().setTextureRect(IntRect(1100, 110, 100, 100));
                        Paclives.back().setPosition(PaclivesX, 582.5);
                        PaclivesX = PaclivesX + 25;
                    }
                }

                ///Makes Pacman look like he is eating
                Pacman.setTextureRect(IntRect(1100, texty, 100, 100));

                if (counter%10 == 0)
                {
                    texty = texty + 100;
                }

                if (texty == 725)
                {
                    counter = 0;
                    texty = 125;
                }
                ///Uses the collision functions so that Pacman does not go through the barriers
                for (int i = 0; i < barrier.size(); i++)
                {
                    if (CollisionRight2(Pacman, barrier[i], Right, borderline) == true)
                    {
                        Pacmovex1 = 0;
                        Pacman.setPosition(Pacman.getPosition().x - 12.0, Pacman.getPosition().y);

                    }

                    if (CollisionLeft2(Pacman, barrier[i], Left, borderline) == true)
                    {
                        Pacmovex2 = 0;
                        Pacman.setPosition(Pacman.getPosition().x + 12.0, Pacman.getPosition().y);

                    }

                    if (CollisionUp2(Pacman, barrier[i], Up, borderline) == true)
                    {
                        Pacmovey1 = 0;
                        Pacman.setPosition(Pacman.getPosition().x, Pacman.getPosition().y + 12.0);

                    }

                    if (CollisionDown2(Pacman, barrier[i], Down, borderline) == true)
                    {
                        Pacmovey2 = 0;
                        Pacman.setPosition(Pacman.getPosition().x, Pacman.getPosition().y - 12.0);

                    }
                }

                ///Uses the collision functions so that Ghost does not go through the barriers
                for (int i = 0; i < barrier.size(); i++)
                {
                    if (CollisionRight(Blinky, barrier[i], GhostRight) == true)
                    {
                        Blinkymovex1 = 0;
                        Blinky.setPosition(Blinky.getPosition().x - 12.0, Blinky.getPosition().y);

                    }

                    if (CollisionLeft(Blinky, barrier[i], GhostLeft) == true)
                    {
                        Blinkymovex2 = 0;
                        Blinky.setPosition(Blinky.getPosition().x + 12.0, Blinky.getPosition().y);

                    }

                    if (CollisionUp(Blinky, barrier[i], GhostUp) == true)
                    {
                        Blinkymovey1 = 0;
                        Blinky.setPosition(Blinky.getPosition().x, Blinky.getPosition().y + 12.0);

                    }

                    if (CollisionDown(Blinky, barrier[i], GhostDown) == true)
                    {
                        Blinkymovey2 = 0;
                        Blinky.setPosition(Blinky.getPosition().x, Blinky.getPosition().y - 12.0);
                    }
                }

                ///Makes it so Pacman cannot move off of the screen
                if (Pacman.getPosition().x <= 25)
                {
                    Pacman.setPosition(Pacman.getPosition().x + 25.0, Pacman.getPosition().y);
                }

                if (Pacman.getPosition().x >= 775)
                {
                    Pacman.setPosition(Pacman.getPosition().x - 25.0, Pacman.getPosition().y);
                }

                if (Pacman.getPosition().y <= 25)
                {
                    Pacman.setPosition(Pacman.getPosition().x, Pacman.getPosition().y + 25.0);
                }

                if (Pacman.getPosition().y >= 575)
                {
                    Pacman.setPosition(Pacman.getPosition().x, Pacman.getPosition().y - 25.0);
                }

                ///Makes it so Ghost cannot move off of the screen
                if (Blinky.getPosition().x <= 25)
                {
                    Blinky.setPosition(Blinky.getPosition().x + 25.0, Blinky.getPosition().y);
                }

                if (Blinky.getPosition().x >= 775)
                {
                    Blinky.setPosition(Blinky.getPosition().x - 25.0, Blinky.getPosition().y);
                }

                if (Blinky.getPosition().y <= 25)
                {
                    Blinky.setPosition(Blinky.getPosition().x, Blinky.getPosition().y + 25.0);
                }

                if (Blinky.getPosition().y >= 575)
                {
                    Blinky.setPosition(Blinky.getPosition().x, Blinky.getPosition().y - 25.0);
                }

                ///Left Right Up and Down movements
                if (Right == true && Left == false && Up == false && Down == false)
                {
                    Pacman.move(Pacmovex1, 0);
                    Pacman.setRotation(0);
                    Pacman.setScale(0.3, 0.3);
                }


                else if (Left == true && Right == false && Up == false && Down == false)
                {
                    Pacman.move(-Pacmovex2, 0);
                    Pacman.setRotation(-180);
                    Pacman.setScale(0.3, -0.3);
                }

                else if (Up == true && Right == false && Left == false && Down == false)
                {
                    Pacman.move(0, -Pacmovey1);
                    Pacman.setRotation(270);
                    Pacman.setScale(0.3, 0.3);
                }

                else if (Down == true && Up == false && Right == false && Left == false)
                {
                    Pacman.move(0, Pacmovey2);
                    Pacman.setRotation(90);
                    Pacman.setScale(0.3, 0.3);
                }

                ///For when adding the number of points pacman get from food
                ScoreCounter = ScoreCounter - DotScores;
                DotScores = 0;

                ///Makes it so that when he is turning and such, Pacman stays in the middle of the box
                for (int i = 0; i < 11; i++)
                {
                    for (int j = 0; j < 15; j++)
                    {
                        ///Number of points pacman gets from food
                        DotScores = 10*(LetterCounter);

                        if (DotScores == 1140)
                        {
                            LevelUp = true;
                            Levelledup = true;
                            DotScores = 0;
                        }

                        if (Left != true)
                            {
                                if ((Pacman.getPosition().x <= 800)
                                    && (Keyboard::isKeyPressed(Keyboard::Right) == true)
                                    && ((Pacman.getPosition().x) <= (dots[i][j].getPosition().x + dotx))
                                    && (Pacman.getPosition().x >= (dots[i][j].getPosition().x - dotx))
                                    && ((Pacman.getPosition().y) <= (dots[i][j].getPosition().y + dotx))
                                    && ((Pacman.getPosition().y) >= (dots[i][j].getPosition().y - dotx)))
                                {
                                    Right = true;
                                    Pacmovex1 = 2;
                                    Pacmovex2 = 0;
                                    Pacmovey1 = 0;
                                    Pacmovey2 = 0;
                                    Left = false;
                                    Down = false;
                                    Up = false;

                                }
                            }

                            if (Left == true)
                            {
                                if ((Pacman.getPosition().x <= 800) && (Keyboard::isKeyPressed(Keyboard::Right) == true))
                                {
                                    Pacmovex1 = 2;
                                    Pacmovex2 = 0;
                                    Pacmovey1 = 0;
                                    Pacmovey2 = 0;
                                    Left = false;
                                    Right = true;
                                    Down = false;
                                    Up = false;


                                }
                            }

                            if (Right != true)
                            {
                                if (((Pacman.getPosition().x >= 0) && (Keyboard::isKeyPressed(Keyboard::Left) == true)
                                    && ((Pacman.getPosition().x) <= (dots[i][j].getPosition().x + dotx))
                                    && (Pacman.getPosition().x >= (dots[i][j].getPosition().x - dotx))
                                    && ((Pacman.getPosition().y) <= (dots[i][j].getPosition().y + dotx))
                                    && ((Pacman.getPosition().y) >= (dots[i][j].getPosition().y - dotx))))
                                {
                                    Pacmovex2 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovey1 = 0;
                                    Pacmovey2 = 0;
                                    Left = true;
                                    Right = false;
                                    Down = false;
                                    Up = false;


                                }
                            }

                            if (Right == true)
                            {
                                if ((Pacman.getPosition().x >= 0) && (Keyboard::isKeyPressed(Keyboard::Left) == true))
                                {
                                    Pacmovex2 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovey1 = 0;
                                    Pacmovey2 = 0;
                                    Left = true;
                                    Right = false;
                                    Down = false;
                                    Up = false;
                                }
                            }

                            if (Down != true)
                            {
                                if ((Pacman.getPosition().y >= 0) && (Keyboard::isKeyPressed(Keyboard::Up) == true)
                                    && ((Pacman.getPosition().x) <= (dots[i][j].getPosition().x + dotx))
                                    && (Pacman.getPosition().x >= (dots[i][j].getPosition().x - dotx))
                                    && ((Pacman.getPosition().y) <= (dots[i][j].getPosition().y + dotx))
                                    && ((Pacman.getPosition().y) >= (dots[i][j].getPosition().y - dotx)))
                                {
                                    Pacmovey1 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovex2 = 0;
                                    Pacmovey2 = 0;
                                    Up = true;
                                    Left = false;
                                    Down = false;
                                    Right = false;

                                }
                            }

                            if (Down == true)
                            {
                                if ((Pacman.getPosition().y >= 0) && (Keyboard::isKeyPressed(Keyboard::Up) == true))
                                {
                                    Pacmovey1 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovex2 = 0;
                                    Pacmovey2 = 0;
                                    Left = false;
                                    Right = false;
                                    Down = false;
                                    Up = true;
                                }
                            }

                            if (Up != true)
                            {
                                if ((Pacman.getPosition().y <= 600) && (Keyboard::isKeyPressed(Keyboard::Down) == true)
                                    && ((Pacman.getPosition().x) <= (dots[i][j].getPosition().x + dotx))
                                    && (Pacman.getPosition().x >= (dots[i][j].getPosition().x - dotx))
                                    && ((Pacman.getPosition().y) <= (dots[i][j].getPosition().y + dotx))
                                    && ((Pacman.getPosition().y) >= (dots[i][j].getPosition().y - dotx)))
                                {
                                    Pacmovey2 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovex2 = 0;
                                    Pacmovey1 = 0;
                                    Down = true;
                                    Left = false;
                                    Up = false;
                                    Right = false;

                                }
                            }

                            if (Up == true)
                            {
                                if ((Pacman.getPosition().y <= 600) && (Keyboard::isKeyPressed(Keyboard::Down) == true))
                                {
                                    Pacmovey2 = 2;
                                    Pacmovex1 = 0;
                                    Pacmovex2 = 0;
                                    Pacmovey1 = 0;
                                    Left = false;
                                    Right = false;
                                    Down = true;
                                    Up = false;
                                }
                            }


                            ///Ghost Movement
                            if (GhostLeft != true)
                            {
                                if ((Keyboard::isKeyPressed(Keyboard::D) == true)
                                    && ((Blinky.getPosition().x) <= (dots[i][j].getPosition().x + dotx2))
                                    && (Blinky.getPosition().x >= (dots[i][j].getPosition().x - dotx2))
                                    && ((Blinky.getPosition().y) <= (dots[i][j].getPosition().y + dotx2))
                                    && ((Blinky.getPosition().y) >= (dots[i][j].getPosition().y - dotx2)))
                                {
                                    GhostRight = true;
                                    Blinkymovex1 = 2;
                                    Blinkymovex2 = 0;
                                    Blinkymovey1 = 0;
                                    Blinkymovey2 = 0;
                                    GhostLeft = false;
                                    GhostDown = false;
                                    GhostUp = false;
                                }
                            }


                            if (GhostRight != true)
                            {
                                if (((Keyboard::isKeyPressed(Keyboard::A) == true)
                                    && ((Blinky.getPosition().x) <= (dots[i][j].getPosition().x + dotx2))
                                    && (Blinky.getPosition().x >= (dots[i][j].getPosition().x - dotx2))
                                    && ((Blinky.getPosition().y) <= (dots[i][j].getPosition().y + dotx2))
                                    && ((Blinky.getPosition().y) >= (dots[i][j].getPosition().y - dotx2))))
                                {
                                    Blinkymovex2 = 2;
                                    Blinkymovex1 = 0;
                                    Blinkymovey1 = 0;
                                    Blinkymovey2 = 0;
                                    GhostLeft = true;
                                    GhostRight = false;
                                    GhostDown = false;
                                    GhostUp = false;
                                }
                            }

                            if (GhostDown != true)
                            {
                                if ( (Keyboard::isKeyPressed(Keyboard::W) == true)
                                    && ((Blinky.getPosition().x) <= (dots[i][j].getPosition().x + dotx2))
                                    && (Blinky.getPosition().x >= (dots[i][j].getPosition().x - dotx2))
                                    && ((Blinky.getPosition().y) <= (dots[i][j].getPosition().y + dotx2))
                                    && ((Blinky.getPosition().y) >= (dots[i][j].getPosition().y - dotx2)))
                                {
                                    Blinkymovey1 = 2;
                                    Blinkymovex1 = 0;
                                    Blinkymovex2 = 0;
                                    Blinkymovey2 = 0;
                                    GhostUp = true;
                                    GhostLeft = false;
                                    GhostDown = false;
                                    GhostRight = false;
                                }
                            }

                            if (GhostUp != true)
                            {
                                if ((Keyboard::isKeyPressed(Keyboard::S) == true)
                                    && ((Blinky.getPosition().x) <= (dots[i][j].getPosition().x + dotx2))
                                    && (Blinky.getPosition().x >= (dots[i][j].getPosition().x - dotx2))
                                    && ((Blinky.getPosition().y) <= (dots[i][j].getPosition().y + dotx2))
                                    && ((Blinky.getPosition().y) >= (dots[i][j].getPosition().y - dotx2)))
                                {
                                    Blinkymovey2 = 2;
                                    Blinkymovex1 = 0;
                                    Blinkymovex2 = 0;
                                    Blinkymovey1 = 0;
                                    GhostDown = true;
                                    GhostLeft = false;
                                    GhostUp = false;
                                    GhostRight = false;
                                }
                            }


                        }
                }

            ///Makes dots on all of the block things
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; j < 15; j++){
                    if (grid[i][j] == 'P')
                    {
                        window.draw(dots[i][j]);
                    }

                }
            }

            ///Draws the pacmans lives (Bottom left of the screen)
            for (int i = 0; i < Paclives.size(); i++)
            {
                window.draw(Paclives[i]);
            }

            ///Pacman eating the dots
            if (Right == true)
            {
                gridx = (Pacman.getPosition().y + 25)/50-1;
                gridy = (Pacman.getPosition().x + 25)/50-1;
                grid[gridx][gridy] = 'R';
                if ((gridx == 5 && gridy == 1) && RightPower == false)
                {
                    if (GhostOutside == true) Powerup = true;
                    c2.restart();
                    RightPower = true;
                }
            }

            if (Left == true)
            {
                gridx = (Pacman.getPosition().y + 25)/50-1;
                gridy = (Pacman.getPosition().x + 25)/50-1;
                grid[gridx][gridy] = 'R';
                if ((gridx == 5 && gridy == 13) && LeftPower == false)
                {
                    if (GhostOutside == true) Powerup = true;
                    c2.restart();
                    LeftPower = true;
                }
            }

            if (Down == true)
            {
                gridx = (Pacman.getPosition().y + 25)/50-1;
                gridy = (Pacman.getPosition().x + 25)/50-1;
                grid[gridx][gridy] = 'R';
                if ((gridx == 1 && gridy == 7) && DownPower == false)
                {
                    if (GhostOutside == true) Powerup = true;
                    c2.restart();
                    DownPower = false;
                }
            }

            if (Up == true)
            {
                gridx = (Pacman.getPosition().y + 25)/50-1;
                gridy = (Pacman.getPosition().x + 25)/50-1;
                grid[gridx][gridy] = 'R';
                if ((gridx == 9 && gridy == 7) && UpPower == false)
                {
                    if (GhostOutside == true) Powerup = true;
                    c2.restart();
                    UpPower = true;
                }
            }

            gridx2 = (Blinky.getPosition().y + 15)/50-1;
            gridy2 = (Blinky.getPosition().x + 15)/50-1;

            if (Powerup == false && Blinkydead == false)
            {
                ///Changes Ghost Face based on direction faced
                Blinky.setTextureRect(IntRect(GhostX, 64, 16, 16));

                if ((gridx == gridx2) && (gridy == gridy2))
                {
                    pacdead = true;
                }
            }

            if (Powerup == true)
            {
                if (Blinkydead == false)
                {
                    EatCounter++;
                    if (EatCounter >= 300)
                    {
                        Powerup = false;
                    }
                }
            }

            if (Powerup == false)
            {
                EatCounter = 0;
            }

            if (Powerup == false)
            {
                Blinky.setColor(Color::White);
            }

            if (Powerup == true)
            {
                ///Changes Ghost Face based on direction faced
                if (Blinkydead == false)
                {
                    colourtimer++;
                    if (colourtimer < 30)
                    {
                        Blinky.setColor(Color::Cyan);
                    }
                    if (colourtimer >= 30 && colourtimer < 60)
                    {
                        Blinky.setColor(Color::Yellow);
                    }

                    if (colourtimer >= 60)
                    {
                        colourtimer = 0;
                    }

                    ///Checks if Blinky and Pacman are in the same box
                    if ((gridx == gridx2) && (gridy == gridy2))
                    {
                        EatGhost.play();
                        Blinkydead = true;
                        Powerup = false;
                    }

                }
            }

            ///Moves the ghost
            if (GhostDown == true)
            {
                if (Blinkydead == true)
                {
                    GhostX = 64;
                    ///Changes Ghost Face based on direction faced
                    Blinky.setTextureRect(IntRect(GhostX, 128, 16, 16));
                }

                if (Blinkydead == false && Powerup == false)
                {
                    GhostX = 0;
                }

                Blinkymovey2 = 2;

                if (Powerup == true)
                {
                    Blinkymovey2 = 1;
                }
                Blinky.move(0, Blinkymovey2);
            }

            if (GhostLeft == true)
            {
                if (Blinkydead == true)
                {
                    GhostX = 80;
                    ///Changes Ghost Face based on direction faced
                    Blinky.setTextureRect(IntRect(GhostX, 128, 16, 16));
                }

                if (Blinkydead == false && Powerup == false)
                {
                    GhostX = 32;
                }

                Blinkymovex2 = 2;

                if (Powerup == true)
                {
                    Blinkymovex2 = 1;
                }
                Blinky.move(-Blinkymovex2, 0);
            }

            if (GhostRight == true)
            {
                if (Blinkydead == true)
                {
                    GhostX = 96;
                    ///Changes Ghost Face based on direction faced
                    Blinky.setTextureRect(IntRect(GhostX, 128, 16, 16));
                }

                if (Blinkydead == false && Powerup == false)
                {
                    GhostX = 64;
                }

                Blinkymovex1 = 2;

                if (Powerup == true)
                {
                    Blinkymovex1 = 1;
                }
                Blinky.move(Blinkymovex1, 0);
            }

            if (GhostUp == true)
            {
                if (Blinkydead == true)
                {
                    GhostX = 112;
                    ///Changes Ghost Face based on direction faced
                    Blinky.setTextureRect(IntRect(GhostX, 128, 16, 16));
                }


                if (Blinkydead == false && Powerup == false)
                {
                    GhostX = 96;
                }

                Blinkymovey1 = 2;

                if (Powerup == true)
                {
                    Blinkymovey1 = 1;
                }
                Blinky.move(0, -Blinkymovey1);
            }

            window.draw(Blinky); ///draws the circle to the video card
            window.draw(Scores);
            window.draw(Pacman);

            }

            if (pacdead == true)
            {
                Fruits = false;
                Dead.play();
                Dead.setVolume(100);
                if (Paclives.size() == 0)
                {
                    Gameovers = true;
                    gamestart = false;
                }

                if (Ghostcounter == 0)
                {
                    Paclives.pop_back();
                }

                Ghostcounter++;

                if (Ghostcounter >= 100)
                {
                    Pacman.setPosition(400, 400);
                    Blinky.setPosition(400, 300);
                    Right = false;
                    Left = false;
                    Down = false;
                    Up = false;
                    GhostRight = false;
                    GhostLeft = false;
                    GhostDown = false;
                    GhostUp = false;
                    pacdead = false;
                    gridx = 7;
                    gridy = 7;
                    gridx2 = 4;
                    gridy2 = 7;
                    Ghostcounter = 0;
                    GhostOutside = false;
                }

                Pacman.setTextureRect(IntRect(DeadX, DeadY, 100, 100));
                window.draw(Map);
                window.draw(Blinky);
                window.draw(Pacman);
                window.draw(Scores);

            }
        }

            if (Gameovers == true)
            {
                window.draw(Gameover);
                window.draw(Scores);
            }

        window.display(); ///displays everything on the video card to the monitor
        ///ends the game loop
    }
    return 0;

}
