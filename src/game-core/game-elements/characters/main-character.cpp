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
                this->mComponentRepresentation = Ui::Components::ComponentConstrutor::GetInstance(Ui::Components::ShapesEnum::circle);
                this->SetCharacteristics();
            }

            void MainCharacter::SetCharacteristics()
            {
                this->mName = "player";
                Color color;
                color.blue = 255;
                color.green = 255;
                color.red = 255;
                this->mComponentRepresentation->SetFillColor(color);
                this->mComponentRepresentation->SetRadius(20.0f);
                this->SetElementSpeed(10);
            }
        }
    }
}