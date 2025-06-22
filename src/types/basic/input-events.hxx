#ifndef INPUT_EVENT_TYPES_HXX
#define INPUT_EVENT_TYPES_HXX

enum EventInputTypeEnum
{
    mouse,
    keyboard
};

enum EventKeyboardTypeEnum
{
    Right,
    Left,
    Up,
    Down
};

struct InputTypeEvent
{
    EventInputTypeEnum type;
    EventKeyboardTypeEnum keypressed;
    bool alt = false;
    bool control = false;
    bool shift = false;
    bool system = false;
};

#endif