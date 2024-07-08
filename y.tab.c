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

    #include "Helper.c"

#line 75 "y.tab.c"

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
#line 4 "Comp.yacc"

    int intval;
    int* intptr;
    float floatval;
    float* floatptr;
    double doubleval;
    double* doubleptr;
    char charval;
    char* strval;
    node* nodeval;

#line 239 "y.tab.c"

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
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_function_type = 65,             /* function_type  */
  YYSYMBOL_function_return_type = 66,      /* function_return_type  */
  YYSYMBOL_function_args = 67,             /* function_args  */
  YYSYMBOL_func_args_decleration = 68,     /* func_args_decleration  */
  YYSYMBOL_func_many_id = 69,              /* func_many_id  */
  YYSYMBOL_function_static = 70,           /* function_static  */
  YYSYMBOL_function_block = 71,            /* function_block  */
  YYSYMBOL_function_return = 72,           /* function_return  */
  YYSYMBOL_function_call = 73,             /* function_call  */
  YYSYMBOL_function_params = 74,           /* function_params  */
  YYSYMBOL_do_while_statement = 75,        /* do_while_statement  */
  YYSYMBOL_while_statement = 76,           /* while_statement  */
  YYSYMBOL_for_statement = 77,             /* for_statement  */
  YYSYMBOL_for_init = 78,                  /* for_init  */
  YYSYMBOL_for_init_many = 79,             /* for_init_many  */
  YYSYMBOL_update = 80,                    /* update  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_else_statement = 82,            /* else_statement  */
  YYSYMBOL_block = 83,                     /* block  */
  YYSYMBOL_statement_recursive = 84,       /* statement_recursive  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_string_assignment = 86,         /* string_assignment  */
  YYSYMBOL_many_string = 87,               /* many_string  */
  YYSYMBOL_var_assignment = 88,            /* var_assignment  */
  YYSYMBOL_many_id = 89,                   /* many_id  */
  YYSYMBOL_assign_statement = 90,          /* assign_statement  */
  YYSYMBOL_param_type = 91,                /* param_type  */
  YYSYMBOL_expression = 92,                /* expression  */
  YYSYMBOL_value = 93                      /* value  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

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
       0,    37,    37,    42,    44,    46,    49,    50,    52,    53,
      54,    56,    58,    59,    60,    61,    64,    65,    67,    69,
      70,    71,    72,    74,    79,    80,    82,    83,    91,    93,
      95,    97,    99,   101,   106,   107,   108,   110,   111,   112,
     114,   115,   120,   121,   123,   128,   129,   131,   132,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   147,   148,
     150,   152,   154,   156,   161,   162,   163,   165,   166,   167,
     168,   170,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222
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
  "$accept", "program", "function", "function_type",
  "function_return_type", "function_args", "func_args_decleration",
  "func_many_id", "function_static", "function_block", "function_return",
  "function_call", "function_params", "do_while_statement",
  "while_statement", "for_statement", "for_init", "for_init_many",
  "update", "if_statement", "else_statement", "block",
  "statement_recursive", "statement", "string_assignment", "many_string",
  "var_assignment", "many_id", "assign_statement", "param_type",
  "expression", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-185)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,  -185,  -185,    18,  -185,   644,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,   -23,  -185,
     -33,   -12,   673,   -30,    -2,   -17,  -185,    -5,   156,  -185,
      15,   -14,   -14,    12,     8,   683,   438,  -185,  -185,   254,
      37,    38,     7,    20,    48,   438,    53,  -185,  -185,  -185,
    -185,   -24,  -185,  -185,  -185,  -185,   438,  -185,   438,  -185,
      35,  -185,  -185,  -185,  -185,  -185,   205,  -185,  -185,  -185,
     592,  -185,    81,   -30,  -185,    14,    51,    54,    45,    57,
     438,    64,    63,    67,   606,   348,    97,  -185,   438,    -1,
    -185,  -185,  -185,  -185,  -185,  -185,    94,  -185,  -185,   438,
      69,   438,    75,   498,   468,  -185,  -185,    70,  -185,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,  -185,  -185,  -185,   -14,   673,   673,    79,  -185,   516,
      83,  -185,  -185,   299,    77,   530,   683,    87,   -18,   438,
      84,  -185,    86,   635,  -185,    85,   562,   482,  -185,  -185,
    -185,  -185,   116,   116,   664,   664,    47,    47,    47,    47,
      47,    47,  -185,  -185,  -185,  -185,  -185,    74,   254,   -16,
      88,  -185,   438,   254,    82,   110,    96,    91,   102,   577,
     438,  -185,  -185,   438,   127,   -15,   145,    83,   112,  -185,
     548,  -185,    96,   438,  -185,    96,   378,   438,   111,  -185,
     118,    12,   114,   254,  -185,  -185,    83,   117,  -185,   635,
    -185,   254,   115,  -185,   408,   121,  -185,    12,  -185,  -185,
    -185,  -185,   254,   254,   120,  -185,  -185,  -185,  -185,   254,
    -185
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     6,     0,     2,     0,     1,    75,    72,    74,
      73,     9,    76,    79,    78,    77,    80,    10,     0,     8,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,    81,    56,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   115,
     114,   110,   113,   101,   102,   103,     0,    22,     0,    55,
       0,   100,    54,    53,    52,    51,     0,    47,    50,    49,
       0,    99,     0,     0,     4,    17,    15,    13,     0,     0,
       0,     0,     0,   110,     0,     0,     0,    45,     0,     0,
     107,   108,   109,   104,   105,   106,    83,    84,    82,     0,
       0,     0,     0,     0,     0,    21,    20,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    18,     3,     0,     0,     0,     0,    58,     0,
       0,    83,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    71,    25,     0,    27,     0,    65,    97,
      98,    19,    93,    94,    95,    96,    89,    87,    88,    85,
      86,    90,    92,    91,    16,    14,    12,     0,     0,    70,
       0,    46,     0,     0,     0,     0,     0,    39,     0,    41,
       0,    66,    24,     0,     0,    63,    42,     0,    69,    64,
       0,    29,     0,     0,    38,     0,     0,     0,     0,    26,
       0,     0,    61,     0,    43,    68,     0,     0,    34,    35,
      37,     0,     0,    40,     0,     0,    62,     0,    44,    67,
      28,    33,     0,     0,     0,    59,    60,    32,    31,     0,
      30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,   167,  -185,  -185,  -185,   -37,   -29,  -185,   -25,
     122,  -185,     3,  -185,  -185,  -185,  -185,  -166,  -172,  -185,
    -185,  -162,   104,   -26,  -185,  -184,  -185,  -168,   -84,    -4,
     -36,  -185
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    59,     5,    18,    24,    26,    76,    73,    29,
      60,    61,   145,    62,    63,    64,   140,   141,   178,    65,
     204,    86,    66,    87,    68,    79,    69,   170,   102,    27,
      70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,    19,    67,    77,    22,    74,   186,    99,   198,    97,
     194,   191,   142,    99,   136,    99,    99,   216,     6,   205,
     103,    21,   104,    20,   212,   213,   208,    28,   137,   210,
     100,    81,    75,   226,   176,   101,   187,   201,   219,    31,
     108,   218,   224,    23,   129,   138,     1,     2,   123,   221,
     139,    32,   135,    30,   177,    90,    91,    92,    78,    67,
     227,   228,    80,   143,   146,   147,   124,   230,    93,    94,
      95,    72,    28,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   188,   119,   120,   165,   166,
      37,    88,    89,   105,    96,   164,    42,    43,    82,    98,
     122,   202,   125,   179,   127,   126,    45,   108,   128,   131,
      46,    47,    48,    49,    50,    83,    52,    53,    54,    55,
     130,   100,   134,    56,   144,    99,   148,   167,   151,   169,
      58,   172,   174,   175,   185,   180,   190,   181,   192,   189,
     182,   193,   138,   195,   179,   111,   112,   146,   113,   114,
     115,   116,   117,   196,   118,   119,   120,   209,   200,   203,
     179,   179,   214,    33,   206,   215,   217,     4,   220,    34,
     222,    35,   225,     1,     2,   229,    36,    37,   179,    38,
      39,    40,    41,    42,    43,    44,   199,     0,   107,   133,
       0,     0,     0,    45,     0,     0,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,     0,
      56,     0,    33,     0,    57,     0,     0,    58,    34,     0,
      35,     0,     1,     2,     0,    36,    37,     0,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     0,     0,    56,
       0,    33,     0,   106,     0,     0,    58,    34,     0,    35,
       0,     1,     2,     0,     0,    37,     0,    38,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    33,     0,    56,     0,
       0,    85,    34,     0,    35,    58,     1,     2,     0,     0,
      37,     0,    38,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       0,     0,     0,    56,     0,    33,     0,   171,     0,     0,
      58,    34,     0,    35,     0,     1,     2,     0,     0,    37,
       0,    38,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    37,
       0,     0,    56,     0,     0,    42,    43,    82,     0,    58,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    46,
      47,    48,    49,    50,    83,    52,    53,    54,    55,    37,
       0,     0,    56,   211,     0,    42,    43,    82,     0,    58,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    46,
      47,    48,    49,    50,    83,    52,    53,    54,    55,    37,
       0,     0,    56,   223,     0,    42,    43,    82,     0,    58,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    46,
      47,    48,    49,    50,    83,    52,    53,    54,    55,     0,
       0,     0,    56,     0,     0,   109,   110,   111,   112,    58,
     113,   114,   115,   116,   117,     0,   118,   119,   120,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
     118,   119,   120,     0,     0,   109,   110,   111,   112,   150,
     113,   114,   115,   116,   117,     0,   118,   119,   120,     0,
       0,     0,   184,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   149,   118,   119,   120,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,   118,   119,
     120,   168,     0,     0,     0,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,   173,   118,   119,   120,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
     118,   119,   120,   207,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,   183,   118,   119,   120,     0,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,   197,
     118,   119,   120,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   121,   118,   119,   120,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   132,     0,     0,
       0,     0,   109,   110,   111,   112,    17,   113,   114,   115,
     116,   117,     0,   118,   119,   120,     7,     8,     9,    10,
      25,    12,    13,    14,    15,    16,     7,     8,     9,    10,
       0,    12,    13,    14,    15,    16,   113,   114,   115,   116,
     117,     0,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      36,     5,    28,    32,    16,    30,   168,    31,   180,    45,
     176,   173,    96,    31,    15,    31,    31,   201,     0,   187,
      56,    54,    58,    46,   196,   197,   192,    57,    29,   195,
      54,    35,    46,   217,    52,    59,    52,    52,   206,    56,
      66,   203,   214,    55,    80,    46,    17,    18,    73,   211,
      51,    56,    88,    55,   138,    48,    49,    50,    46,    85,
     222,   223,    54,    99,   100,   101,    52,   229,    48,    49,
      50,    56,    57,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   169,    39,    40,   125,   126,
      21,    54,    54,    58,    46,   124,    27,    28,    29,    46,
      19,   185,    51,   139,    59,    51,    37,   133,    51,    46,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      56,    54,    25,    54,    55,    31,    51,    48,    58,    46,
      61,    54,   136,    46,    60,    51,   172,    51,    56,    51,
      55,    31,    46,    52,   180,    29,    30,   183,    32,    33,
      34,    35,    36,    51,    38,    39,    40,   193,    31,    14,
     196,   197,    51,     7,    52,    47,    52,     0,    51,    13,
      55,    15,    51,    17,    18,    55,    20,    21,   214,    23,
      24,    25,    26,    27,    28,    29,   183,    -1,    66,    85,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      54,    -1,     7,    -1,    58,    -1,    -1,    61,    13,    -1,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,     7,    -1,    58,    -1,    -1,    61,    13,    -1,    15,
      -1,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,     7,    -1,    54,    -1,
      -1,    57,    13,    -1,    15,    61,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    -1,     7,    -1,    58,    -1,    -1,
      61,    13,    -1,    15,    -1,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    21,
      -1,    -1,    54,    -1,    -1,    27,    28,    29,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    21,
      -1,    -1,    54,    55,    -1,    27,    28,    29,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    21,
      -1,    -1,    54,    55,    -1,    27,    28,    29,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    27,    28,    29,    30,    61,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    -1,    -1,    27,    28,    29,    30,    61,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    -1,
      -1,    -1,    60,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    55,    38,    39,    40,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    55,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    55,    38,    39,    40,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    55,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    52,    38,    39,    40,    -1,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    52,
      38,    39,    40,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    51,    38,    39,    40,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    51,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    22,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    12,    32,    33,    34,    35,
      36,    -1,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    18,    63,    64,    65,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    22,    66,    91,
      46,    54,    16,    55,    67,     7,    68,    91,    57,    71,
      55,    56,    56,     7,    13,    15,    20,    21,    23,    24,
      25,    26,    27,    28,    29,    37,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    54,    58,    61,    64,
      72,    73,    75,    76,    77,    81,    84,    85,    86,    88,
      92,    93,    56,    70,    71,    46,    69,    69,    46,    87,
      54,    91,    29,    46,    92,    57,    83,    85,    54,    54,
      48,    49,    50,    48,    49,    50,    46,    92,    46,    31,
      54,    59,    90,    92,    92,    58,    58,    72,    85,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    38,    39,
      40,    51,    19,    71,    52,    51,    51,    59,    51,    92,
      56,    46,    51,    84,    25,    92,    15,    29,    46,    51,
      78,    79,    90,    92,    55,    74,    92,    92,    51,    55,
      61,    58,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    69,    68,    68,    48,    55,    46,
      89,    58,    54,    55,    91,    46,    52,    90,    80,    92,
      51,    51,    55,    52,    60,    60,    83,    52,    90,    51,
      92,    83,    56,    31,    79,    52,    51,    52,    80,    74,
      31,    52,    90,    14,    82,    89,    52,    55,    79,    92,
      79,    55,    80,    80,    51,    47,    87,    52,    83,    89,
      51,    83,    55,    55,    80,    51,    87,    83,    83,    55,
      83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    68,    68,    68,    68,    69,    69,    70,    71,
      71,    71,    71,    72,    73,    73,    74,    74,    75,    76,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     8,     7,     6,     1,     1,     1,     1,
       1,     2,     5,     3,     5,     3,     3,     1,     2,     4,
       3,     3,     2,     3,     4,     3,     3,     1,     7,     5,
       9,     8,     8,     7,     4,     4,     1,     4,     3,     2,
       3,     1,     5,     6,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     7,
       7,     5,     6,     4,     5,     3,     4,     4,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
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
  case 2: /* program: function  */
