$NetBSD$

--- source3/modules/vfs_zfsacl.c.orig	2017-11-02 11:38:36.000000000 +0000
+++ source3/modules/vfs_zfsacl.c
@@ -51,6 +51,7 @@ static NTSTATUS zfs_get_nt_acl_common(st
 	SMB_STRUCT_STAT sbuf;
 	const SMB_STRUCT_STAT *psbuf = NULL;
 	int ret;
+	bool is_dir;
 
 	if (VALID_STAT(smb_fname->st)) {
 		psbuf = &smb_fname->st;
@@ -66,9 +67,7 @@ static NTSTATUS zfs_get_nt_acl_common(st
 		psbuf = &sbuf;
 	}
 
-	if (S_ISDIR(psbuf->st_ex_mode) && (ace->aceMask & SMB_ACE4_ADD_FILE)) {
-		ace->aceMask |= SMB_ACE4_DELETE_CHILD;
-	}
+	is_dir = S_ISDIR(psbuf->st_ex_mode);
 
 	/* read the number of file aces */
 	if((naces = acl(smb_fname->base_name, ACE_GETACLCNT, 0, NULL)) == -1) {
@@ -115,6 +114,10 @@ static NTSTATUS zfs_get_nt_acl_common(st
 			aceprop.aceMask |= SMB_ACE4_SYNCHRONIZE;
 		}
 
+		if (is_dir && (aceprop.aceMask & SMB_ACE4_ADD_FILE)) {
+			aceprop.aceMask |= SMB_ACE4_DELETE_CHILD;
+		}
+
 		if(aceprop.aceFlags & ACE_OWNER) {
 			aceprop.flags = SMB_ACE4_ID_SPECIAL;
 			aceprop.who.special_id = SMB_ACE4_WHO_OWNER;
