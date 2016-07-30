$NetBSD: patch-salt_utils_____init____.py,v 1.1 2016/02/16 01:52:34 khorben Exp $

Use sockstat(1) on NetBSD

--- salt/utils/__init__.py.orig	2016-07-30 15:30:19.518805391 +0000
+++ salt/utils/__init__.py
@@ -1688,6 +1688,14 @@ def is_netbsd():
 
 
 @real_memoize
+def is_netbsd():
+    '''
+    Simple function to return if host is NetBSD or not
+    '''
+    return sys.platform.startswith('netbsd')
+
+
+@real_memoize
 def is_openbsd():
     '''
     Simple function to return if host is OpenBSD or not