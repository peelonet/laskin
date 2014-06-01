#include "interpreter.hpp"
#include "value.hpp"
#include <cmath>

namespace laskin
{
    /**
     * +(num num : num)
     *
     * Performs addition on given numbers.
     */
    BUILT_IN_FUNCTION(func_add)
    {
        const value b = stack[stack.size() - 1];
        const value a = stack[stack.size() - 2];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() + b.as_real());
        } else {
            stack.push(a.as_int() + b.as_int());
        }
    }

    /**
     * -(num num : num)
     *
     * Performs substraction on given numbers.
     */
    BUILT_IN_FUNCTION(func_sub)
    {
        const value b = stack[stack.size() - 1];
        const value a = stack[stack.size() - 2];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() - b.as_real());
        } else {
            stack.push(a.as_int() - b.as_int());
        }
    }

    /**
     * *(num num : num)
     *
     * Performs multiplication on given numbers.
     */
    BUILT_IN_FUNCTION(func_mul)
    {
        const value b = stack[stack.size() - 1];
        const value a = stack[stack.size() - 2];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() * b.as_real());
        } else {
            stack.push(a.as_int() * b.as_int());
        }
    }

    /**
     * /(num num : num)
     *
     * Performs division on the given numbers.
     */
    BUILT_IN_FUNCTION(func_div)
    {
        const value b = stack[stack.size() - 1];
        const value a = stack[stack.size() - 2];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() / b.as_real());
        } else {
            const integer x = a.as_int();
            const integer y = b.as_int();

            if (y == 0)
            {
                throw script_error("division by zero");
            }
            stack.push(x / y);
        }
    }

    /**
     * ==(any any : bool)
     *
     * Returns true if the two values are equal, false otherwise.
     */
    BUILT_IN_FUNCTION(func_eq)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        stack.push(a == b);
    }

    /**
     * !=(any any : bool)
     *
     * Returns true if the two values are not equal, false otherwise.
     */
    BUILT_IN_FUNCTION(func_ne)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        stack.push(a != b);
    }

    /**
     * <(num num : bool)
     *
     * Less-than comparison between two numbers.
     */
    BUILT_IN_FUNCTION(func_lt)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() < b.as_real());
        } else {
            stack.push(a.as_int() < b.as_int());
        }
    }

    /**
     * >(num num : bool)
     *
     * Greater-than comparison between two numbers.
     */
    BUILT_IN_FUNCTION(func_gt)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() > b.as_real());
        } else {
            stack.push(a.as_int() > b.as_int());
        }
    }

    /**
     * <(num num : bool)
     *
     * Less-than-equals comparison between two numbers.
     */
    BUILT_IN_FUNCTION(func_lte)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() <= b.as_real());
        } else {
            stack.push(a.as_int() <= b.as_int());
        }
    }

    /**
     * >=(num num : bool)
     *
     * Greater-than-equals comparison between two numbers.
     */
    BUILT_IN_FUNCTION(func_gte)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            stack.push(a.as_real() >= b.as_real());
        } else {
            stack.push(a.as_int() >= b.as_int());
        }
    }

    /**
     * max(num num : num)
     *
     * Returns maximum of the two given values.
     */
    BUILT_IN_FUNCTION(func_max)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            const real x = a.as_real();
            const real y = b.as_real();

            stack.push(x > y ? x : y);
        } else {
            const integer x = a.as_int();
            const integer y = b.as_int();

            stack.push(x > y ? x : y);
        }
    }

    /**
     * min(num num : num)
     *
     * Returns minimum of the two given values.
     */
    BUILT_IN_FUNCTION(func_min)
    {
        const value a = stack[stack.size() - 2];
        const value b = stack[stack.size() - 1];

        stack.pop();
        stack.pop();
        if (a.is(value::type_real) || b.is(value::type_real))
        {
            const real x = a.as_real();
            const real y = b.as_real();

            stack.push(x < y ? x : y);
        } else {
            const integer x = a.as_int();
            const integer y = b.as_int();

            stack.push(x < y ? x : y);
        }
    }

    /**
     * e( : real)
     *
     * Returns eulers number.
     */
    BUILT_IN_FUNCTION(func_e)
    {
        stack.push(M_E);
    }

    /**
     * inf( : real)
     *
     * Returns infinity.
     */
    BUILT_IN_FUNCTION(func_inf)
    {
        stack.push(INFINITY);
    }

    /**
     * pi( : real)
     *
     * Returns value of PI.
     */
    BUILT_IN_FUNCTION(func_pi)
    {
        stack.push(M_PI);
    }

    namespace internal
    {
        void initialize_numbers(interpreter* i)
        {
            i->register_function("+", "nn:n", func_add);
            i->register_function("-", "nn:n", func_sub);
            i->register_function("*", "nn:n", func_mul);
            i->register_function("/", "nn:n", func_div);

            // Comparison operators.
            i->register_function("==", "??:b", func_eq);
            i->register_function("!=", "??:b", func_ne);
            i->register_function("<", "nn:b", func_lt);
            i->register_function(">", "nn:b", func_gt);
            i->register_function("<=", "nn:b", func_lte);
            i->register_function(">=", "nn:b", func_gte);

            i->register_function("max", "nn:n", func_max);
            i->register_function("min", "nn:n", func_min);

            // Constants.
            i->register_function("e", "", func_e);
            i->register_function("inf", "", func_inf);
            i->register_function("pi", "", func_pi);
        }
    }
}
