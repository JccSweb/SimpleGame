#pragma once
#include <memory>
#include <list>
#include <mutex>
#include<bits/stdc++.h>

#include "types/basic/player-events.hxx"

namespace Game
{
    class IGameObserver
    {
    public:
        virtual void Update(PlayerEvent event) = 0;
    };

    class IUiSubject
    {
    public:
        virtual void Attach(std::shared_ptr<IGameObserver> observer) = 0;
        virtual void Detach(std::shared_ptr<IGameObserver> observer) = 0;
        // Struct or something to be passed, should garantee decoupling
        virtual void Notify(PlayerEvent event) = 0;
    };

    class UiSubject : public IUiSubject
    {
    public:
        static std::shared_ptr<UiSubject> GetInstance();
        void Attach(std::shared_ptr<IGameObserver> observer);
        void Detach(std::shared_ptr<IGameObserver> observer);
        void Notify(PlayerEvent event);

    protected:
        UiSubject();
        static std::shared_ptr<UiSubject> mInstance;
        static std::mutex mMutex;

    private:
        std::list<std::shared_ptr<IGameObserver>> list_observer_;
    };

    class GameObserver : public std::enable_shared_from_this<GameObserver>, public IGameObserver
    {
        struct Private
        {
            explicit Private() = default;
        };

    public:
        void Update(PlayerEvent event);
        PlayerEvent GetAction();
        bool HasAction();
        void RemoveMeFromTheList();
        GameObserver(std::shared_ptr<IUiSubject> subject, Private); 
        

        static std::shared_ptr<GameObserver> Create(std::shared_ptr<IUiSubject> subject);
        std::shared_ptr<GameObserver> getptr();
       
    private:
        std::queue<PlayerEvent> events;
        static std::mutex mMutex;
        std::shared_ptr<IUiSubject> mSubject;
    };
}