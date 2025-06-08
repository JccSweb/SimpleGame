#include "Sfml-window.hxx"
#include <iostream>
#include <SFML/Graphics.hpp>

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
            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);

            sf::Texture texture;
            if (!texture.loadFromFile("img.png", sf::IntRect({10, 10}, {200, 200})))
            {
                std::cout << "Couldn't load image" << std::endl;
            }
            sf::Sprite sprite(texture);

            while (this->window->isOpen())
            {
                sf::Event event;
                while (bool value = this->window->pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        this->window->close();
                    }
                }

                this->window->clear();
                this->window->draw(sprite);
                this->window->draw(shape);
                this->window->display();
            }
        }

        SfmlWindow::SfmlWindow(Widht width, Height height)
        {
            this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode({width, height}), "Hello World");
        }

        SfmlWindow::~SfmlWindow()
        {
            // destrutor
        }
    }
}