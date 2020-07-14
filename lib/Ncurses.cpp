/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Ncurses
*/

#include <ncurses.h>
#include "Ncurses.hpp"

myNcurses::myNcurses()
{
}

static void create_pairs()
{
    assume_default_colors(-1,-1);
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_GREEN, COLOR_GREEN);
}

void	myNcurses::open(const int &x, const int &y)
{
    (void)x;
    (void)y;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    create_pairs();
    curs_set(0);
    //this->win = newwin(y, x, 0, 0);
    this->isOpen = 1;
}

void	myNcurses::refresh()
{
    refresh();
}

void	myNcurses::close()
{
    endwin();
    this->isOpen = 0;
}

int	myNcurses::checkWindowOpen()
{
    return (this->isOpen);
}

IGraphicLib::Ikey	myNcurses::getKey() const
{
    int key = getch();
    if (key == '2') {
        std::cout << "key is = " <<  key << std::endl;
        return (IGraphicLib::Num_2);
    }
    if (key == '3')
        return (IGraphicLib::Num_3);
    if (key == '4')
        return (IGraphicLib::Num_4);
    if (key == '5')
        return (IGraphicLib::Num_5);
    if (key == '1')
        return (IGraphicLib::Num_1);
    if (key == 27)
        return (IGraphicLib::I_ESC);
    return (I_NONE);
}

void	myNcurses::writeSmth(const int &x, const int &y, const std::string &txt)
{
    int j = 0;
    int k = 0;
    char c;
    for (std::string::size_type i = 0; i < txt.size() * 2; i = i + 2) {
        j = i + (x * 2);
        k = i / 2;
        c = txt.at(k);
        mvprintw(y, j, "%c", c);
    }
}

static void attron_color(const int &x, const int &y, const IGraphicLib::Icolor &color)
{
    attron(COLOR_PAIR(color));
    mvprintw(y, (x * 2), ">>");
}

void	myNcurses::build(const int &x, const int &y, const IGraphicLib::Icolor &color)
{
    attron_color(x, y, color);
    attroff(COLOR_PAIR(color));
}

void	myNcurses::clear()
{
    clear();
}

extern "C"
{
    IGraphicLib* launch_lib()
    {
        return new myNcurses();
    }
}
