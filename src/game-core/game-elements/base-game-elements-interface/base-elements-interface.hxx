#pragma once

#include "ui/sfml/objects-interface.hxx"
#include "types/basic/player-events.hxx"

namespace Game
{
    namespace Elements
    {
        class IBaseElements
        {
        public:
            IBaseElements();
            virtual void mReceiveEvent(PlayerEvent event) = 0;

        private:
            //std::shared_ptr<Ui::Components::IBaseComponent> mRepresentation;
        };
    }
}