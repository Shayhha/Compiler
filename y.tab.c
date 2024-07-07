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
    FOR = 268,                     /* FOR  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    VAR = 271,                     /* VAR  */
    ARGS = 272,                    /* ARGS  */
    PUBLIC = 273,                  /* PUBLIC  */
    PRIVATE = 274,                 /* PRIVATE  */
    STATIC = 275,                  /* STATIC  */
    RETURN = 276,                  /* RETURN  */
    NULL_VALUE = 277,              /* NULL_VALUE  */
    VOID = 278,                    /* VOID  */
    COMMENT = 279,                 /* COMMENT  */
    DO = 280,                      /* DO  */
    WHILE = 281,                   /* WHILE  */
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
#define FOR 268
#define IF 269
#define ELSE 270
#define VAR 271
#define ARGS 272
#define PUBLIC 273
#define PRIVATE 274
#define STATIC 275
#define RETURN 276
#define NULL_VALUE 277
#define VOID 278
#define COMMENT 279
#define DO 280
#define WHILE 281
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
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_VAR = 16,                       /* VAR  */
  YYSYMBOL_ARGS = 17,                      /* ARGS  */
  YYSYMBOL_PUBLIC = 18,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 19,                   /* PRIVATE  */
  YYSYMBOL_STATIC = 20,                    /* STATIC  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_NULL_VALUE = 22,                /* NULL_VALUE  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_COMMENT = 24,                   /* COMMENT  */
  YYSYMBOL_DO = 25,                        /* DO  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
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
  YYSYMBOL_do_while_statement = 73,        /* do_while_statement  */
  YYSYMBOL_while_statement = 74,           /* while_statement  */
  YYSYMBOL_for_statement = 75,             /* for_statement  */
  YYSYMBOL_if_statement = 76,              /* if_statement  */
  YYSYMBOL_else_statement = 77,            /* else_statement  */
  YYSYMBOL_block = 78,                     /* block  */
  YYSYMBOL_statement_recursive = 79,       /* statement_recursive  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_string_assignment = 81,         /* string_assignment  */
  YYSYMBOL_many_string = 82,               /* many_string  */
  YYSYMBOL_var_assignment = 83,            /* var_assignment  */
  YYSYMBOL_many_id = 84,                   /* many_id  */
  YYSYMBOL_assign_statement = 85,          /* assign_statement  */
  YYSYMBOL_param_type = 86,                /* param_type  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_value = 88                      /* value  */
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
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
      54,    56,    58,    59,    61,    62,    64,    66,    67,    68,
      69,    71,    76,    78,    80,    86,    87,    89,    94,    95,
      97,    98,   100,   101,   102,   103,   104,   105,   106,   107,
     112,   113,   114,   116,   118,   120,   122,   128,   129,   130,
     132,   133,   134,   135,   137,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   172,   173,   174,   175,   176,   177,   178,
     179
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
  "FLOAT_PTR", "BOOL", "FOR", "IF", "ELSE", "VAR", "ARGS", "PUBLIC",
  "PRIVATE", "STATIC", "RETURN", "NULL_VALUE", "VOID", "COMMENT", "DO",
  "WHILE", "ADD", "SUB", "MULT", "DIVIDE", "ASSIGN", "EQUAL", "GREATER",
  "GREATER_EQ", "LESSER", "LESSER_EQ", "NOT", "NOT_EQ", "AND", "OR",
  "ADDRESS", "TRUE_VAL", "FALSE_VAL", "HEX_VAL", "STRING_VAL", "ID",
  "CHAR_VAL", "INT_VAL", "FLOAT_VAL", "DOUBLE_VAL", "';'", "','",
  "non_else", "'('", "')'", "':'", "'{'", "'}'", "'['", "']'", "'|'",
  "$accept", "program", "function", "function_type",
  "function_return_type", "function_args", "func_args_decleration",
  "func_many_id", "function_static", "function_block", "function_return",
  "do_while_statement", "while_statement", "for_statement", "if_statement",
  "else_statement", "block", "statement_recursive", "statement",
  "string_assignment", "many_string", "var_assignment", "many_id",
  "assign_statement", "param_type", "expression", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,  -150,  -150,     9,  -150,   203,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   -17,  -150,
     -19,   -15,   236,   -10,     1,  -150,     8,    41,  -150,    29,
      22,    47,    34,    50,   236,   130,  -150,   124,    53,    72,
     -27,  -150,  -150,    61,  -150,  -150,  -150,  -150,    87,  -150,
    -150,  -150,   102,   -10,  -150,    89,    76,    85,   100,   -13,
     130,    98,  -150,   109,   207,   111,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   130,   207,    44,   200,   176,   134,
    -150,   130,   131,   130,   130,   112,  -150,  -150,   103,  -150,
    -150,  -150,    22,   236,   116,  -150,   135,   130,   -29,   119,
    -150,  -150,  -150,     3,   108,   130,   130,  -150,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   110,   120,
      42,   130,    11,   -21,  -150,  -150,  -150,  -150,   122,   130,
      51,   124,   -16,   136,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   130,
     124,    81,  -150,   154,   -11,   107,   130,   171,   130,   119,
     141,  -150,    70,  -150,  -150,   149,    47,   145,    75,   124,
    -150,    11,  -150,   119,   137,   147,  -150,    47,   124,  -150,
    -150,  -150,  -150,  -150,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     6,     0,     2,     0,     1,    58,    55,    57,
      56,     9,    59,    62,    61,    60,    63,    10,     0,     8,
       0,     0,     0,     0,     0,    11,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,    20,    38,     0,    37,    36,    35,    34,     0,    30,
      33,    32,     0,     0,     4,    15,    13,     0,     0,     0,
       0,     0,    64,     0,     0,     0,    87,    88,    90,    86,
      89,    83,    84,    85,     0,     0,     0,    74,     0,     0,
      28,     0,     0,     0,     0,     0,    19,    18,     0,    31,
      16,     3,     0,     0,     0,    40,     0,     0,     0,     0,
      66,    73,    65,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,    41,    17,    14,    12,     0,     0,
       0,     0,    53,     0,    75,    82,    77,    76,    78,    79,
      80,    81,    71,    69,    70,    67,    68,    72,    29,     0,
       0,     0,    48,     0,    44,     0,     0,    25,     0,     0,
      52,    47,     0,    23,    49,     0,     0,    43,     0,     0,
      26,    54,    51,     0,     0,     0,    46,     0,     0,    27,
      50,    22,    42,    45,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   199,  -150,  -150,  -150,   123,   125,  -150,   -22,
     155,  -150,  -150,  -150,  -150,  -150,  -125,   126,   -26,  -150,
    -149,   159,  -110,  -124,     0,   -60,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    42,     5,    18,    24,    25,    56,    53,    28,
      43,    44,    45,    46,    47,   170,    79,    48,    80,    50,
      58,    51,   133,    85,    26,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      98,    49,    22,    34,    83,    19,   157,    54,   160,     6,
     105,   106,     1,     2,   103,   158,    39,   176,   105,   106,
     158,   120,    89,   122,   123,   163,   131,   101,   183,    20,
     167,    91,    84,    96,    61,    21,   159,   130,   104,   153,
      23,   166,   105,   106,   179,   136,   137,    27,    31,   172,
     105,   106,    49,   184,    32,    33,    29,    34,   134,     1,
       2,   151,    35,   180,    30,    36,    37,    38,    55,   155,
      39,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   105,   106,   105,   106,    52,    27,    40,    59,   162,
     105,   106,    89,    57,    31,   107,   168,   150,   171,    41,
      32,    33,   156,    34,    60,     1,     2,    81,    35,   105,
     106,    36,    37,    38,   105,   106,    39,    31,    82,    86,
     105,   106,    90,    32,    33,   174,    34,    93,     1,     2,
     178,    31,   164,    40,    36,    37,    38,    32,    33,    39,
      34,    92,     1,     2,    94,    87,   105,   106,    36,    37,
      38,    95,    62,    39,    99,   100,    40,   102,   152,    63,
     119,   125,   121,   124,   128,   132,   129,    64,   148,   135,
      40,    65,    66,    67,   149,    68,    69,    70,    71,    72,
      73,    78,   154,    31,    74,   165,   169,   161,   181,    32,
      33,    75,    34,   173,     1,     2,   175,   177,   182,     4,
      36,    37,    38,    88,   118,    39,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   127,   126,    97,     0,
       0,     0,    40,     0,     0,     0,    17,   108,   109,   110,
     111,     0,   112,   113,   114,   115,   116,     0,   117,     7,
       8,     9,    10,     0,    12,    13,    14,    15,    16,    66,
      67,     0,    68,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      60,    27,    17,    16,    31,     5,   131,    29,   132,     0,
      39,    40,    18,    19,    74,    31,    29,   166,    39,    40,
      31,    81,    48,    83,    84,   150,    55,    64,   177,    46,
     154,    53,    59,    46,    34,    54,    52,    97,    75,    60,
      55,    52,    39,    40,   169,   105,   106,    57,     7,   159,
      39,    40,    78,   178,    13,    14,    55,    16,    55,    18,
      19,   121,    21,   173,    56,    24,    25,    26,    46,   129,
      29,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    39,    40,    39,    40,    56,    57,    46,    54,   149,
      39,    40,   118,    46,     7,    51,   156,    55,   158,    58,
      13,    14,    51,    16,    54,    18,    19,    54,    21,    39,
      40,    24,    25,    26,    39,    40,    29,     7,    46,    58,
      39,    40,    20,    13,    14,    55,    16,    51,    18,    19,
      55,     7,    51,    46,    24,    25,    26,    13,    14,    29,
      16,    52,    18,    19,    59,    58,    39,    40,    24,    25,
      26,    51,    22,    29,    56,    46,    46,    46,    51,    29,
      26,    58,    31,    51,    48,    46,    31,    37,    58,    61,
      46,    41,    42,    43,    54,    45,    46,    47,    48,    49,
      50,    57,    60,     7,    54,    31,    15,    51,    51,    13,
      14,    61,    16,    52,    18,    19,    47,    52,    51,     0,
      24,    25,    26,    48,    78,    29,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    93,    92,    59,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    23,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    42,
      43,    -1,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    63,    64,    65,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    23,    66,    86,
      46,    54,    17,    55,    67,    68,    86,    57,    71,    55,
      56,     7,    13,    14,    16,    21,    24,    25,    26,    29,
      46,    58,    64,    72,    73,    74,    75,    76,    79,    80,
      81,    83,    56,    70,    71,    46,    69,    46,    82,    54,
      54,    86,    22,    29,    37,    41,    42,    43,    45,    46,
      47,    48,    49,    50,    54,    61,    87,    88,    57,    78,
      80,    54,    46,    31,    59,    85,    58,    58,    72,    80,
      20,    71,    52,    51,    59,    51,    46,    83,    87,    56,
      46,    88,    46,    87,    88,    39,    40,    51,    27,    28,
      29,    30,    32,    33,    34,    35,    36,    38,    79,    26,
      87,    31,    87,    87,    51,    58,    69,    68,    48,    31,
      87,    55,    46,    84,    55,    61,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    58,    54,
      55,    87,    51,    60,    60,    87,    51,    78,    31,    52,
      85,    51,    87,    78,    51,    31,    52,    85,    87,    15,
      77,    87,    84,    52,    55,    47,    82,    52,    55,    78,
      84,    51,    51,    82,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    67,    68,    68,    69,    69,    70,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     8,     7,     6,     1,     1,     1,     1,
       1,     2,     5,     3,     3,     1,     2,     4,     3,     3,
       2,     3,     7,     5,     8,     5,     6,     2,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     7,     5,     4,     7,     6,     5,     4,     5,
       4,     3,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 1446 "y.tab.c"
    break;

  case 3: /* function: function_type function_return_type ID '(' function_args ')' function_static function_block  */
