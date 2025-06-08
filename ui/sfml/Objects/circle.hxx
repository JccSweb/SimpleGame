#include "../objects-interface.hxx"

namespace Ui
{
    namespace Shapes
    {
        class CircleObject : public sf::CircleShape, public IBaseShape
        {
        public:
            CircleObject();
            ~CircleObject();
            std::shared_ptr<sf::Drawable> GetShape() override;

        private:
            std::shared_ptr<sf::Drawable> shape;
        };
    }
}