$NetBSD$

--- source3/modules/vfs_aio_fork.c.orig	2015-02-24 18:59:51.000000000 +0000
+++ source3/modules/vfs_aio_fork.c
@@ -177,6 +177,9 @@ static ssize_t read_fd(int fd, void *ptr
 
 	msg.msg_name = NULL;
 	msg.msg_namelen = 0;
+#ifdef  HAVE_STRUCT_MSGHDR_MSG_CONTROL
+        msg.msg_flags = 0;
+#endif
 
 	iov[0].iov_base = (void *)ptr;
 	iov[0].iov_len = nbytes;
