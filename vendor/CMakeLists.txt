# Copyright (c) 2019-2021, Arm Limited and Contributors
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 the "License";
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.10)

project(vendor LANGUAGES C CXX)

# glm
add_library(glm INTERFACE)
set(GLM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm)
target_sources(glm INTERFACE ${GLM_DIR}/glm/glm.hpp)
target_include_directories(glm INTERFACE ${GLM_DIR})

target_compile_definitions(glm INTERFACE
    GLM_FORCE_SWIZZLE
    GLM_FORCE_RADIANS
    GLM_FORCE_CTOR_INIT
    GLM_ENABLE_EXPERIMENTAL
)
if(NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(glm INTERFACE GLM_FORCE_CXX14)
endif()

# tinygltf
add_library(tinygltf INTERFACE)
set(TINYGLTF_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tinygltf)
target_sources(tinygltf INTERFACE ${TINYGLTF_DIR}/tiny_gltf.h ${TINYGLTF_DIR}/json.hpp)
target_include_directories(tinygltf INTERFACE ${TINYGLTF_DIR})

# # vulkan
# add_library(vulkan INTERFACE)
# set(VULKAN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vulkan/include)
# target_sources(vulkan INTERFACE ${VULKAN_INCLUDE_DIR}/vulkan/vulkan.h)
# target_include_directories(vulkan INTERFACE ${VULKAN_INCLUDE_DIR})

# target_compile_definitions(vulkan INTERFACE VK_NO_PROTOTYPES)

# imgui
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(IMGUI_FILES
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/imconfig.h"
    "${IMGUI_DIR}/imgui.h"
    "${IMGUI_DIR}/imgui_internal.h"
    "${IMGUI_DIR}/imstb_rectpack.h"
    "${IMGUI_DIR}/imstb_textedit.h"
    "${IMGUI_DIR}/imstb_truetype.h")

add_library(imgui STATIC ${IMGUI_FILES})

target_include_directories(imgui PUBLIC ${IMGUI_DIR})

set_property(TARGET imgui PROPERTY FOLDER "vendor")

# glslang
# option(ENABLE_SPVREMAPPER OFF)
# option(ENABLE_GLSLANG_BINARIES OFF)
# set(ENABLE_HLSL ON)
# option(ENABLE_OPT OFF)
# option(BUILD_TESTING OFF)
# option(BUILD_EXTERNAL OFF)

# add_subdirectory(glslang)

# if (NOT TARGET glslang-default-resource-limits)
#     add_library(glslang-default-resource-limits
#                 glslang/StandAlone/ResourceLimits.cpp)

#     set_property(TARGET glslang-default-resource-limits PROPERTY FOLDER "vendor")
    
#     target_include_directories(glslang-default-resource-limits
#                                 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glslang/StandAlone)
# endif()

# if(NOT MSVC)
#     target_compile_options(glslang PRIVATE
#         "-Wno-logical-op-parentheses"
#         "-Wno-unused-parameter")

#     target_compile_options(SPIRV PRIVATE
#         "-Wno-logical-op-parentheses"
#         "-Wno-unused-parameter")
# endif()

# set_property(TARGET glslang PROPERTY FOLDER "vendor")