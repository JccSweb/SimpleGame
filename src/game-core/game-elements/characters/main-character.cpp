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
            void MainCharacter::mReceiveEvent(InputTypeEvent event)
            {   
                std::cout << "pressed" <<  std::endl;
            }
        }
    }
}