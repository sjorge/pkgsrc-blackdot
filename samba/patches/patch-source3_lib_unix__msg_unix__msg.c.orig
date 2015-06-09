$NetBSD$

--- source3/lib/unix_msg/unix_msg.c.orig	2015-02-24 18:59:51.000000000 +0000
+++ source3/lib/unix_msg/unix_msg.c
@@ -492,8 +492,9 @@ static int queue_msg(struct unix_dgram_s
 	 * Note: No need to check for overflow here,
 	 * since cmsg will store <= INT8_MAX fds.
 	 */
+#ifdef HAVE_STRUCT_MSGHDR_MSG_CONTROL
 	msglen += cmsg_space;
-
+#endif
 #endif /*  HAVE_STRUCT_MSGHDR_MSG_CONTROL */
 
 	if (num_fds > INT8_MAX) {
