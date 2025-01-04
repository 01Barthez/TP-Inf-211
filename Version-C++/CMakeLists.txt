cmake_minimum_required(VERSION 3.10)
project(SupermarketSystem)

# Spécifier le standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vérifier si nous sommes sur un système Unix-like
if(UNIX)
    # Utiliser pkg-config pour trouver uuid
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(UUID REQUIRED uuid)
endif()

# Ajouter le répertoire include
include_directories(${PROJECT_SOURCE_DIR}/include)

# Ajouter l'exécutable
add_executable(supermarket_app
    src/main.cpp
)

# Lier avec la bibliothèque UUID
if(UNIX)
    target_link_libraries(supermarket_app uuid)
endif()
