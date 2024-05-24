#include <langkit/lexer.hpp>
#include <stdexcept>
#include <fstream>

using namespace std;
using namespace LangKit;

Lexer::Lexer(const filesystem::path& path)
{
    if (!filesystem::exists(path))
    {
        throw invalid_argument("path does not exist");
    }
    stream = move(make_unique<ifstream>(path));
}

Lexer::Lexer(std::unique_ptr<std::istream> stream)
{
    if (!*stream)
    {
        throw invalid_argument("stream is not valid");
    }
    this->stream = move(stream);
}
