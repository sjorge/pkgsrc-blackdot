# $NetBSD$

DISTNAME=	couchpotato-3.0.1
COMMIT_SHA=	e9593f6 
CATEGORIES=	news
MASTER_SITES=	-https://github.com/CouchPotato/CouchPotatoServer/tarball/${COMMIT_SHA}
DISTFILE= 	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	http://couchpota.tom/
COMMENT=	Search for movies nzb-files via web interface
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

TEMP_DIR= 	CouchPotato-CouchPotatoServer-${COMMIT_SHA}
WRKSRC= 	${WRKDIR}/${TEMP_DIR}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=		couchpotato
PKG_USERS=		couchpotato:couchpotato
PKG_GECOS.couchpotato=	movie download manager
PKG_HOME.couchpotato=	${PKG_SYSCONFDIR}/couchpotato
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR}/couchpotato couchpotato couchpotato 0755

SMF_NAME?=              couchpotato

AUTO_MKDIRS=	yes

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py */*/*/*/*/*.py */*/*/*/*/*/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		CouchPotato.py
SUBST_SED.fix-paths=		-e 's,%%PREFIX%%,${PREFIX},g'

do-install:
	${MKDIR} ${DESTDIR}/${PKG_SYSCONFDIR}/couchpotato
	${MKDIR} ${DESTDIR}/${PREFIX}/share/CouchPotato
	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}/${PREFIX}/share/CouchPotato

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
