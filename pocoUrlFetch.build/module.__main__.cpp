// Generated code for Python source for module '__main__'
// created by Nuitka version 0.5.20

// This code is in part copyright 2016 Kay Hayen.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "nuitka/prelude.hpp"

#include "__helpers.hpp"

// The _module___main__ is a Python object pointer of module type.

// Note: For full compatibility with CPython, every module variable access
// needs to go through it except for cases where the module cannot possibly
// have changed in the mean time.

PyObject *module___main__;
PyDictObject *moduledict___main__;

// The module constants used
static PyObject *const_str_angle_module;
static PyObject *const_str_plain_i;
static PyObject *const_str_plain_imgurl;
extern PyObject *const_str_plain___main__;
static PyObject *const_str_plain_write;
static PyObject *const_str_digest_8928ec53cd49ffa0a7a7e1ec65fadaa0;
extern PyObject *const_str_plain___exit__;
static PyObject *const_tuple_str_newline_tuple;
static PyObject *const_int_neg_1;
static PyObject *const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple;
extern PyObject *const_dict_empty;
static PyObject *const_str_plain_DOTALL;
static PyObject *const_str_digest_befb0ab5fd2dafe8a0ccc9c9b1e4be6e;
static PyObject *const_str_plain_urllib;
extern PyObject *const_str_plain_site;
static PyObject *const_str_digest_26c3335a962f2325c06d4aed04ae2a29;
static PyObject *const_str_plain_IGNORECASE;
static PyObject *const_tuple_0fd0953406d46cca6f9c17f5a5f4c424_tuple;
extern PyObject *const_tuple_empty;
static PyObject *const_str_digest_37d0cb8af5d952b56ed4f68bd54a6819;
static PyObject *const_str_plain_findall;
extern PyObject *const_str_plain___doc__;
static PyObject *const_str_plain_sys;
static PyObject *const_str_plain_read;
static PyObject *const_str_plain_html;
extern PyObject *const_int_0;
static PyObject *const_tuple_str_digest_c59e90e4116bd3913a98e5005e589c71_tuple;
static PyObject *const_str_plain_imgList;
extern PyObject *const_str_plain___enter__;
static PyObject *const_str_plain_getHtml;
extern PyObject *const_str_plain___file__;
static PyObject *const_str_plain_append;
static PyObject *const_str_plain_uf;
static PyObject *const_str_plain_url;
static PyObject *const_str_plain_page;
static PyObject *const_str_plain_tui;
static PyObject *const_str_newline;
static PyObject *const_str_digest_c59e90e4116bd3913a98e5005e589c71;
static PyObject *const_tuple_none_none_none_tuple;
static PyObject *const_str_digest_098808d9d1e5f7e01e3280159c1d9276;
extern PyObject *const_str_empty;
static PyObject *const_str_plain_getImg;
extern PyObject *const_str_plain_compile;
static PyObject *const_str_digest_826c192eef3d46dcd9dc9d613067c8e9;
static PyObject *const_str_plain_m;
static PyObject *const_str_plain_w;
static PyObject *const_str_plain_urlopen;
static PyObject *const_unicode_digest_24069915adcf5647c79e35c204e91800;
static PyObject *const_str_plain_urltext;
static PyObject *const_str_plain_rg;
static PyObject *const_str_plain_re;
static PyObject *const_str_plain_raw_input;
static PyObject *const_str_digest_32e987e541df10211e4f46dfffd489cc;
static PyObject *module_filename_obj;

static bool constants_created = false;

static void createModuleConstants( void )
{
    const_str_angle_module = UNSTREAM_STRING( &constant_bin[ 0 ], 8, 0 );
    const_str_plain_i = UNSTREAM_CHAR( 105, 1 );
    const_str_plain_imgurl = UNSTREAM_STRING( &constant_bin[ 8 ], 6, 1 );
    const_str_plain_write = UNSTREAM_STRING( &constant_bin[ 14 ], 5, 1 );
    const_str_digest_8928ec53cd49ffa0a7a7e1ec65fadaa0 = UNSTREAM_STRING( &constant_bin[ 19 ], 3, 0 );
    const_tuple_str_newline_tuple = PyTuple_New( 1 );
    const_str_newline = UNSTREAM_CHAR( 10, 0 );
    PyTuple_SET_ITEM( const_tuple_str_newline_tuple, 0, const_str_newline ); Py_INCREF( const_str_newline );
    const_int_neg_1 = PyInt_FromLong( -1l );
    const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple = PyTuple_New( 3 );
    const_str_plain_url = UNSTREAM_STRING( &constant_bin[ 11 ], 3, 1 );
    PyTuple_SET_ITEM( const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple, 0, const_str_plain_url ); Py_INCREF( const_str_plain_url );
    const_str_plain_page = UNSTREAM_STRING( &constant_bin[ 22 ], 4, 1 );
    PyTuple_SET_ITEM( const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple, 1, const_str_plain_page ); Py_INCREF( const_str_plain_page );
    const_str_plain_html = UNSTREAM_STRING( &constant_bin[ 26 ], 4, 1 );
    PyTuple_SET_ITEM( const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple, 2, const_str_plain_html ); Py_INCREF( const_str_plain_html );
    const_str_plain_DOTALL = UNSTREAM_STRING( &constant_bin[ 30 ], 6, 1 );
    const_str_digest_befb0ab5fd2dafe8a0ccc9c9b1e4be6e = UNSTREAM_STRING( &constant_bin[ 36 ], 5, 0 );
    const_str_plain_urllib = UNSTREAM_STRING( &constant_bin[ 41 ], 6, 1 );
    const_str_digest_26c3335a962f2325c06d4aed04ae2a29 = UNSTREAM_STRING( &constant_bin[ 47 ], 7, 0 );
    const_str_plain_IGNORECASE = UNSTREAM_STRING( &constant_bin[ 54 ], 10, 1 );
    const_tuple_0fd0953406d46cca6f9c17f5a5f4c424_tuple = PyMarshal_ReadObjectFromString( (char *)&constant_bin[ 64 ], 359 );
    const_str_digest_37d0cb8af5d952b56ed4f68bd54a6819 = UNSTREAM_STRING( &constant_bin[ 423 ], 15, 0 );
    const_str_plain_findall = UNSTREAM_STRING( &constant_bin[ 438 ], 7, 1 );
    const_str_plain_sys = UNSTREAM_STRING( &constant_bin[ 445 ], 3, 1 );
    const_str_plain_read = UNSTREAM_STRING( &constant_bin[ 448 ], 4, 1 );
    const_tuple_str_digest_c59e90e4116bd3913a98e5005e589c71_tuple = PyTuple_New( 1 );
    const_str_digest_c59e90e4116bd3913a98e5005e589c71 = UNSTREAM_STRING( &constant_bin[ 452 ], 2, 0 );
    PyTuple_SET_ITEM( const_tuple_str_digest_c59e90e4116bd3913a98e5005e589c71_tuple, 0, const_str_digest_c59e90e4116bd3913a98e5005e589c71 ); Py_INCREF( const_str_digest_c59e90e4116bd3913a98e5005e589c71 );
    const_str_plain_imgList = UNSTREAM_STRING( &constant_bin[ 372 ], 7, 1 );
    const_str_plain_getHtml = UNSTREAM_STRING( &constant_bin[ 454 ], 7, 1 );
    const_str_plain_append = UNSTREAM_STRING( &constant_bin[ 461 ], 6, 1 );
    const_str_plain_uf = UNSTREAM_STRING( &constant_bin[ 415 ], 2, 1 );
    const_str_plain_tui = UNSTREAM_STRING( &constant_bin[ 407 ], 3, 1 );
    const_tuple_none_none_none_tuple = PyTuple_New( 3 );
    PyTuple_SET_ITEM( const_tuple_none_none_none_tuple, 0, Py_None ); Py_INCREF( Py_None );
    PyTuple_SET_ITEM( const_tuple_none_none_none_tuple, 1, Py_None ); Py_INCREF( Py_None );
    PyTuple_SET_ITEM( const_tuple_none_none_none_tuple, 2, Py_None ); Py_INCREF( Py_None );
    const_str_digest_098808d9d1e5f7e01e3280159c1d9276 = UNSTREAM_STRING( &constant_bin[ 467 ], 3, 0 );
    const_str_plain_getImg = UNSTREAM_STRING( &constant_bin[ 470 ], 6, 1 );
    const_str_digest_826c192eef3d46dcd9dc9d613067c8e9 = UNSTREAM_STRING( &constant_bin[ 476 ], 254, 0 );
    const_str_plain_m = UNSTREAM_CHAR( 109, 1 );
    const_str_plain_w = UNSTREAM_CHAR( 119, 1 );
    const_str_plain_urlopen = UNSTREAM_STRING( &constant_bin[ 730 ], 7, 1 );
    const_unicode_digest_24069915adcf5647c79e35c204e91800 = UNSTREAM_UNICODE( &constant_bin[ 737 ], 22 );
    const_str_plain_urltext = UNSTREAM_STRING( &constant_bin[ 395 ], 7, 1 );
    const_str_plain_rg = UNSTREAM_STRING( &constant_bin[ 353 ], 2, 1 );
    const_str_plain_re = UNSTREAM_STRING( &constant_bin[ 83 ], 2, 1 );
    const_str_plain_raw_input = UNSTREAM_STRING( &constant_bin[ 759 ], 9, 1 );
    const_str_digest_32e987e541df10211e4f46dfffd489cc = UNSTREAM_STRING( &constant_bin[ 768 ], 4, 0 );

    constants_created = true;
}

