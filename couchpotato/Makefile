# $NetBSD$

DISTNAME=	couchpotato-2.6.3
PKGNAME=	pbd-${DISTNAME}
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

PKG_GROUPS= 	couchpotato
PKG_USERS= 	couchpotato:couchpotato
PKG_HOME.couchpotato= ${PREFIX}/couchpotato

INSTALL_DIRS+= 	couchpotato libs
INSTALL_FILES+= CouchPotato.py version.py icon_mac.png
AUTO_MKDIRS=	yes

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py */*/*/*/*/*.py */*/*/*/*/*/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths= 		pre-configure
SUBST_MESSAGE.fix-paths=	Fix absolute paths.
SUBST_FILES.fix-paths=		init/solaris11
SUBST_SED.fix-paths=		-e 's,/opt/couchpotato,${PREFIX}/couchpotato,g'

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/couchpotato
	${CP} ${WRKSRC}/init/solaris11 ${DESTDIR}${PREFIX}/couchpotato/init.solaris11
.for i in ${INSTALL_FILES} ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}${PREFIX}/couchpotato/
.endfor
	@${ECHO} ${COMMIT_SHA} > ${DESTDIR}${PREFIX}/couchpotato/version.txt

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
