#include "abstract-window.hxx"
#include "../sfml/Sfml-window.hxx"


namespace Ui
{
    IAbstractWindow::IAbstractWindow()
    {
        this->mGameController = Game::GameController::GetInstance();
    }
    IAbstractWindow::~IAbstractWindow()
    {
    }

    std::shared_ptr<IAbstractWindow> WindowFactory::GetUi(Widht width, Height height)
    {
        return V1::SfmlWindow::GetInstance(width, height);
    }
}
