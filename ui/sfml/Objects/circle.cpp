#include "circle.hxx"

namespace Ui
{
    namespace Components
    {
        CircleComponent::CircleComponent()
        {
            this->mShape = std::make_shared<sf::CircleShape>(100.f);
            this->mShape->setFillColor(sf::Color::Green);
            this->mShape->setPosition(100, 100);
        };
        CircleComponent::~CircleComponent() {

        };

        std::shared_ptr<sf::Shape> CircleComponent::GetElement()
        {
            return this->mShape;
        }
    }
}