#include "interpreter.hpp"
#include "value.hpp"

namespace laskin
{
    /**
     * clear
     *
     * Clears entire stack.
     */
    BUILT_IN_FUNCTION(func_clear)
    {
        stack.clear();
    }

    /**
     * depth( : integer)
     *
     * Returns current depth of the stack.
     */
    BUILT_IN_FUNCTION(func_depth)
    {
        stack.push_back(static_cast<integer>(stack.size()));
    }

    /**
     * drop(any)
     *
     * Discards top-most value from the stack.
     */
    BUILT_IN_FUNCTION(func_drop)
    {
        stack.pop_back();
    }

    /**
     * drop2(any any)
     *
     * Discards two top-most values from the stack.
     */
    BUILT_IN_FUNCTION(func_drop2)
    {
        stack.pop_back();
        stack.pop_back();
    }

    /**
     * dup(any : any any)
     *
     * Duplicates top-most value on the stack.
     */
    BUILT_IN_FUNCTION(func_dup)
    {
        stack.push_back(stack[stack.size() - 1]);
    }

    /**
     * dup2(any any : any any any any)
     *
     * Duplicates two top-most values on the stack.
     */
    BUILT_IN_FUNCTION(func_dup2)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop_back();
        stack.pop_back();
        stack.push_back(a);
        stack.push_back(b);
        stack.push_back(a);
        stack.push_back(b);
    }

    /**
     * over(any any : any any any)
     *
     * Copies second top-most value from the stack into top-most value of the
     * stack.
     */
    BUILT_IN_FUNCTION(func_over)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop_back();
        stack.pop_back();
        stack.push_back(b);
        stack.push_back(a);
        stack.push_back(b);
    }

    /**
     * rot(any any any : any any any)
     *
     * Rotates three top-most values on the stack.
     */
    BUILT_IN_FUNCTION(func_rot)
    {
        const value a = stack[stack.size() - 3];
        const value b = stack[stack.size() - 2];
        const value c = stack[stack.size() - 1];

        stack.pop_back();
        stack.pop_back();
        stack.pop_back();
        stack.push_back(c);
        stack.push_back(b);
        stack.push_back(a);
    }

    /**
     * swap(any any : any any)
     *
     * Swaps positions of two top-most values on the stack.
     */
    BUILT_IN_FUNCTION(func_swap)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop_back();
        stack.pop_back();
        stack.push_back(b);
        stack.push_back(a);
    }

    namespace internal
    {
        void initialize_stack(interpreter* i)
        {
            i->register_function("clear", "", func_clear);
            i->register_function("depth", ":i", func_depth);
            i->register_function("drop", "?", func_drop);
            i->register_function("drop2", "??", func_drop2);
            i->register_function("dup", "?:??", func_dup);
            i->register_function("dup2", "??:??", func_dup2);
            i->register_function("over", "??:???", func_over);
            i->register_function("rot", "???:???", func_rot);
            i->register_function("swap", "??:??", func_swap);
        }
    }
}
