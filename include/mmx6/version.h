/* mmx6/version.h -- the build versions as ordered numbers (docs/ops/multi-version.md item 5).
 * The build passes -DVERSION=VER_<X> (Makefile CPPFLAGS, from VERSION); C compares with `#if VERSION >= VER_US`,
 * never `#ifdef VERSION_*` (tools/mmx6/stylecheck.py refuses it). Numbers leave gaps of 10 so a version measured
 * older or newer than another takes a number between or around them; only US is a build target. */
#ifndef MMX6_VERSION_H
#define MMX6_VERSION_H

#define VER_US 20

#ifndef VERSION
#error "VERSION is undefined: the build passes -DVERSION=VER_<X> (Makefile CPPFLAGS)"
#endif

#endif
