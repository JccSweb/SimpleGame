#pragma once

#include "game-core/game-elements/base-game-elements-interface/base-elements-interface.hxx"
#include "ui/sfml/objects-interface.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Objects
        {
            class IObjects : public IBaseElements
            {
                public:
                IObjects();
                
                private:
                virtual void mReceiveEvent(InputTypeEvent event) = 0;
            };
        }
    }

}