#line 43 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-7].nodeval), mknode("return type", (yyvsp[-6].nodeval), mknode("name", mknode((yyvsp[-5].strval), NULL, NULL), mknode("args", (yyvsp[-3].nodeval), mknode("static", (yyvsp[-1].nodeval), mknode("func block", (yyvsp[0].nodeval), NULL))))));}
#line 1452 "y.tab.c"
    break;

  case 4: /* function: function_type function_return_type ID '(' function_args ')' function_block  */
#line 45 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-6].nodeval), mknode("return type", (yyvsp[-5].nodeval), mknode("name", mknode((yyvsp[-4].strval), NULL, NULL), mknode("args", (yyvsp[-2].nodeval), mknode("func block", (yyvsp[0].nodeval), NULL)))));}
#line 1458 "y.tab.c"
    break;

  case 5: /* function: function_type function_return_type ID '(' ')' function_block  */
#line 47 "Comp.yacc"
            {(yyval.nodeval) = mknode("Function", (yyvsp[-5].nodeval), mknode("return type", (yyvsp[-4].nodeval), mknode("name", mknode((yyvsp[-3].strval), NULL, NULL), mknode("func block", (yyvsp[0].nodeval), NULL))));}
#line 1464 "y.tab.c"
    break;

  case 6: /* function_type: PRIVATE  */
