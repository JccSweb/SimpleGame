#pragma once

#include <memory>
#include <mutex>
#include "game-core/game-elements/characters/main-character.hxx"
#include "game-core/levels/levels-interface/leves-interface.hxx"

namespace World
{
    class WorldState
    {
    public:
        static std::shared_ptr<WorldState> GetInstance();
        void ReceiveEvents(const InputTypeEvent& event);
        std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> GetElements();
        void InitDefaults();
        void LoadLevel();//const std::shared_ptr<Game::Level::ILevelInterface>& level);

    protected:
        static std::mutex mMutex;
        static std::shared_ptr<WorldState> mInstance;
        WorldState();

    private:
        std::shared_ptr<Game::Elements::Characters::ICharacters> MainCharacter;
        std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> mObjects;
        void InsertElement(const std::string& name, std::shared_ptr<Ui::Components::IBaseComponent> element);
        void ProcessCharacterMoveEvents(const InputTypeEvent& event);

        std::shared_ptr<Game::Level::ILevelInterface> mLevel;
    };
}
