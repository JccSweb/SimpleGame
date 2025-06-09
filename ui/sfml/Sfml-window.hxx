#pragma once

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>
#include "../interface/abstract-window.hxx"
#include "objects-interface.hxx"
#include "Sfml-window.hxx"


namespace Ui
{
    namespace V1
    {

        class SfmlWindow : public IAbstractWindow
        {
        public:
            static std::shared_ptr<SfmlWindow> GetInstance(Widht width, Height height);
            virtual void Render() override;
            ~SfmlWindow();

        protected:
            SfmlWindow(Widht width, Height height);


        private:
            static std::mutex mMutex;
            static std::shared_ptr<SfmlWindow> mInstance;
            std::unique_ptr<sf::RenderWindow> window;
            void Draw(std::shared_ptr<Components::IBaseComponent> imageShape);
            void ProcessEvents();
            std::shared_ptr<Ui::Components::IBaseComponent> mNewShape;
        };
    }
}