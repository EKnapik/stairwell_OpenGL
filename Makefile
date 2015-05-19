# Ma Make File
final:  shader.o object.o shaderSetup.o cylinder.o square.o finalMain.o
		gcc -std=c99 -o final shader.o object.o shaderSetup.o cylinder.o square.o finalMain.o -framework CoreFoundation -framework OpenGL -framework GLUT -lSOIL

shaderSetup.o: shaderSetup.c shaderSetup.h
		gcc -c -std=c99 shaderSetup.c

finalMain.o: finalMain.c object.c object.h cylinder.c cylinder.h square.c square.h
		gcc -c -std=c99 finalMain.c

object.o: object.c object.h shader.c shader.h shaderSetup.c shaderSetup.h
		gcc -c -std=c99 object.c

shader.o: shader.c shader.h shaderSetup.c shaderSetup.h
		gcc -c -std=c99 shader.c

cylinder.o: cylinder.c cylinder.h
		gcc -c -std=c99 cylinder.c

square.o: square.c square.h
		gcc -c -std=c99 square.c

clean:
		$(RM) final *.o
