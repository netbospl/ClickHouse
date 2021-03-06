#pragma once

#include <Interpreters/IInterpreter.h>
#include <Parsers/IAST_fwd.h>


namespace DB
{

class Context;


/** Just call method "optimize" for table.
  */
class InterpreterOptimizeQuery : public IInterpreter
{
public:
    InterpreterOptimizeQuery(const ASTPtr & query_ptr_, Context & context_)
        : query_ptr(query_ptr_), context(context_)
    {
    }

    BlockIO execute() override;

private:
    ASTPtr query_ptr;
    Context & context;
};


}
