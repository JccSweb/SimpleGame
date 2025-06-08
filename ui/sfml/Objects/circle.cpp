#include "circle.hxx"

namespace Ui
{
    namespace Shapes
    {
        CircleObject::CircleObject()
        {
            this->shape = std::make_shared<sf::CircleShape>();
        };
        CircleObject::~CircleObject() {

        };

        std::shared_ptr<sf::Drawable> CircleObject::GetShape()
        {
            return this->shape;
        }
    }
}