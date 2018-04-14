# $NetBSD: Makefile,v 1.7 2015/05/26 15:17:56 jperkin Exp $

DISTNAME=	samba-${VERSION}
PKGNAME=	samba-pbd-${VERSION}
VERSION=	4.7.6
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.samba.org/pub/samba/

MAINTAINER=	sjorge@acheron.be
HOMEPAGE=	http://www.samba.org/
COMMENT=	custom samba 4.x package with vfs_fruit, vfs_zfsacl, vfs_dirsort, vfs_syncops,...
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFLICTS+=	samba-[0-9]* samba4-[0-9]* ja-samba-[0-9]* pam-smbpass-[0-9]* tdb-[0-9]* winbind-[0-9]*

DEPENDS+=	libgcrypt-[0-9]*:../../security/libgcrypt
BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+= docbook-xsl>=1.75.2:../../textproc/docbook-xsl

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

SMB_LIB?=		${PREFIX}/lib
SMF_NAME?=		samba
SMF_INSTANCES=          nmbd smbd winbindd

PKG_SYSCONFSUBDIR=	samba
SMB_SHAREDSTATE?=	${PREFIX}/com
SMB_LOCALSTATE?=	${VARBASE}
SMB_INFO?=		${PREFIX}/info
SMB_MAN?=		${PREFIX}/${PKGMANDIR}
SMB_STATE?=		${VARBASE}/run
SMB_PRIVATE?=		${SMB_LIB}/samba/private
SMB_PID?=		${VARBASE}/run
SMB_CACHE?=		${VARBASE}/run
SMB_LOCK?=		${VARBASE}/run
SMB_LOGFILEBASE?=	${VARBASE}/log
SMB_SOCKETS?=		${VARBASE}/run
SMB_MODULES?=		${SMB_LIB}/samba
SMB_PRIVATELIB?=	${SMB_LIB}/samba/private
SMB_PRIVSOCKETS?=	${VARBASE}/run
SMB_CONFIG?=		${PKG_SYSCONFDIR}
SMB_DATAROOT?=		${PREFIX}/share/samba
SMB_LOCALE?=		${PREFIX}/share/locale
SMB_DOC?=		${PREFIX}/share/doc/samba
SMB_PAMMODULES?=	${SMB_LIB}/samba/security

FILES_SUBST+=		SMB_CONFIG=${SMB_CONFIG}
FILES_SUBST+=		SMB_PID=${SMB_PID}

USE_TOOLS+=		gmake pkg-config perl:run

REPLACE_PERL=		script/findsmb.in
CHECK_INTERPRETER_SKIP+=bin/findsmb

USE_GNU_ICONV=		yes
BROKEN_GETTEXT_DETECTION=yes

HAS_CONFIGURE=		yes
#CONFIGURE_ENV+=		XSLTPROC=${FALSE} # suppress generation of man pages
CONFIGURE_ARGS+=	--libdir=${SAMBA_LIB}
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	${WRKSRC}/buildtools/bin/waf
CONFIGURE_ARGS+=	configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${SMB_INFO}
CONFIGURE_ARGS+=	--mandir=${SMB_MAN}
CONFIGURE_ARGS+=	--datarootdir=${SMB_DATAROOT}
CONFIGURE_ARGS+=	--localedir=${SMB_LOCALE}
CONFIGURE_ARGS+=	--docdir=${SMB_DOC}
CONFIGURE_ARGS+=	--with-statedir=${SMB_STATE}
CONFIGURE_ARGS+=	--with-privatedir=${SMB_PRIVATE}
CONFIGURE_ARGS+=	--with-piddir=${SMB_PID}
CONFIGURE_ARGS+=	--with-cachedir=${SMB_CACHE}
CONFIGURE_ARGS+=	--with-lockdir=${SMB_LOCK}
CONFIGURE_ARGS+=	--with-logfilebase=${SMB_LOGFILEBASE}
CONFIGURE_ARGS+=	--with-sockets-dir=${SMB_SOCKETS}
CONFIGURE_ARGS+=	--with-modulesdir=${SMB_MODULES}
CONFIGURE_ARGS+=	--with-privatelibdir=${SMB_PRIVATELIB}
CONFIGURE_ARGS+=	--with-privileged-socket-dir=${SMB_PRIVSOCKETS}
CONFIGURE_ARGS+=	--with-configdir=${SMB_CONFIG}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+=	--abi-check-disable
CONFIGURE_ARGS+=	--without-systemd
CONFIGURE_ARGS+=	--disable-cups
CONFIGURE_ARGS+=	--disable-iprint
CONFIGURE_ARGS+=	--disable-cephfs
CONFIGURE_ARGS+=	--disable-glusterfs
#CONFIGURE_ARGS+=	--bundled-libraries=!crypto,ldb,ntdb,talloc,tdb,tevent
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO]))
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif

