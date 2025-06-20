#pragma once

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>
#include "ui/interface/abstract-window.hxx"
#include "objects-interface.hxx"
#include "Sfml-window.hxx"
#include "game-core/game-observer.hxx"


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
            std::map<std::string, std::shared_ptr<Ui::Components::IBaseComponent>> objects;

            void Draw(std::shared_ptr<Components::IBaseComponent> imageShape);
            void ProcessEvents(std::shared_ptr<Game::UiSubject> subject);
            InputTypeEvent ParseKeyPressedEvent(sf::Event event);
           
        };
    }
}