#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants___main__( void )
{
    // The module may not have been used at all.
    if (constants_created == false) return;


}
#endif

// The module code objects.
static PyCodeObject *codeobj_ff3939801846d5aef72184cc01c9702d;
static PyCodeObject *codeobj_d0e9aa0757b9c191be3a6a186bd40f41;
static PyCodeObject *codeobj_a307895767dc11223c851da7b6909d12;

static void createModuleCodeObjects(void)
{
    module_filename_obj = MAKE_RELATIVE_PATH( const_str_digest_37d0cb8af5d952b56ed4f68bd54a6819 );
    codeobj_ff3939801846d5aef72184cc01c9702d = MAKE_CODEOBJ( module_filename_obj, const_str_angle_module, 1, const_tuple_empty, 0, CO_NOFREE );
    codeobj_d0e9aa0757b9c191be3a6a186bd40f41 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_getHtml, 5, const_tuple_str_plain_url_str_plain_page_str_plain_html_tuple, 1, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
    codeobj_a307895767dc11223c851da7b6909d12 = MAKE_CODEOBJ( module_filename_obj, const_str_plain_getImg, 10, const_tuple_0fd0953406d46cca6f9c17f5a5f4c424_tuple, 1, CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE );
}

// The module function declarations.
static PyObject *MAKE_FUNCTION_function_1_getHtml_of___main__(  );


static PyObject *MAKE_FUNCTION_function_2_getImg_of___main__(  );


// The module function definitions.
static PyObject *impl_function_1_getHtml_of___main__( Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_url = python_pars[ 0 ];
    PyObject *var_page = NULL;
    PyObject *var_html = NULL;
    PyObject *exception_type = NULL, *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = -1;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_assign_source_1;
    PyObject *tmp_assign_source_2;
    PyObject *tmp_called_name_1;
    PyObject *tmp_called_name_2;
    PyObject *tmp_frame_locals;
    PyObject *tmp_return_value;
    PyObject *tmp_source_name_1;
    PyObject *tmp_source_name_2;
    static PyFrameObject *cache_frame_function = NULL;

    PyFrameObject *frame_function;

    tmp_return_value = NULL;

    // Actual function code.
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_function, codeobj_d0e9aa0757b9c191be3a6a186bd40f41, module___main__ );
    frame_function = cache_frame_function;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_function );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    Py_INCREF( frame_function );
    assert( Py_REFCNT( frame_function ) == 2 ); // Frame stack

#if PYTHON_VERSION >= 340
    frame_function->f_executing += 1;
#endif

    // Framed code:
    tmp_source_name_1 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_urllib );

    if (unlikely( tmp_source_name_1 == NULL ))
    {
        tmp_source_name_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_urllib );
    }

    if ( tmp_source_name_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "global name '%s' is not defined", "urllib" );
        exception_tb = NULL;

        exception_lineno = 6;
        goto frame_exception_exit_1;
    }

    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_urlopen );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 6;
        goto frame_exception_exit_1;
    }
    tmp_args_element_name_1 = par_url;

    frame_function->f_lineno = 6;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_assign_source_1 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    if ( tmp_assign_source_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 6;
        goto frame_exception_exit_1;
    }
    assert( var_page == NULL );
    var_page = tmp_assign_source_1;

    tmp_source_name_2 = var_page;

    tmp_called_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_2, const_str_plain_read );
    if ( tmp_called_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 7;
        goto frame_exception_exit_1;
    }
    frame_function->f_lineno = 7;
    tmp_assign_source_2 = CALL_FUNCTION_NO_ARGS( tmp_called_name_2 );
    Py_DECREF( tmp_called_name_2 );
    if ( tmp_assign_source_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 7;
        goto frame_exception_exit_1;
    }
    assert( var_html == NULL );
    var_html = tmp_assign_source_2;


#if 0
    RESTORE_FRAME_EXCEPTION( frame_function );
#endif
    // Put the previous frame back on top.
    popFrameStack();
#if PYTHON_VERSION >= 340
    frame_function->f_executing -= 1;
#endif
    Py_DECREF( frame_function );
    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_function );
#endif

    {
        bool needs_detach = false;

        if ( exception_tb == NULL )
        {
            exception_tb = MAKE_TRACEBACK( frame_function, exception_lineno );
            needs_detach = true;
        }
        else if ( exception_lineno != -1 )
        {
            PyTracebackObject *traceback_new = MAKE_TRACEBACK( frame_function, exception_lineno );
            traceback_new->tb_next = exception_tb;
            exception_tb = traceback_new;

            needs_detach = true;
        }

        if (needs_detach)
        {

            tmp_frame_locals = PyDict_New();
            if ( par_url )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_url,
                    par_url
                );

                assert( res == 0 );
            }

            if ( var_page )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_page,
                    var_page
                );

                assert( res == 0 );
            }

            if ( var_html )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_html,
                    var_html
                );

                assert( res == 0 );
            }



            detachFrame( exception_tb, tmp_frame_locals );
        }
    }

    popFrameStack();

#if PYTHON_VERSION >= 340
    frame_function->f_executing -= 1;
#endif
    Py_DECREF( frame_function );

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;

    tmp_return_value = var_html;

    Py_INCREF( tmp_return_value );
    goto try_return_handler_1;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( function_1_getHtml_of___main__ );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    CHECK_OBJECT( (PyObject *)par_url );
    Py_DECREF( par_url );
    par_url = NULL;

    CHECK_OBJECT( (PyObject *)var_page );
    Py_DECREF( var_page );
    var_page = NULL;

    CHECK_OBJECT( (PyObject *)var_html );
    Py_DECREF( var_html );
    var_html = NULL;

    goto function_return_exit;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    CHECK_OBJECT( (PyObject *)par_url );
    Py_DECREF( par_url );
    par_url = NULL;

    Py_XDECREF( var_page );
    var_page = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto function_exception_exit;
    // End of try:

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( function_1_getHtml_of___main__ );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
    function_return_exit:

    CHECK_OBJECT( tmp_return_value );
    assert( had_error || !ERROR_OCCURRED() );
    return tmp_return_value;

}


