cmake_minimum_required(VERSION 3.10.0)

project(Calculator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_SRC
    src/main.cpp
    src/Tokenizer.cpp
    src/NumberToken.cpp
    src/FunctionToken.cpp
    src/OperatorToken.cpp
    src/LBracketToken.cpp
    src/RBracketToken.cpp
    src/UnaryNode.cpp
    src/InfixOpNode.cpp
    src/FloatNode.cpp
    src/Parser.cpp
    )

set(TARGET_H
    src/Tokenizer.hpp
    src/Token.hpp
    src/NumberToken.hpp
    src/FunctionToken.hpp
    src/OperatorToken.hpp
    src/LBracketToken.hpp
    src/RBracketToken.hpp
    src/UnaryNode.hpp
    src/InfixOpNode.hpp
    src/FloatNode.hpp
    src/Node.hpp
    src/Parser.hpp
)

add_executable(Calculator ${TARGET_SRC} ${TARGET_H})

include(CTest)
enable_testing()

