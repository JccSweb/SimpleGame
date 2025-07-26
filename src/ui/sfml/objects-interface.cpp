#include <memory>
#include "objects-interface.hxx"
#include "ui/sfml/objects/base-objects/circle.hxx"
#include "ui/sfml/objects/base-objects/rectangular.hxx"

namespace Ui
{
    namespace Components
    {
        IBaseComponent::IBaseComponent()
        {
        }
        
        std::shared_ptr<IBaseComponent> ComponentConstrutor::GetInstance(ShapesEnum value)
        {
            std::shared_ptr<IBaseComponent> component = nullptr;

            if (value == ShapesEnum::circle)
            {
                component = std::make_shared<CircleComponent>();
            }
            else if (value == ShapesEnum::rect)
            {
                component = std::make_shared<RectangularComponent>();
            }
            else if (value == ShapesEnum::sprite)
            {
                component = std::make_shared<RectangularComponent>();
            }
            return component;
        }
    }
}