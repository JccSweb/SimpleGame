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

        std::shared_ptr<SfmlWindow> SfmlWindow::GetInstance(unsigned int width, unsigned int height)
        {
            std::lock_guard<std::mutex> lock(mMutex);
            if (mInstance == nullptr)
            {
                mInstance = std::shared_ptr<SfmlWindow>(new SfmlWindow(width, height));
            }
            return mInstance;
        }

        void SfmlWindow::Render()
        {
            while (this->window->isOpen())
            {
                this->ProcessEvents();
                this->window->clear();
                this->Draw(this->mNewShape);
                this->window->display();
            }
        }

        SfmlWindow::SfmlWindow(Widht width, Height height)
        {
            this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode({width, height}), "Hello World");
            this->mNewShape = Ui::Components::ComponentConstrutor::GetInstance(Ui::Components::Circle);

        }

        SfmlWindow::~SfmlWindow()
        {
            // destrutor
        }

        void SfmlWindow::Draw(std::shared_ptr<Components::IBaseComponent> imageShape)
        {
            this->window->draw(*imageShape->GetElement());
        }

        void SfmlWindow::GetEvents()
        {

        }
        void SfmlWindow::ProcessEvents()
        {
            //Should be sent to a parser and then to a 
            sf::Event event;
            sf::Keyboard eventKeyboard;
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
                    std::cout << "Left!" << std::endl;
                    this->mNewShape->GetElement()->move(-SPEED, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    std::cout << "Right!" << std::endl;
                    this->mNewShape->GetElement()->move(SPEED, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    std::cout << "Up!" << std::endl;
                    this->mNewShape->GetElement()->move(0, -SPEED);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    std::cout << "Down!" << std::endl;
                    this->mNewShape->GetElement()->move(0, SPEED);
                }
                if (event.type == sf::Event::Closed)
                {
                    this->window->close();
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