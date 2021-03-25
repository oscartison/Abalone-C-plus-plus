#include <iostream>
#include "game.h"
#include "observable.h"
#include "vue.h"
#include <stdexcept>



int main()
{
   Game game = Game();
   Vue vue = Vue(&game);


   while(!game.checkWon()) {
       bool lectureReussie { false };

       while (!lectureReussie)
       {
           std::cout << "fournir un mouvement en ABA-pro : ";
           try
           {
               std::string s;
               std::getline(std::cin, s);
               game.stringToMovement(s);
               lectureReussie = true;
           }
           catch (const std::exception & e)
           {
                   std::cout << e.what() << std::endl;
           }
       }

   }

}
