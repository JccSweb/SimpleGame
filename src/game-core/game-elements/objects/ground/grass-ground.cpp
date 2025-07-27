#include "grass-ground.hxx"

namespace Game
{
    namespace Elements
    {
        namespace Objects
        {
           GrassGround::GrassGround()
           {
                this->mComponentRepresentation = Ui::Components::ComponentConstrutor::GetInstance(Ui::Components::ShapesEnum::rect);
                Color green{128, 128, 0, 255};
                this->mComponentRepresentation->SetFillColor(green);
                this->mComponentRepresentation->SetSize(1024,1024);
                this->mName = "Grass";
           }
        }
    }
}
