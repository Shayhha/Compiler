/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Comp.yacc"

    /*
        Maxim Subotin - 207695479
        Shay Hahiashvili - 206423840
    */
    #include "Helper.c" // This file contains the mknode function and a modified printtree function, and its required to run the compiler.

#line 79 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    INT = 259,                     /* INT  */
    DOUBLE = 260,                  /* DOUBLE  */
    FLOAT = 261,                   /* FLOAT  */
    STRING = 262,                  /* STRING  */
    INT_PTR = 263,                 /* INT_PTR  */
    CHAR_PTR = 264,                /* CHAR_PTR  */
    DOUBLE_PTR = 265,              /* DOUBLE_PTR  */
    FLOAT_PTR = 266,               /* FLOAT_PTR  */
    BOOL = 267,                    /* BOOL  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    VAR = 270,                     /* VAR  */
    ARGS = 271,                    /* ARGS  */
    PUBLIC = 272,                  /* PUBLIC  */
    PRIVATE = 273,                 /* PRIVATE  */
    STATIC = 274,                  /* STATIC  */
    RETURN = 275,                  /* RETURN  */
    NULL_VALUE = 276,              /* NULL_VALUE  */
    VOID = 277,                    /* VOID  */
    COMMENT = 278,                 /* COMMENT  */
    DO = 279,                      /* DO  */
    WHILE = 280,                   /* WHILE  */
    FOR = 281,                     /* FOR  */
    ADD = 282,                     /* ADD  */
    SUB = 283,                     /* SUB  */
    MULT = 284,                    /* MULT  */
    DIVIDE = 285,                  /* DIVIDE  */
    ASSIGN = 286,                  /* ASSIGN  */
    EQUAL = 287,                   /* EQUAL  */
    GREATER = 288,                 /* GREATER  */
    GREATER_EQ = 289,              /* GREATER_EQ  */
    LESSER = 290,                  /* LESSER  */
    LESSER_EQ = 291,               /* LESSER_EQ  */
    NOT = 292,                     /* NOT  */
    NOT_EQ = 293,                  /* NOT_EQ  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    ADDRESS = 296,                 /* ADDRESS  */
    TRUE_VAL = 297,                /* TRUE_VAL  */
    FALSE_VAL = 298,               /* FALSE_VAL  */
    HEX_VAL = 299,                 /* HEX_VAL  */
    STRING_VAL = 300,              /* STRING_VAL  */
    ID = 301,                      /* ID  */
    CHAR_VAL = 302,                /* CHAR_VAL  */
    INT_VAL = 303,                 /* INT_VAL  */
    FLOAT_VAL = 304,               /* FLOAT_VAL  */
    DOUBLE_VAL = 305,              /* DOUBLE_VAL  */
    non_else = 306                 /* non_else  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define INT 259
#define DOUBLE 260
#define FLOAT 261
#define STRING 262
#define INT_PTR 263
#define CHAR_PTR 264
#define DOUBLE_PTR 265
#define FLOAT_PTR 266
#define BOOL 267
#define IF 268
#define ELSE 269
#define VAR 270
#define ARGS 271
#define PUBLIC 272
#define PRIVATE 273
#define STATIC 274
#define RETURN 275
#define NULL_VALUE 276
#define VOID 277
#define COMMENT 278
#define DO 279
#define WHILE 280
#define FOR 281
#define ADD 282
#define SUB 283
#define MULT 284
#define DIVIDE 285
#define ASSIGN 286
#define EQUAL 287
#define GREATER 288
#define GREATER_EQ 289
#define LESSER 290
#define LESSER_EQ 291
#define NOT 292
#define NOT_EQ 293
#define AND 294
#define OR 295
#define ADDRESS 296
#define TRUE_VAL 297
#define FALSE_VAL 298
#define HEX_VAL 299
#define STRING_VAL 300
#define ID 301
#define CHAR_VAL 302
#define INT_VAL 303
#define FLOAT_VAL 304
#define DOUBLE_VAL 305
#define non_else 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "Comp.yacc"

    int intval;
    int* intptr;
    float floatval;
    float* floatptr;
    double doubleval;
    double* doubleptr;
    char charval;
    char* strval;
    node* nodeval;

#line 243 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_INT_PTR = 8,                    /* INT_PTR  */
  YYSYMBOL_CHAR_PTR = 9,                   /* CHAR_PTR  */
  YYSYMBOL_DOUBLE_PTR = 10,                /* DOUBLE_PTR  */
  YYSYMBOL_FLOAT_PTR = 11,                 /* FLOAT_PTR  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_ARGS = 16,                      /* ARGS  */
  YYSYMBOL_PUBLIC = 17,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 18,                   /* PRIVATE  */
  YYSYMBOL_STATIC = 19,                    /* STATIC  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_NULL_VALUE = 21,                /* NULL_VALUE  */
  YYSYMBOL_VOID = 22,                      /* VOID  */
  YYSYMBOL_COMMENT = 23,                   /* COMMENT  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_ADD = 27,                       /* ADD  */
  YYSYMBOL_SUB = 28,                       /* SUB  */
  YYSYMBOL_MULT = 29,                      /* MULT  */
  YYSYMBOL_DIVIDE = 30,                    /* DIVIDE  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 32,                     /* EQUAL  */
  YYSYMBOL_GREATER = 33,                   /* GREATER  */
  YYSYMBOL_GREATER_EQ = 34,                /* GREATER_EQ  */
  YYSYMBOL_LESSER = 35,                    /* LESSER  */
  YYSYMBOL_LESSER_EQ = 36,                 /* LESSER_EQ  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_NOT_EQ = 38,                    /* NOT_EQ  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_ADDRESS = 41,                   /* ADDRESS  */
  YYSYMBOL_TRUE_VAL = 42,                  /* TRUE_VAL  */
  YYSYMBOL_FALSE_VAL = 43,                 /* FALSE_VAL  */
  YYSYMBOL_HEX_VAL = 44,                   /* HEX_VAL  */
  YYSYMBOL_STRING_VAL = 45,                /* STRING_VAL  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_CHAR_VAL = 47,                  /* CHAR_VAL  */
  YYSYMBOL_INT_VAL = 48,                   /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 49,                 /* FLOAT_VAL  */
  YYSYMBOL_DOUBLE_VAL = 50,                /* DOUBLE_VAL  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_non_else = 53,                  /* non_else  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ':'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_code = 64,                      /* code  */
  YYSYMBOL_functions = 65,                 /* functions  */
  YYSYMBOL_function = 66,                  /* function  */
  YYSYMBOL_function_type = 67,             /* function_type  */
  YYSYMBOL_function_return_type = 68,      /* function_return_type  */
  YYSYMBOL_function_args = 69,             /* function_args  */
  YYSYMBOL_func_args_decleration = 70,     /* func_args_decleration  */
  YYSYMBOL_func_many_id = 71,              /* func_many_id  */
  YYSYMBOL_function_static = 72,           /* function_static  */
  YYSYMBOL_function_block = 73,            /* function_block  */
  YYSYMBOL_function_call = 74,             /* function_call  */
  YYSYMBOL_function_params = 75,           /* function_params  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_do_while_statement = 77,        /* do_while_statement  */
  YYSYMBOL_while_statement = 78,           /* while_statement  */
  YYSYMBOL_for_statement = 79,             /* for_statement  */
  YYSYMBOL_for_init = 80,                  /* for_init  */
  YYSYMBOL_for_init_many = 81,             /* for_init_many  */
  YYSYMBOL_update = 82,                    /* update  */
  YYSYMBOL_if_statement = 83,              /* if_statement  */
  YYSYMBOL_else_statement = 84,            /* else_statement  */
  YYSYMBOL_return_statement = 85,          /* return_statement  */
  YYSYMBOL_statement_recursive = 86,       /* statement_recursive  */
  YYSYMBOL_statement = 87,                 /* statement  */
  YYSYMBOL_string_assignment = 88,         /* string_assignment  */
  YYSYMBOL_many_string = 89,               /* many_string  */
  YYSYMBOL_var_assignment = 90,            /* var_assignment  */
  YYSYMBOL_many_id = 91,                   /* many_id  */
  YYSYMBOL_assign_statement = 92,          /* assign_statement  */
  YYSYMBOL_param_type = 93,                /* param_type  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_value = 95                      /* value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   747

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    61,    58,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    42,    44,    45,    47,    49,    51,    53,
      56,    57,    59,    60,    61,    63,    65,    66,    67,    68,
      70,    71,    73,    75,    76,    80,    81,    83,    84,    88,
      93,    95,    96,    98,   100,   102,   104,   106,   108,   110,
     112,   117,   118,   119,   121,   122,   123,   124,   126,   127,
     128,   129,   133,   134,   135,   136,   138,   139,   144,   146,
     147,   148,   149,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   165,   166,   167,   169,   171,   173,
     175,   180,   181,   182,   184,   185,   186,   187,   189,   190,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INT",
  "DOUBLE", "FLOAT", "STRING", "INT_PTR", "CHAR_PTR", "DOUBLE_PTR",
  "FLOAT_PTR", "BOOL", "IF", "ELSE", "VAR", "ARGS", "PUBLIC", "PRIVATE",
  "STATIC", "RETURN", "NULL_VALUE", "VOID", "COMMENT", "DO", "WHILE",
  "FOR", "ADD", "SUB", "MULT", "DIVIDE", "ASSIGN", "EQUAL", "GREATER",
  "GREATER_EQ", "LESSER", "LESSER_EQ", "NOT", "NOT_EQ", "AND", "OR",
  "ADDRESS", "TRUE_VAL", "FALSE_VAL", "HEX_VAL", "STRING_VAL", "ID",
  "CHAR_VAL", "INT_VAL", "FLOAT_VAL", "DOUBLE_VAL", "';'", "','",
  "non_else", "'('", "')'", "':'", "'{'", "'}'", "'['", "']'", "'|'",
  "$accept", "program", "code", "functions", "function", "function_type",
  "function_return_type", "function_args", "func_args_decleration",
  "func_many_id", "function_static", "function_block", "function_call",
  "function_params", "block", "do_while_statement", "while_statement",
  "for_statement", "for_init", "for_init_many", "update", "if_statement",
  "else_statement", "return_statement", "statement_recursive", "statement",
  "string_assignment", "many_string", "var_assignment", "many_id",
  "assign_statement", "param_type", "expression", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-219)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,  -219,  -219,    25,  -219,  -219,    56,   694,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,    -4,  -219,     1,    -9,   735,    20,     2,    15,  -219,
      36,    75,   198,    41,  -219,    20,    54,    54,  -219,    58,
      71,   182,   387,  -219,  -219,    53,    72,    73,   -32,    11,
      -1,   387,    12,  -219,  -219,  -219,  -219,   -22,  -219,  -219,
    -219,  -219,   387,   247,  -219,   387,  -219,  -219,   296,  -219,
    -219,  -219,  -219,  -219,    79,   296,  -219,  -219,   614,  -219,
    -219,    41,  -219,    60,    80,    81,    83,    82,   387,    84,
      16,    76,   628,   296,   118,   387,    -7,  -219,  -219,  -219,
    -219,  -219,  -219,   127,   387,  -219,  -219,   113,   417,    74,
     387,   109,   506,  -219,   103,   117,  -219,  -219,  -219,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,  -219,  -219,    54,   735,   735,   114,  -219,   520,   119,
    -219,  -219,   110,   538,   182,   121,   -12,   387,   112,  -219,
     132,   552,   115,    18,   685,  -219,   129,   584,   477,  -219,
    -219,  -219,  -219,   697,   697,   141,   141,    57,    57,    57,
      57,    57,    57,  -219,  -219,  -219,  -219,  -219,   108,   296,
      -3,   144,   387,   296,   140,   166,   153,   149,   642,   387,
    -219,  -219,  -219,   143,  -219,   387,   173,    -2,   192,   192,
     119,   155,  -219,   570,  -219,  -219,   153,   387,  -219,   153,
     327,   656,   387,  -219,    62,    58,   156,   296,  -219,  -219,
    -219,   119,   158,  -219,   685,  -219,   -20,   296,   159,   599,
     357,   491,   169,   177,  -219,    58,  -219,  -219,  -219,  -219,
     165,  -219,  -219,   296,   447,   296,   174,  -219,  -219,  -219,
    -219,   447,  -219,  -219,  -219,  -219,  -219,   296,  -219,  -219,
    -219
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    10,     0,     2,     3,     5,     0,     1,     4,
      93,    90,    92,    91,    13,    94,    97,    96,    95,    98,
      14,     0,    12,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     9,     0,     0,     0,    22,     0,
       0,     0,     0,    99,    70,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   135,   134,   130,   133,   121,
     122,   123,     0,     0,    24,     0,    69,   120,    61,    68,
      67,    66,    65,    72,     0,    59,    64,    63,     0,   119,
       8,     0,     7,    21,    19,    17,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,   127,   128,   129,
     124,   125,   126,   101,     0,   102,   100,     0,     0,     0,
       0,     0,     0,    73,     0,     0,    62,    23,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     6,     0,     0,     0,     0,    74,     0,     0,
     101,    58,     0,     0,     0,     0,    47,     0,     0,    43,
       0,     0,     0,     0,    88,    26,     0,    28,     0,    82,
     117,    29,   118,   111,   112,   113,   114,   107,   105,   106,
     103,   104,   108,   110,   109,    20,    18,    16,     0,     0,
      87,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      83,   115,   116,   100,    25,     0,     0,    80,    54,    52,
       0,    86,    81,     0,    32,    31,     0,     0,    45,     0,
       0,     0,     0,    27,     0,     0,    78,     0,    55,    53,
      85,     0,     0,    41,    42,    44,   130,     0,     0,    49,
       0,     0,     0,     0,    79,     0,    57,    56,    84,    30,
      51,    36,    40,     0,     0,     0,     0,    89,    76,    75,
      77,     0,    35,    39,    48,    34,    38,     0,    50,    33,
      37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   224,    14,  -219,  -219,  -219,   -21,   -34,
     196,   -29,  -219,    37,   -45,  -219,  -219,  -219,  -219,  -171,
    -218,  -219,    34,  -219,   -27,  -152,  -219,  -192,  -219,  -170,
     -90,    -5,   -41,  -219
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    66,     7,    21,    27,    29,    84,
      33,    34,    67,   156,    68,    69,    70,    71,   148,   149,
     228,    72,   218,    73,   114,    75,    76,    87,    77,   181,
     111,    30,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,    92,    22,    85,    80,    74,    82,    25,   144,   108,
     105,   108,   246,   150,     6,   208,    97,    98,    99,   108,
       6,   112,   145,   234,   115,     8,   254,   199,   108,   108,
     220,   205,   109,   258,   109,   223,    89,   110,   225,   146,
     186,   116,    23,   250,   147,   103,    26,   138,   118,   200,
     215,   238,   132,   104,   143,    24,   187,    35,   106,   100,
     101,   102,   140,   151,   193,   237,   107,   154,   157,   158,
     104,    36,   107,     1,     2,   242,    31,    32,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     201,   253,    37,   256,    38,    43,   129,   130,    32,   175,
      83,    48,    49,    90,    86,   260,   188,   216,   232,   233,
      93,    51,   133,   176,   177,    52,    53,    54,    55,    56,
      91,    58,    59,    60,    61,    88,    95,    96,    62,   155,
     109,   134,   135,   137,   198,    65,   240,   117,   204,   184,
     139,   203,   136,   142,   119,   120,   121,   122,   211,   123,
     124,   125,   126,   127,   157,   128,   129,   130,   108,   152,
     159,   161,   178,   189,   182,   180,   224,   185,   197,   229,
     192,   231,   236,   123,   124,   125,   126,   127,   162,   128,
     129,   130,   241,   190,   194,    10,    11,    12,    13,   229,
      15,    16,    17,    18,    19,   202,   206,   207,   252,   146,
     255,   209,   212,   229,   214,    39,   217,   221,   235,   239,
     229,    40,   259,    41,   243,     1,     2,   251,    42,    43,
     248,    44,    45,    46,    47,    48,    49,    50,   249,   257,
       9,    81,   213,   219,     0,    51,     0,     0,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,     0,    39,    63,    64,     0,     0,    65,
      40,     0,    41,     0,     1,     2,     0,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,     0,    39,    63,   113,     0,     0,    65,    40,
       0,    41,     0,     1,     2,     0,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    43,     0,
      62,     0,     0,    63,    48,    49,    90,    65,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,    53,
      54,    55,    56,   226,    58,    59,    60,    61,    43,     0,
       0,    62,   227,     0,    48,    49,    90,     0,    65,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,    53,
      54,    55,    56,   226,    58,    59,    60,    61,    43,     0,
       0,    62,   245,     0,    48,    49,    90,     0,    65,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,    53,
      54,    55,    56,    91,    58,    59,    60,    61,    43,     0,
       0,    62,     0,     0,    48,    49,    90,     0,    65,     0,
       0,     0,     0,     0,    51,     0,     0,     0,   153,    53,
      54,    55,    56,    91,    58,    59,    60,    61,    43,     0,
       0,    62,     0,     0,    48,    49,    90,     0,    65,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,    53,
      54,    55,    56,   226,    58,    59,    60,    61,     0,     0,
       0,    62,     0,     0,   119,   120,   121,   122,    65,   123,
     124,   125,   126,   127,     0,   128,   129,   130,   119,   120,
     121,   122,     0,   123,   124,   125,   126,   127,     0,   128,
     129,   130,     0,   119,   120,   121,   122,   196,   123,   124,
     125,   126,   127,     0,   128,   129,   130,   119,   120,   121,
     122,   247,   123,   124,   125,   126,   127,     0,   128,   129,
     130,   160,     0,     0,     0,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   179,   128,   129,   130,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,     0,
     128,   129,   130,   183,     0,     0,     0,   119,   120,   121,
     122,     0,   123,   124,   125,   126,   127,   191,   128,   129,
     130,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,     0,   128,   129,   130,   222,   119,   120,   121,   122,
       0,   123,   124,   125,   126,   127,   195,   128,   129,   130,
       0,   119,   120,   121,   122,     0,   123,   124,   125,   126,
     127,   244,   128,   129,   130,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   131,   128,   129,   130,   119,
     120,   121,   122,     0,   123,   124,   125,   126,   127,   141,
     128,   129,   130,   119,   120,   121,   122,     0,   123,   124,
     125,   126,   127,   210,   128,   129,   130,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   230,     0,     0,
       0,     0,   119,   120,   121,   122,    20,   123,   124,   125,
     126,   127,     0,   128,   129,   130,   121,   122,     0,   123,
     124,   125,   126,   127,     0,   128,   129,   130,    10,    11,
      12,    13,    28,    15,    16,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
      45,    42,     7,    37,    33,    32,    35,    16,    15,    31,
      51,    31,   230,   103,     0,   186,    48,    49,    50,    31,
       6,    62,    29,   215,    65,     0,   244,   179,    31,    31,
     200,   183,    54,   251,    54,   206,    41,    59,   209,    46,
      52,    68,    46,   235,    51,    46,    55,    88,    75,    52,
      52,   221,    81,    54,    95,    54,   146,    55,    46,    48,
      49,    50,    46,   104,    46,   217,    54,   108,   109,   110,
      54,    56,    54,    17,    18,   227,    56,    57,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     180,   243,    56,   245,    19,    21,    39,    40,    57,   133,
      46,    27,    28,    29,    46,   257,   147,   197,    46,    47,
      57,    37,    52,   134,   135,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    54,    54,    54,    54,    55,
      54,    51,    51,    51,   179,    61,   226,    58,   183,   144,
      56,   182,    59,    25,    27,    28,    29,    30,   189,    32,
      33,    34,    35,    36,   195,    38,    39,    40,    31,    46,
      51,    58,    48,    51,    54,    46,   207,    46,    60,   210,
      55,   212,   217,    32,    33,    34,    35,    36,    61,    38,
      39,    40,   227,    51,    55,     3,     4,     5,     6,   230,
       8,     9,    10,    11,    12,    51,    56,    31,   243,    46,
     245,    52,    59,   244,    31,     7,    14,    52,    52,    51,
     251,    13,   257,    15,    55,    17,    18,    52,    20,    21,
      51,    23,    24,    25,    26,    27,    28,    29,    51,    55,
       6,    35,   195,   199,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,     7,    57,    58,    -1,    -1,    61,
      13,    -1,    15,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,     7,    57,    58,    -1,    -1,    61,    13,
      -1,    15,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    21,    -1,
      54,    -1,    -1,    57,    27,    28,    29,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    21,    -1,
      -1,    54,    55,    -1,    27,    28,    29,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    21,    -1,
      -1,    54,    55,    -1,    27,    28,    29,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    21,    -1,
      -1,    54,    -1,    -1,    27,    28,    29,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    21,    -1,
      -1,    54,    -1,    -1,    27,    28,    29,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    27,    28,    29,    30,    61,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    -1,    27,    28,    29,    30,    60,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    27,    28,    29,
      30,    60,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    55,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    55,    38,    39,    40,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    55,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    55,    38,    39,
      40,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    55,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    52,    38,    39,    40,
      -1,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    52,    38,    39,    40,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    51,    38,    39,    40,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    51,
      38,    39,    40,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    51,    38,    39,    40,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    51,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    22,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    18,    63,    64,    65,    66,    67,     0,    65,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      22,    68,    93,    46,    54,    16,    55,    69,     7,    70,
      93,    56,    57,    72,    73,    55,    56,    56,    19,     7,
      13,    15,    20,    21,    23,    24,    25,    26,    27,    28,
      29,    37,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    54,    57,    58,    61,    66,    74,    76,    77,
      78,    79,    83,    85,    86,    87,    88,    90,    94,    95,
      73,    72,    73,    46,    71,    71,    46,    89,    54,    93,
      29,    46,    94,    57,    76,    54,    54,    48,    49,    50,
      48,    49,    50,    46,    54,    94,    46,    54,    31,    54,
      59,    92,    94,    58,    86,    94,    86,    58,    86,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    38,    39,
      40,    51,    73,    52,    51,    51,    59,    51,    94,    56,
      46,    51,    25,    94,    15,    29,    46,    51,    80,    81,
      92,    94,    46,    41,    94,    55,    75,    94,    94,    51,
      55,    58,    61,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    71,    70,    70,    48,    55,
      46,    91,    54,    55,    93,    46,    52,    92,    94,    51,
      51,    55,    55,    46,    55,    52,    60,    60,    76,    87,
      52,    92,    51,    94,    76,    87,    56,    31,    81,    52,
      51,    94,    59,    75,    31,    52,    92,    14,    84,    84,
      91,    52,    55,    81,    94,    81,    46,    55,    82,    94,
      51,    94,    46,    47,    89,    52,    76,    87,    91,    51,
      92,    76,    87,    55,    52,    55,    82,    60,    51,    51,
      89,    52,    76,    87,    82,    76,    87,    55,    82,    76,
      87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    68,    68,    68,    69,    70,    70,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    90,    90,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     8,     7,     7,     6,
       1,     1,     1,     1,     1,     2,     5,     3,     5,     3,
       3,     1,     2,     3,     2,     4,     3,     3,     1,     3,
       7,     5,     5,     9,     8,     8,     7,     9,     8,     8,
       7,     4,     4,     1,     4,     3,     2,     1,     3,     1,
       4,     2,     5,     6,     5,     6,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     7,     7,     7,     5,     6,
       4,     5,     3,     4,     4,     3,     2,     1,     2,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     3,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: code  */
