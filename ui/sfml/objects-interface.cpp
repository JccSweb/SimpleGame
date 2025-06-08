#include <memory>
#include "objects-interface.hxx"
#include "Objects/circle.hxx"

namespace Ui
{
    namespace Shapes
    {
        IBaseShape::IBaseShape()
        {

        }
        IBaseShape::~IBaseShape()
        {

        }
        
        std::shared_ptr<IBaseShape> ShapeConstrutor::GetInstance(shapesEnum value)
        {
            if(value == shapesEnum::Circle)
            {
                return std::make_shared<CircleObject>();
            }
            return std::make_shared<CircleObject>();
        }
    }
}