# $NetBSD$

DISTNAME=	sabyenc-${DISTVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
DISTVERSION=	3.3.2
#DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

CATEGORIES=	news
MASTER_SITES=   ${MASTER_SITE_PYPI:=s/sabyenc/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	https://pypi.python.org/pypi/sabyenc/
COMMENT=	Mofied the original yenc module by Alessandro Duca for use within SABnzbd.
LICENSE=	gnu-lgpl-v3

REPLACE_PYTHON=	*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35	# for 2.x only

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
