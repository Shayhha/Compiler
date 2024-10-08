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
    #include "Semantics.c" // This is a file that contans the linked list and stack implementations for part 2 of the project

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
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_code = 64,                      /* code  */
  YYSYMBOL_functions = 65,                 /* functions  */
  YYSYMBOL_function = 66,                  /* function  */
  YYSYMBOL_function_type = 67,             /* function_type  */
  YYSYMBOL_function_args = 68,             /* function_args  */
  YYSYMBOL_func_args_decleration = 69,     /* func_args_decleration  */
  YYSYMBOL_func_many_id = 70,              /* func_many_id  */
  YYSYMBOL_function_static = 71,           /* function_static  */
  YYSYMBOL_function_call = 72,             /* function_call  */
  YYSYMBOL_function_params = 73,           /* function_params  */
  YYSYMBOL_do_while_statement = 74,        /* do_while_statement  */
  YYSYMBOL_while_statement = 75,           /* while_statement  */
  YYSYMBOL_for_statement = 76,             /* for_statement  */
  YYSYMBOL_for_init = 77,                  /* for_init  */
  YYSYMBOL_for_init_many = 78,             /* for_init_many  */
  YYSYMBOL_update = 79,                    /* update  */
  YYSYMBOL_if_statement = 80,              /* if_statement  */
  YYSYMBOL_else_statement = 81,            /* else_statement  */
  YYSYMBOL_return_statement = 82,          /* return_statement  */
  YYSYMBOL_block = 83,                     /* block  */
  YYSYMBOL_func_block_contents = 84,       /* func_block_contents  */
  YYSYMBOL_block_contents = 85,            /* block_contents  */
  YYSYMBOL_statement = 86,                 /* statement  */
  YYSYMBOL_statements = 87,                /* statements  */
  YYSYMBOL_func_statement = 88,            /* func_statement  */
  YYSYMBOL_func_statements = 89,           /* func_statements  */
  YYSYMBOL_declarations = 90,              /* declarations  */
  YYSYMBOL_declaration = 91,               /* declaration  */
  YYSYMBOL_string_declaration = 92,        /* string_declaration  */
  YYSYMBOL_many_string = 93,               /* many_string  */
  YYSYMBOL_var_declaration = 94,           /* var_declaration  */
  YYSYMBOL_many_id = 95,                   /* many_id  */
  YYSYMBOL_assignment = 96,                /* assignment  */
  YYSYMBOL_param_type = 97,                /* param_type  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_value = 99                      /* value  */
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
#define YYLAST   1284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  333

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
       2,     2,     2,     2,     2,     2,     2,     2,    58,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    61,    57,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    43,    45,    46,    48,    50,    52,    54,
      57,    59,    61,    63,    67,    67,    69,    71,    72,    75,
      76,    78,    81,    82,    84,    85,    89,    91,    93,    95,
      97,    99,   104,   105,   106,   108,   109,   110,   111,   113,
     114,   115,   116,   120,   121,   123,   127,   128,   130,   132,
     133,   134,   135,   136,   137,   138,   139,   141,   142,   143,
     144,   145,   146,   147,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   165,   166,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   182,
     183,   187,   188,   190,   191,   195,   197,   205,   213,   221,
     232,   234,   235,   236,   237,   239,   240,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294
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
  "non_else", "'('", "')'", "'{'", "'}'", "':'", "'['", "']'", "'|'",
  "$accept", "program", "code", "functions", "function", "function_type",
  "function_args", "func_args_decleration", "func_many_id",
  "function_static", "function_call", "function_params",
  "do_while_statement", "while_statement", "for_statement", "for_init",
  "for_init_many", "update", "if_statement", "else_statement",
  "return_statement", "block", "func_block_contents", "block_contents",
  "statement", "statements", "func_statement", "func_statements",
  "declarations", "declaration", "string_declaration", "many_string",
  "var_declaration", "many_id", "assignment", "param_type", "expression",
  "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     163,  -241,  -241,    40,  -241,  -241,   163,   203,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,   -29,
      18,    49,    69,    -8,    -2,   233,   -30,    44,    48,    71,
    -241,    72,   357,   117,    87,    83,   402,    93,   115,   122,
     132,   129,   233,   672,  -241,  -241,   138,   141,   143,   103,
     154,   -24,   793,   -22,  -241,  -241,  -241,  -241,   -13,  -241,
    -241,  -241,  -241,   793,   267,   142,   525,  -241,  -241,  -241,
    -241,  -241,  -241,   148,   525,  -241,   444,    62,  -241,  -241,
    1049,  -241,  -241,   357,   357,   144,   793,  -241,    32,   -10,
     312,   564,  -241,  -241,  -241,  -241,   161,   642,   199,   486,
    1063,   402,   402,   164,   171,   173,   167,   176,   793,   170,
      74,    43,  -241,  1077,   357,   793,    -9,  -241,  -241,  -241,
    -241,  -241,  -241,   198,   793,  -241,  -241,   185,   823,   703,
     793,   182,   941,  -241,   177,  -241,   179,  -241,  -241,  -241,
     525,  -241,  -241,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,  -241,   189,   191,   357,  1091,
     198,   793,   200,  -241,   193,   793,   232,  -241,  -241,   793,
     793,   603,   234,  -241,   196,   201,   402,   122,   233,   207,
    -241,   955,   210,  -241,   793,  -241,   204,   973,   233,   211,
       0,   793,   209,  -241,   214,   987,   212,    91,  1231,  -241,
     213,  1019,   883,  -241,  -241,  -241,  -241,  -241,   162,   162,
    -241,  -241,   137,   137,   137,   137,   137,   137,  1245,  1231,
    -241,  -241,   205,  -241,   215,   897,  -241,  -241,  1105,   793,
    1119,  1133,   793,   249,   793,  -241,  -241,   216,  -241,  -241,
     217,   525,     8,   220,   912,   247,   525,   218,   198,   229,
     226,  1147,   793,  -241,  -241,  -241,   222,  -241,   793,   198,
    -241,  -241,   198,  -241,  1161,  -241,  -241,  1175,   793,  1189,
    -241,    39,   265,   210,   245,  -241,  -241,   244,  -241,   229,
    -241,  -241,   229,   733,  1203,   793,  -241,   235,   248,  -241,
    -241,  1217,  -241,   132,   250,   525,  -241,  -241,   210,   793,
    -241,  -241,    17,   525,   246,  1034,   763,   926,  -241,  -241,
    -241,  -241,   132,  -241,  -241,  1005,   251,  -241,   525,   853,
     525,   252,  -241,  -241,   254,   853,  -241,  -241,  -241,   525,
    -241,  -241,  -241
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    14,     0,     2,     3,     5,     0,     1,     4,
     110,   107,   109,   108,   111,   114,   113,   112,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,    68,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   153,   152,   148,   151,
     139,   140,   141,     0,     0,     0,    62,   138,    67,    66,
      65,    64,    70,     0,    77,    63,    61,    92,    94,    93,
       0,   137,    21,     0,     0,     0,     0,    82,     0,   148,
       0,     0,    81,    80,    79,    78,     0,    90,     0,     0,
       0,     0,     0,     0,    20,    18,     0,     0,     0,     0,
       0,   148,    47,     0,     0,     0,     0,   145,   146,   147,
     142,   143,   144,   118,     0,   119,   117,     0,     0,     0,
       0,     0,     0,    72,     0,    48,     0,    60,    13,    76,
      58,    59,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
     118,     0,     0,    85,     0,     0,     0,     9,    89,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
      95,     0,     0,   118,     0,    46,     0,     0,     0,     0,
      38,     0,     0,    34,     0,     0,     0,     0,   105,    23,
       0,    25,     0,    73,   134,    71,   135,    57,   128,   129,
     130,   131,   124,   122,   123,   120,   121,   125,   127,   126,
      12,    11,     0,    56,     0,     0,    86,    84,     0,     0,
       0,     0,     0,     0,     0,     8,     7,     0,    19,    17,
       0,     0,   104,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    74,   132,   133,   117,    22,     0,   136,
      10,    87,   136,    54,     0,    55,    53,     0,     0,     0,
       6,    99,    43,     0,   103,   100,   136,     0,    27,     0,
      33,    36,     0,     0,     0,     0,    24,     0,     0,    52,
      50,     0,    51,     0,    97,     0,    44,   102,     0,     0,
      32,    35,   148,     0,     0,    40,     0,     0,    75,    88,
      49,    98,     0,    45,   101,     0,    42,    31,     0,     0,
       0,     0,   106,    96,     0,     0,    30,    39,    29,     0,
      26,    41,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,  -241,    45,  -241,  -241,   276,   128,   145,   134,
    -241,    60,   -17,    -1,    59,  -241,  -220,  -187,    88,  -241,
    -241,   -80,   -89,   -27,  -119,   -51,  -241,   -88,   -34,  -241,
    -241,  -239,  -241,  -240,   -85,    -6,   -36,  -241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    66,     6,     7,    27,    30,   105,    34,
      67,   200,    68,    69,    70,   192,   193,   304,    71,   296,
      72,   134,    96,   135,    74,    75,    97,    98,    76,    77,
      78,   107,    79,   243,   131,    31,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,    20,    99,   166,   162,    73,   188,   113,    25,   168,
     164,   172,   174,   175,    25,   137,   125,    21,   128,    92,
     189,   128,   123,   139,   126,   141,    32,   132,    33,   281,
     124,   128,   127,   297,   186,    93,   109,   190,   194,   128,
       8,   129,   191,   142,   129,     5,   130,    26,   128,   161,
     159,     9,   249,    28,   311,   100,   156,   157,   314,   300,
     273,   100,   301,   100,    22,   100,   100,    99,    99,    40,
     128,   129,   181,   323,    92,   224,   184,    42,   160,   187,
      92,    91,    92,   233,    92,    92,   124,   237,   195,   207,
      93,   293,   198,   201,   202,    94,    93,   129,    93,    35,
      93,    93,   184,    23,    36,   250,    33,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   321,
     183,   140,   272,    24,    95,   225,    38,   278,   124,   228,
      39,   222,   327,   230,   231,   100,    82,   256,   331,    84,
     100,    33,    99,    83,   171,   127,    91,    91,   244,   101,
      94,   117,   118,   119,    92,   251,    94,   274,    94,    92,
      94,    94,    37,   280,   143,   144,   145,   146,   104,    85,
      93,   102,   103,    33,   287,    93,   313,   288,   106,    95,
       1,     2,   247,   108,   317,    95,   294,    95,   136,    95,
      95,   145,   146,   264,   114,   115,   267,   116,   269,   326,
     158,   328,   120,   121,   122,   138,    10,    11,    12,    13,
     332,    14,    15,    16,    17,    18,   284,   316,   167,   169,
     176,    91,   201,   177,   178,    19,   179,   180,   182,   128,
      94,   196,   291,   203,   205,    94,    10,    11,    12,    13,
     206,    14,    15,    16,    17,    18,   220,   305,   221,   307,
     227,   226,   229,   235,   234,   240,   242,   248,   236,    95,
     252,   245,   260,   315,    95,   253,   261,   255,   257,   268,
     305,   275,   277,   270,    40,   190,   279,   271,   282,   295,
      41,   285,    42,   305,     1,     2,   308,    43,    44,   305,
      45,    46,    47,    48,    49,    50,    51,   298,   299,   309,
      29,   318,   312,   325,    52,   330,   239,   329,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   286,    40,
       0,    63,   238,    64,   133,    41,     0,    42,    65,     1,
       2,     0,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    40,     0,    63,     0,    64,   163,
      41,     0,    42,    65,     1,     2,     0,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    40,
       0,    63,     0,    64,     0,    41,     0,    42,    65,     1,
       2,     0,    86,    44,     0,    87,    46,    47,    48,    49,
      50,    88,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,    53,    54,    55,    56,    57,    89,    59,
      60,    61,    62,     0,     0,     0,    63,    41,    90,     0,
       0,     1,     2,    65,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,    63,    41,
      64,     0,     0,     1,     2,    65,   170,    44,     0,    87,
      46,    47,    48,    49,    50,    88,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,    53,    54,    55,
      56,    57,    89,    59,    60,    61,    62,     0,    41,     0,
      63,     0,    90,     0,     0,    43,    44,    65,    45,    46,
      47,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    41,     0,    63,
       0,    64,     0,     0,   165,    44,    65,    87,    46,    47,
      48,    49,    50,    88,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,    53,    54,    55,    56,    57,
      89,    59,    60,    61,    62,     0,    41,     0,    63,     0,
      90,     0,     0,   232,    44,    65,    87,    46,    47,    48,
      49,    50,    88,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,    89,
      59,    60,    61,    62,     0,    41,     0,    63,     0,    90,
       0,     0,     0,    44,    65,    87,    46,    47,    48,    49,
      50,    88,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,    53,    54,    55,    56,    57,    89,    59,
      60,    61,    62,    44,     0,     0,    63,     0,    90,    49,
      50,   110,     0,    65,     0,     0,     0,     0,     0,    52,
       0,     0,     0,    53,    54,    55,    56,    57,   111,    59,
      60,    61,    62,   112,    44,     0,    63,     0,     0,     0,
      49,    50,   110,    65,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,   111,
      59,    60,    61,    62,    44,     0,     0,    63,   199,     0,
      49,    50,   110,     0,    65,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,   302,
      59,    60,    61,    62,    44,     0,     0,    63,   303,     0,
      49,    50,   110,     0,    65,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,   302,
      59,    60,    61,    62,    44,     0,     0,    63,   320,     0,
      49,    50,   110,     0,    65,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,   111,
      59,    60,    61,    62,    44,     0,     0,    63,     0,     0,
      49,    50,   110,     0,    65,     0,     0,     0,     0,     0,
      52,     0,     0,     0,   197,    54,    55,    56,    57,   111,
      59,    60,    61,    62,    44,     0,     0,    63,     0,     0,
      49,    50,   110,     0,    65,     0,     0,     0,     0,     0,
      52,     0,     0,     0,    53,    54,    55,    56,    57,   302,
      59,    60,    61,    62,     0,     0,     0,    63,     0,     0,
     143,   144,   145,   146,    65,   147,   148,   149,   150,   151,
       0,   152,   153,   154,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,     0,   152,   153,   154,     0,   143,
     144,   145,   146,   259,   147,   148,   149,   150,   151,     0,
     152,   153,   154,   143,   144,   145,   146,   262,   147,   148,
     149,   150,   151,     0,   152,   153,   154,     0,   143,   144,
     145,   146,   276,   147,   148,   149,   150,   151,     0,   152,
     153,   154,   143,   144,   145,   146,   322,   147,   148,   149,
     150,   151,     0,   152,   153,   154,   204,     0,     0,     0,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     241,   152,   153,   154,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,     0,   152,   153,   154,   246,     0,
       0,     0,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   254,   152,   153,   154,   143,   144,   145,   146,
       0,   147,   148,   149,   150,   151,     0,   152,   153,   154,
     324,   143,   144,   145,   146,     0,   147,   148,   149,   150,
     151,   258,   152,   153,   154,     0,   143,   144,   145,   146,
       0,   147,   148,   149,   150,   151,   319,   152,   153,   154,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     155,   152,   153,   154,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,   173,   152,   153,   154,   143,   144,
     145,   146,     0,   147,   148,   149,   150,   151,   185,   152,
     153,   154,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   223,   152,   153,   154,   143,   144,   145,   146,
       0,   147,   148,   149,   150,   151,   263,   152,   153,   154,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     265,   152,   153,   154,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,   266,   152,   153,   154,   143,   144,
     145,   146,     0,   147,   148,   149,   150,   151,   283,   152,
     153,   154,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   289,   152,   153,   154,   143,   144,   145,   146,
       0,   147,   148,   149,   150,   151,   290,   152,   153,   154,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     292,   152,   153,   154,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,   306,   152,   153,   154,   143,   144,
     145,   146,     0,   147,   148,   149,   150,   151,   310,   152,
     153,   154,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,     0,   152,   153
};

