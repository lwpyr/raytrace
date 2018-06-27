# ---- build option ----#
set(BUILD_WITH_OPENGL 1)
set(BUILD_WITH_OPENCV 1)
# ---- build option ----#

cmake_minimum_required(VERSION 3.5)
project(ray_tracer)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_EXE_LINKER_FLAGS)

set(SOURCE_FILES Core/Vector3.cpp
        Core/Vector3.h
        Core/Ray3.cpp
        Core/Ray3.h
        Core/Color3.cpp
        Core/Color3.h
        Object/Object.h
        Intersection.h
        Object/Material/Material.h
        Object/Light/LightRay3.cpp
        Object/Light/LightRay3.h Camera.cpp
        Camera.h
        Canvas.cpp
        Canvas.h
        Core/Pixel2.cpp
        Core/Pixel2.h
        Core/Vector2.h
        Object/LightSource/LightSource.h
        Tracer.cpp
        Tracer.h
        Render.h
        Render_cv.h
        Render_gl.h
        Object/Material/DefaultMaterial.h
        Object/Material/DefaultMaterial.cpp
        Object/InfinitePlane.cpp
        Object/InfinitePlane.h
        Object/LightSource/SunLight.cpp
        Object/LightSource/SunLight.h
        Object/Material/Phong.cpp
        Object/Material/Phong.h
        Object/Sphere.cpp
        Object/Sphere.h
        Object/Circle.h
        Object/Circle.cpp
        Object/Cylinder.h
        Object/Cylinder.cpp
        Object/Triangle.cpp
        Object/Triangle.h
        Object/Light/PointLightRay3.cpp
        Object/Light/PointLightRay3.h
        Object/LightSource/PointLightSource.cpp
        Object/LightSource/PointLightSource.h
        Object/Square.cpp
        Object/Square.h)


if(BUILD_WITH_OPENGL)
    find_package( glfw3 REQUIRED)
    set(CMAKE_EXE_LINKER_FLAGS  "-lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread")
    set(SOURCE_FILES ${SOURCE_FILES} Render_gl.cpp)
    message("build with opengl")
    FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Render_cv.h "/*build with gl too!*/")
else()
    FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Render_cv.h "#define CV_ONLY")
    set(CMAKE_EXE_LINKER_FLAGS  "")
    message("build without opengl")
endif()

if(BUILD_WITH_OPENCV)
    find_package( OpenCV REQUIRED )
    set(SOURCE_FILES ${SOURCE_FILES} Render_cv.cpp)
    FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Render_gl.h "/*build with cv too!*/")
    message("build with opencv")
else()
    FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Render_gl.h "#define GL_ONLY")
    message("build without opencv")
endif()

add_executable(tracer_single
        single_multi-lightsource.cpp
        ${SOURCE_FILES})

add_executable(tracer_double
        double_multi-lightsource.cpp
        ${SOURCE_FILES})

add_executable(UnitTest
        UnitTest.cpp
        ${SOURCE_FILES})

add_executable(tracer
        single_lightsource.cpp
        ${SOURCE_FILES})

target_link_libraries(tracer ${CMAKE_EXE_LINKER_FLAGS} ${OpenCV_LIBS} ${CMAKE_EXE_LINKER_FLAGS})
target_link_libraries(tracer_single ${CMAKE_EXE_LINKER_FLAGS} ${OpenCV_LIBS} ${CMAKE_EXE_LINKER_FLAGS})
target_link_libraries(tracer_double ${CMAKE_EXE_LINKER_FLAGS} ${OpenCV_LIBS} ${CMAKE_EXE_LINKER_FLAGS})
target_link_libraries(UnitTest ${CMAKE_EXE_LINKER_FLAGS} ${OpenCV_LIBS})
message(${PROJECT_SOURCE_DIR})
