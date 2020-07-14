/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include <random>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <random>
#include "../include/IGraphicLib.hpp"
#include "../include/IGameLib.hpp"
#include "../Core/Menu.hpp"

class	Pacman : public IGameLib {
    public:
        Pacman(int width, int height);
        virtual ~Pacman();
        virtual void WindowOpen(void);
        virtual void CreateAssets(void);
        virtual void Movement(void);
        virtual void GameAction(void);
        virtual void DisplayGame(void);
        virtual void start_Game(void);
        sf::RenderWindow	window;
    private:
        sf::RectangleShape block;
        sf::RectangleShape blockApple;
        sf::RectangleShape blockSnake;
        sf::Event e;
        sf::Clock clock;
        float chrono;
        float delay;
        float time;
        bool GameOver;
};

#endif
