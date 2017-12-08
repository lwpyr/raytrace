cmake_minimum_required(VERSION 3.5)
project(ray_tracer)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_EXE_LINKER_FLAGS  "-lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread")
add_executable(tracer
        main.cpp
        Core/Vector3.cpp
        Core/Vector3.h
        Core/Ray3.cpp
        Core/Ray3.h
        Core/Color3.cpp
        Core/Color3.h
        Object/Object.h
        Intersection.h
        Object/Material/Material.h
        Core/LightRay3.cpp
        Core/LightRay3.h Camera.cpp
        Camera.h
        Canvas.cpp
        Canvas.h
        Core/Pixel2.cpp
        Core/Pixel2.h
        Core/Vector2.h
        Object/LightSource/LightSource.h
        Tracer.cpp
        Tracer.h
        Render.cpp
        Render.h
        Object/Material/DefaultMaterial.h
        Object/Material/DefaultMaterial.cpp
        Object/InfinitePlane.cpp
        Object/InfinitePlane.h
        Object/LightSource/SunLight.cpp
        Object/LightSource/SunLight.h Object/Material/Phong.cpp Object/Material/Phong.h)
target_link_libraries(tracer ${CMAKE_EXE_LINKER_FLAGS})
message(${PROJECT_SOURCE_DIR})
