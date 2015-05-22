# $NetBSD$

DISTNAME=	sickbeard-0.0.20141116
COMMIT_SHA=	db2658a
CATEGORIES=	news
MASTER_SITES=	-https://github.com/midgetspy/Sick-Beard/tarball/${COMMIT_SHA}
DISTFILE= 	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wongk@apt.homeunix.net
HOMEPAGE=	http://sickbeard.com/
COMMENT=	Search for TV series nzb-files via web interface
# sickbeard, cherrypy, simplejson, jquery, gntp, tvdb_api
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC= 	${WRKDIR}/midgetspy-Sick-Beard-${COMMIT_SHA}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=	dlmgr
PKG_USERS=	dlmgr:dlmgr
PKG_GECOS.dlmgr=Download Manager Daemon
PKG_HOME.dlmgr=	${PKG_SYSCONFDIR}/dlmgr
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/dlmgr dlmgr dlmgr 0755

INSTALLATION_DIRS+=	autoProcessTV cherrypy data lib COPYING.txt CHANGELOG.txt

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	*.py */*.py */*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths= 		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		SickBeard.py
SUBST_SED.fix-paths=		-e 's,/opt/sickbeard,${PREFIX}/share/sickbeard,g'

do-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw SickBeard.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp sickbeard ${DESTDIR}/${PREFIX}/${PYSITELIB}/
.for i in ${INSTALLATION_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/sickbeard
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/sickbeard
.endfor
	${RM} -rf ${DESTDIR}/${PREFIX}/share/sickbeard/lib/tvdb_api/tests

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
