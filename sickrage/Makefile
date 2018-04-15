# $NetBSD$

DISTNAME=	sickrage-${DISTVERSION}
DISTVERSION=	2018.04.08
COMMIT_SHA=	39c5dc6
CATEGORIES=	news
MASTER_SITES=	-https://github.com/SickRage/SickRage/tarball/${COMMIT_SHA}
DISTFILES=      ${DISTNAME}-1${EXTRACT_SUFX}
DISTFILE= 	${DISTNAME}-1${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	https://sickrage.github.io/
COMMENT=	SickRage is an automatic Video Library Manager for TV Shows.
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.3:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=1.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2.5:../../databases/py-sqlalchemy
USE_LANGUAGES+= c

TEMP_DIR= 	SickRage-SickRage-${COMMIT_SHA}
WRKSRC= 	${WRKDIR}/${TEMP_DIR}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

SICKRAGE_USER=		sickrage
SICKRAGE_GROUP=		sickrage

PKG_GROUPS=		${SICKRAGE_GROUP}
PKG_USERS=		${SICKRAGE_USER}:${SICKRAGE_GROUP}
PKG_GECOS.sickrage=	series download manager
PKG_HOME.sickrage=	${PKG_SYSCONFDIR}/sickrage
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/sickrage ${SICKRAGE_USER} ${SICKRAGE_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/share/SickRage ${SICKRAGE_USER} ${SICKRAGE_GROUP} 0755
SPECIAL_PERMS+=		${PREFIX}/share/SickRage/SickBeard.py ${SICKRAGE_USER} ${SICKRAGE_GROUP} 0750

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
CLEAN_LIBS+=                    tornado markupsafe sqlalchemy lxml

do-install:
	${MKDIR} ${DESTDIR}/${PKG_SYSCONFDIR}/sickrage
	${MKDIR} ${DESTDIR}/${PREFIX}/share/SickRage
.for i in ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw ${i} ${DESTDIR}${PREFIX}/share/SickRage
.endfor
.for i in ${INSTALL_FILES}
	cd ${WRKSRC} && pax -rw ${i} ${DESTDIR}${PREFIX}/share/SickRage
.endfor
.for i in ${CLEAN_LIBS}
	cd ${WRKSRC} && ${RM} -r ${DESTDIR}${PREFIX}/share/SickRage/lib/${i}/
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
