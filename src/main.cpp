/*
** KU PROJECT, 2024
** GAZEAU-ROUSSEAU PAUL PHILIPPE FERNAND
** 2023850024
*/

#include <iostream>
#include "OpenTerrain.hpp"

int usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./open-terrain [-h]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\t-h\t\tPrint the usage and quit." << std::endl;
    return (0);
}

int main(int argc, char const *argv[])
{

    try {
        OpenTerrain::OpenTerrain openterrain("OpenTerrain", 800, 600);
        openterrain.launch();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return 0;
}
