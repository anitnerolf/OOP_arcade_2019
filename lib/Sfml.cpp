/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Sfml
*/


#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sfml.hpp"

Sfml::Sfml()
{
}

void	Sfml::open(const int &x, const int &y)
{
    this->_first = 0;
    this->_second = 0;
    this->win.create(sf::VideoMode(x * 30, y * 30),
                     "Welcome to Arcade", sf::Style::Close);
    this->set();
    this->win.display();
}

void	Sfml::refresh()
{
    this->set();
    this->win.display();
}

void	Sfml::close()
{ this->win.close(); }

void	Sfml::set()
{
    sf::Vector2u size = this->win.getSize();

    this->_x = size.x;
    this->_y = size.x;
    this->_first = this->_x / 40;
    this->_second = this->_y / 40;
    this->win.pollEvent(this->_event);
}

IGraphicLib::Ikey	Sfml::getKey() const
{
    std::array<
        std::pair<IGraphicLib::Ikey, sf::Keyboard::Key>,
        7> keys = {{
            {Num_1,sf::Keyboard::Num1},
            {Num_2, sf::Keyboard::Num2},
            {Num_3, sf::Keyboard::Num3},
            {Num_4, sf::Keyboard::Num4},
            {Num_5, sf::Keyboard::Num5},
            {I_ESC, sf::Keyboard::Escape},
            {SPACE, sf::Keyboard::Space}
        }};
    for (auto &i : keys) {
        if (sf::Keyboard::isKeyPressed(i.second))
            return i.first;
    }
    return (I_NONE);
}

void	Sfml::writeSmth(const int &x, const int &y, const std::string& txt)
{
    sf::Text      text;
    sf::Font      f;
    std::string   str;
    std::size_t i = 0;

    if (f.loadFromFile("./lib/times-new-roman.ttf") == false)
        exit (84);
    text.setFont(f);
    text.setCharacterSize(20);
    text.setString(txt);
    text.setPosition(sf::Vector2f(x * this->_first, y * this->_second));
    text.setFillColor(sf::Color::Red);
    while (i < txt.size()) {
        str = txt.at(i);
        text.setString(str);
        text.setPosition(sf::Vector2f((x * this->_first) + (i * this->_first), y * this->_second));
        this->win.draw(text);
        i++;
    }
}

static sf::Color	colorCell(IGraphicLib::Icolor col)
{
    switch(col) {
    case IGraphicLib::I_WHITE :
        return (sf::Color::White);
    case IGraphicLib::I_YELLOW :
        return (sf::Color::Yellow);
    case IGraphicLib::I_RED :
        return (sf::Color::Red);
    case IGraphicLib::I_GREEN :
        return (sf::Color::Green);
    case IGraphicLib::I_BLUE :
        return (sf::Color::Blue);
    default :
        return (sf::Color::Black);
    }
}

void	Sfml::build(const int &x, const int &y, const IGraphicLib::Icolor &col)
{
    sf::RectangleShape rectangle(sf::Vector2f(this->_first, this->_first));
    rectangle.setFillColor(colorCell(col));
    rectangle.setPosition(x * this->_first, y * this->_second);
    this->win.draw(rectangle);
}

void	Sfml::clear()
{
    this->win.clear(sf::Color::Black);
}

extern "C"
{
    IGraphicLib* launch_lib()
    {
        return new Sfml();
    }
}
