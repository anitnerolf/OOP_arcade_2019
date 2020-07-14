/*
** EPITECH PROJECT, 2020
** main
** File description:
** Arcade
*/

#include <stdbool.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <dlfcn.h>
#include "../include/IGameLib.hpp"
#include "../include/IGraphicLib.hpp"
#include "Menu.hpp"
#include "../include/Error.hpp"


static void print_usage()
{
    printf("USAGE :\n"
        "\t\t[binary] [lib]\tgraphical library "
        "to use, default if empty.\n");
}

int             main(int ac, char **av)
{   
    try {
        if (ac != 2) {
            throw StateError("USAGE: ./arcade path_to_graphics_lib_file (don't forget ./lib/ in the path!)");
        }
        if (ac == 2 && std::strcmp(av[1], "-h") == 0) {
            print_usage();
            return (0);
        }
        std::string str(av[1]);
        Menu l(str);
        l.launch();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}
