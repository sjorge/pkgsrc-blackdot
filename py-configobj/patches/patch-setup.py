$NetBSD$

--- setup.py.orig	2015-05-16 22:07:47.267741705 +0000
+++ setup.py
@@ -12,7 +12,7 @@
 # http://opensource.org/licenses/BSD-3-Clause
 import os
 import sys
-from distutils.core import setup
+from setuptools import setup
 # a simple import wouldn't work if we moved towards a package with __init__
 from _version import __version__
 
