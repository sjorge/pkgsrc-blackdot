# $NetBSD$
#

DISTNAME=		znc-1.6.4
CATEGORIES=		net
PKGREVISION=		1
MASTER_SITES=		http://znc.in/releases/

MAINTAINER=		florian@geiges.net
HOMEPAGE=		http://znc.in/
COMMENT=		Advanced IRC bouncer with IPv6 and SSL support
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PLIST_SRC=		PLIST

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	znc.pc.in

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		znc
PKG_USERS=		znc:znc
PKG_HOME.znc=		${PKG_SYSCONFDIR}
PKG_GECOS.znc=		ZNC Daemon
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR} znc znc 0755


SUBST_CLASSES+=			fix-man-znc
SUBST_STAGE.fix-man-znc=	pre-configure
SUBST_MESSAGE.fix-man-znc=	Fixing absolute paths in znc.1 manpage.
SUBST_FILES.fix-man-znc=	man/znc.1
SUBST_SED.fix-man-znc=		-e 's,\~\/\.znc,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-man-znc+=		-e 's,\/usr\/local,${PREFIX},g'

SUBST_CLASSES+=			paths
SUBST_MESSAGE.paths=		Fixing paths.
SUBST_FILES.paths=		${WRKDIR}/znc-setup
SUBST_STAGE.paths=		post-patch
SUBST_SED.paths+=		-e 's,@ZNC_USER@,znc,g'
SUBST_SED.paths+=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=		-e 's,@PKG_PREFIX@,${PREFIX},g'

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFDIR
BUILD_DEFS+=		PKG_USERS

RCD_SCRIPTS+=		znc

MANCOMPRESSED=		yes

post-extract:
	${CP} ${FILESDIR}/znc-setup ${WRKDIR}

post-install:
	${INSTALL_SCRIPT} -d ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKDIR}/znc-setup \
		${DESTDIR}${PREFIX}/sbin/znc-setup

.include		"./options.mk"

.include 		"../../devel/libgetopt/buildlink3.mk"
.include		"../../mk/bsd.pkg.mk"
