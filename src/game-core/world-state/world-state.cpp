#include "game-core/world-state/world-state.hxx"
#include "types/basic/movement.hxx"
#include "game-core/levels/level-1/level-one.hxx"
#include <iostream>

namespace World
{
   
    std::mutex WorldState::mMutex;
    std::shared_ptr<WorldState> WorldState::mInstance;

    std::shared_ptr<WorldState> WorldState::GetInstance()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mInstance == nullptr)
        {
            mInstance = std::shared_ptr<WorldState>(new WorldState());
        }
        return mInstance;
    }

    void WorldState::ProcessCharacterMoveEvents(const InputTypeEvent& event)
    {
        this->MainCharacter->GetElementPosition();

        Movement move;   
        if (event.keypressed == EventKeyboardTypeEnum::right)
        {
            move.x = this->MainCharacter->GetElementSpeed();
        }
        if (event.keypressed == EventKeyboardTypeEnum::left)
        {
            move.x = -this->MainCharacter->GetElementSpeed();
        }
        if (event.keypressed == EventKeyboardTypeEnum::up)
        {
            move.y = -this->MainCharacter->GetElementSpeed();
        }
        if (event.keypressed == EventKeyboardTypeEnum::down)
        {
            move.y = this->MainCharacter->GetElementSpeed();
        }
        this->MainCharacter->Move(move);
    }

    void WorldState::ReceiveEvents(const InputTypeEvent& event)
    {

        //O que sabemos:
        //Veio um evento:
        //Esse evento é de movimento, logo é para a persongem.
        //A personagem é que deverá ter uma velocidade.
        //Mas quem sabe se a personagem pode ir na direcção é o mundo -> que irá calcular com base no motor de colisão.

        this->ProcessCharacterMoveEvents(event);
    }

    void WorldState::InsertElement(const std::string& name, std::shared_ptr<Ui::Components::IBaseComponent> element )
    {
        std::lock_guard<std::mutex> lock(this->mMutex);
        this->mObjects.insert({name, element});
    }

    std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> WorldState::GetElements()
    {
        std::lock_guard<std::mutex> lock(this->mMutex);
        return this->mObjects;
    }

    WorldState::WorldState()
    {
        this->MainCharacter = std::shared_ptr<Game::Elements::Characters::MainCharacter>(new Game::Elements::Characters::MainCharacter());
    }

    void WorldState::InitDefaults()
    {
        this->InsertElement(this->MainCharacter->GetName(), this->MainCharacter->GetElementRepresentation());
    }

    void WorldState::LoadLevel()//const std::shared_ptr<Game::Level::ILevelInterface>& level)
    {
        //harcoded level 1 for now
        
        auto factory = Game::Level::LevelFactory();
        std::string level = "level1";
        this->mLevel = factory.GetLevel(level);
        for (const auto& element : this->mLevel->GetElements())
        {
            this->InsertElement(element->GetName(), element->GetElementRepresentation());
        }
    }
}
