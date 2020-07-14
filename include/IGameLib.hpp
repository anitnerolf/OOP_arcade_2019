/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IGameLib
*/

#ifndef IGAMELIB_HPP_
# define IGAMELIB_HPP_

#include "IGraphicLib.hpp"

class	IGameLib
{
public:
    typedef enum {
        E_NONE,
        E_WIN,
        E_LOSE
    } e_end;

    virtual ~IGameLib() {};
    virtual void WindowOpen() = 0;
    virtual void CreateAssets(void) = 0;
    virtual void Movement(void) = 0;
    virtual void GameAction(void) = 0;
    virtual void DisplayGame() = 0;
    virtual void start_Game(void) = 0;

};

#endif /* !IGAMELIB_HPP_ */
