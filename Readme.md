# Laboratorio 2 — Estimación del nivel de estrés basada en la respuesta galvánica cutánea (GSR)

# 1. Introducción

La respuesta galvánica cutánea (GSR, Galvanic Skin Response) es una señal fisiológica relacionada con los cambios en la conductancia eléctrica de la piel. Esta señal hace parte de la actividad electrodérmica (EDA, Electrodermal Activity), la cual comprende diferentes fenómenos eléctricos que ocurren en la piel y que pueden variar ante estímulos fisiológicos, térmicos, mecánicos o emocionales.

La GSR resulta de interés en instrumentación biomédica debido a su relación con la actividad del sistema nervioso autónomo. Durante situaciones que generan activación fisiológica, pueden producirse cambios en la actividad de las glándulas sudoríparas, modificando la conductancia de la piel. Por esta razón, la GSR puede emplearse como un indicador indirecto de activación o respuesta fisiológica asociada al estrés, aunque no debe interpretarse como una medida exclusiva o directa del estrés.

En esta práctica se desarrolló un sistema vestible para adquirir continuamente las variaciones de la GSR y observar su comportamiento durante diferentes condiciones, incluyendo reposo, respiración profunda y actividades que requieren concentración y esfuerzo mental. La guía plantea como propósito desarrollar un sistema capaz de monitorear el nivel de estrés percibido mediante la respuesta galvánica cutánea.

 # 2. Marco teórico

 ## 2.1 Actividad electrodérmica

La actividad electrodérmica o EDA corresponde a los fenómenos eléctricos asociados con la piel, entre ellos las variaciones de su capacidad para conducir corriente eléctrica. Una de las variables utilizadas para caracterizar este fenómeno es la conductancia cutánea, que puede cambiar ante diferentes estímulos.

La conductancia eléctrica se expresa en siemens (S) y representa la facilidad con la que una corriente eléctrica puede circular a través de un material. En el caso de la piel, esta propiedad está relacionada, entre otros factores, con la actividad de las glándulas sudoríparas.

## 2.2 Nivel de conductancia cutánea y respuesta de conductancia

La señal GSR puede analizarse considerando una componente estacionaria y una componente transitoria.

La componente estacionaria, también denominada SCL (Skin Conductance Level), corresponde al nivel basal de conductancia de la piel. Este nivel puede variar lentamente dependiendo del estado fisiológico de la persona.

La componente transitoria, denominada SCR (Skin Conductance Response), corresponde a cambios temporales que aparecen sobre el nivel basal como respuesta a un estímulo. De acuerdo con la guía, estas respuestas suelen manifestarse como un incremento relativamente rápido de la conductancia seguido de un retorno más lento hacia el valor inicial.

De forma simplificada, la señal puede representarse como:

GSR = componente estacionaria + componente transitoria

La identificación de estas dos componentes es uno de los objetivos principales de la práctica.

## 2.3 GSR y estrés

El estrés puede producir una activación del sistema nervioso autónomo, generando diferentes respuestas fisiológicas. Una de ellas puede ser el aumento de la actividad de las glándulas sudoríparas, lo que modifica las propiedades eléctricas de la piel y puede producir cambios observables en la GSR.

Sin embargo, un aumento de la GSR no significa necesariamente que una persona esté experimentando estrés. La señal también puede modificarse debido a factores como respiración, movimiento, temperatura, estímulos físicos o cambios en el estado fisiológico. La propia guía señala que la conductancia cutánea puede aumentar ante estímulos de diferente naturaleza, no únicamente ante situaciones relacionadas con estrés.

Por esta razón, en esta práctica la GSR debe considerarse un **indicador indirecto de activación fisiológica**, y los resultados deben interpretarse teniendo en cuenta las condiciones en las que fueron obtenidos.

## 2.4 Sistema de adquisición

Para obtener la señal se utilizan electrodos colocados sobre la piel, los cuales permiten detectar cambios en sus propiedades eléctricas. La guía propone el desarrollo de un dispositivo vestible capaz de capturar las variaciones de GSR y transmitirlas a un computador, además de evaluar posteriormente una transmisión inalámbrica.

