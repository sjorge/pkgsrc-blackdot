$NetBSD$

--- source4/ntvfs/sysdep/inotify.c.orig	2016-01-26 11:45:46.000000000 +0000
+++ source4/ntvfs/sysdep/inotify.c
@@ -30,6 +30,9 @@
 #include "param/param.h"
 
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 /* glibc < 2.5 headers don't have these defines */
 #ifndef IN_ONLYDIR
