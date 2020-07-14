/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IGraphicLib
*/

#ifndef IGRAPHICLIB_HPP_
#define IGRAPHICLIB_HPP_

#include <iostream>
#include <string>
#include <array>

class	IGraphicLib
{
public:
    typedef enum {
        I_RED,
        I_WHITE,
        I_YELLOW,
        I_BLUE,
        I_GREEN
    } Icolor;

    typedef enum {
        I_NONE = -1,
        I_LEFT = 0,
        I_ESC,
        Num_1,
        Num_2,
        Num_3,
        Num_4,
        Num_5,
        SPACE
    } Ikey;

    virtual ~IGraphicLib() {};

    // Window
    virtual void	open(const int &x, const int &y) = 0;
    virtual void	refresh() = 0;
    virtual void	clear() = 0;
    virtual void	close() = 0;
    virtual Ikey	getKey() const = 0;

    // Draw
    virtual void	writeSmth(const int &x,
                          const int &y,
                          const std::string& text) = 0;
    virtual void	build(const int &x,
                      const int &y,
                      const Icolor &col) = 0;
};

#endif