static PyObject *impl_function_2_getImg_of___main__( Nuitka_FunctionObject const *self, PyObject **python_pars )
{
    // Preserve error status for checks
#ifndef __NUITKA_NO_ASSERT__
    NUITKA_MAY_BE_UNUSED bool had_error = ERROR_OCCURRED();
#endif

    // Local variable declarations.
    PyObject *par_html = python_pars[ 0 ];
    PyObject *var_rg = NULL;
    PyObject *var_m = NULL;
    PyObject *var_imgList = NULL;
    PyObject *var_imgurl = NULL;
    PyObject *var_urltext = NULL;
    PyObject *var_tui = NULL;
    PyObject *var_uf = NULL;
    PyObject *var_i = NULL;
    PyObject *tmp_for_loop_1__for_iterator = NULL;
    PyObject *tmp_for_loop_1__iter_value = NULL;
    PyObject *tmp_for_loop_2__for_iterator = NULL;
    PyObject *tmp_for_loop_2__iter_value = NULL;
    PyObject *tmp_for_loop_3__for_iterator = NULL;
    PyObject *tmp_for_loop_3__iter_value = NULL;
    PyObject *tmp_with_1__source = NULL;
    PyObject *tmp_with_1__exit = NULL;
    PyObject *tmp_with_1__enter = NULL;
    PyObject *tmp_with_1__indicator = NULL;
    PyObject *exception_type = NULL, *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = -1;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;
    PyObject *exception_keeper_type_5;
    PyObject *exception_keeper_value_5;
    PyTracebackObject *exception_keeper_tb_5;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_5;
    PyObject *exception_keeper_type_6;
    PyObject *exception_keeper_value_6;
    PyTracebackObject *exception_keeper_tb_6;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_6;
    PyObject *exception_keeper_type_7;
    PyObject *exception_keeper_value_7;
    PyTracebackObject *exception_keeper_tb_7;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_7;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_args_element_name_2;
    PyObject *tmp_args_element_name_3;
    PyObject *tmp_args_element_name_4;
    PyObject *tmp_args_element_name_5;
    PyObject *tmp_args_element_name_6;
    PyObject *tmp_args_element_name_7;
    PyObject *tmp_args_element_name_8;
    PyObject *tmp_assign_source_1;
    PyObject *tmp_assign_source_2;
    PyObject *tmp_assign_source_3;
    PyObject *tmp_assign_source_4;
    PyObject *tmp_assign_source_5;
    PyObject *tmp_assign_source_6;
    PyObject *tmp_assign_source_7;
    PyObject *tmp_assign_source_8;
    PyObject *tmp_assign_source_9;
    PyObject *tmp_assign_source_10;
    PyObject *tmp_assign_source_11;
    PyObject *tmp_assign_source_12;
    PyObject *tmp_assign_source_13;
    PyObject *tmp_assign_source_14;
    PyObject *tmp_assign_source_15;
    PyObject *tmp_assign_source_16;
    PyObject *tmp_assign_source_17;
    PyObject *tmp_assign_source_18;
    PyObject *tmp_assign_source_19;
    PyObject *tmp_assign_source_20;
    PyObject *tmp_assign_source_21;
    PyObject *tmp_called_name_1;
    PyObject *tmp_called_name_2;
    PyObject *tmp_called_name_3;
    PyObject *tmp_called_name_4;
    PyObject *tmp_called_name_5;
    PyObject *tmp_called_name_6;
    PyObject *tmp_called_name_7;
    PyObject *tmp_called_name_8;
    PyObject *tmp_called_name_9;
    PyObject *tmp_compare_left_1;
    PyObject *tmp_compare_left_2;
    PyObject *tmp_compare_left_3;
    PyObject *tmp_compare_right_1;
    PyObject *tmp_compare_right_2;
    PyObject *tmp_compare_right_3;
    int tmp_cond_truth_1;
    PyObject *tmp_cond_value_1;
    int tmp_exc_match_exception_match_1;
    PyObject *tmp_frame_locals;
    bool tmp_is_1;
    bool tmp_is_2;
    PyObject *tmp_iter_arg_1;
    PyObject *tmp_iter_arg_2;
    PyObject *tmp_iter_arg_3;
    PyObject *tmp_left_name_1;
    PyObject *tmp_left_name_2;
    PyObject *tmp_left_name_3;
    PyObject *tmp_left_name_4;
    PyObject *tmp_left_name_5;
    PyObject *tmp_left_name_6;
    PyObject *tmp_left_name_7;
    PyObject *tmp_left_name_8;
    PyObject *tmp_list_arg_1;
    PyObject *tmp_next_source_1;
    PyObject *tmp_next_source_2;
    PyObject *tmp_next_source_3;
    PyObject *tmp_open_filename_1;
    PyObject *tmp_open_mode_1;
    bool tmp_result;
    PyObject *tmp_return_value;
    PyObject *tmp_right_name_1;
    PyObject *tmp_right_name_2;
    PyObject *tmp_right_name_3;
    PyObject *tmp_right_name_4;
    PyObject *tmp_right_name_5;
    PyObject *tmp_right_name_6;
    PyObject *tmp_right_name_7;
    PyObject *tmp_right_name_8;
    PyObject *tmp_set_arg_1;
    PyObject *tmp_source_name_1;
    PyObject *tmp_source_name_2;
    PyObject *tmp_source_name_3;
    PyObject *tmp_source_name_4;
    PyObject *tmp_source_name_5;
    PyObject *tmp_source_name_6;
    PyObject *tmp_source_name_7;
    PyObject *tmp_source_name_8;
    PyObject *tmp_source_name_9;
    PyObject *tmp_str_arg_1;
    NUITKA_MAY_BE_UNUSED PyObject *tmp_unused;
    static PyFrameObject *cache_frame_function = NULL;

    PyFrameObject *frame_function;

    tmp_return_value = NULL;

    // Actual function code.
    // Tried code:
    MAKE_OR_REUSE_FRAME( cache_frame_function, codeobj_a307895767dc11223c851da7b6909d12, module___main__ );
    frame_function = cache_frame_function;

    // Push the new frame as the currently active one.
    pushFrameStack( frame_function );

    // Mark the frame object as in use, ref count 1 will be up for reuse.
    Py_INCREF( frame_function );
    assert( Py_REFCNT( frame_function ) == 2 ); // Frame stack

#if PYTHON_VERSION >= 340
    frame_function->f_executing += 1;
#endif

    // Framed code:
    tmp_source_name_1 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_re );

    if (unlikely( tmp_source_name_1 == NULL ))
    {
        tmp_source_name_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_re );
    }

    if ( tmp_source_name_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "global name '%s' is not defined", "re" );
        exception_tb = NULL;

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }

    tmp_called_name_1 = LOOKUP_ATTRIBUTE( tmp_source_name_1, const_str_plain_compile );
    if ( tmp_called_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_left_name_6 = const_str_digest_826c192eef3d46dcd9dc9d613067c8e9;
    tmp_right_name_1 = const_str_digest_32e987e541df10211e4f46dfffd489cc;
    tmp_left_name_5 = BINARY_OPERATION_ADD( tmp_left_name_6, tmp_right_name_1 );
    if ( tmp_left_name_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_right_name_2 = const_str_digest_befb0ab5fd2dafe8a0ccc9c9b1e4be6e;
    tmp_left_name_4 = BINARY_OPERATION_ADD( tmp_left_name_5, tmp_right_name_2 );
    Py_DECREF( tmp_left_name_5 );
    if ( tmp_left_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_right_name_3 = const_str_digest_8928ec53cd49ffa0a7a7e1ec65fadaa0;
    tmp_left_name_3 = BINARY_OPERATION_ADD( tmp_left_name_4, tmp_right_name_3 );
    Py_DECREF( tmp_left_name_4 );
    if ( tmp_left_name_3 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_right_name_4 = const_str_digest_befb0ab5fd2dafe8a0ccc9c9b1e4be6e;
    tmp_left_name_2 = BINARY_OPERATION_ADD( tmp_left_name_3, tmp_right_name_4 );
    Py_DECREF( tmp_left_name_3 );
    if ( tmp_left_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_right_name_5 = const_str_digest_098808d9d1e5f7e01e3280159c1d9276;
    tmp_left_name_1 = BINARY_OPERATION_ADD( tmp_left_name_2, tmp_right_name_5 );
    Py_DECREF( tmp_left_name_2 );
    if ( tmp_left_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_right_name_6 = const_str_digest_befb0ab5fd2dafe8a0ccc9c9b1e4be6e;
    tmp_args_element_name_1 = BINARY_OPERATION_ADD( tmp_left_name_1, tmp_right_name_6 );
    Py_DECREF( tmp_left_name_1 );
    if ( tmp_args_element_name_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_source_name_2 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_re );

    if (unlikely( tmp_source_name_2 == NULL ))
    {
        tmp_source_name_2 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_re );
    }

    if ( tmp_source_name_2 == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_args_element_name_1 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "global name '%s' is not defined", "re" );
        exception_tb = NULL;

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }

    tmp_left_name_7 = LOOKUP_ATTRIBUTE( tmp_source_name_2, const_str_plain_IGNORECASE );
    if ( tmp_left_name_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_args_element_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_source_name_3 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_re );

    if (unlikely( tmp_source_name_3 == NULL ))
    {
        tmp_source_name_3 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_re );
    }

    if ( tmp_source_name_3 == NULL )
    {
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_args_element_name_1 );
        Py_DECREF( tmp_left_name_7 );
        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "global name '%s' is not defined", "re" );
        exception_tb = NULL;

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }

    tmp_right_name_7 = LOOKUP_ATTRIBUTE( tmp_source_name_3, const_str_plain_DOTALL );
    if ( tmp_right_name_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_args_element_name_1 );
        Py_DECREF( tmp_left_name_7 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    tmp_args_element_name_2 = BINARY_OPERATION( PyNumber_Or, tmp_left_name_7, tmp_right_name_7 );
    Py_DECREF( tmp_left_name_7 );
    Py_DECREF( tmp_right_name_7 );
    if ( tmp_args_element_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_1 );
        Py_DECREF( tmp_args_element_name_1 );

        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    frame_function->f_lineno = 43;
    {
        PyObject *call_args[] = { tmp_args_element_name_1, tmp_args_element_name_2 };
        tmp_assign_source_1 = CALL_FUNCTION_WITH_ARGS2( tmp_called_name_1, call_args );
    }

    Py_DECREF( tmp_called_name_1 );
    Py_DECREF( tmp_args_element_name_1 );
    Py_DECREF( tmp_args_element_name_2 );
    if ( tmp_assign_source_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 43;
        goto frame_exception_exit_1;
    }
    assert( var_rg == NULL );
    var_rg = tmp_assign_source_1;

    tmp_source_name_4 = var_rg;

    tmp_called_name_2 = LOOKUP_ATTRIBUTE( tmp_source_name_4, const_str_plain_findall );
    if ( tmp_called_name_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 44;
        goto frame_exception_exit_1;
    }
    tmp_args_element_name_3 = par_html;

    frame_function->f_lineno = 44;
    {
        PyObject *call_args[] = { tmp_args_element_name_3 };
        tmp_assign_source_2 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_2, call_args );
    }

    Py_DECREF( tmp_called_name_2 );
    if ( tmp_assign_source_2 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 44;
        goto frame_exception_exit_1;
    }
    assert( var_m == NULL );
    var_m = tmp_assign_source_2;

    tmp_assign_source_3 = PyList_New( 0 );
    assert( var_imgList == NULL );
    var_imgList = tmp_assign_source_3;

    tmp_iter_arg_1 = var_m;

    tmp_assign_source_4 = MAKE_ITERATOR( tmp_iter_arg_1 );
    if ( tmp_assign_source_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 48;
        goto frame_exception_exit_1;
    }
    assert( tmp_for_loop_1__for_iterator == NULL );
    tmp_for_loop_1__for_iterator = tmp_assign_source_4;

    // Tried code:
    loop_start_1:;
    tmp_next_source_1 = tmp_for_loop_1__for_iterator;

    tmp_assign_source_5 = ITERATOR_NEXT( tmp_next_source_1 );
    if ( tmp_assign_source_5 == NULL )
    {
        if ( CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED() )
        {

            goto loop_end_1;
        }
        else
        {

            FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
            frame_function->f_lineno = 48;
            goto try_except_handler_2;
        }
    }

    {
        PyObject *old = tmp_for_loop_1__iter_value;
        tmp_for_loop_1__iter_value = tmp_assign_source_5;
        Py_XDECREF( old );
    }

    tmp_assign_source_6 = tmp_for_loop_1__iter_value;

    {
        PyObject *old = var_imgurl;
        var_imgurl = tmp_assign_source_6;
        Py_INCREF( var_imgurl );
        Py_XDECREF( old );
    }

    tmp_assign_source_7 = const_str_empty;
    {
        PyObject *old = var_urltext;
        var_urltext = tmp_assign_source_7;
        Py_INCREF( var_urltext );
        Py_XDECREF( old );
    }

    tmp_iter_arg_2 = var_imgurl;

    tmp_assign_source_8 = MAKE_ITERATOR( tmp_iter_arg_2 );
    if ( tmp_assign_source_8 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 50;
        goto try_except_handler_2;
    }
    {
        PyObject *old = tmp_for_loop_2__for_iterator;
        tmp_for_loop_2__for_iterator = tmp_assign_source_8;
        Py_XDECREF( old );
    }

    // Tried code:
    loop_start_2:;
    tmp_next_source_2 = tmp_for_loop_2__for_iterator;

    tmp_assign_source_9 = ITERATOR_NEXT( tmp_next_source_2 );
    if ( tmp_assign_source_9 == NULL )
    {
        if ( CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED() )
        {

            goto loop_end_2;
        }
        else
        {

            FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
            frame_function->f_lineno = 50;
            goto try_except_handler_3;
        }
    }

    {
        PyObject *old = tmp_for_loop_2__iter_value;
        tmp_for_loop_2__iter_value = tmp_assign_source_9;
        Py_XDECREF( old );
    }

    tmp_assign_source_10 = tmp_for_loop_2__iter_value;

    {
        PyObject *old = var_tui;
        var_tui = tmp_assign_source_10;
        Py_INCREF( var_tui );
        Py_XDECREF( old );
    }

    tmp_left_name_8 = var_urltext;

    if ( tmp_left_name_8 == NULL )
    {

        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "local variable '%s' referenced before assignment", "urltext" );
        exception_tb = NULL;

        exception_lineno = 51;
        goto try_except_handler_3;
    }

    tmp_right_name_8 = var_tui;

    tmp_result = BINARY_OPERATION_ADD_INPLACE( &tmp_left_name_8, tmp_right_name_8 );
    tmp_assign_source_11 = tmp_left_name_8;
    if ( tmp_result == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 51;
        goto try_except_handler_3;
    }
    var_urltext = tmp_assign_source_11;

    if ( CONSIDER_THREADING() == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 50;
        goto try_except_handler_3;
    }
    goto loop_start_2;
    loop_end_2:;
    goto try_end_1;
    // Exception handler code:
    try_except_handler_3:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    Py_XDECREF( tmp_for_loop_2__iter_value );
    tmp_for_loop_2__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_2__for_iterator );
    Py_DECREF( tmp_for_loop_2__for_iterator );
    tmp_for_loop_2__for_iterator = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto try_except_handler_2;
    // End of try:
    try_end_1:;
    Py_XDECREF( tmp_for_loop_2__iter_value );
    tmp_for_loop_2__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_2__for_iterator );
    Py_DECREF( tmp_for_loop_2__for_iterator );
    tmp_for_loop_2__for_iterator = NULL;

    tmp_source_name_5 = var_imgList;

    tmp_called_name_3 = LOOKUP_ATTRIBUTE( tmp_source_name_5, const_str_plain_append );
    if ( tmp_called_name_3 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 52;
        goto try_except_handler_2;
    }
    tmp_args_element_name_4 = var_urltext;

    if ( tmp_args_element_name_4 == NULL )
    {
        Py_DECREF( tmp_called_name_3 );
        exception_type = PyExc_UnboundLocalError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "local variable '%s' referenced before assignment", "urltext" );
        exception_tb = NULL;

        exception_lineno = 52;
        goto try_except_handler_2;
    }

    frame_function->f_lineno = 52;
    {
        PyObject *call_args[] = { tmp_args_element_name_4 };
        tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_3, call_args );
    }

    Py_DECREF( tmp_called_name_3 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 52;
        goto try_except_handler_2;
    }
    Py_DECREF( tmp_unused );
    if ( CONSIDER_THREADING() == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 48;
        goto try_except_handler_2;
    }
    goto loop_start_1;
    loop_end_1:;
    goto try_end_2;
    // Exception handler code:
    try_except_handler_2:;
    exception_keeper_type_2 = exception_type;
    exception_keeper_value_2 = exception_value;
    exception_keeper_tb_2 = exception_tb;
    exception_keeper_lineno_2 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    Py_XDECREF( tmp_for_loop_1__iter_value );
    tmp_for_loop_1__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_1__for_iterator );
    Py_DECREF( tmp_for_loop_1__for_iterator );
    tmp_for_loop_1__for_iterator = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_2;
    exception_value = exception_keeper_value_2;
    exception_tb = exception_keeper_tb_2;
    exception_lineno = exception_keeper_lineno_2;

    goto frame_exception_exit_1;
    // End of try:
    try_end_2:;
    Py_XDECREF( tmp_for_loop_1__iter_value );
    tmp_for_loop_1__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_1__for_iterator );
    Py_DECREF( tmp_for_loop_1__for_iterator );
    tmp_for_loop_1__for_iterator = NULL;

    tmp_set_arg_1 = var_imgList;

    tmp_list_arg_1 = PySet_New( tmp_set_arg_1 );
    if ( tmp_list_arg_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 54;
        goto frame_exception_exit_1;
    }
    tmp_assign_source_12 = PySequence_List( tmp_list_arg_1 );
    Py_DECREF( tmp_list_arg_1 );
    if ( tmp_assign_source_12 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 54;
        goto frame_exception_exit_1;
    }
    {
        PyObject *old = var_imgList;
        assert( old != NULL );
        var_imgList = tmp_assign_source_12;
        Py_DECREF( old );
    }

    // Tried code:
    tmp_open_filename_1 = const_str_digest_26c3335a962f2325c06d4aed04ae2a29;
    tmp_open_mode_1 = const_str_plain_w;
    tmp_assign_source_13 = BUILTIN_OPEN( tmp_open_filename_1, tmp_open_mode_1, NULL );
    if ( tmp_assign_source_13 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 55;
        goto try_except_handler_4;
    }
    assert( tmp_with_1__source == NULL );
    tmp_with_1__source = tmp_assign_source_13;

    tmp_source_name_6 = tmp_with_1__source;

    tmp_assign_source_14 = LOOKUP_SPECIAL( tmp_source_name_6, const_str_plain___exit__ );
    if ( tmp_assign_source_14 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 55;
        goto try_except_handler_4;
    }
    assert( tmp_with_1__exit == NULL );
    tmp_with_1__exit = tmp_assign_source_14;

    tmp_source_name_7 = tmp_with_1__source;

    tmp_called_name_4 = LOOKUP_SPECIAL( tmp_source_name_7, const_str_plain___enter__ );
    if ( tmp_called_name_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 55;
        goto try_except_handler_4;
    }
    frame_function->f_lineno = 55;
    tmp_assign_source_15 = CALL_FUNCTION_NO_ARGS( tmp_called_name_4 );
    Py_DECREF( tmp_called_name_4 );
    if ( tmp_assign_source_15 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 55;
        goto try_except_handler_4;
    }
    assert( tmp_with_1__enter == NULL );
    tmp_with_1__enter = tmp_assign_source_15;

    tmp_assign_source_16 = Py_True;
    assert( tmp_with_1__indicator == NULL );
    Py_INCREF( tmp_assign_source_16 );
    tmp_with_1__indicator = tmp_assign_source_16;

    tmp_assign_source_17 = tmp_with_1__enter;

    assert( var_uf == NULL );
    Py_INCREF( tmp_assign_source_17 );
    var_uf = tmp_assign_source_17;

    // Tried code:
    // Tried code:
    tmp_iter_arg_3 = var_imgList;

    tmp_assign_source_18 = MAKE_ITERATOR( tmp_iter_arg_3 );
    if ( tmp_assign_source_18 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 56;
        goto try_except_handler_6;
    }
    assert( tmp_for_loop_3__for_iterator == NULL );
    tmp_for_loop_3__for_iterator = tmp_assign_source_18;

    // Tried code:
    loop_start_3:;
    tmp_next_source_3 = tmp_for_loop_3__for_iterator;

    tmp_assign_source_19 = ITERATOR_NEXT( tmp_next_source_3 );
    if ( tmp_assign_source_19 == NULL )
    {
        if ( CHECK_AND_CLEAR_STOP_ITERATION_OCCURRED() )
        {

            goto loop_end_3;
        }
        else
        {

            FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
            frame_function->f_lineno = 56;
            goto try_except_handler_7;
        }
    }

    {
        PyObject *old = tmp_for_loop_3__iter_value;
        tmp_for_loop_3__iter_value = tmp_assign_source_19;
        Py_XDECREF( old );
    }

    tmp_assign_source_20 = tmp_for_loop_3__iter_value;

    {
        PyObject *old = var_i;
        var_i = tmp_assign_source_20;
        Py_INCREF( var_i );
        Py_XDECREF( old );
    }

    tmp_source_name_8 = var_uf;

    tmp_called_name_5 = LOOKUP_ATTRIBUTE( tmp_source_name_8, const_str_plain_write );
    if ( tmp_called_name_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 57;
        goto try_except_handler_7;
    }
    tmp_str_arg_1 = var_i;

    tmp_args_element_name_5 = PyObject_Str( tmp_str_arg_1 );
    if ( tmp_args_element_name_5 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_called_name_5 );

        exception_lineno = 57;
        goto try_except_handler_7;
    }
    frame_function->f_lineno = 57;
    {
        PyObject *call_args[] = { tmp_args_element_name_5 };
        tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_5, call_args );
    }

    Py_DECREF( tmp_called_name_5 );
    Py_DECREF( tmp_args_element_name_5 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 57;
        goto try_except_handler_7;
    }
    Py_DECREF( tmp_unused );
    tmp_source_name_9 = var_uf;

    tmp_called_name_6 = LOOKUP_ATTRIBUTE( tmp_source_name_9, const_str_plain_write );
    if ( tmp_called_name_6 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 58;
        goto try_except_handler_7;
    }
    frame_function->f_lineno = 58;
    tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_6, &PyTuple_GET_ITEM( const_tuple_str_newline_tuple, 0 ) );

    Py_DECREF( tmp_called_name_6 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 58;
        goto try_except_handler_7;
    }
    Py_DECREF( tmp_unused );
    if ( CONSIDER_THREADING() == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 56;
        goto try_except_handler_7;
    }
    goto loop_start_3;
    loop_end_3:;
    goto try_end_3;
    // Exception handler code:
    try_except_handler_7:;
    exception_keeper_type_3 = exception_type;
    exception_keeper_value_3 = exception_value;
    exception_keeper_tb_3 = exception_tb;
    exception_keeper_lineno_3 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    Py_XDECREF( tmp_for_loop_3__iter_value );
    tmp_for_loop_3__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_3__for_iterator );
    Py_DECREF( tmp_for_loop_3__for_iterator );
    tmp_for_loop_3__for_iterator = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_3;
    exception_value = exception_keeper_value_3;
    exception_tb = exception_keeper_tb_3;
    exception_lineno = exception_keeper_lineno_3;

    goto try_except_handler_6;
    // End of try:
    try_end_3:;
    Py_XDECREF( tmp_for_loop_3__iter_value );
    tmp_for_loop_3__iter_value = NULL;

    CHECK_OBJECT( (PyObject *)tmp_for_loop_3__for_iterator );
    Py_DECREF( tmp_for_loop_3__for_iterator );
    tmp_for_loop_3__for_iterator = NULL;

    goto try_end_4;
    // Exception handler code:
    try_except_handler_6:;
    exception_keeper_type_4 = exception_type;
    exception_keeper_value_4 = exception_value;
    exception_keeper_tb_4 = exception_tb;
    exception_keeper_lineno_4 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    // Preserve existing published exception.
    PRESERVE_FRAME_EXCEPTION( frame_function );
    if ( exception_keeper_tb_4 == NULL )
    {
        exception_keeper_tb_4 = MAKE_TRACEBACK( frame_function, exception_keeper_lineno_4 );
    }
    else if ( exception_keeper_lineno_4 != -1 )
    {
        exception_keeper_tb_4 = ADD_TRACEBACK( exception_keeper_tb_4, frame_function, exception_keeper_lineno_4 );
    }

    NORMALIZE_EXCEPTION( &exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4 );
    PUBLISH_EXCEPTION( &exception_keeper_type_4, &exception_keeper_value_4, &exception_keeper_tb_4 );
    tmp_compare_left_1 = PyThreadState_GET()->exc_type;
    tmp_compare_right_1 = PyExc_BaseException;
    tmp_exc_match_exception_match_1 = EXCEPTION_MATCH_BOOL( tmp_compare_left_1, tmp_compare_right_1 );
    if ( tmp_exc_match_exception_match_1 == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 55;
        goto try_except_handler_5;
    }
    if ( tmp_exc_match_exception_match_1 == 1 )
    {
        goto branch_yes_1;
    }
    else
    {
        goto branch_no_1;
    }
    branch_yes_1:;
    tmp_assign_source_21 = Py_False;
    {
        PyObject *old = tmp_with_1__indicator;
        assert( old != NULL );
        tmp_with_1__indicator = tmp_assign_source_21;
        Py_INCREF( tmp_with_1__indicator );
        Py_DECREF( old );
    }

    tmp_called_name_7 = tmp_with_1__exit;

    tmp_args_element_name_6 = PyThreadState_GET()->exc_type;
    tmp_args_element_name_7 = PyThreadState_GET()->exc_value;
    tmp_args_element_name_8 = PyThreadState_GET()->exc_traceback;
    frame_function->f_lineno = 56;
    {
        PyObject *call_args[] = { tmp_args_element_name_6, tmp_args_element_name_7, tmp_args_element_name_8 };
        tmp_cond_value_1 = CALL_FUNCTION_WITH_ARGS3( tmp_called_name_7, call_args );
    }

    if ( tmp_cond_value_1 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 56;
        goto try_except_handler_5;
    }
    tmp_cond_truth_1 = CHECK_IF_TRUE( tmp_cond_value_1 );
    if ( tmp_cond_truth_1 == -1 )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );
        Py_DECREF( tmp_cond_value_1 );

        exception_lineno = 56;
        goto try_except_handler_5;
    }
    Py_DECREF( tmp_cond_value_1 );
    if ( tmp_cond_truth_1 == 1 )
    {
        goto branch_no_2;
    }
    else
    {
        goto branch_yes_2;
    }
    branch_yes_2:;
    RERAISE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
    if (exception_tb && exception_tb->tb_frame == frame_function) frame_function->f_lineno = exception_tb->tb_lineno;
    goto try_except_handler_5;
    branch_no_2:;
    goto branch_end_1;
    branch_no_1:;
    RERAISE_EXCEPTION( &exception_type, &exception_value, &exception_tb );
    if (exception_tb && exception_tb->tb_frame == frame_function) frame_function->f_lineno = exception_tb->tb_lineno;
    goto try_except_handler_5;
    branch_end_1:;
    goto try_end_4;
    // exception handler codes exits in all cases
    NUITKA_CANNOT_GET_HERE( function_2_getImg_of___main__ );
    return NULL;
    // End of try:
    try_end_4:;
    goto try_end_5;
    // Exception handler code:
    try_except_handler_5:;
    exception_keeper_type_5 = exception_type;
    exception_keeper_value_5 = exception_value;
    exception_keeper_tb_5 = exception_tb;
    exception_keeper_lineno_5 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    tmp_compare_left_2 = tmp_with_1__indicator;

    tmp_compare_right_2 = Py_True;
    tmp_is_1 = ( tmp_compare_left_2 == tmp_compare_right_2 );
    if ( tmp_is_1 )
    {
        goto branch_yes_3;
    }
    else
    {
        goto branch_no_3;
    }
    branch_yes_3:;
    tmp_called_name_8 = tmp_with_1__exit;

    frame_function->f_lineno = 56;
    tmp_unused = CALL_FUNCTION_WITH_ARGS3( tmp_called_name_8, &PyTuple_GET_ITEM( const_tuple_none_none_none_tuple, 0 ) );

    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );

        Py_DECREF( exception_keeper_type_5 );
        Py_XDECREF( exception_keeper_value_5 );
        Py_XDECREF( exception_keeper_tb_5 );

        exception_lineno = 56;
        goto try_except_handler_4;
    }
    Py_DECREF( tmp_unused );
    branch_no_3:;
    // Re-raise.
    exception_type = exception_keeper_type_5;
    exception_value = exception_keeper_value_5;
    exception_tb = exception_keeper_tb_5;
    exception_lineno = exception_keeper_lineno_5;

    goto try_except_handler_4;
    // End of try:
    try_end_5:;
    tmp_compare_left_3 = tmp_with_1__indicator;

    tmp_compare_right_3 = Py_True;
    tmp_is_2 = ( tmp_compare_left_3 == tmp_compare_right_3 );
    if ( tmp_is_2 )
    {
        goto branch_yes_4;
    }
    else
    {
        goto branch_no_4;
    }
    branch_yes_4:;
    tmp_called_name_9 = tmp_with_1__exit;

    frame_function->f_lineno = 56;
    tmp_unused = CALL_FUNCTION_WITH_ARGS3( tmp_called_name_9, &PyTuple_GET_ITEM( const_tuple_none_none_none_tuple, 0 ) );

    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 56;
        goto try_except_handler_4;
    }
    Py_DECREF( tmp_unused );
    branch_no_4:;
    goto try_end_6;
    // Exception handler code:
    try_except_handler_4:;
    exception_keeper_type_6 = exception_type;
    exception_keeper_value_6 = exception_value;
    exception_keeper_tb_6 = exception_tb;
    exception_keeper_lineno_6 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    Py_XDECREF( tmp_with_1__source );
    tmp_with_1__source = NULL;

    Py_XDECREF( tmp_with_1__enter );
    tmp_with_1__enter = NULL;

    Py_XDECREF( tmp_with_1__exit );
    tmp_with_1__exit = NULL;

    Py_XDECREF( tmp_with_1__indicator );
    tmp_with_1__indicator = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_6;
    exception_value = exception_keeper_value_6;
    exception_tb = exception_keeper_tb_6;
    exception_lineno = exception_keeper_lineno_6;

    goto frame_exception_exit_1;
    // End of try:
    try_end_6:;

