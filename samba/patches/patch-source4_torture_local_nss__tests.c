$NetBSD$

--- source4/torture/local/nss_tests.c.orig	2015-10-20 10:40:54.000000000 +0000
+++ source4/torture/local/nss_tests.c
@@ -698,6 +698,7 @@ static bool test_group_r_cross(struct to
 	return true;
 }
 
+#ifdef HAVE_GETGROUPLIST
 static bool test_getgrouplist(struct torture_context *tctx,
 			      const char *user,
 			      gid_t gid,
@@ -732,6 +733,7 @@ static bool test_getgrouplist(struct tor
 
 	return true;
 }
+#endif /* HAVE_GETGROUPLIST */
 
 static bool test_user_in_group(struct torture_context *tctx,
 			       const struct passwd *pwd,
@@ -759,12 +761,14 @@ static bool test_membership_user(struct
 	int g, i;
 	bool primary_group_had_user_member = false;
 
-	torture_assert(tctx, test_getgrouplist(tctx,
+#ifdef HAVE_GETGROUPLIST
+        torture_assert(tctx, test_getgrouplist(tctx,
 					       pwd->pw_name,
 					       pwd->pw_gid,
 					       &user_groups,
 					       &num_user_groups),
 					       "failed to test getgrouplist");
+#endif /* HAVE_GETGROUPLIST */
 
 	for (g=0; g < num_user_groups; g++) {
 		torture_assert(tctx, test_getgrgid(tctx, user_groups[g], NULL),
