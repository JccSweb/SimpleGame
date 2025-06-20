#include "game-core/command/commands/create-character-commnand.hxx"

namespace Game
{
    namespace Commands
    {
        CreateMainCharacterCommand::CreateMainCharacterCommand()
        {
            this->mCommandName = "MainCharacter";
        }

        std::shared_ptr<Ui::Components::IBaseComponent>  CreateMainCharacterCommand::CreateCharacterBuilder()
        {
            this->mComponent = Ui::Components::ComponentConstructor::GetInstance(Ui::Components::Circle);
            return this->mComponent;
        }

        void CreateMainCharacterCommand::ProcessCommand()
        {
            this->mUi->Add(this->mCommandName, this->mComponent);   
        }
    }
}