Entre los elementos disponibles para el desarrollo de la práctica se encuentran Arduino UNO o Nano, protoboard, cables, una resistencia de 68 kΩ, un condensador de 1 μF y electrodos Ag-AgCl o electrodos metálicos apropiados.

Un aspecto fundamental del diseño es limitar la corriente que atraviesa el cuerpo. La guía establece que, utilizando una alimentación entre 3.3 y 5 VDC, se deben realizar los cálculos necesarios para garantizar que la corriente a través de la piel de un sujeto sano no supere **1 mA**, incluso considerando el caso extremo de una resistencia de piel igual a cero.

# 3. Objetivos

## Objetivo general

Proporcionar un sistema de medición continua de estrés basado en la respuesta galvánica cutánea (GSR).

## Objetivos específicos

* Identificar las componentes estacionaria y transitoria de la GSR.
* Elaborar un dispositivo vestible que permita capturar de forma continua las variaciones de la GSR.
* Plantear hipótesis desde la fisiología humana sobre el rol de la GSR como indicador de estrés.

Estos objetivos corresponden a los establecidos en la guía de laboratorio.

 # 4. Metodología
Para la implementación del sistema de adquisición de la respuesta galvánica cutánea se utilizó un **corrector de postura como estructura de soporte para el dispositivo vestible**. Sobre este se fijó una protoboard que contenía el circuito de adquisición, el ESP y los demás componentes necesarios para el funcionamiento del sistema. La utilización del corrector permitió mantener los elementos electrónicos sujetos al cuerpo y facilitar el desplazamiento del sujeto durante las pruebas.

El ESP fue alimentado mediante una **power bank**, ubicada en la zona de la cintura del sujeto, con el propósito de proporcionar la energía necesaria para el funcionamiento del dispositivo sin limitar la movilidad de la persona. Esta configuración permitió realizar las mediciones mientras el sistema permanecía colocado sobre el cuerpo.

En la protoboard también se conectaron los **electrodos encargados de adquirir la señal proveniente del bíceps**. Estos electrodos permitieron obtener la información fisiológica necesaria para el análisis de la respuesta galvánica cutánea, manteniendo el contacto con la piel durante las diferentes pruebas realizadas.

La comunicación entre el dispositivo y el computador se realizó mediante **Wi-Fi**, permitiendo transmitir los datos adquiridos de forma inalámbrica. Aunque esta alternativa representó un mayor consumo energético debido al funcionamiento continuo de la comunicación inalámbrica, durante las pruebas presentó un comportamiento más favorable y permitió obtener mejores resultados en comparación con otras alternativas de transmisión evaluadas. Por esta razón, se decidió utilizar la comunicación Wi-Fi como parte de la configuración final del sistema.

La disposición de los componentes permitió obtener un sistema vestible integrado, en el cual el corrector de postura funcionó como soporte físico, la protoboard como base para el circuito electrónico, el ESP como unidad de procesamiento y comunicación, los electrodos como elementos de adquisición de la señal y la power bank como fuente de alimentación. Esta configuración permitió realizar las pruebas de adquisición mientras el sujeto llevaba puesto el dispositivo y se desplazaba con los elementos electrónicos instalados sobre el cuerpo.

# Montaje del dispositivo vestible

<img width="496" height="595" alt="Gemini_Generated_Image_yjhbw1yjhbw1yjhb" src="https://github.com/user-attachments/assets/fdc06a4e-0a8e-4cec-b4af-89a124ee7b5a" />


*En la vista frontal se observa la disposición del corrector de postura y los elementos asociados al sistema de adquisición, mientras que en la vista posterior se aprecia la ubicación de la protoboard, el ESP y la conexión con la fuente de alimentación ubicada en la zona de la cintura.*



# 5. Resultados

El sistema desarrollado permitió adquirir la señal proveniente del sensor GSR y visualizar sus variaciones tanto en tiempo real como mediante el almacenamiento de los datos para análisis posterior.

La señal obtenida por Arduino se expresó inicialmente como una lectura del conversor analógico-digital en un rango de 0 a 1023. A partir de esta lectura también se calculó el voltaje equivalente. Por lo tanto, las gráficas obtenidas directamente a partir del archivo CSV representan principalmente la **respuesta del sistema de adquisición en unidades ADC**, y no una medición directa de conductancia en siemens.
## RESULTADO 1

