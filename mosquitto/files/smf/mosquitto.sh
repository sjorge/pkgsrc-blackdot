#!@SMF_METHOD_SHELL@
#
# $NetBSD: mosquitto.sh,v 1.1 2020/04/11 16:17:42 ??? Exp $
#

. /lib/svc/share/smf_include.sh

if [ ! -d @VARBASE@/run/mosquitto ]; then
	@MKDIR@ @VARBASE@/run/mosquitto
	@CHMOD@ 0750 @VARBASE@/run/mosquitto
	@CHOWN@ @MOSQUITTO_USER@:@MOSQUITTO_GROUP@ @VARBASE@/run/mosquitto
fi

@PREFIX@/sbin/mosquitto "$@"
