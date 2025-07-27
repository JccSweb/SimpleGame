#include "leves-interface.hxx"
#include "game-core/levels/level-1/level-one.hxx"

namespace Game
{
    namespace Level
    {
        std::shared_ptr<ILevelInterface> LevelFactory::GetLevel(const std::string& levelname)
        {
            return std::shared_ptr<ILevelInterface>(new LevelOne());
        }
    }
}