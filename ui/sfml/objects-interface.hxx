#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../resources/types/enums/objects-enum.hxx"

namespace Ui
{
    namespace Shapes
    {
        class IBaseShape 
        {
            public:
            IBaseShape();
            ~IBaseShape();
            virtual std::shared_ptr<sf::Drawable> GetShape() = 0;
        };

/*         class SpriteObject : public sf::Sprite, IBaseShape
        {
            SpriteObject();
            ~SpriteObject()
        }; */

        class ShapeConstrutor 
        {
            public:
            static std::shared_ptr<IBaseShape> GetInstance(shapesEnum value);
        };
    }
}