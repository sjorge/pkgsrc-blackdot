# $NetBSD: Makefile,v 1.23 2016/09/01 16:33:43 wiz Exp $

DISTNAME=	par2-mt-0.6.14
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jkansanen/}
GITHUB_PROJECT=	par2cmdline-mt
GITHUB_TAG=	v${PKGVERSION_NOREV}-mt1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jkansanen/par2cmdline-mt/
COMMENT=	PAR 2.0 compatible file verification and repair tool
LICENSE=	gnu-gpl-v2

CONFLICTS=      par2-[0-9]*

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake autoreconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
