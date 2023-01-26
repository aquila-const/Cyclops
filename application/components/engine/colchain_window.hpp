#include <GLES3/gl3.h>
#include <imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>

//create a class for an opengl window
class Window {
    //constructor
    public:
        Window(int width, int height, const char* name);
};