#line 40 "Comp.yacc"
               {(yyval.nodeval) = (yyvsp[0].nodeval); printtree((yyval.nodeval), 0);}
#line 1594 "y.tab.c"
    break;

  case 3: /* code: functions  */
#line 42 "Comp.yacc"
                 {(yyval.nodeval) = mknode("CODE", (yyvsp[0].nodeval), NULL);}
#line 1600 "y.tab.c"
    break;

  case 4: /* functions: function functions  */
#line 44 "Comp.yacc"
                               {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1606 "y.tab.c"
    break;

  case 5: /* functions: function  */
#line 45 "Comp.yacc"
                   {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1612 "y.tab.c"
    break;

  case 6: /* function: function_type function_return_type ID '(' function_args ')' function_static function_block  */
#line 48 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-5].strval), mknode("", (yyvsp[-7].nodeval), (yyvsp[-1].nodeval)), mknode("ARGS>>", (yyvsp[-3].nodeval), NULL)), mknode("RETURN", (yyvsp[-6].nodeval), mknode("FUNCTION BLOCK", (yyvsp[0].nodeval), NULL)));}
#line 1618 "y.tab.c"
    break;

  case 7: /* function: function_type function_return_type ID '(' function_args ')' function_block  */
#line 50 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-4].strval), mknode("", (yyvsp[-6].nodeval), NULL), mknode("ARGS>>", (yyvsp[-2].nodeval), NULL)), mknode("RETURN", (yyvsp[-5].nodeval), mknode("FUNCTION BLOCK", (yyvsp[0].nodeval), NULL)));}
#line 1624 "y.tab.c"
    break;

  case 8: /* function: function_type function_return_type ID '(' ')' function_static function_block  */
#line 52 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-4].strval), mknode("", (yyvsp[-6].nodeval), (yyvsp[-1].nodeval)), NULL), mknode("RETURN", (yyvsp[-5].nodeval), mknode("FUNCTION BLOCK", (yyvsp[0].nodeval), NULL)));}
#line 1630 "y.tab.c"
    break;

  case 9: /* function: function_type function_return_type ID '(' ')' function_block  */
#line 54 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-3].strval), mknode("", (yyvsp[-5].nodeval), NULL), NULL), mknode("RETURN", (yyvsp[-4].nodeval), mknode("FUNCTION BLOCK", (yyvsp[0].nodeval), NULL)));}
#line 1636 "y.tab.c"
    break;

  case 10: /* function_type: PRIVATE  */
#line 56 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1642 "y.tab.c"
    break;

  case 11: /* function_type: PUBLIC  */
#line 57 "Comp.yacc"
                         {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1648 "y.tab.c"
    break;

  case 12: /* function_return_type: param_type  */
#line 59 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1654 "y.tab.c"
    break;

  case 13: /* function_return_type: STRING  */
#line 60 "Comp.yacc"
                                 {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1660 "y.tab.c"
    break;

  case 14: /* function_return_type: VOID  */
#line 61 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1666 "y.tab.c"
    break;

  case 15: /* function_args: ARGS func_args_decleration  */
#line 63 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1672 "y.tab.c"
    break;

  case 16: /* func_args_decleration: param_type ':' func_many_id ';' func_args_decleration  */
#line 65 "Comp.yacc"
                                                                              {(yyval.nodeval) = mknode("VAR", mknode("", (yyvsp[-4].nodeval), (yyvsp[-2].nodeval)), (yyvsp[0].nodeval));}
#line 1678 "y.tab.c"
    break;

  case 17: /* func_args_decleration: param_type ':' func_many_id  */
#line 66 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode("VAR", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1684 "y.tab.c"
    break;

  case 18: /* func_args_decleration: STRING ':' func_many_id ';' func_args_decleration  */
#line 67 "Comp.yacc"
                                                                            {(yyval.nodeval) = mknode("STRING", mknode("", (yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval));}
#line 1690 "y.tab.c"
    break;

  case 19: /* func_args_decleration: STRING ':' func_many_id  */
#line 68 "Comp.yacc"
                                                  {(yyval.nodeval) = mknode("STRING", (yyvsp[0].nodeval), NULL);}
#line 1696 "y.tab.c"
    break;

  case 20: /* func_many_id: ID ',' func_many_id  */
#line 70 "Comp.yacc"
                                   {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1702 "y.tab.c"
    break;

  case 21: /* func_many_id: ID  */
#line 71 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1708 "y.tab.c"
    break;

  case 22: /* function_static: ':' STATIC  */
#line 73 "Comp.yacc"
                             {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1714 "y.tab.c"
    break;

  case 23: /* function_block: '{' statement_recursive '}'  */
#line 75 "Comp.yacc"
                                             {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), NULL);}
#line 1720 "y.tab.c"
    break;

  case 24: /* function_block: '{' '}'  */
#line 76 "Comp.yacc"
                          {(yyval.nodeval) = NULL;}
#line 1726 "y.tab.c"
    break;

  case 25: /* function_call: ID '(' function_params ')'  */
#line 80 "Comp.yacc"
                                           {(yyval.nodeval) = mknode(concat((yyvsp[-3].strval),"( params: ... )"), (yyvsp[-1].nodeval), NULL);}
#line 1732 "y.tab.c"
    break;

  case 26: /* function_call: ID '(' ')'  */
#line 81 "Comp.yacc"
                             {(yyval.nodeval) = mknode(concat((yyvsp[-2].strval),"()"), NULL, NULL);}
#line 1738 "y.tab.c"
    break;

  case 27: /* function_params: expression ',' function_params  */
#line 83 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1744 "y.tab.c"
    break;

  case 28: /* function_params: expression  */
#line 84 "Comp.yacc"
                             {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1750 "y.tab.c"
    break;

  case 29: /* block: '{' statement_recursive '}'  */
#line 88 "Comp.yacc"
                                    {(yyval.nodeval) = mknode("BLOCK", (yyvsp[-1].nodeval), NULL);}
#line 1756 "y.tab.c"
    break;

  case 30: /* do_while_statement: DO block WHILE '(' expression ')' ';'  */
#line 93 "Comp.yacc"
                                                           {(yyval.nodeval) = mknode("DO WHILE", (yyvsp[-5].nodeval), (yyvsp[-2].nodeval));}
#line 1762 "y.tab.c"
    break;

  case 31: /* while_statement: WHILE '(' expression ')' statement  */
#line 95 "Comp.yacc"
                                                     {(yyval.nodeval) = mknode("WHILE", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1768 "y.tab.c"
    break;

  case 32: /* while_statement: WHILE '(' expression ')' block  */
#line 96 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("WHILE", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1774 "y.tab.c"
    break;

  case 33: /* for_statement: FOR '(' for_init ';' expression ';' update ')' block  */
#line 99 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("ASSIGN", (yyvsp[-6].nodeval), mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL))), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1780 "y.tab.c"
    break;

  case 34: /* for_statement: FOR '(' for_init ';' expression ';' ')' block  */
#line 101 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("ASSIGN", (yyvsp[-5].nodeval), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1786 "y.tab.c"
    break;

  case 35: /* for_statement: FOR '(' ';' expression ';' update ')' block  */
#line 103 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1792 "y.tab.c"
    break;

  case 36: /* for_statement: FOR '(' ';' expression ';' ')' block  */
#line 105 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1798 "y.tab.c"
    break;

  case 37: /* for_statement: FOR '(' for_init ';' expression ';' update ')' statement  */
#line 107 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("ASSIGN", (yyvsp[-6].nodeval), mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL))), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1804 "y.tab.c"
    break;

  case 38: /* for_statement: FOR '(' for_init ';' expression ';' ')' statement  */
#line 109 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("ASSIGN", (yyvsp[-5].nodeval), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1810 "y.tab.c"
    break;

  case 39: /* for_statement: FOR '(' ';' expression ';' update ')' statement  */
#line 111 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1816 "y.tab.c"
    break;

  case 40: /* for_statement: FOR '(' ';' expression ';' ')' statement  */
#line 113 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FOR", mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1822 "y.tab.c"
    break;

  case 41: /* for_init: VAR param_type ':' for_init_many  */
#line 117 "Comp.yacc"
                                            {(yyval.nodeval) = mknode("", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1828 "y.tab.c"
    break;

  case 42: /* for_init: MULT ID ASSIGN expression  */
#line 118 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("", mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL), NULL);}
#line 1834 "y.tab.c"
    break;

  case 43: /* for_init: for_init_many  */
#line 119 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1840 "y.tab.c"
    break;

  case 44: /* for_init_many: ID assign_statement ',' for_init_many  */
#line 121 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1846 "y.tab.c"
    break;

  case 45: /* for_init_many: ID ',' for_init_many  */
#line 122 "Comp.yacc"
                                 {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1852 "y.tab.c"
    break;

  case 46: /* for_init_many: ID assign_statement  */
#line 123 "Comp.yacc"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 1858 "y.tab.c"
    break;

  case 47: /* for_init_many: ID  */
#line 124 "Comp.yacc"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1864 "y.tab.c"
    break;

  case 48: /* update: expression ',' update  */
#line 126 "Comp.yacc"
                               {(yyval.nodeval) = mknode("", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1870 "y.tab.c"
    break;

  case 49: /* update: expression  */
#line 127 "Comp.yacc"
                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1876 "y.tab.c"
    break;

  case 50: /* update: ID assign_statement ',' update  */
#line 128 "Comp.yacc"
                                         {(yyval.nodeval) = mknode(concat("ASSIGN  ",(yyvsp[-3].strval)), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1882 "y.tab.c"
    break;

  case 51: /* update: ID assign_statement  */
#line 129 "Comp.yacc"
                              {(yyval.nodeval) = mknode(concat("ASSIGN  ",(yyvsp[-1].strval)), (yyvsp[0].nodeval), NULL);}
#line 1888 "y.tab.c"
    break;

  case 52: /* if_statement: IF '(' expression ')' statement  */
#line 133 "Comp.yacc"
                                                              {(yyval.nodeval) = mknode("IF", mknode("CONDITION",(yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval));}
#line 1894 "y.tab.c"
    break;

  case 53: /* if_statement: IF '(' expression ')' statement else_statement  */
#line 134 "Comp.yacc"
                                                                 {(yyval.nodeval) = mknode("", mknode("IF", mknode("CONDITION",(yyvsp[-3].nodeval), NULL), (yyvsp[-1].nodeval)), mknode("ELSE", (yyvsp[0].nodeval), NULL));}
#line 1900 "y.tab.c"
    break;

  case 54: /* if_statement: IF '(' expression ')' block  */
#line 135 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("IF", mknode("CONDITION",(yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval));}
#line 1906 "y.tab.c"
    break;

  case 55: /* if_statement: IF '(' expression ')' block else_statement  */
#line 136 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("", mknode("IF", mknode("CONDITION",(yyvsp[-3].nodeval), NULL), (yyvsp[-1].nodeval)), mknode("ELSE", (yyvsp[0].nodeval), NULL));}
#line 1912 "y.tab.c"
    break;

  case 56: /* else_statement: ELSE statement  */
#line 138 "Comp.yacc"
                                {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1918 "y.tab.c"
    break;

  case 57: /* else_statement: ELSE block  */
#line 139 "Comp.yacc"
                             {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1924 "y.tab.c"
    break;

  case 58: /* return_statement: RETURN expression ';'  */
#line 144 "Comp.yacc"
                                         {(yyval.nodeval) = mknode("RETURN", (yyvsp[-1].nodeval), NULL);}
#line 1930 "y.tab.c"
    break;

  case 59: /* statement_recursive: statement  */
#line 146 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1936 "y.tab.c"
    break;

  case 60: /* statement_recursive: statement statement_recursive  */
#line 147 "Comp.yacc"
                                                    {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1942 "y.tab.c"
    break;

  case 61: /* statement_recursive: block  */
#line 148 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1948 "y.tab.c"
    break;

  case 62: /* statement_recursive: block statement_recursive  */
#line 149 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1954 "y.tab.c"
    break;

  case 63: /* statement: var_assignment  */
#line 151 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1960 "y.tab.c"
    break;

  case 64: /* statement: string_assignment  */
#line 152 "Comp.yacc"
                                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1966 "y.tab.c"
    break;

  case 65: /* statement: if_statement  */
#line 153 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1972 "y.tab.c"
    break;

  case 66: /* statement: for_statement  */
#line 154 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1978 "y.tab.c"
    break;

  case 67: /* statement: while_statement  */
#line 155 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1984 "y.tab.c"
    break;

  case 68: /* statement: do_while_statement  */
#line 156 "Comp.yacc"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1990 "y.tab.c"
    break;

  case 69: /* statement: function  */
#line 157 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1996 "y.tab.c"
    break;

  case 70: /* statement: COMMENT  */
#line 158 "Comp.yacc"
                          {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2002 "y.tab.c"
    break;

  case 71: /* statement: expression ';'  */
#line 159 "Comp.yacc"
                                 {(yyval.nodeval) = (yyvsp[-1].nodeval);}
#line 2008 "y.tab.c"
    break;

  case 72: /* statement: return_statement  */
#line 160 "Comp.yacc"
                                   {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2014 "y.tab.c"
    break;

  case 73: /* statement: '{' '}'  */
#line 161 "Comp.yacc"
                          {(yyval.nodeval) = NULL;}
#line 2020 "y.tab.c"
    break;

  case 74: /* string_assignment: STRING many_string ';'  */
#line 165 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("STRING", (yyvsp[-1].nodeval), NULL);}
#line 2026 "y.tab.c"
    break;

  case 75: /* string_assignment: ID '[' expression ']' ASSIGN CHAR_VAL ';'  */
#line 166 "Comp.yacc"
                                                                {(yyval.nodeval) = mknode("ASSIGN[]", mknode("ID", mknode((yyvsp[-6].strval), NULL, NULL), (yyvsp[-4].nodeval)), mknode("assign", mknode((yyvsp[-1].strval), NULL, NULL), NULL));}
#line 2032 "y.tab.c"
    break;

  case 76: /* string_assignment: ID '[' expression ']' ASSIGN ID ';'  */
#line 167 "Comp.yacc"
                                                          {(yyval.nodeval) = mknode("ASSIGN[]", mknode("ID", mknode((yyvsp[-6].strval), NULL, NULL), (yyvsp[-4].nodeval)), mknode("assign", mknode((yyvsp[-1].strval), NULL, NULL), NULL));}
#line 2038 "y.tab.c"
    break;

  case 77: /* many_string: ID '[' INT_VAL ']' assign_statement ',' many_string  */
#line 170 "Comp.yacc"
                {(yyval.nodeval) = mknode("", mknode("ID", mknode((yyvsp[-6].strval), NULL, NULL), mknode(concat(concat("[",(yyvsp[-4].strval)),"]"), NULL, NULL)), mknode("ASSIGN", (yyvsp[-2].nodeval), (yyvsp[0].nodeval)));}
#line 2044 "y.tab.c"
    break;

  case 78: /* many_string: ID '[' INT_VAL ']' assign_statement  */
#line 172 "Comp.yacc"
                {(yyval.nodeval) = mknode("", mknode("ID", mknode((yyvsp[-4].strval), NULL, NULL), mknode(concat(concat("[",(yyvsp[-2].strval)),"]"), NULL, NULL)), mknode("ASSIGN",(yyvsp[0].nodeval),NULL));}
#line 2050 "y.tab.c"
    break;

  case 79: /* many_string: ID '[' INT_VAL ']' ',' many_string  */
#line 174 "Comp.yacc"
                {(yyval.nodeval) = mknode("", mknode("ID", mknode((yyvsp[-5].strval), NULL, NULL), mknode(concat(concat("[",(yyvsp[-3].strval)),"]"), NULL, NULL)), (yyvsp[0].nodeval));}
#line 2056 "y.tab.c"
    break;

  case 80: /* many_string: ID '[' INT_VAL ']'  */
#line 176 "Comp.yacc"
                {(yyval.nodeval) = mknode("", mknode((yyvsp[-3].strval), NULL, NULL), mknode(concat(concat("[",(yyvsp[-1].strval)),"]"), NULL, NULL));}
#line 2062 "y.tab.c"
    break;

  case 81: /* var_assignment: VAR param_type ':' many_id ';'  */
#line 180 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("ASSIGN", (yyvsp[-3].nodeval), (yyvsp[-1].nodeval));}
#line 2068 "y.tab.c"
    break;

  case 82: /* var_assignment: ID assign_statement ';'  */
#line 181 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2074 "y.tab.c"
    break;

  case 83: /* var_assignment: MULT ID assign_statement ';'  */
#line 182 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2080 "y.tab.c"
    break;

  case 84: /* many_id: ID assign_statement ',' many_id  */
#line 184 "Comp.yacc"
                                          {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2086 "y.tab.c"
    break;

  case 85: /* many_id: ID ',' many_id  */
#line 185 "Comp.yacc"
                           {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 2092 "y.tab.c"
    break;

  case 86: /* many_id: ID assign_statement  */
#line 186 "Comp.yacc"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 2098 "y.tab.c"
    break;

  case 87: /* many_id: ID  */
#line 187 "Comp.yacc"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2104 "y.tab.c"
    break;

  case 88: /* assign_statement: ASSIGN expression  */
#line 189 "Comp.yacc"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2110 "y.tab.c"
    break;

  case 89: /* assign_statement: ASSIGN ADDRESS ID '[' expression ']'  */
#line 190 "Comp.yacc"
                                                         {(yyval.nodeval) = mknode(concat("&",(yyvsp[-3].strval)), (yyvsp[-1].nodeval), NULL);}
#line 2116 "y.tab.c"
    break;

  case 90: /* param_type: INT  */
#line 194 "Comp.yacc"
                 {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2122 "y.tab.c"
    break;

  case 91: /* param_type: FLOAT  */
#line 195 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2128 "y.tab.c"
    break;

  case 92: /* param_type: DOUBLE  */
#line 196 "Comp.yacc"
                      {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2134 "y.tab.c"
    break;

  case 93: /* param_type: CHAR  */
#line 197 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2140 "y.tab.c"
    break;

  case 94: /* param_type: INT_PTR  */
#line 198 "Comp.yacc"
                       {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2146 "y.tab.c"
    break;

  case 95: /* param_type: FLOAT_PTR  */
#line 199 "Comp.yacc"
                         {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2152 "y.tab.c"
    break;

  case 96: /* param_type: DOUBLE_PTR  */
#line 200 "Comp.yacc"
                          {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2158 "y.tab.c"
    break;

  case 97: /* param_type: CHAR_PTR  */
#line 201 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2164 "y.tab.c"
    break;

  case 98: /* param_type: BOOL  */
#line 202 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2170 "y.tab.c"
    break;

  case 99: /* expression: NULL_VALUE  */
#line 205 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2176 "y.tab.c"
    break;

  case 100: /* expression: ADDRESS ID  */
#line 206 "Comp.yacc"
                         {(yyval.nodeval) = mknode("&", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 2182 "y.tab.c"
    break;

  case 101: /* expression: MULT ID  */
#line 207 "Comp.yacc"
                      {(yyval.nodeval) = mknode("*", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 2188 "y.tab.c"
    break;

  case 102: /* expression: NOT expression  */
#line 208 "Comp.yacc"
                             {(yyval.nodeval) = mknode("! (not)", (yyvsp[0].nodeval), NULL);}
#line 2194 "y.tab.c"
    break;

  case 103: /* expression: expression LESSER expression  */
#line 209 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("<", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2200 "y.tab.c"
    break;

  case 104: /* expression: expression LESSER_EQ expression  */
#line 210 "Comp.yacc"
                                              {(yyval.nodeval) = mknode("<=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2206 "y.tab.c"
    break;

  case 105: /* expression: expression GREATER expression  */
#line 211 "Comp.yacc"
                                            {(yyval.nodeval) = mknode(">", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2212 "y.tab.c"
    break;

  case 106: /* expression: expression GREATER_EQ expression  */
#line 212 "Comp.yacc"
                                               {(yyval.nodeval) = mknode(">=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2218 "y.tab.c"
    break;

  case 107: /* expression: expression EQUAL expression  */
#line 213 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("==", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2224 "y.tab.c"
    break;

  case 108: /* expression: expression NOT_EQ expression  */
#line 214 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("!=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2230 "y.tab.c"
    break;

  case 109: /* expression: expression OR expression  */
#line 215 "Comp.yacc"
                                       {(yyval.nodeval) = mknode("||", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2236 "y.tab.c"
    break;

  case 110: /* expression: expression AND expression  */
#line 216 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("&&", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2242 "y.tab.c"
    break;

  case 111: /* expression: expression ADD expression  */
#line 217 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("+", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2248 "y.tab.c"
    break;

  case 112: /* expression: expression SUB expression  */
#line 218 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("-", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2254 "y.tab.c"
    break;

  case 113: /* expression: expression MULT expression  */
#line 219 "Comp.yacc"
                                         {(yyval.nodeval) = mknode("*", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2260 "y.tab.c"
    break;

  case 114: /* expression: expression DIVIDE expression  */
#line 220 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("/", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2266 "y.tab.c"
    break;

  case 115: /* expression: MULT '(' expression ')'  */
#line 221 "Comp.yacc"
                                      {(yyval.nodeval) = mknode("*( )", (yyvsp[-1].nodeval), NULL);}
#line 2272 "y.tab.c"
    break;

  case 116: /* expression: ADDRESS '(' ID ')'  */
#line 222 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("&( )", mknode((yyvsp[-1].strval),NULL,NULL), NULL);}
#line 2278 "y.tab.c"
    break;

  case 117: /* expression: '(' expression ')'  */
#line 223 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("( )", (yyvsp[-1].nodeval), NULL);}
#line 2284 "y.tab.c"
    break;

  case 118: /* expression: '|' expression '|'  */
#line 224 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("| |", (yyvsp[-1].nodeval), NULL);}
#line 2290 "y.tab.c"
    break;

  case 119: /* expression: value  */
#line 225 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2296 "y.tab.c"
    break;

  case 120: /* expression: function_call  */
#line 226 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2302 "y.tab.c"
    break;

  case 121: /* value: INT_VAL  */
#line 229 "Comp.yacc"
                {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2308 "y.tab.c"
    break;

  case 122: /* value: FLOAT_VAL  */
#line 230 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2314 "y.tab.c"
    break;

  case 123: /* value: DOUBLE_VAL  */
#line 231 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2320 "y.tab.c"
    break;

  case 124: /* value: SUB INT_VAL  */
#line 232 "Comp.yacc"
                      {(yyval.nodeval) = mknode(concat("-",(yyvsp[0].strval)), NULL, NULL);}
#line 2326 "y.tab.c"
    break;

  case 125: /* value: SUB FLOAT_VAL  */
#line 233 "Comp.yacc"
                        {(yyval.nodeval) = mknode(concat("-",(yyvsp[0].strval)), NULL, NULL);}
#line 2332 "y.tab.c"
    break;

  case 126: /* value: SUB DOUBLE_VAL  */
#line 234 "Comp.yacc"
                         {(yyval.nodeval) = mknode(concat("-",(yyvsp[0].strval)), NULL, NULL);}
#line 2338 "y.tab.c"
    break;

  case 127: /* value: ADD INT_VAL  */
#line 235 "Comp.yacc"
                      {(yyval.nodeval) = mknode(concat("+",(yyvsp[0].strval)), NULL, NULL);}
#line 2344 "y.tab.c"
    break;

  case 128: /* value: ADD FLOAT_VAL  */
#line 236 "Comp.yacc"
                        {(yyval.nodeval) = mknode(concat("+",(yyvsp[0].strval)), NULL, NULL);}
#line 2350 "y.tab.c"
    break;

  case 129: /* value: ADD DOUBLE_VAL  */
#line 237 "Comp.yacc"
                         {(yyval.nodeval) = mknode(concat("+",(yyvsp[0].strval)), NULL, NULL);}
#line 2356 "y.tab.c"
    break;

  case 130: /* value: ID  */
#line 238 "Comp.yacc"
             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2362 "y.tab.c"
    break;

  case 131: /* value: TRUE_VAL  */
#line 239 "Comp.yacc"
                   {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2368 "y.tab.c"
    break;

  case 132: /* value: FALSE_VAL  */
#line 240 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2374 "y.tab.c"
    break;

  case 133: /* value: CHAR_VAL  */
#line 241 "Comp.yacc"
                   {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2380 "y.tab.c"
    break;

  case 134: /* value: STRING_VAL  */
#line 242 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2386 "y.tab.c"
    break;

  case 135: /* value: HEX_VAL  */
#line 243 "Comp.yacc"
                  {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2392 "y.tab.c"
    break;


#line 2396 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 245 "Comp.yacc"

#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        int yydebug = 1;
        fflush(stdout);
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "%s at line %d\n", error, yylineno);
        fprintf(stderr, "rejected token: %s\n", yytext);
        return 0;
}