static const yytype_int16 yycheck[] =
{
      36,     7,    36,    91,    89,    32,    15,    43,    16,    97,
      90,    99,   101,   102,    16,    66,    52,    46,    31,    36,
      29,    31,    46,    74,    46,    76,    56,    63,    58,   249,
      54,    31,    54,   273,   114,    36,    42,    46,   123,    31,
       0,    54,    51,    77,    54,     0,    59,    55,    31,    59,
      86,     6,    52,    55,   293,    91,    83,    84,   298,   279,
      52,    97,   282,    99,    46,   101,   102,   101,   102,     7,
      31,    54,   108,   312,    91,   160,    59,    15,    46,   115,
      97,    36,    99,   171,   101,   102,    54,   176,   124,   140,
      91,    52,   128,   129,   130,    36,    97,    54,    99,    55,
     101,   102,    59,    54,    56,   190,    58,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   306,
      46,    76,   241,    54,    36,   161,    55,   246,    54,   165,
      58,   158,   319,   169,   170,   171,    19,    46,   325,    56,
     176,    58,   176,    56,    99,    54,   101,   102,   184,    56,
      91,    48,    49,    50,   171,   191,    97,   242,    99,   176,
     101,   102,    28,   248,    27,    28,    29,    30,    46,    35,
     171,    56,    38,    58,   259,   176,   295,   262,    46,    91,
      17,    18,   188,    54,   303,    97,   271,    99,    46,   101,
     102,    29,    30,   229,    56,    54,   232,    54,   234,   318,
      56,   320,    48,    49,    50,    57,     3,     4,     5,     6,
     329,     8,     9,    10,    11,    12,   252,   302,    57,    20,
      56,   176,   258,    52,    51,    22,    59,    51,    58,    31,
     171,    46,   268,    51,    57,   176,     3,     4,     5,     6,
      61,     8,     9,    10,    11,    12,    57,   283,    57,   285,
      57,    51,    20,    57,    20,    48,    46,    46,    57,   171,
      51,    57,    57,   299,   176,    51,    51,    55,    55,    20,
     306,    51,    25,    57,     7,    46,    58,    60,    52,    14,
      13,    59,    15,   319,    17,    18,    51,    20,    21,   325,
      23,    24,    25,    26,    27,    28,    29,    52,    54,    51,
      24,    55,    52,    52,    37,    51,   178,    55,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   258,     7,
      -1,    54,   177,    56,    57,    13,    -1,    15,    61,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,     7,    -1,    54,    -1,    56,    57,
      13,    -1,    15,    61,    17,    18,    -1,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,     7,
      -1,    54,    -1,    56,    -1,    13,    -1,    15,    61,    17,
      18,    -1,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    13,    56,    -1,
      -1,    17,    18,    61,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    13,
      56,    -1,    -1,    17,    18,    61,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    13,    -1,
      54,    -1,    56,    -1,    -1,    20,    21,    61,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    13,    -1,    54,
      -1,    56,    -1,    -1,    20,    21,    61,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    13,    -1,    54,    -1,
      56,    -1,    -1,    20,    21,    61,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    13,    -1,    54,    -1,    56,
      -1,    -1,    -1,    21,    61,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    21,    -1,    -1,    54,    -1,    56,    27,
      28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    21,    -1,    54,    -1,    -1,    -1,
      27,    28,    29,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    21,    -1,    -1,    54,    55,    -1,
      27,    28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    21,    -1,    -1,    54,    55,    -1,
      27,    28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    21,    -1,    -1,    54,    55,    -1,
      27,    28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    21,    -1,    -1,    54,    -1,    -1,
      27,    28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    21,    -1,    -1,    54,    -1,    -1,
      27,    28,    29,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      27,    28,    29,    30,    61,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    -1,    27,
      28,    29,    30,    60,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    27,    28,    29,    30,    60,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    -1,    27,    28,
      29,    30,    60,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    27,    28,    29,    30,    60,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    55,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      55,    38,    39,    40,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    55,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    55,    38,    39,    40,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      55,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    52,    38,    39,    40,    -1,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    52,    38,    39,    40,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      51,    38,    39,    40,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    51,    38,    39,    40,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    51,    38,
      39,    40,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    51,    38,    39,    40,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    51,    38,    39,    40,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      51,    38,    39,    40,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    51,    38,    39,    40,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    51,    38,
      39,    40,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    51,    38,    39,    40,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    51,    38,    39,    40,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      51,    38,    39,    40,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    51,    38,    39,    40,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    51,    38,
      39,    40,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    18,    63,    64,    65,    66,    67,     0,    65,
       3,     4,     5,     6,     8,     9,    10,    11,    12,    22,
      97,    46,    46,    54,    54,    16,    55,    68,    55,    68,
      69,    97,    56,    58,    71,    55,    56,    71,    55,    58,
       7,    13,    15,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    37,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    54,    56,    61,    65,    72,    74,    75,
      76,    80,    82,    85,    86,    87,    90,    91,    92,    94,
      98,    99,    19,    56,    56,    71,    20,    23,    29,    46,
      56,    65,    74,    75,    76,    80,    84,    88,    89,    90,
      98,    56,    56,    71,    46,    70,    46,    93,    54,    97,
      29,    46,    51,    98,    56,    54,    54,    48,    49,    50,
      48,    49,    50,    46,    54,    98,    46,    54,    31,    54,
      59,    96,    98,    57,    83,    85,    46,    87,    57,    87,
      65,    87,    90,    27,    28,    29,    30,    32,    33,    34,
      35,    36,    38,    39,    40,    51,    85,    85,    56,    98,
      46,    59,    96,    57,    83,    20,    89,    57,    89,    20,
      20,    65,    89,    51,    84,    84,    56,    52,    51,    59,
      51,    98,    58,    46,    59,    51,    83,    98,    15,    29,
      46,    51,    77,    78,    96,    98,    46,    41,    98,    55,
      73,    98,    98,    51,    55,    57,    61,    87,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      57,    57,    85,    51,    96,    98,    51,    57,    98,    20,
      98,    98,    20,    89,    20,    57,    57,    84,    70,    69,
      48,    55,    46,    95,    98,    57,    55,    97,    46,    52,
      96,    98,    51,    51,    55,    55,    46,    55,    52,    60,
      57,    51,    60,    51,    98,    51,    51,    98,    20,    98,
      57,    60,    86,    52,    96,    51,    60,    25,    86,    58,
      96,    78,    52,    51,    98,    59,    73,    96,    96,    51,
      51,    98,    51,    52,    96,    14,    81,    95,    52,    54,
      78,    78,    46,    55,    79,    98,    51,    98,    51,    51,
      51,    93,    52,    86,    95,    98,    96,    86,    55,    52,
      55,    79,    60,    93,    55,    52,    86,    79,    86,    55,
      51,    79,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    74,    75,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    79,    80,    80,    81,    82,    82,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    93,    93,    93,    93,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,    10,     9,     9,     8,
      10,     9,     9,     8,     1,     1,     2,     5,     3,     3,
       1,     2,     4,     3,     3,     1,     9,     5,     9,     8,
       8,     7,     4,     3,     1,     4,     3,     2,     1,     3,
       1,     4,     2,     5,     6,     2,     3,     2,     1,     6,
       5,     5,     5,     4,     4,     4,     3,     3,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     3,     4,     6,     2,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     3,     4,     6,     2,
       1,     2,     1,     1,     1,     3,     7,     5,     6,     4,
       5,     4,     3,     2,     1,     2,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     3,     4,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1
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
#line 41 "Comp.yacc"
               {(yyval.nodeval) = (yyvsp[0].nodeval); checktree((yyval.nodeval)); printtree((yyval.nodeval), 0); printf("\n 🂡 ⧓ ⧖ ⧓ ⧖ ⧓ ⧖ ⧔  Semantic Checks Passed! ⧕ ⧖ ⧓ ⧖ ⧓ ⧖ ⧓ 🂡\n"); printf("\n 🂡 ⧓ ⧖ ⧓ ⧖ ⧓ ⧖ ⧔  Created 3-Address-Code successfuly! 🐱‍🚀 ⧕ ⧖ ⧓ ⧖ ⧓ ⧖ ⧓ 🂡\n\n");}
#line 1735 "y.tab.c"
    break;

  case 3: /* code: functions  */
#line 43 "Comp.yacc"
                 {(yyval.nodeval) = mknode("CODE", (yyvsp[0].nodeval), NULL);}
#line 1741 "y.tab.c"
    break;

  case 4: /* functions: function functions  */
#line 45 "Comp.yacc"
                               {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1747 "y.tab.c"
    break;

  case 5: /* functions: function  */
#line 46 "Comp.yacc"
                   {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1753 "y.tab.c"
    break;

  case 6: /* function: function_type param_type ID '(' function_args ')' function_static '{' func_block_contents '}'  */
#line 49 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-7].strval), mknode("", (yyvsp[-9].nodeval), (yyvsp[-3].nodeval)), mknode("ARGS>>", (yyvsp[-5].nodeval), NULL)), mknode("RETURN", (yyvsp[-8].nodeval), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1759 "y.tab.c"
    break;

  case 7: /* function: function_type param_type ID '(' function_args ')' '{' func_block_contents '}'  */
#line 51 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-6].strval), mknode("", (yyvsp[-8].nodeval), NULL), mknode("ARGS>>", (yyvsp[-4].nodeval), NULL)), mknode("RETURN", (yyvsp[-7].nodeval), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1765 "y.tab.c"
    break;

  case 8: /* function: function_type param_type ID '(' ')' function_static '{' func_block_contents '}'  */
#line 53 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-6].strval), mknode("", (yyvsp[-8].nodeval), (yyvsp[-3].nodeval)), NULL), mknode("RETURN", (yyvsp[-7].nodeval), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1771 "y.tab.c"
    break;

  case 9: /* function: function_type param_type ID '(' ')' '{' func_block_contents '}'  */
#line 55 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-5].strval), mknode("", (yyvsp[-7].nodeval), NULL), NULL), mknode("RETURN", (yyvsp[-6].nodeval), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1777 "y.tab.c"
    break;

  case 10: /* function: function_type VOID ID '(' function_args ')' function_static '{' block_contents '}'  */
#line 58 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-7].strval), mknode("", (yyvsp[-9].nodeval), (yyvsp[-3].nodeval)), mknode("ARGS>>", (yyvsp[-5].nodeval), NULL)), mknode("RETURN", mknode((yyvsp[-8].strval), NULL, NULL), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1783 "y.tab.c"
    break;

  case 11: /* function: function_type VOID ID '(' function_args ')' '{' block_contents '}'  */
#line 60 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-6].strval), mknode("", (yyvsp[-8].nodeval), NULL), mknode("ARGS>>", (yyvsp[-4].nodeval), NULL)), mknode("RETURN", mknode((yyvsp[-7].strval), NULL, NULL), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1789 "y.tab.c"
    break;

  case 12: /* function: function_type VOID ID '(' ')' function_static '{' block_contents '}'  */
#line 62 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-6].strval), mknode("", (yyvsp[-8].nodeval), (yyvsp[-3].nodeval)), NULL), mknode("RETURN", mknode((yyvsp[-7].strval), NULL, NULL), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1795 "y.tab.c"
    break;

  case 13: /* function: function_type VOID ID '(' ')' '{' block_contents '}'  */
#line 64 "Comp.yacc"
            {(yyval.nodeval) = mknode("FUNCTION", mknode((yyvsp[-5].strval), mknode("", (yyvsp[-7].nodeval), NULL), NULL), mknode("RETURN", mknode((yyvsp[-6].strval), NULL, NULL), mknode("FUNCTION BLOCK", (yyvsp[-1].nodeval), NULL)));}
#line 1801 "y.tab.c"
    break;

  case 14: /* function_type: PRIVATE  */
#line 67 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1807 "y.tab.c"
    break;

  case 15: /* function_type: PUBLIC  */
#line 67 "Comp.yacc"
                                                                {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1813 "y.tab.c"
    break;

  case 16: /* function_args: ARGS func_args_decleration  */
#line 69 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1819 "y.tab.c"
    break;

  case 17: /* func_args_decleration: param_type ':' func_many_id ';' func_args_decleration  */
#line 71 "Comp.yacc"
                                                                              {(yyval.nodeval) = mknode("VAR", mknode("", (yyvsp[-4].nodeval), (yyvsp[-2].nodeval)), (yyvsp[0].nodeval));}
#line 1825 "y.tab.c"
    break;

  case 18: /* func_args_decleration: param_type ':' func_many_id  */
#line 72 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode("VAR", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1831 "y.tab.c"
    break;

  case 19: /* func_many_id: ID ',' func_many_id  */
#line 75 "Comp.yacc"
                                   {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1837 "y.tab.c"
    break;

  case 20: /* func_many_id: ID  */
#line 76 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1843 "y.tab.c"
    break;

  case 21: /* function_static: ':' STATIC  */
#line 78 "Comp.yacc"
                             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1849 "y.tab.c"
    break;

  case 22: /* function_call: ID '(' function_params ')'  */
#line 81 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("FUNCTION CALL", mknode((yyvsp[-3].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 1855 "y.tab.c"
    break;

  case 23: /* function_call: ID '(' ')'  */
#line 82 "Comp.yacc"
                             {(yyval.nodeval) = mknode("FUNCTION CALL", mknode((yyvsp[-2].strval), NULL, NULL), NULL);}
#line 1861 "y.tab.c"
    break;

  case 24: /* function_params: expression ',' function_params  */
#line 84 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("EXPRESSION", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1867 "y.tab.c"
    break;

  case 25: /* function_params: expression  */
#line 85 "Comp.yacc"
                             {(yyval.nodeval) = mknode("EXPRESSION", (yyvsp[0].nodeval), NULL);}
#line 1873 "y.tab.c"
    break;

  case 26: /* do_while_statement: DO '{' block '}' WHILE '(' expression ')' ';'  */
#line 89 "Comp.yacc"
                                                                   {(yyval.nodeval) = mknode("DO WHILE", (yyvsp[-6].nodeval), mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL));}
#line 1879 "y.tab.c"
    break;

  case 27: /* while_statement: WHILE '(' expression ')' statement  */
#line 91 "Comp.yacc"
                                                     {(yyval.nodeval) = mknode((yyvsp[-4].strval), mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval));}
#line 1885 "y.tab.c"
    break;

  case 28: /* for_statement: FOR '(' for_init ';' expression ';' update ')' statement  */
#line 94 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[-8].strval), mknode("FOR INIT", (yyvsp[-6].nodeval), mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL))), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1891 "y.tab.c"
    break;

  case 29: /* for_statement: FOR '(' for_init ';' expression ';' ')' statement  */
#line 96 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[-7].strval), mknode("FOR INIT", (yyvsp[-5].nodeval), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1897 "y.tab.c"
    break;

  case 30: /* for_statement: FOR '(' ';' expression ';' update ')' statement  */
#line 98 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[-7].strval), mknode("EXPRESSION", (yyvsp[-4].nodeval), mknode("UPDATE", (yyvsp[-2].nodeval), NULL)), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1903 "y.tab.c"
    break;

  case 31: /* for_statement: FOR '(' ';' expression ';' ')' statement  */
#line 100 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[-6].strval), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL), mknode("FOR BLOCK", (yyvsp[0].nodeval), NULL));}
#line 1909 "y.tab.c"
    break;

  case 32: /* for_init: VAR param_type ':' for_init_many  */
#line 104 "Comp.yacc"
                                            {(yyval.nodeval) = mknode("VAR", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1915 "y.tab.c"
    break;

  case 33: /* for_init: MULT ID assignment  */
#line 105 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("* ID ASSIGN", mknode((yyvsp[-1].strval), NULL, NULL), (yyvsp[0].nodeval));}
#line 1921 "y.tab.c"
    break;

  case 34: /* for_init: for_init_many  */
#line 106 "Comp.yacc"
                            {(yyval.nodeval) = mknode("FOR INIT", (yyvsp[0].nodeval), NULL);}
#line 1927 "y.tab.c"
    break;

  case 35: /* for_init_many: ID assignment ',' for_init_many  */
#line 108 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("", mknode("ID ASSIGN", mknode((yyvsp[-3].strval), NULL, NULL), (yyvsp[-2].nodeval)), mknode("FOR INIT", (yyvsp[0].nodeval), NULL));}
#line 1933 "y.tab.c"
    break;

  case 36: /* for_init_many: ID ',' for_init_many  */
#line 109 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("", mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[-2].strval), NULL, NULL), NULL), NULL), NULL), mknode("FOR INIT", (yyvsp[0].nodeval), NULL));}
#line 1939 "y.tab.c"
    break;

  case 37: /* for_init_many: ID assignment  */
#line 110 "Comp.yacc"
                          {(yyval.nodeval) = mknode("ID ASSIGN", mknode((yyvsp[-1].strval), NULL, NULL), (yyvsp[0].nodeval));}
#line 1945 "y.tab.c"
    break;

  case 38: /* for_init_many: ID  */
#line 111 "Comp.yacc"
               {(yyval.nodeval) = mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[0].strval), NULL, NULL), NULL), NULL), NULL);}
