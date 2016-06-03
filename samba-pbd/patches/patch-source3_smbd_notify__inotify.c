$NetBSD$

--- source3/smbd/notify_inotify.c.orig	2016-01-26 11:45:46.000000000 +0000
+++ source3/smbd/notify_inotify.c
@@ -27,6 +27,9 @@
 #include "lib/util/sys_rw_data.h"
 
 #include <sys/inotify.h>
+#ifdef HAVE_SYS_FILIO_H
+#include <sys/filio.h>
+#endif
 
 /* glibc < 2.5 headers don't have these defines */
 #ifndef IN_ONLYDIR
