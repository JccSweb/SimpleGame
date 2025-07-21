
#include "base-elements-interface.hxx"

#include <iostream>

namespace Game
{
    namespace Elements
    {
        IBaseElements::IBaseElements()
        {
            this->mName = "";
        }
        std::shared_ptr<Ui::Components::IBaseComponent> IBaseElements::GetElementRepresentation()
        {
            return this->mComponentRepresentation;
        }
        std::string IBaseElements::GetName()
        {
            return this->mName;
        }
        void IBaseElements::Move(const Movement& move)
        {
            this->mComponentRepresentation->Move(move);
        }

        void IBaseElements::GetElementPosition()
        {
           //sf::Vector2f pos = this->mComponentRepresentation->GetElement()->getPosition();
           //std::cout << "On y: " << pos.x << " On y: " << pos.y << std::endl;
        }
    }   
}