/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Menu
*/

#include <stdexcept>
#include <regex>
#include <signal.h>
#include <dirent.h>
#include <iostream>
#include <dlfcn.h>
#include <thread>
#include <string>
#include <chrono>
#include "../include/IGameLib.hpp"
#include "../include/IGraphicLib.hpp"
#include "Menu.hpp"
#include "../include/Error.hpp"

using std::string;

Menu::Menu(string &lib)
{
    openLib(lib);
    openGame();
    openDL();
}

Menu::~Menu()
{
    if (!this->_dLib)
        return;
    dlclose(this->_dLib);
}

void    Menu::openDL()
{
    IGraphicLib* (*launch)();

    if (this->_actualLib == -1) {
        throw StateError("something wrong");
    }
    this->_dLib = dlopen(this->_libName[this->_actualLib].c_str(), RTLD_LAZY);
    if (this->_dLib == nullptr
        || (launch = reinterpret_cast<IGraphicLib* (*)()>
            (dlsym(this->_dLib, "launch_lib"))) == nullptr) {
        throw StateError("something wrong");
    }
    this->_lib.reset(launch());
}

void    Menu::openGame()
{
    DIR *dir;
    struct dirent *dlib;
    const string pacman = "libarcade_pacman.so";
    const string snake = "libarcade_snake.so";
    string game_path = "./game/";
    int a = 0;

    if ((dir = opendir("./games")) != NULL) {
        while (a != 2 && (dlib = readdir(dir)) != NULL) {
            if (string(dlib->d_name) == pacman || string(dlib->d_name) == snake) {
                this->_gameName[a] = game_path + dlib->d_name;
                a++;
            }
        }
        closedir(dir);
    } else {
        throw LibError("this game does not exist");
    }
}

void    Menu::openLib(string &lib)
{
    DIR *dir;
    struct dirent *dlib;
    const string sfml = "lib_arcade_sfml.so";
    const string ncurses = "lib_arcade_ncurses.so";
    string lib_path = "./lib/";
    int a = 0;
    this->_actualLib = -1;

    if ((dir = opendir("./lib")) != NULL) {
        while ((dlib = readdir(dir)) != NULL) {
            if (string(dlib->d_name) == sfml || string(dlib->d_name) == ncurses) {
                this->_libName[a] = lib_path + dlib->d_name;
                if (lib == this->_libName[a])
                    this->_actualLib = a;
                a++;
            }
        }
        closedir(dir);
    } else {
        throw LibError("a library file does not exist");
    }
}

void Menu::changeLib(IGraphicLib::Ikey key)
{
    if (key == IGraphicLib::Num_2 && this->_actualLib != 0)
        this->_actualLib--;
    else if (key == IGraphicLib::Num_3 && this->_libName[this->_actualLib + 1] != "")
        this->_actualLib++;
}

void Menu::Frame()
{
    int	i;

    for (i = 1; i != 39; i++)
        this->_lib->build(i, 6, IGraphicLib::I_WHITE);
    for (i = 1; i != 39; i++)
        this->_lib->build(i, 18, IGraphicLib::I_BLUE);
    for (i = 1; i != 39; i++)
        this->_lib->build(i, 29, IGraphicLib::I_WHITE);

    for (i = 3; i != 5; i++)
        this->_lib->build(i, 12 + (2 * this->_actualLib), IGraphicLib::I_GREEN);
    for (i = 3; i != 5; i++)
        this->_lib->build(i, 24 + (2 * this->_actualGame), IGraphicLib::I_GREEN);
}

void Menu::changeGame(IGraphicLib::Ikey key)
{
    if (key == IGraphicLib::Num_4 && this->_actualGame != 0)
        this->_actualGame--;
    else if (key == IGraphicLib::Num_5 && this->_gameName[this->_actualGame + 1] != "")
        this->_actualGame++;
}

void Menu::writeMenu()
{
    int	y = 12;

    this->_lib->writeSmth(18, 3, "MENU");
    this->_lib->writeSmth(3, 9, "Chose a graphic library:");
    this->_lib->writeSmth(6, y, "Sfml");
    y += 2;
    this->_lib->writeSmth(6, y, "Ncurses");
    y += 2;
    this->_lib->writeSmth(3, 21, "Chose a game:");
    y = 24;
    this->_lib->writeSmth(6, y, "Pacman");
    y += 2;
    this->_lib->writeSmth(6, y, "Snake");
    y += 2;
}

void Menu::play_game()
{
    IGameLib*   (*game)();

    this->_game.reset(reinterpret_cast<IGameLib*>(dlopen("./game/libarcade_snake.so", RTLD_NOW)));
    if (this->_game == nullptr)
        throw StateError("Something wrong with dl_game");
    // this->_game.reset(game()->startGame);
    //game->start_Game();
}

int Menu::react(IGraphicLib::Ikey key)
{
    switch (key) {
        case IGraphicLib::Num_2: case IGraphicLib::Num_3:
            this->changeLib(key);
            break;
        case IGraphicLib::I_ESC:
            return (-1);
        case IGraphicLib::Num_4:
            if (this->_game == NULL){
                if (this->_actualGame != 0)
                    this->_actualGame--;
            }
            else
                this->changeGame(key);
            break;
        case IGraphicLib::Num_5:
            if (this->_game == NULL) {
                if (this->_actualGame == 0)
                    this->_actualGame++;
            }
            else
                this->changeGame(key);
            break;
        case IGraphicLib::SPACE:
            this->play_game();
            break;
        default:
            return (0);
    }
    return (0);
}

void Menu::launch()
{
    this->_end = IGameLib::E_NONE;
    this->_actualGame = 0;
    this->_lib->open(40, 40);
    while (true) {
        this->writeMenu();
        this->Frame();
        if (this->react(this->_lib->getKey()) == -1)
            break ;
        this->_lib->refresh();
        this->_lib->clear();
    }
    this->_lib->close();
}
