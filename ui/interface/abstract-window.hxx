#pragma once
#include <memory>
#include "../../resources/typedefinitions.hxx"

namespace Ui
{
    class IAbstractWindow
    {
    public:
        virtual void Render() = 0;
        ~IAbstractWindow();

    protected:
        IAbstractWindow();
    };

    class WindowFactory
    {
    public:
        static std::shared_ptr<IAbstractWindow> GetUi(Widht width, Height height);
    };
}
