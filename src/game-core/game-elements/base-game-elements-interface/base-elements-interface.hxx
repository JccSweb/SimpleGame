#pragma once

#include "ui/sfml/objects-interface.hxx"
#include "types/basic/input-events.hxx"
#include "types/basic/movement.hxx"

namespace Game
{
    namespace Elements
    {
        class IBaseElements
        {
        public:
            virtual ~IBaseElements() = default;
            virtual std::shared_ptr<Ui::Components::IBaseComponent> GetElementRepresentation() = 0;
            virtual std::string GetName() = 0;
            virtual void Move(const Movement& move) = 0;
            virtual void GetElementPosition() = 0;
            virtual const double GetElementSpeed() = 0;
            virtual void SetElementSpeed(double newSpeed) = 0;
            virtual void SetCharacteristics() = 0;

        protected:
            std::shared_ptr<Ui::Components::IBaseComponent> mComponentRepresentation = nullptr;
            std::string mName;
            bool mIsMoveable{false};
            bool mIsActionable{false};
            double mBaseSpeed{0};
            float mXPosition{0};
            float mYPosition{0};
           
        };
    }
}