noinst_LIBRARIES = libeffect.a

libeffect_a_SOURCES = sai.c  scale2x.c  scanline.c scale2x.h scale3x.h \
		      hq2x.c hq2x.h hq2x.dat interp.h interp.c lq2x.c lq2x.h \
		      lq2x.dat hq3x.c hq3x.h hq3x.dat lq3x.c lq3x.h lq3x.dat \
		      hqx_common.c hqx_common.h

if HAVE_NASM
libeffect_a_LIBADD = 2xsaimmx.o effect_i386.o hq2x16.o hq3x16.o
endif


#2xsaimmx.o : 2xsaimmx.asm
#	nasm -f elf -I $(srcdir)/ $(srcdir)/2xsaimmx.asm && mv $(srcdir)/

#effect_i386.o : effect_i386.asm
#	nasm -f elf -I $(srcdir)/ $(srcdir)/effect_i386.asm  -o $(srcdir)/%.o

#hq2x16.o : hq2x16.asm
#	nasm -f elf -I $(srcdir)/ $(srcdir)/hq2x16.asm  -o $(srcdir)/%.o

#hq3x16.o : hq3x16.asm
#	nasm -f elf -I $(srcdir)/ $(srcdir)/hq3x16.asm  -o $(srcdir)/%.o

2xsaimmx.o effect_i386.o hq2x16.o hq3x16.o: %.o: %.asm
	nasm -f elf -I $(srcdir)/ $< -o $@ 

EXTRA_DIST = 2xsaimmx.asm effect_i386.asm hq2x16.asm hq3x16.asm 