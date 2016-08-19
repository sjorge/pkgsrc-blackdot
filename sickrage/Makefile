# $NetBSD$

DISTNAME=	sickrage-${DISTVERSION}
DISTVERSION=	2016.07.31
COMMIT_SHA=	4e8b9ee
CATEGORIES=	news
MASTER_SITES=	-https://github.com/SickRage/SickRage/tarball/${COMMIT_SHA}
DISTFILE= 	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	https://sickrage.github.io/
COMMENT=	SickRage is an automatic Video Library Manager for TV Shows.
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

TEMP_DIR= 	SickRage-SickRage-${COMMIT_SHA}
WRKSRC= 	${WRKDIR}/${TEMP_DIR}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=		sickrage
PKG_USERS=		sickrage:sickrage
PKG_GECOS.sickrage=	serie download manager
PKG_HOME.sickrage=	${PKG_SYSCONFDIR}/sickrage
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/sickrage sickrage sickrage 0755

SMF_NAME?=              sickrage

AUTO_MKDIRS=	yes

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py */*/*/*/*/*.py */*/*/*/*/*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		SickBeard.py
SUBST_SED.fix-paths=		-e 's,%%PREFIX%%,${PREFIX},g'
INSTALL_DIRS+=			sickrage sickbeard lib gui locale
INSTALL_FILES+=			SickBeard.py readme.md COPYING.txt

do-install:
	${MKDIR} ${DESTDIR}/${PKG_SYSCONFDIR}/sickrage
	${MKDIR} ${DESTDIR}/${PREFIX}/share/SickRage
	${MKDIR} ${DESTDIR}/${PREFIX}/share/SickRage
	${MKDIR} ${DESTDIR}/${PREFIX}/share/SickRage/lib
	${MKDIR} -m 0777 ${DESTDIR}/${PREFIX}/share/SickRage/lib/adba
.for i in ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/SickRage
.endfor
.for i in ${INSTALL_FILES}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/SickRage
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
