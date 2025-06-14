#include "abstract-window.hxx"
#include "ui/sfml/Sfml-window.hxx"


namespace Ui
{
    IAbstractWindow::IAbstractWindow()
    {
        this->mGameController = Game::GameController::GetInstance();
    }
    std::shared_ptr<IAbstractWindow> WindowFactory::GetUi()
    {
        return V1::SfmlWindow::GetInstance();
    }
}
