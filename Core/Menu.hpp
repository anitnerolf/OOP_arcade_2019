/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Menu
*/

#ifndef MENU_HPP_
# define MENU_HPP_

# include <memory>
# include <array>
# include "../include/IGameLib.hpp"
# include "../include/IGraphicLib.hpp"

class Menu {
public:
    Menu(std::string &lib);
    ~Menu();

    void launch();
    void changeLib(IGraphicLib::Ikey key);
    void changeGame(IGraphicLib::Ikey key);
    void writeMenu();
    void openLib(std::string &lib);
    void openGame();
    void openDL();
    void Frame();
    void play_game();
    int  react(IGraphicLib::Ikey key);

private:
    IGameLib::e_end _end;

    // Graphic libs
    std::shared_ptr<IGraphicLib> _lib;
    int _actualLib;
    void* _dLib;
    std::array<std::string, 3> _libName;

    // Game libs
    std::shared_ptr<IGameLib> _game;
    int _actualGame;
    void* _dGame;
    std::array<std::string, 3> _gameName;
};

#endif
