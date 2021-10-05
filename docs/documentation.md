---
title: Code Transformations for APR 
author: P. Reiter, A. Espinoza 
date: BSS Lab ASU
---

# Synopsis

`code_expand.py [-h] -n FILE_NAME [-f OUT_FILE] [-p PRE_PROCESS]`

- `-n` is necessary.
- `-f` is optional which defaults to `new_code_expand.c`
- `-p` is optional.


# Overview

This program performs a series of transformations that increase the granularity
of statements in a program such that APR tools have access to more mutations in
C code.  Transformations focus on extracting function arguments out such that
APR tools can manipulate them.  

Conditional statements (`if`) that contain functions are transformed such that the
function argument is extracted from the conditional check.

While loops with functions in their conditional check are ignored.

# Pre-process file
This is an ***optional*** json file that contains:

1. `filenames`: with function definitions the FILE_NAME needs to perform transformations.
2. `macros`: macro definitions that the makefile supplies the compiler.
3. `disable_eval`: functions to remove from evaluation when transforming code.

## filenames
Filenames of any library function required to transform the target C file. Used
when extracting function arguments during program transformation. Currently supports
the C file of the libraries, header files are future work. The file names are given
as a json list, e.g.,

~~~
        "filenames":[
                {"name":"./libc.c"}
        ],
~~~

## macros
If there are macros which need defining when compiling, we need to know and use
them to correctly transform the C code. For example, in the CGC challenge binaries this field will
likely appear as follows:

~~~
        "macros":[
                {"name": "PATCHED",
                "value": false}
        ],
~~~

## disable_eval
A .json list of functions... e.g.:

~~~
        "disable_eval":[
        "cgc_check",
        "cgc_receive_delim",
        ]
~~~
