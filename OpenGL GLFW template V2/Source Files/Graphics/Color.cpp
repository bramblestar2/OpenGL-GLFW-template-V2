#include "../../Headers/Graphics/Color.h"

jf::Color jf::Color::toGL()
{
    return Color(r / 255, g / 255, b / 255, a / 255);
}