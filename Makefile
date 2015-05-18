# Ma Make File
final:  shader.o object.o shaderSetup.o cylinder.o finalMain.o 
		gcc -std=c99 -o final shader.o object.o shaderSetup.o cylinder.o finalMain.o -framework OpenGL -framework GLUT

shaderSetup.o: shaderSetup.c shaderSetup.h
		gcc -c -std=c99 shaderSetup.c

finalMain.o: finalMain.c object.c object.h cylinder.c cylinder.o
		gcc -c -std=c99 finalMain.c

object.o: object.c object.h shader.c shader.h shaderSetup.c shaderSetup.h
		gcc -c -std=c99 object.c

shader.o: shader.c shader.h shaderSetup.c shaderSetup.h
		gcc -c -std=c99 shader.c

cylinder.o: cylinder.c cylinder.h
		gcc -c -std=c99 cylinder.c

clean:
		$(RM) final *.o
