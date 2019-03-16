# $NetBSD$

DISTNAME=	mosquitto-1.5.8
CATEGORIES=	pbd
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mosquitto.org/files/source/
COMMENT=	Open source MQTT broker
LICENSE=	epl-v1.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmosquitto.pc.in
PKGCONFIG_OVERRIDE+=	libmosquittopp.pc.in

LDFLAGS.SunOS+=		-lsocket

## configure the user, group and home
MOSQUITTO_USER?=	mqtt
MOSQUITTO_GROUP?=	mqtt
MOSQUITTO_HOME?=	${VARBASE}/lib/mqtt

FILES_SUBST+=		MOSQUITTO_USER=${MOSQUITTO_USER}
FILES_SUBST+=		MOSQUITTO_GROUP=${MOSQUITTO_GROUP}
FILES_SUBST+=		MOSQUITTO_HOME=${MOSQUITTO_HOME}
BUILD_DEFS+=		MOSQUITTO_HOME VARBASE

PKG_GROUPS_VARS+=	MOSQUITTO_GROUP
PKG_USERS_VARS+=	MOSQUITTO_USER

PKG_GROUPS=			${MOSQUITTO_GROUP}
PKG_USERS=			${MOSQUITTO_USER}:${MOSQUITTO_GROUP}
PKG_GECOS.${MOSQUITTO_USER}=	Mosquitto MQTT Broker
PKG_HOME.${MOSQUITTO_USER}=	${MOSQUITTO_HOME}

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
INSTALLATION_DIRS+= ${PKGMANDIR}/

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/
.endif

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
