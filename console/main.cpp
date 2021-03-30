#include <iostream>
#include "game.h"
#include "observable.h"
#include "vue.h"
#include <stdexcept>

int main() {

    abalone::model::Game game = abalone::model::Game();
    abalone::view::Vue vue = abalone::view::Vue(&game);

    while(!game.checkWon()) {
        bool readSuccess { false };
        while (!readSuccess) {
            std::cout << "Please enter a movement in ABA-Pro : ";
            try {
                std::string s;
                std::getline(std::cin, s);
                game.stringToMovement(s);
                readSuccess = true;
            }
            catch (const std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    game.cleanBoard();
}
