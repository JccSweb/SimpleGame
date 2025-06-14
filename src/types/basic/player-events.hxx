#pragma once
#include <string>

enum PlayerEventType
{
    mouse,
    keyboard
};

struct PlayerEvent
{
    PlayerEventType type;
    std::string keypressed;
    bool alt = false;
    bool control = false;
    bool shift = false;
    bool system = false;
};
