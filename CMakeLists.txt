cmake_minimum_required(VERSION 3.26)
project(BECppObjetsConnectes)

set(CMAKE_CXX_STANDARD 23)

add_executable(BECppObjetsConnectes main.cpp
        ./intellight/Appartement.h
        ./intellight/Appartement.cpp
        ./intellight/Personne.h
        ./intellight/Personne.cpp
        ./intellight/Piece.h
        ./intellight/Piece.cpp
        ./intellight/Principal.h
        ./intellight/Principal.cpp
        ./intellight/Numpad.cpp
        ./intellight/Numpad.h
)

