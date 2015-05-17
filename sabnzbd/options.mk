# $NetBSD: options.mk,v 1.36 2011/05/10 13:38:23 taca Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.sabnzbdplus
PKG_SUPPORTED_OPTIONS=	par2 unrar unzip 7zip feedparser yenc openssl
PKG_SUGGESTED_OPTIONS=	par2 unrar unzip 7zip feedparser yenc openssl

.include "../../mk/bsd.options.mk"
.include "../../lang/python/application.mk"

###
### par2 support
###
.if !empty(PKG_OPTIONS:Mpar2)
DEPENDS+=	par2-[0-9]*:../../archivers/par2
.endif

###
### unrar support
###
.if !empty(PKG_OPTIONS:Munrar)
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
.endif

###
### unzip support
###
.if !empty(PKG_OPTIONS:Munzip)
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
.endif

###
### 7zip support
###
.if !empty(PKG_OPTIONS:M7zip)
DEPENDS+=	p7zip-[0-9]*:../../archivers/p7zip
.endif

###
### feedparser support
###
.if !empty(PKG_OPTIONS:Mfeedparser)
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
.endif

###
### par2 support
###
.if !empty(PKG_OPTIONS:Myenc)
DEPENDS+=	pbd-${PYPKGPREFIX}-yenc-[0-9]*:../../pbd/py-yenc
.endif

###
### openssl support
###
.if !empty(PKG_OPTIONS:Mopenssl)
DEPENDS+=	openssl-[0-9]*:../../security/openssl
DEPENDS+= ${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
.endif