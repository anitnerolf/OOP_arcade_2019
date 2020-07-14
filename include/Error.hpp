/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IGameLib
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <exception>
# include <string>

class Error: public std::exception {
    public:
        virtual ~Error() {}
        Error() {}
        virtual const char *what() const noexcept = 0;
};

class StateError: public Error {
    public:
        StateError(const std::string &c) : str(std::move(c)) {}
        ~StateError() = default;
        const char *what() const noexcept { return str.c_str(); }
    private:
        std::string str;
};

class LibError: public Error {
    public:
        LibError(const std::string &c) : str(std::move(c)) {}
        ~LibError() = default;
        const char *what() const noexcept { return str.c_str(); }
    private:
        std::string str;
};

#endif
