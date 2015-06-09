$NetBSD$

SunOS needs sys/filio.h for FIONREAD.

--- source3/smbd/notify_inotify.c.orig	2014-10-01 09:16:21.000000000 +0000
+++ source3/smbd/notify_inotify.c
@@ -27,6 +27,9 @@
 
 #ifdef HAVE_INOTIFY
 
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/inotify.h>
 
 /* glibc < 2.5 headers don't have these defines */
