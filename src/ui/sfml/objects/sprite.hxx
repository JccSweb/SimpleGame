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
            void SetFillColor(const Color& color);
            void SetOutlineColor(const Color& color);
            void Move(const Movement& move);
            void SetRadius(float rad);
            Movement GetPosition();

        private:
            std::shared_ptr<sf::Sprite> mShape;
        };
    }
}