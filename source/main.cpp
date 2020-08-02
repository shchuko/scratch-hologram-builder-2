#include <iostream>

#include <simple_svg_1.0.0.hpp>
#include <tiny_obj_loader.h>
#include <GL/glui.h>
#include <GL/glut.h>
#include <boost/program_options.hpp>
#include <CExampleClass.hpp>

int main(int argc, char *argv[]) {
    std::cout << "Hello, I'm alive!" << std::endl;
    std::cout << "Project root: " << PROJECT_SOURCE_DIR_DEF << std::endl;
    std::cout << "Project version: " << PROJECT_VERSION_DEF << std::endl;
    std::cout << "Project test resources root: " << TEST_RESOURCES_DIR_DEF << std::endl;
}
