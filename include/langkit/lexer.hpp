#pragma once
#include <langkit/ipositional.hpp>
#include <memory>
#include <istream>
#include <filesystem>
#include <functional>
#include <vector>

namespace LangKit
{
    class Lexer : protected IPositional
    {
    private:
        std::unique_ptr<std::istream> stream;

    public:
        Lexer() = delete;
        Lexer(const std::filesystem::path &path);
        Lexer(std::unique_ptr<std::istream> stream);

    protected:
        inline bool eof() const { return stream->peek() == EOF; }
        char peek() const;
        char get();
    };
}
