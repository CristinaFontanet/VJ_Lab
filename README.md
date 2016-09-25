# VJ_Lab
Laboratoris de l'assignature de Videojocs


#01 - window - DONE

Aquest exemple simplement obre una finestra amb color de fons gris fosc.

Examina el codi i prova a canviar el tamany de la finestra i el color.
Si ho aconsegueixes modifica l'aplicació per a que es pugui canviar el color de fons amb les tecles
numèriques ('1', '2', '3', ...).

#02 - primitives - DONE/2

Llegeix el codi que ha canviat respecte a l'exemple Window, especialment les classes Quad i Scene.
Veuràs que la geometria s'envia mitjançant VBOs (Vertex Buffer Objects). Encara que els rectangles
que s'envien a pintar tenen la mateixa amplada i alçada es dibuixan com a rectangles.

El problema el solucionarem a l'exemple 4. De moment prova a canviar les coordenades dels
vèrtexs a veure si ets capaç de fer que els quads siguin quadrats.

Després prova a crear-te la teva pròpia classe Circle que crei el VBO corresponent als vèrtexs d'un
cercle (com un polígon regular de N costats) i el pinti. No et preocupis si et surt un el·lipsoide per
culpa de la deformació de la finestra.

#03 - uniforms

En aquest exenple veuràs que els quatre quads de l'exemple anterior canvien de color gradualment
al llarg del temps. L'efecte s'aconsegueix passant el color als shaders via un uniform.

També podràs observar que sembla que els colors no canviïn la seva intensitat de forma coordinada.
En canvi al codi si que ho fan. La causa està en la diferent percepció que tenim de cada color.

A màxima intensitat cada Quad té un color C associat. Prova a canviar el codi per a que els quads
canviïn entre blanc i el color C, en comptes d'entre negre i C.

Afegeix un altre uniform que produeixi un escal·lat de tota la geometria que s'envia. El pots
implementar enviant un vector 2D que es multipliqui per les coordenades dels vèrtexs.

#04 - transforms - DONE

En aquest projecte solucionem el problema de deformació i afegim moviment utilitzant
transformacions geomètriques. En concret les dues matrius típiques de les versions antigues
d'OpenGL, la projection i la modelview matrix.

Per ajudar-nos a construir aquestes matrius a la CPU abans d'enviar-les a la GPU utilitzem la
llibreria GLM que fa servir la mateixa notació que GLSL (el llenguatge de programació de shaders).

Després de mirar-te el codi per entendre com s'encadenen les transformacions prova a canviar el
moviment dels quads. Prova a fer que deixin de girar i en canvi es moguin d'esquerra a dreta i tornin
a la seva posició original.

Un cop fet aixó afegeix un escalat progressiu que faci que els quads tinguin el seu tamany original
quan es troben a l'esquerra i una quarta part quan es trobin a l'esquerra. Ves en compte en com
concatenes les matrius. Recorda que aquí l'ordre importa.

#05 - textures - DONE

Fent servir la llibreria SOIL (però podríem fer servir moltes altres) podem carregar textures i
aplicar-les a les primitives que li enviem a OpenGL. En aquest exemple mostrem un quad sense
texturar, dos quads que fan servir troços diferents del mateix atlas de textures (spritesheet), i un
quad amb una textura repetida 4 vegades (2x2).

Comenta el codi que renderitza els quads actuals i crea el teu propi quad fent servir el spritesheet
que conté l'estrella i el Mario. En comptes d'agafar algun d'aquests dos canvia les coordenades de
textura per dibuixar el bolet del Super Mario. Combina això amb el moviment d'esquerra a dreta
que has implementat per l'exemple anterior.

Al directori images (on es troben les textures) trobaràs un arxiu brick.png. Afegeix dos quads nous.
Un ocuparà tota la pantalla i serà de color blau cel. L'altre tindrà la textura brick.png repetida i
ocuparà la part inferior de manera que faci de terra. Assegura't de que la textura brick no surt
deformada i de que el bolet es mou just per sobre del terra. També és important pintar els quads en
l'ordre correcte: cel, terra i, finalment, bolet.

#06 - text

Finalment tenim l'exemple de text. Tota aquesta funcionalitat gira al voltant de la classe Text.
Aquesta utilitza la llibreria FreeType per carregar la font que vulgueu i construir un atlas de textures
que conté els caràcters més utilitzats amb la font i la mida seleccionats. Via la classe Text podeu
dibuixar cadenes de caràcters a pantalla del color que vulgueu. Si voleu podeu mirar com funciona
internament la classe Text, però se surt completament dels objectius de l'assignatura.

Si heu fet el que es demanava a l'exercici anterior ara podeu afegir un marcador. Coloqueu un text a
la part superior esquerra que digui 'Rebots: X' sense les cometes i on X és el nombre de vegades que
el bolet ha rebotat amb els límits esquerra i dret de la finestra.

Ara afegiu un nou text que digui 'Bolet' de tal manera que es mostri sempre sobre el bolet encara
que aquest s'estigui movent. Afegiu una opció que permeti amb una tecla activar i desactivar aquest
text.
