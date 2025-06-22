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
        void SpriteComponent::SetFillColor(Color color)
        {
        }
        void SpriteComponent::SetOutlineColor(Color color)
        {
        }
        void SpriteComponent::Move(Movement move)
        {
            this->mShape->move(move.x, move.y);
        }
    }
}