<img width="1600" height="789" alt="WhatsApp Image 2026-08-25 at 9 43 34 PM" src="https://github.com/user-attachments/assets/adc91bc9-03ee-4d24-8c99-7089cdfa3b51" />
<img width="542" height="150" alt="WhatsApp Image 2026-08-25 at 9 43 34 PM (1)" src="https://github.com/user-attachments/assets/7e48bd8f-bce4-428e-a2f5-e0657e1ddf59" />

## RESULTADO 2

<img width="1600" height="809" alt="WhatsApp Image 2026-08-25 at 9 44 04 PM (1)" src="https://github.com/user-attachments/assets/c73d9e60-5867-4ec7-957c-ecb9facc5b96" />
<img width="417" height="112" alt="WhatsApp Image 2026-08-25 at 9 44 04 PM" src="https://github.com/user-attachments/assets/5d21f6df-ba9d-43f3-8850-f85857eba346" />

## RESULTADO 3

















 # 6. Análisis de resultados

Durante las pruebas se realizaron adquisiciones de 30 segundos, obteniendo aproximadamente 600 muestras por registro, lo que evidencia una adquisición continua y estable de la señal. En los resultados se obtuvieron diferentes valores promedio de conductancia dependiendo de la condición evaluada. En una de las pruebas se registró una conductancia promedio de 0,1983 µS, clasificada por el sistema como estrés bajo o estado relajado. En otra medición se obtuvo un promedio de 0,5179 µS, correspondiente a un estado clasificado como estrés elevado o respuesta simpática alta, mientras que una tercera prueba presentó un promedio de **0,6256 µS**, clasificado como **estrés moderado o estado de alerta**.

En las gráficas se observa que la señal de conductancia presenta una componente que cambia lentamente a lo largo del tiempo, correspondiente a la componente tónica o SCL, sobre la cual aparecen variaciones más rápidas asociadas a la componente fásica o SCR. En la primera gráfica, la conductancia se mantiene aproximadamente entre 0,61 y 0,66 µS, con varias fluctuaciones y algunos incrementos puntuales. La componente fásica presenta cambios más notorios al inicio y alrededor de los 13 y 20 segundos, mostrando respuestas transitorias sobre el nivel basal.

En la segunda prueba se observa un comportamiento diferente, con un aumento inicial de la conductancia desde aproximadamente 0,50 µS hasta valores cercanos a 0,65 µS durante los primeros segundos. Posteriormente, la señal disminuye y permanece alrededor de 0,48–0,52 µS durante buena parte del registro. Este comportamiento también se refleja en la componente fásica, donde se presenta una respuesta marcada aproximadamente entre los 6 y 8 segundos, seguida de variaciones de menor amplitud.

Finalmente, en la prueba clasificada como estrés bajo se observa una tendencia progresiva de la componente tónica, pasando aproximadamente de 0,16 µS al inicio hasta valores cercanos a 0,22 µS al final del registro. Aunque existen fluctuaciones en la componente fásica, estas presentan una amplitud relativamente pequeña en comparación con las observadas en las otras pruebas.

En conjunto, los resultados muestran que el sistema fue capaz de detectar diferentes comportamientos de la señal GSR y distinguir variaciones entre las condiciones evaluadas. Sin embargo, los valores de conductancia y las categorías de estrés deben interpretarse como resultados obtenidos bajo las condiciones específicas de la práctica, ya que la señal GSR puede verse afectada por factores adicionales al estrés, como movimiento, contacto de los electrodos y cambios fisiológicos del sujeto.




 # 7. Discusión

Los resultados obtenidos permiten observar que la respuesta galvánica cutánea presenta variaciones tanto en su nivel basal como en sus respuestas transitorias. Esto es importante porque la señal GSR no permanece constante durante una prueba, sino que puede cambiar como consecuencia de diferentes estímulos y del estado fisiológico del sujeto. En las tres mediciones realizadas se observaron comportamientos diferentes, lo que permitió al sistema establecer distintos estados de respuesta.

