#pragma once
#include <memory>
#include <list>
#include <mutex>
#include<bits/stdc++.h>

#include "types/basic/input-events.hxx"

namespace Game
{
    class IGameObserver
    {
    public:
        virtual void Update(InputTypeEvent event) = 0;
    };

    class IUiSubject
    {
    public:
        virtual void Attach(const std::shared_ptr<IGameObserver>& observer) = 0;
        virtual void Detach(const std::shared_ptr<IGameObserver>& observer) = 0;
        // Struct or something to be passed, should garantee decoupling
        virtual void Notify(const InputTypeEvent& event) = 0;
    };

    class UiSubject : public IUiSubject
    {
    public:
        static std::shared_ptr<UiSubject> GetInstance();
        void Attach(const std::shared_ptr<IGameObserver>& observer);
        void Detach(const std::shared_ptr<IGameObserver>& observer);
        void Notify(const InputTypeEvent& event);

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
        void Update(InputTypeEvent event);
        InputTypeEvent GetAction();
        bool HasAction();
        void RemoveMeFromTheList();
        GameObserver(std::shared_ptr<IUiSubject> subject, Private); 
        

        static std::shared_ptr<GameObserver> Create(std::shared_ptr<IUiSubject> subject);
        std::shared_ptr<GameObserver> getptr();
       
    private:
        std::queue<InputTypeEvent> events;
        static std::mutex mMutex;
        std::shared_ptr<IUiSubject> mSubject;
    };
}