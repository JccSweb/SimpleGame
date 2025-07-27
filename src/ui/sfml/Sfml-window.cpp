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
            /*  // sf::Texture texture;
             // texture.loadFromFile("mapa.png", sf::IntRect(0, 0, 1024, 1024));
             // sf::Sprite sprite(texture);

             // sf::Texture tileset;
             // tileset.loadFromFile("roguelikeSheet_transparent.png");
             sf::VertexArray quad(sf::Quads, 4);

             // Desenha um quadrado no ecrã
             quad[0].position = sf::Vector2f(0, 0);
             quad[1].position = sf::Vector2f(132, 0);
             quad[2].position = sf::Vector2f(132, 132);
             quad[3].position = sf::Vector2f(0, 132);

             // Seleciona a parte da imagem (por exemplo, tile no canto superior esquerdo)
             quad[0].texCoords = sf::Vector2f(0, 0);
             quad[1].texCoords = sf::Vector2f(16, 0);
             quad[2].texCoords = sf::Vector2f(16, 16);
             quad[3].texCoords = sf::Vector2f(0, 16);

             // Quando desenhas, informas a textura usada:
             sf::RenderStates states;
             /* states.texture = &tileset; */

            // No teu ciclo principal de desenho:

            // window->draw(quad, states);


            while (this->mWindow->isOpen())
            {
                this->ProcessEvents(this->mSubject);
                this->mWindow->clear();

                auto elements = this->mState->GetElements();

                for (auto element : elements)
                {
                    if (element.first == "player")
                    {
                        this->mView.setCenter(element.second->GetPositionBySfVector());
                    }
                    this->mWindow->setView(this->mView);
                    std::cout << element.first << std::endl;
                    this->Draw(element.second);
                }
                this->mWindow->display();
            }
        }

        SfmlWindow::SfmlWindow()
        {
            Width width = 600;
            Height height = 600;
            std::string title = "Hello World";
            this->mWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode({width, height}), title);
            this->mSubject = Game::UiSubject::GetInstance();
            this->mState = World::WorldState::GetInstance();
            this->mView = this->mWindow->getDefaultView();
            //sf::View view1(sf::FloatRect({0.f, 0.f}, {600.0f, 600.0f}));
        }

        void SfmlWindow::Draw(const std::shared_ptr<Components::IBaseComponent> &imageShape)
        {
            this->mWindow->draw(*imageShape->GetElement());
        }

        void SfmlWindow::GetEvents()
        {
        }
        void SfmlWindow::ProcessEvents(const std::shared_ptr<Game::UiSubject> &subject)
        {

            sf::Event event;
            while (bool value = this->mWindow->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    this->mWindow->close();
                    this->mGameController->SetStatus(false);
                }

                // Review: It was possible to receive the input from more than two keys
                // Now it only processes one, and only when it's pressed, not while it's pressed.
                // Todo: look at commit: 8618ca4e261bc5caeef95c1bf4344f5a9ed46e0c

                if (event.type == sf::Event::KeyPressed)
                {
                    InputTypeEvent pEvent = this->ParseKeyPressedEvent(event);
                    subject->Notify(pEvent);
                }
            }
        }

        InputTypeEvent SfmlWindow::ParseKeyPressedEvent(sf::Event event)
        {

            std::cout << "Window: " << event.key.code << std::endl;
            InputTypeEvent inputEvent;
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                inputEvent.keypressed = EventKeyboardTypeEnum::left;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Right:
                inputEvent.keypressed = EventKeyboardTypeEnum::right;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Up:
                inputEvent.keypressed = EventKeyboardTypeEnum::up;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            case sf::Keyboard::Down:
                inputEvent.keypressed = EventKeyboardTypeEnum::down;
                inputEvent.type = EventInputTypeEnum::keyboard;
                break;
            default:
                break;
            }
            if (event.key.shift)
            {
                inputEvent.shift = true;
            }
            return inputEvent;
        }
    }
}
