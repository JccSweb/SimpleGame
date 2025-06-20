#include "Sfml-window.hxx"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "objects-interface.hxx"

int SPEED = 5;

namespace Ui
{
    namespace V1
    {
        std::mutex SfmlWindow::mMutex;
        std::shared_ptr<SfmlWindow> SfmlWindow::mInstance = nullptr;

        std::shared_ptr<SfmlWindow> SfmlWindow::GetInstance()
        {
            std::lock_guard<std::mutex> lock(mMutex);
            if (mInstance == nullptr)
            {
                mInstance = std::shared_ptr<SfmlWindow>(new SfmlWindow());
            }
            return mInstance;
        }

        void SfmlWindow::Render()
        {
            std::shared_ptr<Game::UiSubject> subject = Game::UiSubject::GetInstance();
            // auto circle = Ui::Components::ComponentConstrutor::GetInstance(Ui::Components::Circle);

            // this->mShapes.push_back(circle);
            while (this->window->isOpen())
            {
                this->ProcessEvents(subject);
                // this->ProccessCommands(); Responsable for moving, fight, etc.
                this->window->clear();
                /*   for (auto shape : this->mShapes)
                  {
                      this->Draw(shape);
                  }
                */
                this->window->display();
            }
            // this->mShapes.remove(circle);
        }

        SfmlWindow::SfmlWindow()
        {
            Widht widht = 800;
            Height height = 800;
            std::string title = "Hello World";
            this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode({widht, height}), title);
        }

        void SfmlWindow::Draw(std::shared_ptr<Components::IBaseComponent> imageShape)
        {
            this->window->draw(*imageShape->GetElement());
        }

        void SfmlWindow::GetEvents()
        {
        }
        void SfmlWindow::ProcessEvents(std::shared_ptr<Game::UiSubject> subject)
        {
            sf::Event event;
            while (bool value = this->window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    this->window->close();
                    this->mGameController->SetStatus(false);
                }

                if (event.type == sf::Event::KeyPressed)
                {
                    InputTypeEvent pEvent = this->ParseKeyPressedEvent(event);
                    subject->Notify(pEvent);
                }
            }
        }

        InputTypeEvent SfmlWindow::ParseKeyPressedEvent(sf::Event event)
        {
            InputTypeEvent inputEvent;
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                inputEvent.keypressed = EventKeyboardTypeEnum::Left;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Right:
                inputEvent.keypressed = EventKeyboardTypeEnum::Right;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Up:
                inputEvent.keypressed = EventKeyboardTypeEnum::Up;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Down:
                inputEvent.keypressed = EventKeyboardTypeEnum::Down;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            default:
                break;
            }
        }
    }
}

/*             sf::Texture texture;
            if (!texture.loadFromFile("img.png", sf::IntRect({10, 10}, {200, 200})))
            {
                std::cout << "Couldn't load image" << std::endl;
            }
            sf::Sprite sprite(texture);
 */