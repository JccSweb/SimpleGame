
#include "game-core.hxx"

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
    }

    void GameCore::Start()
    {
        while (this->mGameController->GetStatus())
        {
            std::cout << "thread 2" << std::endl;
        }
    }
}