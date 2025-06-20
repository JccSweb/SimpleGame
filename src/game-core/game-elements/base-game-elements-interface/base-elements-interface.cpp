
#include "base-elements-interface.hxx"

namespace Game
{
    namespace Elements
    {
        IBaseElements::IBaseElements()
        {
            this->name = "";
        }
        std::shared_ptr<Ui::Components::IBaseComponent> IBaseElements::GetElementRepresentation()
        {
            return this->mComponentRepresentation;
        }
        std::string IBaseElements::GetName()
        {
            return this->name;
        }
    }
}
