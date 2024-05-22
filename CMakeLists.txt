add_library(langkit STATIC
    "src/lexer.cpp"
)
target_include_directories(langkit PUBLIC include)