#if 1
    RESTORE_FRAME_EXCEPTION( frame_function );
#endif
    // Put the previous frame back on top.
    popFrameStack();
#if PYTHON_VERSION >= 340
    frame_function->f_executing -= 1;
#endif
    Py_DECREF( frame_function );
    goto frame_no_exception_1;

    frame_exception_exit_1:;
#if 1
    RESTORE_FRAME_EXCEPTION( frame_function );
#endif

    {
        bool needs_detach = false;

        if ( exception_tb == NULL )
        {
            exception_tb = MAKE_TRACEBACK( frame_function, exception_lineno );
            needs_detach = true;
        }
        else if ( exception_lineno != -1 )
        {
            PyTracebackObject *traceback_new = MAKE_TRACEBACK( frame_function, exception_lineno );
            traceback_new->tb_next = exception_tb;
            exception_tb = traceback_new;

            needs_detach = true;
        }

        if (needs_detach)
        {

            tmp_frame_locals = PyDict_New();
            if ( par_html )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_html,
                    par_html
                );

                assert( res == 0 );
            }

            if ( var_rg )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_rg,
                    var_rg
                );

                assert( res == 0 );
            }

            if ( var_m )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_m,
                    var_m
                );

                assert( res == 0 );
            }

            if ( var_imgList )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_imgList,
                    var_imgList
                );

                assert( res == 0 );
            }

            if ( var_imgurl )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_imgurl,
                    var_imgurl
                );

                assert( res == 0 );
            }

            if ( var_urltext )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_urltext,
                    var_urltext
                );

                assert( res == 0 );
            }

            if ( var_tui )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_tui,
                    var_tui
                );

                assert( res == 0 );
            }

            if ( var_uf )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_uf,
                    var_uf
                );

                assert( res == 0 );
            }

            if ( var_i )
            {
                int res = PyDict_SetItem(
                    tmp_frame_locals,
                    const_str_plain_i,
                    var_i
                );

                assert( res == 0 );
            }



            detachFrame( exception_tb, tmp_frame_locals );
        }
    }

    popFrameStack();

