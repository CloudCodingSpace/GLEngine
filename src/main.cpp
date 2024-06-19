#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "engine/ge.hpp"

int main(void) {
    try {
        GLEngine engine(GE_STD_WINDOW_WIDTH, GE_STD_WINDOW_HEIGHT, "GLEngine");
        engine.Run();
        engine.Cleanup();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cin.get();
        return EXIT_FAILURE;
    }

    std::cin.get();
    return EXIT_SUCCESS;
}