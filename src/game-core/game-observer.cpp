#include "game-observer.hxx"
#include <iostream>
namespace Game
{
    std::shared_ptr<UiSubject> UiSubject::mInstance;
    std::mutex UiSubject::mMutex;

    UiSubject::UiSubject()
    {
    }
    
    void UiSubject::Attach(const std::shared_ptr<IGameObserver>& observer)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        this->list_observer_.push_back(observer);
    }

    void UiSubject::Detach(const std::shared_ptr<IGameObserver>& observer)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        this->list_observer_.remove(observer);
    }

    void UiSubject::Notify(const InputTypeEvent& event)
    {
        for (auto observer : this->list_observer_)
        {
            observer->Update(event);
        }
    }

    std::shared_ptr<UiSubject> UiSubject::GetInstance()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        if (mInstance == nullptr)
        {
            mInstance = std::shared_ptr<UiSubject>(new UiSubject());
        }
        return mInstance;
    }

    std::mutex GameObserver::mMutex;
    GameObserver::GameObserver(std::shared_ptr<IUiSubject> subject, Private)
    {
        this->mSubject = subject;
    }

    void GameObserver::Update(InputTypeEvent event)
    {
        std::lock_guard<std::mutex> lock(mMutex);
        this->events.push(event);
    }

    bool GameObserver::HasAction()
    {
        return !this->events.empty();
    }

    InputTypeEvent GameObserver::GetAction()
    {
        std::lock_guard<std::mutex> lock(mMutex);
        InputTypeEvent action;
        action = this->events.front();
        this->events.pop();
        return action;
    }
    void GameObserver::RemoveMeFromTheList()
    {
        this->mSubject->Detach(shared_from_this());
    }

    std::shared_ptr<GameObserver> GameObserver::Create(std::shared_ptr<IUiSubject> subject)
    {
        std::shared_ptr<GameObserver> observer = std::make_shared<GameObserver>(subject, Private());
        subject->Attach(observer);
        return observer;
    }

    std::shared_ptr<GameObserver> GameObserver::getptr()
    {
        return shared_from_this();
    }
}