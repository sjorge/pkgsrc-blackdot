# $NetBSD$
#

DISTNAME=		znc-1.6.0
CATEGORIES=		net
PKGREVISION=		9
MASTER_SITES=		http://znc.in/releases/archive/

MAINTAINER=		florian@geiges.net
HOMEPAGE=		http://znc.in/
COMMENT=		Advanced IRC bouncer with IPv6 and SSL support
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PLIST_SRC=		PLIST
PLIST_SUBST+=		ZNC_USER=znc
PLIST_SUBST+=		PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"
PLIST_SUBST+=		PKG_PREFIX="${PREFIX}"

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

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFDIR
BUILD_DEFS+=		znc
BUILD_DEFS+=		znc

RCD_SCRIPTS+=		znc

MANCOMPRESSED=		yes

.include		"./options.mk"

.include 		"../../devel/libgetopt/buildlink3.mk"
.include		"../../mk/bsd.pkg.mk"
