cmake_minimum_required(VERSION 3.26)
project(BECppObjetsConnectes)

set(CMAKE_CXX_STANDARD 23)

add_executable(BECppObjetsConnectes main.cpp
        Piece.h
        Piece.cpp
        Personne.h
        Personne.cpp
        Appartement.h
        Appartement.cpp)
