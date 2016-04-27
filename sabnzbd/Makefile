# $NetBSD$

DISTNAME=	sabnzbd-${DISTVERSION}
DISTVERSION=	1.0.1
DISTFILES=	SABnzbd-${DISTVERSION}-src${EXTRACT_SUFX}
CATEGORIES=	news
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE:=sabnzbdplus/sabnzbdplus/}${DISTVERSION}/

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://sabnzbdplus.sourceforge.net/
COMMENT=	Web-interface based binary newsgrabber in python, with nzb support
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml
DEPENDS+=	par2-[0-9]*:../../archivers/par2                               # par2 support
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar                             # unrar support
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip                             # unzip support
DEPENDS+=	p7zip-[0-9]*:../../archivers/p7zip                             # 7zip support
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser  # feedparser support
DEPENDS+=	${PYPKGPREFIX}-yenc-[0-9]*:../../pbd/py-yenc                   # yenc support
DEPENDS+=	openssl-[0-9]*:../../security/openssl                          # openssl support
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}
USE_TOOLS=	pax

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=		sabnzbd
PKG_USERS=		sabnzbd:sabnzbd
PKG_GECOS.sabnzbd=	sabnbzd usenet download manager
PKG_HOME.sabnzbd=	${PKG_SYSCONFDIR}/sabnzbd
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/sabnzbd sabnzbd sabnzbd 0750

SMF_NAME?=              sabnzbd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah, py-xml
PY_PATCHPLIST=          yes
PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=		*.py */*.py */*/*.py

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=Fix absolute paths.
SUBST_FILES.fix-paths=	SABnzbd.py
SUBST_SED.fix-paths=	-e 's,%%PREFIX%%,${PREFIX},g'


do-install:
	${MKDIR} ${DESTDIR}/${PKG_SYSCONFDIR}/sabnzbd
	${MKDIR} ${DESTDIR}/${PREFIX}/share/SABnzbd
	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}/${PREFIX}/share/SABnzbd

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
