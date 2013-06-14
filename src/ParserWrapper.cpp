#include "ParserWrapper.hpp"
#include "Ast.hpp"
#include "parser.hpp"
// The parser entry point, generated by Bison.
// extern "C" int yyparse(void *);
int yyparse(ParserWrapper *);

ParserWrapper::ParserWrapper():
  _lex(this)
{
}

ParserWrapper::~ParserWrapper()
{
}

int 
ParserWrapper::Parse(std::istream *stream, const char *filename)
{
//    _lex.switch_streams(stream, 0);
    _filename = filename;

    int status = yyparse(this);

    return status;
}
