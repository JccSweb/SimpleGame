#include "game-core/game-elements/characters/main-character.hxx"

#include <iostream>

namespace Game
{
    namespace Elements
    {
        namespace Characters
        {
            MainCharacter::MainCharacter()
            {
                this->mComponentRepresentation = Ui::Components::ComponentConstrutor::GetInstance(Ui::Components::Circle);
            }

            void MainCharacter::mReceiveEvent(InputTypeEvent event)
            {   
                std::cout << "pressed" <<  std::endl;
            }
        }
    }
}