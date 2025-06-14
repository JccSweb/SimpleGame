#include "main-character.hxx"

#include <iostream>

namespace Game
{
    namespace Elements
    {
        namespace Characters
        {
            MainCharacter::MainCharacter()
            {
                
            }
            void MainCharacter::mReceiveEvent(PlayerEvent event)
            {   
                std::cout << event.keypressed <<  std::endl;
            }
        }
    }
}