cmake_minimum_required(VERSION 3.20) #current version
project(cyclops C CXX)

# FETCH CONTENT LIBS
include(FetchContent) 
FetchContent_Declare(iir GIT_REPOSITORY https://github.com/berndporr/iir1) 
FetchContent_MakeAvailable(iir)
## Find dependencies
find_package(glfw3 CONFIG REQUIRED)
find_package(glew REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Freetype CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(main_dir application)
set(components_dir ${main_dir}/components)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES")
file(GLOB sources ${main_dir}/*.cpp ${components_dir}/*.cpp ${components_dir}/engine/*.cpp)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
    freetype
    glfw
    iir
    glad::glad
    glm::glm
    GLEW::GLEW
    imgui::imgui
    implot::implot
)
target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)