La prueba con un promedio de 0,6256 µS, clasificada como estrés moderado o estado de alerta, presentó una señal relativamente estable alrededor de 0,62–0,65 µS, acompañada de varias respuestas fásicas. Esto indica que, aunque la conductancia no presentó cambios extremadamente grandes durante todo el registro, sí existieron variaciones puntuales que modificaron temporalmente la señal.

Por otro lado, la medición con un promedio de 0,5179 µS, clasificada por el sistema como estrés elevado o respuesta simpática alta, presentó una respuesta más marcada durante los primeros segundos. La conductancia aumentó rápidamente hasta aproximadamente 0,65 µS y posteriormente descendió hacia valores cercanos a 0,50 µS. Este cambio también se refleja claramente en la componente fásica, donde aparece una respuesta de mayor amplitud. Este comportamiento puede relacionarse con una activación fisiológica durante ese intervalo, aunque no permite afirmar por sí solo que el sujeto haya experimentado estrés psicológico.

La prueba clasificada como estrés bajo o relajado, con un promedio de 0,1983 µS, mostró una componente fásica de menor amplitud y una variación más gradual de la componente tónica. Esto representa un comportamiento diferente al observado en la prueba de mayor respuesta, y permite apreciar cómo la señal puede cambiar dependiendo de la condición del sujeto.

Un aspecto importante es que la clasificación de estrés utilizada por el sistema debe considerarse una estimación relativa. La GSR está relacionada con la actividad del sistema nervioso autónomo y puede responder ante diferentes estímulos, por lo que una mayor conductancia no necesariamente significa que exista un mayor nivel de estrés psicológico. Por esta razón, los resultados deben interpretarse considerando las condiciones experimentales y no únicamente el valor promedio de conductancia.

La separación de la señal en una componente tónica y una componente fásica permitió analizar de una manera más clara estos cambios. La componente tónica permitió observar la tendencia general de la conductancia durante los 30 segundos de adquisición, mientras que la componente fásica permitió identificar respuestas transitorias que aparecen sobre dicho nivel. Esta separación fue especialmente útil para reconocer los cambios más pronunciados presentes al inicio de algunas de las pruebas.

En general, el sistema presentó un comportamiento adecuado para registrar continuamente la señal durante las pruebas, obteniendo cerca de 600 muestras en cada registro de 30 segundos. Esto demuestra que la adquisición y transmisión de los datos funcionaron de manera estable y permitieron posteriormente realizar el procesamiento y análisis de la señal.

 
# 8. Conclusión

A partir de las pruebas realizadas fue posible comprobar el funcionamiento del sistema desarrollado para la adquisición y análisis de la respuesta galvánica cutánea. En registros de 30 segundos se obtuvieron aproximadamente 600 muestras, permitiendo observar de manera continua las variaciones de la señal y analizar tanto su comportamiento tónico como sus respuestas fásicas.

Los resultados presentaron diferentes valores promedio de conductancia, desde 0,1983 µS, asociado por el sistema con un estado de estrés bajo o relajado, hasta 0,6256 µS, clasificado como un estado moderado o de alerta. También se obtuvo un valor promedio de 0,5179 µS, que el sistema clasificó como estrés elevado o respuesta simpática alta. Estas diferencias permitieron demostrar que el dispositivo es capaz de detectar cambios en la respuesta fisiológica entre diferentes condiciones de evaluación.

El análisis de las componentes tónica y fásica permitió identificar tanto las variaciones lentas de la conductancia como las respuestas transitorias que aparecen durante determinados momentos de la prueba. Esto facilita la interpretación de la señal y permite observar cambios que podrían pasar desapercibidos al analizar únicamente un valor promedio.

Finalmente, aunque los resultados muestran que la GSR puede utilizarse para detectar variaciones relacionadas con la activación fisiológica, la señal no debe considerarse por sí sola como una medición directa del estrés. Factores como el movimiento, el contacto de los electrodos y otras respuestas fisiológicas pueden modificar la conductancia. Por lo tanto, el sistema desarrollado representa una herramienta útil para el monitoreo y análisis de la respuesta electrodérmica, pero sus resultados deben interpretarse teniendo en cuenta las condiciones específicas de cada prueba.

