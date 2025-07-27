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
            sf::Color convert(color.red, color.green, color.blue, color.alpha);
            this->mShape->setFillColor(convert);
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
            sf::Vector2f vect = this->GetPositionBySfVector();
            move.x = vect.x;
            move.y = vect.y;
            return move;
        }
        sf::Vector2f RectangularComponent::GetPositionBySfVector()
        {
            return this->mShape->getPosition();
        }

        void RectangularComponent::SetSize(Width width, Height height)
        {
            this->mShape->setSize(sf::Vector2f(width, height));
        }
    }
}