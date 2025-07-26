#include "main-objects-interface.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Objects
        {
            IObjects::IObjects() 
            {
            };
            std::shared_ptr<Ui::Components::IBaseComponent> IObjects::GetElementRepresentation()
            {
                return this->mComponentRepresentation;
            }
            std::string IObjects::GetName()
            {
                return this->mName;
            }
            void IObjects::Move(const Movement &move)
            {
                this->mComponentRepresentation->Move(move);
            }

            void IObjects::GetElementPosition()
            {
                // sf::Vector2f pos = this->mComponentRepresentation->GetElement()->getPosition();
                // std::cout << "On y: " << pos.x << " On y: " << pos.y << std::endl;
            }

            const double IObjects::GetElementSpeed()
            {
                return this->mBaseSpeed;
            }
            void IObjects::SetElementSpeed(double newSpeed)
            {
                this->mBaseSpeed = newSpeed;
            }


            void IObjects::SetCharacteristics()
            {
                
            }
        }
    }
}
