#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

#include "types/enums/objects-enum.hxx"
#include "types/basic/movement.hxx"
#include "types/basic/color.hxx"

namespace Ui
{
    namespace Components
    {
        class IBaseComponent
        {
        public:
            IBaseComponent();

            void Move(Movement move);
            virtual std::shared_ptr<sf::Drawable> GetElement() = 0;
            virtual void SetFillColor(Color color) = 0;
            virtual void SetOutlineColor(Color color) = 0;
        };

        class ComponentConstrutor
        {
        public:
            static std::shared_ptr<IBaseComponent> GetInstance(shapesEnum value);
        };
    }
}