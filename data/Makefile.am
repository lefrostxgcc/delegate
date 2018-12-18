images = images/1.png images/2.png images/3.png	\
			images/4.png images/5.png images/6.png
EXTRA_DIST = $(images) resources.xml

$(top_builddir)/src/resources.c:	$(top_srcdir)/data/images/*.png \
									$(top_srcdir)/data/resources.xml
	glib-compile-resources --generate-source		\
		--sourcedir=$(top_srcdir)/data/images		\
		--sourcedir=$(top_srcdir)/data				\
		--target=$(top_builddir)/src/resources.c	\
		$(top_srcdir)/data/resources.xml
