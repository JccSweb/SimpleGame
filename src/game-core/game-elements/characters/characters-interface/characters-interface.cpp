#include "characters-interface.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Characters
        {
            ICharacters::ICharacters()
            {
            }
            std::shared_ptr<Ui::Components::IBaseComponent> ICharacters::GetElementRepresentation()
            {
                return this->mComponentRepresentation;
            }
            std::string ICharacters::GetName()
            {
                return this->mName;
            }
            void ICharacters::Move(const Movement &move)
            {
                this->mComponentRepresentation->Move(move);
            }

            void ICharacters::GetElementPosition()
            {
                // sf::Vector2f pos = this->mComponentRepresentation->GetElement()->getPosition();
                // std::cout << "On y: " << pos.x << " On y: " << pos.y << std::endl;
            }

            const double ICharacters::GetElementSpeed()
            {
                return this->mBaseSpeed;
            }
            void ICharacters::SetElementSpeed(double newSpeed)
            {
                this->mBaseSpeed = newSpeed;
            }

            void ICharacters::SetCharacteristics()
            {
            }

        }
    }
}
