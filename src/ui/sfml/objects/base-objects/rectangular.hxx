#pragma once
#include "ui/sfml/objects-interface.hxx"

namespace Ui
{
    namespace Components
    {
        class RectangularComponent : public IBaseComponent
        {
        public:
            RectangularComponent();
            std::shared_ptr<sf::Drawable> GetElement();
            void SetFillColor(Color color);
            void SetOutlineColor(Color color);
            void Move(Movement move);

        private:
            std::shared_ptr<sf::RectangleShape> mShape;
        };
    }
}
