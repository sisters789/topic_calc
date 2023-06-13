add_library(calculator SHARED calculator.cpp)
add_library(scientific SHARED scientific.cpp)

# State that anybody linking to MathFunctions needs to include the
# current source directory, while MathFunctions itself doesn't.
# Hint: Use target_include_directories with the INTERFACE keyword
target_include_directories(calculator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(scientific INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})