# $NetBSD$

DISTNAME=	pbd-sabnzbd-${DISTVERSION}
DISTVERSION=	0.7.20
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
DEPENDS+=	pbd-${PYPKGPREFIX}-configobj-[0-9]*:../../pbd/py-configobj
#unzip
#7zip

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SABnzbd-${DISTVERSION}
USE_TOOLS=	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah, py-xml

.include "options.mk"

PKG_GROUPS=		sabnzbd
PKG_USERS=		sabnzbd:sabnzbd
PKG_HOME.sabnzbd=	${PREFIX}/sabnzbd

OWN_DIRS_PERMS=		${PREFIX}/sabnzbd sabnzbd sabnzbd 0755

INSTALLATION_DIRS+=	cherrypy gntp interfaces locale po tools util

PY_PATCHPLIST=          yes
PLIST_SUBST+=           PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=		*.py */*.py */*/*.py

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=Fix absolute paths.
SUBST_FILES.fix-paths=	SABnzbd.py
SUBST_SED.fix-paths=	-e 's,%%PREFIX%%,${PREFIX},g'

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw SABnzbd.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sabnzbd ${DESTDIR}/${PREFIX}/${PYSITELIB}/
.for i in ${INSTALLATION_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sabnzbdplus
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sabnzbdplus
.endfor
	cd ${.CURDIR}/files && pax -rw -pmp sabnzbd.xml ${DESTDIR}/${PREFIX}/share/sabnzbdplus

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"