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
#line 1 "Comp.y"

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
#line 4 "Comp.y"

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
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_do_while_statement = 61,        /* do_while_statement  */
  YYSYMBOL_while_statement = 62,           /* while_statement  */
  YYSYMBOL_for_statement = 63,             /* for_statement  */
  YYSYMBOL_if_statement = 64,              /* if_statement  */
  YYSYMBOL_else_statement = 65,            /* else_statement  */
  YYSYMBOL_block = 66,                     /* block  */
  YYSYMBOL_statement_recursive = 67,       /* statement_recursive  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_var_assignment = 69,            /* var_assignment  */
  YYSYMBOL_many_id = 70,                   /* many_id  */
  YYSYMBOL_assign_statement = 71,          /* assign_statement  */
  YYSYMBOL_param_type = 72,                /* param_type  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_condition = 74,                 /* condition  */
  YYSYMBOL_math_expression = 75,           /* math_expression  */
  YYSYMBOL_value = 76                      /* value  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
static const yytype_int8 yyrline[] =
{
       0,    37,    37,    39,    41,    43,    46,    47,    49,    51,
      52,    54,    55,    57,    58,    59,    60,    61,    62,    63,
      65,    66,    68,    69,    70,    71,    73,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    87,    88,    89,    90,
      92,    93,    94,    95,    96,    97,    98,    99,   101,   102,
     103,   104,   105,   107,   108,   109,   110
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
  "non_else", "'('", "')'", "'{'", "'}'", "':'", "$accept", "program",
  "do_while_statement", "while_statement", "for_statement", "if_statement",
  "else_statement", "block", "statement_recursive", "statement",
  "var_assignment", "many_id", "assign_statement", "param_type",
  "expression", "condition", "math_expression", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -44,    13,   -72,   -11,   -72,   106,   -17,    83,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -40,    56,
     -72,   -72,   -72,   -72,   -24,    92,   -10,   -72,   -72,   -72,
      -9,   -72,   107,    83,    83,    83,    83,    83,    83,    83,
      83,    83,   -28,    -2,   -72,    83,    83,    83,    83,   -72,
     -72,   -21,   -72,   -72,   -72,   -72,   -72,   -72,    56,   -10,
      -1,   -72,   -72,   -72,   -72,   -72,    34,   -72,   -72,   -10,
       0,   -72,    34,     2,   -17,    48,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     6,   -72,    83,    37,    83,    -5,   -72,
     -72,    31,    12,    36,   -72,   -72,    34,    83,    34,    52,
      68,   -72,    34,   -72,    17,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,    30,
      27,    29,    28,    31,    34,    33,    32,    35,     0,     0,
      56,    53,    54,    55,     0,     0,     0,    39,    38,    37,
       0,    36,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    21,     0,     0,     0,     0,    47,
      46,     0,    44,    42,    43,    40,    41,    45,     0,     0,
      24,    20,    48,    49,    50,    51,     0,    26,    23,     0,
       0,    19,     0,     0,    56,     0,    18,    17,    16,    15,
       5,     9,    13,     0,    22,     0,     0,     0,     0,    11,
      14,     0,     0,     0,    10,    12,     0,     0,     0,     6,
       0,     4,     0,     7,     0,     8,     3
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,    81,   -72,   -72,    -3,   -72,   -71,
      84,   -47,   -72,   -72,    27,   -32,   -12,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    76,    77,    78,    79,   103,    80,    88,    81,
      82,    43,    60,    18,    30,    24,    83,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    49,    50,    58,    89,     6,     1,    31,     1,    70,
       4,     6,    68,     5,    19,    33,    34,    95,    26,    71,
      72,    73,    84,    51,    59,    25,    25,    35,    52,    53,
      54,    55,    56,    57,    66,     7,    42,    62,    63,    64,
      65,    74,    44,    21,    22,    23,    31,     1,    70,    61,
       6,    69,    94,    91,    85,    93,    87,    90,    71,    72,
      73,     1,    70,    92,     6,   100,    97,   102,   106,    86,
      33,    34,    71,    72,    73,    33,    34,    25,    27,    25,
      74,     3,    21,    22,    23,    67,    96,     0,     8,    25,
      75,    98,     0,    99,    74,   101,    21,    22,    23,   105,
       0,    28,    20,    29,    21,    22,    23,    33,    34,     9,
      10,    11,    12,     0,    13,    14,    15,    16,    17,     0,
       0,     0,     0,   104,    36,    37,    38,    39,    40,    20,
      41,    21,    22,    23,    45,    46,    47,    48
};

static const yytype_int8 yycheck[] =
{
       8,    33,    34,    31,    75,    16,    13,    19,    13,    14,
      54,    16,    59,     0,    31,    39,    40,    88,    58,    24,
      25,    26,    69,    35,    52,    33,    34,    51,    36,    37,
      38,    39,    40,    41,    55,    46,    46,    45,    46,    47,
      48,    46,    51,    48,    49,    50,    58,    13,    14,    51,
      16,    52,    57,    85,    54,    87,    54,    51,    24,    25,
      26,    13,    14,    26,    16,    97,    54,    15,    51,    72,
      39,    40,    24,    25,    26,    39,    40,    85,    22,    87,
      46,     0,    48,    49,    50,    58,    55,    -1,     4,    97,
      56,    55,    -1,    96,    46,    98,    48,    49,    50,   102,
      -1,    45,    46,    47,    48,    49,    50,    39,    40,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    55,    32,    33,    34,    35,    36,    46,
      38,    48,    49,    50,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    60,    63,    54,     0,    16,    46,    69,     3,
       4,     5,     6,     8,     9,    10,    11,    12,    72,    31,
      46,    48,    49,    50,    74,    76,    58,    22,    45,    47,
      73,    75,    76,    39,    40,    51,    32,    33,    34,    35,
      36,    38,    46,    70,    51,    27,    28,    29,    30,    74,
      74,    75,    76,    76,    76,    76,    76,    76,    31,    52,
      71,    51,    76,    76,    76,    76,    55,    73,    70,    52,
      14,    24,    25,    26,    46,    56,    61,    62,    63,    64,
      66,    68,    69,    75,    70,    54,    66,    54,    67,    68,
      51,    74,    26,    74,    57,    68,    55,    54,    55,    66,
      74,    66,    15,    65,    55,    66,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     7,     5,     8,     5,     6,     2,     1,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       5,     4,     4,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1
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
  case 2: /* program: for_statement  */
