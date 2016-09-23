$NetBSD$

--- source3/script/tests/test_smbclient_s3.sh.orig	2016-01-26 11:45:46.000000000 +0000
+++ source3/script/tests/test_smbclient_s3.sh
@@ -889,7 +889,7 @@ EOF
 
     echo "$out" | grep 'NT_STATUS'
     ret=$?
-    if [ $ret == 0 ] ; then
+    if [ $ret = 0 ] ; then
 	echo "$out"
 	echo "failed - NT_STATUS_XXXX listing \\manglenames_share\\FF4GBY~Q"
 	false
@@ -1027,7 +1027,7 @@ EOF
 
     echo "$out" | grep 'NT_STATUS'
     ret=$?
-    if [ $ret == 0 ] ; then
+    if [ $ret = 0 ] ; then
 	echo "$out"
 	echo "failed - NT_STATUS_XXXX listing \\widelinks_share\\dot"
 	false
