# Control de riego en una plantación
#### Trabajo Práctico con Máquinas de Estado
### Memoria descriptiva

Mi sistema será el encargado de controlar el riego de una plantación. Para decidir en que momentos regar se basa en los siguientes principios:
- Se regará por las noches, o muy temprano por la mañana. De esta forma se ahorra agua, ya que durante el día ésta se puede evaporar por la temperatura de los suelos.
- Si llueve se detiene el riego.
- Si no hay agua en la cisterna no se puede regar. Si la bomba se encendiera aún si haber agua, se dañaría, generando un costo alto repararla o cambiarla.
- La húmedad de la tierra será el parámetro clave para saber si regar o no.