#line 37 "Comp.y"
                        {(yyval.nodeval) = (yyvsp[0].nodeval); printtree((yyval.nodeval), 0);}
#line 1369 "y.tab.c"
    break;

  case 3: /* do_while_statement: DO block WHILE '(' condition ')' ';'  */
#line 39 "Comp.y"
                                                          {(yyval.nodeval) = mknode("do_while_statement", (yyvsp[-5].nodeval), (yyvsp[-2].nodeval));}
#line 1375 "y.tab.c"
    break;

  case 4: /* while_statement: WHILE '(' condition ')' block  */
#line 41 "Comp.y"
                                                {(yyval.nodeval) = mknode("while_statement", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1381 "y.tab.c"
    break;

  case 5: /* for_statement: FOR '(' var_assignment condition ';' math_expression ')' block  */
#line 44 "Comp.y"
                        {(yyval.nodeval) = mknode("for", mknode("var_assignment", (yyvsp[-5].nodeval), mknode("condition", (yyvsp[-4].nodeval), mknode("math_expression", (yyvsp[-2].nodeval), NULL))), mknode("for_block", (yyvsp[0].nodeval), NULL));}
#line 1387 "y.tab.c"
    break;

  case 6: /* if_statement: IF '(' condition ')' block  */
#line 46 "Comp.y"
                                                         {(yyval.nodeval) = mknode("if", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1393 "y.tab.c"
    break;

  case 7: /* if_statement: IF '(' condition ')' block else_statement  */
#line 47 "Comp.y"
                                                            {(yyval.nodeval) = mknode("if", (yyvsp[-3].nodeval), mknode(" ", (yyvsp[-1].nodeval), (yyvsp[0].nodeval)));}
#line 1399 "y.tab.c"
    break;

  case 8: /* else_statement: ELSE block  */
#line 49 "Comp.y"
                            {(yyval.nodeval) = mknode("else", (yyvsp[0].nodeval), NULL);}
#line 1405 "y.tab.c"
    break;

  case 9: /* block: statement  */
#line 51 "Comp.y"
                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1411 "y.tab.c"
    break;

  case 10: /* block: '{' statement_recursive '}'  */
#line 52 "Comp.y"
                                      {(yyval.nodeval) = mknode("block", (yyvsp[-1].nodeval),NULL);}
#line 1417 "y.tab.c"
    break;

  case 11: /* statement_recursive: statement  */
#line 54 "Comp.y"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1423 "y.tab.c"
    break;

  case 12: /* statement_recursive: statement_recursive statement  */
#line 55 "Comp.y"
                                                    {(yyval.nodeval) = mknode("statements", (yyvsp[-1].nodeval), (yyvsp[0].nodeval));}
#line 1429 "y.tab.c"
    break;

  case 13: /* statement: var_assignment  */
#line 57 "Comp.y"
                           {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1435 "y.tab.c"
    break;

  case 14: /* statement: math_expression ';'  */
#line 58 "Comp.y"
                                      {(yyval.nodeval) = (yyvsp[-1].nodeval);}
#line 1441 "y.tab.c"
    break;

  case 15: /* statement: if_statement  */
#line 59 "Comp.y"
                               {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1447 "y.tab.c"
    break;

  case 16: /* statement: for_statement  */
#line 60 "Comp.y"
                                {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1453 "y.tab.c"
    break;

  case 17: /* statement: while_statement  */
#line 61 "Comp.y"
                                  {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1459 "y.tab.c"
    break;

  case 18: /* statement: do_while_statement  */
#line 62 "Comp.y"
                                     {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1465 "y.tab.c"
    break;

  case 19: /* statement: COMMENT  */
#line 63 "Comp.y"
                          {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1471 "y.tab.c"
    break;

  case 20: /* var_assignment: VAR param_type ':' many_id ';'  */
#line 65 "Comp.y"
                                                {(yyval.nodeval) = mknode("new var", (yyvsp[-3].nodeval), (yyvsp[-1].nodeval));}
#line 1477 "y.tab.c"
    break;

  case 21: /* var_assignment: ID ASSIGN expression ';'  */
#line 66 "Comp.y"
                                            {(yyval.nodeval) = mknode("assign", mknode((yyvsp[-3].strval), (yyvsp[-1].nodeval), NULL), NULL);}
#line 1483 "y.tab.c"
    break;

  case 22: /* many_id: ID assign_statement ',' many_id  */
#line 68 "Comp.y"
                                          {(yyval.nodeval) = mknode((yyvsp[-3].strval), (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1489 "y.tab.c"
    break;

  case 23: /* many_id: ID ',' many_id  */
#line 69 "Comp.y"
                           {(yyval.nodeval) = mknode((yyvsp[-2].strval), (yyvsp[0].nodeval), NULL);}
#line 1495 "y.tab.c"
    break;

  case 24: /* many_id: ID assign_statement  */
#line 70 "Comp.y"
                                {(yyval.nodeval) = mknode((yyvsp[-1].strval), (yyvsp[0].nodeval), NULL);}
#line 1501 "y.tab.c"
    break;

  case 25: /* many_id: ID  */
#line 71 "Comp.y"
               {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1507 "y.tab.c"
    break;

  case 26: /* assign_statement: ASSIGN expression  */
#line 73 "Comp.y"
                                     {(yyval.nodeval) = mknode("assign", (yyvsp[0].nodeval), NULL);}
#line 1513 "y.tab.c"
    break;

  case 27: /* param_type: INT  */
#line 77 "Comp.y"
                 {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1519 "y.tab.c"
    break;

  case 28: /* param_type: FLOAT  */
#line 78 "Comp.y"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1525 "y.tab.c"
    break;

  case 29: /* param_type: DOUBLE  */
#line 79 "Comp.y"
                      {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1531 "y.tab.c"
    break;

  case 30: /* param_type: CHAR  */
#line 80 "Comp.y"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1537 "y.tab.c"
    break;

  case 31: /* param_type: INT_PTR  */
#line 81 "Comp.y"
                       {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1543 "y.tab.c"
    break;

  case 32: /* param_type: FLOAT_PTR  */
#line 82 "Comp.y"
                         {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1549 "y.tab.c"
    break;

  case 33: /* param_type: DOUBLE_PTR  */
#line 83 "Comp.y"
                          {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1555 "y.tab.c"
    break;

  case 34: /* param_type: CHAR_PTR  */
#line 84 "Comp.y"
                        {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1561 "y.tab.c"
    break;

  case 35: /* param_type: BOOL  */
#line 85 "Comp.y"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval),NULL,NULL);}
#line 1567 "y.tab.c"
    break;

  case 36: /* expression: math_expression  */
#line 87 "Comp.y"
                             {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1573 "y.tab.c"
    break;

  case 37: /* expression: CHAR_VAL  */
#line 88 "Comp.y"
                           {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1579 "y.tab.c"
    break;

  case 38: /* expression: STRING_VAL  */
#line 89 "Comp.y"
                             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1585 "y.tab.c"
    break;

  case 39: /* expression: NULL_VALUE  */
#line 90 "Comp.y"
                             {(yyval.nodeval) = mknode((yyvsp[0].nodeval), NULL, NULL);}
#line 1591 "y.tab.c"
    break;

  case 40: /* condition: value LESSER value  */
#line 92 "Comp.y"
                               {(yyval.nodeval) = mknode("<", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1597 "y.tab.c"
    break;

  case 41: /* condition: value LESSER_EQ value  */
#line 93 "Comp.y"
                                        {(yyval.nodeval) = mknode("<=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1603 "y.tab.c"
    break;

  case 42: /* condition: value GREATER value  */
#line 94 "Comp.y"
                                      {(yyval.nodeval) = mknode(">", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1609 "y.tab.c"
    break;

  case 43: /* condition: value GREATER_EQ value  */
#line 95 "Comp.y"
                                         {(yyval.nodeval) = mknode(">=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1615 "y.tab.c"
    break;

  case 44: /* condition: value EQUAL value  */
#line 96 "Comp.y"
                                    {(yyval.nodeval) = mknode("==", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1621 "y.tab.c"
    break;

  case 45: /* condition: value NOT_EQ value  */
#line 97 "Comp.y"
                                     {(yyval.nodeval) = mknode("!=", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1627 "y.tab.c"
    break;

  case 46: /* condition: condition OR condition  */
#line 98 "Comp.y"
                                         {(yyval.nodeval) = mknode("||", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1633 "y.tab.c"
    break;

  case 47: /* condition: condition AND condition  */
#line 99 "Comp.y"
                                          {(yyval.nodeval) = mknode("&&", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1639 "y.tab.c"
    break;

  case 48: /* math_expression: value ADD value  */
#line 101 "Comp.y"
                                  {(yyval.nodeval) = mknode("+", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1645 "y.tab.c"
    break;

  case 49: /* math_expression: value SUB value  */
#line 102 "Comp.y"
                                      {(yyval.nodeval) = mknode("-", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1651 "y.tab.c"
    break;

  case 50: /* math_expression: value MULT value  */
#line 103 "Comp.y"
                                       {(yyval.nodeval) = mknode("*", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1657 "y.tab.c"
    break;

  case 51: /* math_expression: value DIVIDE value  */
#line 104 "Comp.y"
                                         {(yyval.nodeval) = mknode("/", (yyvsp[-2].nodeval), (yyvsp[0].nodeval));}
#line 1663 "y.tab.c"
    break;

  case 52: /* math_expression: value  */
#line 105 "Comp.y"
                            {(yyval.nodeval) = (yyvsp[0].nodeval);}
#line 1669 "y.tab.c"
    break;

  case 53: /* value: INT_VAL  */
#line 107 "Comp.y"
                {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1675 "y.tab.c"
    break;

  case 54: /* value: FLOAT_VAL  */
#line 108 "Comp.y"
                    {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1681 "y.tab.c"
    break;

  case 55: /* value: DOUBLE_VAL  */
#line 109 "Comp.y"
                     {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1687 "y.tab.c"
    break;

  case 56: /* value: ID  */
#line 110 "Comp.y"
             {(yyval.nodeval) = mknode((yyvsp[0].strval), NULL, NULL);}
#line 1693 "y.tab.c"
    break;


#line 1697 "y.tab.c"

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

#line 112 "Comp.y"

#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        printf("syntax error, line: %d\n", yylineno);
        return 0;
}
