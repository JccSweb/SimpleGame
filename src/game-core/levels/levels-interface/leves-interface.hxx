#pragma once
#include <memory>
#include <vector>
#include "game-core/game-elements/base-game-elements-interface/base-elements-interface.hxx"

namespace Game
{
    namespace Level
    {
        class ILevelInterface
        {
        public:
            virtual ~ILevelInterface() = default;
            virtual std::vector<std::shared_ptr<Game::Elements::IBaseElements>> GetElements() = 0;

        protected:
            
            std::vector<std::shared_ptr<Game::Elements::IBaseElements>> mElements;
            Width mWidht;
            Height mHeight;
        };

        class LevelFactory
        {
            public:
            std::shared_ptr<ILevelInterface> GetLevel(const std::string& levelname);
        };
    }
}