#line 1951 "y.tab.c"
    break;

  case 39: /* update: expression ',' update  */
#line 113 "Comp.yacc"
                               {(yyval.nodeval) = mknode("", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("UPDATE", (yyvsp[0].nodeval), NULL));}
#line 1957 "y.tab.c"
    break;

  case 40: /* update: expression  */
#line 114 "Comp.yacc"
                     {(yyval.nodeval) = mknode("EXPRESSION", (yyvsp[0].nodeval), NULL);}
#line 1963 "y.tab.c"
    break;

  case 41: /* update: ID assignment ',' update  */
#line 115 "Comp.yacc"
                                   {(yyval.nodeval) = mknode("", mknode("ID ASSIGN", mknode((yyvsp[-3].strval), NULL, NULL), (yyvsp[-2].nodeval)), mknode("UPDATE", (yyvsp[0].nodeval), NULL));}
#line 1969 "y.tab.c"
    break;

  case 42: /* update: ID assignment  */
#line 116 "Comp.yacc"
                        {(yyval.nodeval) = mknode("ID ASSIGN", mknode((yyvsp[-1].strval), NULL, NULL), (yyvsp[0].nodeval));}
#line 1975 "y.tab.c"
    break;

  case 43: /* if_statement: IF '(' expression ')' statement  */