#line 49 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1470 "y.tab.c"
    break;

  case 7: /* function_type: PUBLIC  */
#line 50 "Comp.yacc"
                         {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1476 "y.tab.c"
    break;

  case 8: /* function_return_type: param_type  */
#line 52 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1482 "y.tab.c"
    break;

  case 9: /* function_return_type: STRING  */
#line 53 "Comp.yacc"
                                 {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1488 "y.tab.c"
    break;

  case 10: /* function_return_type: VOID  */
#line 54 "Comp.yacc"
                               {(yyval.nodeval) = mknode((yyvsp[0].nodeval), NULL, NULL);}
#line 1494 "y.tab.c"
    break;

  case 11: /* function_args: ARGS func_args_decleration  */
#line 56 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("args>>", (yyvsp[0].nodeval), NULL);}
#line 1500 "y.tab.c"
    break;

  case 12: /* func_args_decleration: param_type ':' func_many_id ';' func_args_decleration  */
#line 58 "Comp.yacc"
                                                                              {(yyval.nodeval) = mknode("new vars", mknode("params", (yyvsp[-4].nodeval), (yyvsp[-2].nodeval)), (yyvsp[0].nodeval));}
#line 1506 "y.tab.c"
    break;

  case 13: /* func_args_decleration: param_type ':' func_many_id  */
#line 59 "Comp.yacc"
                                                      {(yyval.nodeval) = mknode("new var", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1512 "y.tab.c"
    break;

  case 14: /* func_many_id: ID ',' func_many_id  */
#line 61 "Comp.yacc"
                                   {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1518 "y.tab.c"
    break;

  case 15: /* func_many_id: ID  */
#line 62 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1524 "y.tab.c"
    break;

  case 16: /* function_static: ':' STATIC  */
#line 64 "Comp.yacc"
                             {(yyval.nodeval) = mknode(":", (yyvsp[0].nodeval), NULL);}
#line 1530 "y.tab.c"
    break;

  case 17: /* function_block: '{' statement_recursive function_return '}'  */
#line 66 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("func block", (yyvsp[-2].nodeval), (yyvsp[-1].nodeval));}
#line 1536 "y.tab.c"
    break;

  case 18: /* function_block: '{' statement_recursive '}'  */
#line 67 "Comp.yacc"
                                              {(yyval.nodeval) = mknode("func block", (yyvsp[-1].nodeval), NULL);}
#line 1542 "y.tab.c"
    break;

  case 19: /* function_block: '{' function_return '}'  */
#line 68 "Comp.yacc"
                                          {(yyval.nodeval) = mknode("func block", (yyvsp[-1].nodeval), NULL);}
#line 1548 "y.tab.c"
    break;

  case 20: /* function_block: '{' '}'  */
#line 69 "Comp.yacc"
                          {(yyval.nodeval) = NULL;}
#line 1554 "y.tab.c"
    break;

  case 21: /* function_return: RETURN expression ';'  */
#line 71 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("RETURN", (yyvsp[-1].nodeval), NULL);}
#line 1560 "y.tab.c"
    break;

  case 22: /* do_while_statement: DO block WHILE '(' expression ')' ';'  */
#line 76 "Comp.yacc"
                                                           {(yyval.nodeval) = mknode("do_while_statement", (yyvsp[-5].nodeval), (yyvsp[-2].nodeval));}
#line 1566 "y.tab.c"
    break;

  case 23: /* while_statement: WHILE '(' expression ')' block  */
#line 78 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("while_statement", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1572 "y.tab.c"
    break;

  case 24: /* for_statement: FOR '(' var_assignment expression ';' expression ')' block  */
#line 81 "Comp.yacc"
                        {(yyval.nodeval) = mknode("for", mknode("var_assignment", (yyvsp[-5].nodeval), mknode("expression", (yyvsp[-4].nodeval), mknode("expression", (yyvsp[-2].nodeval), NULL))), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1578 "y.tab.c"
    break;

  case 25: /* if_statement: IF '(' expression ')' block  */
#line 86 "Comp.yacc"
                                                          {(yyval.nodeval) = mknode("if", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1584 "y.tab.c"
    break;

  case 26: /* if_statement: IF '(' expression ')' block else_statement  */
#line 87 "Comp.yacc"
                                                             {(yyval.nodeval) = mknode("if", (yyvsp[-3].nodeval), mknode(" ", (yyvsp[-1].nodeval), (yyvsp[0].nodeval)));}
#line 1590 "y.tab.c"
    break;

  case 27: /* else_statement: ELSE block  */
#line 89 "Comp.yacc"
                            {(yyval.nodeval) = mknode("else", (yyvsp[0].nodeval), NULL);}
#line 1596 "y.tab.c"
    break;

  case 28: /* block: statement  */
#line 94 "Comp.yacc"
                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1602 "y.tab.c"
    break;

  case 29: /* block: '{' statement_recursive '}'  */
#line 95 "Comp.yacc"
                                      {(yyval.nodeval) = mknode("block", (yyvsp[-1].nodeval),NULL);}
#line 1608 "y.tab.c"
    break;

  case 30: /* statement_recursive: statement  */
#line 97 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1614 "y.tab.c"
    break;

  case 31: /* statement_recursive: statement_recursive statement  */
#line 98 "Comp.yacc"
                                                    {(yyval.nodeval) = mknode("statements", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1620 "y.tab.c"
    break;

  case 32: /* statement: var_assignment  */
#line 100 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1626 "y.tab.c"
    break;

  case 33: /* statement: string_assignment  */
#line 101 "Comp.yacc"
                                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1632 "y.tab.c"
    break;

  case 34: /* statement: if_statement  */
#line 102 "Comp.yacc"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1638 "y.tab.c"
    break;

  case 35: /* statement: for_statement  */
#line 103 "Comp.yacc"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1644 "y.tab.c"
    break;

  case 36: /* statement: while_statement  */
#line 104 "Comp.yacc"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1650 "y.tab.c"
    break;

  case 37: /* statement: do_while_statement  */
#line 105 "Comp.yacc"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1656 "y.tab.c"
    break;

  case 38: /* statement: function  */
#line 106 "Comp.yacc"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1662 "y.tab.c"
    break;

  case 39: /* statement: COMMENT  */
#line 107 "Comp.yacc"
                          {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1668 "y.tab.c"
    break;

  case 40: /* string_assignment: STRING many_string ';'  */
#line 112 "Comp.yacc"
                                           {(yyval.nodeval) = mknode("new string", (yyvsp[-1].nodeval), NULL);}
#line 1674 "y.tab.c"
    break;

  case 41: /* string_assignment: ID assign_statement ';'  */
#line 113 "Comp.yacc"
                                                  {(yyval.nodeval) = mknode("assign string", mknode((yyvsp[-2].strval), NULL, NULL), (yyvsp[-1].nodeval));}
#line 1680 "y.tab.c"
    break;

  case 42: /* string_assignment: ID '[' expression ']' ASSIGN CHAR_VAL ';'  */
#line 114 "Comp.yacc"
                                                                    {(yyval.nodeval) = mknode("assign string index", mknode("id", mknode((yyvsp[-6].strval), NULL, NULL), (yyvsp[-4].nodeval)), mknode("assign", mknode((yyvsp[-1].strval), NULL, NULL), NULL));}
#line 1686 "y.tab.c"
    break;

  case 43: /* many_string: ID '[' INT_VAL ']' assign_statement  */
#line 117 "Comp.yacc"
                {(yyval.nodeval) = mknode("string2", mknode("id", mknode((yyvsp[-4].strval), NULL, NULL), mknode((yyvsp[-2].strval), NULL, NULL)), (yyvsp[0].nodeval));}
#line 1692 "y.tab.c"
    break;

  case 44: /* many_string: ID '[' INT_VAL ']'  */
#line 119 "Comp.yacc"
                {(yyval.nodeval) = mknode("string1", mknode((yyvsp[-3].strval), NULL, NULL), mknode((yyvsp[-1].strval), NULL, NULL));}
#line 1698 "y.tab.c"
    break;

  case 45: /* many_string: ID '[' INT_VAL ']' assign_statement ',' many_string  */
#line 121 "Comp.yacc"
                {(yyval.nodeval) = mknode("list1", mknode("id", mknode((yyvsp[-6].strval), NULL, NULL), mknode((yyvsp[-4].strval), NULL, NULL)), mknode("value", (yyvsp[-2].nodeval), (yyvsp[0].nodeval)));}
#line 1704 "y.tab.c"
    break;

  case 46: /* many_string: ID '[' INT_VAL ']' ',' many_string  */
#line 123 "Comp.yacc"
                {(yyval.nodeval) = mknode("list2", mknode("id", mknode((yyvsp[-5].strval), NULL, NULL), mknode((yyvsp[-3].strval), NULL, NULL)), (yyvsp[0].nodeval));}
#line 1710 "y.tab.c"
    break;

  case 47: /* var_assignment: VAR param_type ':' many_id ';'  */
#line 128 "Comp.yacc"
                                                {(yyval.nodeval) = mknode("new var", (yyvsp[-3].nodeval), (yyvsp[-1].nodeval));}
#line 1716 "y.tab.c"
    break;

  case 48: /* var_assignment: ID ASSIGN expression ';'  */
#line 129 "Comp.yacc"
                                            {(yyval.nodeval) = mknode("assign", mknode((yyvsp[-3].strval), (yyvsp[-1].nodeval), NULL), NULL);}
#line 1722 "y.tab.c"
    break;

  case 49: /* var_assignment: MULT ID ASSIGN expression ';'  */
#line 130 "Comp.yacc"
                                                 {(yyval.nodeval) = mknode("ptr assign", mknode((yyvsp[-3].strval), (yyvsp[-1].nodeval), NULL), NULL);}
#line 1728 "y.tab.c"
    break;

  case 50: /* many_id: ID assign_statement ',' many_id  */
#line 132 "Comp.yacc"
                                          {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1734 "y.tab.c"
    break;

  case 51: /* many_id: ID ',' many_id  */
#line 133 "Comp.yacc"
                           {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1740 "y.tab.c"
    break;

  case 52: /* many_id: ID assign_statement  */
#line 134 "Comp.yacc"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 1746 "y.tab.c"
    break;

  case 53: /* many_id: ID  */
#line 135 "Comp.yacc"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1752 "y.tab.c"
    break;

  case 54: /* assign_statement: ASSIGN expression  */
#line 137 "Comp.yacc"
                                     {(yyval.nodeval) = mknode("assign", (yyvsp[0].nodeval), NULL);}
#line 1758 "y.tab.c"
    break;

  case 55: /* param_type: INT  */
#line 142 "Comp.yacc"
                 {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1764 "y.tab.c"
    break;

  case 56: /* param_type: FLOAT  */
#line 143 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1770 "y.tab.c"
    break;

  case 57: /* param_type: DOUBLE  */
#line 144 "Comp.yacc"
                      {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1776 "y.tab.c"
    break;

  case 58: /* param_type: CHAR  */
#line 145 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1782 "y.tab.c"
    break;

  case 59: /* param_type: INT_PTR  */
#line 146 "Comp.yacc"
                       {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1788 "y.tab.c"
    break;

  case 60: /* param_type: FLOAT_PTR  */
#line 147 "Comp.yacc"
                         {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1794 "y.tab.c"
    break;

  case 61: /* param_type: DOUBLE_PTR  */
#line 148 "Comp.yacc"
                          {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1800 "y.tab.c"
    break;

  case 62: /* param_type: CHAR_PTR  */
#line 149 "Comp.yacc"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1806 "y.tab.c"
    break;

  case 63: /* param_type: BOOL  */
#line 150 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1812 "y.tab.c"
    break;

  case 64: /* expression: NULL_VALUE  */
#line 152 "Comp.yacc"
                        {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1818 "y.tab.c"
    break;

  case 65: /* expression: ADDRESS ID  */
#line 153 "Comp.yacc"
                         {(yyval.nodeval) = mknode("&", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 1824 "y.tab.c"
    break;

  case 66: /* expression: MULT ID  */
#line 154 "Comp.yacc"
                      {(yyval.nodeval) = mknode("*", mknode((yyvsp[0].strval),NULL,NULL), NULL);}
#line 1830 "y.tab.c"
    break;

  case 67: /* expression: value LESSER value  */
#line 155 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("<", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1836 "y.tab.c"
    break;

  case 68: /* expression: value LESSER_EQ value  */
#line 156 "Comp.yacc"
                                    {(yyval.nodeval) = mknode("<=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1842 "y.tab.c"
    break;

  case 69: /* expression: value GREATER value  */
#line 157 "Comp.yacc"
                                  {(yyval.nodeval) = mknode(">", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1848 "y.tab.c"
    break;

  case 70: /* expression: value GREATER_EQ value  */
#line 158 "Comp.yacc"
                                     {(yyval.nodeval) = mknode(">=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1854 "y.tab.c"
    break;

  case 71: /* expression: value EQUAL value  */
#line 159 "Comp.yacc"
                                {(yyval.nodeval) = mknode("==", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1860 "y.tab.c"
    break;

  case 72: /* expression: value NOT_EQ value  */
#line 160 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("!=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1866 "y.tab.c"
    break;

  case 73: /* expression: NOT value  */
#line 161 "Comp.yacc"
                        {(yyval.nodeval) = mknode("! (not)", (yyvsp[0].nodeval), NULL);}
#line 1872 "y.tab.c"
    break;

  case 74: /* expression: value  */
#line 162 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1878 "y.tab.c"
    break;

  case 75: /* expression: '(' expression ')'  */
#line 163 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("( )", (yyvsp[-1].nodeval), NULL);}
#line 1884 "y.tab.c"
    break;

  case 76: /* expression: expression OR expression  */
#line 164 "Comp.yacc"
                                       {(yyval.nodeval) = mknode("||", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1890 "y.tab.c"
    break;

  case 77: /* expression: expression AND expression  */
#line 165 "Comp.yacc"
                                        {(yyval.nodeval) = mknode("&&", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1896 "y.tab.c"
    break;

  case 78: /* expression: value ADD value  */
#line 166 "Comp.yacc"
                              {(yyval.nodeval) = mknode("+", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1902 "y.tab.c"
    break;

  case 79: /* expression: value SUB value  */
#line 167 "Comp.yacc"
                              {(yyval.nodeval) = mknode("-", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1908 "y.tab.c"
    break;

  case 80: /* expression: value MULT value  */
#line 168 "Comp.yacc"
                               {(yyval.nodeval) = mknode("*", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1914 "y.tab.c"
    break;

  case 81: /* expression: value DIVIDE value  */
#line 169 "Comp.yacc"
                                 {(yyval.nodeval) = mknode("/", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1920 "y.tab.c"
    break;

  case 82: /* expression: '|' value '|'  */
#line 170 "Comp.yacc"
                            {(yyval.nodeval) = mknode("length of array", (yyvsp[-1].nodeval), NULL);}
#line 1926 "y.tab.c"
    break;

  case 83: /* value: INT_VAL  */
#line 172 "Comp.yacc"
                {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1932 "y.tab.c"
    break;

  case 84: /* value: FLOAT_VAL  */
#line 173 "Comp.yacc"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1938 "y.tab.c"
    break;

  case 85: /* value: DOUBLE_VAL  */
#line 174 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1944 "y.tab.c"
    break;

  case 86: /* value: ID  */
#line 175 "Comp.yacc"
             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1950 "y.tab.c"
    break;

  case 87: /* value: TRUE_VAL  */
#line 176 "Comp.yacc"
                   {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1956 "y.tab.c"
    break;

  case 88: /* value: FALSE_VAL  */
#line 177 "Comp.yacc"
                    {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1962 "y.tab.c"
    break;

  case 89: /* value: CHAR_VAL  */
#line 178 "Comp.yacc"
                   {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1968 "y.tab.c"
    break;

  case 90: /* value: STRING_VAL  */
#line 179 "Comp.yacc"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1974 "y.tab.c"
    break;


#line 1978 "y.tab.c"

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

#line 180 "Comp.yacc"

#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        printf("syntax error, line: %d\n", yylineno);
        return 0;
}
