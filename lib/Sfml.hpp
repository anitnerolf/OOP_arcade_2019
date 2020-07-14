/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Sfml
*/

#ifndef MYSFML_HPP_
#define MYSFML_HPP_

#include "../include/IGraphicLib.hpp"

class	Sfml : public IGraphicLib
{
public:
    Sfml();
    virtual ~Sfml() {};

    virtual void	build(const int &x,
                      const int &y,
                      const Icolor &col);
    virtual void	writeSmth(const int &x,
                          const int &y,
                          const std::string& text);
    void	set();
    virtual void	open(const int &x, const int &y);
    virtual void	refresh();
    virtual void	clear();
    virtual void	close();
    virtual IGraphicLib::Ikey	getKey() const;

private:
    sf::RenderWindow	win;
    sf::Event	_event;
    int	_second;
    int	_first;
    int	_y;
    int	_x;
};

#endif