#line 120 "Comp.yacc"
                                                              {(yyval.nodeval) = mknode((yyvsp[-4].strval), mknode("", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval)), NULL);}
#line 1981 "y.tab.c"
    break;

  case 44: /* if_statement: IF '(' expression ')' statement else_statement  */
#line 121 "Comp.yacc"
                                                                 {(yyval.nodeval) = mknode((yyvsp[-5].strval), mknode("",mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL), (yyvsp[-1].nodeval)), mknode("ELSE", (yyvsp[0].nodeval), NULL));}
#line 1987 "y.tab.c"
    break;

  case 45: /* else_statement: ELSE statement  */
#line 123 "Comp.yacc"
                                {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 1993 "y.tab.c"
    break;

  case 46: /* return_statement: RETURN expression ';'  */
#line 127 "Comp.yacc"
                                         {(yyval.nodeval) = mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL);}
#line 1999 "y.tab.c"
    break;

  case 47: /* return_statement: RETURN ';'  */
#line 128 "Comp.yacc"
                              {(yyval.nodeval) = mknode((yyvsp[-1].strval), NULL, NULL);}
#line 2005 "y.tab.c"
    break;

  case 48: /* block: block_contents  */
#line 130 "Comp.yacc"
                       {(yyval.nodeval) = mknode("BLOCK", (yyvsp[0].nodeval), NULL);}
