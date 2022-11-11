#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include <iostream>
#include <string>

using namespace ftxui;
//test comment push from vscode
int main(int, char**) {
    int value = 50;

    auto buttons = Container::Horizontal(
        {Button("Decrease", [&] { value--; }),
         Button("Increase", [&] { value++; })}
    );

    auto component = Renderer(buttons, [&] {
        return vbox(
                   {text("value = " + std::to_string(value)),
                    separator(),
                    gauge(value * 0.01f),
                    separator(),
                    buttons->Render()}
               ) |
               border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component);
}
