#include <thread>
#include <SFML/Graphics.hpp>
#include "ui/sfml/Sfml-window.hxx"
#include "game-core/game-core.hxx"



void StartGame()
{
    auto game = Game::GameCore();
    game.Start();
}

int main()
{
    std::thread gameWorker(StartGame);
    auto factory = Ui::WindowFactory();
    std::shared_ptr<Ui::IAbstractWindow> ui = factory.GetUi(800, 800);
    try
    {
        ui->Render();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    gameWorker.join();
    std::cout << "Finished!!\n";
}