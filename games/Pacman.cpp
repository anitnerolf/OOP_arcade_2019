/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Pacman
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include "../Core/Menu.hpp"
#include "../include/IGraphicLib.hpp"
#include "Pacman.hpp"

Pacman::Pacman(int width, int height)
{
    (void)width;
    (void)height;
}

Pacman::~Pacman()
{
}


extern "C"
{
    IGameLib*launch_game(int x, int y)
    {
        return new Pacman(x, y);
    }
}
