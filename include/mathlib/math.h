#pragma once
#include <climits>

namespace mathlib
{

    enum class MathError
    {
        Ok = 0,
        DivisionByZero,
        Overflow,
        NegativeFactorial
    };

    inline MathError add(long long a, long long b, long long &res)
    {
        bool owerflow = __builtin_add_overflow(a, b, &res);
        if (owerflow)
        {
            return MathError::Overflow;
        }
        return MathError::Ok;
    }

    inline MathError substract(long long a, long long b, long long &res)
    {
        if (__builtin_sub_overflow(a, b, &res))
        {
            return MathError::Overflow;
        }
        return MathError::Ok;
    }

    inline MathError multiply(long long a, long long b, long long &res)
    {
        if (__builtin_mul_overflow(a, b, &res))
        {
            return MathError::Overflow;
        }
        return MathError::Ok;
    }

    inline MathError divide(long long a, long long b, long long &res)
    {
        if (b == 0)
        {
            return MathError::DivisionByZero;
        }

        if (a == LLONG_MIN && b == -1)
        {
            return MathError::Overflow;
        }

        res = a / b;
        return MathError::Ok;
    }

    inline MathError power(long long n, long long exp, long long &res)
    {
        if (exp < 0)
        {
            // отрицательная степень дает дробь - не поддерживаем
            return MathError::Overflow;
        }

        res = 1;
        for (long long i = 0; i < exp; ++i)
        {
            if (__builtin_mul_overflow(res, n, &res))
            {
                return MathError::Overflow;
            }
        }

        return MathError::Ok;
    }

    inline MathError factorial(long long n, long long &res)
    {
        if (n < 0)
        {
            return MathError::NegativeFactorial;
        }

        if (n == 0 || n == 1) {
            res = 1;
            return MathError::Ok;
        }
        
        long long prev = 0;

        MathError err = factorial(n - 1, prev);

        if (err != MathError::Ok) {
            return err;
        }

        if (__builtin_mul_overflow(n, prev, &res)) {
            return MathError::Overflow;
        }

        return MathError::Ok;
    } 

}
