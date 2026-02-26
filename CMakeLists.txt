# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Название проекта - можно оставить ProjectName или изменить, например, BankSystem
project(BankSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем, где искать заголовочные файлы (.h)
include_directories(include)

# Указываем, какие файлы собирать в исполняемый файл
add_executable(${PROJECT_NAME}
    main.cpp
    src/BankAccount.cpp
    src/Bank.cpp
    include/BankAccount.h
    include/Bank.h
)