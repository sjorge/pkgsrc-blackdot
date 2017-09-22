$NetBSD$

--- source3/modules/vfs_solarisacl.c.orig	2017-07-04 10:05:25.000000000 +0000
+++ source3/modules/vfs_solarisacl.c
@@ -306,7 +306,7 @@ int solarisacl_sys_acl_set_fd(vfs_handle
  * check is considered unnecessary. --- Agreed? XXX
  */
 int solarisacl_sys_acl_delete_def_file(vfs_handle_struct *handle,
-				struct smb_filename *smb_fname)
+				const struct smb_filename *smb_fname)
 {
 	SMB_ACL_T smb_acl;
 	int ret = -1;
