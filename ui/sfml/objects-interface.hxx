#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../resources/types/enums/objects-enum.hxx"

namespace Ui
{
    namespace Components
    {
        class IBaseComponent 
        {
            public:
            IBaseComponent();
            ~IBaseComponent();
            virtual std::shared_ptr<sf::Shape> GetElement() = 0;
        };

        class ComponentConstrutor 
        {
            public:
                static std::shared_ptr<IBaseComponent> GetInstance(shapesEnum value);
        };
    }
}