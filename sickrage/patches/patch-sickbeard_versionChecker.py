$NetBSD$

--- sickbeard/versionChecker.py.orig	2015-10-16 19:41:53.550591789 +0000
+++ sickbeard/versionChecker.py
@@ -51,13 +51,9 @@ class CheckVersion:
         self.updater = None
         self.install_type = None
         self.amActive = False
-        if sickbeard.gh:
-            self.install_type = self.find_install_type()
-            if self.install_type == 'git':
-                self.updater = GitUpdateManager()
-            elif self.install_type == 'source':
-                self.updater = SourceUpdateManager()
 
+        sickbeard.BRANCH = 'master'
+        sickbeard.CUR_COMMIT_HASH = 'pkgsrc-%%VERSION%%'
         self.session=requests.Session()
 
     def run(self, force=False):
