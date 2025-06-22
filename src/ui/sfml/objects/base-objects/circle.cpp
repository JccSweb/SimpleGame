#include "circle.hxx"

namespace Ui
{
    namespace Components
    {
        CircleComponent::CircleComponent()
        {
            this->mShape = std::make_shared<sf::CircleShape>();
        };

        std::shared_ptr<sf::Drawable> CircleComponent::GetElement()
        {
            return this->mShape;
        }
        void CircleComponent::SetFillColor(Color color)
        {
        }
        void CircleComponent::SetOutlineColor(Color color)
        {
        }
        void CircleComponent::Move(Movement move)
        {
            this->mShape->move(move.x, move.y);
        }
    }
}