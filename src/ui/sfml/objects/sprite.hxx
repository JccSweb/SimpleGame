#pragma once

#include "ui/sfml/objects-interface.hxx"

namespace Ui
{
    namespace Components
    {
        class SpriteComponent : public IBaseComponent
        {
        public:
            SpriteComponent();
            std::shared_ptr<sf::Drawable> GetElement() override;
            void SetFillColor(Color color);
            void SetOutlineColor(Color color);
            void Move(Movement move);

        private:
            std::shared_ptr<sf::Sprite> mShape;
        };
    }
}