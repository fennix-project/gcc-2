
#undef TARGET_FENNIX
#define TARGET_FENNIX 1

#undef LIB_SPEC
#define LIB_SPEC "-lc"

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

#undef STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/lib/"

#undef LINK_SPEC
#define LINK_SPEC                      \
"%{shared:-shared}                     \
 %{static:-static}                     \
 %{!shared:                            \
   %{!static:                          \
     %{rdynamic:-export-dynamic}       \
     -dynamic-linker /lib/ld.so        \
    }                                  \
  } -z max-page-size=4096"

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()         \
    do                                   \
    {                                    \
        builtin_define("__fennix__");    \
        builtin_define("__unix__");      \
        builtin_assert("system=fennix"); \
        builtin_assert("system=unix");   \
        builtin_assert("system=posix");  \
    } while (0);
