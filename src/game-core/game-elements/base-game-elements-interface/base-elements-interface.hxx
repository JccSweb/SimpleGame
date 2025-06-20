#pragma once

#include "ui/sfml/objects-interface.hxx"
#include "types/basic/input-events.hxx"

namespace Game
{
    namespace Elements
    {
        class IBaseElements
        {
        public:
            IBaseElements();
            virtual void mReceiveEvent(InputTypeEvent event) = 0;
            std::shared_ptr<Ui::Components::IBaseComponent> GetElementRepresentation();
            std::string GetName();

        protected:
            std::shared_ptr<Ui::Components::IBaseComponent> mComponentRepresentation = nullptr;
            std::string name;
        };
    }
}