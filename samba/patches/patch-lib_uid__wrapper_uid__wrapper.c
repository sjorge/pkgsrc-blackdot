$NetBSD$

--- lib/uid_wrapper/uid_wrapper.c.orig	2014-10-01 09:16:21.000000000 +0000
+++ lib/uid_wrapper/uid_wrapper.c
@@ -27,9 +27,11 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <grp.h>
+#ifndef __sun
 #ifdef HAVE_SYS_SYSCALL_H
 #include <sys/syscall.h>
 #endif
+#endif
 #ifdef HAVE_SYSCALL_H
 #include <syscall.h>
 #endif
