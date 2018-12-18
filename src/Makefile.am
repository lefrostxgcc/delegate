images = images/1.png images/2.png images/3.png	\
			images/4.png images/5.png images/6.png
EXTRA_DIST = $(images) resources.xml

bin_PROGRAMS = delegate
delegate_SOURCES = main.c main_window.c dice.c delegate.c resources.c
delegate_CFLAGS = -I$(top_srcdir)/include		\
					$(PKGGTK_CFLAGS) $(AM_CFLAGS)
delegate_LDADD = $(PKGGTK_LIBS)

resources.c:	$(top_srcdir)/src/images/*.png \
									$(top_srcdir)/src/resources.xml
	glib-compile-resources --generate-source		\
		--sourcedir=$(top_srcdir)/src/images		\
		--sourcedir=$(top_srcdir)/src				\
		$(top_srcdir)/src/resources.xml
