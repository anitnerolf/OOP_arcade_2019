/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"



int SIZE = 30;
int vx = SIZE * SIZE;
int vy = SIZE * 15;
int horizontalLine = 30;
int verticalLine = 15;
int direction = 2;
int num = 3;

struct Fruit {
    int x, y;
} apple;

struct SnakePosition {
    int x, y;
} snakePos[100];

Snake::Snake(int width, int height)
{
    (void)width;
    (void)height;
    this->GameOver = false; 
}

void	Snake::GameAction(void)
{
    for (int i = num; i > 0; i--) {
        snakePos[i].x = snakePos[i - 1].x;
        snakePos[i].y = snakePos[i - 1].y;
    }

    if (direction == 0) {
        snakePos[0].y += 1;
    } else if (direction == 1) {
        snakePos[0].x -= 1;
    } else if (direction == 2) {
        snakePos[0].x += 1;
    } else if (direction == 3) {
        snakePos[0].y -= 1;
    }

    if ((snakePos[0].x == apple.x) && (snakePos[0].y == apple.y)) {
        num++;
        apple.x = rand() % 30;
        apple.y = rand() % 15;
    }

    if (snakePos[0].x > 30 || snakePos[0].x < 0 || snakePos[0].y > 15 || snakePos[0].y < 0) {
        this->GameOver = true;
        num = 3;
    }

    for (int i = 3; i < num; i++) {
        if (snakePos[0].x == snakePos[i].x && snakePos[0].y == snakePos[i].y) {
            this->GameOver = true;
            num = 3;
        }
    }

}

void	Snake::CreateAssets(void)
{
    this->block.setSize(sf::Vector2f(SIZE, SIZE));
    this->block.setFillColor(sf::Color::Black);
    this->block.setOutlineThickness(1);
    this->block.setOutlineColor(sf::Color::White);
    this->blockApple.setSize(sf::Vector2f(SIZE, SIZE));
    this->blockApple.setFillColor(sf::Color::Red);
    this->blockApple.setOutlineThickness(1);
    this->blockApple.setOutlineColor(sf::Color::White);
    this->blockSnake.setSize(sf::Vector2f(SIZE, SIZE));
    this->blockSnake.setFillColor(sf::Color::Green);
    this->blockSnake.setOutlineThickness(1);
    this->blockSnake.setOutlineColor(sf::Color::White);
    this->chrono = 0;
    this->delay = 0.1;
    apple.x = rand() % 30;
    apple.y = rand() % 15;
}

void	Snake::Movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = 0;
    }
}

void	Snake::DisplayGame(void)
{
    for (int i = 0; i < verticalLine; i++) {
        for (int j = 0; j < horizontalLine; j++) {
            this->block.setPosition(j * SIZE, i * SIZE);
            this->window.draw(this->block);
        }
    }
    for (int i = 0; i < num; i++) {
        this->blockSnake.setPosition(snakePos[i].x * SIZE, snakePos[i].y * SIZE);
        this->window.draw(this->blockSnake);
    }
    this->blockApple.setPosition(apple.x * SIZE, apple.y * SIZE);
    this->window.draw(this->blockApple);
}


void	Snake::WindowOpen(void)
{
    this->CreateAssets();
    while (this->window.isOpen()) {
        this->time = this->clock.getElapsedTime().asSeconds();
        this->clock.restart();
        this->chrono += this->time;
        if (this->GameOver == true) {
            this->window.close();
        }
        while (window.pollEvent(this->e)) {
            if (this->e.type == sf::Event::Closed) {
                this->window.close();
            }
        }
        this->Movement();
        this->window.clear();
        if (this->chrono > this->delay) {
            chrono = 0;
            this->GameAction();
        }
        this->DisplayGame();
        this->window.display();
    }
}

void	Snake::start_Game()
{
    this->window.create(sf::VideoMode(vx, vy), "Snake Game");
    this->WindowOpen();
}

extern "C"
{

    IGameLib* launch_game(int x, int y)
    {
        return new Snake(x, y);
    }
}
