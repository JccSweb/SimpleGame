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
        
        std::shared_ptr<IBaseComponent> ComponentConstrutor::GetInstance(shapesEnum value)
        {
            std::shared_ptr<IBaseComponent> component = nullptr;

            if (value == shapesEnum::Circle)
            {
                component = std::make_shared<CircleComponent>();
            }
            else if (value == shapesEnum::Rect)
            {
                component = std::make_shared<RectangularComponent>();
            }
            else if (value == shapesEnum::Sprite)
            {
                component = std::make_shared<RectangularComponent>();
            }
            return component;
        }
    }
}