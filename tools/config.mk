CC		=	clang

CFLAGS	=	-fcf-protection -fchar8_t -fstack-protector-strong \
			-fsplit-lto-unit -fsplit-stack

CFLAGS	+=	-fno-access-control -fno-autolink -fno-strict-aliasing \
			-fno-rtti -fno-rtti-data

CFLAGS	+=	-mlvi-cfi -mlvi-hardening -mstack-arg-probe \
			-mseses -msse4.2 -mavx

CLIBS	=	-luser32

C_UNI	=	-H -v