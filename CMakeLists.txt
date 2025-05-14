cmake_minimum_required(VERSION 3.14)
project(MC 2.0)

include(FetchContent)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(DEPS ${CMAKE_BINARY_DIR}/_deps)
set(SRC ${PROJECT_SOURCE_DIR}/src)

find_package(Vulkan REQUIRED)
find_package(glfw3)

if(glfw3_FOUND)
    message(STATUS "GLFW found")
else()
    message(STATUS "GLFW not found, downloading")
    FetchContent_Declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
    )
    FetchContent_MakeAvailable(glfw)
endif()

find_package(glm)

if(glm_FOUND)
    message(STATUS "GLM found")
else()
    message(STATUS "GLM not found, downloading")
    FetchContent_Declare(glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
    )
    FetchContent_MakeAvailable(glm)
endif()


FetchContent_Declare(stb
    URL https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
    DOWNLOAD_DIR ${CMAKE_BINARY_DIR}/_deps/stb-src
    DOWNLOAD_NO_EXTRACT TRUE
)
FetchContent_MakeAvailable(stb)

add_executable(MC
    ${SRC}/engine/output/window.cpp
    ${SRC}/main.cpp
)

target_include_directories(Engine PRIVATE
    ${glm_SOURCE_DIR}
    ${glfw_SOURCE_DIR}/include
    ${DEPS}/stb-src
)

target_link_libraries(MC
    Vulkan::Vulkan
    glfw
    glm
)
