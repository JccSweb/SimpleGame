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
            Widht widht = 800;
            Height height = 800;
            std::string title = "Hello World";
            this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode({widht, height}), title);
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
            // Should be sent to a parser and then to a
            sf::Event event;
            while (bool value = this->window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    std::cout << "Closed!" << std::endl;
                    this->window->close();
                    this->mGameController->SetStatus(false);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    PlayerEvent event;
                    event.keypressed = "Teste";
                    event.type = PlayerEventType::keyboard;
                    subject->Notify(event);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    PlayerEvent event;
                    event.keypressed = "Teste";
                    event.type = PlayerEventType::keyboard;
                    subject->Notify(event);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    PlayerEvent event;
                    event.keypressed = "Teste";
                    event.type = PlayerEventType::keyboard;
                    subject->Notify(event);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    PlayerEvent event;
                    event.keypressed = "Teste";
                    event.type = PlayerEventType::keyboard;
                    subject->Notify(event);
                }
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