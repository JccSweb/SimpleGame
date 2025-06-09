#include "../objects-interface.hxx"

namespace Ui
{
    namespace Components
    {
        class CircleComponent : public IBaseComponent
        {
        public:
            CircleComponent();
            ~CircleComponent();
            std::shared_ptr<sf::Shape> GetElement();

        private:
            std::shared_ptr<sf::Shape> mShape;

        };
    }
}