#if PYTHON_VERSION >= 340
    frame_function->f_executing -= 1;
#endif
    Py_DECREF( frame_function );

    // Return the error.
    goto try_except_handler_1;

    frame_no_exception_1:;

    CHECK_OBJECT( (PyObject *)tmp_with_1__source );
    Py_DECREF( tmp_with_1__source );
    tmp_with_1__source = NULL;

    CHECK_OBJECT( (PyObject *)tmp_with_1__enter );
    Py_DECREF( tmp_with_1__enter );
    tmp_with_1__enter = NULL;

    CHECK_OBJECT( (PyObject *)tmp_with_1__exit );
    Py_DECREF( tmp_with_1__exit );
    tmp_with_1__exit = NULL;

    Py_XDECREF( tmp_with_1__indicator );
    tmp_with_1__indicator = NULL;

    tmp_return_value = Py_None;
    Py_INCREF( tmp_return_value );
    goto try_return_handler_1;
    // tried codes exits in all cases
    NUITKA_CANNOT_GET_HERE( function_2_getImg_of___main__ );
    return NULL;
    // Return handler code:
    try_return_handler_1:;
    CHECK_OBJECT( (PyObject *)par_html );
    Py_DECREF( par_html );
    par_html = NULL;

    CHECK_OBJECT( (PyObject *)var_rg );
    Py_DECREF( var_rg );
    var_rg = NULL;

    CHECK_OBJECT( (PyObject *)var_m );
    Py_DECREF( var_m );
    var_m = NULL;

    CHECK_OBJECT( (PyObject *)var_imgList );
    Py_DECREF( var_imgList );
    var_imgList = NULL;

    Py_XDECREF( var_imgurl );
    var_imgurl = NULL;

    Py_XDECREF( var_urltext );
    var_urltext = NULL;

    Py_XDECREF( var_tui );
    var_tui = NULL;

    CHECK_OBJECT( (PyObject *)var_uf );
    Py_DECREF( var_uf );
    var_uf = NULL;

    Py_XDECREF( var_i );
    var_i = NULL;

    goto function_return_exit;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_7 = exception_type;
    exception_keeper_value_7 = exception_value;
    exception_keeper_tb_7 = exception_tb;
    exception_keeper_lineno_7 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = -1;

    CHECK_OBJECT( (PyObject *)par_html );
    Py_DECREF( par_html );
    par_html = NULL;

    Py_XDECREF( var_rg );
    var_rg = NULL;

    Py_XDECREF( var_m );
    var_m = NULL;

    Py_XDECREF( var_imgList );
    var_imgList = NULL;

    Py_XDECREF( var_imgurl );
    var_imgurl = NULL;

    Py_XDECREF( var_urltext );
    var_urltext = NULL;

    Py_XDECREF( var_tui );
    var_tui = NULL;

    Py_XDECREF( var_uf );
    var_uf = NULL;

    Py_XDECREF( var_i );
    var_i = NULL;

    // Re-raise.
    exception_type = exception_keeper_type_7;
    exception_value = exception_keeper_value_7;
    exception_tb = exception_keeper_tb_7;
    exception_lineno = exception_keeper_lineno_7;

    goto function_exception_exit;
    // End of try:

    // Return statement must have exited already.
    NUITKA_CANNOT_GET_HERE( function_2_getImg_of___main__ );
    return NULL;

