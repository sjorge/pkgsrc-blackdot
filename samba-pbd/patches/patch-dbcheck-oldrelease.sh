$NetBSD$

--- testprogs/blackbox/dbcheck-oldrelease.sh.orig	2016-09-22 06:42:48.000000000 +0000
+++ testprogs/blackbox/dbcheck-oldrelease.sh
@@ -287,19 +287,19 @@ dbcheck_clean2() {
 }
 
 referenceprovision() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
         $PYTHON $BINDIR/samba-tool domain provision --server-role="dc" --domain=SAMBA --host-name=ares --realm=${RELEASE}.samba.corp --targetdir=$PREFIX_ABS/${RELEASE}_reference --use-ntvfs --host-ip=127.0.0.1 --host-ip6=::1 --function-level=2003
     fi
 }
 
 ldapcmp() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
          $PYTHON $BINDIR/samba-tool ldapcmp tdb://$PREFIX_ABS/${RELEASE}_reference/private/sam.ldb tdb://$PREFIX_ABS/${RELEASE}/private/sam.ldb --two --skip-missing-dn --filter=dnsRecord
     fi
 }
 
 ldapcmp_sd() {
-    if [ x$RELEASE == x"release-4-0-0" ]; then
+    if [ x$RELEASE = x"release-4-0-0" ]; then
         $PYTHON $BINDIR/samba-tool ldapcmp tdb://$PREFIX_ABS/${RELEASE}_reference/private/sam.ldb tdb://$PREFIX_ABS/${RELEASE}/private/sam.ldb --two --sd --skip-missing-dn
     fi
 }
