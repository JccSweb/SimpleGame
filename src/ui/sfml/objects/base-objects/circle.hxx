#pragma once
#include "ui/sfml/objects-interface.hxx"

namespace Ui
{
    namespace Components
    {
        class CircleComponent : public IBaseComponent
        {
        public:
            CircleComponent();
            std::shared_ptr<sf::Drawable> GetElement();
            void SetFillColor(Color color);
            void SetOutlineColor(Color color);
        private:
            std::shared_ptr<sf::CircleShape> mShape;
        };
    }
}
