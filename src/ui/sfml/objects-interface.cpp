#include <memory>
#include "objects-interface.hxx"
#include "ui/sfml/objects/circle.hxx"

namespace Ui
{
    namespace Components
    {
        IBaseComponent::IBaseComponent()
        {

        }

        std::shared_ptr<sf::Shape> IBaseComponent::GetElement()
        {
            return this->mShape;
        }

        std::shared_ptr<IBaseComponent> ComponentConstrutor::GetInstance(shapesEnum value)
        {
            if(value == shapesEnum::Circle)
            {
                return std::make_shared<CircleComponent>();
            }
            return std::make_shared<CircleComponent>();
        }
    }
}