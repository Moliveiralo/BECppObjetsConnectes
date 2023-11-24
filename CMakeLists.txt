cmake_minimum_required(VERSION 3.26)
project(BECppObjetsConnectes)

set(CMAKE_CXX_STANDARD 23)

add_executable(BECppObjetsConnectes main.cpp
        Piece.h
        Piece.cpp
        Personne.h
        Personne.cpp
        Appartement.h
        Appartement.cpp
        Visiteur.cpp
        Visiteur.h)


## On spécifie la version minimale de CMake
#cmake_minimum_required(VERSION 3.23)
#
## On définit le nom du projet
#set(PROJECT_NAME "JeuDeDames")
## set(PROJECT_NAME "Gameboard Galore")
#project(${PROJECT_NAME})
#
## On spécifie les répertoires où chercher les bibliothèques SFML et TGUI
#set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML/lib/cmake/SFML")
#set(TGUI_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/TGUI/lib/cmake/TGUI")
#
## On copie tous les fichiers .dll requis dans le dossier de sortie
#file(GLOB ALL_REQUIRED_DLL "libs/required_dlls/*.dll")
#file(COPY ${ALL_REQUIRED_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#
## On copie tous les fichiers .dll de TGUI dans le dossier de sortie
#file(GLOB TGUI_DLL "libs/TGUI/bin/*.dll")
#file(COPY ${TGUI_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#
## On spécifie le standard C++ à utiliser
#set(CMAKE_CXX_STANDARD 17)
#
## On lie la bibliothèque stdc++fs pour gérer les fichiers
#link_libraries(stdc++fs)
#
## On cherche tous les fichiers source et header dans le dossier src
#file(GLOB_RECURSE SCRF "src/*.cpp" "src/*.hpp")
#
## On ajoute l'icône de l'application à l'exécutable sous Windows
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")
#add_executable(${PROJECT_NAME}
#        WIN32
#        main.cpp
#        ${APP_ICON_RESOURCE_WINDOWS}
#)
#
## On recherche les bibliothèques SFML nécessaires pour le projet
#find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
#
## On recherche la bibliothèque TGUI nécessaire pour le projet
#find_package(TGUI 0.9 REQUIRED)
#
## On lie les bibliothèques nécessaires à l'exécutable
#target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system tgui)
