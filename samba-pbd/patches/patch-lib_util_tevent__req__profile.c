$NetBSD$

--- lib/util/tevent_req_profile.c.orig	2018-10-09 18:25:28.140384252 +0000
+++ lib/util/tevent_req_profile.c
@@ -29,10 +29,11 @@
 #include "lib/util/time_basic.h"
 #include "lib/util/memory.h"
 
-int tevent_req_profile_print(const struct tevent_req_profile *profile,
-			     FILE *fp,
-			     unsigned indent,
-			     unsigned max_indent)
+static bool tevent_req_profile_string_internal(
+	const struct tevent_req_profile *profile,
+	unsigned indent,
+	unsigned max_indent,
+	char **string)
 {
 	struct timeval start, stop, diff;
 	struct timeval_buf start_buf, stop_buf;
@@ -44,7 +45,7 @@ int tevent_req_profile_print(const struc
 	const char *state_buf = NULL;
 	uint64_t user_error;
 	const struct tevent_req_profile *sub = NULL;
-	int ret;
+	char *result;
 
 	tevent_req_profile_get_name(profile, &req_name);
 
@@ -85,8 +86,8 @@ int tevent_req_profile_print(const struc
 		break;
 	}
 
-	ret = fprintf(
-		fp,
+	result = talloc_asprintf_append_buffer(
+		*string,
 		"%*s[%s] %s [%s] %s [%s] [%ju.%.6ju] -> %s (%d %"PRIu64"))\n",
 		indent,
 		"",
@@ -100,72 +101,58 @@ int tevent_req_profile_print(const struc
 		state_buf,
 		(int)state,
 		user_error);
-
-	if (ret < 0) {
-		return ret;
+	if (result == NULL) {
+		return false;
 	}
+	*string = result;
 
 	indent += 1;
 
 	if (indent >= max_indent) {
-		return ret;
+		return true;
 	}
 
 	for (sub = tevent_req_profile_get_subprofiles(profile);
 	     sub != NULL;
 	     sub = tevent_req_profile_next(sub)) {
-		int subret;
+		bool ret;
 
-		subret = tevent_req_profile_print(sub, fp, indent, max_indent);
-		if (subret < 0) {
-			return subret;
-		}
-
-		ret += subret;
-
-		if (ret < subret) {
-			/* overflow */
-			return -1;
+		ret = tevent_req_profile_string_internal(
+			sub,
+			indent,
+			max_indent,
+			string);
+		if (!ret) {
+			return false;
 		}
 	}
 
-	return ret;
+	return true;
 }
 
-char *tevent_req_profile_string(const struct tevent_req_profile *profile,
-				TALLOC_CTX *mem_ctx,
+char *tevent_req_profile_string(TALLOC_CTX *mem_ctx,
+				const struct tevent_req_profile *profile,
 				unsigned indent,
 				unsigned max_indent)
 {
-	FILE *fp = NULL;
-	char *buf = NULL;
-	size_t buflen = 0;
-	char *result = NULL;
-	int ret;
+	char *result;
+	bool ret;
 
-	fp = open_memstream(&buf, &buflen);
-	if (fp == NULL) {
+	result = talloc_strdup(mem_ctx, "");
+	if (result == NULL) {
 		return NULL;
 	}
 
-	ret = tevent_req_profile_print(profile, fp, 0, max_indent);
-	if (ret < 0) {
-		goto done;
-	}
-
-	ret = fclose(fp);
-	if (ret != 0) {
-		goto done;
+	ret = tevent_req_profile_string_internal(
+		profile,
+		indent,
+		max_indent,
+		&result);
+	if (!ret) {
+		TALLOC_FREE(result);
+		return NULL;
 	}
 
-	/*
-	 * A FILE* from open_memstream maintains the 0-byte at the end
-	 * beyond the reported length.
-	 */
-	result = talloc_memdup(mem_ctx, buf, buflen+1);
-
-done:
-	SAFE_FREE(buf);
 	return result;
 }
 
