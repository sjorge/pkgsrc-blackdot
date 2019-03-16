$NetBSD$

--- src/net.c.orig	2019-02-28 17:18:59.000000000 +0000
+++ src/net.c
@@ -16,6 +16,9 @@ Contributors:
 
 #include "config.h"
 
+#include <netinet/in.h>
+#include <sys/socket.h>
+
 #ifndef WIN32
 #include <netdb.h>
 #include <unistd.h>
@@ -437,9 +440,10 @@ int net__socket_listen(struct mosquitto_
 #ifndef WIN32
 		ss_opt = 1;
 		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &ss_opt, sizeof(ss_opt));
-#endif
+#else
 		ss_opt = 1;
 		setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, &ss_opt, sizeof(ss_opt));
+#endif
 
 		if(net__socket_nonblock(&sock)){
 			return 1;
