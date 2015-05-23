# $NetBSD$

DISTNAME=	couchpotato-2.6.3
COMMIT_SHA=	965b808 
CATEGORIES=	news
MASTER_SITES=	-https://github.com/RuudBurger/CouchPotatoServer/tarball/${COMMIT_SHA}
DISTFILE= 	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sjorge@blackdot.be
HOMEPAGE=	http://couchpota.tom/
COMMENT=	Search for movies nzb-files via web interface
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND unlicense

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

TEMP_DIR= 	RuudBurger-CouchPotatoServer-${COMMIT_SHA}
WRKSRC= 	${WRKDIR}/${TEMP_DIR}
NO_BUILD= 	yes
USE_TOOLS= 	pax

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

BUILD_DEFS+=		PKG_SYSCONFDIR

PKG_GROUPS=	dlmgr
PKG_USERS=	dlmgr:dlmgr
PKG_GECOS.dlmgr=Download Manager Daemon
PKG_HOME.dlmgr=	${PKG_SYSCONFDIR}/dlmgr
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/dlmgr dlmgr dlmgr 0755

INSTALL_DIRS+= 	libs
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
	${MKDIR} ${DESTDIR}/${PREFIX}/bin
	cd ${WRKSRC} && pax -rw CouchPotato.py ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${PREFIX}/${PYSITELIB}/
	cd ${WRKSRC} && pax -rw -pmp couchpotato ${DESTDIR}/${PREFIX}/${PYSITELIB}/
.for i in ${INSTALL_DIRS}
	${MKDIR} ${DESTDIR}/${PREFIX}/share/couchpotato
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}/${PREFIX}/share/couchpotato
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
