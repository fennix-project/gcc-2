
#undef  TARGET_FENNIX
#define TARGET_FENNIX 1

#undef  LIB_SPEC
#define LIB_SPEC "-lc"

#undef  CPP_SPEC
#define CPP_SPEC "%{posix:-D_POSIX_SOURCE} %{pthread:-D_POSIX_THREADS}"

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC        \
 "crti.o%s                    \
  %{!shared:                  \
    %{!static:                \
      crtbeginS.o%s Scrt1.o%s \
    }                         \
  }                           \
  %{static:crtbegin.o%s crt1.o%s}"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC        \
 "crtn.o%s                  \
  %{!shared:                \
    %{!static:              \
      crtendS.o%s           \
    }                       \
  }                         \
  %{static:crtend.o%s}"

#undef  STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/lib/"

#undef  LINK_SPEC
#define LINK_SPEC                       \
 "%{shared:-shared}                     \
  %{static:-static}                     \
  %{!shared:                            \
    %{!static:                          \
      %{rdynamic:-export-dynamic}       \
    }                                   \
  }                                     \
  %{!static:                            \
    %{!dynamic-linker:                  \
      -dynamic-linker=/lib/ld.so        \
    }                                   \
  }                                     \
  -z max-page-size=4096"

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()       \
  do                                   \
  {                                    \
      builtin_define("__fennix__");    \
      builtin_define("__unix__");      \
      builtin_assert("system=fennix"); \
      builtin_assert("system=unix");   \
      builtin_assert("system=posix");  \
  } while (0);