# extra CF and LD flags
LDFLAGS+=               ${COMPILER_RPATH_FLAG}${SMB_PRIVATELIB} -lintl
LDFLAGS.SunOS+=         -lsocket -lnsl
CFLAGS.SunOS+=		-DHAVE_SOLARIS_GETGRENT_R
PLIST_SUBST+=		LIBEXT=so
SAMBA_LIBEXT=		so
SAMBA_STATIC_MODULES:=	# empty
SAMBA_SHARED_MODULES:=	# empty

###
### Support ACL on ZFS
###
CONFIGURE_ARGS+=	--with-acl-support
SAMBA_SHARED_MODULES:=	${SAMBA_SHARED_MODULES},vfs_zfsacl

###
### Enable APPL extension
###
SAMBA_SHARED_MODULES:=	${SAMBA_SHARED_MODULES},vfs_fruit

###
### Support PAM authentication and build smbpass and winbind PAM modules.
###
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pammodulesdir=${SMB_PAMMODULES}
INSTALLATION_DIRS+=	${EGDIR}/pam_smbpass

###
### LDAP support
###
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap

###
### Support querying a PDC for domain user and group information, e.g.,
### through NSS or PAM.
###
CONFIGURE_ARGS+=	--with-winbind
SAMBA_SHARED_MODULES:= ${SAMBA_SHARED_MODULES},idmap_rid,idmap_autorid,idmap_hash
SAMBA_SHARED_MODULES:= ${SAMBA_SHARED_MODULES},idmap_ad,idmap_ldap

###
### Add the optional static modules to the configuration.
###
.if !empty(SAMBA_STATIC_MODULES)
CONFIGURE_ARGS+=	--with-static-modules=${SAMBA_STATIC_MODULES:S/^,//}
.endif

###
### Add the optionsl shared modules to the configuration
###
.if !empty(SAMBA_SHARED_MODULES)
CONFIGURE_ARGS+=	--with-shared-modules=${SAMBA_SHARED_MODULES:S/^,//}
.endif

.if !defined(PWD_MKDB)
PWD_MKDB!=		${TYPE} pwd_mkdb 2>&1 | \
			${AWK} '/not found/ { print "pwd_mkdb"; exit } { print $$3 }'
MAKEFLAGS+=		PWD_MKDB=${PWD_MKDB:Q}
.endif
FILES_SUBST+=		MKTEMP=${MKTEMP:Q}
FILES_SUBST+=		PWD_MKDB=${PWD_MKDB:Q}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

DOCDIR=			share/doc/${PKGBASE}
EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${PREFIX}/${EGDIR}/smb.conf.default ${SMB_CONFIG}/smb.conf
OWN_DIRS_PERMS=		${SMB_PRIVATE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g'
SUBST_SED.paths+=	-e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@MKTEMP@,${MKTEMP},g'
SUBST_SED.paths+=	-e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@PWD_MKDB@,${PWD_MKDB},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'

SUBST_CLASSES+=		logpath
SUBST_MESSAGE.logpath=	Fixing log path.
SUBST_FILES.logpath=	examples/smb.conf.default
SUBST_STAGE.logpath=	pre-configure
SUBST_SED.logpath+=	-e 's,/usr/local/samba/var/log.%m,${SMB_LOGFILEBASE}/log.%m,g'

CHECK_PORTABILITY_SKIP+=source3/script/tests/test_smbclient_s3.sh

post-install:
	set -e ; cd ${WRKSRC}/docs-xml/registry; for f in *.reg; do \
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${DOCDIR}/$${f}; \
	done
	${INSTALL_DATA} ${WRKSRC}/examples/LDAP/samba.schema \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/smb.conf.default \
		${DESTDIR}${PREFIX}/${EGDIR}
	mkdir -p ${DESTDIR}${SMB_MAN}/man{8,7,5,1}
	${INSTALL_DATA} ${WRKSRC}/docs/manpages/*.8 \
		${DESTDIR}${SMB_MAN}/man8
	${INSTALL_DATA} ${WRKSRC}/docs/manpages/*.7 \
		${DESTDIR}${SMB_MAN}/man7
	${INSTALL_DATA} ${WRKSRC}/docs/manpages/*.5 \
		${DESTDIR}${SMB_MAN}/man5
	${INSTALL_DATA} ${WRKSRC}/docs/manpages/*.1 \
		${DESTDIR}${SMB_MAN}/man1

REPLACE_PERL=	pidl/pidl
REPLACE_PYTHON=	buildtools/bin/waf \
		source4/setup/* \
		source4/scripting/bin/* \
		lib/subunit/python/subunit/run.py \
		lib/subunit/python/subunit/tests/sample-script.py \
		lib/subunit/python/subunit/tests/sample-two-script.py \
		lib/tevent/tevent.py


PY_PATCHPLIST=	yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
