.c.o:
	cc -c $<

thf: thf.o
	cc $< -o $@ -lm 

install: thf
	cp $< /usr/local/bin

clean:
	rm *.o thf
