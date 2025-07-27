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
        void CircleComponent::SetFillColor(const Color& color)
        {
        }
        void CircleComponent::SetOutlineColor(const Color& color)
        {
        }
        void CircleComponent::Move(const Movement& move)
        {
            this->mShape->move(move.x, move.y);
        }
        void CircleComponent::SetRadius(float rad)
        {
            this->mShape->setRadius(rad);
        }
        Movement CircleComponent::GetPosition()
        {
            Movement move;
            sf::Vector2f vect = this->GetPositionBySfVector();
            move.x = vect.x;
            move.y = vect.y;
            return move;
        }
        sf::Vector2f CircleComponent::GetPositionBySfVector()
        {
            return this->mShape->getPosition();
        }
        void CircleComponent::SetSize(Width width, Height height)
        {
            
        }
    }
}