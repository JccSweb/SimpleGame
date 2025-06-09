#pragma once
#include <iostream>
#include <memory>
#include <mutex>

namespace Game
{
    class GameController
    {
        public:
        static std::shared_ptr<GameController> GetInstance();
        bool GetStatus();
        void SetStatus(bool shutdown);
        private:
        bool mStatus = true;
        GameController();
        static std::shared_ptr<GameController> mInstance;
        static std::mutex mMutex;
    };

    class GameCore
    {
    public:
        GameCore();
        void Start();
    private:
        std::shared_ptr<GameController>  mGameController;
    };
}
