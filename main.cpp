#include <SFML/Graphics.hpp>
#include "ui/sfml/Sfml-window.hxx"


int main()
{
    auto factory = Ui::WindowFactory();
    std::shared_ptr<Ui::IAbstractWindow> ui = factory.GetUi(800, 1000);
    ui->Render();
}