#include "game-core.hxx"
#include "game-observer.hxx"

namespace Game
{
    std::shared_ptr<GameController> GameController::mInstance;
    std::mutex GameController::mMutex;

    GameController::GameController()
    {
    }
    bool GameController::GetStatus()
    {
        return this->mStatus;
    }

    void GameController::SetStatus(bool shutdown)
    {
        this->mStatus = shutdown;
    }

    std::shared_ptr<GameController> GameController::GetInstance()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mInstance == nullptr)
        {
            mInstance = std::shared_ptr<GameController>(new GameController());
        }
        return mInstance;
    }

    GameCore::GameCore()
    {
        this->mGameController = GameController::GetInstance();
        auto mPlayer = std::make_shared<Game::Elements::Characters::MainCharacter>();
        this->mElements.push_back(mPlayer);
    }

    void GameCore::Start()
    {
        std::shared_ptr<Game::UiSubject> subject = Game::UiSubject::GetInstance();
        std::shared_ptr<Game::GameObserver> observer = Game::GameObserver::Create(subject);

        while (this->mGameController->GetStatus())
        {
            while (observer->HasAction())
            {
                InputTypeEvent event;
                event = observer->GetAction();
                for (auto elem : this->mElements)
                {
                    elem->mReceiveEvent(event);
                }
            }
        }
    }
}