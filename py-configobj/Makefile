# $NetBSD: Makefile,v 1.1 2014/03/31 08:10:05 wiz Exp $

DISTNAME=	configobj-5.0.6
CATEGORIES=	python
MASTER_SITES=	https://pypi.python.org/packages/source/c/configobj/

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	https://pypi.python.org/pypi/configobj/5.0.6
COMMENT=	Config file reading, writing and validation.
LICENSE=	mit

REPLACE_PYTHON= *.py
PYDISTUTILSPKG= no

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

#pre-configure:
#	sed s#distutils.core#setuptools#g ${WRKDIR}/${DISTNAME}/setup.py > ${WRKDIR}/${DISTNAME}/setup.py.patched

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
