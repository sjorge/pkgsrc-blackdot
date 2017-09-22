$NetBSD$

--- source3/modules/vfs_solarisacl.h.orig	2017-07-04 10:05:25.000000000 +0000
+++ source3/modules/vfs_solarisacl.h
@@ -41,7 +41,7 @@ int solarisacl_sys_acl_set_fd(vfs_handle
 int solarisacl_sys_acl_delete_def_file(vfs_handle_struct *handle,
 				const struct smb_filename *smb_fname);
 
-NTSTATUS vfs_solarisacl_init(void);
+NTSTATUS vfs_solarisacl_init(TALLOC_CTX *);
 
 #endif
 
