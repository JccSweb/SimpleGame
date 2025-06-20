#pragma once
#include "game-core/game-elements/characters/characters-interface/characters-interface.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Characters
        {
            class MainCharacter : public ICharacters
            {
            public:
                MainCharacter();
                virtual void mReceiveEvent(InputTypeEvent event);                
            };
        }
    }
}