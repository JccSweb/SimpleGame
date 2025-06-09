#include "circle.hxx"

namespace Ui
{
    namespace Components
    {
        CircleComponent::CircleComponent()
        {
            this->mShape = std::make_shared<sf::CircleShape>(100.f);
            this->mShape->setFillColor(sf::Color::Green);
        };
        CircleComponent::~CircleComponent() {

        };
    }
}