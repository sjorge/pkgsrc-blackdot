# $NetBSD: Makefile,v 1.50 2018/03/12 11:16:20 wiz Exp $

PKGVERSION=		3.2
DISTNAME=		git-cola-${PKGVERSION}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		-https://github.com/git-cola/git-cola/archive/v${PKGVERSION}.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/git-cola/git-cola/
COMMENT=		GUI for git
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=		${PYPKGPREFIX}-argparse>=1.1:../../textproc/py-iniparse
DEPENDS+=		${PYPKGPREFIX}-qt5>=5.4:../../x11/py-qt5
USE_TOOLS+=		msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
