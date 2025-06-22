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
        void RectangularComponent::SetFillColor(Color color)
        {
        }
        void RectangularComponent::SetOutlineColor(Color color)
        {
        }
    }
}