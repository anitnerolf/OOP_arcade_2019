/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Ncurses
*/

#ifndef MYNCURSES_HPP_
# define MYNCURSES_HPP_

# include "../include/IGraphicLib.hpp"
# include <memory>

class myNcurses : public IGraphicLib
{
public:
    myNcurses();
    virtual ~myNcurses() {};
    int isOpen;

    // Window
    virtual void	open(const int &x, const int &y);
    virtual void	refresh();
    virtual void	clear();
    virtual void	close();
    virtual int checkWindowOpen();
    virtual IGraphicLib::Ikey	getKey() const;

    // Draw
    virtual void	build(const int &x,
                      const int &y,
                      const Icolor &col);
    virtual void	writeSmth(const int &x,
                          const int &y,
                          const std::string& text);

private:
    std::unique_ptr<WINDOW> win;
};

#endif
