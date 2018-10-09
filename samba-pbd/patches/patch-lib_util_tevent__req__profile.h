$NetBSD$

--- lib/util/tevent_req_profile.h.orig	2018-10-09 18:25:31.711133582 +0000
+++ lib/util/tevent_req_profile.h
@@ -29,12 +29,8 @@
 #include "replace.h"
 #include <tevent.h>
 
-int tevent_req_profile_print(const struct tevent_req_profile *profile,
-			     FILE *fp,
-			     unsigned indent,
-			     unsigned max_indent);
-char *tevent_req_profile_string(const struct tevent_req_profile *profile,
-				TALLOC_CTX *mem_ctx,
+char *tevent_req_profile_string(TALLOC_CTX *mem_ctx,
+				const struct tevent_req_profile *profile,
 				unsigned indent,
 				unsigned max_indent);
 ssize_t tevent_req_profile_pack(
