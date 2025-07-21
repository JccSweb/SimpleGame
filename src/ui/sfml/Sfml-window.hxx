#pragma once

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>
#include "ui/interface/abstract-window.hxx"
#include "objects-interface.hxx"
#include "Sfml-window.hxx"
#include "game-core/game-observer.hxx"
#include "game-core/world-state/world-state.hxx"

namespace Ui
{
    namespace V1
    {
        class SfmlWindow : public IAbstractWindow
        {
        public:
            static std::shared_ptr<SfmlWindow> GetInstance();
            void GetEvents();
            virtual void Render() override;

        protected:
            SfmlWindow();

        private:
            static std::mutex mMutex;
            static std::shared_ptr<SfmlWindow> mInstance;
            
            std::unique_ptr<sf::RenderWindow> window;
            std::shared_ptr<World::WorldState> state;
            std::shared_ptr<Game::UiSubject> subject;

            void Draw(const std::shared_ptr<Components::IBaseComponent>& imageShape);
            void ProcessEvents(const std::shared_ptr<Game::UiSubject>& subject);
            InputTypeEvent ParseKeyPressedEvent(sf::Event event);
        };
    }
}