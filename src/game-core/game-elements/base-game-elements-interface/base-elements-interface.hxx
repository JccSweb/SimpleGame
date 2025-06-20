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

        private:
            //std::shared_ptr<Ui::Components::IBaseComponent> mRepresentation;
        };
    }
}