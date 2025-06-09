#include <memory>
#include "objects-interface.hxx"
#include "Objects/circle.hxx"

namespace Ui
{
    namespace Components
    {
        IBaseComponent::IBaseComponent()
        {

        }
        IBaseComponent::~IBaseComponent()
        {

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