#line 37 "Comp.yacc"
                   {(yyval.nodeval) = (yyvsp[0].nodeval); printtree((yyval.nodeval), 0);}
#line 1566 "y.tab.c"
    break;

  case 3: /* function: function_type function_return_type ID '(' function_args ')' function_static function_block  */
#line 43 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-7].nodeval), mknode("return type", (yyvsp[-6].nodeval), mknode("name", mknode((yyvsp[-5].strval), NULL, NULL), mknode("args", (yyvsp[-3].nodeval), mknode("static", (yyvsp[-1].nodeval), mknode("func block", (yyvsp[0].nodeval), NULL))))));}
#line 1572 "y.tab.c"
    break;

  case 4: /* function: function_type function_return_type ID '(' function_args ')' function_block  */
#line 45 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-6].nodeval), mknode("return type", (yyvsp[-5].nodeval), mknode("name", mknode((yyvsp[-4].strval), NULL, NULL), mknode("args", (yyvsp[-2].nodeval), mknode("func block", (yyvsp[0].nodeval), NULL)))));}
#line 1578 "y.tab.c"
    break;

  case 5: /* function: function_type function_return_type ID '(' ')' function_block  */
#line 47 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-5].nodeval), mknode("return type", (yyvsp[-4].nodeval), mknode("name", mknode((yyvsp[-3].strval), NULL, NULL), mknode("func block", (yyvsp[0].nodeval), NULL))));}
#line 1584 "y.tab.c"
    break;

  case 6: /* function_type: PRIVATE  */
