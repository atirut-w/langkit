#include <langkit/lexer.hpp>
#include <stdexcept>
#include <fstream>

using namespace std;
using namespace LangKit;

Lexer::Lexer(const filesystem::path &path)
{
    auto stream = make_unique<ifstream>(path);
    if (!*stream)
    {
        throw invalid_argument("could not open \"" + filesystem::absolute(path).string() + "\" for reading");
    }
    this->stream = move(stream);
}

Lexer::Lexer(std::unique_ptr<std::istream> stream)
{
    if (!*stream)
    {
        throw invalid_argument("stream is not valid");
    }
    this->stream = move(stream);
}

char Lexer::peek() const
{
    if (eof())
        return '\0';

    if (stream->peek() == '\r' || stream->peek() == '\n')
    {
        return '\n';
    }
    return stream->peek();
}

char Lexer::get()
{
    if (eof())
        return '\0';

    char c = stream->get();
    if (c == '\n')
    {
        line++;
        column = 1;
    }
    else if (c == '\r')
    {
        if (stream->peek() == '\n')
        {
            stream->get();
        }
        c = '\n'; // Implicit simplification of CR/CRLF to LF
        line++;
        column = 1;
    }
    else
    {
        column++;
    }
    return c;
}