function_exception_exit:
    assert( exception_type );
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );

    return NULL;
    function_return_exit:

    CHECK_OBJECT( tmp_return_value );
    assert( had_error || !ERROR_OCCURRED() );
    return tmp_return_value;

}



static PyObject *MAKE_FUNCTION_function_1_getHtml_of___main__(  )
{
    PyObject *result = Nuitka_Function_New(
        impl_function_1_getHtml_of___main__,
        const_str_plain_getHtml,
#if PYTHON_VERSION >= 330
        NULL,
#endif
        codeobj_d0e9aa0757b9c191be3a6a186bd40f41,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        const_dict_empty,
#endif
        module___main__,
        Py_None
    );

    return result;
}



static PyObject *MAKE_FUNCTION_function_2_getImg_of___main__(  )
{
    PyObject *result = Nuitka_Function_New(
        impl_function_2_getImg_of___main__,
        const_str_plain_getImg,
#if PYTHON_VERSION >= 330
        NULL,
#endif
        codeobj_a307895767dc11223c851da7b6909d12,
        NULL,
#if PYTHON_VERSION >= 300
        NULL,
        const_dict_empty,
#endif
        module___main__,
        Py_None
    );

    return result;
}



#if PYTHON_VERSION >= 300
static struct PyModuleDef mdef___main__ =
{
    PyModuleDef_HEAD_INIT,
    "__main__",   /* m_name */
    NULL,                /* m_doc */
    -1,                  /* m_size */
    NULL,                /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#endif

#if PYTHON_VERSION >= 300
extern PyObject *metapath_based_loader;
#endif

// The exported interface to CPython. On import of the module, this function
// gets called. It has to have an exact function name, in cases it's a shared
// library export. This is hidden behind the MOD_INIT_DECL.

MOD_INIT_DECL( __main__ )
{
#if defined(_NUITKA_EXE) || PYTHON_VERSION >= 300
    static bool _init_done = false;

    // Modules might be imported repeatedly, which is to be ignored.
    if ( _init_done )
    {
        return MOD_RETURN_VALUE( module___main__ );
    }
    else
    {
        _init_done = true;
    }
#endif

#ifdef _NUITKA_MODULE
    // In case of a stand alone extension module, need to call initialization
    // the init here because that's the first and only time we are going to get
    // called here.

    // Initialize the constant values used.
    _initBuiltinModule();
    createGlobalConstants();

    // Initialize the compiled types of Nuitka.
    PyType_Ready( &Nuitka_Generator_Type );
    PyType_Ready( &Nuitka_Function_Type );
    PyType_Ready( &Nuitka_Method_Type );
    PyType_Ready( &Nuitka_Frame_Type );
#if PYTHON_VERSION >= 350
    PyType_Ready( &Nuitka_Coroutine_Type );
    PyType_Ready( &Nuitka_CoroutineWrapper_Type );
#endif

#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

    patchBuiltinModule();
    patchTypeComparison();

    // Enable meta path based loader if not already done.
    setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 300
    patchInspectModule();
#endif

#endif

    createModuleConstants();
    createModuleCodeObjects();

    // puts( "in init__main__" );

    // Create the module object first. There are no methods initially, all are
    // added dynamically in actual code only.  Also no "__doc__" is initially
    // set at this time, as it could not contain NUL characters this way, they
    // are instead set in early module code.  No "self" for modules, we have no
    // use for it.
#if PYTHON_VERSION < 300
    module___main__ = Py_InitModule4(
        "__main__",       // Module Name
        NULL,                    // No methods initially, all are added
                                 // dynamically in actual module code only.
        NULL,                    // No __doc__ is initially set, as it could
                                 // not contain NUL this way, added early in
                                 // actual code.
        NULL,                    // No self for modules, we don't use it.
        PYTHON_API_VERSION
    );
#else
    module___main__ = PyModule_Create( &mdef___main__ );
#endif

    moduledict___main__ = (PyDictObject *)((PyModuleObject *)module___main__)->md_dict;

    CHECK_OBJECT( module___main__ );

// Seems to work for Python2.7 out of the box, but for Python3, the module
// doesn't automatically enter "sys.modules", so do it manually.
#if PYTHON_VERSION >= 300
    {
        int r = PyObject_SetItem( PySys_GetObject( (char *)"modules" ), const_str_plain___main__, module___main__ );

        assert( r != -1 );
    }
#endif

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    PyObject *module_dict = PyModule_GetDict( module___main__ );

    if ( PyDict_GetItem( module_dict, const_str_plain___builtins__ ) == NULL )
    {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then.
#if !defined(_NUITKA_EXE) || !1
        value = PyModule_GetDict( value );
#endif

#ifndef __NUITKA_NO_ASSERT__
        int res =
#endif
            PyDict_SetItem( module_dict, const_str_plain___builtins__, value );

        assert( res == 0 );
    }

#if PYTHON_VERSION >= 330
    PyDict_SetItem( module_dict, const_str_plain___loader__, metapath_based_loader );
#endif

    // Temp variables if any
    PyObject *exception_type = NULL, *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = -1;
    PyObject *tmp_args_element_name_1;
    PyObject *tmp_args_element_name_2;
    PyObject *tmp_assign_source_1;
    PyObject *tmp_assign_source_2;
    PyObject *tmp_assign_source_3;
    PyObject *tmp_assign_source_4;
    PyObject *tmp_assign_source_5;
    PyObject *tmp_assign_source_6;
    PyObject *tmp_assign_source_7;
    PyObject *tmp_assign_source_8;
    PyObject *tmp_called_name_1;
    PyObject *tmp_called_name_2;
    PyObject *tmp_called_name_3;
    PyObject *tmp_import_globals_1;
    PyObject *tmp_import_globals_2;
    PyObject *tmp_import_globals_3;
    PyObject *tmp_import_globals_4;
    PyObject *tmp_print_value;
    NUITKA_MAY_BE_UNUSED PyObject *tmp_unused;
    PyFrameObject *frame_module;


    // Module code.
    // Frame without reuse.
    frame_module = MAKE_MODULE_FRAME( codeobj_ff3939801846d5aef72184cc01c9702d, module___main__ );

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStack( frame_module );
    assert( Py_REFCNT( frame_module ) == 1 );

#if PYTHON_VERSION >= 340
    frame_module->f_executing += 1;
#endif

    // Framed code:
    tmp_import_globals_1 = ((PyModuleObject *)module___main__)->md_dict;
    frame_module->f_lineno = 1;
    tmp_unused = IMPORT_MODULE( const_str_plain_sys, tmp_import_globals_1, tmp_import_globals_1, const_tuple_empty, const_int_neg_1 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;
        goto frame_exception_exit_1;
    }
    Py_DECREF( tmp_unused );
    tmp_import_globals_2 = ((PyModuleObject *)module___main__)->md_dict;
    frame_module->f_lineno = 1;
    tmp_unused = IMPORT_MODULE( const_str_plain_site, tmp_import_globals_2, tmp_import_globals_2, const_tuple_empty, const_int_neg_1 );
    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 1;
        goto frame_exception_exit_1;
    }
    Py_DECREF( tmp_unused );
    tmp_assign_source_1 = Py_None;
    UPDATE_STRING_DICT0( moduledict___main__, (Nuitka_StringObject *)const_str_plain___doc__, tmp_assign_source_1 );
    tmp_assign_source_2 = module_filename_obj;
    UPDATE_STRING_DICT0( moduledict___main__, (Nuitka_StringObject *)const_str_plain___file__, tmp_assign_source_2 );
    tmp_import_globals_3 = ((PyModuleObject *)module___main__)->md_dict;
    frame_module->f_lineno = 2;
    tmp_assign_source_3 = IMPORT_MODULE( const_str_plain_re, tmp_import_globals_3, tmp_import_globals_3, Py_None, const_int_neg_1 );
    if ( tmp_assign_source_3 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 2;
        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_re, tmp_assign_source_3 );
    tmp_import_globals_4 = ((PyModuleObject *)module___main__)->md_dict;
    frame_module->f_lineno = 3;
    tmp_assign_source_4 = IMPORT_MODULE( const_str_plain_urllib, tmp_import_globals_4, tmp_import_globals_4, Py_None, const_int_neg_1 );
    if ( tmp_assign_source_4 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 3;
        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_urllib, tmp_assign_source_4 );
    tmp_assign_source_5 = MAKE_FUNCTION_function_1_getHtml_of___main__(  );
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_getHtml, tmp_assign_source_5 );
    tmp_assign_source_6 = MAKE_FUNCTION_function_2_getImg_of___main__(  );
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_getImg, tmp_assign_source_6 );
    tmp_print_value = const_unicode_digest_24069915adcf5647c79e35c204e91800;
    if ( PRINT_ITEM( tmp_print_value ) == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 61;
        goto frame_exception_exit_1;
    }
    if ( PRINT_NEW_LINE() == false )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 61;
        goto frame_exception_exit_1;
    }
    tmp_called_name_1 = LOOKUP_BUILTIN( const_str_plain_raw_input );
    assert( tmp_called_name_1 != NULL );
    frame_module->f_lineno = 62;
    tmp_assign_source_7 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_1, &PyTuple_GET_ITEM( const_tuple_str_digest_c59e90e4116bd3913a98e5005e589c71_tuple, 0 ) );

    if ( tmp_assign_source_7 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 62;
        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_url, tmp_assign_source_7 );
    tmp_called_name_2 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_getHtml );

    if (unlikely( tmp_called_name_2 == NULL ))
    {
        tmp_called_name_2 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_getHtml );
    }

    if ( tmp_called_name_2 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "name '%s' is not defined", "getHtml" );
        exception_tb = NULL;

        exception_lineno = 63;
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_1 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_url );

    if (unlikely( tmp_args_element_name_1 == NULL ))
    {
        tmp_args_element_name_1 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_url );
    }

    if ( tmp_args_element_name_1 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "name '%s' is not defined", "url" );
        exception_tb = NULL;

        exception_lineno = 63;
        goto frame_exception_exit_1;
    }

    frame_module->f_lineno = 63;
    {
        PyObject *call_args[] = { tmp_args_element_name_1 };
        tmp_assign_source_8 = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_2, call_args );
    }

    if ( tmp_assign_source_8 == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 63;
        goto frame_exception_exit_1;
    }
    UPDATE_STRING_DICT1( moduledict___main__, (Nuitka_StringObject *)const_str_plain_html, tmp_assign_source_8 );
    tmp_called_name_3 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_getImg );

    if (unlikely( tmp_called_name_3 == NULL ))
    {
        tmp_called_name_3 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_getImg );
    }

    if ( tmp_called_name_3 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "name '%s' is not defined", "getImg" );
        exception_tb = NULL;

        exception_lineno = 64;
        goto frame_exception_exit_1;
    }

    tmp_args_element_name_2 = GET_STRING_DICT_VALUE( moduledict___main__, (Nuitka_StringObject *)const_str_plain_html );

    if (unlikely( tmp_args_element_name_2 == NULL ))
    {
        tmp_args_element_name_2 = GET_STRING_DICT_VALUE( dict_builtin, (Nuitka_StringObject *)const_str_plain_html );
    }

    if ( tmp_args_element_name_2 == NULL )
    {

        exception_type = PyExc_NameError;
        Py_INCREF( exception_type );
        exception_value = PyString_FromFormat( "name '%s' is not defined", "html" );
        exception_tb = NULL;

        exception_lineno = 64;
        goto frame_exception_exit_1;
    }

    frame_module->f_lineno = 64;
    {
        PyObject *call_args[] = { tmp_args_element_name_2 };
        tmp_unused = CALL_FUNCTION_WITH_ARGS1( tmp_called_name_3, call_args );
    }

    if ( tmp_unused == NULL )
    {
        assert( ERROR_OCCURRED() );

        FETCH_ERROR_OCCURRED( &exception_type, &exception_value, &exception_tb );


        exception_lineno = 64;
        goto frame_exception_exit_1;
    }
    Py_DECREF( tmp_unused );

    // Restore frame exception if necessary.
