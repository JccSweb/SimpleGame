#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../types/enums/objects-enum.hxx"

namespace Ui
{
    namespace Components
    {
        class IBaseComponent 
        {
            public:
            IBaseComponent();
            ~IBaseComponent();
            std::shared_ptr<sf::Shape> GetElement();
            protected:
            std::shared_ptr<sf::Shape> mShape;
        };

        class ComponentConstrutor 
        {
            public:
                static std::shared_ptr<IBaseComponent> GetInstance(shapesEnum value);
        };
    }
}