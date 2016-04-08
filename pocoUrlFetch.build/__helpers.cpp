// This file contains helper functions that are automatically created from
// templates.

#include "nuitka/prelude.hpp"

extern PyObject *callPythonFunction( PyObject *func, PyObject **args, int count );


PyObject *CALL_FUNCTION_WITH_ARGS1( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 1; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 1 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 1; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 1 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 1 * sizeof(PyObject *) );
            memcpy( python_pars + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 1 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 1 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 1; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 1 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 1 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 1, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 1 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 1 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (1 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 1 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (1 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 1 );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            1
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 1 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS2( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 2; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 2 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 2; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 2 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 2 * sizeof(PyObject *) );
            memcpy( python_pars + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 2 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 2 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 2; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 2 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 2 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 2, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 2 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 2 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (2 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 2 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (2 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 2 );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            2
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 2 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}

PyObject *CALL_FUNCTION_WITH_ARGS3( PyObject *called, PyObject **args )
{
    CHECK_OBJECT( called );

    // Check if arguments are valid objects in debug mode.
#ifndef __NUITKA_NO_ASSERT__
    for( size_t i = 0; i < 3; i++ )
    {
        CHECK_OBJECT( args[ i ] );
    }
#endif

    if ( Nuitka_Function_Check( called ) )
    {
        if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
        {
            return NULL;
        }

        Nuitka_FunctionObject *function = (Nuitka_FunctionObject *)called;
        PyObject *result;

        if ( function->m_args_simple && 3 == function->m_args_positional_count )
        {
            for( Py_ssize_t i = 0; i < 3; i++ )
            {
                Py_INCREF( args[ i ] );
            }

            result = function->m_c_code( function, args );
        }
        else if ( function->m_args_simple && 3 + function->m_defaults_given == function->m_args_positional_count )
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
            PyObject *python_pars[ function->m_args_positional_count ];
#endif
            memcpy( python_pars, args, 3 * sizeof(PyObject *) );
            memcpy( python_pars + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

            for( Py_ssize_t i = 0; i < function->m_args_positional_count; i++ )
            {
                Py_INCREF( python_pars[ i ] );
            }

            result = function->m_c_code( function, python_pars );
        }
        else
        {
#ifdef _MSC_VER
            PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
            PyObject *python_pars[ function->m_args_overall_count ];
#endif
            memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

            if ( parseArgumentsPos( function, python_pars, args, 3 ))
            {
                result = function->m_c_code( function, python_pars );
            }
            else
            {
                result = NULL;
            }
        }

        Py_LeaveRecursiveCall();

        return result;
    }
    else if ( Nuitka_Method_Check( called ) )
    {
        Nuitka_MethodObject *method = (Nuitka_MethodObject *)called;

        // Unbound method without arguments, let the error path be slow.
        if ( method->m_object != NULL )
        {
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }

            Nuitka_FunctionObject *function = method->m_function;

            PyObject *result;

            if ( function->m_args_simple && 3 + 1 == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                for( Py_ssize_t i = 0; i < 3; i++ )
                {
                    python_pars[ i + 1 ] = args[ i ];
                    Py_INCREF( args[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else if ( function->m_args_simple && 3 + 1 + function->m_defaults_given == function->m_args_positional_count )
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_positional_count );
#else
                PyObject *python_pars[ function->m_args_positional_count ];
#endif
                python_pars[ 0 ] = method->m_object;
                Py_INCREF( method->m_object );

                memcpy( python_pars+1, args, 3 * sizeof(PyObject *) );
                memcpy( python_pars+1 + 3, &PyTuple_GET_ITEM( function->m_defaults, 0 ), function->m_defaults_given * sizeof(PyObject *) );

                for( Py_ssize_t i = 1; i < function->m_args_overall_count; i++ )
                {
                    Py_INCREF( python_pars[ i ] );
                }

                result = function->m_c_code( function, python_pars );
            }
            else
            {
#ifdef _MSC_VER
                PyObject **python_pars = (PyObject **)_alloca( sizeof( PyObject * ) * function->m_args_overall_count );
#else
                PyObject *python_pars[ function->m_args_overall_count ];
#endif
                memset( python_pars, 0, function->m_args_overall_count * sizeof(PyObject *) );

                if ( parseArgumentsMethodPos( function, python_pars, method->m_object, args, 3 ) )
                {
                    result = function->m_c_code( function, python_pars );
                }
                else
                {
                    result = NULL;
                }
            }

            Py_LeaveRecursiveCall();

            return result;
        }
    }
    else if ( PyCFunction_Check( called ) )
    {
        // Try to be fast about wrapping the arguments.
        int flags = PyCFunction_GET_FLAGS( called );

        if ( flags & METH_NOARGS )
        {
#if 3 == 0
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, NULL );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(
                PyExc_TypeError,
                "%s() takes no arguments (3 given)",
                ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else if ( flags & METH_O )
        {
#if 3 == 1
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            PyObject *result = (*method)( self, args[0] );

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                return NULL;
            }
#else
            PyErr_Format(PyExc_TypeError,
                "%s() takes exactly one argument (3 given)",
                 ((PyCFunctionObject *)called)->m_ml->ml_name
            );
            return NULL;
#endif
        }
        else
        {
            PyCFunction method = PyCFunction_GET_FUNCTION( called );
            PyObject *self = PyCFunction_GET_SELF( called );

            PyObject *pos_args = MAKE_TUPLE( args, 3 );

            PyObject *result;

            assert( flags && METH_VARARGS );

            // Recursion guard is not strictly necessary, as we already have
            // one on our way to here.
#ifdef _NUITKA_FULL_COMPAT
            if (unlikely( Py_EnterRecursiveCall( (char *)" while calling a Python object" ) ))
            {
                return NULL;
            }
#endif

            if ( flags && METH_KEYWORDS )
            {
                result = (*(PyCFunctionWithKeywords)method)( self, pos_args, NULL );
            }
            else
            {
                result = (*method)( self, pos_args );
            }

#ifdef _NUITKA_FULL_COMPAT
            Py_LeaveRecursiveCall();
#endif

            if ( result != NULL )
            {
            // Some buggy C functions do set an error, but do not indicate it
            // and Nuitka inner workings can get upset/confused from it.
                DROP_ERROR_OCCURRED();

                Py_DECREF( pos_args );
                return result;
            }
            else
            {
                // Other buggy C functions do this, return NULL, but with
                // no error set, not allowed.
                if (unlikely( !ERROR_OCCURRED() ))
                {
                    PyErr_Format(
                        PyExc_SystemError,
                        "NULL result without error in PyObject_Call"
                    );
                }

                Py_DECREF( pos_args );
                return NULL;
            }
        }
    }
    else if ( PyFunction_Check( called ) )
    {
        return callPythonFunction(
            called,
            args,
            3
        );
    }

    PyObject *pos_args = MAKE_TUPLE( args, 3 );

    PyObject *result = CALL_FUNCTION(
        called,
        pos_args,
        NULL
    );

    Py_DECREF( pos_args );

    return result;
}
/* Code to register embedded modules for meta path based loading if any. */
#if 1 == 1

#include "nuitka/unfreezing.hpp"

/* Table for lookup to find compiled or bytecode modules included in this
 * binary or module, or put along this binary as extension modules. We do
 * our own loading for each of these.
 */

static struct Nuitka_MetaPathBasedLoaderEntry meta_path_loader_entries[] =
{
    { (char *)"BaseHTTPServer", NULL, &constant_bin[ 1048 ], 21589, NUITKA_BYTECODE_FLAG },
    { (char *)"Bastion", NULL, &constant_bin[ 22637 ], 6577, NUITKA_BYTECODE_FLAG },
    { (char *)"CGIHTTPServer", NULL, &constant_bin[ 29214 ], 11037, NUITKA_BYTECODE_FLAG },
    { (char *)"Canvas", NULL, &constant_bin[ 40251 ], 15156, NUITKA_BYTECODE_FLAG },
    { (char *)"ConfigParser", NULL, &constant_bin[ 55407 ], 24910, NUITKA_BYTECODE_FLAG },
    { (char *)"Cookie", NULL, &constant_bin[ 80317 ], 22416, NUITKA_BYTECODE_FLAG },
    { (char *)"Dialog", NULL, &constant_bin[ 102733 ], 1887, NUITKA_BYTECODE_FLAG },
    { (char *)"DocXMLRPCServer", NULL, &constant_bin[ 104620 ], 9736, NUITKA_BYTECODE_FLAG },
    { (char *)"FileDialog", NULL, &constant_bin[ 114356 ], 9606, NUITKA_BYTECODE_FLAG },
    { (char *)"FixTk", NULL, &constant_bin[ 123962 ], 1975, NUITKA_BYTECODE_FLAG },
    { (char *)"HTMLParser", NULL, &constant_bin[ 125937 ], 13566, NUITKA_BYTECODE_FLAG },
    { (char *)"MimeWriter", NULL, &constant_bin[ 139503 ], 7311, NUITKA_BYTECODE_FLAG },
    { (char *)"Queue", NULL, &constant_bin[ 146814 ], 9276, NUITKA_BYTECODE_FLAG },
    { (char *)"ScrolledText", NULL, &constant_bin[ 156090 ], 2631, NUITKA_BYTECODE_FLAG },
    { (char *)"SimpleDialog", NULL, &constant_bin[ 158721 ], 4276, NUITKA_BYTECODE_FLAG },
    { (char *)"SimpleHTTPServer", NULL, &constant_bin[ 162997 ], 7803, NUITKA_BYTECODE_FLAG },
    { (char *)"SimpleXMLRPCServer", NULL, &constant_bin[ 170800 ], 22674, NUITKA_BYTECODE_FLAG },
    { (char *)"SocketServer", NULL, &constant_bin[ 193474 ], 23765, NUITKA_BYTECODE_FLAG },
    { (char *)"StringIO", NULL, &constant_bin[ 217239 ], 11377, NUITKA_BYTECODE_FLAG },
    { (char *)"Tix", NULL, &constant_bin[ 228616 ], 94389, NUITKA_BYTECODE_FLAG },
    { (char *)"Tkconstants", NULL, &constant_bin[ 323005 ], 2233, NUITKA_BYTECODE_FLAG },
    { (char *)"Tkdnd", NULL, &constant_bin[ 325238 ], 12687, NUITKA_BYTECODE_FLAG },
    { (char *)"Tkinter", NULL, &constant_bin[ 337925 ], 196832, NUITKA_BYTECODE_FLAG },
    { (char *)"UserDict", NULL, &constant_bin[ 534757 ], 8587, NUITKA_BYTECODE_FLAG },
    { (char *)"UserList", NULL, &constant_bin[ 543344 ], 6399, NUITKA_BYTECODE_FLAG },
    { (char *)"UserString", NULL, &constant_bin[ 549743 ], 14516, NUITKA_BYTECODE_FLAG },
    { (char *)"_LWPCookieJar", NULL, &constant_bin[ 564259 ], 5496, NUITKA_BYTECODE_FLAG },
    { (char *)"_MozillaCookieJar", NULL, &constant_bin[ 569755 ], 4432, NUITKA_BYTECODE_FLAG },
    { (char *)"__future__", NULL, &constant_bin[ 574187 ], 4254, NUITKA_BYTECODE_FLAG },
    { (char *)"_abcoll", NULL, &constant_bin[ 578441 ], 25024, NUITKA_BYTECODE_FLAG },
    { (char *)"_osx_support", NULL, &constant_bin[ 603465 ], 11699, NUITKA_BYTECODE_FLAG },
    { (char *)"_pyio", NULL, &constant_bin[ 615164 ], 63526, NUITKA_BYTECODE_FLAG },
    { (char *)"_strptime", NULL, &constant_bin[ 678690 ], 14767, NUITKA_BYTECODE_FLAG },
    { (char *)"_threading_local", NULL, &constant_bin[ 693457 ], 6551, NUITKA_BYTECODE_FLAG },
    { (char *)"_weakrefset", NULL, &constant_bin[ 700008 ], 9430, NUITKA_BYTECODE_FLAG },
    { (char *)"abc", NULL, &constant_bin[ 709438 ], 6080, NUITKA_BYTECODE_FLAG },
    { (char *)"aifc", NULL, &constant_bin[ 715518 ], 30080, NUITKA_BYTECODE_FLAG },
    { (char *)"anydbm", NULL, &constant_bin[ 745598 ], 2777, NUITKA_BYTECODE_FLAG },
    { (char *)"ast", NULL, &constant_bin[ 748375 ], 12826, NUITKA_BYTECODE_FLAG },
    { (char *)"asynchat", NULL, &constant_bin[ 761201 ], 8661, NUITKA_BYTECODE_FLAG },
    { (char *)"asyncore", NULL, &constant_bin[ 769862 ], 18537, NUITKA_BYTECODE_FLAG },
    { (char *)"atexit", NULL, &constant_bin[ 788399 ], 2165, NUITKA_BYTECODE_FLAG },
    { (char *)"audiodev", NULL, &constant_bin[ 790564 ], 8325, NUITKA_BYTECODE_FLAG },
    { (char *)"base64", NULL, &constant_bin[ 798889 ], 10790, NUITKA_BYTECODE_FLAG },
    { (char *)"bdb", NULL, &constant_bin[ 809679 ], 18788, NUITKA_BYTECODE_FLAG },
    { (char *)"binhex", NULL, &constant_bin[ 828467 ], 15137, NUITKA_BYTECODE_FLAG },
    { (char *)"bisect", NULL, &constant_bin[ 843604 ], 3038, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb", NULL, &constant_bin[ 846642 ], 12255, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"bsddb.db", NULL, &constant_bin[ 858897 ], 579, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.dbobj", NULL, &constant_bin[ 859476 ], 18280, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.dbrecio", NULL, &constant_bin[ 877756 ], 5233, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.dbshelve", NULL, &constant_bin[ 882989 ], 12754, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.dbtables", NULL, &constant_bin[ 895743 ], 24219, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.dbutils", NULL, &constant_bin[ 919962 ], 1609, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test", NULL, &constant_bin[ 921571 ], 117, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"bsddb.test.test_all", NULL, &constant_bin[ 921688 ], 24074, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_associate", NULL, &constant_bin[ 945762 ], 19508, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_basics", NULL, &constant_bin[ 965270 ], 33751, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_compare", NULL, &constant_bin[ 999021 ], 19363, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_compat", NULL, &constant_bin[ 1018384 ], 5351, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_cursor_pget_bug", NULL, &constant_bin[ 1023735 ], 2653, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_db", NULL, &constant_bin[ 1026388 ], 8628, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_dbenv", NULL, &constant_bin[ 1035016 ], 21996, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_dbobj", NULL, &constant_bin[ 1057012 ], 3368, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_dbshelve", NULL, &constant_bin[ 1060380 ], 14067, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_dbtables", NULL, &constant_bin[ 1074447 ], 11641, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_distributed_transactions", NULL, &constant_bin[ 1086088 ], 5596, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_early_close", NULL, &constant_bin[ 1091684 ], 6749, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_fileid", NULL, &constant_bin[ 1098433 ], 2385, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_get_none", NULL, &constant_bin[ 1100818 ], 2841, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_join", NULL, &constant_bin[ 1103659 ], 3649, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_lock", NULL, &constant_bin[ 1107308 ], 5916, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_misc", NULL, &constant_bin[ 1113224 ], 5085, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_pickle", NULL, &constant_bin[ 1118309 ], 2770, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_queue", NULL, &constant_bin[ 1121079 ], 3952, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_recno", NULL, &constant_bin[ 1125031 ], 7729, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_replication", NULL, &constant_bin[ 1132760 ], 15787, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_sequence", NULL, &constant_bin[ 1148547 ], 6675, NUITKA_BYTECODE_FLAG },
    { (char *)"bsddb.test.test_thread", NULL, &constant_bin[ 1155222 ], 15201, NUITKA_BYTECODE_FLAG },
    { (char *)"cProfile", NULL, &constant_bin[ 1170423 ], 6230, NUITKA_BYTECODE_FLAG },
    { (char *)"calendar", NULL, &constant_bin[ 1176653 ], 27386, NUITKA_BYTECODE_FLAG },
    { (char *)"cgi", NULL, &constant_bin[ 1204039 ], 32206, NUITKA_BYTECODE_FLAG },
    { (char *)"cgitb", NULL, &constant_bin[ 1236245 ], 12086, NUITKA_BYTECODE_FLAG },
    { (char *)"chunk", NULL, &constant_bin[ 1248331 ], 5528, NUITKA_BYTECODE_FLAG },
    { (char *)"cmd", NULL, &constant_bin[ 1253859 ], 13926, NUITKA_BYTECODE_FLAG },
    { (char *)"code", NULL, &constant_bin[ 1267785 ], 10245, NUITKA_BYTECODE_FLAG },
    { (char *)"codeop", NULL, &constant_bin[ 1278030 ], 6539, NUITKA_BYTECODE_FLAG },
    { (char *)"collections", NULL, &constant_bin[ 1284569 ], 25353, NUITKA_BYTECODE_FLAG },
    { (char *)"colorsys", NULL, &constant_bin[ 1309922 ], 3943, NUITKA_BYTECODE_FLAG },
    { (char *)"commands", NULL, &constant_bin[ 1313865 ], 2431, NUITKA_BYTECODE_FLAG },
    { (char *)"compileall", NULL, &constant_bin[ 1316296 ], 6978, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler", NULL, &constant_bin[ 1323274 ], 1284, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"compiler.ast", NULL, &constant_bin[ 1324558 ], 70172, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.consts", NULL, &constant_bin[ 1394730 ], 724, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.future", NULL, &constant_bin[ 1395454 ], 2988, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.misc", NULL, &constant_bin[ 1398442 ], 3630, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.pyassem", NULL, &constant_bin[ 1402072 ], 25589, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.pycodegen", NULL, &constant_bin[ 1427661 ], 55642, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.symbols", NULL, &constant_bin[ 1483303 ], 17389, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.syntax", NULL, &constant_bin[ 1500692 ], 1844, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.transformer", NULL, &constant_bin[ 1502536 ], 46996, NUITKA_BYTECODE_FLAG },
    { (char *)"compiler.visitor", NULL, &constant_bin[ 1549532 ], 4129, NUITKA_BYTECODE_FLAG },
    { (char *)"contextlib", NULL, &constant_bin[ 1553661 ], 4386, NUITKA_BYTECODE_FLAG },
    { (char *)"cookielib", NULL, &constant_bin[ 1558047 ], 54245, NUITKA_BYTECODE_FLAG },
    { (char *)"copy", NULL, &constant_bin[ 1612292 ], 12056, NUITKA_BYTECODE_FLAG },
    { (char *)"csv", NULL, &constant_bin[ 1624348 ], 13367, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes", NULL, &constant_bin[ 1637715 ], 20015, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"ctypes._endian", NULL, &constant_bin[ 1657730 ], 2269, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes.macholib", NULL, &constant_bin[ 1659999 ], 303, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"ctypes.macholib.dyld", NULL, &constant_bin[ 1660302 ], 5699, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes.macholib.dylib", NULL, &constant_bin[ 1666001 ], 2287, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes.macholib.framework", NULL, &constant_bin[ 1668288 ], 2597, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes.util", NULL, &constant_bin[ 1670885 ], 7906, NUITKA_BYTECODE_FLAG },
    { (char *)"ctypes.wintypes", NULL, &constant_bin[ 1678791 ], 5882, NUITKA_BYTECODE_FLAG },
    { (char *)"curses", NULL, &constant_bin[ 1684673 ], 1530, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"dbhash", NULL, &constant_bin[ 1686203 ], 700, NUITKA_BYTECODE_FLAG },
    { (char *)"decimal", NULL, &constant_bin[ 1686903 ], 170085, NUITKA_BYTECODE_FLAG },
    { (char *)"difflib", NULL, &constant_bin[ 1856988 ], 61671, NUITKA_BYTECODE_FLAG },
    { (char *)"dircache", NULL, &constant_bin[ 1918659 ], 1548, NUITKA_BYTECODE_FLAG },
    { (char *)"dis", NULL, &constant_bin[ 1920207 ], 6180, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils", NULL, &constant_bin[ 1926387 ], 372, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"distutils.archive_util", NULL, &constant_bin[ 1926759 ], 7408, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.bcppcompiler", NULL, &constant_bin[ 1934167 ], 7829, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.ccompiler", NULL, &constant_bin[ 1941996 ], 36547, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.cmd", NULL, &constant_bin[ 1978543 ], 16611, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command", NULL, &constant_bin[ 1995154 ], 652, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"distutils.command.bdist", NULL, &constant_bin[ 1995806 ], 5181, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.bdist_dumb", NULL, &constant_bin[ 2000987 ], 5010, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.bdist_msi", NULL, &constant_bin[ 2005997 ], 23920, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.bdist_rpm", NULL, &constant_bin[ 2029917 ], 17696, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.bdist_wininst", NULL, &constant_bin[ 2047613 ], 10735, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.build", NULL, &constant_bin[ 2058348 ], 5089, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.build_clib", NULL, &constant_bin[ 2063437 ], 6375, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.build_ext", NULL, &constant_bin[ 2069812 ], 19262, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.build_py", NULL, &constant_bin[ 2089074 ], 11420, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.build_scripts", NULL, &constant_bin[ 2100494 ], 4491, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.check", NULL, &constant_bin[ 2104985 ], 6160, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.clean", NULL, &constant_bin[ 2111145 ], 3143, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.config", NULL, &constant_bin[ 2114288 ], 12581, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install", NULL, &constant_bin[ 2126869 ], 16747, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install_data", NULL, &constant_bin[ 2143616 ], 3121, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install_egg_info", NULL, &constant_bin[ 2146737 ], 3713, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install_headers", NULL, &constant_bin[ 2150450 ], 2253, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install_lib", NULL, &constant_bin[ 2152703 ], 6716, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.install_scripts", NULL, &constant_bin[ 2159419 ], 2955, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.register", NULL, &constant_bin[ 2162374 ], 10149, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.sdist", NULL, &constant_bin[ 2172523 ], 16602, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.command.upload", NULL, &constant_bin[ 2189125 ], 6290, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.config", NULL, &constant_bin[ 2195415 ], 3527, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.core", NULL, &constant_bin[ 2198942 ], 7622, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.cygwinccompiler", NULL, &constant_bin[ 2206564 ], 9757, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.debug", NULL, &constant_bin[ 2216321 ], 241, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.dep_util", NULL, &constant_bin[ 2216562 ], 3152, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.dir_util", NULL, &constant_bin[ 2219714 ], 6745, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.dist", NULL, &constant_bin[ 2226459 ], 39228, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.emxccompiler", NULL, &constant_bin[ 2265687 ], 7414, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.errors", NULL, &constant_bin[ 2273101 ], 6177, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.extension", NULL, &constant_bin[ 2279278 ], 7383, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.fancy_getopt", NULL, &constant_bin[ 2286661 ], 11845, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.file_util", NULL, &constant_bin[ 2298506 ], 6716, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.filelist", NULL, &constant_bin[ 2305222 ], 10663, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.log", NULL, &constant_bin[ 2315885 ], 2718, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.msvc9compiler", NULL, &constant_bin[ 2318603 ], 21365, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.msvccompiler", NULL, &constant_bin[ 2339968 ], 17385, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.spawn", NULL, &constant_bin[ 2357353 ], 6355, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.sysconfig", NULL, &constant_bin[ 2363708 ], 13118, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.tests", NULL, &constant_bin[ 2376826 ], 1450, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"distutils.text_file", NULL, &constant_bin[ 2378276 ], 9181, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.unixccompiler", NULL, &constant_bin[ 2387457 ], 7535, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.util", NULL, &constant_bin[ 2394992 ], 14279, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.version", NULL, &constant_bin[ 2409271 ], 7125, NUITKA_BYTECODE_FLAG },
    { (char *)"distutils.versionpredicate", NULL, &constant_bin[ 2416396 ], 5499, NUITKA_BYTECODE_FLAG },
    { (char *)"doctest", NULL, &constant_bin[ 2421895 ], 83077, NUITKA_BYTECODE_FLAG },
    { (char *)"dumbdbm", NULL, &constant_bin[ 2504972 ], 6424, NUITKA_BYTECODE_FLAG },
    { (char *)"dummy_thread", NULL, &constant_bin[ 2511396 ], 5311, NUITKA_BYTECODE_FLAG },
    { (char *)"dummy_threading", NULL, &constant_bin[ 2516707 ], 1272, NUITKA_BYTECODE_FLAG },
    { (char *)"email", NULL, &constant_bin[ 2517979 ], 2834, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"email._parseaddr", NULL, &constant_bin[ 2520813 ], 13682, NUITKA_BYTECODE_FLAG },
    { (char *)"email.base64mime", NULL, &constant_bin[ 2534495 ], 5290, NUITKA_BYTECODE_FLAG },
    { (char *)"email.charset", NULL, &constant_bin[ 2539785 ], 13448, NUITKA_BYTECODE_FLAG },
    { (char *)"email.encoders", NULL, &constant_bin[ 2553233 ], 2189, NUITKA_BYTECODE_FLAG },
    { (char *)"email.errors", NULL, &constant_bin[ 2555422 ], 3446, NUITKA_BYTECODE_FLAG },
    { (char *)"email.feedparser", NULL, &constant_bin[ 2558868 ], 11444, NUITKA_BYTECODE_FLAG },
    { (char *)"email.generator", NULL, &constant_bin[ 2570312 ], 10277, NUITKA_BYTECODE_FLAG },
    { (char *)"email.header", NULL, &constant_bin[ 2580589 ], 13574, NUITKA_BYTECODE_FLAG },
    { (char *)"email.iterators", NULL, &constant_bin[ 2594163 ], 2333, NUITKA_BYTECODE_FLAG },
    { (char *)"email.message", NULL, &constant_bin[ 2596496 ], 28435, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime", NULL, &constant_bin[ 2624931 ], 117, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"email.mime.application", NULL, &constant_bin[ 2625048 ], 1561, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.audio", NULL, &constant_bin[ 2626609 ], 2881, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.base", NULL, &constant_bin[ 2629490 ], 1093, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.image", NULL, &constant_bin[ 2630583 ], 2026, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.message", NULL, &constant_bin[ 2632609 ], 1425, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.multipart", NULL, &constant_bin[ 2634034 ], 1646, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.nonmultipart", NULL, &constant_bin[ 2635680 ], 865, NUITKA_BYTECODE_FLAG },
    { (char *)"email.mime.text", NULL, &constant_bin[ 2636545 ], 1285, NUITKA_BYTECODE_FLAG },
    { (char *)"email.parser", NULL, &constant_bin[ 2637830 ], 3781, NUITKA_BYTECODE_FLAG },
    { (char *)"email.quoprimime", NULL, &constant_bin[ 2641611 ], 8777, NUITKA_BYTECODE_FLAG },
    { (char *)"email.test", NULL, &constant_bin[ 2650388 ], 117, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"email.test.test_email", NULL, &constant_bin[ 2650505 ], 143319, NUITKA_BYTECODE_FLAG },
    { (char *)"email.test.test_email_codecs", NULL, &constant_bin[ 2793824 ], 2844, NUITKA_BYTECODE_FLAG },
    { (char *)"email.test.test_email_codecs_renamed", NULL, &constant_bin[ 2796668 ], 2892, NUITKA_BYTECODE_FLAG },
    { (char *)"email.test.test_email_renamed", NULL, &constant_bin[ 2799560 ], 133721, NUITKA_BYTECODE_FLAG },
    { (char *)"email.test.test_email_torture", NULL, &constant_bin[ 2933281 ], 4464, NUITKA_BYTECODE_FLAG },
    { (char *)"email.utils", NULL, &constant_bin[ 2937745 ], 9075, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.base64_codec", NULL, &constant_bin[ 2946820 ], 3755, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.big5", NULL, &constant_bin[ 2950575 ], 1727, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.big5hkscs", NULL, &constant_bin[ 2952302 ], 1767, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.bz2_codec", NULL, &constant_bin[ 2954069 ], 4635, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.charmap", NULL, &constant_bin[ 2958704 ], 3420, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp037", NULL, &constant_bin[ 2962124 ], 2796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1006", NULL, &constant_bin[ 2964920 ], 2882, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1026", NULL, &constant_bin[ 2967802 ], 2810, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1140", NULL, &constant_bin[ 2970612 ], 2796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1250", NULL, &constant_bin[ 2973408 ], 2833, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1251", NULL, &constant_bin[ 2976241 ], 2830, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1252", NULL, &constant_bin[ 2979071 ], 2833, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1253", NULL, &constant_bin[ 2981904 ], 2846, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1254", NULL, &constant_bin[ 2984750 ], 2835, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1255", NULL, &constant_bin[ 2987585 ], 2854, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1256", NULL, &constant_bin[ 2990439 ], 2832, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1257", NULL, &constant_bin[ 2993271 ], 2840, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp1258", NULL, &constant_bin[ 2996111 ], 2838, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp424", NULL, &constant_bin[ 2998949 ], 2826, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp500", NULL, &constant_bin[ 3001775 ], 2796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp720", NULL, &constant_bin[ 3004571 ], 2893, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp737", NULL, &constant_bin[ 3007464 ], 8259, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp775", NULL, &constant_bin[ 3015723 ], 8045, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp850", NULL, &constant_bin[ 3023768 ], 7778, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp852", NULL, &constant_bin[ 3031546 ], 8047, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp855", NULL, &constant_bin[ 3039593 ], 8228, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp856", NULL, &constant_bin[ 3047821 ], 2858, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp857", NULL, &constant_bin[ 3050679 ], 7768, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp858", NULL, &constant_bin[ 3058447 ], 7748, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp860", NULL, &constant_bin[ 3066195 ], 8014, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp861", NULL, &constant_bin[ 3074209 ], 8025, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp862", NULL, &constant_bin[ 3082234 ], 8160, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp863", NULL, &constant_bin[ 3090394 ], 8025, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp864", NULL, &constant_bin[ 3098419 ], 8156, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp865", NULL, &constant_bin[ 3106575 ], 8025, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp866", NULL, &constant_bin[ 3114600 ], 8260, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp869", NULL, &constant_bin[ 3122860 ], 8072, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp874", NULL, &constant_bin[ 3130932 ], 2924, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp875", NULL, &constant_bin[ 3133856 ], 2793, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp932", NULL, &constant_bin[ 3136649 ], 1735, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp949", NULL, &constant_bin[ 3138384 ], 1735, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.cp950", NULL, &constant_bin[ 3140119 ], 1735, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.euc_jis_2004", NULL, &constant_bin[ 3141854 ], 1791, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.euc_jisx0213", NULL, &constant_bin[ 3143645 ], 1791, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.euc_jp", NULL, &constant_bin[ 3145436 ], 1743, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.euc_kr", NULL, &constant_bin[ 3147179 ], 1743, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.gb18030", NULL, &constant_bin[ 3148922 ], 1751, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.gb2312", NULL, &constant_bin[ 3150673 ], 1743, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.gbk", NULL, &constant_bin[ 3152416 ], 1719, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.hp_roman8", NULL, &constant_bin[ 3154135 ], 4079, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.hz", NULL, &constant_bin[ 3158214 ], 1711, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp", NULL, &constant_bin[ 3159925 ], 1780, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp_1", NULL, &constant_bin[ 3161705 ], 1796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp_2", NULL, &constant_bin[ 3163501 ], 1796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp_2004", NULL, &constant_bin[ 3165297 ], 1820, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp_3", NULL, &constant_bin[ 3167117 ], 1796, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_jp_ext", NULL, &constant_bin[ 3168913 ], 1812, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso2022_kr", NULL, &constant_bin[ 3170725 ], 1780, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_1", NULL, &constant_bin[ 3172505 ], 2835, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_10", NULL, &constant_bin[ 3175340 ], 2850, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_11", NULL, &constant_bin[ 3178190 ], 2944, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_13", NULL, &constant_bin[ 3181134 ], 2853, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_14", NULL, &constant_bin[ 3183987 ], 2871, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_15", NULL, &constant_bin[ 3186858 ], 2850, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_16", NULL, &constant_bin[ 3189708 ], 2852, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_2", NULL, &constant_bin[ 3192560 ], 2835, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_3", NULL, &constant_bin[ 3195395 ], 2842, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_4", NULL, &constant_bin[ 3198237 ], 2835, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_5", NULL, &constant_bin[ 3201072 ], 2836, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_6", NULL, &constant_bin[ 3203908 ], 2880, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_7", NULL, &constant_bin[ 3206788 ], 2843, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_8", NULL, &constant_bin[ 3209631 ], 2874, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.iso8859_9", NULL, &constant_bin[ 3212505 ], 2835, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.johab", NULL, &constant_bin[ 3215340 ], 1735, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.koi8_r", NULL, &constant_bin[ 3217075 ], 2857, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.koi8_u", NULL, &constant_bin[ 3219932 ], 2843, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.latin_1", NULL, &constant_bin[ 3222775 ], 2253, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_arabic", NULL, &constant_bin[ 3225028 ], 7981, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_centeuro", NULL, &constant_bin[ 3233009 ], 2904, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_croatian", NULL, &constant_bin[ 3235913 ], 2912, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_cyrillic", NULL, &constant_bin[ 3238825 ], 2902, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_farsi", NULL, &constant_bin[ 3241727 ], 2816, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_greek", NULL, &constant_bin[ 3244543 ], 2856, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_iceland", NULL, &constant_bin[ 3247399 ], 2895, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_latin2", NULL, &constant_bin[ 3250294 ], 4874, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_roman", NULL, &constant_bin[ 3255168 ], 2873, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_romanian", NULL, &constant_bin[ 3258041 ], 2913, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.mac_turkish", NULL, &constant_bin[ 3260954 ], 2896, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.palmos", NULL, &constant_bin[ 3263850 ], 3033, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.ptcp154", NULL, &constant_bin[ 3266883 ], 4857, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.punycode", NULL, &constant_bin[ 3271740 ], 7907, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.quopri_codec", NULL, &constant_bin[ 3279647 ], 3552, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.raw_unicode_escape", NULL, &constant_bin[ 3283199 ], 2175, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.rot_13", NULL, &constant_bin[ 3285374 ], 3585, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.shift_jis", NULL, &constant_bin[ 3288959 ], 1767, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.shift_jis_2004", NULL, &constant_bin[ 3290726 ], 1807, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.shift_jisx0213", NULL, &constant_bin[ 3292533 ], 1807, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.string_escape", NULL, &constant_bin[ 3294340 ], 2034, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.tis_620", NULL, &constant_bin[ 3296374 ], 2905, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.undefined", NULL, &constant_bin[ 3299279 ], 2556, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.unicode_escape", NULL, &constant_bin[ 3301835 ], 2123, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.unicode_internal", NULL, &constant_bin[ 3303958 ], 2149, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_16", NULL, &constant_bin[ 3306107 ], 5100, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_16_be", NULL, &constant_bin[ 3311207 ], 1966, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_16_le", NULL, &constant_bin[ 3313173 ], 1966, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_32", NULL, &constant_bin[ 3315139 ], 5658, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_32_be", NULL, &constant_bin[ 3320797 ], 1859, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_32_le", NULL, &constant_bin[ 3322656 ], 1859, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_7", NULL, &constant_bin[ 3324515 ], 1859, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.utf_8_sig", NULL, &constant_bin[ 3326374 ], 4917, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.uu_codec", NULL, &constant_bin[ 3331291 ], 4833, NUITKA_BYTECODE_FLAG },
    { (char *)"encodings.zlib_codec", NULL, &constant_bin[ 3336124 ], 4555, NUITKA_BYTECODE_FLAG },
    { (char *)"filecmp", NULL, &constant_bin[ 3340679 ], 9514, NUITKA_BYTECODE_FLAG },
    { (char *)"fileinput", NULL, &constant_bin[ 3350193 ], 14697, NUITKA_BYTECODE_FLAG },
    { (char *)"fnmatch", NULL, &constant_bin[ 3364890 ], 3496, NUITKA_BYTECODE_FLAG },
    { (char *)"formatter", NULL, &constant_bin[ 3368386 ], 18785, NUITKA_BYTECODE_FLAG },
    { (char *)"fpformat", NULL, &constant_bin[ 3387171 ], 4623, NUITKA_BYTECODE_FLAG },
    { (char *)"fractions", NULL, &constant_bin[ 3391794 ], 19530, NUITKA_BYTECODE_FLAG },
    { (char *)"ftplib", NULL, &constant_bin[ 3411324 ], 33829, NUITKA_BYTECODE_FLAG },
    { (char *)"genericpath", NULL, &constant_bin[ 3445153 ], 3205, NUITKA_BYTECODE_FLAG },
    { (char *)"getopt", NULL, &constant_bin[ 3448358 ], 6596, NUITKA_BYTECODE_FLAG },
    { (char *)"getpass", NULL, &constant_bin[ 3454954 ], 4700, NUITKA_BYTECODE_FLAG },
    { (char *)"gettext", NULL, &constant_bin[ 3459654 ], 15312, NUITKA_BYTECODE_FLAG },
    { (char *)"glob", NULL, &constant_bin[ 3474966 ], 2895, NUITKA_BYTECODE_FLAG },
    { (char *)"gzip", NULL, &constant_bin[ 3477861 ], 15050, NUITKA_BYTECODE_FLAG },
    { (char *)"hashlib", NULL, &constant_bin[ 3492911 ], 7014, NUITKA_BYTECODE_FLAG },
    { (char *)"heapq", NULL, &constant_bin[ 3499925 ], 14466, NUITKA_BYTECODE_FLAG },
    { (char *)"hmac", NULL, &constant_bin[ 3514391 ], 4484, NUITKA_BYTECODE_FLAG },
    { (char *)"hotshot", NULL, &constant_bin[ 3518875 ], 3421, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"hotshot.log", NULL, &constant_bin[ 3522296 ], 5464, NUITKA_BYTECODE_FLAG },
    { (char *)"hotshot.stats", NULL, &constant_bin[ 3527760 ], 3205, NUITKA_BYTECODE_FLAG },
    { (char *)"hotshot.stones", NULL, &constant_bin[ 3530965 ], 1138, NUITKA_BYTECODE_FLAG },
    { (char *)"htmlentitydefs", NULL, &constant_bin[ 3532103 ], 6354, NUITKA_BYTECODE_FLAG },
    { (char *)"htmllib", NULL, &constant_bin[ 3538457 ], 19846, NUITKA_BYTECODE_FLAG },
    { (char *)"httplib", NULL, &constant_bin[ 3558303 ], 35815, NUITKA_BYTECODE_FLAG },
    { (char *)"ihooks", NULL, &constant_bin[ 3594118 ], 21019, NUITKA_BYTECODE_FLAG },
    { (char *)"imaplib", NULL, &constant_bin[ 3615137 ], 44853, NUITKA_BYTECODE_FLAG },
    { (char *)"imghdr", NULL, &constant_bin[ 3659990 ], 4750, NUITKA_BYTECODE_FLAG },
    { (char *)"importlib", NULL, &constant_bin[ 3664740 ], 1479, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"imputil", NULL, &constant_bin[ 3666219 ], 15425, NUITKA_BYTECODE_FLAG },
    { (char *)"inspect", NULL, &constant_bin[ 3681644 ], 39679, NUITKA_BYTECODE_FLAG },
    { (char *)"io", NULL, &constant_bin[ 3721323 ], 3555, NUITKA_BYTECODE_FLAG },
    { (char *)"json", NULL, &constant_bin[ 3724878 ], 13922, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"json.decoder", NULL, &constant_bin[ 3738800 ], 12026, NUITKA_BYTECODE_FLAG },
    { (char *)"json.encoder", NULL, &constant_bin[ 3750826 ], 13617, NUITKA_BYTECODE_FLAG },
    { (char *)"json.scanner", NULL, &constant_bin[ 3764443 ], 2206, NUITKA_BYTECODE_FLAG },
    { (char *)"json.tests", NULL, &constant_bin[ 3766649 ], 3405, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"json.tool", NULL, &constant_bin[ 3770054 ], 1276, NUITKA_BYTECODE_FLAG },
    { (char *)"keyword", NULL, &constant_bin[ 3771330 ], 2087, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3", NULL, &constant_bin[ 3773417 ], 114, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"lib2to3.btm_matcher", NULL, &constant_bin[ 3773531 ], 5767, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.btm_utils", NULL, &constant_bin[ 3779298 ], 7490, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixer_base", NULL, &constant_bin[ 3786788 ], 7169, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixer_util", NULL, &constant_bin[ 3793957 ], 14505, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes", NULL, &constant_bin[ 3808462 ], 120, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"lib2to3.fixes.fix_apply", NULL, &constant_bin[ 3808582 ], 1860, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_asserts", NULL, &constant_bin[ 3810442 ], 1538, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_basestring", NULL, &constant_bin[ 3811980 ], 784, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_buffer", NULL, &constant_bin[ 3812764 ], 941, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_callable", NULL, &constant_bin[ 3813705 ], 1484, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_dict", NULL, &constant_bin[ 3815189 ], 3741, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_except", NULL, &constant_bin[ 3818930 ], 2981, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_exec", NULL, &constant_bin[ 3821911 ], 1409, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_execfile", NULL, &constant_bin[ 3823320 ], 2050, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_exitfunc", NULL, &constant_bin[ 3825370 ], 2724, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_filter", NULL, &constant_bin[ 3828094 ], 2247, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_funcattrs", NULL, &constant_bin[ 3830341 ], 1105, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_future", NULL, &constant_bin[ 3831446 ], 910, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_getcwdu", NULL, &constant_bin[ 3832356 ], 917, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_has_key", NULL, &constant_bin[ 3833273 ], 3175, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_idioms", NULL, &constant_bin[ 3836448 ], 4494, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_import", NULL, &constant_bin[ 3840942 ], 3215, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_imports", NULL, &constant_bin[ 3844157 ], 5322, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_imports2", NULL, &constant_bin[ 3849479 ], 616, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_input", NULL, &constant_bin[ 3850095 ], 1125, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_intern", NULL, &constant_bin[ 3851220 ], 1596, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_isinstance", NULL, &constant_bin[ 3852816 ], 1829, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_itertools", NULL, &constant_bin[ 3854645 ], 1782, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_itertools_imports", NULL, &constant_bin[ 3856427 ], 2007, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_long", NULL, &constant_bin[ 3858434 ], 832, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_map", NULL, &constant_bin[ 3859266 ], 3031, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_metaclass", NULL, &constant_bin[ 3862297 ], 6551, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_methodattrs", NULL, &constant_bin[ 3868848 ], 1129, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_ne", NULL, &constant_bin[ 3869977 ], 973, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_next", NULL, &constant_bin[ 3870950 ], 3507, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_nonzero", NULL, &constant_bin[ 3874457 ], 1077, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_numliterals", NULL, &constant_bin[ 3875534 ], 1237, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_operator", NULL, &constant_bin[ 3876771 ], 5067, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_paren", NULL, &constant_bin[ 3881838 ], 1534, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_print", NULL, &constant_bin[ 3883372 ], 2715, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_raise", NULL, &constant_bin[ 3886087 ], 2489, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_raw_input", NULL, &constant_bin[ 3888576 ], 927, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_reduce", NULL, &constant_bin[ 3889503 ], 1253, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_renames", NULL, &constant_bin[ 3890756 ], 2428, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_repr", NULL, &constant_bin[ 3893184 ], 1007, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_set_literal", NULL, &constant_bin[ 3894191 ], 1976, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_standarderror", NULL, &constant_bin[ 3896167 ], 844, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_sys_exc", NULL, &constant_bin[ 3897011 ], 1693, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_throw", NULL, &constant_bin[ 3898704 ], 1987, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_tuple_params", NULL, &constant_bin[ 3900691 ], 5400, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_types", NULL, &constant_bin[ 3906091 ], 2176, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_unicode", NULL, &constant_bin[ 3908267 ], 1704, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_urllib", NULL, &constant_bin[ 3909971 ], 7107, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_ws_comma", NULL, &constant_bin[ 3917078 ], 1373, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_xrange", NULL, &constant_bin[ 3918451 ], 3039, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_xreadlines", NULL, &constant_bin[ 3921490 ], 1143, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.fixes.fix_zip", NULL, &constant_bin[ 3922633 ], 1337, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.main", NULL, &constant_bin[ 3923970 ], 9773, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.patcomp", NULL, &constant_bin[ 3933743 ], 6598, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2", NULL, &constant_bin[ 3940341 ], 161, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"lib2to3.pgen2.conv", NULL, &constant_bin[ 3940502 ], 8151, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.driver", NULL, &constant_bin[ 3948653 ], 5325, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.grammar", NULL, &constant_bin[ 3953978 ], 5983, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.literals", NULL, &constant_bin[ 3959961 ], 1990, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.parse", NULL, &constant_bin[ 3961951 ], 7168, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.pgen", NULL, &constant_bin[ 3969119 ], 12005, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.token", NULL, &constant_bin[ 3981124 ], 2275, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pgen2.tokenize", NULL, &constant_bin[ 3983399 ], 16861, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pygram", NULL, &constant_bin[ 4000260 ], 1391, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.pytree", NULL, &constant_bin[ 4001651 ], 29915, NUITKA_BYTECODE_FLAG },
    { (char *)"lib2to3.refactor", NULL, &constant_bin[ 4031566 ], 23744, NUITKA_BYTECODE_FLAG },
    { (char *)"linecache", NULL, &constant_bin[ 4055310 ], 3173, NUITKA_BYTECODE_FLAG },
    { (char *)"logging", NULL, &constant_bin[ 4058483 ], 56937, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"logging.config", NULL, &constant_bin[ 4115420 ], 25678, NUITKA_BYTECODE_FLAG },
    { (char *)"logging.handlers", NULL, &constant_bin[ 4141098 ], 38931, NUITKA_BYTECODE_FLAG },
    { (char *)"macpath", NULL, &constant_bin[ 4180029 ], 7544, NUITKA_BYTECODE_FLAG },
    { (char *)"macurl2path", NULL, &constant_bin[ 4187573 ], 2216, NUITKA_BYTECODE_FLAG },
    { (char *)"mailbox", NULL, &constant_bin[ 4189789 ], 75596, NUITKA_BYTECODE_FLAG },
    { (char *)"mailcap", NULL, &constant_bin[ 4265385 ], 7005, NUITKA_BYTECODE_FLAG },
    { (char *)"markupbase", NULL, &constant_bin[ 4272390 ], 9213, NUITKA_BYTECODE_FLAG },
    { (char *)"md5", NULL, &constant_bin[ 4281603 ], 365, NUITKA_BYTECODE_FLAG },
    { (char *)"mhlib", NULL, &constant_bin[ 4281968 ], 33415, NUITKA_BYTECODE_FLAG },
    { (char *)"mimetools", NULL, &constant_bin[ 4315383 ], 8114, NUITKA_BYTECODE_FLAG },
    { (char *)"mimetypes", NULL, &constant_bin[ 4323497 ], 18154, NUITKA_BYTECODE_FLAG },
    { (char *)"mimify", NULL, &constant_bin[ 4341651 ], 11907, NUITKA_BYTECODE_FLAG },
    { (char *)"modulefinder", NULL, &constant_bin[ 4353558 ], 18537, NUITKA_BYTECODE_FLAG },
    { (char *)"msilib", NULL, &constant_bin[ 4372095 ], 19127, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"msilib.schema", NULL, &constant_bin[ 4391222 ], 59838, NUITKA_BYTECODE_FLAG },
    { (char *)"msilib.sequence", NULL, &constant_bin[ 4451060 ], 6264, NUITKA_BYTECODE_FLAG },
    { (char *)"msilib.text", NULL, &constant_bin[ 4457324 ], 18477, NUITKA_BYTECODE_FLAG },
    { (char *)"multifile", NULL, &constant_bin[ 4475801 ], 5336, NUITKA_BYTECODE_FLAG },
    { (char *)"mutex", NULL, &constant_bin[ 4481137 ], 2472, NUITKA_BYTECODE_FLAG },
    { (char *)"netrc", NULL, &constant_bin[ 4483609 ], 4616, NUITKA_BYTECODE_FLAG },
    { (char *)"new", NULL, &constant_bin[ 4488225 ], 849, NUITKA_BYTECODE_FLAG },
    { (char *)"nntplib", NULL, &constant_bin[ 4489074 ], 20813, NUITKA_BYTECODE_FLAG },
    { (char *)"ntpath", NULL, &constant_bin[ 4509887 ], 12974, NUITKA_BYTECODE_FLAG },
    { (char *)"nturl2path", NULL, &constant_bin[ 4522861 ], 1792, NUITKA_BYTECODE_FLAG },
    { (char *)"numbers", NULL, &constant_bin[ 4524653 ], 13694, NUITKA_BYTECODE_FLAG },
    { (char *)"opcode", NULL, &constant_bin[ 4538347 ], 6116, NUITKA_BYTECODE_FLAG },
    { (char *)"optparse", NULL, &constant_bin[ 4544463 ], 53423, NUITKA_BYTECODE_FLAG },
    { (char *)"os", NULL, &constant_bin[ 4597886 ], 25429, NUITKA_BYTECODE_FLAG },
    { (char *)"os2emxpath", NULL, &constant_bin[ 4623315 ], 4439, NUITKA_BYTECODE_FLAG },
    { (char *)"pdb", NULL, &constant_bin[ 4627754 ], 43029, NUITKA_BYTECODE_FLAG },
    { (char *)"pickle", NULL, &constant_bin[ 4670783 ], 37941, NUITKA_BYTECODE_FLAG },
    { (char *)"pickletools", NULL, &constant_bin[ 4708724 ], 56976, NUITKA_BYTECODE_FLAG },
    { (char *)"pipes", NULL, &constant_bin[ 4765700 ], 9220, NUITKA_BYTECODE_FLAG },
    { (char *)"pkgutil", NULL, &constant_bin[ 4774920 ], 18760, NUITKA_BYTECODE_FLAG },
    { (char *)"platform", NULL, &constant_bin[ 4793680 ], 36861, NUITKA_BYTECODE_FLAG },
    { (char *)"plistlib", NULL, &constant_bin[ 4830541 ], 18966, NUITKA_BYTECODE_FLAG },
    { (char *)"popen2", NULL, &constant_bin[ 4849507 ], 8937, NUITKA_BYTECODE_FLAG },
    { (char *)"poplib", NULL, &constant_bin[ 4858444 ], 13171, NUITKA_BYTECODE_FLAG },
    { (char *)"posixfile", NULL, &constant_bin[ 4871615 ], 7584, NUITKA_BYTECODE_FLAG },
    { (char *)"posixpath", NULL, &constant_bin[ 4879199 ], 11487, NUITKA_BYTECODE_FLAG },
    { (char *)"pprint", NULL, &constant_bin[ 4890686 ], 10091, NUITKA_BYTECODE_FLAG },
    { (char *)"profile", NULL, &constant_bin[ 4900777 ], 16255, NUITKA_BYTECODE_FLAG },
    { (char *)"pstats", NULL, &constant_bin[ 4917032 ], 24705, NUITKA_BYTECODE_FLAG },
    { (char *)"pty", NULL, &constant_bin[ 4941737 ], 4908, NUITKA_BYTECODE_FLAG },
    { (char *)"py_compile", NULL, &constant_bin[ 4946645 ], 6381, NUITKA_BYTECODE_FLAG },
    { (char *)"pyclbr", NULL, &constant_bin[ 4953026 ], 9578, NUITKA_BYTECODE_FLAG },
    { (char *)"pydoc", NULL, &constant_bin[ 4962604 ], 91269, NUITKA_BYTECODE_FLAG },
    { (char *)"pydoc_data", NULL, &constant_bin[ 5053873 ], 117, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"pydoc_data.topics", NULL, &constant_bin[ 5053990 ], 395106, NUITKA_BYTECODE_FLAG },
    { (char *)"quopri", NULL, &constant_bin[ 5449096 ], 6509, NUITKA_BYTECODE_FLAG },
    { (char *)"random", NULL, &constant_bin[ 5455605 ], 25345, NUITKA_BYTECODE_FLAG },
    { (char *)"repr", NULL, &constant_bin[ 5480950 ], 5292, NUITKA_BYTECODE_FLAG },
    { (char *)"rexec", NULL, &constant_bin[ 5486242 ], 23864, NUITKA_BYTECODE_FLAG },
    { (char *)"rfc822", NULL, &constant_bin[ 5510106 ], 31519, NUITKA_BYTECODE_FLAG },
    { (char *)"rlcompleter", NULL, &constant_bin[ 5541625 ], 5930, NUITKA_BYTECODE_FLAG },
    { (char *)"robotparser", NULL, &constant_bin[ 5547555 ], 7832, NUITKA_BYTECODE_FLAG },
    { (char *)"runpy", NULL, &constant_bin[ 5555387 ], 8300, NUITKA_BYTECODE_FLAG },
    { (char *)"sched", NULL, &constant_bin[ 5563687 ], 4941, NUITKA_BYTECODE_FLAG },
    { (char *)"sets", NULL, &constant_bin[ 5568628 ], 16607, NUITKA_BYTECODE_FLAG },
    { (char *)"sgmllib", NULL, &constant_bin[ 5585235 ], 15193, NUITKA_BYTECODE_FLAG },
    { (char *)"sha", NULL, &constant_bin[ 5600428 ], 408, NUITKA_BYTECODE_FLAG },
    { (char *)"shelve", NULL, &constant_bin[ 5600836 ], 10124, NUITKA_BYTECODE_FLAG },
    { (char *)"shlex", NULL, &constant_bin[ 5610960 ], 7469, NUITKA_BYTECODE_FLAG },
    { (char *)"shutil", NULL, &constant_bin[ 5618429 ], 18259, NUITKA_BYTECODE_FLAG },
    { (char *)"site", NULL, &constant_bin[ 5636688 ], 16755, NUITKA_BYTECODE_FLAG },
    { (char *)"smtpd", NULL, &constant_bin[ 5653443 ], 15733, NUITKA_BYTECODE_FLAG },
    { (char *)"smtplib", NULL, &constant_bin[ 5669176 ], 29950, NUITKA_BYTECODE_FLAG },
    { (char *)"sndhdr", NULL, &constant_bin[ 5699126 ], 7264, NUITKA_BYTECODE_FLAG },
    { (char *)"socket", NULL, &constant_bin[ 5706390 ], 15948, NUITKA_BYTECODE_FLAG },
    { (char *)"sqlite3", NULL, &constant_bin[ 5722338 ], 151, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"sqlite3.dbapi2", NULL, &constant_bin[ 5722489 ], 2655, NUITKA_BYTECODE_FLAG },
    { (char *)"sqlite3.dump", NULL, &constant_bin[ 5725144 ], 2048, NUITKA_BYTECODE_FLAG },
    { (char *)"sre", NULL, &constant_bin[ 5727192 ], 506, NUITKA_BYTECODE_FLAG },
    { (char *)"ssl", NULL, &constant_bin[ 5727698 ], 30705, NUITKA_BYTECODE_FLAG },
    { (char *)"stat", NULL, &constant_bin[ 5758403 ], 2693, NUITKA_BYTECODE_FLAG },
    { (char *)"statvfs", NULL, &constant_bin[ 5761096 ], 607, NUITKA_BYTECODE_FLAG },
    { (char *)"string", NULL, &constant_bin[ 5761703 ], 19648, NUITKA_BYTECODE_FLAG },
    { (char *)"stringold", NULL, &constant_bin[ 5781351 ], 12406, NUITKA_BYTECODE_FLAG },
    { (char *)"struct", NULL, &constant_bin[ 5793757 ], 226, NUITKA_BYTECODE_FLAG },
    { (char *)"subprocess", NULL, &constant_bin[ 5793983 ], 41664, NUITKA_BYTECODE_FLAG },
    { (char *)"sunau", NULL, &constant_bin[ 5835647 ], 18157, NUITKA_BYTECODE_FLAG },
    { (char *)"sunaudio", NULL, &constant_bin[ 5853804 ], 1954, NUITKA_BYTECODE_FLAG },
    { (char *)"symbol", NULL, &constant_bin[ 5855758 ], 3008, NUITKA_BYTECODE_FLAG },
    { (char *)"symtable", NULL, &constant_bin[ 5858766 ], 11528, NUITKA_BYTECODE_FLAG },
    { (char *)"sysconfig", NULL, &constant_bin[ 5870294 ], 17413, NUITKA_BYTECODE_FLAG },
    { (char *)"tabnanny", NULL, &constant_bin[ 5887707 ], 8135, NUITKA_BYTECODE_FLAG },
    { (char *)"tarfile", NULL, &constant_bin[ 5895842 ], 74594, NUITKA_BYTECODE_FLAG },
    { (char *)"telnetlib", NULL, &constant_bin[ 5970436 ], 22960, NUITKA_BYTECODE_FLAG },
    { (char *)"tempfile", NULL, &constant_bin[ 5993396 ], 19704, NUITKA_BYTECODE_FLAG },
    { (char *)"textwrap", NULL, &constant_bin[ 6013100 ], 11821, NUITKA_BYTECODE_FLAG },
    { (char *)"this", NULL, &constant_bin[ 6024921 ], 1207, NUITKA_BYTECODE_FLAG },
    { (char *)"threading", NULL, &constant_bin[ 6026128 ], 42204, NUITKA_BYTECODE_FLAG },
    { (char *)"timeit", NULL, &constant_bin[ 6068332 ], 11700, NUITKA_BYTECODE_FLAG },
    { (char *)"tkColorChooser", NULL, &constant_bin[ 6080032 ], 1387, NUITKA_BYTECODE_FLAG },
    { (char *)"tkCommonDialog", NULL, &constant_bin[ 6081419 ], 1478, NUITKA_BYTECODE_FLAG },
    { (char *)"tkFileDialog", NULL, &constant_bin[ 6082897 ], 5073, NUITKA_BYTECODE_FLAG },
    { (char *)"tkFont", NULL, &constant_bin[ 6087970 ], 7016, NUITKA_BYTECODE_FLAG },
    { (char *)"tkMessageBox", NULL, &constant_bin[ 6094986 ], 3831, NUITKA_BYTECODE_FLAG },
    { (char *)"tkSimpleDialog", NULL, &constant_bin[ 6098817 ], 8975, NUITKA_BYTECODE_FLAG },
    { (char *)"toaiff", NULL, &constant_bin[ 6107792 ], 3078, NUITKA_BYTECODE_FLAG },
    { (char *)"token", NULL, &constant_bin[ 6110870 ], 3783, NUITKA_BYTECODE_FLAG },
    { (char *)"tokenize", NULL, &constant_bin[ 6114653 ], 14134, NUITKA_BYTECODE_FLAG },
    { (char *)"trace", NULL, &constant_bin[ 6128787 ], 22614, NUITKA_BYTECODE_FLAG },
    { (char *)"traceback", NULL, &constant_bin[ 6151401 ], 11571, NUITKA_BYTECODE_FLAG },
    { (char *)"ttk", NULL, &constant_bin[ 6162972 ], 61816, NUITKA_BYTECODE_FLAG },
    { (char *)"tty", NULL, &constant_bin[ 6224788 ], 1294, NUITKA_BYTECODE_FLAG },
    { (char *)"turtle", NULL, &constant_bin[ 6226082 ], 138331, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest", NULL, &constant_bin[ 6364413 ], 2951, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"unittest.case", NULL, &constant_bin[ 6367364 ], 39878, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.loader", NULL, &constant_bin[ 6407242 ], 11262, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.main", NULL, &constant_bin[ 6418504 ], 7958, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.result", NULL, &constant_bin[ 6426462 ], 7796, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.runner", NULL, &constant_bin[ 6434258 ], 7536, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.signals", NULL, &constant_bin[ 6441794 ], 2708, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.suite", NULL, &constant_bin[ 6444502 ], 10355, NUITKA_BYTECODE_FLAG },
    { (char *)"unittest.util", NULL, &constant_bin[ 6454857 ], 4470, NUITKA_BYTECODE_FLAG },
    { (char *)"urllib", NULL, &constant_bin[ 6459327 ], 49891, NUITKA_BYTECODE_FLAG },
    { (char *)"urllib2", NULL, &constant_bin[ 6509218 ], 46607, NUITKA_BYTECODE_FLAG },
    { (char *)"urlparse", NULL, &constant_bin[ 6555825 ], 14378, NUITKA_BYTECODE_FLAG },
    { (char *)"user", NULL, &constant_bin[ 6570203 ], 1711, NUITKA_BYTECODE_FLAG },
    { (char *)"uu", NULL, &constant_bin[ 6571914 ], 4279, NUITKA_BYTECODE_FLAG },
    { (char *)"uuid", NULL, &constant_bin[ 6576193 ], 22593, NUITKA_BYTECODE_FLAG },
    { (char *)"warnings", NULL, &constant_bin[ 6598786 ], 13065, NUITKA_BYTECODE_FLAG },
    { (char *)"wave", NULL, &constant_bin[ 6611851 ], 19737, NUITKA_BYTECODE_FLAG },
    { (char *)"weakref", NULL, &constant_bin[ 6631588 ], 15087, NUITKA_BYTECODE_FLAG },
    { (char *)"webbrowser", NULL, &constant_bin[ 6646675 ], 19546, NUITKA_BYTECODE_FLAG },
    { (char *)"whichdb", NULL, &constant_bin[ 6666221 ], 2223, NUITKA_BYTECODE_FLAG },
    { (char *)"wsgiref", NULL, &constant_bin[ 6668444 ], 716, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"wsgiref.handlers", NULL, &constant_bin[ 6669160 ], 16061, NUITKA_BYTECODE_FLAG },
    { (char *)"wsgiref.headers", NULL, &constant_bin[ 6685221 ], 7375, NUITKA_BYTECODE_FLAG },
    { (char *)"wsgiref.simple_server", NULL, &constant_bin[ 6692596 ], 6157, NUITKA_BYTECODE_FLAG },
    { (char *)"wsgiref.util", NULL, &constant_bin[ 6698753 ], 5925, NUITKA_BYTECODE_FLAG },
    { (char *)"wsgiref.validate", NULL, &constant_bin[ 6704678 ], 16653, NUITKA_BYTECODE_FLAG },
    { (char *)"xdrlib", NULL, &constant_bin[ 6721331 ], 9683, NUITKA_BYTECODE_FLAG },
    { (char *)"xml", NULL, &constant_bin[ 6731014 ], 1065, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"xml.dom", NULL, &constant_bin[ 6732079 ], 6361, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"xml.dom.NodeFilter", NULL, &constant_bin[ 6738440 ], 1103, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.domreg", NULL, &constant_bin[ 6739543 ], 3278, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.expatbuilder", NULL, &constant_bin[ 6742821 ], 32735, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.minicompat", NULL, &constant_bin[ 6775556 ], 3476, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.minidom", NULL, &constant_bin[ 6779032 ], 64543, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.pulldom", NULL, &constant_bin[ 6843575 ], 12860, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.dom.xmlbuilder", NULL, &constant_bin[ 6856435 ], 16231, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.etree", NULL, &constant_bin[ 6872666 ], 116, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"xml.etree.ElementInclude", NULL, &constant_bin[ 6872782 ], 1939, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.etree.ElementPath", NULL, &constant_bin[ 6874721 ], 7483, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.etree.ElementTree", NULL, &constant_bin[ 6882204 ], 34349, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.etree.cElementTree", NULL, &constant_bin[ 6916553 ], 163, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.parsers", NULL, &constant_bin[ 6916716 ], 301, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"xml.parsers.expat", NULL, &constant_bin[ 6917017 ], 274, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.sax", NULL, &constant_bin[ 6917291 ], 3661, NUITKA_BYTECODE_FLAG | NUITKA_PACKAGE_FLAG },
    { (char *)"xml.sax._exceptions", NULL, &constant_bin[ 6920952 ], 6076, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.sax.expatreader", NULL, &constant_bin[ 6927028 ], 14253, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.sax.handler", NULL, &constant_bin[ 6941281 ], 12895, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.sax.saxutils", NULL, &constant_bin[ 6954176 ], 14523, NUITKA_BYTECODE_FLAG },
    { (char *)"xml.sax.xmlreader", NULL, &constant_bin[ 6968699 ], 18874, NUITKA_BYTECODE_FLAG },
    { (char *)"xmllib", NULL, &constant_bin[ 6987573 ], 26569, NUITKA_BYTECODE_FLAG },
    { (char *)"xmlrpclib", NULL, &constant_bin[ 7014142 ], 43205, NUITKA_BYTECODE_FLAG },
    { (char *)"zipfile", NULL, &constant_bin[ 7057347 ], 42488, NUITKA_BYTECODE_FLAG },
    { NULL, NULL, 0 }
};

void setupMetaPathBasedLoader( void )
{
    static bool init_done = false;

    if ( init_done == false )
    {
        registerMetaPathBasedUnfreezer( meta_path_loader_entries );
        init_done = true;
    }
}
#else

void setupMetaPathBasedLoader( void )
{
}

#endif
