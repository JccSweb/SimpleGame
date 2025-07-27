#pragma once

#include "game-core/levels/levels-interface/leves-interface.hxx"

namespace Game
{
    namespace Level
    {
        class LevelOne : public ILevelInterface
        {
        public:
            LevelOne();
            std::vector<std::shared_ptr<Game::Elements::IBaseElements>> GetElements() override;
        };

    }
}