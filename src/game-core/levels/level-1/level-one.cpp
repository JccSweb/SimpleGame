#include "level-one.hxx"
#include "game-core/game-elements/objects/ground/grass-ground.hxx"

namespace Game
{
    namespace Level
    {
        LevelOne::LevelOne()
        {
            this->mElements.emplace_back(new Game::Elements::Objects::GrassGround());
            this->mWidht = 1024;
            this->mHeight = 1024;
        };

        std::vector<std::shared_ptr<Game::Elements::IBaseElements>> LevelOne::GetElements()
        {
            return this->mElements;
        }
    }
}