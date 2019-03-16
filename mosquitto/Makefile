# $NetBSD$

DISTNAME=	mosquitto-1.5.8
CATEGORIES=	pbd
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mosquitto.org/files/source/
COMMENT=	An open source MQTT broker
LICENSE=	epl-v1.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKG_GROUPS=		mosquitto
PKG_USERS=		mosquitto:mosquitto
PKG_GECOS.mosquitto=	Mosquitto MQTT Broker
PKG_HOME.mosquitto=	/var/lib/mosquitto

PKGCONFIG_OVERRIDE+=	libmosquitto.pc.in
PKGCONFIG_OVERRIDE+=	libmosquittopp.pc.in

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/openssl/builtin.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
