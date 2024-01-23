#include <config.h>

#if HAVE_GNUSPARC_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-gnusparc.c>
#elif HAVE_GNUM68K_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-gnum68k.c>
#elif HAVE_GNUPPC_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-gnuppc.c>
#elif HAVE_GNUX86_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-gnux86.c>
#elif HAVE_HPUX11_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-hpux11.c>
#elif HAVE_HPUX_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-hpux.c>
#elif HAVE_SUNOS4_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-sunos4.c>
#elif HAVE_SOLARIS_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-solaris.c>
#elif HAVE_IRIX_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-irix.c>
#elif HAVE_AIX_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-aix.c>
#elif HAVE_TRU64_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-tru64.c>
#elif HAVE_FREEBSD_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-freebsd.c>
#elif HAVE_OS2EMX_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-os2emx.c>
#elif HAVE_NETBSD_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-netbsd.c>
#elif HAVE_OPENBSD_IEEE_INTERFACE
#include <gsl/ieee-utils/fp-openbsd.c>
/* Try to handle universal binaries */
#elif HAVE_DARWIN_IEEE_INTERFACE
# if defined(__i386__)
#  include <gsl/ieee-utils/fp-darwin86.c>
#else
#  include <gsl/ieee-utils/fp-darwin.c>
# endif
#elif HAVE_DARWIN86_IEEE_INTERFACE
# if defined(__ppc__)
#  include <gsl/ieee-utils/fp-darwin.c>
# else
#  include <gsl/ieee-utils/fp-darwin86.c>
#endif
#elif HAVE_DECL_FEENABLEEXCEPT || HAVE_DECL_FESETTRAPENABLE
#include <gsl/ieee-utils/fp-gnuc99.c>
#else
#include <gsl/ieee-utils/fp-unknown.c> 
#endif
