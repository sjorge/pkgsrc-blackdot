$NetBSD$

--- source3/smbd/notify_inotify.c.orig	2015-07-21 09:47:49.000000000 +0000
+++ source3/smbd/notify_inotify.c
@@ -27,6 +27,9 @@
 #include "lib/sys_rw_data.h"
 
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 /* glibc < 2.5 headers don't have these defines */
 #ifndef IN_ONLYDIR