#line 49 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1590 "y.tab.c"
    break;

  case 7: /* function_type: PUBLIC  */
#line 50 "Comp.yacc"
                         {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1596 "y.tab.c"
    break;

  case 8: /* function_return_type: param_type  */
#line 52 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1602 "y.tab.c"
    break;

  case 9: /* function_return_type: STRING  */
#line 53 "Comp.yacc"
                                 {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1608 "y.tab.c"
    break;

  case 10: /* function_return_type: VOID  */
#line 54 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1614 "y.tab.c"
    break;

  case 11: /* function_args: ARGS func_args_decleration  */
#line 56 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("args>>", (yyvsp[0].nodeval), NULL);}
#line 1620 "y.tab.c"
    break;

  case 12: /* func_args_decleration: param_type ':' func_many_id ';' func_args_decleration  */
#line 58 "Comp.yacc"
                                                                              {(yyval.nodeval) = mknode("new vars", mknode("params", (yyvsp[-4].nodeval), (yyvsp[-2].nodeval)), (yyvsp[0].nodeval));}
#line 1626 "y.tab.c"
    break;

  case 13: /* func_args_decleration: param_type ':' func_many_id  */
#line 59 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode("new var", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1632 "y.tab.c"
    break;

  case 14: /* func_args_decleration: STRING ':' func_many_id ';' func_args_decleration  */
#line 60 "Comp.yacc"
                                                                            {(yyval.nodeval) = mknode("string", mknode("params", (yyvsp[-2].nodeval), NULL), (yyvsp[0].nodeval));}
#line 1638 "y.tab.c"
    break;

  case 15: /* func_args_decleration: STRING ':' func_many_id  */
#line 61 "Comp.yacc"
                                                  {(yyval.nodeval) = mknode("string", (yyvsp[0].nodeval), NULL);}
#line 1644 "y.tab.c"
    break;

  case 16: /* func_many_id: ID ',' func_many_id  */
#line 64 "Comp.yacc"
                                   {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1650 "y.tab.c"
    break;

  case 17: /* func_many_id: ID  */
#line 65 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1656 "y.tab.c"
    break;

  case 18: /* function_static: ':' STATIC  */
#line 67 "Comp.yacc"
                             {(yyval.nodeval) = mknode(":", (yyvsp[0].nodeval), NULL);}
#line 1662 "y.tab.c"
    break;

  case 19: /* function_block: '{' statement_recursive function_return '}'  */
#line 69 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("func block", (yyvsp[-2].nodeval), (yyvsp[-1].nodeval));}
#line 1668 "y.tab.c"
    break;

  case 20: /* function_block: '{' statement_recursive '}'  */
#line 70 "Comp.yacc"
                                              {(yyval.nodeval) = mknode("func block", (yyvsp[-1].nodeval), NULL);}
#line 1674 "y.tab.c"
    break;

  case 21: /* function_block: '{' function_return '}'  */
#line 71 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("func block", (yyvsp[-1].nodeval), NULL);}
#line 1680 "y.tab.c"
    break;

  case 22: /* function_block: '{' '}'  */
#line 72 "Comp.yacc"
                          {(yyval.nodeval) = NULL;}
#line 1686 "y.tab.c"
    break;

  case 23: /* function_return: RETURN expression ';'  */
#line 74 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("RETURN", (yyvsp[-1].nodeval), NULL);}
#line 1692 "y.tab.c"
    break;

  case 24: /* function_call: ID '(' function_params ')'  */
#line 79 "Comp.yacc"
                                           {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-1].nodeval), NULL);}
