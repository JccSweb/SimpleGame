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
        }
    }
}