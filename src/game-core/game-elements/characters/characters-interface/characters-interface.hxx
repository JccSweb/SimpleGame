#pragma once

#include "game-core/game-elements/base-game-elements-interface/base-elements-interface.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Characters
        {
            class ICharacters : public Elements::IBaseElements
            {
                public:
                ICharacters();
                virtual void mReceiveEvent(PlayerEvent event) = 0;
            };
        }
    }
}