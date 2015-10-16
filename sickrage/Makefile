# $NetBSD$

DISTNAME=	sickrage-${VERSION}
COMMIT_SHA=	3baef95 
VERSION=        4.0.75.3
CATEGORIES=	news
MASTER_SITES=	-https://github.com/SiCKRAGETV/SickRage/tarball/${COMMIT_SHA}
DISTFILE= 	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	http://www.sickrage.tv/
COMMENT=	Search for TV series nzb-files via web interface
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC= 	${WRKDIR}/SiCKRAGETV-SickRage-${COMMIT_SHA}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=	dlmgr
PKG_USERS=	dlmgr:dlmgr
PKG_GECOS.dlmgr=Download Manager Daemon
PKG_HOME.dlmgr=	${PKG_SYSCONFDIR}/dlmgr
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/dlmgr dlmgr dlmgr 0755

INSTALL_DIRS+=	autoProcessTV tornado lib gui runscripts contrib

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	*.py */*.py */*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		SickBeard.py
SUBST_SED.fix-paths=		-e 's,%%PREFIX%%,${PREFIX},g'
SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	pre-configure
SUBST_MESSAGE.fix-version=	Fix Version
SUBST_FILES.fix-version=	sickbeard/versionChecker.py
SUBST_SED.fix-version=		-e 's,%%VERSION%%,${VERSION},g'

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw SickBeard.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sickbeard ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sickrage ${DESTDIR}/${PREFIX}/${PYSITELIB}/
.for i in ${INSTALL_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sickrage
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sickrage
.endfor
	${RM} -rf ${DESTDIR}/${PREFIX}/share/sickrage/lib/tvdb_api/tests
	${RM} -rf ${DESTDIR}/${PREFIX}/share/sickrage/tornado/test

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
