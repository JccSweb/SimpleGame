#include "rectangular.hxx"

namespace Ui
{
    namespace Components
    {
        RectangularComponent::RectangularComponent()
        {
            this->mShape = std::make_shared<sf::RectangleShape>();
        };

        std::shared_ptr<sf::Drawable> RectangularComponent::GetElement()
        {
            return this->mShape;
        }
        void RectangularComponent::SetFillColor(const Color& color)
        {
        }
        void RectangularComponent::SetOutlineColor(const Color& color)
        {
        }
        void RectangularComponent::Move(const Movement& move)
        {
            this->mShape->move(move.x, move.y);
        }
        void RectangularComponent::SetRadius(float rad)
        {
        }
        Movement RectangularComponent::GetPosition()
        {
            Movement move;
            sf::Vector2f vect = this->mShape->getPosition();
            move.x = vect.x;
            move.y = vect.y;
            return move;
        }
    }
}