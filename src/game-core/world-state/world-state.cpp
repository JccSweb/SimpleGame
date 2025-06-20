#include "game-core/world-state/world-state.hxx"

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

    void WorldState::ReceiveEvents(InputTypeEvent event)
    {
        this->MainCharacter->mReceiveEvent(event);
    }

    std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> WorldState::GetElements()
    {
        std::lock_guard<std::mutex> lock(this->mMutex);
        return this->mObjects;
    }

    WorldState::WorldState()
    {
        this->MainCharacter = std::shared_ptr<Game::Elements::Characters::MainCharacter>(new Game::Elements::Characters::MainCharacter());
        this->mObjects.insert({this->MainCharacter->GetName(), this->MainCharacter->GetElementRepresentation()});
    }
}
