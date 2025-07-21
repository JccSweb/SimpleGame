#include "game-core/world-state/world-state.hxx"
#include "types/basic/movement.hxx"

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

    void WorldState::ReceiveEvents(const InputTypeEvent& event)
    {
        std::cout << event.keypressed << std::endl;
        Movement move;   
        if (event.keypressed == EventKeyboardTypeEnum::Right)
        {
            move.x = 2.0;
        }
        if (event.keypressed == EventKeyboardTypeEnum::Left)
        {
            move.x = -2.0;
        }
        if (event.keypressed == EventKeyboardTypeEnum::Up)
        {
            move.y = -2.0;
        }
        if (event.keypressed == EventKeyboardTypeEnum::Down)
        {
            move.y = 2.0;
        }
        this->MainCharacter->GetElementPosition();
        this->MainCharacter->Move(move);
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
}