#if 0
    RESTORE_FRAME_EXCEPTION( frame_module );
#endif
    popFrameStack();

    assertFrameObject( frame_module );
    Py_DECREF( frame_module );

    goto frame_no_exception_1;
    frame_exception_exit_1:;
#if 0
    RESTORE_FRAME_EXCEPTION( frame_module );
#endif

    if ( exception_tb == NULL )
    {
        exception_tb = MAKE_TRACEBACK( frame_module, exception_lineno );
    }
    else if ( exception_tb->tb_frame != frame_module )
    {
        PyTracebackObject *traceback_new = MAKE_TRACEBACK( frame_module, exception_lineno );
        traceback_new->tb_next = exception_tb;
        exception_tb = traceback_new;
    }

    // Put the previous frame back on top.
    popFrameStack();

#if PYTHON_VERSION >= 340
    frame_module->f_executing -= 1;
#endif
    Py_DECREF( frame_module );

    // Return the error.
    goto module_exception_exit;
    frame_no_exception_1:;

    return MOD_RETURN_VALUE( module___main__ );
    module_exception_exit:
    RESTORE_ERROR_OCCURRED( exception_type, exception_value, exception_tb );
    return MOD_RETURN_VALUE( NULL );
}
// The main program for C++. It needs to prepare the interpreter and then
// calls the initialization code of the "__main__" module.

#include "structseq.h"
#include "osdefs.h"

#if 0
extern PyObject *const_str_plain_ignore;
#endif

