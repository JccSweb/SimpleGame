#include "sprite.hxx"

namespace Ui
{
    namespace Components
    {
        SpriteComponent::SpriteComponent()
        {
            this->mShape = std::make_shared<sf::Sprite>();
        };
        std::shared_ptr<sf::Drawable> SpriteComponent::GetElement()
        {
            return this->mShape;
        }
        void SpriteComponent::SetFillColor(const Color& color)
        {
        }
        void SpriteComponent::SetOutlineColor(const Color& color)
        {
        }
        void SpriteComponent::Move(const Movement& move)
        {
            this->mShape->move(move.x, move.y);
        }
        void SpriteComponent::SetRadius(float rad)
        {
        }
        Movement SpriteComponent::GetPosition()
        {
            Movement move;
            sf::Vector2f vect = this->GetPositionBySfVector();
            move.x = vect.x;
            move.y = vect.y;
            return move;
        }
        sf::Vector2f SpriteComponent::GetPositionBySfVector()
        {
            return this->mShape->getPosition();
        }
        void SpriteComponent::SetSize(Width width, Height height)
        {
        }
    }
}