#line 1698 "y.tab.c"
    break;

  case 25: /* function_call: ID '(' ')'  */
#line 80 "Comp.yacc"
                             {(yyval.nodeval) = mknode((yyvsp[-2].strval), NULL, NULL);}
#line 1704 "y.tab.c"
    break;

  case 26: /* function_params: expression ',' function_params  */
#line 82 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1710 "y.tab.c"
    break;

  case 27: /* function_params: expression  */
#line 83 "Comp.yacc"
                             {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1716 "y.tab.c"
    break;

  case 28: /* do_while_statement: DO block WHILE '(' expression ')' ';'  */
#line 91 "Comp.yacc"
                                                           {(yyval.nodeval) = mknode("do_while_statement", (yyvsp[-5].nodeval), (yyvsp[-2].nodeval));}
#line 1722 "y.tab.c"
    break;

  case 29: /* while_statement: WHILE '(' expression ')' block  */
#line 93 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("while_statement", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1728 "y.tab.c"
    break;

  case 30: /* for_statement: FOR '(' for_init ';' update ';' update ')' block  */
#line 96 "Comp.yacc"
                        {(yyval.nodeval) = mknode("for", mknode("var_assignment", (yyvsp[-6].nodeval), mknode("expression", (yyvsp[-4].nodeval), mknode("expression", (yyvsp[-2].nodeval), NULL))), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1734 "y.tab.c"
    break;

  case 31: /* for_statement: FOR '(' for_init ';' update ';' ')' block  */
#line 98 "Comp.yacc"
                        {(yyval.nodeval) = mknode("for", mknode("var_assignment", (yyvsp[-5].nodeval), mknode("expression", (yyvsp[-3].nodeval), NULL)), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1740 "y.tab.c"
    break;

  case 32: /* for_statement: FOR '(' ';' update ';' update ')' block  */
#line 100 "Comp.yacc"
                        {(yyval.nodeval) = mknode("for", mknode("expression", (yyvsp[-4].nodeval), mknode("update", (yyvsp[-2].nodeval), NULL)), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1746 "y.tab.c"
    break;

  case 33: /* for_statement: FOR '(' ';' update ';' ')' block  */
#line 102 "Comp.yacc"
                        {(yyval.nodeval) = mknode("for", mknode("expression", (yyvsp[-3].nodeval), NULL), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1752 "y.tab.c"
    break;

  case 34: /* for_init: VAR param_type ':' for_init_many  */
#line 106 "Comp.yacc"
                                            {(yyval.nodeval) = mknode("new var", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1758 "y.tab.c"
    break;

  case 35: /* for_init: MULT ID ASSIGN expression  */
#line 107 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("ptr assign", mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL), NULL);}
#line 1764 "y.tab.c"
    break;

  case 36: /* for_init: for_init_many  */
#line 108 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1770 "y.tab.c"
    break;

  case 37: /* for_init_many: ID assign_statement ',' for_init_many  */
#line 110 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1776 "y.tab.c"
    break;

  case 38: /* for_init_many: ID ',' for_init_many  */
#line 111 "Comp.yacc"
                                 {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1782 "y.tab.c"
    break;

  case 39: /* for_init_many: ID assign_statement  */
#line 112 "Comp.yacc"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 1788 "y.tab.c"
    break;

  case 40: /* update: expression ',' update  */
#line 114 "Comp.yacc"
                               {(yyval.nodeval) = mknode("", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1794 "y.tab.c"
    break;

  case 41: /* update: expression  */
#line 115 "Comp.yacc"
                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1800 "y.tab.c"
    break;

  case 42: /* if_statement: IF '(' expression ')' block  */
#line 120 "Comp.yacc"
                                                          {(yyval.nodeval) = mknode("if", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1806 "y.tab.c"
    break;

  case 43: /* if_statement: IF '(' expression ')' block else_statement  */
#line 121 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("if", (yyvsp[-3].nodeval), mknode(" ", (yyvsp[-1].nodeval), (yyvsp[0].nodeval)));}
#line 1812 "y.tab.c"
    break;

  case 44: /* else_statement: ELSE block  */
#line 123 "Comp.yacc"
                            {(yyval.nodeval) = mknode("else", (yyvsp[0].nodeval), NULL);}
#line 1818 "y.tab.c"
    break;

  case 45: /* block: statement  */
#line 128 "Comp.yacc"
                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1824 "y.tab.c"
    break;

  case 46: /* block: '{' statement_recursive '}'  */
#line 129 "Comp.yacc"
                                      {(yyval.nodeval) = mknode("block", (yyvsp[-1].nodeval),NULL);}
#line 1830 "y.tab.c"
    break;

  case 47: /* statement_recursive: statement  */
#line 131 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1836 "y.tab.c"
    break;

  case 48: /* statement_recursive: statement_recursive statement  */
#line 132 "Comp.yacc"
                                                    {(yyval.nodeval) = mknode("statements", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1842 "y.tab.c"
    break;

  case 49: /* statement: var_assignment  */
#line 134 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1848 "y.tab.c"
    break;

  case 50: /* statement: string_assignment  */
#line 135 "Comp.yacc"
                                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1854 "y.tab.c"
    break;

  case 51: /* statement: if_statement  */
#line 136 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1860 "y.tab.c"
    break;

  case 52: /* statement: for_statement  */
#line 137 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1866 "y.tab.c"
    break;

  case 53: /* statement: while_statement  */
#line 138 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1872 "y.tab.c"
    break;

  case 54: /* statement: do_while_statement  */
#line 139 "Comp.yacc"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1878 "y.tab.c"
    break;

  case 55: /* statement: function  */
#line 140 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1884 "y.tab.c"
    break;

  case 56: /* statement: COMMENT  */
#line 141 "Comp.yacc"
                          {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1890 "y.tab.c"
    break;

  case 57: /* statement: expression ';'  */
#line 142 "Comp.yacc"
                                 {(yyval.nodeval) = (yyvsp[-1].nodeval);}
#line 1896 "y.tab.c"
    break;

  case 58: /* string_assignment: STRING many_string ';'  */
#line 147 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("new string", (yyvsp[-1].nodeval), NULL);}
#line 1902 "y.tab.c"
    break;

  case 59: /* string_assignment: ID '[' expression ']' ASSIGN CHAR_VAL ';'  */
#line 148 "Comp.yacc"
                                                                {(yyval.nodeval) = mknode("assign string index", mknode("id", mknode((yyvsp[-6].strval), NULL, NULL), (yyvsp[-4].nodeval)), mknode("assign", mknode((yyvsp[-1].strval), NULL, NULL), NULL));}
#line 1908 "y.tab.c"
    break;

  case 60: /* many_string: ID '[' INT_VAL ']' assign_statement ',' many_string  */
#line 151 "Comp.yacc"
                {(yyval.nodeval) = mknode("list1", mknode("id", mknode((yyvsp[-6].strval), NULL, NULL), mknode((yyvsp[-4].strval), NULL, NULL)), mknode("value", (yyvsp[-2].nodeval), (yyvsp[0].nodeval)));}
#line 1914 "y.tab.c"
    break;

  case 61: /* many_string: ID '[' INT_VAL ']' assign_statement  */
#line 153 "Comp.yacc"
                {(yyval.nodeval) = mknode("string2", mknode("id", mknode((yyvsp[-4].strval), NULL, NULL), mknode((yyvsp[-2].strval), NULL, NULL)), (yyvsp[0].nodeval));}
#line 1920 "y.tab.c"
    break;

  case 62: /* many_string: ID '[' INT_VAL ']' ',' many_string  */
#line 155 "Comp.yacc"
                {(yyval.nodeval) = mknode("list2", mknode("id", mknode((yyvsp[-5].strval), NULL, NULL), mknode((yyvsp[-3].strval), NULL, NULL)), (yyvsp[0].nodeval));}
#line 1926 "y.tab.c"
    break;

  case 63: /* many_string: ID '[' INT_VAL ']'  */
#line 157 "Comp.yacc"
                {(yyval.nodeval) = mknode("string1", mknode((yyvsp[-3].strval), NULL, NULL), mknode((yyvsp[-1].strval), NULL, NULL));}
#line 1932 "y.tab.c"
    break;

  case 64: /* var_assignment: VAR param_type ':' many_id ';'  */
#line 161 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("new var", (yyvsp[-3].nodeval), (yyvsp[-1].nodeval));}
#line 1938 "y.tab.c"
    break;

  case 65: /* var_assignment: ID assign_statement ';'  */
#line 162 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("assign", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 1944 "y.tab.c"
    break;

  case 66: /* var_assignment: MULT ID assign_statement ';'  */
#line 163 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("ptr assign", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 1950 "y.tab.c"
    break;

  case 67: /* many_id: ID assign_statement ',' many_id  */
#line 165 "Comp.yacc"
                                          {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1956 "y.tab.c"
    break;

  case 68: /* many_id: ID ',' many_id  */
#line 166 "Comp.yacc"
                           {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1962 "y.tab.c"
    break;

  case 69: /* many_id: ID assign_statement  */
#line 167 "Comp.yacc"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 1968 "y.tab.c"
    break;

  case 70: /* many_id: ID  */
#line 168 "Comp.yacc"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1974 "y.tab.c"
    break;

  case 71: /* assign_statement: ASSIGN expression  */
#line 170 "Comp.yacc"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1980 "y.tab.c"
    break;

  case 72: /* param_type: INT  */
#line 175 "Comp.yacc"
                 {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1986 "y.tab.c"
    break;

  case 73: /* param_type: FLOAT  */
#line 176 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1992 "y.tab.c"
    break;

  case 74: /* param_type: DOUBLE  */
#line 177 "Comp.yacc"
                      {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1998 "y.tab.c"
    break;

  case 75: /* param_type: CHAR  */
#line 178 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2004 "y.tab.c"
    break;

  case 76: /* param_type: INT_PTR  */
#line 179 "Comp.yacc"
                       {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2010 "y.tab.c"
    break;

  case 77: /* param_type: FLOAT_PTR  */
#line 180 "Comp.yacc"
                         {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2016 "y.tab.c"
    break;

  case 78: /* param_type: DOUBLE_PTR  */
#line 181 "Comp.yacc"
                          {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2022 "y.tab.c"
    break;

  case 79: /* param_type: CHAR_PTR  */
#line 182 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2028 "y.tab.c"
    break;

  case 80: /* param_type: BOOL  */
#line 183 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 2034 "y.tab.c"
    break;

  case 81: /* expression: NULL_VALUE  */
#line 185 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2040 "y.tab.c"
    break;

  case 82: /* expression: ADDRESS ID  */
#line 186 "Comp.yacc"
                         {(yyval.nodeval) = mknode("&", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 2046 "y.tab.c"
    break;

  case 83: /* expression: MULT ID  */
#line 187 "Comp.yacc"
                      {(yyval.nodeval) = mknode("*", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 2052 "y.tab.c"
    break;

  case 84: /* expression: NOT expression  */
#line 188 "Comp.yacc"
                             {(yyval.nodeval) = mknode("! (not)", (yyvsp[0].nodeval), NULL);}
#line 2058 "y.tab.c"
    break;

  case 85: /* expression: expression LESSER expression  */
#line 189 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("<", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2064 "y.tab.c"
    break;

  case 86: /* expression: expression LESSER_EQ expression  */
#line 190 "Comp.yacc"
                                              {(yyval.nodeval) = mknode("<=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2070 "y.tab.c"
    break;

  case 87: /* expression: expression GREATER expression  */
#line 191 "Comp.yacc"
                                            {(yyval.nodeval) = mknode(">", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2076 "y.tab.c"
    break;

  case 88: /* expression: expression GREATER_EQ expression  */
#line 192 "Comp.yacc"
                                               {(yyval.nodeval) = mknode(">=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2082 "y.tab.c"
    break;

  case 89: /* expression: expression EQUAL expression  */
#line 193 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("==", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2088 "y.tab.c"
    break;

  case 90: /* expression: expression NOT_EQ expression  */
#line 194 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("!=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2094 "y.tab.c"
    break;

  case 91: /* expression: expression OR expression  */
#line 195 "Comp.yacc"
                                       {(yyval.nodeval) = mknode("||", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2100 "y.tab.c"
    break;

  case 92: /* expression: expression AND expression  */
#line 196 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("&&", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2106 "y.tab.c"
    break;

  case 93: /* expression: expression ADD expression  */
#line 197 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("+", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2112 "y.tab.c"
    break;

  case 94: /* expression: expression SUB expression  */
#line 198 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("value - value", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2118 "y.tab.c"
    break;

  case 95: /* expression: expression MULT expression  */
#line 199 "Comp.yacc"
                                         {(yyval.nodeval) = mknode("*", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2124 "y.tab.c"
    break;

  case 96: /* expression: expression DIVIDE expression  */
#line 200 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("/", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 2130 "y.tab.c"
    break;

  case 97: /* expression: '(' expression ')'  */
#line 201 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("( )", (yyvsp[-1].nodeval), NULL);}
#line 2136 "y.tab.c"
    break;

  case 98: /* expression: '|' expression '|'  */
#line 202 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("length of array", (yyvsp[-1].nodeval), NULL);}
#line 2142 "y.tab.c"
    break;

  case 99: /* expression: value  */
#line 203 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2148 "y.tab.c"
    break;

  case 100: /* expression: function_call  */
#line 204 "Comp.yacc"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2154 "y.tab.c"
    break;

  case 101: /* value: INT_VAL  */
#line 208 "Comp.yacc"
                {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2160 "y.tab.c"
    break;

  case 102: /* value: FLOAT_VAL  */
#line 209 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2166 "y.tab.c"
    break;

  case 103: /* value: DOUBLE_VAL  */
#line 210 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2172 "y.tab.c"
    break;

  case 104: /* value: SUB INT_VAL  */
#line 211 "Comp.yacc"
                      {(yyval.nodeval) = mknode("-", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2178 "y.tab.c"
    break;

  case 105: /* value: SUB FLOAT_VAL  */
#line 212 "Comp.yacc"
                        {(yyval.nodeval) = mknode("-", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2184 "y.tab.c"
    break;

  case 106: /* value: SUB DOUBLE_VAL  */
#line 213 "Comp.yacc"
                         {(yyval.nodeval) = mknode("-", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2190 "y.tab.c"
    break;

  case 107: /* value: ADD INT_VAL  */
#line 214 "Comp.yacc"
                      {(yyval.nodeval) = mknode("+", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2196 "y.tab.c"
    break;

  case 108: /* value: ADD FLOAT_VAL  */
#line 215 "Comp.yacc"
                        {(yyval.nodeval) = mknode("+", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2202 "y.tab.c"
    break;

  case 109: /* value: ADD DOUBLE_VAL  */
#line 216 "Comp.yacc"
                         {(yyval.nodeval) = mknode("+", mknode((yyvsp[0].strval), NULL, NULL), NULL);}
#line 2208 "y.tab.c"
    break;

  case 110: /* value: ID  */
#line 217 "Comp.yacc"
             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2214 "y.tab.c"
    break;

  case 111: /* value: TRUE_VAL  */
#line 218 "Comp.yacc"
                   {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2220 "y.tab.c"
    break;

  case 112: /* value: FALSE_VAL  */
#line 219 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 2226 "y.tab.c"
    break;

  case 113: /* value: CHAR_VAL  */
#line 220 "Comp.yacc"
                   {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2232 "y.tab.c"
    break;

  case 114: /* value: STRING_VAL  */
#line 221 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2238 "y.tab.c"
    break;

  case 115: /* value: HEX_VAL  */
#line 222 "Comp.yacc"
                  {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 2244 "y.tab.c"
    break;


#line 2248 "y.tab.c"

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

#line 224 "Comp.yacc"

#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        printf("syntax error, line: %d\n", yylineno);
        return 0;
}
