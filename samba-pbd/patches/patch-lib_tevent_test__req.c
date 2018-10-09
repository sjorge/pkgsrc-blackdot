$NetBSD$

--- lib/tevent/test_req.c.orig	2018-10-09 18:25:19.212293068 +0000
+++ lib/tevent/test_req.c
@@ -170,6 +170,7 @@ static bool test_tevent_req_profile2(str
 	pid_t pid1, pid2;
 	enum tevent_req_state state1, state2;
 	uint64_t err1, err2;
+	char *printstring;
 	ssize_t pack_len;
 	int err;
 	bool ok;
@@ -189,7 +190,12 @@ static bool test_tevent_req_profile2(str
 	TALLOC_FREE(req);
 	TALLOC_FREE(ev);
 
-	tevent_req_profile_print(p1, stdout, 0, UINT_MAX);
+	printstring = tevent_req_profile_string(tctx, p1, 0, UINT_MAX);
+	torture_assert_not_null(
+		tctx,
+		printstring,
+		"tevent_req_profile_string failed\n");
+	printf("%s\n", printstring);
 
 	pack_len = tevent_req_profile_pack(p1, NULL, 0);
 	torture_assert(tctx, pack_len>0, "profile_pack failed\n");
@@ -212,7 +218,12 @@ static bool test_tevent_req_profile2(str
 					 "profile_unpack failed\n");
 	}
 
-	tevent_req_profile_print(p2, stdout, 0, UINT_MAX);
+	printstring = tevent_req_profile_string(tctx, p2, 0, UINT_MAX);
+	torture_assert_not_null(
+		tctx,
+		printstring,
+		"tevent_req_profile_string failed\n");
+	printf("%s\n", printstring);
 
 	tevent_req_profile_get_name(p1, &str1);
 	tevent_req_profile_get_name(p2, &str2);
