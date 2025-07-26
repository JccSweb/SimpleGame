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
                std::shared_ptr<Ui::Components::IBaseComponent> GetElementRepresentation() override;
                std::string GetName() override;
                void Move(const Movement &move) override;
                void GetElementPosition() override;
                const double GetElementSpeed() override;
                void SetElementSpeed(double newSpeed) override;
                void SetCharacteristics() override;
            };
        }
    }

}
