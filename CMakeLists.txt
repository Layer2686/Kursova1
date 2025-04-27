cmake_minimum_required(VERSION 3.30)
project(KursovaCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(KursovaCPP main.cpp
        CUser.cpp
        CUser.h
        CProduct.cpp
        CProduct.h
        Catalog.cpp
        Catalog.h
        CAdmin.cpp
        CAdmin.h
        CBuyer.cpp
        CBuyer.h)
