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
            void SetFillColor(const Color& color);
            void SetOutlineColor(const Color& color);
            void Move(const Movement& move);
            void SetRadius(float rad);
            Movement GetPosition();

        private:
            std::shared_ptr<sf::RectangleShape> mShape;
        };
    }
}
