#pragma once

#include <memory>
#include <mutex>
#include "game-core/game-elements/characters/main-character.hxx"

namespace World
{
    class WorldState
    {
    public:
        static std::shared_ptr<WorldState> GetInstance();
        void ReceiveEvents(InputTypeEvent event);
        std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> GetElements();

    protected:
        static std::mutex mMutex;
        static std::shared_ptr<WorldState> mInstance;
        WorldState();

    private:
        std::shared_ptr<Game::Elements::Characters::ICharacters> MainCharacter;
        std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> mObjects;
    };
}
