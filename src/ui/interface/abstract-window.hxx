#pragma once
#include <memory>
#include "types/basic/type-definitions.hxx"
#include "game-core/game-core.hxx"

namespace Ui
{
    class IAbstractWindow
    {
    public:
        virtual void Render() = 0;

    protected:
        IAbstractWindow();
        std::shared_ptr<Game::GameController> mGameController;
    };

    class WindowFactory
    {
    public:
        static std::shared_ptr<IAbstractWindow> GetUi();
    };
}