#ifdef _NUITKA_WINMAIN_ENTRY_POINT
int __stdcall WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpCmdLine, int nCmdShow )
{
#if defined(__MINGW32__) && !defined(_W64)
    /* MINGW32 */
    int argc = _argc;
    char** argv = _argv;
#else
    /* MSVC, MINGW64 */
    int argc = __argc;
    char** argv = __argv;
#endif
#else
int main( int argc, char **argv )
{
#endif
#ifdef _NUITKA_TRACE
    puts("main(): Entered.");
#endif

#ifdef __FreeBSD__
    // 754 requires that FP exceptions run in "no stop" mode by default, and
    // until C vendors implement C99's ways to control FP exceptions, Python
    // requires non-stop mode.  Alas, some platforms enable FP exceptions by
    // default.  Here we disable them.

    fp_except_t m;

    m = fpgetmask();
    fpsetmask( m & ~FP_X_OFL );
#endif

#ifdef _NUITKA_STANDALONE
#ifdef _NUITKA_TRACE
    puts("main(): Prepare standalone environment.");
#endif
    prepareStandaloneEnvironment();
#else
    /* For Python installations that need the PYTHONHOME set. */
#if defined(PYTHON_HOME_PATH)
    puts("main(): Prepare run environment.");
    {
        char buffer[MAXPATHLEN+10];

        strcpy(buffer, "PYTHONHOME=");
        strcat(buffer, PYTHON_HOME_PATH);

        int res = putenv(buffer);
        assert( res == 0 );
    }
#endif
#endif

    // Initialize CPython library environment.
    Py_DebugFlag = 0;
#if 0
    Py_Py3kWarningFlag = 0;
#endif
#if 0
    Py_DivisionWarningFlag =
#if 0
        Py_Py3kWarningFlag ||
#endif
        0;
#endif
    Py_InspectFlag = 0;
    Py_InteractiveFlag = 0;
    Py_OptimizeFlag = 0;
    Py_DontWriteBytecodeFlag = 0;
    Py_NoUserSiteDirectory = 0;
    Py_IgnoreEnvironmentFlag = 0;
#if 0
    Py_TabcheckFlag = 0;
#endif
    Py_VerboseFlag = 0;
#if 0
    Py_UnicodeFlag = 0;
#endif
    Py_BytesWarningFlag = 0;
#if 1
    Py_HashRandomizationFlag = 1;
#endif

    // We want to import the site module, but only after we finished our own
    // setup. The site module import will be the first thing, the main module
    // does.
    Py_NoSiteFlag = 1;

    // Initial command line handling only.

#ifdef _NUITKA_TRACE
    puts("main(): Calling convert/setCommandLineParameters.");
#endif

#if PYTHON_VERSION >= 300
    wchar_t **argv_unicode = convertCommandLineParameters( argc, argv );
#endif

#if PYTHON_VERSION < 300
    bool is_multiprocess_forking = setCommandLineParameters( argc, argv, true );
#else
    bool is_multiprocess_forking = setCommandLineParameters( argc, argv_unicode, true );
#endif

    // Initialize the embedded CPython interpreter.
#ifdef _NUITKA_TRACE
    puts("main(): Calling Py_Initialize.");
#endif
    Py_Initialize();
#ifdef _NUITKA_TRACE
    puts("main(): Returned from Py_Initialize.");
#endif

    // Lie about it, believe it or not, there are "site" files, that check
    // against later imports, see below.
    Py_NoSiteFlag = 0;

    // Set the command line parameters for run time usage.
#ifdef _NUITKA_TRACE
    puts("main(): Calling setCommandLineParameters.");
#endif

#if PYTHON_VERSION < 300
    setCommandLineParameters( argc, argv, false );
#else
    setCommandLineParameters( argc, argv_unicode, false );
#endif

#ifdef _NUITKA_STANDALONE
#ifdef _NUITKA_TRACE
    puts("main(): Restore standalone environment.");
#endif
    restoreStandaloneEnvironment();
#endif

    // Initialize the built-in module tricks used.
#ifdef _NUITKA_TRACE
    puts("main(): Calling _initBuiltinModule().");
#endif
    _initBuiltinModule();
#ifdef _NUITKA_TRACE
    puts("main(): Returned from _initBuiltinModule.");
#endif

    // Initialize the constant values used.
#ifdef _NUITKA_TRACE
    puts("main(): Calling createGlobalConstants().");
#endif
    createGlobalConstants();
#ifdef _NUITKA_TRACE
    puts("main(): Calling _initBuiltinOriginalValues().");
#endif
    _initBuiltinOriginalValues();

    // Revert the wrong "sys.flags" value, it's used by "site" on at least
    // Debian for Python 3.3, more uses may exist.
#if 0 == 0
#if PYTHON_VERSION >= 330
    PyStructSequence_SetItem( PySys_GetObject( "flags" ), 6, const_int_0 );
#elif PYTHON_VERSION >= 320
    PyStructSequence_SetItem( PySys_GetObject( "flags" ), 7, const_int_0 );
#elif PYTHON_VERSION >= 260
    PyStructSequence_SET_ITEM( PySys_GetObject( (char *)"flags" ), 9, const_int_0 );
#endif
#endif

    // Initialize the compiled types of Nuitka.
    PyType_Ready( &Nuitka_Generator_Type );
    PyType_Ready( &Nuitka_Function_Type );
    PyType_Ready( &Nuitka_Method_Type );
    PyType_Ready( &Nuitka_Frame_Type );
#if PYTHON_VERSION >= 350
    PyType_Ready( &Nuitka_Coroutine_Type );
    PyType_Ready( &Nuitka_CoroutineWrapper_Type );
#endif


#if PYTHON_VERSION < 300
    _initSlotCompare();
#endif
#if PYTHON_VERSION >= 270
    _initSlotIternext();
#endif

#ifdef _NUITKA_TRACE
    puts("main(): Calling enhancePythonTypes().");
#endif
    enhancePythonTypes();

    // Set the sys.executable path to the original Python executable on Linux
    // or to python.exe on Windows.
    PySys_SetObject(
        (char *)"executable",
        UNSTREAM_STRING( &constant_bin[ 772 ], 22, 0 )
    );

#ifdef _NUITKA_TRACE
    puts("main(): Calling patchBuiltinModule().");
#endif
    patchBuiltinModule();
#ifdef _NUITKA_TRACE
    puts("main(): Calling patchTypeComparison().");
#endif
    patchTypeComparison();

    // Allow to override the ticker value, to remove checks for threads in
    // CPython core from impact on benchmarks.
    char const *ticker_value = getenv( "NUITKA_TICKER" );
    if ( ticker_value != NULL )
    {
        _Py_Ticker = atoi( ticker_value );
        assert ( _Py_Ticker >= 20 );
    }

#ifdef _NUITKA_STANDALONE
#ifdef _NUITKA_TRACE
    puts("main(): Calling setEarlyFrozenModulesFileAttribute().");
#endif
#if PYTHON_VERSION >= 300
    PyObject *os_module = PyImport_ImportModule("os");
    CHECK_OBJECT( os_module );
#endif
    setEarlyFrozenModulesFileAttribute();
#endif

#ifdef _NUITKA_TRACE
    puts("main(): Calling setupMetaPathBasedLoader().");
#endif
    /* Enable meta path based loader. */
    setupMetaPathBasedLoader();


    // Disable Python warnings if requested to.
#if 0
    // Should be same as:
    //   warnings.simplefilter("ignore", UserWarning)
    //   warnings.simplefilter("ignore", DeprecationWarning)
    // There is no C-API to control warnings. We don't care if it actually
    // works, i.e. return code of "simplefilter" function is not checked.
    {
        PyObject *warnings = PyImport_ImportModule( "warnings" );
        if ( warnings != NULL )
        {
            PyObject *simplefilter = PyObject_GetAttrString( warnings, "simplefilter" );

            if ( simplefilter != NULL )
            {
                PyObject *result1 = PyObject_CallFunctionObjArgs( simplefilter, const_str_plain_ignore, PyExc_UserWarning, NULL );
                assert( result1 );
                Py_XDECREF( result1 );
                PyObject *result2 = PyObject_CallFunctionObjArgs( simplefilter, const_str_plain_ignore, PyExc_DeprecationWarning, NULL );
                assert( result2 );
                Py_XDECREF( result2 );
            }
        }
    }
#endif

#if PYTHON_VERSION >= 300
#ifdef _NUITKA_TRACE
    puts("main(): Calling patchInspectModule().");
#endif
    patchInspectModule();
#endif

#if _NUITKA_PROFILE
    startProfiling();
#endif

    // Execute the main module. In case of multiprocessing making a fork on
    // Windows, we should execute something else instead.
#if _NUITKA_MODULE_COUNT > 1
    if (unlikely( is_multiprocess_forking ))
    {
#ifdef _NUITKA_TRACE
        puts("main(): Calling __parents_main__.");
#endif
        PyObject *result = IMPORT_COMPILED_MODULE(
            PyUnicode_FromString("__parents_main__"),
            "__parents_main__"
        );

        if ( result == NULL )
        {
            PyErr_PrintEx( 0 );
            Py_Exit( 1 );
        }
    }
    else
#endif
    {
        assert( !is_multiprocess_forking );

#ifdef _NUITKA_TRACE
        puts("main(): Calling __main__.");
#endif
        // Execute the "__main__" module init function.
        MOD_INIT_NAME( __main__ )();
    }

#if _NUITKA_PROFILE
    stopProfiling();
#endif

#ifndef __NUITKA_NO_ASSERT__
    checkGlobalConstants();
    checkModuleConstants___main__();
#endif

    if ( ERROR_OCCURRED() )
    {
        // Cleanup code may need a frame, so put one back.
        PyThreadState_GET()->frame = MAKE_MODULE_FRAME( codeobj_ff3939801846d5aef72184cc01c9702d, module___main__ );

        PyErr_PrintEx( 0 );
        Py_Exit( 1 );
    }
    else
    {
        Py_Exit( 0 );
    }

    // The above branches both do "Py_Exit()" calls which are not supposed to
    // return.
    NUITKA_CANNOT_GET_HERE( main );
}