#line 2011 "y.tab.c"
    break;

  case 49: /* func_block_contents: declarations functions func_statements RETURN expression ';'  */
#line 132 "Comp.yacc"
                                                                                   {(yyval.nodeval) = mknode("", mknode("", mknode("", (yyvsp[-5].nodeval), (yyvsp[-4].nodeval)), (yyvsp[-3].nodeval)), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2017 "y.tab.c"
    break;

  case 50: /* func_block_contents: declarations functions RETURN expression ';'  */
#line 133 "Comp.yacc"
                                                               {(yyval.nodeval) = mknode("", mknode("", (yyvsp[-4].nodeval), (yyvsp[-3].nodeval)), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2023 "y.tab.c"
    break;

  case 51: /* func_block_contents: declarations func_statements RETURN expression ';'  */
#line 134 "Comp.yacc"
                                                                     {(yyval.nodeval) = mknode("", mknode("", (yyvsp[-4].nodeval), (yyvsp[-3].nodeval)), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2029 "y.tab.c"
    break;

  case 52: /* func_block_contents: functions func_statements RETURN expression ';'  */
#line 135 "Comp.yacc"
                                                                  {(yyval.nodeval) = mknode("", mknode("", (yyvsp[-4].nodeval), (yyvsp[-3].nodeval)), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2035 "y.tab.c"
    break;

  case 53: /* func_block_contents: declarations RETURN expression ';'  */
#line 136 "Comp.yacc"
                                                     {(yyval.nodeval) = mknode("", (yyvsp[-3].nodeval), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2041 "y.tab.c"
    break;

  case 54: /* func_block_contents: functions RETURN expression ';'  */
#line 137 "Comp.yacc"
                                                  {(yyval.nodeval) = mknode("", (yyvsp[-3].nodeval), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2047 "y.tab.c"
    break;

  case 55: /* func_block_contents: func_statements RETURN expression ';'  */
#line 138 "Comp.yacc"
                                                        {(yyval.nodeval) = mknode("", (yyvsp[-3].nodeval), mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL));}
#line 2053 "y.tab.c"
    break;

  case 56: /* func_block_contents: RETURN expression ';'  */
#line 139 "Comp.yacc"
                                        {(yyval.nodeval) = mknode((yyvsp[-2].strval), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL);}
#line 2059 "y.tab.c"
    break;

  case 57: /* block_contents: declarations functions statements  */
#line 141 "Comp.yacc"
                                                   {(yyval.nodeval) = mknode("", mknode("", (yyvsp[-2].nodeval), (yyvsp[-1].nodeval)), (yyvsp[0].nodeval));}
#line 2065 "y.tab.c"
    break;

  case 58: /* block_contents: declarations functions  */
#line 142 "Comp.yacc"
                                         {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2071 "y.tab.c"
    break;

  case 59: /* block_contents: declarations statements  */
#line 143 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2077 "y.tab.c"
    break;

  case 60: /* block_contents: functions statements  */
#line 144 "Comp.yacc"
                                       {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2083 "y.tab.c"
    break;

  case 61: /* block_contents: declarations  */
#line 145 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2089 "y.tab.c"
    break;

  case 62: /* block_contents: functions  */
#line 146 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2095 "y.tab.c"
    break;

  case 63: /* block_contents: statements  */
#line 147 "Comp.yacc"
                             {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2101 "y.tab.c"
    break;

  case 64: /* statement: if_statement  */
#line 150 "Comp.yacc"
                         {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2107 "y.tab.c"
    break;

  case 65: /* statement: for_statement  */
#line 151 "Comp.yacc"
                        {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2113 "y.tab.c"
    break;

  case 66: /* statement: while_statement  */
#line 152 "Comp.yacc"
                          {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2119 "y.tab.c"
    break;

  case 67: /* statement: do_while_statement  */
#line 153 "Comp.yacc"
                             {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2125 "y.tab.c"
    break;

  case 68: /* statement: COMMENT  */
#line 154 "Comp.yacc"
                  {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2131 "y.tab.c"
    break;

  case 69: /* statement: expression ';'  */
#line 155 "Comp.yacc"
                         {(yyval.nodeval) = mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL);}
#line 2137 "y.tab.c"
    break;

  case 70: /* statement: return_statement  */
#line 156 "Comp.yacc"
                           {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2143 "y.tab.c"
    break;

  case 71: /* statement: '{' block '}'  */
#line 157 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[-1].nodeval);}
#line 2149 "y.tab.c"
    break;

  case 72: /* statement: '{' '}'  */
#line 158 "Comp.yacc"
                  {(yyval.nodeval) = mknode("",NULL,NULL);}
#line 2155 "y.tab.c"
    break;

  case 73: /* statement: ID assignment ';'  */
#line 159 "Comp.yacc"
                            {(yyval.nodeval) = mknode("ID ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2161 "y.tab.c"
    break;

  case 74: /* statement: MULT ID assignment ';'  */
#line 160 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("* ID ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2167 "y.tab.c"
    break;

  case 75: /* statement: ID '[' expression ']' assignment ';'  */
#line 161 "Comp.yacc"
                                               {(yyval.nodeval) = mknode("ASSIGN[]", mknode("ID", mknode((yyvsp[-5].strval), NULL, NULL), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL)), mknode("", (yyvsp[-1].nodeval), NULL));}
#line 2173 "y.tab.c"
    break;

  case 76: /* statements: statement statements  */
#line 165 "Comp.yacc"
                                  {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2179 "y.tab.c"
    break;

  case 77: /* statements: statement  */
#line 166 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2185 "y.tab.c"
    break;

  case 78: /* func_statement: if_statement  */
#line 169 "Comp.yacc"
                              {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2191 "y.tab.c"
    break;

  case 79: /* func_statement: for_statement  */
#line 170 "Comp.yacc"
                        {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2197 "y.tab.c"
    break;

  case 80: /* func_statement: while_statement  */
#line 171 "Comp.yacc"
                          {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2203 "y.tab.c"
    break;

  case 81: /* func_statement: do_while_statement  */
#line 172 "Comp.yacc"
                             {(yyval.nodeval) = mknode("",(yyvsp[0].nodeval),NULL);}
#line 2209 "y.tab.c"
    break;

  case 82: /* func_statement: COMMENT  */
#line 173 "Comp.yacc"
                  {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2215 "y.tab.c"
    break;

  case 83: /* func_statement: expression ';'  */
#line 174 "Comp.yacc"
                         {(yyval.nodeval) = mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL);}
#line 2221 "y.tab.c"
    break;

  case 84: /* func_statement: '{' block '}'  */
#line 175 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[-1].nodeval);}
#line 2227 "y.tab.c"
    break;

  case 85: /* func_statement: '{' '}'  */
#line 176 "Comp.yacc"
                  {(yyval.nodeval) = mknode("",NULL,NULL);}
#line 2233 "y.tab.c"
    break;

  case 86: /* func_statement: ID assignment ';'  */
#line 177 "Comp.yacc"
                            {(yyval.nodeval) = mknode("ID ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2239 "y.tab.c"
    break;

  case 87: /* func_statement: MULT ID assignment ';'  */
#line 178 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("* ID ASSIGN", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 2245 "y.tab.c"
    break;

  case 88: /* func_statement: ID '[' expression ']' assignment ';'  */
#line 179 "Comp.yacc"
                                               {(yyval.nodeval) = mknode("ASSIGN[]", mknode("ID", mknode((yyvsp[-5].strval), NULL, NULL), mknode("EXPRESSION", (yyvsp[-3].nodeval), NULL)), mknode("", (yyvsp[-1].nodeval), NULL));}
#line 2251 "y.tab.c"
    break;

  case 89: /* func_statements: func_statement func_statements  */
#line 182 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2257 "y.tab.c"
    break;

  case 90: /* func_statements: func_statement  */
#line 183 "Comp.yacc"
                         {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2263 "y.tab.c"
    break;

  case 91: /* declarations: declaration declarations  */
#line 187 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("DECLERATION", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 2269 "y.tab.c"
    break;

  case 92: /* declarations: declaration  */
#line 188 "Comp.yacc"
                      {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2275 "y.tab.c"
    break;

  case 93: /* declaration: var_declaration  */
#line 190 "Comp.yacc"
                              {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2281 "y.tab.c"
    break;

  case 94: /* declaration: string_declaration  */
#line 191 "Comp.yacc"
                             {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2287 "y.tab.c"
    break;

  case 95: /* string_declaration: STRING many_string ';'  */
#line 195 "Comp.yacc"
                                             {(yyval.nodeval) = mknode("STRING", (yyvsp[-1].nodeval), NULL);}
#line 2293 "y.tab.c"
    break;

  case 96: /* many_string: ID '[' INT_VAL ']' assignment ',' many_string  */
#line 198 "Comp.yacc"
                {(yyval.nodeval) = mknode("", 
                                mknode("", 
                                        mknode("", 
                                                mknode((yyvsp[-6].strval), NULL, NULL), 
                                                mknode((yyvsp[-4].strval), NULL, NULL)),
                                        mknode("", (yyvsp[-2].nodeval), NULL)), 
                                mknode("", (yyvsp[0].nodeval), NULL));}
#line 2305 "y.tab.c"
    break;

  case 97: /* many_string: ID '[' INT_VAL ']' assignment  */
#line 206 "Comp.yacc"
                {(yyval.nodeval) = mknode("", 
                                mknode("", 
                                        mknode("", 
                                                mknode((yyvsp[-4].strval), NULL, NULL), 
                                                mknode((yyvsp[-2].strval), NULL, NULL)),
                                        mknode("", (yyvsp[0].nodeval), NULL)), 
                                mknode("", NULL, NULL));}
#line 2317 "y.tab.c"
    break;

  case 98: /* many_string: ID '[' INT_VAL ']' ',' many_string  */
#line 214 "Comp.yacc"
                {(yyval.nodeval) = mknode("", 
                                mknode("", 
                                        mknode("", 
                                                mknode((yyvsp[-5].strval), NULL, NULL), 
                                                mknode((yyvsp[-3].strval), NULL, NULL)),
                                        mknode("", NULL, NULL)), 
                                mknode("", (yyvsp[0].nodeval), NULL));}
#line 2329 "y.tab.c"
    break;

  case 99: /* many_string: ID '[' INT_VAL ']'  */
#line 222 "Comp.yacc"
                {(yyval.nodeval) = mknode("", 
                                mknode("", 
                                        mknode("", 
                                                mknode((yyvsp[-3].strval), NULL, NULL), 
                                                mknode((yyvsp[-1].strval), NULL, NULL)),
                                        mknode("", NULL, NULL)), 
                                mknode("", NULL, NULL));}
#line 2341 "y.tab.c"
    break;

  case 100: /* var_declaration: VAR param_type ':' many_id ';'  */
#line 232 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("VAR", (yyvsp[-3].nodeval), (yyvsp[-1].nodeval));}
#line 2347 "y.tab.c"
    break;

  case 101: /* many_id: ID assignment ',' many_id  */
#line 234 "Comp.yacc"
                                    {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2353 "y.tab.c"
    break;

  case 102: /* many_id: ID ',' many_id  */
#line 235 "Comp.yacc"
                           {(yyval.nodeval) = mknode((yyvsp[-2].strval), NULL, (yyvsp[0].nodeval));}
#line 2359 "y.tab.c"
    break;

  case 103: /* many_id: ID assignment  */
#line 236 "Comp.yacc"
                          {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 2365 "y.tab.c"
    break;

  case 104: /* many_id: ID  */
#line 237 "Comp.yacc"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2371 "y.tab.c"
    break;

  case 105: /* assignment: ASSIGN expression  */
#line 239 "Comp.yacc"
                               {(yyval.nodeval) = mknode("ASSIGN",mknode("EXPRESSION", (yyvsp[0].nodeval), NULL),NULL);}
#line 2377 "y.tab.c"
    break;

  case 106: /* assignment: ASSIGN ADDRESS ID '[' expression ']'  */
#line 240 "Comp.yacc"
                                               {(yyval.nodeval) = mknode("&ID[]", mknode("ID", mknode((yyvsp[-3].strval), NULL, NULL), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL)), NULL);}
#line 2383 "y.tab.c"
    break;

  case 107: /* param_type: INT  */
#line 244 "Comp.yacc"
                 {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2389 "y.tab.c"
    break;

  case 108: /* param_type: FLOAT  */
#line 245 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2395 "y.tab.c"
    break;

  case 109: /* param_type: DOUBLE  */
#line 246 "Comp.yacc"
                      {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2401 "y.tab.c"
    break;

  case 110: /* param_type: CHAR  */
#line 247 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2407 "y.tab.c"
    break;

  case 111: /* param_type: INT_PTR  */
#line 248 "Comp.yacc"
                       {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2413 "y.tab.c"
    break;

  case 112: /* param_type: FLOAT_PTR  */
#line 249 "Comp.yacc"
                         {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2419 "y.tab.c"
    break;

  case 113: /* param_type: DOUBLE_PTR  */
#line 250 "Comp.yacc"
                          {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2425 "y.tab.c"
    break;

  case 114: /* param_type: CHAR_PTR  */
#line 251 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2431 "y.tab.c"
    break;

  case 115: /* param_type: BOOL  */
#line 252 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2437 "y.tab.c"
    break;

  case 116: /* expression: NULL_VALUE  */
#line 255 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2443 "y.tab.c"
    break;

  case 117: /* expression: ADDRESS ID  */
#line 256 "Comp.yacc"
                         {(yyval.nodeval) = mknode("&", mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[0].strval), NULL, NULL), NULL), NULL), NULL), NULL);}
#line 2449 "y.tab.c"
    break;

  case 118: /* expression: MULT ID  */
#line 257 "Comp.yacc"
                      {(yyval.nodeval) = mknode("* (pointer)", mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[0].strval), NULL, NULL), NULL), NULL), NULL), NULL);}
#line 2455 "y.tab.c"
    break;

  case 119: /* expression: NOT expression  */
#line 258 "Comp.yacc"
                             {(yyval.nodeval) = mknode("! (not)", mknode("EXPRESSION", (yyvsp[0].nodeval), NULL), NULL);}
#line 2461 "y.tab.c"
    break;

  case 120: /* expression: expression LESSER expression  */
#line 259 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("<", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2467 "y.tab.c"
    break;

  case 121: /* expression: expression LESSER_EQ expression  */
#line 260 "Comp.yacc"
                                              {(yyval.nodeval) = mknode("<=", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2473 "y.tab.c"
    break;

  case 122: /* expression: expression GREATER expression  */
#line 261 "Comp.yacc"
                                            {(yyval.nodeval) = mknode(">", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2479 "y.tab.c"
    break;

  case 123: /* expression: expression GREATER_EQ expression  */
#line 262 "Comp.yacc"
                                               {(yyval.nodeval) = mknode(">=", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2485 "y.tab.c"
    break;

  case 124: /* expression: expression EQUAL expression  */
#line 263 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("==", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2491 "y.tab.c"
    break;

  case 125: /* expression: expression NOT_EQ expression  */
#line 264 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("!=", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2497 "y.tab.c"
    break;

  case 126: /* expression: expression OR expression  */
#line 265 "Comp.yacc"
                                       {(yyval.nodeval) = mknode("||", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2503 "y.tab.c"
    break;

  case 127: /* expression: expression AND expression  */
#line 266 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("&&", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2509 "y.tab.c"
    break;

  case 128: /* expression: expression ADD expression  */
#line 267 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("+", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2515 "y.tab.c"
    break;

  case 129: /* expression: expression SUB expression  */
#line 268 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("-", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2521 "y.tab.c"
    break;

  case 130: /* expression: expression MULT expression  */
#line 269 "Comp.yacc"
                                         {(yyval.nodeval) = mknode("*", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2527 "y.tab.c"
    break;

  case 131: /* expression: expression DIVIDE expression  */
#line 270 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("/", mknode("EXPRESSION", (yyvsp[-2].nodeval), NULL), mknode("EXPRESSION", (yyvsp[0].nodeval), NULL));}
#line 2533 "y.tab.c"
    break;

  case 132: /* expression: MULT '(' expression ')'  */
#line 271 "Comp.yacc"
                                      {(yyval.nodeval) = mknode("* (pointer)", mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL);}
#line 2539 "y.tab.c"
    break;

  case 133: /* expression: ADDRESS '(' ID ')'  */
#line 272 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("&", mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[-1].strval), NULL, NULL), NULL), NULL), NULL), NULL);}
#line 2545 "y.tab.c"
    break;

  case 134: /* expression: '(' expression ')'  */
#line 273 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("( )", mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL), NULL);}
#line 2551 "y.tab.c"
    break;

  case 135: /* expression: '|' ID '|'  */
#line 274 "Comp.yacc"
                         {(yyval.nodeval) = mknode("| |", mknode("EXPRESSION", mknode("VALUE", mknode("ID", mknode((yyvsp[-1].strval), NULL, NULL), NULL), NULL), NULL), NULL);}
#line 2557 "y.tab.c"
    break;

  case 136: /* expression: ID '[' expression ']'  */
#line 275 "Comp.yacc"
                                    {(yyval.nodeval) = mknode("ID[]", mknode("ID", mknode((yyvsp[-3].strval), NULL, NULL), mknode("EXPRESSION", (yyvsp[-1].nodeval), NULL)), NULL);}
#line 2563 "y.tab.c"
    break;

  case 137: /* expression: value  */
#line 276 "Comp.yacc"
                    {(yyval.nodeval) = mknode("VALUE", (yyvsp[0].nodeval), NULL);}
#line 2569 "y.tab.c"
    break;

  case 138: /* expression: function_call  */
#line 277 "Comp.yacc"
                            {(yyval.nodeval) = mknode("", (yyvsp[0].nodeval), NULL);}
#line 2575 "y.tab.c"
    break;

  case 139: /* value: INT_VAL  */
#line 280 "Comp.yacc"
                {(yyval.nodeval) = mknode("INT", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2581 "y.tab.c"
    break;

  case 140: /* value: FLOAT_VAL  */
#line 281 "Comp.yacc"
                    {(yyval.nodeval) = mknode("FLOAT", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2587 "y.tab.c"
    break;

  case 141: /* value: DOUBLE_VAL  */
#line 282 "Comp.yacc"
                     {(yyval.nodeval) = mknode("DOUBLE", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2593 "y.tab.c"
    break;

  case 142: /* value: SUB INT_VAL  */
#line 283 "Comp.yacc"
                      {(yyval.nodeval) = mknode("INT", mknode(concat("-",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2599 "y.tab.c"
    break;

  case 143: /* value: SUB FLOAT_VAL  */
#line 284 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FLOAT", mknode(concat("-",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2605 "y.tab.c"
    break;

  case 144: /* value: SUB DOUBLE_VAL  */
#line 285 "Comp.yacc"
                         {(yyval.nodeval) = mknode("DOUBLE", mknode(concat("-",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2611 "y.tab.c"
    break;

  case 145: /* value: ADD INT_VAL  */
#line 286 "Comp.yacc"
                      {(yyval.nodeval) = mknode("INT", mknode(concat("+",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2617 "y.tab.c"
    break;

  case 146: /* value: ADD FLOAT_VAL  */
#line 287 "Comp.yacc"
                        {(yyval.nodeval) = mknode("FLOAT", mknode(concat("+",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2623 "y.tab.c"
    break;

  case 147: /* value: ADD DOUBLE_VAL  */
#line 288 "Comp.yacc"
                         {(yyval.nodeval) = mknode("DOUBLE", mknode(concat("+",(yyvsp[0].strval)), NULL, NULL), NULL);}
#line 2629 "y.tab.c"
    break;

  case 148: /* value: ID  */
#line 289 "Comp.yacc"
             {(yyval.nodeval) = mknode("ID", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2635 "y.tab.c"
    break;

  case 149: /* value: TRUE_VAL  */
#line 290 "Comp.yacc"
                   {(yyval.nodeval) = mknode("BOOL", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2641 "y.tab.c"
    break;

  case 150: /* value: FALSE_VAL  */
#line 291 "Comp.yacc"
                    {(yyval.nodeval) = mknode("BOOL", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2647 "y.tab.c"
    break;

  case 151: /* value: CHAR_VAL  */
#line 292 "Comp.yacc"
                   {(yyval.nodeval) = mknode("CHAR", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2653 "y.tab.c"
    break;

  case 152: /* value: STRING_VAL  */
#line 293 "Comp.yacc"
                     {(yyval.nodeval) = mknode("STRING", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2659 "y.tab.c"
    break;

  case 153: /* value: HEX_VAL  */
#line 294 "Comp.yacc"
                  {(yyval.nodeval) = mknode("INT", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2665 "y.tab.c"
    break;


#line 2669 "y.tab.c"

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

#line 296 "Comp.yacc"

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
