$NetBSD$

--- source3/lib/messages_dgm.c.orig	2017-01-11 07:55:15.000000000 +0000
+++ source3/lib/messages_dgm.c
@@ -34,6 +34,11 @@
 
 #define MESSAGING_DGM_FRAGMENT_LENGTH 1024
 
+/* illumos does not have MSG_NOSIGNAL */
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL 0
+#endif
+
 struct sun_path_buf {
 	/*
 	 * This will carry enough for a socket path
