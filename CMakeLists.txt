cmake_minimum_required(VERSION 3.24.0) #current version
project(cyclops C CXX)

## Find dependencies
find_package(glfw3 CONFIG REQUIRED)
find_package(glew REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Freetype CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")

add_executable(${PROJECT_NAME} application/main.cpp)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
    freetype
    glfw
    glad::glad
    glm::glm
    GLEW::GLEW
    imgui::imgui
)
target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)