$NetBSD$

--- source3/winbindd/winbindd.c.orig	2018-07-12 08:23:36.000000000 +0000
+++ source3/winbindd/winbindd.c
@@ -1057,7 +1057,8 @@ static void winbind_client_processed(str
 		DBG_ERR("request took %u.%.6u seconds\n",
 			(unsigned)diff.tv_sec, (unsigned)diff.tv_usec);
 
-		str = tevent_req_profile_string(profile, talloc_tos(), 0, depth);
+		str = tevent_req_profile_string(
+			talloc_tos(), profile, 0, depth);
 		if (str != NULL) {
 			/* No "\n", already contained in "str" */
 			DEBUGADD(0, ("%s", str));
